#include <iostream>
#include <vector>
#include <sstream>
#include <functional>

bool is_single_valued_binary_tree(const std::vector<int>& values) {
    if (values.empty()) {
        return true;
    }

    int root_val = values[0];

    std::function<bool(int)> check_subtree = [&](int index) {
        if (index >= values.size() || values[index] == -1) {
            return true;
        }

        if (values[index] != root_val) {
            return false;
        }

        return check_subtree(2 * index + 1) && check_subtree(2 * index + 2);
    };

    return check_subtree(0);
}

int main() {
    std::vector<int> values;
    int val;
    while (std::cin >> val) {
        values.push_back(val);
    }
    bool result = is_single_valued_binary_tree(values);
    if (result) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
    return 0;
}