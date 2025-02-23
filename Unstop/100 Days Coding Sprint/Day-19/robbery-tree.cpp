#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map> 

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertLevelOrder(const std::vector<std::string>& arr, int i) {
    if (i >= arr.size() || arr[i] == "null") {
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(arr[i]));
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    return root;
}

int rob(TreeNode* root, std::unordered_map<TreeNode*, int>& memo) {
    if (root == nullptr) {
        return 0;
    }

    if (memo.count(root)) {
        return memo[root];
    }

    int rob_root = root->val;
    if (root->left) {
        rob_root += rob(root->left->left, memo);
        rob_root += rob(root->left->right, memo);
    }
    if (root->right) {
        rob_root += rob(root->right->left, memo);
        rob_root += rob(root->right->right, memo);
    }

    int not_rob_root = 0;
    if (root->left) {
        not_rob_root += rob(root->left, memo);
    }
    if (root->right) {
        not_rob_root += rob(root->right, memo);
    }

    int max_rob = std::max(rob_root, not_rob_root);
    memo[root] = max_rob;
    return max_rob;
}

int user_logic(TreeNode* root) {
    std::unordered_map<TreeNode*, int> memo;
    return rob(root, memo);
}

int main() {
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<std::string> data;
    std::string item;
    while (iss >> item) {
        data.push_back(item);
    }
    TreeNode* root = insertLevelOrder(data, 0);
    int result = user_logic(root);
    std::cout << result << std::endl;
    return 0;
}