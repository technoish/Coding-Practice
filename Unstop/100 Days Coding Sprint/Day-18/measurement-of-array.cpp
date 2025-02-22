#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int user_logic(int n, vector<int>& arr) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {arr[i], i};
    }

    sort(v.begin(), v.end());

    map<int, int> last_occurrence;
    for (int i = 0; i < n; i++) {
        last_occurrence[v[i].first] = i;
    }

    long long measurement = 0;
    for (int i = 0; i < n; i++) {
        measurement = (measurement + v[i].second + last_occurrence[v[i].first]) % 1000000007;
    }

    return static_cast<int>(measurement);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = user_logic(n, arr);
    cout << result << endl;
    return 0;
}