// LeetCode 20 - Valid Parentheses (Easy)
// Topics: Stack, PUSH/POP operations | Unit IV
// Approach: Push openers; on a closer, the top must be its matching opener. O(n) time, O(n) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    cout << boolalpha;
    cout << s.isValid("()[]{}") << "\n"; // true
    cout << s.isValid("(]") << "\n";     // false
    cout << s.isValid("([{}])") << "\n"; // true
    return 0;
}
