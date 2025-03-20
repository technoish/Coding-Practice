#include <iostream>
#include <vector>
#include <algorithm>

int beautiful_teams_count(int n, int k, std::vector<int>& strengths) {
    int count = 0;
    for (int i = 1; i < (1 << n); i++) {
        std::vector<int> team;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                team.push_back(strengths[j]);
            }
        }
        bool beautiful = true;
        for (int j = 0; j < team.size(); j++) {
            for (int l = j + 1; l < team.size(); l++) {
                if (abs(team[j] - team[l]) == k) {
                    beautiful = false;
                    break;
                }
            }
            if (!beautiful) {
                break;
            }
        }
        if (beautiful) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strengths[i];
    }
    int result = beautiful_teams_count(n, k, strengths);
    std::cout << result << std::endl;
    return 0;
}