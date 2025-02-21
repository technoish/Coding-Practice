#include <iostream>
#include <string>

#define MOD 1000000007

int homogenous_substring(const std::string &s) {
    int n = s.length();
    long long count = 0;
    int current_length = 0;

    for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] == s[i - 1]) {
            current_length++;
        } else {
            current_length = 1;
        }
        count = (count + current_length) % MOD; 
    }

    return static_cast<int>(count); 
}

int main() {
    std::string s;
    std::cin >> s;

    int result = homogenous_substring(s);
    std::cout << result << std::endl;

    return 0;
}