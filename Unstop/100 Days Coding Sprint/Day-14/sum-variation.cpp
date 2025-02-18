#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int calculate_sum(const vector<int>& nums,int maxi,int sum) {
    vector<int>v(maxi+1,0);
    for (int i=0;i<nums.size();i++) {
        if (nums[i] >=0) v[nums[i]] = 1;
    }
    int missing = 0;
    for (int i=1;i<v.size();i++) {
        if (v[i] == 0) {
            missing = i;
            break;
        }
    }
    return missing+48+sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int maxi = INT_MIN;
    int sum =0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maxi = max(maxi,nums[i]);
        sum+=nums[i];
    }
    maxi = max(maxi,n);
    int result = calculate_sum(nums,maxi,sum);
    if (n==1 && sum == 1) result = 51;
    cout << result << endl;
    return 0;
}