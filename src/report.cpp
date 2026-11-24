#include "report.hpp"

std::string reportReasonToString(ReportReason reason) {
    switch (reason) {
        case ReportReason::HARASSMENT:
            return "Harassment";
        case ReportReason::SAFETY_CONCERN:
            return "Safety Concern";
        case ReportReason::SPAM:
            return "Spam";
        case ReportReason::INAPPROPRIATE_BEHAVIOR:
            return "Inappropriate Behavior";
        case ReportReason::OTHER:
            return "Other";
    }

    return "Unknown";
}

Report::Report(int id, std::string reporterUsername, std::string reportedUsername, ReportReason reason, std::string details) {

    this->id = id;
    this->reporterUsername = reporterUsername;
    this->reportedUsername = reportedUsername;
    this->reason = reason;
    this->details = details;
    this->status = ReportStatus::OPEN;
    this->action = ReportAction::NONE;
}

int Report::getId() const {
    return this->id;
}

std::string Report::getReporterUsername() const {
    return this->reporterUsername;
}

std::string Report::getReportedUsername() const {
    return this->reportedUsername;
}

ReportReason Report::getReason() const {
    return this->reason;
}

std::string Report::getDetails() const {
    return this->details;
}

ReportStatus Report::getStatus() const {
    return this->status;
}

ReportAction Report::getAction() const {
    return this->action;
}

bool Report::isOpen() const {
    return this->status == ReportStatus::OPEN;
}

void Report::resolve(ReportAction action) {
    this->status = ReportStatus::RESOLVED;
    this->action = action;
}

void Report::dismiss() {
    this->status = ReportStatus::DISMISSED;
    this->action = ReportAction::NONE;
}

// --------- ReportBoard ---------

ReportBoard::ReportBoard() {
    this->nextId = 1;
}

bool ReportBoard::hasOpenReport(std::string reporterUsername, std::string reportedUsername) const {
    for (const Report& report : reports) {
        if (report.isOpen()
           && report.getReporterUsername() == reporterUsername
           && report.getReportedUsername() == reportedUsername)
            return true;
    }

    return false;
}

int ReportBoard::fileReport(std::string reporterUsername, std::string reportedUsername, ReportReason reason, std::string details) {

    if (reporterUsername.empty() || reportedUsername.empty())
        return -1;
    
    // Users cannot report themselves
    if (reporterUsername == reportedUsername)
        return -1;
    
    // "Other" needs an explanation
    if (reason == ReportReason::OTHER && details.empty())
        return -1;
    
    // One open report per reporter per user, so nobody can spam reports
    if (hasOpenReport(reporterUsername, reportedUsername))
        return -1;

    int id = nextId;
    nextId++;
    reports.push_back(Report(id, reporterUsername, reportedUsername, reason, details));
    return id;
}

Report* ReportBoard::findReport(int id) {
    for (Report& report : reports) {
        if (report.getId() == id)
            return &report;
    }

    return nullptr;
}

std::vector<Report*> ReportBoard::getOpenReports() {
    std::vector<Report*> open;

    for (Report& report : reports) {
        if (report.isOpen())
            open.push_back(&report);
    }

    return open;
}

int ReportBoard::getSize() const {
    return reports.size();
}
