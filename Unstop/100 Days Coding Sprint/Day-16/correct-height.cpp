#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = heightChecker(arr);
    cout << result << endl;
    return 0;
}

int heightChecker(vector<int>& heights) {
    int n = heights.size();
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());

    int diff_count = 0;
    for (int i = 0; i < n; i++) {
        if (heights[i] != expected[i]) {
            diff_count++;
        }
    }
    return diff_count;
}