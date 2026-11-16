// LeetCode 92 - Reverse Linked List II (Medium)
// Topics: Linked list, pointer manipulation | Unit III
// Approach: Find node before 'left', then repeatedly move next node to the front of the sublist.
// O(n) time, O(1) space, single pass.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) prev = prev->next;

        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        return dummy.next;
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
    printList(Solution().reverseBetween(head, 2, 4)); // 1 -> 4 -> 3 -> 2 -> 5
    return 0;
}
