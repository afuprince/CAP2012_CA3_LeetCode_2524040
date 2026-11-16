// LeetCode 1281 - Subtract the Product and Sum of Digits of an Integer (Easy)
// Topics: Loops, control structures, arithmetic | Unit I
// Approach: Extract digits with % and /. O(log n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int d = n % 10;
            product *= d;
            sum += d;
            n /= 10;
        }
        return product - sum;
    }
};

int main() {
    Solution s;
    cout << s.subtractProductAndSum(234) << "\n";  // 15
    cout << s.subtractProductAndSum(4421) << "\n"; // 21
    return 0;
}
