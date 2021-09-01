/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (55.80%)
 * Likes:    1042
 * Dislikes: 63
 * Total Accepted:    74.2K
 * Total Submissions: 133K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 *
 * In one move, you can increment or decrement an element of the array by 1.
 *
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,10,2,9]
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    // int minMoves2(vector<int>& nums) {
        // if (nums.empty()) return 0;
        // sort(nums.begin(), nums.end());

        // int median_num = 0;
        // if (nums.size() & 1) {
            // median_num = nums[nums.size() / 2];
        // } else {
            // median_num = (((long)nums[nums.size() / 2] + (long)nums[nums.size() / 2 - 1]) >> 1);
        // }

        // int ans = 0;
        // for (auto n : nums) {
            // ans += abs(n - median_num);
        // }
        // return ans;
    // }


    int minMoves2(vector<int> &nums) {
        int res = 0;
        int median = findKthLargest(nums, nums.size() / 2 + 1);
        for (auto n : nums){
            res += abs(median - n);
        }
        return res;
    }


private:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while(true) {
            int pos = partition(nums, left, right);
            if (pos + 1 == k) {
                return nums[pos];
            } else if (pos + 1 > k) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    int partition(vector<int> &nums, int l, int r) {
        int privot = nums[l];
        int s = l + 1;
        int e = r;
        while(s <= e) {
            if (nums[s] < privot && nums[e] > privot) {
                swap(nums, s++, e--);
            }
            if (nums[s] >= privot) {
                s++;
            }
            if (nums[e] <= privot) {
                e--;
            }
        }
        swap(nums, l, e);
        return e;
    }

    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
// @lc code=end
