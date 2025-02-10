#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int

int divide_garden(int n, std::vector<int> &A) {
   
    ll tot=0, sm=0;
    vector<ll>pre(n);
    for(auto pr: A) sm+=pr;
    pre[0]=A[0];
    for(int i=1; i<n; ++i){
        pre[i]=pre[i-1]+A[i];
    }
    ll i=1, j=1;
    while(j<n-1){
        ll s1=pre[i-1], s3=pre[j+1];
        ll s2=sm-s1-s3;
        if((s1+s3)<=s2){i++; j=max(j,i);}
        else{
            j++; tot++;
        }
    }
    return tot;

}

int main() {
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int j = 0; j < n; j++) {
            std::cin >> A[j];
        }
        

        int result = divide_garden(n, A);
        std::cout << result << std::endl;
    }
    
    return 0;
}

