#include <iostream>

void inputMatrix(int matrix[][4], int rows) 
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < 4; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][4], int rows) 
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < 4; ++j) {
            std::cout << matrix[i][j] <<"\t";
        }
        std::cout << std::endl;
    }
}

void makeDiagonal(int matrix[][4], int rows) 
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(i != j) {
                matrix[i][j] = 0;
            }
        }
    }
}

const int MATRIX_SIZE{4};


int main()
{
    int A[MATRIX_SIZE][MATRIX_SIZE];
    int B[MATRIX_SIZE][MATRIX_SIZE];

    std::cout << "Enter the elements of matrix A (16 integers):\n";
    inputMatrix(A, MATRIX_SIZE);

    std::cout << "Enter the elements of matrix B:\n";

    for(int i = 0; i < MATRIX_SIZE; ++i) {
        for(int j = 0; j < MATRIX_SIZE; ++j) {
            std::cin >> B[i][j];

            if(A[i][j] != B[i][j]) {
                std::cout << "\nThe matrices are not equal. The program is completed.\n";
                return 0;
            }
        }
    }

    std::cout << "\nThe matrices are equal to each other!\n\n";
    std::cout << "We reduce the matrix A to a diagonal form...\n";

    makeDiagonal(A, MATRIX_SIZE);

    std::cout << "Conversion result:\n";
    printMatrix(A, MATRIX_SIZE);


    return 0;
}