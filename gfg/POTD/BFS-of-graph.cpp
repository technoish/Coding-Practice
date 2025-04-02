class Solution {
    public:
      vector<int> bfs(vector<vector<int>> &adj) {
          int n = adj.size();
          vector<int> BFSResult;
          vector<bool> vis(n, false);
          queue<int> q;
          
          vis[0] = true;
          q.push(0);
          
          while(!q.empty()){
              int node = q.front();
              q.pop();
              BFSResult.push_back(node);
              
              for(int neighbor : adj[node]){
                  if(!vis[neighbor]){
                      vis[neighbor] = true;
                      q.push(neighbor);
                  }
              }
          }
          return BFSResult;
      }
  };
