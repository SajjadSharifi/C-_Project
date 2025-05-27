class Matrix2x2 {
private:
    double data[2][2];

public:
    Matrix2x2() {
        data[0][0] = data[1][1] = 1;
        data[0][1] = data[1][0] = 0;
    }

    // Addition operator
    Matrix2x2 operator+(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Subtraction operator
    Matrix2x2 operator-(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }
};