#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree(vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start;
    TreeNode* root = new TreeNode(arr[mid]);

    int left_end = mid + (end - mid)/2;
    root->left = create_tree(arr, mid + 1, left_end);

    root->right = create_tree(arr, left_end + 1, end);

    return root;
}


void find_min_max(TreeNode* root, int& min_val, int& max_val) {
    if (!root) return;

    if (!root->left && !root->right) {
        min_val = min(min_val, root->val);
        max_val = max(max_val, root->val);
        return;
    }

    find_min_max(root->left, min_val, max_val);
    find_min_max(root->right, min_val, max_val);
}

int maximum_abs_diff(TreeNode* root) {
    if (!root) return 0;

    int min_val = INT_MAX;
    int max_val = INT_MIN;

    find_min_max(root, min_val, max_val);

    return abs(max_val - min_val);
}

int main() {
    int T;
    cin >> T;
    vector<int> results;
    for (int t = 0; t < T; t++) {
        int numberOfLevel;
        cin >> numberOfLevel;
        int numberOfNodes = pow(2, numberOfLevel) - 1;
        vector<int> arr(numberOfNodes);
        for (int i = 0; i < numberOfNodes; i++) {
            cin >> arr[i];
        }

        TreeNode* root = create_tree(arr, 0, arr.size()-1);

        int result = maximum_abs_diff(root);
        results.push_back(result);
    }
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}