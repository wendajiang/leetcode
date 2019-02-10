/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *
 * Easy (35.53%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * 
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        if(nums.size() == 0)
            return result;
        result = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]){
                result++;
                nums[result - 1] = nums[i];
            }
            
        }
        return result;
    }
};
