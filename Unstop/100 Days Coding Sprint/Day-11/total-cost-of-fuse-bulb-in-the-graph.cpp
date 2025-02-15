#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calculate_total_cost(int k, int n, int m, vector<pair<int, int>> &edges) {
    if (m == 0) return 0;

    vector<vector<int>> adj(n + 1);

    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }


    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(0); 
    visited[0] = true;
    
    int non_functional_count = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u != 0 && u % m == 0) {
            non_functional_count++;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return non_functional_count * k;
}

int main() {
    int k, n, m, len_graph;
    cin >> k >> n >> m >> len_graph;

    vector<pair<int, int>> graph(len_graph);
    for (int i = 0; i < len_graph; i++) {
        cin >> graph[i].first >> graph[i].second;
    }

    cout << calculate_total_cost(k, n, m, graph) << endl;
    return 0;
}
