#include <iostream>
#include <vector>

int calculateX(int N) {
    if (N == 0) {
        return 5;
    }
    if (N == 1) {
        return 3;
    }

    std::vector<long long> dp(N + 1);
    dp[0] = 5;
    dp[1] = 3;

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 1) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 998;
        } else {
            dp[i] = (dp[i - 1] * dp[i - 2]) % 999;
        }
    }

    return dp[N];
}

int main() {
    int N;
    std::cin >> N;
    int result = calculateX(N);
    std::cout << result << std::endl;
    return 0;
}