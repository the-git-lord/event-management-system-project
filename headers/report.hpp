#ifndef REPORT
#define REPORT

#include <string>

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

class Report {
    private:
    int id;
    std::string reporterUsername;
    std::string reportedUsername;
    std::string reason;
    ReportStatus status;
    ReportAction action;

    public:
    Report(int id, std::string reporterUsername, std::string reportedUsername, std::string reason);

    int getId() const;
    std::string getReporterUsername() const;
    std::string getReportedUsername() const;
    std::string getReason() const;
    ReportStatus getStatus() const;
    ReportAction getAction() const;
    bool isOpen() const;

    void resolve(ReportAction action);
    void dismiss();
};

#endif