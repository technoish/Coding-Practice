#include <iostream>
#include <vector>

int user_logic(int n, std::vector<int> &arr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] ^ arr[j]) <= (arr[i] & arr[j])) {
                count++;
            }
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
    int result = user_logic(n, arr);
    std::cout << result << std::endl;
    return 0;
}