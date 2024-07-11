#include <iostream>
using namespace std;
unsigned long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is not defined for negative numbers.");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    try {
        unsigned long long result = factorial(number);
        cout << "Factorial of " << number << " is " << result <<endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}
