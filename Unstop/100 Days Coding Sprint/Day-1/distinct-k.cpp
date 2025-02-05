#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findKthUniqueString(int N, vector<string>& strings, int k) {
    unordered_map<string, int> freq;
    vector<string> uniqueStrings;
   
    for (const string &s : strings) {
        freq[s]++;
        if (freq[s] == 1) { 
            uniqueStrings.push_back(s);
        }
    }

    vector<string> validUniqueStrings;
    for (const string &s : uniqueStrings) {
        if (freq[s] == 1) {
            validUniqueStrings.push_back(s);
        }
    }

    if (k > validUniqueStrings.size()) {
        cout << "-1" << endl;
    } else {
        cout << validUniqueStrings[k - 1] << endl; 
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> strings(N);
    
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    int k;
    cin >> k;

    findKthUniqueString(N, strings, k);
    return 0;
}