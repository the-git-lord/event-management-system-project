#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <gtest/gtest.h>

#include "admin.hpp"
#include "password.hpp"
#include "user.hpp"

// Each test gets its own empty password file in the system's temp folder,
// deleting again when the test ends
class UserPasswords : public testing::Test {
protected:
    std::string filePath;

    void SetUp() override {
        std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();
        filePath = (std::filesystem::temp_directory_path() / ("passwords_" + testName + ".txt")).string();
        std::filesystem::remove(filePath);
    }

    void TearDown() override {
        std::filesystem::remove(filePath);
    }

    std::string readFile() {
        std::ifstream in(filePath);
        std::stringstream contents;
        contents << in.rdbuf();
        return contents.str();
    }
};

// ---------- Hashing ----------

TEST_F(UserPasswords, Sha256_Matches_Known_Values) {
    // Official SHA-256 test vectors
    ASSERT_EQ(sha256(""), "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    ASSERT_EQ(sha256("abc"), "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
}

TEST_F(UserPasswords, Salts_Are_Random) {
    std::string salt1 = generateSalt();
    std::string salt2 = generateSalt();
    
    ASSERT_EQ(salt1.size(), 32u);
    ASSERT_NE(salt1, salt2);
}

TEST_F(UserPasswords, Same_Password_And_Salt_Give_Same_Hash) {
    ASSERT_EQ(hashPassword("pass123", "salt"), hashPassword("pass123", "salt"));
    ASSERT_NE(hashPassword("pass123", "salt"), hashPassword("pass124", "salt"));
    ASSERT_NE(hashPassword("pass123", "salt"), hashPassword("pass123", "other"));
}

// ---------- User ----------

TEST_F(UserPasswords, User_Does_Not_Store_Plain_Password) {
    Participant user("Sam", "sam01", "pass123");

    ASSERT_NE(user.getPasswordHash(), "pass123");
    ASSERT_EQ(user.getPasswordHash(), hashPassword("pass123", user.getPasswordSalt()));
}

TEST_F(UserPasswords, Same_Password_Gives_Different_Hashes_For_Different_Users) {
    Participant sam("Sam", "sam01", "pass123");
    Participant kim("Kim", "kim07", "pass123");

    ASSERT_NE(sam.getPasswordHash(), kim.getPasswordHash());
}

TEST_F(UserPasswords, Login_Still_Works_With_Hashed_Password) {
    Participant user("Sam", "sam01", "pass123");

    ASSERT_FALSE(user.login("sam01", "wrong"));
    ASSERT_TRUE(user.login("sam01", "pass123"));
}

// ---------- PasswordFile ----------

TEST_F(UserPasswords, Saved_File_Has_Hash_Not_Plain_Password) {
    PasswordFile file(filePath);
    Participant user("Sam", "sam01", "pass123");

    ASSERT_TRUE(user.saveCredentials(file));

    std::string contents = readFile();
    ASSERT_NE(contents.find("sam01"), std::string::npos);
    ASSERT_NE(contents.find(user.getPasswordHash()), std::string::npos);
    ASSERT_EQ(contents.find("pass123"), std::string::npos);
}

TEST_F(UserPasswords, Verify_Correct_And_Wrong_Password) {
    PasswordFile file(filePath);
    Participant user("Sam", "sam01", "pass123");
    user.saveCredentials(file);

    ASSERT_TRUE(file.verify("sam01", "pass123"));
    ASSERT_FALSE(file.verify("sam01", "wrong"));
}

TEST_F(UserPasswords, Unknown_User_Cannot_Be_Verified) {
    PasswordFile file(filePath);

    ASSERT_FALSE(file.contains("ghost"));
    ASSERT_FALSE(file.verify("ghost", "pass123"));
}

TEST_F(UserPasswords, Saving_Again_Replaces_Old_Password) {
    PasswordFile file(filePath);
    Participant oldUser("Sam", "sam01", "oldpass");
    Participant newUser("Sam", "sam01", "newpass");

    oldUser.saveCredentials(file);
    newUser.saveCredentials(file);

    ASSERT_FALSE(file.verify("sam01", "oldpass"));
    ASSERT_TRUE(file.verify("sam01", "newpass"));
}

TEST_F(UserPasswords, File_Keeps_Several_Users) {
    PasswordFile file(filePath);
    Participant sam("Sam", "sam01", "pass123");
    Administrator admin("Raghav", "raghav", "admin123");

    sam.saveCredentials(file);
    admin.saveCredentials(file);

    ASSERT_TRUE(file.verify("sam01", "pass123"));
    ASSERT_TRUE(file.verify("raghav", "admin123"));
}

TEST_F(UserPasswords, Cannot_Save_Username_With_Spaces) {
    PasswordFile file(filePath);

    ASSERT_FALSE(file.save("sam 01", "salt", "hash"));
    ASSERT_FALSE(file.save("", "salt", "hash"));
}

TEST_F(UserPasswords, Login_With_Password_File) {
    PasswordFile file(filePath);
    Participant user("Sam", "sam01", "pass123");
    user.saveCredentials(file);

    ASSERT_FALSE(user.login(file, "sam01", "wrong"));
    ASSERT_FALSE(user.isLoggedIn());

    ASSERT_TRUE(user.login(file, "sam01", "pass123"));
    ASSERT_TRUE(user.isLoggedIn());
}

TEST_F(UserPasswords, Cannot_Log_In_Before_Saving_To_File) {
    PasswordFile file(filePath);
    Participant user("Sam", "sam01", "pass123");

    ASSERT_FALSE(user.login(file, "sam01", "pass123"));
}
