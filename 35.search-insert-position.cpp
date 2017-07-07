/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * Easy (39.58%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1]\n0'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            if(target <= nums[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
