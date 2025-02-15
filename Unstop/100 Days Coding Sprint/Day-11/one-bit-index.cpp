#include <iostream>
#include <vector>

int count_good_indices(int n, std::vector<int> &arr) {
    int count = 0;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        int set_bits = 0;
        int temp_sum = current_sum;
        while (temp_sum > 0) {
            set_bits += (temp_sum & 1);
            temp_sum >>= 1;
        }

        if (set_bits == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = count_good_indices(n, arr);
    std::cout << result << std::endl;

    return 0;
}