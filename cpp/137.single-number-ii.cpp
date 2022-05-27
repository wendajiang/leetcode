/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (42.56%)
 * Total Accepted:    133K
 * Total Submissions: 312.1K
 * Testcase Example:  '[1]'
 *
 *
 * Given an array of integers, every element appears three times except for
 * one, which appears exactly once. Find that single one.
 *
 *
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0; //occur ones bit
        int twos = 0; //occur twos bits
        int threes;
        for(int i = 0; i < nums.size(); i++){
            int t = nums[i];
            twos |= ones & t;
            ones ^= t;
            threes = ones & twos;
            ones &= ~threes;  //clear occur three bits
            twos &= ~threes;
        }
        return ones;
    }
};
