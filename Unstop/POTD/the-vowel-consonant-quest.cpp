#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_perfect_square_of_prime(int n) {
    if (n <= 0) return false;
    int root = std::sqrt(n);
    if (root * root != n) return false;
    return is_prime(root);
}

void check_qualification(const std::string &word) {
    int vowel_count = 0;
    int consonant_count = 0;

    for (char c : word) {
        char lower_c = std::tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
            vowel_count++;
        } else if (std::isalpha(c)) {
            consonant_count++;
        }
    }

    if (vowel_count < 2) {
        std::cout << "Disqualify" << std::endl;
        return;
    }

    if (consonant_count == 0){
        std::cout << "Disqualify" << std::endl;
        return;
    }

    if (is_perfect_square_of_prime(consonant_count)) {
        std::cout << "Qualify" << std::endl;
    } else {
        std::cout << "Disqualify" << std::endl;
    }
}

int main() {
    std::string word;
    std::getline(std::cin, word);

    check_qualification(word);
    return 0;
}