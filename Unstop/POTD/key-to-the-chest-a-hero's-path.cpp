#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, vector<vector<char>> &v) {
    return (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != 'O');
}

int findSteps(vector<vector<char>> &v) {
    int n = v.size();
    int m = v[0].size();
    int tk = 0, startX = -1, startY = -1;
    vector<vector<int>> v1(n, vector<int>(m, 0));
    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'H') {
                startX = i;
                startY = j;
            } else if (v[i][j] == 'K') {
                v1[i][j] = s;
                s++;
                tk++;
            }
        }
    }
    int kk = (1 << tk) - 1;
    queue<tuple<int, int, int, int>> q;
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1 << tk, false)));
    q.push({startX, startY, 0, 0});
    vis[startX][startY][0] = true;

    while (!q.empty()) {
        int x, y, steps, keys;
        tie(x, y, steps, keys) = q.front();
        q.pop();
        if (v[x][y] == 'C' && keys == kk) {
            return steps;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny, n, m, v)) {
                int newKeys = keys;
                if (v[nx][ny] == 'K') {
                    newKeys |= (1 << (v1[nx][ny]));
                }
                if (!vis[nx][ny][newKeys]) {
                    if (v[nx][ny] == 'C') {
                        if (newKeys == kk) {
                            vis[nx][ny][newKeys] = true;
                            q.push({nx, ny, steps + 1, newKeys});
                        }
                    } else {
                        vis[nx][ny][newKeys] = true;
                        q.push({nx, ny, steps + 1, newKeys});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int result = findSteps(v);
    if (result == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}