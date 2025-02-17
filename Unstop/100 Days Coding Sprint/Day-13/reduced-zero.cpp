#include <iostream>
#include <cmath>
using namespace std;

int smallest_prime_factor(int n) {
    if (n % 2 == 0) {
        return 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

int user_logic(int n) {
    int operations = 0;
    while (n > 0) {
        int spf = smallest_prime_factor(n);
        n -= spf;
        operations++;
    }
    return operations;
}

int main() {
    int n;
    cin >> n;

    int result = user_logic(n);
    cout << result << endl;

    return 0;
}