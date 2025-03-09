#include <iostream>
#include <vector>

int user_logic(int N, int K) {
    std::vector<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }

    for (int k = 0; k < K; k++) {
        std::vector<int> indices_to_remove;
        for (int i = 0; i < arr.size(); i++) {
            if ((i + 1) % 3 == 1) {
                indices_to_remove.push_back(i);
            }
        }

        std::vector<int> new_arr;
        int remove_index = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (remove_index < indices_to_remove.size() && i == indices_to_remove[remove_index]) {
                remove_index++;
            } else {
                new_arr.push_back(arr[i]);
            }
        }
        arr = new_arr;

        if (arr.empty()) {
            break;
        }
    }

    long long total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    return total_sum % 998244353;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    int result = user_logic(N, K);
    std::cout << result << std::endl;
    return 0;
}