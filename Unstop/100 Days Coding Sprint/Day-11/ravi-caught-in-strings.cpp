#include <iostream>
#include <string>
#include <algorithm>

int longest_palindromic_substring_length(int n, std::string s) {
    if (n == 0) {
        return 0;
    }

    int max_length = 1; 

    for (int i = 0; i < n; i++) {
       
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            max_length = std::max(max_length, right - left + 1);
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            max_length = std::max(max_length, right - left + 1);
            left--;
            right++;
        }
    }

    return max_length;
}

int main() {
    int n;
    std::string s;

    std::cin >> n >> s;

    int result = longest_palindromic_substring_length(n, s);
    std::cout << result << std::endl;

    return 0;
}