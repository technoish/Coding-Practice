#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s,t;
    cin>>s>>t;
    int n=s.size();
    if(n!=t.size()){
        cout<<"false"<<endl;
        return 0;
    }
    int cnt=0,vnt=0;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    for(int i=0;i<n;i++){
        if(s[i]>t[i])   cnt++;
        else if(s[i]<t[i])  vnt++;
        else cnt++,vnt++;
    }
    if(cnt==n || vnt==n){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}