#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long totalSetBits = 0;

    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            totalSetBits += (num & 1);
            num >>= 1; 
        }
    }

    cout << totalSetBits << endl;

    return 0;
}