#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

std::pair<std::string, std::vector<int>> user_logic(int n, std::vector<int> arr) {
    int sum= 0;
    for (int &it : arr) sum+=it;
    if (sum == 0) return {"IMPOSSIBLE", {}};
    sort(arr.begin(),arr.end());
    if (sum < 0) return {"POSSIBLE",arr};
    reverse(arr.begin(),arr.end());
    return {"POSSIBLE",arr};
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    auto result = user_logic(n, arr);
    
    if (result.first == "IMPOSSIBLE") {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::cout << "POSSIBLE" << std::endl;
        for (const auto& num : result.second) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}