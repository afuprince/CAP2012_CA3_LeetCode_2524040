// LeetCode 232 - Implement Queue using Stacks (Easy)
// Topics: Stack, queue, FIFO operations | Unit IV
// Approach: Two stacks (input/output); transfer lazily. Amortized O(1) per operation.
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> in, out;

    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) { in.push(x); }

    int pop() {
        transfer();
        int v = out.top();
        out.pop();
        return v;
    }

    int peek() {
        transfer();
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << "\n";  // 1
    cout << q.pop() << "\n";   // 1
    cout << boolalpha << q.empty() << "\n"; // false
    return 0;
}
