#include <iostream>
#include "matrix.h"

int main() {
    Matrix<int, -1> matrix;

    const int matrixSz = 10;
    for (int x = 0; x < matrixSz; ++x) {
        matrix[x][x] = x;
        int secondIdx = matrixSz - x - 1;
        matrix[x][secondIdx] = secondIdx;
    }
    std::cout << '\n';

    std::cout << "Number of cells: " << matrix.size() << '\n' << '\n';

    std::cout << "Cells in the range[1..8][1..8]:" << '\n';
    for (auto i = 1; i < matrixSz - 1; ++i) {
        for (auto j = 1; j < matrixSz - 1; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << '\n';

    std::cout << "operator=:" << '\n';
    std::cout <<  (((matrix[100][100] = 314) = 0) = 217) << '\n' << '\n';

    for (const auto& c: matrix) {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << x << y << v << '\n';
    }

    return 0;
}
