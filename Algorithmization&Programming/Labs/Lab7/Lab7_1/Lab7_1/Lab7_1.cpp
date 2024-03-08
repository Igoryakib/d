#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double fact(int N);

double getEps();

double getStep();


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    double h = getStep();
    double eps = getEps();
    double x = 0.0;
    int n = 3;
    double Px = 1;
    double Sx = 0.0;
    double C = (fact(n+2) + (n*x)) / fact(2 * n);
    cout << n << "\t " << C << "\n";
    while (x <= 1) {
        while (C > eps) {
            C = (fact(n + 2) + (n * x)) / fact(2 * n);
            n++;
            Px *= C;
            cout << n << "\t " << C << "\n";
        }
        x += h;
        Sx += Px;
    }
    cout << "Px:" << Px << endl << "Sx:" << Sx << endl << "Result of Integral:" << Sx * (1 / h);
	return 0;
}

double fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

double getEps() {
    cout << "¬вед≥ть точн≥сть обчисленн€ :";
    double data;
    cin >> data;
    return data;
}

double getStep() {
    cout << "¬вед≥ть крок обчисленн€ :";
    double data;
    cin >> data;
    return data;
}