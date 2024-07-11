#include <iostream>
using namespace std;
int sumOfDigits(int number) {
    int sum = 0;
    number = abs(number);
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int result = sumOfDigits(number);
    cout << "Sum of the digits of " << number << " is " << result <<endl;
    return 0;
}
