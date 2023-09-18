#include <algorithm>
#include <iostream>
#include "taskManager.h"


void taskManager::addTask(const Task& task)
{
    tasks.push_back(task);
    return;
}

void taskManager::addTask(Task&& task)
{
    tasks.push_back(task);
    return;
}

void taskManager::modifyTask(int mode, std::string word, std::vector<Task>::iterator it)
{
    std::string check;
    switch(mode)
    {
        case 0:
            (*it).name = word;
        break;
        case 1:
            (*it).status = word;
        break;
        case 2:
            (*it).description = word;
        break;
        case 3:
            (*it).startDate = word;
        break;
        case 4:
            (*it).endDate = word;
        break;
        default:break;
    }
}

// void taskManager::modifyTask(int mode, std::string word, std::vector<Task*>* modify)
// {
//     std::string check;
//     switch(mode)
//     {
//         case 0:
//         for(Task* task: *modify)
//         {
//             task->name = word;
//         }
//         break;
//         case 1:
//         for(Task* task: *modify)
//         {
//             task->status = word;
//         }
//         break;
//         case 2:
//         for(Task* task: *modify)
//         {
//             task->description = word;
//         }
//         break;
//         case 3:
//         for(Task* task: *modify)
//         {
//             task->startDate = word;
//         }
//         break;
//         case 4:
//         for(Task* task: *modify)
//         {
//             task->endDate = word;
//         }
//         break;
//         default:break;
//     }
// }

void taskManager::deleteTask(std::vector<Task>::iterator it)
{
    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task deleted" << std::endl;
    }
    else
    {
        std::cout << "Task doesn`t exist" << std::endl;
    }
}

std::vector<Task>::iterator taskManager::searchFirstTask(int mode, std::string word)
{
    std::vector<Task>::iterator it = tasks.end();
    switch(mode)
    {
        case 0:
        for(Task task : tasks)
        {
            if(task.name == word)
            {
                it = std::find(tasks.begin(), tasks.end(), task);
            }
        }
        break;
        case 1:
        for(Task task : tasks)
        {
            if(task.status == word)
            {
                it = std::find(tasks.begin(), tasks.end(), task);
            }
        }
        break;
        case 2:
        for(Task task : tasks)
        {
            if(task.description == word)
            {
                it = std::find(tasks.begin(), tasks.end(), task);
            }
        }
        break;
        case 3:
        for(Task task : tasks)
        {
            if(task.startDate == word)
            {
                it = std::find(tasks.begin(), tasks.end(), task);
            }
        }
        break;
        case 4:
        for(Task task : tasks)
        {
            if(task.endDate == word)
            {
                it = std::find(tasks.begin(), tasks.end(), task);
            }
        }
        break;
        default: 
        std::cerr << "Uncorrect mode" << std::endl;
        break;
    }
    return it;
}

std::vector<std::vector<Task>::iterator> taskManager::searchTasks(int mode, std::string word)
{
    std::vector<std::vector<Task>::iterator> search;
    switch(mode)
    {
        case 0:
        for(Task task : tasks)
        {
            if(task.name == word)
            {
               search.push_back(std::find(tasks.begin(), tasks.end(), task));
            }
        }
        break;
        case 1:
        for(Task task : tasks)
        {
            if(task.status == word)
            {
               search.push_back(std::find(tasks.begin(), tasks.end(), task));
            }
        }
        break;
        case 2:
        for(Task task : tasks)
        {
            if(task.description == word)
            {
               search.push_back(std::find(tasks.begin(), tasks.end(), task));
            }
        }
        break;
        case 3:
        for(Task task : tasks)
        {
            if(task.startDate == word)
            {
               search.push_back(std::find(tasks.begin(), tasks.end(), task));
            }
        }
        break;
        case 4:
        for(Task task : tasks)
        {
            if(task.endDate == word)
            {
               search.push_back(std::find(tasks.begin(), tasks.end(), task));
            }
        }
        break;
        default: 
        std::cerr << "Uncorrect mode" << std::endl;
        break;
    }
    return search;
}

void taskManager::Save()
{
    std::ofstream file("save.txt");
    if(file.is_open())
    {
        for(Task task : tasks)
        {
        file << task.name << "|" << task.description << "|" << task.status << "|" << task.startDate << "|" << task.endDate << std::endl;

        }
        file.close();
        std::cout << "Data saved to save.txt" << std::endl;
    }
    else
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

void taskManager::Load()
{
    std::ifstream file("save.txt");
    if(file.is_open())
    {
        std::string line;
        char delimiter = '|';
        Task task;
        while(std::getline(file, line))
        {
            size_t start = 0;
            size_t end = line.find(delimiter);

            task.name = line.substr(start, end - start);
            start = end + 1;
            end = line.find(delimiter, start);

            task.description = line.substr(start, end - start);
            start = end + 1;
            end = line.find(delimiter, start);

            task.status = line.substr(start, end - start);
            start = end + 1;
            end = line.find(delimiter, start);

            task.startDate = line.substr(start, end - start);
            start = end + 1;
            end = line.find(delimiter, start);

            task.endDate = line.substr(start);

            tasks.push_back(task);
        }
        file.close();
    }
    else
    {
        std::cerr << "File doesn`t exist" << std::endl;
    }
}
