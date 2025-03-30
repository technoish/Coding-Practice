#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int findFirstRepeatingIndex(const vector<int>& cards) {
    unordered_map<int, int> first_occurrence;
    unordered_set<int> repeating;
    
    for (int i = 0; i < cards.size(); i++) {
        if (first_occurrence.find(cards[i]) != first_occurrence.end()) {
            repeating.insert(cards[i]);
        } else {
            first_occurrence[cards[i]] = i + 1;
        }
    }
    
    if (!repeating.empty()) {
        int min_index = INT_MAX;
        for (int card : repeating) {
            min_index = min(min_index, first_occurrence[card]);
        }
        return min_index;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    cout << findFirstRepeatingIndex(cards) << endl;
    return 0;
}