#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> getAllElementsFromBSTs(vector<int>& bst1_nodes, vector<int>& bst2_nodes);

TreeNode* constructBST(vector<int>& arr, int si, int ei) {
    if (si > ei) {
        return nullptr;
    }
    if (si == ei) {
        TreeNode* newNode = new TreeNode(arr[si]);
        return newNode;
    }
    int mid = si + (ei - si) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    TreeNode* left = constructBST(arr, si, mid - 1);
    TreeNode* right = constructBST(arr, mid + 1, ei);
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> bst1_nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> bst1_nodes[i];
    }
    sort(bst1_nodes.begin(), bst1_nodes.end());

    int m;
    cin >> m;
    vector<int> bst2_nodes(m);
    for (int i = 0; i < m; i++) {
        cin >> bst2_nodes[i];
    }
    sort(bst2_nodes.begin(), bst2_nodes.end());

    vector<int> result = getAllElementsFromBSTs(bst1_nodes, bst2_nodes);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

vector<int> getAllElementsFromBSTs(vector<int>& bst1_nodes, vector<int>& bst2_nodes) {
    vector<int>ans;
   for(int i=0;i<bst1_nodes.size();i++)
   {
    ans.push_back(bst1_nodes[i]);
   }
   for(int i=0;i<bst2_nodes.size();i++)
   {
    ans.push_back(bst2_nodes[i]);
   }
   sort(ans.begin(),ans.end());
   return ans;
    
}