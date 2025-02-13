#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    map<int, vector<int>> indices;
    for (int i = 0; i < n; ++i) {
        indices[sorted_a[i]].push_back(i);
    }

    if (indices.find(k) != indices.end()) {
        vector<int> result_indices = indices[k];
        cout << result_indices.size() << endl;
        for (int i = 0; i < result_indices.size(); i++) {
            cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}