#include <iostream>
#include <string>
#include <vector>
#include <climits>

bool is_palindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int min_partition_cost(const std::string& S) {
    int n = S.length();
    if (is_palindrome(S)) {
        return 0;
    }

    std::vector<std::pair<int, int>> dp(n + 1, {INT_MAX, 0});
    dp[0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            std::string sub = S.substr(j, i - j);
            if (is_palindrome(sub)) {
                int cost = (j > 0) ? dp[j].second + (int)S[j - 1] + (int)S[i - 1] : 0;
                int partitions = dp[j].first + (j > 0);

                if (dp[i].first > partitions || (dp[i].first == partitions && dp[i].second > cost)) {
                    dp[i] = {partitions, cost};
                }
            }
        }
    }

    return dp[n].second;
}

int main() {
    std::string S;
    std::getline(std::cin, S);
    int result = min_partition_cost(S);
    std::cout << result << std::endl;
    return 0;
}