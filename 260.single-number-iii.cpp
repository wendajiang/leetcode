/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (53.02%)
 * Total Accepted:    80.4K
 * Total Submissions: 151.3K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 *
 * For example:
 *
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 *
 * Note:
 *
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 *
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= ~(diff - 1);
        //diff &= -diff;

        vector<int> res = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & diff){
                res[0] ^= nums[i];
            }else{
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};
