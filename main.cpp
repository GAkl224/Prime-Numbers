#include <iostream>

using namespace std;

const int MAX_FACTORS = 100; // Max number of prime factors


int calculatePrimeFactors(int n, int factors[], bool print = false, int divisor = 2) {
    if (n <= 1) {
        if (print)
            cout << "cannot calculate the prime factors of that number." << endl;
        return 0;
    }

    int factorCount = 0;
    bool foundFactor = false;

    while (n % divisor == 0) {
        foundFactor = true;
        if (print)
            cout << divisor;
        factors[factorCount++] = divisor;
        if (n != divisor) {
            if (print)
                cout << ", ";
        }
        n = n / divisor;
    }

    if (foundFactor && print) {
        cout << endl;
    }

    if (divisor * divisor <= n) {
        factorCount += calculatePrimeFactors(n, factors + factorCount, print, divisor + 1);
    } else if (n > 1) {
        if (print)
            cout << n << endl;
        factors[factorCount++] = n;
    }
    
    return factorCount;
}

//  reduce fraction
void reduce(int numerator, int denominator, int reducedFraction[]) {
    // check if the input is valid
    if (numerator <= 1 || denominator <= 0) {
        cout << "Invalid input: Cannot calculate prime factors for number less than or greater than 1." << endl;
        return;
    }

    // find prime factors of numerator and denominator
    int numFactors[MAX_FACTORS], denomFactors[MAX_FACTORS];
    int numFactorCount = calculatePrimeFactors(numerator, numFactors);
    int denomFactorCount = calculatePrimeFactors(denominator, denomFactors);

    // cancel out common factors
    for (int i = 0; i < numFactorCount; ++i) {
        for (int j = 0; j < denomFactorCount; ++j) {
            if (numFactors[i] == denomFactors[j]) {
                numFactors[i] = denomFactors[j] = 1; // Cancel out common factors
                break;
            }
        }
    }

    // Calculate reduced values
    int reducedNumerator = 1;
    int reducedDenominator = 1;
    for (int i = 0; i < numFactorCount; ++i) {
        reducedNumerator *= numFactors[i];
    }
    for (int i = 0; i < denomFactorCount; ++i) {
        reducedDenominator *= denomFactors[i];
    }

    reducedFraction[0] = reducedNumerator;
    reducedFraction[1] = reducedDenominator;
}


void prettyPrint(int num) {
    cout << "The prime factors of " << num << " are: ";
    int factors[MAX_FACTORS];
    int factorCount = calculatePrimeFactors(num, factors, true);
}

int main() {
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    int reducedFraction[2];
    reduce(numerator, denominator, reducedFraction);
    cout << "Reduced fraction: " << reducedFraction[0] << "/" << reducedFraction[1] << endl;

    int number;
    cout << "Enter a number to find its prime factors: ";
    cin >> number;
    prettyPrint(number);

    return 0;
}


