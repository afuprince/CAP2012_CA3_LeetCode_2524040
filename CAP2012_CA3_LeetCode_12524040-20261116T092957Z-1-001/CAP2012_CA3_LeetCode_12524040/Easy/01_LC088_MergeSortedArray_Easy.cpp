// LeetCode 88 - Merge Sorted Array (Easy)
// Topics: Arrays, merging | Unit II
// Approach: Three pointers from the back. O(m+n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution().merge(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << " ";
    cout << "\n"; // 1 2 2 3 5 6
    return 0;
}
