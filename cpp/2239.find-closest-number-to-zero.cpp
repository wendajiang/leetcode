// Category: algorithms
// Level: Easy
// Percent: 45.973675%

/*
 * Given an integer array nums of size n, return the number with the value
 * closest to 0 in nums. If there are multiple answers, return the number with
 * the largest value.   Example 1:
 *
 * Input: nums = [-4,-2,1,4,8]
 * Output: 1
 * Explanation:
 * The distance from -4 to 0 is |-4| = 4.
 * The distance from -2 to 0 is |-2| = 2.
 * The distance from 1 to 0 is |1| = 1.
 * The distance from 4 to 0 is |4| = 4.
 * The distance from 8 to 0 is |8| = 8.
 * Thus, the closest number to 0 in the array is 1.
 *
 *
 * Example 2:
 *
 * Input: nums = [2,-1,1]
 * Output: 1
 * Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is
 * returned.
 *
 *
 *  
 * Constraints:
 *
 *
 * 	1 <= n <= 1000
 * 	-10^5 <= nums[i] <= 10^5
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int findClosestNumber(vector<int>& nums) {
        int result = nums[0];
        for (auto& num : nums)
            /*  nums中最接近0的数字，如果距离相等记录较大的 */
            if (abs(num) < abs(result) ||
                (abs(num) == abs(result) && num > result))
                result = num;
        return result;
    }
};
// @lc code=end
