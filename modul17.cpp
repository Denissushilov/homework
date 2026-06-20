#include <iostream>

// Функции из задачи 1
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *a, int *b)  //Через указатели менее удобно и менее безопасно 
{
    int tmp = *a;
    *a = *b; 
    *b = tmp;
}
// Функция из задачи 2
void rev(int *arr)
{
    for(int i = 0, j = 9; i < j; i++, j--) {
        int tmp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = tmp;
    }
}

// Функция из задачи 3
bool substr(const char *str1, const char *str2)
{
    if (str2[0] == '\0') return true;
    for(int i = 0; str1[i]; ++i) {
        for(int j = i, k = 0; str1[j] && str2[k]; ++j, ++k) {
            if(str1[j] != str2[k]) break;
            if(str2[k+1] == '\0') return true;
        }
    }
    return false;
}

const char *bool_flag(bool val)
{
    return (val ? "true" : "false");
}

int main()
{
    // Задача 1
    int a = 10, b = 20;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap2(&a, &b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    // Задача 2
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rev(arr);
    for(int i = 0; i < 10; ++i) std::cout << arr[i] << ' ';
    std::cout << "\n";

    // Задача 3
    const char* aa = "Hello world";
    const char* bb = "wor";
    const char* cc = "banana";
    std::cout << bool_flag(substr(aa,bb)) << " " << bool_flag(substr(aa,cc));


    return 0;
}