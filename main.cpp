#include <iostream>
#include "taskManager.h"

void menu()
{
    std::cout << "0-add new Task" << std::endl;
    std::cout << "1-search Task" << std::endl;
    std::cout << "2-modify Task" << std::endl;
    std::cout << "3-delete Task" << std::endl;
    std::cout << "4-save" << std::endl;
    std::cout << "5-load" << std::endl;
    std::cout << "6-exit" << std::endl;
    std::cout << "chose one:";
}

void search_menu()
{
    std::cout << "0-name" << std::endl;
    std::cout << "1-status" << std::endl;
    std::cout << "2-description" << std::endl;
    std::cout << "3-start Date" << std::endl;
    std::cout << "4-end Date" << std::endl;
    std::cout << "chose one:";
}
int main()
{   
    Task* task = new Task();
    taskManager* list = new taskManager();
    int mode;
    do
    {
        menu();
        std::cin >> mode;
        switch(mode)
        {
            case 0:
            {
                std::cout << std::endl;
                std::cout << "Enter name:";
                std::cin >> task->name;
                std::cout << "Enter description:";
                std::cin >> task->description;
                std::cout << "Enter status:";
                std::cin >> task->status;
                std::cout << "Enter start Date:";
                std::cin >> task->startDate;  
                std::cout << "Enter end Date:";
                std::cin >> task->endDate;  
                std::cout << std::endl;
                list->addTask(*task);   
                break;        
            }
            case 1:
            {
                std::cout << std::endl;
                int search_mode;
                std::string word;
                std::vector<Task> search;
                search_menu();
                std::cin >> search_mode;
                std::cout << "Enter word: ";
                std::cin >>word;
                std::cout << std::endl;
                list->searchTasks(search_mode,word,&search);
                if(search.empty())
                {
                    std::cerr << "Undefine word" << std::endl;
                }
                else
                {
                    for(Task search_task: search)
                    {
                        std::cout << "Name:" << search_task.name << std::endl;
                        std::cout << "Description:" << search_task.description << std::endl;
                        std::cout << "Status:" << search_task.status << std::endl;
                        std::cout << "Start Date:" << search_task.startDate << std::endl;
                        std::cout << "End Date:" << search_task.endDate << std::endl;
                        std::cout << std::endl;
                    }
                }
                break;
            }
            case 2:
            {

                std::cout << std::endl;
                int modify_mode;
                std::string word;
                std::vector<Task> modify;
                search_menu();
                std::cin >> modify_mode;
                std::cout << "Enter previos: ";
                std::cin >>word;
                std::cout << std::endl;
                list->searchTasks(modify_mode,word,&modify);
                if(modify.empty())
                {
                    std::cerr << "Undefine word" << std::endl;
                }
                else
                {
                    for(Task modify_task: modify)
                    {
                        std::cout << "Name:" << modify_task.name << std::endl;
                        std::cout << "Description:" << modify_task.description << std::endl;
                        std::cout << "Status:" << modify_task.status << std::endl;
                        std::cout << "Start Date:" << modify_task.startDate << std::endl;
                        std::cout << "End Date:" << modify_task.endDate << std::endl;
                        std::cout << std::endl;
                    }
                }
                std::cout << "Enter new: ";
                std::cin >>word;
                list->modifyTask(modify_mode,word,&modify);
                break;
            }
            case 3:
            {
                std::cout << std::endl;
                std::string word;
                std::cout << "Enter task name: ";
                std::cin >>word;
                    std::cout << std::endl; 
                auto it = list->searchFirstTask(0,word);
                    std::cout << "Name:" << it->name << std::endl;
                    std::cout << "Description:" << it->description << std::endl;
                    std::cout << "Status:" << it->status << std::endl;
                    std::cout << "Start Date:" << it->startDate << std::endl;
                    std::cout << "End Date:" << it->endDate << std::endl;
                    std::cout << std::endl;
                list->deleteTask(it);
                break;
            }
            case 4:
            {
                list->Save();
                break;
            }
            case 5:
            {
                list->Load();
                break;
            }
            case 6: break;
            default:std::cout << "Try again" <<std::endl;break;
            
        }

    }while(mode != 6);

    return 0;
}