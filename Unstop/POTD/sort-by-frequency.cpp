#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

void frequency_sort(std::string& s) {
    std::unordered_map<char, int> freq;
    std::vector<std::pair<char, int>> charFreq;

    for (char c : s) {
        freq[c]++;
    }

    for (auto it = freq.begin(); it != freq.end(); it++) {
        charFreq.push_back({it->first, it->second});
    }

    std::sort(charFreq.begin(), charFreq.end(), [&](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return s.find(a.first) < s.find(b.first);
        }
    });

    s = "";
    for (auto it = charFreq.begin(); it != charFreq.end(); it++) {
        s.append(it->second, it->first);
    }
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    frequency_sort(s);
    std::cout << s << std::endl;
    return 0;
}