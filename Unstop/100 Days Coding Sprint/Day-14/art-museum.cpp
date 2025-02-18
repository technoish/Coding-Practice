#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countOptimalPositions(int n, vector<pair<long long, long long>>& points) {
    vector<long long> x_coords, y_coords;

    for (auto& p : points) {
        x_coords.push_back(p.first);
        y_coords.push_back(p.second);
    }
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());
    
    long x_min = x_coords[(n - 1) / 2], x_max = x_coords[n / 2];
    long y_min = y_coords[(n - 1) / 2], y_max = y_coords[n / 2];
    long x_count = x_max - x_min + 1;
    long y_count = y_max - y_min + 1;
    
    return x_count * y_count;
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    cout << countOptimalPositions(n, points) << endl;
    
    return 0;
}