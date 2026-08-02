// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> tasks;

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

void deleteTask() {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }
    viewTasks();
    cout << "Enter task number to delete: ";
    int num;
    if (cin >> num && num >= 1 && num <= static_cast<int>(tasks.size())) {
        string removed = tasks[num - 1];
        tasks.erase(tasks.begin() + (num - 1));
        cout << "Task \"" << removed << "\" has been removed.\n";
    } else {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n====================\n  TO-DO LIST MENU  \n====================\n"
             << "1. Add task\n2. View tasks\n3. Delete task\n4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) addTask();
        else if (choice == 2) viewTasks();
        else if (choice == 3) deleteTask();
        else if (choice == 4) cout << "Goodbye!\n";
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}

