class Solution {
    public:
          void prov(int node, vector<int>&ans, vector<int>&vis, vector<vector<int>>&adj){
              vis[node] = 1;
              ans.push_back(node);
              for(auto it: adj[node]){
                  if(!vis[it]){
                      prov(it, ans, vis, adj);
                  }
              }
              return;
          }
          vector<int> dfs(vector<vector<int>>& adj) {
              int n = adj.size();
              vector<int>vis(n, 0);
              vector<int>ans;
              prov(0, ans, vis, adj);
              return ans;
          }
  };