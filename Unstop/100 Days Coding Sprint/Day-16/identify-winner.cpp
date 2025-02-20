#include <iostream>
#include <vector>
#include <unordered_map>

int find_winner(const std::vector<int>& arr) {

    std::unordered_map<int, int> counts;
    for (int num : arr) {
        counts[num]++;
    }

    for (int num : arr) {
        if (counts[num] == 1) {
            return num;
        }
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int result = find_winner(arr);
    std::cout << result << std::endl;
    return 0;
}