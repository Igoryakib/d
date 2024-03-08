#include <iostream>
#include <cmath>

using namespace std;

double mathOperation1() {
	double x, y, z;
	cout << "Enter x: \n";
	cin >> x;
	cout << "Enter y: \n";
	cin >> y;
	cout << "Enter z: \n";
	cin >> z;

	double h = ((pow(x, y) * x) + exp(y) / exp(1.0)) / (1 + x * fabs(y - tan(z))) * (1 + fabs(y - x)) + ((pow(fabs(y - x), 2) / 2) - (pow(fabs(y - x), 3) / 3));

	return h;
}

double mathOperation2() {
	double z, x;
	cout << "Enter z: \n";
	cin >> z;
	if (z > 0) {
		x = -3*z;
	}
	if (z <= 0) {
		x = pow(z, 2);
	}

	double y = x * (sin(x) + exp(-x-3));

	return y;
}

int main() {

	//cout << "Your result is: " << mathOperation1();
	cout << "Your result is: " << mathOperation2();

	return 0;
}
