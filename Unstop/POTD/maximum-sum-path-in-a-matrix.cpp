#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int j, vector<vector<int>>& matrix, int M, int N, vector<vector<int>> &dp){
    if(i >= M || j >= N || j < 0 || i < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int result = 0;
    result = max(result, matrix[i][j] + dfs(i + 1, j, matrix, M, N, dp));
    result = max(result, matrix[i][j] + dfs(i + 1, j + 1, matrix, M, N, dp));
    result = max(result, matrix[i][j] + dfs(i + 1, j - 1, matrix, M, N, dp));
    return dp[i][j] = result;
}

void get_max_path_sum(vector<vector<int>>& matrix, int M, int N, int& max_sum, vector<int>& path) {
    int y, maxi = 0;
    for(int j = 0; j < N; j++){
        if(matrix[0][j] > maxi){
            maxi = matrix[0][j];
            y = j;
        }
    }
    vector<vector<int>> dp(M, vector<int> (N, -1));
    max_sum = dfs(0, y, matrix, M, N, dp);
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int max_sum;
    vector<int> path;
    get_max_path_sum(matrix, M, N, max_sum, path);

    cout << "Maximum Sum: " << max_sum << endl;

    return 0;
}