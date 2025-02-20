#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string firstPalindrome(const vector<string>& words) {
    for (const string& word : words) {
        string reversed_word = word;
        reverse(reversed_word.begin(), reversed_word.end());
        if (word == reversed_word) {
            return word;
        }
    }
    return "";
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "" << endl;
        return 0;
    }

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    string result = firstPalindrome(arr);
    cout << result << endl;

    return 0;
}