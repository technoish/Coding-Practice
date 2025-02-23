#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int count_valid_pins(int N) {
    long long count = 1;
    long long mod = 1e9 + 7;

    for (int i = 1; i <= N; i++) {
        if (is_prime(i)) {
            count = (count * 4) % mod;
        } else {
            count = (count * 5) % mod;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int result = count_valid_pins(N);
    cout << result << endl;
    return 0;
}