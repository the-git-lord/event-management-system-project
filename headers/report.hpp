#ifndef REPORT
#define REPORT

#include <list>
#include <string>
#include <vector>

enum class ReportStatus {
    OPEN,
    RESOLVED,
    DISMISSED
};

enum class ReportAction {
    NONE,
    WARNING,
    REMOVED_FROM_EVENT,
    BANNED
};

// The set of options a user can pick from when reporting someone
enum class ReportReason {
    HARASSMENT,
    SAFETY_CONCERN,
    SPAM,
    INAPPROPRIATE_BEHAVIOR,
    OTHER
};

std::string reportReasonToString(ReportReason reason);

class Report {
    private:
    int id;
    std::string reporterUsername;
    std::string reportedUsername;
    ReportReason reason;
    std::string details;
    ReportStatus status;
    ReportAction action;

    public:
    Report(int id, std::string reporterUsername, std::string reportedUsername, ReportReason reason, std::string details = "");


    int getId() const;
    std::string getReporterUsername() const;
    std::string getReportedUsername() const;
    ReportReason getReason() const;
    std::string getDetails() const;
    ReportStatus getStatus() const;
    ReportAction getAction() const;
    bool isOpen() const;

    void resolve(ReportAction action);
    void dismiss();
};

// Stores every report that has been filed
class ReportBoard {
    private:
    // std::list keeps each Report at the same address when more are added,
    // so Report* pointers handed out by findReport stay valid
    std::list<Report> reports;
    int nextId;

    bool hasOpenReport(std::string reporterUsername, std::string reportedUsername) const;

    public:
    ReportBoard();

    // Returns the new report's id, or -1 if the report was rejected
    int fileReport(std::string reporterUsername, std::string reportedUsername, ReportReason reason, std::string details = "");


    Report* findReport(int id);
    std::vector<Report*> getOpenReports();
    int getSize() const;
};

#endif