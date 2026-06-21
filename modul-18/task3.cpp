#include <iostream>

void evendigits(long long n, int& ans) {

    if (n < 0) {
        n = -n;
    }

    if (n == 0) {
        return;
    }

    int last_digit = n % 10;

    if (last_digit % 2 == 0) {
        ans++;
    }

    evendigits(n / 10, ans);
}

int main() {
    long long n;
    std::cout << "Enter a large integer (long long): ";
    std::cin >> n;

    int ans = 0;

  
    if (n == 0) {
        ans = 1;
    } else {
        evendigits(n, ans);
    }

    std::cout << "Number of even digits: " << ans << std::endl;

    return 0;
}
