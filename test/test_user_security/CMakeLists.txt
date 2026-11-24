add_executable(TestUserPasswords testUserPasswords.cpp)
target_link_libraries(TestUserPasswords
  PRIVATE
  Admin
  User
  Password
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestUserPasswords)
