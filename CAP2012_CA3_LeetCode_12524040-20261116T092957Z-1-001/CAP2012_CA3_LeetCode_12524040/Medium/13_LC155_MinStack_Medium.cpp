// LeetCode 155 - Min Stack (Medium)
// Topics: Stack, PUSH, POP, TOP operations | Unit IV
// Approach: Each stack entry stores (value, minimum so far). All operations O(1).
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int, int>> st; // {value, current minimum}

public:
    MinStack() {}

    void push(int val) {
        int mn = st.empty() ? val : min(val, st.top().second);
        st.push({val, mn});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << "\n"; // -3
    ms.pop();
    cout << ms.top() << "\n";    // 0
    cout << ms.getMin() << "\n"; // -2
    return 0;
}
