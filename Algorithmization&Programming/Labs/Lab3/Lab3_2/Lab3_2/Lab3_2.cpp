#include <iostream>
#include <cmath>

using namespace std;
double x, Yx, Sx = 0, C, epsylon;
int k = 1;
int main() {
	cout << "Enter x: \n";
	cin >> x;
	cout << "Enter epsylon: \n";
	cin >> epsylon;
	C = 0.5 * pow(x, 2);
	Yx = -log(sqrt(1 + pow(x, 2))) + x * atan(x);
	while (C > epsylon) {
		C = pow(-1, k + 1) * (pow(x, 2 * k) / (2 * k * (2 * k - 1)));
		Sx += C;
		k++;
	}
	cout << "Accurate Yx: " << Yx << endl;
	cout << "Accurate Sx: " << Sx << endl;
	cout << "|Sx - Yx|: " << abs(Sx - Yx);
	return 0;
}