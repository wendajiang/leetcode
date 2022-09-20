//  Category: algorithms
//  Level: Medium
//  Percent: 38.36478%

//  Given an array of non-negative integers nums, you are initially positioned
//  at the first index of the array.
//
//  Each element in the array represents your maximum jump length at that
//  position.
//
//  Your goal is to reach the last index in the minimum number of jumps.
//
//  You can assume that you can always reach the last index.
//
//   
//  Example 1:
//
//  Input: nums = [2,3,1,1,4]
//  Output: 2
//  Explanation: The minimum number of jumps to reach the last index is 2. Jump
//  1 step from index 0 to 1, then 3 steps to the last index.
//
//
//  Example 2:
//
//  Input: nums = [2,3,0,1,4]
//  Output: 2
//
//
//   
//  Constraints:
//
//
//  	1 <= nums.length <= 10⁴
//  	0 <= nums[i] <= 1000
//

#include <bits/stdc++.h>
using namespace std;
// https://medium.com/@bill800227/leetcode-45-jump-game-ii-9648746e96e3
// bfs think process
//  @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) {
        auto len = nums.size();
        if (len <= 1) return 0;
        int cur_step = 0, i = 0;
        int level = 0;
        while (cur_step < len - 1) {
            level++;
            int pre_step = cur_step;
            for (; i <= pre_step; i++) {
                cur_step = max(cur_step, i + nums[i]);
            }
        }
        return level;
    }
};
//  @lc code=end
