#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int minimum_addition(const string &str) {
    int cnt =0;
    string str1;
    str1 = str;
    str1[str.length()-1] = 'c';
    int n = str1.length();
    for (int i=0;i<n/2;i++) {
        if (str1[i] != str1[n-i-1]) cnt++;
    }
    if (cnt ==0) return 0;
    else if (str[0] == str[1]) return n-2;
    else return n-1;
}

int main() {
    string input;
    getline(cin, input);
    int result = minimum_addition(input);
    cout << result << endl;
    return 0;
}