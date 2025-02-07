#include <iostream>
#include <vector>
#include <string>

std::string user_logic(const std::string& word) {
    std::string result = word;
    size_t pos = result.find("nancy");

    if (pos == std::string::npos) return "-1"; 

    while (pos != std::string::npos) { 
        result.replace(pos, 5, "sanvi"); 
        pos = result.find("nancy", pos + 5); 
    }
    return result;
}

int main() {
    int T;
    std::cin >> T;
    
    std::vector<std::string> testCases(T);
    for (int i = 0; i < T; ++i) {
        std::cin >> testCases[i];
    }
    
    for (const auto& word : testCases) {
        std::string result = user_logic(word);
        std::cout << result << std::endl;
    }
    
    return 0;
}