#include "Reports.h"

Report::Report(const string& id, HeadOfDep* by, const string& date)
    : reportId(id), generatedBy(by), generatedDate(date) {}

string Report::getReportId() const {
    return reportId;
}

HeadOfDep* Report::getGeneratedBy() const {
    return generatedBy;
}

string Report::getGeneratedDate() const {
    return generatedDate;
}
