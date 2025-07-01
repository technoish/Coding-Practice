#include <algorithm>
void solve(string str, vector<string>& ans, int index){
        //base case
        if(index >= str.size()){
            ans.push_back(str);
            return;
        }

        for(int j = index; j < str.size(); j++){
            swap(str[index], str[j]);
            solve(str, ans, index + 1);
            // backtracking
            swap(str[index], str[j]);
        }
}
vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end());
    return ans;
}