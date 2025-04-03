#include <iostream>
#include <map>
using namespace std;

map<int, long long> dp;

long long solve(int n) {
    if (n <= 1) {
        return n;
    }
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    long long result = solve(n / 2) + solve(n / 3) + solve(n / 4);
    dp[n] = max((long long)n, result);
    return dp[n];
}

int Maximum(int N) {
    return solve(N);
}

int main() {
    int N;
    cin >> N;
    cout << Maximum(N) << endl;
    return 0;
}