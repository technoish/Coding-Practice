#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_size = 0;
    vector<int> queue;

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < queue.size(); j++) {
            if (queue[j] + 5000 <= arr[i]) {  
                queue.erase(queue.begin() + j);
                j--; 
            }
        }

        queue.push_back(arr[i]); 
        max_size = max(max_size, (int)queue.size());
    }

    cout << max_size << endl;

    return 0;
}