#include <gtest/gtest.h>

#include "admin.hpp"
#include "event.hpp"
#include "report.hpp"
#include "user.hpp"

// Shared setup: a logged-in admin, a participant, and an event they join
class AdminUserReports : public testing::Test {
protected:
    Administrator admin = Administrator("Raghav", "raghav", "pass123");
    Participant user = Participant("Sam", "sam01", "abc");
    Event event;

    void SetUp() override {
        admin.login("raghav", "pass123");

        event.setName("Workshop");
        event.setCapacity(10);
        event.addParticipant(user);
    }
};

TEST_F(AdminUserReports, New_Report_Is_Open) {
    Report report(1, "alex02", "sam01", "Spamming in the chat");

    ASSERT_TRUE(report.isOpen());
    ASSERT_EQ(report.getStatus(), ReportStatus::OPEN);
    ASSERT_EQ(report.getAction(), ReportAction::NONE);
}

TEST_F(AdminUserReports, New_User_Has_No_Warnings_And_Is_Not_Banned) {
    ASSERT_EQ(user.getWarningCount(), 0);
    ASSERT_FALSE(user.isBanned());
}

TEST_F(AdminUserReports, Warn_User) {
    ASSERT_TRUE(admin.warnUser(user));
    ASSERT_TRUE(admin.warnUser(user));
    ASSERT_EQ(user.getWarningCount(), 2);
}

TEST_F(AdminUserReports, Remove_User_From_Event) {
    ASSERT_TRUE(event.isEnrolled("sam01"));
    ASSERT_TRUE(admin.removeUserFromEvent(event, user));
    ASSERT_FALSE(event.isEnrolled("sam01"));
    ASSERT_EQ(event.getEnrolledSize(), 0u);
}

TEST_F(AdminUserReports, Cannot_Remove_User_Not_In_Event) {
    Participant other("Kim", "kim07", "xyz");

    ASSERT_FALSE(admin.removeUserFromEvent(event, other));
    ASSERT_EQ(event.getEnrolledSize(), 1u);
}

TEST_F(AdminUserReports, Banned_User_Cannot_Join_Future_Events) {
    Event futureEvent;
    futureEvent.setName("Conference");
    futureEvent.setCapacity(10);

    ASSERT_TRUE(admin.banUser(user));
    ASSERT_TRUE(user.isBanned());
    ASSERT_EQ(futureEvent.addParticipant(user), RegisterCode::REJECTED_BANNED);
    ASSERT_EQ(futureEvent.getEnrolledSize(), 0u);
}

TEST_F(AdminUserReports, Unbanned_User_Can_Join_Again) {
    admin.banUser(user);
    ASSERT_TRUE(admin.unbanUser(user));

    Event futureEvent;
    futureEvent.setName("Conference");
    futureEvent.setCapacity(10);
    ASSERT_EQ(futureEvent.addParticipant(user), RegisterCode::ADDED_TO_EVENT);
}

TEST_F(AdminUserReports, Cannot_Ban_Another_Admin) {
    Administrator otherAdmin("Steve", "steve001", "1234");

    ASSERT_FALSE(admin.banUser(otherAdmin));
    ASSERT_FALSE(otherAdmin.isBanned());
}

TEST_F(AdminUserReports, Logged_Out_Admin_Cannot_Take_Action) {
    Report report(1, "alex02", "sam01", "Spamming in the chat");
    admin.logout();

    ASSERT_FALSE(admin.warnUser(user));
    ASSERT_FALSE(admin.banUser(user));
    ASSERT_FALSE(admin.removeUserFromEvent(event, user));
    ASSERT_FALSE(admin.handleReport(report, user, ReportAction::WARNING));
    ASSERT_FALSE(admin.dismissReport(report));

    ASSERT_EQ(user.getWarningCount(), 0);
    ASSERT_FALSE(user.isBanned());
    ASSERT_TRUE(event.isEnrolled("sam01"));
    ASSERT_TRUE(report.isOpen());
}

TEST_F(AdminUserReports, Handle_Report_With_Warning) {
    Report report(1, "alex02", "sam01", "Spamming in the chat");

    ASSERT_TRUE(admin.handleReport(report, user, ReportAction::WARNING));
    ASSERT_EQ(user.getWarningCount(), 1);
    ASSERT_EQ(report.getStatus(), ReportStatus::RESOLVED);
    ASSERT_EQ(report.getAction(), ReportAction::WARNING);
}

TEST_F(AdminUserReports, Handle_Report_By_Removing_From_Event) {
    Report report(2, "alex02", "sam01", "Disruptive behavior");

    ASSERT_TRUE(admin.handleReport(report, user, ReportAction::REMOVED_FROM_EVENT, &event));
    ASSERT_FALSE(event.isEnrolled("sam01"));
    ASSERT_EQ(report.getAction(), ReportAction::REMOVED_FROM_EVENT);
}

TEST_F(AdminUserReports, Remove_From_Event_Needs_An_Event) {
    Report report(2, "alex02", "sam01", "Disruptive behavior");

    ASSERT_FALSE(admin.handleReport(report, user, ReportAction::REMOVED_FROM_EVENT));
    ASSERT_TRUE(report.isOpen());
}

TEST_F(AdminUserReports, Handle_Report_With_Ban) {
    Report report(3, "alex02", "sam01", "Harassment");

    ASSERT_TRUE(admin.handleReport(report, user, ReportAction::BANNED));
    ASSERT_TRUE(user.isBanned());
    ASSERT_EQ(report.getAction(), ReportAction::BANNED);
}

TEST_F(AdminUserReports, Cannot_Handle_Report_For_Wrong_User) {
    Report report(1, "alex02", "sam01", "Spamming in the chat");
    Participant other("Kim", "kim07", "xyz");

    ASSERT_FALSE(admin.handleReport(report, other, ReportAction::BANNED));
    ASSERT_FALSE(other.isBanned());
    ASSERT_TRUE(report.isOpen());
}

TEST_F(AdminUserReports, Cannot_Handle_Closed_Report_Twice) {
    Report report(1, "alex02", "sam01", "Spamming in the chat");

    ASSERT_TRUE(admin.handleReport(report, user, ReportAction::WARNING));
    ASSERT_FALSE(admin.handleReport(report, user, ReportAction::WARNING));
    ASSERT_EQ(user.getWarningCount(), 1);
}

TEST_F(AdminUserReports, Dismiss_Report) {
    Report report(1, "alex02", "sam01", "Not actually a problem");

    ASSERT_TRUE(admin.dismissReport(report));
    ASSERT_EQ(report.getStatus(), ReportStatus::DISMISSED);
    ASSERT_EQ(user.getWarningCount(), 0);
    ASSERT_FALSE(admin.dismissReport(report));
}
