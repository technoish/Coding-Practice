#include <iostream>
#include <vector>

using namespace std;

int find(int m) {
    if (m == 0) {
        return 0;
    }

    vector<bool> coins(m, false); 

    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j < m; j += i) {
            coins[j] = !coins[j]; 
        }
    }

    int headCount = 0;
    for (int i = 0; i < m; i++) {
        if (coins[i]) {
            headCount++;
        }
    }

    return headCount;
}

int main() {
    int m;
    cin >> m;
    int count = find(m);
    cout << count << endl;
    return 0;
}