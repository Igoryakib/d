#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:
	int integer;
	int numerator;
	int denominator;


public:
	Fraction(int intenger, int numerator, int denominator);


	friend int operator-(Fraction& a, Fraction& b);

	friend int operator*(Fraction& a, Fraction& b);
};