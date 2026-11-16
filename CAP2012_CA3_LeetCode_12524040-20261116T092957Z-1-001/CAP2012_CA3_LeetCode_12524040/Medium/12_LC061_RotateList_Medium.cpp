// LeetCode 61 - Rotate List (Medium)
// Topics: Linked list, traversal, link manipulation | Unit III
// Approach: Make the list circular, then break it at the (len - k)th node. O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        tail->next = head; // make circular
        ListNode* p = head;
        for (int i = 0; i < len - k - 1; i++) p = p->next;

        ListNode* newHead = p->next;
        p->next = nullptr;
        return newHead;
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
    printList(Solution().rotateRight(head, 2)); // 4 -> 5 -> 1 -> 2 -> 3
    return 0;
}
