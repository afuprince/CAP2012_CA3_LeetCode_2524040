// LeetCode 509 - Fibonacci Number (Easy)
// Topics: Recursion | Unit IV
// Approach: Recursion with memoization. O(n) time, O(n) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int memo[31];

    int helper(int n) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = helper(n - 1) + helper(n - 2);
    }

public:
    int fib(int n) {
        memset(memo, -1, sizeof(memo));
        return helper(n);
    }
};

int main() {
    Solution s;
    cout << s.fib(2) << "\n";  // 1
    cout << s.fib(3) << "\n";  // 2
    cout << s.fib(4) << "\n";  // 3
    cout << s.fib(30) << "\n"; // 832040
    return 0;
}
