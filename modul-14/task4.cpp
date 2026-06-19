#include <iostream>

int main()
{
    float a[4][4];
    float b[4];
    float c[4] = {0.0f};

    std::cout << "Enter the elements of matrix A (4X4, 16 float numbers):\n";
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            std::cin >> a[i][j];
        }
    } 

    std::cout << "Enter the 4 elements of vector B:\n";
    for(int i = 0; i < 4; ++i)
        std::cin >> b[i];

    for(int i = 0; i < 4; ++i) {
        float sum = 0.0f;

        for(int j = 0; j < 4; ++j) {
            sum += a[i][j] * b[j];
        }

        c[i] = sum;
    }  
    
    std::cout << "\nResult vector C:\n";
    for(int i = 0; i < 4; ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;    

    return 0;
}