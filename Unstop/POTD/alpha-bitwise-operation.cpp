#include <iostream>
#include <vector>
#include <cassert>

int alpha_bitwise_operation(int n, std::vector<int>& arr) {
    int result = 0;
    for (int i = 0; i < 32; i++) { 
        int set_count = 0;
        for (int j = 0; j < n; j++) {
            if ((arr[j] >> i) & 1) {
                set_count++;
            }
        }
        if (set_count * 2 > n) {
            result |= (1 << i);
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    assert(arr.size() == n);

    int result = alpha_bitwise_operation(n, arr);
    std::cout << result << std::endl;

    return 0;
}