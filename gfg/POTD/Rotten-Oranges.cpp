class Solution
{
public:
    int orangesRotting(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), t = 0, f = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                    q.push({i, j});
                else if (mat[i][j] == 1)
                    f++;
            }
        if (!f)
            return 0;
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            int sz = q.size();
            bool ch = false;
            while (sz--)
            {
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                for (auto &dir : d)
                {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || y < 0 || x >= n || y >= m || mat[x][y] != 1)
                        continue;
                    mat[x][y] = 2;
                    q.push({x, y});
                    f--;
                    ch = true;
                }
            }
            if (ch)
                t++;
        }
        return f ? -1 : t;
    }
};