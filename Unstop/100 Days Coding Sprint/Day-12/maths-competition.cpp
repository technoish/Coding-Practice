#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long helper(long long mid, vector<int>& arr) {
    long long ans =0;
    for (long long i=0;i<arr.size();i++) {
        ans+= mid/arr[i];
         if (ans > 1e9) return ans;
    }

    return ans;
}

int minimum_time_to_solve_problems(int n, int k, vector<int>& arr) {
    int low = 1;
    long long high = 1LL * (*max_element(arr.begin(), arr.end())) * k;    
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low)/2;
        long long questions = helper(mid,arr);
        if (questions >= k) {
            ans = mid;
            high = mid -1;
        }
        else low = mid +1;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    if (n == 1) {
        cout << 1LL * k * times[0] << endl;
        return 0; 
    }    
    int result = minimum_time_to_solve_problems(n, k, times);
    cout << result << endl;
    return 0;
}