#include <iostream>
#include <vector>

int user_logic(int n) {
    const int MOD = 1e9 + 7;
    if (n == 0) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }

    std::vector<int> l(n + 1);
    l[0] = 2;
    l[1] = 1;

    for (int i = 2; i <= n; i++) {
        l[i] = (l[i - 1] + l[i - 2]) % MOD;
    }

    return l[n];
}

int main() {
    int n;
    std::cin >> n;
    int result = user_logic(n);
    std::cout << result << std::endl;

    return 0;
}