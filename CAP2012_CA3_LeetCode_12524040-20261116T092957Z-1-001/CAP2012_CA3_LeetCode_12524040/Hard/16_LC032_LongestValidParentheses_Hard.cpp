// LeetCode 32 - Longest Valid Parentheses (Hard)
// Topics: Stack, parentheses processing | Unit IV
// Approach: Stack of indices; the base holds the index just before the current valid window.
// O(n) time, O(n) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // new base
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("(()") << "\n";    // 2
    cout << s.longestValidParentheses(")()())") << "\n"; // 4
    cout << s.longestValidParentheses("") << "\n";       // 0
    return 0;
}
