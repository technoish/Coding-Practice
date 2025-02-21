#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int minTimeToType(const std::string& word) {
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());

    int totalSeconds = 0;
    char current = 'a';

    for (char target : sortedWord) {
        int clockwiseDist = std::abs(target - current);
        int counterClockwiseDist = 26 - clockwiseDist;
        int moveTime = std::min(clockwiseDist, counterClockwiseDist);

        totalSeconds += moveTime + 1; 
        current = target;
    }

    return totalSeconds;
}

int main() {
    std::string word;
    std::cin >> word;
    int result = minTimeToType(word);
    std::cout << result << std::endl;
    return 0;
}