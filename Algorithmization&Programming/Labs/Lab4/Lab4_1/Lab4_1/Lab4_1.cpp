#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int N = 10;
int* setArrayNum() {
	static int arrayNumbers[N];
	for (int i = 0; i < N; i++) {
		arrayNumbers[i] = rand() % 20;
		if (i >= N/2) {
			arrayNumbers[i] = (rand() % 20) * -1;
		}
	}

	return arrayNumbers;
}



int main() {
	srand(time(NULL));
	int* ptr;
	ptr = setArrayNum();
	cout << "Array is: ";
	for (int i = 0; i < N; i++)
		cout << ptr[i] << "  ";
	int minElement = ptr[0];
	int maxElement = ptr[0];
	int maxElementIndex;
	int minElementIndex;
	for (int i = 0; i < N; i++) {
		if (minElement > ptr[i]) {
			minElement = ptr[i];
			minElementIndex = i;
		}
		else if (maxElement < ptr[i]) {
			maxElement = ptr[i];
			maxElementIndex = i;
		}
	}
	cout << endl << "MaxElement: " << maxElement << endl << "MinElement: " << minElement << endl;
	ptr[maxElementIndex] = minElement;
	ptr[minElementIndex] = maxElement;
	for (int i = 0; i < N; i++)
		cout << ptr[i] << "  ";
	return 0;
}