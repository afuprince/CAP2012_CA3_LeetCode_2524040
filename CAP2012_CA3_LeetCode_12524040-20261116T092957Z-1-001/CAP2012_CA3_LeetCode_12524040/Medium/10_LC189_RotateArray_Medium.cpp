// LeetCode 189 - Rotate Array (Medium)
// Topics: Arrays, traversal, array manipulation | Unit II
// Approach: Reverse whole array, then reverse first k and remaining n-k. O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(nums, 3);
    for (int x : nums) cout << x << " ";
    cout << "\n"; // 5 6 7 1 2 3 4
    return 0;
}
