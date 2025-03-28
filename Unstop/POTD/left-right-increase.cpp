#include <iostream>
#include <vector>

using namespace std;

int processData(int size, int days, vector<int>& elements) {
    if (size == 1) {
        return 0;
    }
    
    vector<int> extra(size, 0);
    for (int i = 0; i < size; i++) {
        if (elements[i] > 0) {
            extra[i] = elements[i];
        }
    }
    
    for (int d = 0; d < days; d++) {
        vector<int> newExtra = extra;
        for (int i = 0; i < size; i++) {
            if (extra[i] > 0) {
                if (i > 0) {
                    newExtra[i - 1] += 2;
                }
                if (i < size - 1) {
                    newExtra[i + 1] += 2;
                }
            }
        }
        extra = newExtra;
    }
    
    int totalIncrease = 0;
    for (int i = 0; i < size; i++) {
        totalIncrease += extra[i] - elements[i];
    }
    return totalIncrease;
}

int main() {
    int size, days;
    cin >> size >> days;
    vector<int> elements(size);
    for (int i = 0; i < size; i++) {
        cin >> elements[i];
    }
    
    int result = processData(size, days, elements);
    cout << result << endl;
    
    return 0;
}