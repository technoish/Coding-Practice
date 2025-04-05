class Solution {
    public:
      int countIslands(vector<vector<char>>& grid) {
          int n = grid.size(), m = grid[0].size(), ans = 0;
          function<void(int,int)> f = [&](int i, int j){
              if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'W') return;
              grid[i][j] = 'W';
              for(int a = -1; a <= 1; a++) 
                  for(int b = -1; b <= 1; b++) 
                      f(i + a, j + b);
          };
          for(int i = 0; i < n; i++)
              for(int j = 0; j < m; j++)
                  if(grid[i][j] == 'L') { ans++; f(i, j); }
          return ans;
      }
  };