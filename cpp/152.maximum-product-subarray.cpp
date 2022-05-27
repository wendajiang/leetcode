/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (32.62%)
 * Likes:    7744
 * Dislikes: 246
 * Total Accepted:    522.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a contiguous non-empty subarray within the
 * array that has the largest product, and return the product.
 * 
 * It is guaranteed that the answer will fit in a 32-bit integer.
 * 
 * A subarray is a contiguous subsequence of the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> maxend(nums.size());
        vector<int> minend(nums.size());
        maxend[0] = minend[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxend[i] = max(max(maxend[i - 1] * nums[i], minend[i - 1] * nums[i]), nums[i]);
            minend[i] = min(min(maxend[i - 1] * nums[i], minend[i - 1] * nums[i]), nums[i]);
        }

        int ret = numeric_limits<int>::min();
        for (auto n : maxend) {
            ret = max(ret, n);
        }
        return ret;
    }
};
// @lc code=end
