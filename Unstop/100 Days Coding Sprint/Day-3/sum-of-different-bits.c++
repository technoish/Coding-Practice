#include <iostream>
#include <string>

using namespace std;

long long int compareBits(string a, string b) {
    int n = a.length();
    int m = b.length();
    long long int totalDiffBits = 0;

    for (int i = 0; i <= m - n; i++) {
        int diffBits = 0;
        string sub = b.substr(i, n);
        for (int j = 0; j < n; j++) {
            if (a[j] != sub[j]) {
                diffBits++;
            }
        }
        totalDiffBits += diffBits;
    }

    return totalDiffBits;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << compareBits(a, b);
    return 0;
}