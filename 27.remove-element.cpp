/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element
 *
 * Easy (38.62%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        int count = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(nums[i] == val){
                count ++;
            }
        }
        int result = length - count;
        int index = length - 1;
        while(nums[index] == val){
            index--;
        }
        for(int i = 0; i < length - count; i++){
            if(nums[i] == val){
                swapArray(nums, i, index);
                while(nums[index] == val){
                    index--;
                }
            }     
        }
        return result;
    }
    
private:
    void swapArray(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
