// LeetCode 83 - Remove Duplicates from Sorted List (Easy)
// Topics: Linked list, traversal, deletion | Unit III
// Approach: Single pass, skip nodes with equal value. O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* dup = curr->next;
                curr->next = dup->next;
                delete dup;
            } else {
                curr = curr->next;
            }
        }
        return head;
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
    ListNode* head = build({1, 1, 2, 3, 3});
    printList(Solution().deleteDuplicates(head)); // 1 -> 2 -> 3
    return 0;
}
