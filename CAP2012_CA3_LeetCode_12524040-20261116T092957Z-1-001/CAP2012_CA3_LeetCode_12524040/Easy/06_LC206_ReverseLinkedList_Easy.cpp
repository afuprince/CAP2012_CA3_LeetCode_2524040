// LeetCode 206 - Reverse Linked List (Easy)
// Topics: Singly linked list, pointers, traversal | Unit III
// Approach: Iterative pointer reversal. O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}

void printList(ListNode* h) {
    for (; h; h = h->next) cout << h->val << (h->next ? " -> " : "");
    cout << "\n";
}

int main() {
    ListNode* head = build({1, 2, 3, 4, 5});
    printList(Solution().reverseList(head)); // 5 -> 4 -> 3 -> 2 -> 1
    return 0;
}
