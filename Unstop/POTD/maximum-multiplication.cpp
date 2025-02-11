#include <iostream>
#include <vector>
#include <numeric>

int maximum(const std::vector<int>& arr) {
    int n = arr.size();
    long long max_product = 0;

    for (int i = 0; i < n; ++i) {
        long long sum1 = 0;
        long long sum2 = 0;

        if (i >= 0) {
            sum1 = std::accumulate(arr.begin(), arr.begin() + i + 1, 0LL);
        }

        if (i < n - 1) {
            sum2 = std::accumulate(arr.begin() + i + 1, arr.end(), 0LL);
        }
        
        long long current_product = sum1 * sum2;
        max_product = std::max(max_product, current_product);
    }

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = maximum(arr);
    std::cout << result << std::endl;

    return 0;
}