#include <iostream>
#include <fstream>

const static int GRID_SIZE = 100;

void readMatrix(std::ifstream &file, int matrix[][GRID_SIZE], int size);
void printMatrix(int matrix[][GRID_SIZE], int size);
void addMatrices(int matrixA[][GRID_SIZE], int matrixB[][GRID_SIZE], int result[][GRID_SIZE], int size);
void multiplyMatrices(int matrixA[][GRID_SIZE], int matrixB[][GRID_SIZE], int result[][GRID_SIZE], int size);
void subtractMatrices(int matrixA[][GRID_SIZE], int matrixB[][GRID_SIZE], int result[][GRID_SIZE], int size);

int main() {
    int matrixA[GRID_SIZE][GRID_SIZE], matrixB[GRID_SIZE][GRID_SIZE], result[GRID_SIZE][GRID_SIZE];
    int size;

    std::ifstream file("matrix_input.txt");
    file >> size;

    std::cout << "Sam Muehlebach\n";
    std::cout << "Lab #6: Matrix Manipulation\n";

    readMatrix(file, matrixA, size);
    readMatrix(file, matrixB, size);

    file.close();

    std::cout << "\nMatrix A: \n";
    printMatrix(matrixA, size);

    std::cout << "\nMatrix B: \n";
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Sum (A + B): \n";
    printMatrix(result, size);

    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Product(A * B): \n";
    printMatrix(result, size);

    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Difference(A - B): \n";
    printMatrix(result, size);

    return 0;
}
void readMatrix(std::ifstream &file, int matrix[][GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int matrixA[][GRID_SIZE], int matrixB[][GRID_SIZE], int result[][GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[][GRID_SIZE], int matrixB[][GRID_SIZE], int result[][GRID_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int matrix1[][GRID_SIZE], int matrix2[][GRID_SIZE], int result[][GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
