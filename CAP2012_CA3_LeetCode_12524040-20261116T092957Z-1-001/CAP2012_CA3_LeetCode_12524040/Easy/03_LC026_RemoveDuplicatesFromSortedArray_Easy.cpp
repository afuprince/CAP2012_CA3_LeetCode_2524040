// LeetCode 26 - Remove Duplicates from Sorted Array (Easy)
// Topics: Arrays, traversal, array modification | Unit II
// Approach: Two pointers (slow writes unique values). O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[k - 1]) nums[k++] = nums[i];
        }
        return k;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = Solution().removeDuplicates(nums);
    cout << k << " : ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << "\n"; // 5 : 0 1 2 3 4
    return 0;
}
