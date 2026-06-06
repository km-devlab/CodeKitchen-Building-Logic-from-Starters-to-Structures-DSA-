
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void loadTasks(vector<string>& tasks) {
    ifstream file("tasks.txt");
    string task;

    while (getline(file, task)) {
        tasks.push_back(task);
    }

    file.close();
}

void saveTasks(const vector<string>& tasks) {
    ofstream file("tasks.txt");

    for (string task : tasks) {
        file << task << endl;
    }

    file.close();
}

int main() {
    vector<string> tasks;
    int choice;
    string task;

    loadTasks(tasks);

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                saveTasks(tasks);
                cout << "Task added successfully!\n";
                break;

            case 2:
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    cout << "\nYour Tasks:\n";
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
                break;

            case 3:
                int index;
                if (tasks.empty()) {
                    cout << "No tasks to delete.\n";
                } else {
                    cout << "Enter task number to delete: ";
                    cin >> index;

                    if (index >= 1 && index <= tasks.size()) {
                        tasks.erase(tasks.begin() + index - 1);
                        saveTasks(tasks);
                        cout << "Task deleted successfully!\n";
                    } else {
                        cout << "Invalid task number.\n";
                    }
                }
                break;

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
