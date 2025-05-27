#include<iostream>
class Matrix3x3 {
private:
    double data[3][3];
public:
    // Default constructor (identity matrix)
    Matrix3x3() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                data[i][j] = (i == j) ? 1 : 0;
    }

    // Copy constructor
    Matrix3x3(const Matrix3x3& other) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                data[i][j] = other.data[i][j];
    }

    // Calculate determinant
    double determinant() const {
        return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
            data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
            data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
    }

    // Check if matrix is singular
    bool isSingular() const {
        return determinant() == 0;
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }
};