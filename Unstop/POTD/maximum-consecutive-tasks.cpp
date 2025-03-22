#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveTasks(int N, vector<int>& tasks, int T) {
    int maxTasks = 0, currentSum = 0, start = 0;

    for (int end = 0; end < N; end++) {
        currentSum += tasks[end];

        while (currentSum > T) {
            currentSum -= tasks[start];
            ++start;
        }

        maxTasks = max(maxTasks, end - start + 1);
    }

    return maxTasks;
}

int main() {
    int N, T;
    cin >> N;

    vector<int> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i];
    }

    cin >> T;

    cout << maxConsecutiveTasks(N, tasks, T) << endl;

    return 0;
}