#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void modify_string(int n, string s) {
    vector<int> primes;
    for (char c : s) {
        if (isdigit(c)) {
            int num = c - '0';
            if (is_prime(num)) {
                primes.push_back(num);
            }
        }
    }

    int avg_prime = 0;
    if (!primes.empty()) {
        avg_prime = floor(accumulate(primes.begin(), primes.end(), 0) / (double)primes.size());
    }

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            int index;
            if (!primes.empty()) {
                index = num % avg_prime;
            } else {
                index = num;
            }
            s[i] = 'a' + index;
        }
    }
    cout << s << endl;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    modify_string(n, s);
    return 0;
}