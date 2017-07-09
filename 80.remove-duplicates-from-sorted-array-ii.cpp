/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *
 * Medium (35.76%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 *
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int occur = 1;
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[index] == nums[i]){
                if(occur == 2){
                    continue;
                }
                occur ++;
            }else{
                occur = 1;
            }
            nums[++index] = nums[i];
        }
        return index + 1;
    }
};
