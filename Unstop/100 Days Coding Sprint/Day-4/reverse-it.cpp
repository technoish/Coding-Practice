#include <iostream>
#include <string>
#include <algorithm>
#include <sstream> 

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line); 
    string s;
    char ch;

    ss >> s >> ch; 

    int last_occurrence = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ch) {
            last_occurrence = i;
        }
    }

    if (last_occurrence != -1) {
        reverse(s.begin() + last_occurrence, s.end());
    }

    cout << s << endl;

    return 0;
}