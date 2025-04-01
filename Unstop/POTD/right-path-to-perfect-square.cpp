#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isPerfectSquare(int num) {
    int sqrt_val = sqrt(num);
    return (sqrt_val * sqrt_val == num);
}

TreeNode* constructTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int index = 1;
    while (!q.empty() && index < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (index < nodes.size() && nodes[index] != -1) {
            node->left = new TreeNode(nodes[index]);
            q.push(node->left);
        }
        index++;
        
        if (index < nodes.size() && nodes[index] != -1) {
            node->right = new TreeNode(nodes[index]);
            q.push(node->right);
        }
        index++;
    }
    return root;
}

string user_logic(int M, vector<int>& nodes) {
    TreeNode* root = constructTree(nodes);
    if (!root) return "NO";
    
    int sum = 0;
    TreeNode* current = root;
    while (current) {
        sum += current->val;
        current = current->right;
    }
    
    return isPerfectSquare(sum) ? "YES" : "NO";
}

int main() {
    int M;
    cin >> M;
    vector<int> nodes(M);
    for (int i = 0; i < M; ++i) {
        string val;
        cin >> val;
        if (val == "N") {
            nodes[i] = -1; 
        } else {
            nodes[i] = stoi(val);
        }
    }
    string result = user_logic(M, nodes);
    cout << result << endl;
    return 0;
}