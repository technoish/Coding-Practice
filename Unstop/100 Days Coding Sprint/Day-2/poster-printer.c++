#include <iostream>
#include <string>
using namespace std;

bool isPrintable(int N, string s) {
    bool hasB = false, hasR = false;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'W') {
            if (hasB ^ hasR) return false; 
            hasB = hasR = false;
        } else if (s[i] == 'B') {
            hasB = true;
        } else if (s[i] == 'R') {
            hasR = true;
        }
    }
    return !(hasB ^ hasR); 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        cout << (isPrintable(N, s) ? "YES" : "NO") << endl;
    }
    return 0;
}
