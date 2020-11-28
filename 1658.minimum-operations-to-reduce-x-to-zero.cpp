/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (29.82%)
 * Likes:    244
 * Dislikes: 4
 * Total Accepted:    6.8K
 * Total Submissions: 22.8K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * You are given an integer array nums and an integer x. In one operation, you
 * can either remove the leftmost or the rightmost element from the array nums
 * and subtract its value from x. Note that this modifies the array for future
 * operations.
 * 
 * Return the minimum number of operations to reduce x to exactly 0 if it's
 * possible, otherwise, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,4,2,3], x = 5
 * Output: 2
 * Explanation: The optimal solution is to remove the last two elements to
 * reduce x to zero.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,6,7,8,9], x = 4
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,2,20,1,1,3], x = 10
 * Output: 5
 * Explanation: The optimal solution is to remove the last three elements and
 * the first two elements (5 operations in total) to reduce x to zero.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    /** TLE
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        vector<int> presum(len + 1, 0);
        vector<int> postsum(len + 1, 0);
        for (size_t i = 0; i < len; i++) {
            presum[i + 1] = presum[i] + nums[i];
            postsum[i + 1] = postsum[i] + nums[len - i - 1];
        }
        
        int mincnt = std::numeric_limits<int>::max();
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= len; j++) {
                if (i + j > len) continue;
                int ipresum = presum[i];
                int jpostsum = postsum[j];
                if (x == ipresum + jpostsum) {
                    mincnt = std::min(mincnt, i + j);
                }
            }
        }
        if (mincnt == std::numeric_limits<int>::max()) {
            return -1;
        }
        else {
            return mincnt;
        }
    }
    */

    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        vector<int> presum(len + 1, 0);
        vector<int> postsum(len + 1, 0);
        for (size_t i = 0; i < len; i++) {
            presum[i + 1] = presum[i] + nums[i];
            postsum[i + 1] = postsum[i] + nums[len - i - 1];
        }
        
        int mincnt = std::numeric_limits<int>::max();
        for (int i = 0; i <= len; i++) {
            int remain = x - presum[i];
            auto find_it = std::lower_bound(begin(postsum), end(postsum), remain);
            if (find_it != postsum.end() && (*find_it) == remain) {
                int j = find_it - postsum.begin();
                if (i + j > len) continue;
                mincnt = std::min(mincnt, i + j);
            }

        }
        if (mincnt == std::numeric_limits<int>::max()) {
            return -1;
        }
        else {
            return mincnt;
        }
    }
};
// @lc code=end

