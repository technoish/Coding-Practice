#include <iostream>
#include <string>
#include <stack>

using namespace std;

string processString(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result; 
        st.pop();
    }
    return result;
}

int main() {
    string bob, alice;
    cin >> bob >> alice;

    string processedBob = processString(bob);
    string processedAlice = processString(alice);

    if (processedBob == processedAlice) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}