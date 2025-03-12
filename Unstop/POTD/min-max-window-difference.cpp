#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int smallest_max_difference(const std::vector<int>& arr, int K) {
    int N = arr.size();
    deque<int> maxDeque, minDeque;
    int minMaxDiff = INT_MAX;
    
    for (int i = 0; i < N; i++) {
        if (!maxDeque.empty() && maxDeque.front() == i - K) maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() == i - K) minDeque.pop_front();

        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[i]) maxDeque.pop_back();
        maxDeque.push_back(i);

        while (!minDeque.empty() && arr[minDeque.back()] >= arr[i]) minDeque.pop_back();
        minDeque.push_back(i);
        
        if (i >= K - 1) {
            int maxElement = arr[maxDeque.front()];
            int minElement = arr[minDeque.front()];
            minMaxDiff = min(minMaxDiff, maxElement - minElement);
        }
    }
    return minMaxDiff;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> k;
    
    int result = smallest_max_difference(arr, k);
    std::cout << result << std::endl;
    
    return 0;
}