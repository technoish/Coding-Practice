#include <iostream>
#include <vector>
#include <string>

int matching_count(const std::vector<std::vector<std::string>>& items, const std::string& ruleKey, const std::string& ruleValue) {
    int count = 0;
    int key_index = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
    for (const auto& item : items) {
        if (item[key_index] == ruleValue) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> items(n, std::vector<std::string>(3));
    for (int i = 0; i < n; i++) {
        std::cin >> items[i][0] >> items[i][1] >> items[i][2];
    }
    std::string ruleKey, ruleValue;
    std::cin >> ruleKey >> ruleValue;
    int result = matching_count(items, ruleKey, ruleValue);
    std::cout << result << std::endl;
    return 0;
}