// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

struct Student {
    std::string name, id;
    std::vector<double> scores;
};

double getAvg(const std::vector<double>& s) {
    return s.empty() ? 0 : std::accumulate(s.begin(), s.end(), 0.0) / s.size();
}

int main() {
    std::vector<Student> students;
    int choice;

    while (true) {
        std::cout << "\n1.Add  2.Display  3.Avg  4.Quit\nChoice: ";
        if (!(std::cin >> choice) || choice == 4) break;

        if (choice == 1) {
            Student s;
            std::cout << "Name: "; std::cin >> std::ws; std::getline(std::cin, s.name);
            std::cout << "ID: "; std::cin >> s.id;
            int n; std::cout << "Scores count: "; std::cin >> n;
            s.scores.resize(n);
            for (int i = 0; i < n; ++i) { std::cout << "Score " << i + 1 << ": "; std::cin >> s.scores[i]; }
            students.push_back(s);
            std::cout << "Added!\n";
        } 
        else if (choice == 2) {
            if (students.empty()) { std::cout << "No students.\n"; continue; }
            for (const auto& s : students) {
                std::cout << s.name << " | " << s.id << " | Scores: ";
                for (double sc : s.scores) std::cout << sc << " ";
                std::cout << "| Avg: " << std::fixed << std::setprecision(2) << getAvg(s.scores) << "\n";
            }
        } 
        else if (choice == 3) {
            std::string id; std::cout << "Enter ID: "; std::cin >> id;
            bool found = false;
            for (const auto& s : students) {
                if (s.id == id) {
                    std::cout << s.name << " Avg: " << std::fixed << std::setprecision(2) << getAvg(s.scores) << "\n";
                    found = true; break;
                }
            }
            if (!found) std::cout << "ID not found.\n";
        }
    }
}


