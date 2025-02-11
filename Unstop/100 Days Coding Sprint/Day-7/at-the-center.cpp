#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    double distance; 

    Point(int _x, int _y) : x(_x), y(_y) {
        distance = sqrt(x * x + y * y);
    }
    bool operator<(const Point& other) const {
        return distance < other.distance;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    int k;
    cin >> k;

    sort(points.begin(), points.end()); 

    for (int i = 0; i < k; ++i) {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}