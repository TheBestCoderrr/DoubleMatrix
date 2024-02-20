#include "Matrix.h"

int main() {
	srand(time(0));
	int rows, cols;
	cout << "Enter rows/cols: ";
	cin >> rows >> cols;
	vector<vector<double>> matrix(rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) 
			matrix[i].push_back(rand() % 100);
	}
	try{
		Matrix m(matrix);
		m.Print();
		cout << "determinant = " << double(m);
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
}