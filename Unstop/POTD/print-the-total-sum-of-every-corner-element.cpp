#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

Node* constructBST(vector<int>& preorder) {
    Node* root = NULL;
    for (int val : preorder) {
        root = insert(root, val);
    }
    return root;
}

int user_logic(Node* root) {
    if (root == NULL) return 0;

    int totalSum = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int first = INT_MAX; 
        int last = INT_MIN;   

        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            if (i == 0) first = curr->val; 
            if (i == levelSize - 1) last = curr->val; 

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if(first != INT_MAX) totalSum += first;
        if(last != INT_MIN && first != last) totalSum += last; 
    }

    return totalSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    Node* root = constructBST(preorder);
    int result = user_logic(root);
    cout << result << endl;
    return 0;
}