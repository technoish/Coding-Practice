#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void interpret(const string& s) {
    unordered_map<string, string> enigma_codes = {
        {"S", "send"},
        {"[]", "the"},
        {"[sps]", "ships"}
    };

    string result = "";
    size_t i = 0;
    while (i < s.length()) {
        string token;
        if (s[i] == '[') {
            size_t j = i + 1;
            while (j < s.length() && s[j] != ']') {
                j++;
            }
            if (j < s.length()) { 
                token = s.substr(i, j - i + 1);
                i = j + 1; 
            } else { 
                i++;
                continue;
            }
        } else {
            token = s.substr(i, 1); 
            i++;
        }

        if (enigma_codes.count(token)) {
            result += enigma_codes[token] + " ";
        }
    }

    if (!result.empty()) {
        result.pop_back(); 
    }

    cout << result << endl;
}

int main() {
    string s;
    getline(cin, s);

    interpret(s);

    return 0;
}