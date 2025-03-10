#include <iostream>
#include <vector>
#include <algorithm>

int minBoxesRequired(std::vector<int> arr, int T) {
    int left = *std::max_element(arr.begin(), arr.end());
    int right = 0;
    for (int diamonds : arr) {
        right += diamonds;
    }
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int trips = 1, currentLoad = 0;
        
        for (int diamonds : arr) {
            if (currentLoad + diamonds > mid) {
                trips++;
                currentLoad = 0;
            }
            currentLoad += diamonds;
        }
        
        if (trips <= T) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, T;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::cin >> T;
    
    int result = minBoxesRequired(arr, T);
    std::cout << result << std::endl;
    return 0;
}