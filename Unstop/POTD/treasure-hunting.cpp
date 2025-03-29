#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long findMinXORSum(const vector<long long>& a, const vector<long long>& b, long long N) {
    vector<vector<long long>> dp(N + 1, vector<long long>(1 << N, numeric_limits<long long>::max()));
    dp[0][0] = 0;

    for (long long i = 0; i < N; i++) {
        for (long long mask = 0; mask < (1 << N); mask++) {
            if (dp[i][mask] == numeric_limits<long long>::max()) {
                continue;
            }
            for (long long j = 0; j < N; j++) {
                if (!(mask & (1LL << j))) {
                    long long newMask = mask | (1LL << j);
                    dp[i + 1][newMask] = min(dp[i + 1][newMask], dp[i][mask] + (a[i] ^ b[j]));
                }
            }
        }
    }

    return dp[N][(1 << N) - 1];
}

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N), b(N);

    for (long long i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < N; i++) {
        cin >> b[i];
    }

    cout << findMinXORSum(a, b, N) << endl;

    return 0;
}