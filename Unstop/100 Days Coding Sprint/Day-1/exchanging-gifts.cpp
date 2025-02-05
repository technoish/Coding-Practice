#include <iostream>
#include <vector>
using namespace std;

void find_youngest_member(int n, int m, vector<pair<int, int>> &gifts) {
    vector<int> gives(n + 1, 0), receives(n + 1, 0);

    for (const auto &gift : gifts) {
        gives[gift.first]++;
        receives[gift.second]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (gives[i] == 0 && receives[i] == n - 1) {
            cout << i << endl;
            return;
        }
    }

    cout << "-1" << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> gifts(m);
    for (int i = 0; i < m; ++i) {
        cin >> gifts[i].first >> gifts[i].second;
    }
    find_youngest_member(n, m, gifts);
    return 0;
}
