#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largest_pack(int n) {
    for (int i = n;i >= 0;i--) {
        if ((i & (i-1)) == 0) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n; 
    int result = largest_pack(n);
    std::cout << result << std::endl;

    return 0;
}