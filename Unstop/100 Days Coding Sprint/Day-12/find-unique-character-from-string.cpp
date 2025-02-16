#include <iostream>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

void determine_winner(int N, string smit_str, string joy_str) {
    set<char> smit_unique_chars;
    set<char> joy_unique_chars;

    for (char c : smit_str) {
        smit_unique_chars.insert(c);
    }

    for (char c : joy_str) {
        joy_unique_chars.insert(c);
    }

    double smit_mean = (double)smit_unique_chars.size() / N;
    double joy_mean = (double)joy_unique_chars.size() / N;

    if (smit_mean > joy_mean) {
        cout << "SMIT" << endl;
    } else if (joy_mean > smit_mean) {
        cout << "JOY" << endl;
    } else {
        cout << "TIE" << endl;
    }
}

int main() {
    int N;
    string smit_str, joy_str;

    cin >> N;
    cin >> smit_str;
    cin >> joy_str;

    determine_winner(N, smit_str, joy_str);

    return 0;
}