#include <iostream>

int mod_inverse(int A, int M) {
    A = A % M;
    for (int X = 1; X < M; X++) {
        if ((A * X) % M == 1) {
            return X;
        }
    }
    return 0; 
}

bool solve(int n) {
    if (n <= 0) {
        return false;
    }
    if ((n & (n - 1)) == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    int t = mod_inverse(n, 10007);
    bool result = solve(t);
    std::cout << (result ? 1 : 0) << std::endl;
    return 0;
}