#include <iostream>
#include <string>
#include <bitset>

std::string shiftAndAddBinaryStrings(int N, const std::string& A, const std::string& B) {
    unsigned long long a = std::bitset<64>(A).to_ullong();
    unsigned long long b = std::bitset<64>(B).to_ullong();

    unsigned long long leftShiftedA = a << N;
    unsigned long long rightShiftedB = b >> N;

    unsigned long long result = leftShiftedA + rightShiftedB;

    return std::bitset<128>(result).to_string().substr(std::bitset<128>(result).to_string().find('1'));
}

int main() {
    int N;
    std::string A, B;
    std::cin >> N;
    std::cin >> A;
    std::cin >> B;

    std::cout << shiftAndAddBinaryStrings(N, A, B) << std::endl;

    return 0;
}