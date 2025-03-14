#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int min_time_to_complete_tasks(int N, std::vector<int>& time, std::vector<std::pair<int, int>>& dependencies) {
    std::vector<std::vector<int>> adj(N);
    for (const auto& dep : dependencies) {
        adj[dep.second].push_back(dep.first);
    }

    std::vector<int> end_times(N, 0);

    std::function<int(int)> calculate_end_time = [&](int task) {
        if (end_times[task] != 0) {
            return end_times[task];
        }

        int max_dependency_time = 0;
        for (int dependency : adj[task]) {
            max_dependency_time = std::max(max_dependency_time, calculate_end_time(dependency));
        }

        end_times[task] = max_dependency_time + time[task];
        return end_times[task];
    };

    int max_end_time = 0;
    for (int i = 0; i < N; i++) {
        max_end_time = std::max(max_end_time, calculate_end_time(i));
    }

    return max_end_time;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> time(N);
    for (int i = 0; i < N; i++) {
        std::cin >> time[i];
    }

    int M;
    std::cin >> M;

    std::vector<std::pair<int, int>> dependencies(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        dependencies[i] = std::make_pair(a, b);
    }

    int result = min_time_to_complete_tasks(N, time, dependencies);
    std::cout << result << std::endl;

    return 0;
}