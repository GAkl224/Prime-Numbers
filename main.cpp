#include <iostream>

using namespace std;


void calculatePrimeFactors(int n, int divisor = 2) {
    if (n <= 1) {
        cout << "I cannot calculate the prime factors of that number." << endl;
        return;
    }

    bool foundFactor = false;

    while (n % divisor == 0) {
        foundFactor = true;
        cout << divisor;
        if (n != divisor) {
            cout << ", ";
        }
        n = n / divisor;
    }

    if (foundFactor) {
        cout << endl;
    }

    if (divisor * divisor <= n) {
        calculatePrimeFactors(n, divisor + 1);
    } else if (n > 1) {
        cout << n << endl;
    }
}

void prettyPrint(int num){
    cout << "The prime factors of " << num << " are: ";
    calculatePrimeFactors(num);
}

int main() {
   // int number = getUserInput();
    int number;
    cout << "Enter a number greater than 1: ";
    cin >> number;
    if(number <= 1)
    {
        cout << "\nThis number is invalid, enter number greater than 1:";
        cin >> number;
    }
    prettyPrint(number);
    
    return 0;
}
