#include <iostream>
#include <vector>
using namespace std;

int main() {
    int totalBoxes, n;
    cin >> totalBoxes;
    n = totalBoxes / 2;

    vector<int> freq(10001, 0); 
    int label;

    for (int i = 0; i < totalBoxes; i++) {
        cin >> label;
        freq[label]++;
        if (freq[label] == n) {  
            cout << label << endl;
            return 0;
        }
    }

    return 0;
}
