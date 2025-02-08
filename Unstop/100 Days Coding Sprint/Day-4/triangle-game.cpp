#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> row(n + 1);
    row[0] = 1;

    for (int i = 0; i <= n; ++i) {
        vector<long long> next_row(i + 1);
        next_row[0] = 1;
        for (int j = 1; j < i; ++j) {
            next_row[j] = row[j - 1] + row[j];
        }
        next_row[i] = 1;

        if (i == n) {
            for (int j = 0; j <= i; ++j) {
                cout << next_row[j] << " ";
            }
            cout << endl;
        }
        row = next_row;
    }

    return 0;
}