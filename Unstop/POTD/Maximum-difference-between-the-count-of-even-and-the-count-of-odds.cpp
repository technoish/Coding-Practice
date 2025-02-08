#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_difference(const vector<int>& V) {
    int n = V.size();
    int max_diff = -1; 

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int even_count = 0;
            int odd_count = 0;
            for (int k = i; k <= j; ++k) {
                if (V[k] % 2 == 0) {
                    even_count++;
                } else {
                    odd_count++;
                }
            }
            if (even_count > 0 || odd_count > 0) { 
                max_diff = max(max_diff, even_count - odd_count);
            }
        }
    }

    return max_diff;
}

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    int result = max_difference(V);
    cout << result << endl;
    return 0;
}