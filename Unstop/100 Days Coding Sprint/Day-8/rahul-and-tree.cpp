#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
};

Node* construct(int arr[], int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = hi - ((hi - lo) / 2);
    int data = arr[mid];
    Node* left = construct(arr, lo, mid - 1);
    Node* right = construct(arr, mid + 1, hi);
    Node* node = new Node(data, left, right);
    return node;
}

void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    string str = "";
    str += (node->left == nullptr) ? "." : to_string(node->left->data);
    str += " <- " + to_string(node->data) + " -> ";
    str += (node->right == nullptr) ? "." : to_string(node->right->data);
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Node* root = construct(arr, 0, n - 1);
    display(root);

    return 0;
}