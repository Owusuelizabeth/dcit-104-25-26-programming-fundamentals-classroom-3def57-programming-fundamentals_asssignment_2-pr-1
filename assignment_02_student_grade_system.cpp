// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW —
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

struct Student { std::string name, id; std::vector<double> scores; };
std::vector<Student> students;

void addStudent() {
    Student s;
    std::cout << "Name: "; std::cin >> std::ws; std::getline(std::cin, s.name);
    std::cout << "ID: "; std::cin >> s.id;
    int n; std::cout << "Score count: "; std::cin >> n;
    s.scores.resize(n);
    for (int i = 0; i < n; ++i) { std::cout << "Score " << i+1 << ": "; std::cin >> s.scores[i]; }
    students.push_back(s);
}

void displayAll() {
    if (students.empty()) { std::cout << "No students.\n"; return; }
    for (const auto& s : students) {
        double avg = s.scores.empty() ? 0 : std::accumulate(s.scores.begin(), s.scores.end(), 0.0) / s.scores.size();
        std::cout << s.name << " | " << s.id << " | Avg: " << std::fixed << std::setprecision(2) << avg << "\n";
    }
}

void calcAverage() {
    std::string id; std::cout << "Enter ID: "; std::cin >> id;
    for (const auto& s : students) {
        if (s.id == id) {
            double avg = s.scores.empty() ? 0 : std::accumulate(s.scores.begin(), s.scores.end(), 0.0) / s.scores.size();
            std::cout << s.name << " Avg: " << std::fixed << std::setprecision(2) << avg << "\n";
            return;
        }
    }
    std::cout << "ID not found.\n";
}

int main() {
    int c;
    while (true) {
        std::cout << "\n1.Add 2.Display 3.Avg 4.Quit: ";
        if (!(std::cin >> c) || c == 4) break;
        if (c == 1) addStudent();
        else if (c == 2) displayAll();
        else if (c == 3) calcAverage();
    }
}

// =============================================================================

#include <iostream>
using namespace std;

