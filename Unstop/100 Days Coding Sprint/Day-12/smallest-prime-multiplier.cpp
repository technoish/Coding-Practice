#include <iostream>

int main() {
    long long p, n;
    std::cin >> p >> n;

    if (n % p == 0) {
        std::cout << n << std::endl;
    } else {
        std::cout << p * n << std::endl;
    }

    return 0;
}