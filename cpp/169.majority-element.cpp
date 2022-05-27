/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element
 *
 * Easy (46.32%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        if(nums.size() == 1)
            return candidate;
        for(int i = 1; i < nums.size(); i++){
            if(candidate == nums[i]){
                count++;
            }else{
                count--;
                if(count == 0){
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};
