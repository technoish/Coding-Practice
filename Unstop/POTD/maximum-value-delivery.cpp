#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    vector<pair<long long, long long>> v(N);
    for (long long i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<long long> C(K);
    for (long long i = 0; i < K; i++) {
        cin >> C[i];
    }

    sort(C.begin(), C.end());
    sort(v.begin(), v.end());

    priority_queue<long long> pq;
    long long ans = 0, idx1 = 0, idx2 = 0;

    while (idx1 < v.size() && idx2 < C.size()) {
        while (idx1 < v.size() && v[idx1].first <= C[idx2]) {
            pq.push(v[idx1].second);
            idx1++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        idx2++;
    }

    cout << ans << endl;
    return 0;
}