#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAttempts(int n, int k) {
    if (n == 0 || k == 0) return 0; 
    if (k == 1) return n;      
    if (n == 1) return 1;   

   
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; i++) {
        dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) {
        dp[1][j] = j; 
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = j;
            int low = 1, high = j;

            while (low <= high) {
                int mid = (low + high) / 2;
                int break_case = dp[i - 1][mid - 1];
                int no_break_case = dp[i][j - mid];  
                int worst_case = 1 + max(break_case, no_break_case);

                dp[i][j] = min(dp[i][j], worst_case);

                if (break_case > no_break_case) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }

    return dp[k][n];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << minAttempts(n, k) << endl;
    return 0;
}