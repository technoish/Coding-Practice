#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, int> freq;
    int A, B;
    
    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        freq[B] += A;  
    }

    int minFreq = INT_MAX, maxFreq = INT_MIN;
    int minNum = INT_MAX, maxNum = INT_MIN;

    for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        int num = it->first;
        int count = it->second;

        if (count > maxFreq || (count == maxFreq && num > maxNum)) {
            maxFreq = count;
            maxNum = num;
        }
        if (count < minFreq || (count == minFreq && num < minNum)) {
            minFreq = count;
            minNum = num;
        }
    }

    cout << abs(maxNum - minNum) << endl;
    return 0;
}
