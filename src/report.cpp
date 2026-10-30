#include "report.hpp"

Report::Report(int id, std::string reporterUsername, std::string reportedUsername, std::string reason) {
    this->id = id;
    this->reporterUsername = reporterUsername;
    this->reportedUsername = reportedUsername;
    this->reason = reason;
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

std::string Report::getReason() const {
    return this->reason;
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