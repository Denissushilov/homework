#include <iostream>

int countWays(int n, int k = 3) {

    if (n == 0) return 1;
    if (n < 0) return 0;

    int totalWays = 0;
    
    for (int i = 1; i <= k; ++i) {
        totalWays += countWays(n - i, k);
    }

    return totalWays;
}

int main() {
    int n, k;
    std::cout << "Enter the step number (n) and maximum jump length (k): ";
    std::cin >> n >> k;

    std::cout << "Ways to reach step " << n << " (with k = " << k << "): " << countWays(n, k) << std::endl;


    std::cout << "Ways to reach step " << n << " (with default k = 3): " << countWays(n) << std::endl;

    return 0;
}
