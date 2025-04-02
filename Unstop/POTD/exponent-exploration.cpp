#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::pair<int, int>> x_power_y_pairs(int n) {
    std::vector<std::pair<int, int>> pairs;
    if (n == 1) {
        pairs.push_back({1, 1});
        return pairs;
    }
    for (int x = 2; x <= n; ++x) {
        for (int y = 2; pow(x, y) <= n; ++y) {
            if (pow(x, y) == n) {
                pairs.push_back({x, y});
            }
        }
    }
    pairs.push_back({n, 1});
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> pairs = x_power_y_pairs(n);
    
    std::cout << pairs.size() << std::endl;
    
    for (const auto& pair : pairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    
    return 0;
}