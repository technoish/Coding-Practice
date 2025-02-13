#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> user_logic(int n, int m, std::vector<int> prices, std::vector<int> budgets) {
    std::vector<int> results;
    std::multiset<int> available_tickets;
    for (int price : prices) {
        available_tickets.insert(price);
    }

    for (int budget : budgets) {
        auto it = available_tickets.lower_bound(budget + 1);
        if (it == available_tickets.begin()) {
            results.push_back(-1);
        } else {
            --it;
            results.push_back(*it);
            available_tickets.erase(it);
        }
    }
    return results;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    std::vector<int> budgets(m);
    for (int i = 0; i < m; i++) {
        std::cin >> budgets[i];
    }

    std::vector<int> results = user_logic(n, m, prices, budgets);
    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}