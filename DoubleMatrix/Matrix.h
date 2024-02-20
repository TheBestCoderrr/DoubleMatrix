#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    Matrix(const vector<vector<double>>& matrix) {
        size = matrix.size();
        if (size > 0 && size == matrix[0].size())
            this->matrix = matrix;
        else throw exception("Error inizialised matrix");
    }
    void Print() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                cout << matrix[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }
    operator double() const {
        return calculateDeterminant(matrix);
    }
private:
    vector<vector<double>> matrix;
    size_t size;
    double calculateDeterminant(const vector<vector<double>>& matrix) const {
        if (matrix.size() == 1) {
            return matrix[0][0];
        }
        double determinant = 0;
        int sign = 1;

        for (size_t i = 0; i < matrix.size(); ++i) {
            vector<vector<double>> tempMatrix;
            for (size_t j = 1; j < matrix.size(); ++j) {
                vector<double> row;
                for (size_t k = 0; k < matrix.size(); ++k) {
                    if (k != i) {
                        row.push_back(matrix[j][k]);
                    }
                }
                tempMatrix.push_back(row);
            }
            determinant += sign * matrix[0][i] * calculateDeterminant(tempMatrix);
            sign = -sign;
        }
        return determinant;
    }
};