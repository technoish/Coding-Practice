#include <iostream>
#include <vector>
using namespace std;

int highest_altitude(int n, vector<int> &l) {
    int max_altitude = 0, current_altitude = 0;
    for (int change : l) {
        current_altitude += change;
        max_altitude = max(max_altitude, current_altitude);
    }
    return max_altitude;
}

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    int result = highest_altitude(n, l);
    cout << result << endl;
    return 0;
}