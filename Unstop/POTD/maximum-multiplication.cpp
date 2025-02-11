#include <iostream>
#include <vector>
#include <numeric>

long long maximum(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0; 

    std::vector<long long> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    long long max_product = 0;

    for (int i = 0; i < n - 1; i++) {
        long long sum1 = prefix_sum[i + 1];
        long long sum2 = prefix_sum[n] - sum1;

        max_product = std::max(max_product, sum1 * sum2);
    }

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << maximum(arr) << std::endl;
    return 0;
}
