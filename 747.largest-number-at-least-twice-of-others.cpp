/*
 * [748] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (41.84%)
 * Total Accepted:    14.5K
 * Total Submissions: 34.7K
 * Testcase Example:  '[0,0,0,1]'
 *
 * In a given integer array nums, there is always exactly one largest element.
 *
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array.
 *
 * If it is, return the index of the largest element, otherwise return -1.
 *
 * Example 1:
 *
 *
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the
 * array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return
 * 1.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return
 * -1.
 *
 *
 *
 *
 * Note:
 *
 *
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 *
 *
 *
 *
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int mx = nums[0];
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > mx){
                mx = nums[i];
                res = i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(res != i){
                if(2 * nums[i] > mx){
                    return  -1;
                }
            }
        }
        return res;
    }
};
