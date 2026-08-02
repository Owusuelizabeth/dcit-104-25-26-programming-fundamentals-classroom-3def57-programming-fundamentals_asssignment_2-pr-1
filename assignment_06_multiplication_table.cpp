// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace #include <iostream>
#include <iomanip>
#include <string>
#include <limits>

int get_positive_integer(const std::string& prompt) {
    int val;
    std::cout << prompt;
    if (std::cin >> val) {
        if (val > 0) return val;
        std::cout << "Error: Input must be a positive integer.\n";
    } else {
        std::cout << "Error: Invalid input. Please enter a valid integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return -1;
}

void print_table(int num) {
    std::cout << "\nMultiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << num << "  x  " << std::left << std::setw(2) << i << " =  " << (num * i) << "\n";
    }
}

void part_a() {
    int num = get_positive_integer("Enter a number: ");
    if (num != -1) print_table(num);
}

void part_b() {
    int n = get_positive_integer("Enter a number N: ");
    if (n != -1) {
        for (int i = 1; i <= n; ++i) {
            print_table(i);
            if (i < n) std::cout << "-------------\n";
        }
    }
}

int main() {
    part_a();
    // part_b();
    return 0;
}
