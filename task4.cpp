#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& taskList) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (taskList[i].completed ? "[X] " : "[ ] ");
        cout << taskList[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed: " << taskList[index - 1].description << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        cout << "Task removed: " << taskList[index - 1].description << endl;
        taskList.erase(taskList.begin() + index - 1);
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Ignore the newline character left in the input buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t index;
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}