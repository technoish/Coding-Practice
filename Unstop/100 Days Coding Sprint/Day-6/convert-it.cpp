#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> modify_array(int n, std::vector<int> arr) {
    std::vector<int> modified_arr(n);
    int max_so_far = 0;

    for (int i = 0; i < n; i++) {
        max_so_far = std::max(max_so_far, arr[i]); 
        modified_arr[i] = arr[i] + max_so_far;    
    }
    return modified_arr;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> modified_arr = modify_array(n, arr);
    for (int i = 0; i < modified_arr.size(); i++) {
        std::cout << modified_arr[i] << " ";
    }
    std::cout << std::endl; 
    return 0;
}