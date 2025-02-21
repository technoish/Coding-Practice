
#include <iostream>
#include <vector>
using namespace std;

int countANDTriplets(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

                if ((arr[i] & arr[j] & arr[k]) == 0) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << countANDTriplets(arr) << endl;
    
    return 0;
}