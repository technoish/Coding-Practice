#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

int find_longest_palindrome(int n, int m, std::vector<std::string> &strings) {
    std::unordered_set<std::string> unique_strings(strings.begin(), strings.end());
    std::vector<std::string> unique_vec(unique_strings.begin(), unique_strings.end());
    n = unique_vec.size();

    int palindrome_length = 0;
    std::string middle_string = "";

    std::vector<std::pair<std::string, std::string>> pairs;
    for (int i = 0; i < n; i++) {
        std::string reversed_string = unique_vec[i];
        std::reverse(reversed_string.begin(), reversed_string.end());
        if (unique_vec[i] == reversed_string) {
            if (unique_vec[i] > middle_string) {
                middle_string = unique_vec[i];
            }
        } else {
            for (int j = i + 1; j < n; j++) {
                if (reversed_string == unique_vec[j]) {
                    pairs.push_back({unique_vec[i], unique_vec[j]});
                }
            }
        }
    }

    palindrome_length = pairs.size() * 2 * m;
    if (!middle_string.empty()) {
        palindrome_length += m;
    }

    return palindrome_length;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }
    
    int result = find_longest_palindrome(n, m, strings);
    std::cout << result << std::endl;
    return 0;
}