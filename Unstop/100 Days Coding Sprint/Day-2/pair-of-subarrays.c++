#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int countEqualSumPairs(vector<int>& A) {
    int N = A.size();
    vector<int> prefixSum(N + 1, 0);
    unordered_map<int, vector<pair<int, int>>> sumMap;
    int count = 0;
    
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    }
    
    for (int L = 1; L <= N; L++) {
        for (int R = L; R <= N; R++) {
            int sum = prefixSum[R] - prefixSum[L - 1];
            if (sumMap.find(sum) != sumMap.end()) {
                for (auto& p : sumMap[sum]) {
                    if (p.second < L) {
                        count++;
                    }
                }
            }
            sumMap[sum].push_back({L, R});
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << countEqualSumPairs(A) << endl;
    return 0;
}