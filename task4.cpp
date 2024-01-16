#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct td_list
{
    string item;
    bool state;
};

class todo_list
{
public:
    td_list task;
    int number;
    vector<td_list> tasks;

    todo_list()
    {
        number = 0;
    }

    void addTask()
    {
        cout << "Enter Task : ";
        cin.ignore();
        getline(cin, task.item);
        task.state = false;
        tasks.push_back(task);
    }

    void complete()
    {
        cout << "Enter number of task to be completed: ";
        cin >> number;

        if (number < 1 || number > tasks.size())
        {
            cout << "Enter a valid task number!" << endl;
        }
        else
        {
            tasks[number - 1].state = true;
            display();
        }
    }

    void removeTask()
    {
        if (tasks.empty())
        {
            cout << "No Tasks to Remove" << endl;
            return;
        }
        cout << "Enter task number to remove: ";
        cin >> number;
        if (number < 1 || number > tasks.size())
        {
            cout << "Enter valid task number!!" << endl;
            return;
        }
        else
        {
            tasks.erase(tasks.begin() + number - 1);
        }
    }

    void display()
    {
        cout << "Tasks:" << endl;
        if (tasks.empty())
        {
            cout << "To-Do List is empty!" << endl;
        }
        cout << "Tasks to be completed: \t\tCompleted tasks: " << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].state == false)
            {
                cout << tasks[i].item << endl;
            }
            else
            {
                cout << "\t\t\t\t" << tasks[i].item << endl;
            }
        }
    }
};

int main()
{
    todo_list L;
    int i_choice;
    char c_choice;

    do
    {
        cout << "\t TO-DO List" << endl
             << endl
             << "1. Add task" << endl
             << "2. Remove task" << endl
             << "3. Display list" << endl
             << "4. Mark task as Completed" << endl
             << "5. Exit" << endl
             << "Enter your choice: ";
        cin >> i_choice;
    
        switch (i_choice)
        {
        case 1:
            L.addTask();
            break;
        case 2:
            L.removeTask();
            break;
        case 3:
            L.display();
            break;
        case 4:
            L.complete();
            break;
        case 5:
            cout << "Exiting the application..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice!!" << endl;
            break;
        }
    
        cout << "Do you want to continue? (y/n): ";
        cin >> c_choice;
    } while (c_choice == 'y');
    
    return 0;
}