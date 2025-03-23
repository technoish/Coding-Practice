#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int maxConsecutiveDays(int N, vector<int>& workHours, int M) {
    deque<int> maxDeque, minDeque;
    int left = 0, maxDays = 0;

    for (int right = 0; right < N; right++) {
       
        while (!maxDeque.empty() && workHours[maxDeque.back()] <= workHours[right])
            maxDeque.pop_back();
        maxDeque.push_back(right);

        while (!minDeque.empty() && workHours[minDeque.back()] >= workHours[right])
            minDeque.pop_back();
        minDeque.push_back(right);

        while (workHours[maxDeque.front()] - workHours[minDeque.front()] > M) {
            left++; 
            if (maxDeque.front() < left) maxDeque.pop_front();
            if (minDeque.front() < left) minDeque.pop_front();
        }

        maxDays = max(maxDays, right - left + 1);
    }

    return maxDays;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> workHours(N);
    for (int i = 0; i < N; i++) cin >> workHours[i];
    cin >> M;

    cout << maxConsecutiveDays(N, workHours, M) << endl;
    return 0;
}