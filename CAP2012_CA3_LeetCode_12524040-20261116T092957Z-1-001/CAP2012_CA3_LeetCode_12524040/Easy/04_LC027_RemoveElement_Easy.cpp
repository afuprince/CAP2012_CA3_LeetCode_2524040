// LeetCode 27 - Remove Element (Easy)
// Topics: Arrays, traversal, deletion | Unit II
// Approach: Two pointers, copy only elements != val. O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int k = Solution().removeElement(nums, 2);
    cout << k << " : ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << "\n"; // 5 : 0 1 3 0 4
    return 0;
}
