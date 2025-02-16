#include <iostream>
#include <vector>
#include <set>

void calculate_sum(const std::vector<std::vector<int>>& matrix, int n, int k) {
    std::set<std::pair<int, int>> used;
    int main_diag_sum = 0;


    for (int i = 0; i < n; i++) {
        if (used.find({i, i}) == used.end()) {
            main_diag_sum += matrix[i][i];
            used.insert({i, i});
        }
        if (i > 0 && used.find({i - 1, i}) == used.end()) {
            main_diag_sum += matrix[i - 1][i];
            used.insert({i - 1, i});
        }
        if (i < n - 1 && used.find({i + 1, i}) == used.end()) {
            main_diag_sum += matrix[i + 1][i];
            used.insert({i + 1, i});
        }
         if (i > 0 && used.find({i, i-1}) == used.end()) {
            main_diag_sum += matrix[i][i-1];
            used.insert({i, i-1});
        }
        if (i < n - 1 && used.find({i, i+1}) == used.end()) {
            main_diag_sum += matrix[i][i+1];
            used.insert({i, i+1});
        }
    }

    int border_sum = 0;
    for (int i = 0; i < n; i++) {
        if (used.find({0, i}) == used.end()) {
            border_sum += matrix[0][i];
            used.insert({0, i});
        }
        if (used.find({n - 1, i}) == used.end()) {
            border_sum += matrix[n - 1][i];
            used.insert({n - 1, i});
        }
        if (i > 0 && i < n - 1 && used.find({i, 0}) == used.end()) {
            border_sum += matrix[i][0];
            used.insert({i, 0});
        }
        if (i > 0 && i < n - 1 && used.find({i, n - 1}) == used.end()) {
            border_sum += matrix[i][n - 1];
            used.insert({i, n - 1});
        }
    }

    int central_sum = 0;
    int start_row = (n - k) / 2;
    int start_col = (n - k) / 2;

    for (int i = start_row; i < start_row + k; i++) {
        for (int j = start_col; j < start_col + k; j++) {
            if (used.find({i, j}) == used.end()) {
                central_sum += matrix[i][j];
                used.insert({i, j});
            }
        }
    }

    std::cout << main_diag_sum + border_sum + central_sum << std::endl;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    calculate_sum(matrix, n, k);
    return 0;
}