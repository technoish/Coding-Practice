#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert_into_bst(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val <= root->val) root->left = insert_into_bst(root->left, val);
    else root->right = insert_into_bst(root->right, val);
    return root;
}

int sum_of_values_in_range(TreeNode* root, int start, int end) {
    if (!root) {
        return 0;
    }

    int sum = 0;
    if (root->val >= start && root->val <= end) {
        sum += root->val;
    }

    if (root->val > start) {  
        sum += sum_of_values_in_range(root->left, start, end);
    }
    if (root->val < end) { 
        sum += sum_of_values_in_range(root->right, start, end);
    }

    return sum;
}

int main() {
    int n, start, end;
    cin >> n;
    int values[n];
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    cin >> start >> end;
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert_into_bst(root, values[i]);
    }
    int result = sum_of_values_in_range(root, start, end);
    cout << result << endl;
    return 0;
}