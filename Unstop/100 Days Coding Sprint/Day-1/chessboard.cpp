#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin>> s;
    char col = s[0];
    int row = s[1] - '0';
    int colNumber = col - 'a' + 1;
    int sum = colNumber + row;
    if(sum%2 == 0){
        cout << "Black";
    }else{
        cout << "White";
    }   
    return 0;
}