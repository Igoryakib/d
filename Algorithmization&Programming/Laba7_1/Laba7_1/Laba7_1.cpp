#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return log(x / (5 * pow(x, 2))) + 95 * x;
}
double calculateIntegral(double a, double b, double step) {
    double result = 0.0;

    for (double x = a + step / 2; x < b; x += step) {
        result += function(x);
    }

    result *= step;
    return result;
}
double getInput(const std::string& prompt) {
    double value;
    cout << prompt;
    cin >> value;
    return value;
}

void displayResult(double result) {
    std::cout << "The result is: " << result << std::endl;
}

int main() {
    double a = getInput("The starting point of the interval (a): ");
    double b = getInput("The ending point of the interval (b): ");
    double step = getInput("Step: ");

    double integralResult = calculateIntegral(a, b, step);
    displayResult(integralResult);

    return 0;
}
