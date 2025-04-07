class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adj, visited, recStack))
                {
                    return true;
                }
            }
            else if (recStack[neighbor])
            {
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recStack))
                {
                    return true;
                }
            }
        }

        return false;
    }
};