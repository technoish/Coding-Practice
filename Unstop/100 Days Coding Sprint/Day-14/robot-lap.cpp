#include <bits/stdc++.h>
using namespace std;

string carReturnsToOrigin(int n, string moves) {
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(moves[i] == 'U') y++;
        else if(moves[i] == 'D') y--;
        else if(moves[i] == 'R') x++;
        else x--;
    }

    if(x == 0 && y == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int n;
    cin >> n;
    string moves;
    cin >> moves;

    string result = carReturnsToOrigin(n, moves);

    cout << result << '\n';

    return 0;
}
