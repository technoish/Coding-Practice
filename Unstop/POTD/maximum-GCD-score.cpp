#include <bits/stdc++.h>
using namespace std;

int maxScore(int n, vector<int>& arr) {
    vector<bool> vis(n, false);
    vis[0] = true;
    vector<int> gcds(n, 0);

    if (n == 1) {
        return 0;
    }

    for (int i = 1; i < n; i++) {
        gcds[i] = __gcd(arr[0], arr[i]);
    }

    long long result = 0;
    for (int count = 1; count < n; count++) {
        int bestIdx = -1, bestVal = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && gcds[i] > bestVal) {
                bestVal = gcds[i];
                bestIdx = i;
            }
        }

        result += bestVal;
        vis[bestIdx] = true;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int tempGcd = __gcd(arr[bestIdx], arr[i]);
                gcds[i] = max(gcds[i], tempGcd);
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = maxScore(n, arr);
    cout << result << endl;
    return 0;
}