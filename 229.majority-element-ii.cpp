/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii
 *
 * Medium (28.47%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            else{
                if(count1 && count2) {
                    count1--;
                    count2--;
                }else if(count1){
                    candidate2 = nums[i];
                    count2 = 1;
                }else{
                    candidate1 = nums[i];
                    count1 = 1;
                }
            }
        }
        vector<int> res;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1)
                count1++;
            if(nums[i] == candidate2)
                count2++;
        }
        if(count1 > nums.size() / 3)
            res.push_back(candidate1);
        if(count2 > nums.size() / 3)
            res.push_back(candidate2);
        return res;
    }
};
