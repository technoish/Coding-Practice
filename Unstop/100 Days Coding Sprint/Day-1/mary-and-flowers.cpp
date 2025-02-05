#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, t;
    cin>>N>>t;

    int a[N];
    for (int i = 0; i < N; i++) {
       int t;
       cin>>t;
       a[i] = t;
    }

    int i = 0, j = N - 1;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == t) {
            cout<<i<<" "<<j;
            break;
        } else if (sum < t) {
            i++;
        } else {
            j--;
        }
    } 
    return 0;
}