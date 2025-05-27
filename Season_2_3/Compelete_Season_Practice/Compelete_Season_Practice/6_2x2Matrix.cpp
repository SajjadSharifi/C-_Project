#include<iostream>
class Matrix2x2 {
private:
    double data[2][2];
public:
    // Default constructor (identity matrix)
    Matrix2x2() {
        data[0][0] = data[1][1] = 1;
        data[0][1] = data[1][0] = 0;
    }

    // Copy constructor
    Matrix2x2(const Matrix2x2& other) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                data[i][j] = other.data[i][j];
    }

    // Calculate determinant
    double determinant() const {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    // Check if matrix is singular
    bool isSingular() const {
        return determinant() == 0;
    }

    // Calculate inverse
    Matrix2x2 inverse() const {
        double det = determinant();
        if (det == 0) return Matrix2x2(); // Return identity if singular

        Matrix2x2 inv;
        inv.data[0][0] = data[1][1] / det;
        inv.data[0][1] = -data[0][1] / det;
        inv.data[1][0] = -data[1][0] / det;
        inv.data[1][1] = data[0][0] / det;
        return inv;
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }
};