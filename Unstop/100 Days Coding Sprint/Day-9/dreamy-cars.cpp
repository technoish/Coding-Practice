#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    if(n%2==0){
        cout<<0<<endl;
        return 0;
    } 
    int tmp=0;
    for(int i=0;i<n;i+=2)    tmp^=a[i];
    cout<<tmp<<endl;
    return 0;
}

