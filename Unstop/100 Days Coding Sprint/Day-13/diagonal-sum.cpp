#include <iostream>
#include <vector>

#define int long long

int sum_of_diagonals(int n) {
    return (n%2) ? (2*n-1) : (2*n);
}

int32_t main() {
    int n;
    std::cin >> n;
    
    int result = sum_of_diagonals(n);

    std::cout << result << std::endl;
    return 0;
}