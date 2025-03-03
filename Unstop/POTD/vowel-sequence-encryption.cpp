#include <bits/stdc++.h>
using namespace std;

int count_valid_sequences(int N, int P) {
    
    vector<vector<int>> trans={
        {1,3},
        {0,2},
        {3,4},
        {0,2},
        {1,4}
    };

    vector<long long>dp(5,1),temp(5,0);
    
    for(int i=2;i<=N;i++)
    {
        fill(temp.begin(),temp.end(),0);
        for(int v=0;v<5;v++)
        {
            for(int next: trans[v])
            {
                temp[next]=(temp[next]+dp[v])%P;
            }
        }
        dp=temp;
    }

    long long total=0;

    for(int i=0;i<5;i++)
    {
        total=(total+dp[i])%P;
    }

    return total;
}

int main() {
    int N, P;
    cin >> N >> P;
    int result = count_valid_sequences(N, P);
    cout << oct << result << endl;
    return 0;
}