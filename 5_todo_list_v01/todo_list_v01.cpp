#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    enum commands
    {
        NEW,
        EDIT,
        DELETE,
        SHOW,
        QUIT
    };
    int cCommand = 0;
    int command = 0;
    std::string item = "";
    std::string itemSearch = "";
    std::vector<std::string> list;
    std::vector<std::string>::iterator wIter;
    std::vector<std::string>::const_iterator rIter;

    //welcome user
    std::cout << "Welcome to the Task Lister!\n\n";
    //while there are no tasks saved and user doesn't quit
    while (command != QUIT)
    {
        std::cout << "\n\n1-NEW 2-EDIT 3-DELETE 4-SHOW 5-QUIT\n\n";
        std::cin >> cCommand;
        command = cCommand - 1;
        if ((list.empty()) && (command == EDIT || command == DELETE || command == SHOW))
        {
            std::cout << "List is empty, please insert Tasks first.\n";
            continue;
        }
        switch (command)
        {
        case NEW:
            //add a task
            std::cout << "Please, write the task title:\n";
            std::cin >> item;
            list.push_back(item);
            break;
        case EDIT:
            //edit a task
            std::cout << "Please, input the task title:\n";
            std::cin >> itemSearch;
            wIter = find(list.begin(), list.end(), itemSearch);
            if (wIter != list.end())
            {
                std::cout << "Task found - ";
                std::cout << "::" << *wIter << "::" << std::endl;
                std::cout << "Please insert the new Task title:\n";
                std::cin >> *wIter;
                std::cout << "The edited task is now: \n";
                std::cout << "::" << *wIter << "::\n\n";
            }
            else
            {
                std::cout << "Task not found.\n";
            }
            break;
        case DELETE:
            //delete a task
            std::cout << "Please input the task title to delete:\n";
            std::cin >> itemSearch;
            rIter = find(list.begin(), list.end(), itemSearch);
            if(rIter!=list.end())
            {
                list.erase(rIter);
                std::cout << "Task deleted.\n";
            }
            else
            {
                std::cout << "Task not found.\n";
            }
            break;
        case SHOW:
            //ask if user wants to see the list
            std::cout << "The Task list:\n";
            for (rIter = list.begin(); rIter != list.end(); ++rIter)
            {
                std::cout << *rIter << std::endl;
            }
            break;
        case QUIT:
            std::cout << "Here is your current List:\n";
            for (rIter = list.begin(); rIter != list.end(); ++rIter)
            {
                std::cout << *rIter << std::endl;
            }
            std::cout << std::endl;
            break;
        default:
            std::cout << "please insert the correct command.\n";
            break;
        }
    }
    if (command == QUIT)
    {

        std::cout << "Thank you!\n";
    }

    system("pause");
    return 0;
}

