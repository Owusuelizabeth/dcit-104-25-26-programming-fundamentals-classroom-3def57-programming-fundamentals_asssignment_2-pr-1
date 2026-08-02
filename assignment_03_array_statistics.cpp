// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — 
#include <iostream>

double getSum(const double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

double getAvg(const double arr[], int n) {
    return getSum(arr, n) / n;
}

double getMax(const double arr[], int n) {
    double max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

double getMin(const double arr[], int n) {
    double min = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] < min) min = arr[i];
    return min;
}

int main() {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;

    if (n <= 0) return 1;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\nResults:\n";
    std::cout << "Sum:      " << getSum(arr, n) << "\n";
    std::cout << "Average:  " << getAvg(arr, n) << "\n";
    std::cout << "Maximum:  " << getMax(arr, n) << "\n";
    std::cout << "Minimum:  " << getMin(arr, n) << "\n";

    delete[] arr;
    return 0;
}

// =============================================================================

#include <iostream>
using namespace std;

