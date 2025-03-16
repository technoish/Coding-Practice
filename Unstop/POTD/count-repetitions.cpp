#include <iostream>
#include <string>
using namespace std;

int number_of_days_when_subsequence(string S, string T) {
    int n = S.length();
    int m = T.length();
    for (int days = 1; ; days++) {
        string current_string = "";
        for (int i = 0; i < days; i++) {
            current_string += S;
        }
        int i = 0, j = 0;
        while (i < current_string.length() && j < m) {
            if (current_string[i] == T[j]) {
                j++;
            }
            i++;
        }
        if (j == m) {
            return days;
        }
    }
}

int main() {
    string S, T;
    cin >> S >> T;
    int result = number_of_days_when_subsequence(S, T);
    cout << result << endl;
    return 0;
}