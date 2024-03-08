#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;
double y;

double f(double x) {
    return y = sin(4 * x) + 2 * x * cos(x - PI);
};

int main() {
    double Integral;
    double a = 0, b = PI;
    int n = 13;
    double h = (b - a) / n;
    double IntegralResult;
    cout << "#N\targument\tfunction value" << "\n";
    for (int i = 1; i <= n - 1; i++) {
        double x = a + i * h;
        double Integral = 0.0;
        cout << i << "\t " << x << "\t" << y << "\n";
        IntegralResult = Integral + h * f(a + h * (i - 0.5));
    }
    cout << "Your integral: " << IntegralResult << endl;
    return 0;
}