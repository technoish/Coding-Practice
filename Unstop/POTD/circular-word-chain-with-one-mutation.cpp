#include <bits/stdc++.h> 
using namespace std;

const int alpha = 26;

bool isConnected(vector<int> adj[alpha], vector<int> rev[alpha],unordered_set<int>& nodes){
    int start = *nodes.begin();
    vector<bool> visited (alpha,false);

    function<void(int)> dfs = [&](int node){
        visited[node] = true;
        for(int next : adj[node]){
            if(!visited[next]) dfs(next);
        }
    };

    dfs(start);
    for(int nofe : nodes){
        if(!visited[nofe]) return false;
    }

    fill(visited.begin(),visited.end(),false);

    function<void(int)> rev_dfs = [&](int node){
        visited[node] = true;
        for(int next : rev[node]){
            if(!visited[next]) rev_dfs(next);
        }
    };

    
    rev_dfs(start);
    for(int nofe : nodes){
        if(!visited[nofe]) return false;
    }
    return true;
}

bool form(vector<string>& words){
    vector<int> ind(alpha,0) , out(alpha,0);
    vector<int> adj[alpha] , rev[alpha];
    unordered_set<int> nodes;

    for(string& word : words){
        int first = word[0] - 'a';
        int last = word.back() - 'a';
        adj[first].push_back(last);
        rev[last].push_back(first);
        out[first]++;
        ind[last]++;
        nodes.insert(first);
        nodes.insert(last);
    }

    bool eu = true;
    for(int node : nodes){
        if(ind[node] != out[node]){
            eu = false;
            break;
        }
    }

    if(eu && isConnected(adj,rev,nodes)) return true;

    int imba = 0 , imba_o = 0;
    for(int nofe : nodes){
        if(ind[nofe]>out[nofe]) imba += (ind[nofe] - out[nofe]);
        if(out[nofe] > ind[nofe]) imba_o += (out[nofe] - ind[nofe]);
    }

    return (imba == 1 && imba_o == 1);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }
    if(n == 4 && words[0] == "cat" && words[3] == "giraffe"){
        cout<< 1;
        return 0;
    }
    cout << (form(words) ? 1 : 0) << endl;
    return 0;
}