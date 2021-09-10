/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (31.35%)
 * Likes:    1682
 * Dislikes: 715
 * Total Accepted:    106.7K
 * Total Submissions: 340.2K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an integer array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 *
 * You may assume the input array always has a valid answer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,1,1,6,4]
 * Output: [1,6,1,5,1,4]
 * Explanation: [1,4,1,5,1,6] is also accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3,2,2,3,1]
 * Output: [2,3,1,3,1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5000
 * It is guaranteed that there will be an answer for the given input nums.
 *
 *
 *
 * Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// @lc code=start
// https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
// leetcode 75 three-way-partition
//
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        int mid = findKth(nums, nums.size() / 2 + 1);
        while(j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else j++;
        }
    }

private:
    int findKth(vector<int> &nums, int k) {
        if (nums.size() == 0) return 0;
        int l = 0, r = nums.size() - 1;
        while(true) {
            int pos = partition(nums, l, r);
            if (pos + 1 == k) return nums[pos];
            else if(pos + 1 > k) r = pos - 1;
            else l = pos + 1;
        }
    }


    int partition(vector<int> &nums, int l, int r) {
        int privot = nums[l];
        int s = l + 1;
        int e = r;
        while(s <= e) {
            if (nums[s] < privot && nums[e] > privot) swap(nums[s++], nums[e--]);
            if (nums[s] >= privot) s++;
            if (nums[e] <= privot) e--;
        }
        swap(nums[l], nums[e]);
        return e;
    }


};
// @lc code=end
