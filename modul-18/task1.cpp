#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int arr[]);

int main()
{
    std::vector<int> a = {1,2,3,4};

    int b[] = {2,4,6,8};

    swapvec(a,b);

    for(int i = 0; i < 4; ++i)
        std::cout << a[i];

    std::cout << std::endl;

    for(int i = 0; i < 4; ++i)
        std::cout << b[i];

    return 0;
}

void swapvec(std::vector<int>& vec, int arr[])
{
    size_t size = vec.size();

    for(int i = 0; i < size; ++i) {
        int tmp = vec[i];
        vec[i] = arr[i];
        arr[i] = tmp;
    }
}