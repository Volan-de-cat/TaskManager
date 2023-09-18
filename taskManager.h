#include <vector>
#include <fstream>
#include "task.h"

class taskManager 
{
public:
    void addTask(const Task& task);
    void addTask(Task&& eDate);
    void modifyTask(int mode, std::string word, std::vector<Task>::iterator it);
    void deleteTask(std::vector<Task>::iterator it);
    std::vector<Task>::iterator searchFirstTask(int mode, std::string word);
    std::vector<std::vector<Task>::iterator> searchTasks(int mode, std::string word);
    void Save();
    void Load();

private:
    std::vector<Task> tasks;
};
