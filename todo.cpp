#include <iostream>
#include <vector>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n--- TO DO LIST ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        if (choice == 1) {
            string task;
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added successfully!\n";
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "\nYour Tasks:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            int taskNumber;
            cout << "Enter task number to delete: ";
            cin >> taskNumber;

            if (taskNumber > 0 && taskNumber <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNumber - 1);
                cout << "Task deleted successfully!\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
