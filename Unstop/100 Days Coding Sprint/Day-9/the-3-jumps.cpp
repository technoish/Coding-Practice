#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int min_cost(const std::vector<int>& v) {
    int n = v.size();
    std::vector<long long> dp(n, LLONG_MAX); 
    dp[0] = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3 && i + j < n; j++) {
            long long cost = std::abs(v[i] - v[i + j]);
            if (dp[i] != LLONG_MAX) { 
                dp[i + j] = std::min(dp[i + j], dp[i] + cost);
            }
        }
    }

    return (dp[n - 1] == LLONG_MAX) ? 0 : dp[n - 1]; 
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int result = min_cost(v);
    std::cout << result << std::endl;
    return 0;
}