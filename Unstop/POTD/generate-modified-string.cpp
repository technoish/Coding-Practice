#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void modify_string(int n, std::string s) {
    std::vector<int> primes;
    for (char c : s) {
        if (isdigit(c)) {
            int num = c - '0';
            if (is_prime(num)) {
                primes.push_back(num);
            }
        }
    }

    int unique_number = 0;
    if (!primes.empty()) {
        int sum = 0;
        for (int prime : primes) {
            sum += prime;
        }
        unique_number = floor(static_cast<double>(sum) / primes.size());
    }

    std::string result = "";
    for (char c : s) {
        if (isdigit(c)) {
            int num = c - '0';
            int index;
            if (unique_number != 0) {
                index = num % unique_number;
            } else {
                index = num;
            }
            result += static_cast<char>('a' + index);
        } else {
            result += c;
        }
    }
    std::cout << result << std::endl;
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    modify_string(n, s);
    return 0;
}