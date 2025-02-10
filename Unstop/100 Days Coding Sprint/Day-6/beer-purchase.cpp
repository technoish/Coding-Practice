#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long long maxBot(long long a[], long long n, long long x);

int main() {
    long long n, x;
    cin >> n >> x;
    long long a[n];
    for(long long i = 0; i < n; i++)
        cin >> a[i];
    cout << maxBot(a, n, x) << endl;
    return 0;
}

long long maxBot(long long a[], long long n, long long x) {

    sort(a,a+n);
    int i = 0;
    int j = n-1;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
    }

    long long index = 0;
    long long cnt = 0;
    long long dec = 0;

    while(j >= 0){
        if(sum + (index * (n-dec)) <= x){
            cnt += (n-dec);
            index++;
        }
        else{
            sum -= (a[j]);
            j--;
            dec++;
        }
    }
    return cnt;

    
}