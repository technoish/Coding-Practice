#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    ListNode* kthFromStart = nullptr;
    ListNode* kthFromEnd = nullptr;

    for (int i = 1; i < k; i++) {
        first = first->next;
    }
    kthFromStart = first;

    ListNode* temp = head;
    for (int i = 0; i < k - 1; i++) {
        temp = temp->next;
    }

    first = head;
    while (temp->next != nullptr) {
        first = first->next;
        temp = temp->next;
    }
    kthFromEnd = first;

    int tempVal = kthFromStart->val;
    kthFromStart->val = kthFromEnd->val;
    kthFromEnd->val = tempVal;

    return head;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }
    std::cin >> k;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;

    ListNode* modified_head = swapNodes(head, k);

    current = modified_head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}