#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007
#define MAX_SIZE 10000001

vector<long long> dp(MAX_SIZE, 0);

int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 0;

    for (long long i = 4; i < MAX_SIZE; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}