#include <iostream>
#include <chrono>
#include <iomanip>

#include "task.h"

Task::Task(const std::string& name, const std::string& description, const std::string& status)
: name(name), status(status), description(description)
{
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::tm tm_time = *std::localtime(&time);

    int year = tm_time.tm_year + 1900;  
    int month = tm_time.tm_mon + 1;     
    int day = tm_time.tm_mday;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-" << std::setw(2) << day;

    startDate = oss.str();

    day++;

    std::ostringstream dss;
    dss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-" << std::setw(2) << day;

    endDate = dss.str();
}

Task::Task(const std::string& name, const std::string& description, const std::string& status, const std::string& sDate, const std::string& eDate)
: name(name), status(status), description(description), startDate(sDate), endDate(eDate) 
{}

Task::Task()
: name("name"), status("status"), description("description"), startDate("startDate"), endDate("endDate") 
{}
