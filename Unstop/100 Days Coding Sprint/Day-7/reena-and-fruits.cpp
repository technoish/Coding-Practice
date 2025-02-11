#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n2;
    cin >> n2;

    vector<int> nums(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int max_sum = 0;
    for (int i = 0; i < n2; i += 2) {
        max_sum += min(nums[i], nums[i + 1]);
    }

    cout << max_sum << endl;

    return 0;
}