#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int count_characters(const std::vector<std::string>& words, const std::string& chars) {
    int totalLength = 0;
    std::unordered_map<char, int> charCounts;

    for (std::string::const_iterator it = chars.begin(); it != chars.end(); ++it) {
        char c = *it;
        charCounts[c]++;
    }

    for (std::vector<std::string>::const_iterator word_it = words.begin(); word_it != words.end(); ++word_it) {
        const std::string& word = *word_it;
        std::unordered_map<char, int> wordCounts;
        bool goodWord = true;

        for (std::string::const_iterator it = word.begin(); it != word.end(); ++it) {
            char c = *it;
            wordCounts[c]++;
        }

        for (std::unordered_map<char, int>::const_iterator it = wordCounts.begin(); it != wordCounts.end(); it++) {
            char c = it->first;
            int count = it->second;
            if (charCounts.find(c) == charCounts.end() || charCounts.at(c) < count) {
                goodWord = false;
                break;
            }
        }

        if (goodWord) {
            totalLength += word.length();
        }
    }

    return totalLength;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }
    std::string chars;
    std::cin >> chars;

    int result = count_characters(words, chars);
    std::cout << result << std::endl;
    return 0;
}