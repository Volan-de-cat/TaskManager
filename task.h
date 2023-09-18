#include <string>

class Task
{
public:
    Task();
    Task(const std::string& name, const std::string& description, const std::string& status);
    Task(const std::string& name, const std::string& description, const std::string& status, const std::string& sDate, const std::string& eDate);
    bool operator==(const Task& other) const {return name == other.name && description == other.description && status == other.status;};
    std::string name;
    std::string status;    
    std::string description;
    std::string startDate;
    std::string endDate;
    
private:
};