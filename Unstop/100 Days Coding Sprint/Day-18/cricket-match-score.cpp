#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

bool canScoreExactRuns(ll n, vector<ll>& arr) {
    queue<ll> q;
    vector<bool> visited(n, false);
    
    q.push(0); 
    visited[0] = true;
    
    while (!q.empty()) {
        ll current_score = q.front();
        q.pop();
        
        if (current_score == n - 1) {
            return true; 
        }
        
        for (ll i = 1; i <= arr[current_score]; i++) {
            ll next_score = current_score + i;
            if (next_score < n && !visited[next_score]) {
                visited[next_score] = true;
                q.push(next_score);
            }
        }
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << (canScoreExactRuns(n, arr) ? "true" : "false") << endl;
    
    return 0;
}
