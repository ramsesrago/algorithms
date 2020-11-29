#include <iostream>

// To get the factorial of a number we could use recursion e.g. to get factorial of 5 we need to multiply 5 by factorial of 4
// Factorial of 4 is 4 * (factorial of 3) and so on
// We need to set the stop point for the factorial

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n-1);
    }
    else if (n == 0 || n == 1) {
        return 1;
    }
}

int main() {
   int input = 0;
   std::cout << "Choose a number to get factorial: ";
   std::cin >> input;
   int num = factorial(input); // 120
   std::cout << "Factorial of: " <<  input << " is: " << num << std::endl;
   return 0;
}