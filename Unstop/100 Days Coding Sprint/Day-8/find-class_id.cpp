#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int peakIndexInMountainArray(vector<int>& A);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}


int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int low =0;
    int high = 2;
    while (high < n) {
        int mid = low + (high -  low)/2;
        if (arr[mid] >= arr[low] && arr[mid] >= arr[high]) return mid;
        low++;
        high++;
    }
    if (arr[0] >= arr[1]) return 0;
    if (arr[n-1] >= arr[n-2]) return n-1;
    else return -1;
}