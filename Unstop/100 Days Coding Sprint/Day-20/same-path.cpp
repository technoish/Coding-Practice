#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int check(Node* l1, Node* l2) {
    unordered_set<int> seen;
    Node* temp1 = l1;
    while (temp1 != nullptr) {
        seen.insert(temp1->val);
        temp1 = temp1->next;
    }

    Node* temp2 = l2;
    while (temp2 != nullptr) {
        if (seen.find(temp2->val) != seen.end()) {
            return 1;
        }
        temp2 = temp2->next;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Node* l1 = new Node(0);
    Node* temp = l1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        temp->next = new Node(t);
        temp = temp->next;
    }
    l1 = l1->next;
    
    Node* l2 = new Node(0);
    temp = l2;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        temp->next = new Node(t);
        temp = temp->next;
    }
    l2 = l2->next;
    
    int result = check(l1, l2);
    cout << result << endl;
    return 0;
}