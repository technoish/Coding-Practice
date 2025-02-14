#include <iostream>
#include <string>

using namespace std;

int user_logic(int n, string s) {
    int max_depth = 0;
    int current_depth = 0;
    for (char c : s) {
        if (c == '(') {
            current_depth++;
            max_depth = max(max_depth, current_depth);
        } else if (c == ')') {
            if (current_depth > 0) {
                current_depth--;
            }
        }
    }
    return max_depth;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int result = user_logic(n, s);
    cout << result << endl;
    return 0;
}