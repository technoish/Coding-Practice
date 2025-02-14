#include <iostream>
#include <string>

std::string follows_ab_pattern(const std::string& s) {
    bool b_encountered = false;
    for (char c : s) {
        if (c == 'b') {
            b_encountered = true;
        } else if (c == 'a' && b_encountered) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::string result = follows_ab_pattern(s);
    std::cout << result << std::endl;

    return 0;
}