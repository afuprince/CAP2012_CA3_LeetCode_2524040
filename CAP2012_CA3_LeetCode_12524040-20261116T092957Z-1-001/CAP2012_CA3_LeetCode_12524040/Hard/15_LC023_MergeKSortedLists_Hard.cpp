// LeetCode 23 - Merge k Sorted Lists (Hard)
// Topics: Linked lists, traversal, merging | Unit III
// Approach: Min-heap holding the current head of each list. O(N log k) time, O(k) space.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (ListNode* l : lists)
            if (l) pq.push(l);

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
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
    vector<ListNode*> lists = {build({1, 4, 5}), build({1, 3, 4}), build({2, 6})};
    printList(Solution().mergeKLists(lists)); // 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
    return 0;
}
