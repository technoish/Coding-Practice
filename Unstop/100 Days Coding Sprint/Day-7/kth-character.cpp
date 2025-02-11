#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << s[n - k] << endl;

    return 0;
}