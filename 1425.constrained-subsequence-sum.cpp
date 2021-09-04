/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 *
 * https://leetcode.com/problems/constrained-subsequence-sum/description/
 *
 * algorithms
 * Hard (44.96%)
 * Likes:    591
 * Dislikes: 27
 * Total Accepted:    14.2K
 * Total Submissions: 31.2K
 * Testcase Example:  '[10,2,-10,5,20]\n2'
 *
 * Given an integer array nums and an integer k, return the maximum sum of a
 * non-empty subsequence of that array such that for every two consecutive
 * integers in the subsequence, nums[i] and nums[j], where i < j, the condition
 * j - i <= k is satisfied.
 *
 * A subsequence of an array is obtained by deleting some number of elements
 * (can be zero) from the array, leaving the remaining elements in their
 * original order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2,-10,5,20], k = 2
 * Output: 37
 * Explanation: The subsequence is [10, 2, 5, 20].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,-2,-3], k = 1
 * Output: -1
 * Explanation: The subsequence must be non-empty, so we choose the largest
 * number.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [10,-2,-10,-5,20], k = 2
 * Output: 23
 * Explanation: The subsequence is [10, -2, -5, 20].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    // n*k -> n * log(k)
    // int constrainedSubsetSum(vector<int>& nums, int k) {
        // vector<int> dp(nums.size(), 0);
        // multiset<int> heap{INT_MIN};
        // int ans = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
            // if (i > k) heap.erase(heap.equal_range(dp[i - k - 1]).first);
            // dp[i] = max(*rbegin(heap), 0) + nums[i];
            // heap.insert(dp[i]);
            // ans = max(ans, dp[i]);
        // }
        // return ans;
    // }

    int constrainedSubsetSum(vector<int> &nums, int k) {
        const int kN = nums.size();
        vector<int> dp(kN);
        deque<int> q;
        int ans = INT_MIN;
        for (int i = 0; i < kN; i++) {
            if (i > k && q.front() == i - k - 1) q.pop_front();
            dp[i] = (q.empty() ? 0 : max(dp[q.front()], 0)) + nums[i];
            while(!q.empty() && dp[i] >= dp[q.back()]) q.pop_back();
            q.push_back(i);
            ans = max(dp[i], ans);
        }
        return ans;
    }


};
// @lc code=end
