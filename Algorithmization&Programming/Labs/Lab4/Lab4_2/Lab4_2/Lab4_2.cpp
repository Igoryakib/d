#include <iostream>
#include <stdlib.h>

using namespace std;
const int N = 4;
int matricArrayNumbers[N][N];

int main() {
	srand(time(NULL));
	int maxElement = matricArrayNumbers[0][0];
	int rowIndex;
	int columnIndex;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			matricArrayNumbers[i][j] = rand() % 35;

				if (maxElement < matricArrayNumbers[i][j]) 
				{
					maxElement = matricArrayNumbers[i][j];
					rowIndex = i;
					columnIndex = j;
			}
			cout << matricArrayNumbers[i][j] << "\t";

		}
	}
	cout << endl << endl << "MaxElement: " << maxElement;
	cout << endl << "rowIndex: " << rowIndex;
	cout << endl << "columnIndex: " << columnIndex << endl;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			if (i == rowIndex || j == columnIndex)
			{ 
				matricArrayNumbers[i][j] = 0;
			}
			cout << matricArrayNumbers[i][j] << "\t";

		}
	}
	return 0;
}