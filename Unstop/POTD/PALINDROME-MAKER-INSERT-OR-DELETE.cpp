#include <bits/stdc++.h>
using namespace std;
void user_logic1(int n, int K, std::string S, int& result_count, std::string& result_string) {
    vector<unordered_set<string>> dp(K + 1);
    dp[0].insert(S);
    
    for (int k = 1; k <= K; k++) {
        for (const string &prev : dp[k - 1]) {
            for (int i = 0; i < prev.size(); i++) {
                string temp = prev;
                temp.erase(i, 1);
                dp[k].insert(temp);
            }
            for (char c = 'a'; c <= 'z'; c++) {
                for (int i = 0; i <= prev.size(); i++) {
                    string temp = prev;
                    temp.insert(i, 1, c);
                    dp[k].insert(temp);
                }
            }
        }
    }
    
    set<string> finalPalindromes;
    for (const string &str : dp[K]) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (str == rev) finalPalindromes.insert(str);
    }
    result_count = finalPalindromes.size();
    if(result_count == 0){
        result_count = -1;
        return;
    }
    result_string = *finalPalindromes.begin();
}
bool isPalindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
unordered_map<string, bool> memo;
void palindromes(string s, int k, set<string> &st){
    if(k == 0){
        if(isPalindrome(s)){
            st.insert(s);
        }
        return;
    }
    if(memo[s] == true)
        return;
    for(int i = 0; i < s.size(); i++){
        string temp = s;
        temp.erase(i, 1);
        palindromes(temp, k - 1, st);
    }
    for(int i = 0; i <= s.size(); i++){
        for(char ch = 'a'; ch <= 'z'; ch++){
            string temp = s;
            temp.insert(temp.begin() + i, ch);
            palindromes(temp, k - 1, st);
        }
    }
    memo[s] = true;
}
void user_logic(int n, int K, std::string S, int& result_count, std::string& result_string) {
    set<string> st;
    palindromes(S, K, st);
    if(st.empty())
        result_count = -1;
    else{
        result_count = st.size();
        result_string = *st.begin();
    }
}

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    
    int result_count;
    std::string result_string;
    
    user_logic(n, k, s, result_count, result_string);
    
    if (result_count == -1) {
        std::cout << result_count << std::endl;
    } else {
        std::cout << result_count << std::endl;
        std::cout << result_string << std::endl;
    }
    
    return 0;
}