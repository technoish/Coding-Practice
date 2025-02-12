#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;  
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];  
    }

    vector<int> prefix(N + 1, 0); 
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }  

    long long SE = 0; 
    long long SO = 0;  
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int subarrayXOR = prefix[j] ^ prefix[i];  
            if ((j - i) % 2 == 0) { 
                SE += subarrayXOR;
            } else {  
                SO += subarrayXOR;
            }
        }
    }

    
    long long G = abs(SE - SO);
    cout << G << endl;

    return 0;
}