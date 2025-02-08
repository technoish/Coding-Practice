#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ops(n);
    for (int i = 0; i < n; i++) {
        cin >> ops[i];
    }

    stack<int> scores;

    for (const string& op : ops) {
        if (op == "+") {
            int score2 = scores.top();
            scores.pop();
            int score1 = scores.top();
            scores.push(score2); 
            scores.push(score1 + score2);
        } else if (op == "D") {
            scores.push(scores.top() * 2);
        } else if (op == "C") {
            scores.pop();
        } else {
            scores.push(stoi(op));
        }
    }

    int sum = 0;
    while (!scores.empty()) {
        sum += scores.top();
        scores.pop();
    }

    cout << sum << endl;

    return 0;
}