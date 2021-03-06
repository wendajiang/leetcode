/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number
 *
 * Easy (44.14%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[0]'
 *
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 *
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     int len = nums.size(); //len = n, actually there is n + 1 numbers,find the missing number
    //     std::sort(nums.begin(), nums.end());
    //     for(int i = 0; i < nums.size(); i++){
    //         if(i != nums[i])
    //             return i;
    //     }
    //     return len;
    // }

    int missingNumber(vector<int>& nums){
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
