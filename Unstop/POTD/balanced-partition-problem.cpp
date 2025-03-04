#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int user_logic(int N, int K, vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int> prefix_sum(N);
    prefix_sum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    int total = prefix_sum[N - 1];
    int ans = INT_MAX;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] - arr[0] <= K) {
            if (arr[N - 1] - arr[i + 1] <= K) {
                int left = prefix_sum[i];
                int right = total - left;
                ans = min(ans, abs(left - right));
            }
        }
    }
    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int result = user_logic(N, K, arr);
    cout << result << endl;
    
    return 0;
}