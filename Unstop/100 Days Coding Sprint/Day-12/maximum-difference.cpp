#include <iostream>
#include <vector>
#include <climits>

void user_logic(int n, const std::vector<int>& arr, int &result) {
    result = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = arr[j] - arr[i];
            if (diff > 0) {
                if (result == -1 || diff > result) {
                    result = diff;
                }
            }
        }
    }
}

int main() {
    int T;
    std::cin >> T;
    std::vector<int> results(T);
    
    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;
        std::vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            std::cin >> arr[i];
        }
        
        user_logic(N, arr, results[t]);
    }
    
    for (const auto &result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}