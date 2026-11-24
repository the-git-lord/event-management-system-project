#include <vector>
#include <gtest/gtest.h>

#include "admin.hpp"
#include "report.hpp"
#include "user.hpp"

// Shared setup: two logged-in participants and an empty report board
class UserReporting : public testing::Test {
protected:
    Participant alex = Participant("Alex", "alex02", "pw1");
    Participant sam = Participant("Sam", "sam01", "pw2");
    ReportBoard board;

    void SetUp() override {
        alex.login("alex02", "pw1");
        sam.login("sam01", "pw2");
    }
};

TEST_F(UserReporting, Reason_Options_Have_Readable_Names) {
    ASSERT_EQ(reportReasonToString(ReportReason::HARASSMENT), "Harassment");
    ASSERT_EQ(reportReasonToString(ReportReason::SAFETY_CONCERN), "Safety concern");
    ASSERT_EQ(reportReasonToString(ReportReason::SPAM), "Spam");
    ASSERT_EQ(reportReasonToString(ReportReason::INAPPROPRIATE_BEHAVIOR), "Inappropriate behavior");
    ASSERT_EQ(reportReasonToString(ReportReason::OTHER), "Other");
}

TEST_F(UserReporting, User_Can_Report_Another_User) {
    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::HARASSMENT));
    ASSERT_EQ(board.getSize(), 1);

    Report* report = board.findReport(1);
    ASSERT_NE(report, nullptr);
    ASSERT_EQ(report->getReporterUsername(), "alex02");
    ASSERT_EQ(report->getReportedUsername(), "sam01");
    ASSERT_EQ(report->getReason(), ReportReason::HARASSMENT);
    ASSERT_TRUE(report->isOpen());
}

TEST_F(UserReporting, Report_Keeps_Optional_Details) {
    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::SAFETY_CONCERN, "Blocked the fire exit"));
    ASSERT_EQ(board.findReport(1)->getDetails(), "Blocked the fire exit");
}

TEST_F(UserReporting, Logged_Out_User_Cannot_Report) {
    alex.logout();

    ASSERT_FALSE(alex.reportUser(board, sam, ReportReason::SPAM));
    ASSERT_EQ(board.getSize(), 0);
}

TEST_F(UserReporting, Cannot_Report_Yourself) {
    ASSERT_FALSE(alex.reportUser(board, alex, ReportReason::SPAM));
    ASSERT_EQ(board.getSize(), 0);
}

TEST_F(UserReporting, Other_Reason_Requires_Details) {
    ASSERT_FALSE(alex.reportUser(board, sam, ReportReason::OTHER));
    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::OTHER, "Kept taking my seat"));
    ASSERT_EQ(board.getSize(), 1);
}

TEST_F(UserReporting, Cannot_File_Duplicate_Open_Report) {
    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::SPAM));
    ASSERT_FALSE(alex.reportUser(board, sam, ReportReason::HARASSMENT));
    ASSERT_EQ(board.getSize(), 1);
}

TEST_F(UserReporting, Different_Users_Can_Report_Same_Person) {
    Participant kim("Kim", "kim07", "pw3");
    kim.login("kim07", "pw3");

    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::SPAM));
    ASSERT_TRUE(kim.reportUser(board, sam, ReportReason::SPAM));
    ASSERT_EQ(board.getSize(), 2);
}

TEST_F(UserReporting, Can_Report_Again_After_Report_Is_Closed) {
    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::SPAM));
    board.findReport(1)->dismiss();

    ASSERT_TRUE(alex.reportUser(board, sam, ReportReason::HARASSMENT));
    ASSERT_EQ(board.getSize(), 2);
}

TEST_F(UserReporting, Report_Ids_Increase) {
    Participant kim("Kim", "kim07", "pw3");

    alex.reportUser(board, sam, ReportReason::SPAM);
    alex.reportUser(board, kim, ReportReason::SPAM);

    ASSERT_NE(board.findReport(1), nullptr);
    ASSERT_NE(board.findReport(2), nullptr);
    ASSERT_EQ(board.findReport(3), nullptr);
}

TEST_F(UserReporting, Admin_Sees_Only_Open_Reports) {
    Participant kim("Kim", "kim07", "pw3");
    Administrator admin("Raghav", "raghav", "pass123");
    admin.login("raghav", "pass123");

    alex.reportUser(board, sam, ReportReason::SPAM);
    alex.reportUser(board, kim, ReportReason::HARASSMENT);
    admin.dismissReport(*board.findReport(1));

    std::vector<Report*> open = admin.viewOpenReports(board);
    ASSERT_EQ(open.size(), 1u);
    ASSERT_EQ(open[0]->getReportedUsername(), "kim07");
}

TEST_F(UserReporting, Logged_Out_Admin_Cannot_View_Reports) {
    Administrator admin("Raghav", "raghav", "pass123");
    alex.reportUser(board, sam, ReportReason::SPAM);

    ASSERT_TRUE(admin.viewOpenReports(board).empty());
}

TEST_F(UserReporting, Admin_Can_Act_On_A_User_Filed_Report) {
    Administrator admin("Raghav", "raghav", "pass123");
    admin.login("raghav", "pass123");

    alex.reportUser(board, sam, ReportReason::HARASSMENT);
    Report* report = board.findReport(1);

    ASSERT_TRUE(admin.handleReport(*report, sam, ReportAction::WARNING));
    ASSERT_EQ(sam.getWarningCount(), 1);
    ASSERT_TRUE(admin.viewOpenReports(board).empty());
}