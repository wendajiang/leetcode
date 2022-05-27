/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    3186
 * Dislikes: 130
 * Total Accepted:    321K
 * Total Submissions: 820.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
                                                  
// @lc code=start
class Solution {
public:

    /* nlog(n) prefixsum + bsearch
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        for (int i = 1; i < len; i++) {
            nums[i] += nums[i - 1];
        }
        if (nums[len - 1] < s) return 0;
        int cur = 0;
        int ans = INT_MAX;
        while(cur < len && nums[cur] < s) cur++;
        for (; cur < len; cur++) {
            int target = nums[cur] - s;
            auto it = lower_bound(begin(nums), end(nums), target);
            int index = it - begin(nums);
            if (*it == target) ans = min(ans, cur - index);
            else ans = min(ans, cur - index + 1);
        }
        return ans;
    }
    */

   // 双指针法
   int minSubArrayLen(int s, vector<int>& nums) {
       if (nums.size() == 0) return 0;
       int l = 0, r = 0;
       int sum = 0;
       int ans = INT_MAX;
       while(r < nums.size()) {
            sum += nums[r];   
            while(sum >= s) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
       }
       return ans == INT_MAX ? 0 : ans;
   }
};
// @lc code=end

