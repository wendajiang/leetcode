/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 * Medium (32.11%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int index1 = 0;
        int index2 = nums.size() - 1;
        if(nums[index1] < nums[index2]){
            return binearySearch(nums, 0, nums.size() - 1, target);
        }else{
            while(nums[index1] > nums[index2]){
                if(index2 - index1 == 1)
                    break;
                int mid = (index1 + index2) / 2;
                if(nums[mid] >= nums[index1]){
                    index1 = mid;
                }else if(nums[mid] <= nums[index2]){
                    index2 = mid;
                }
            }
            if(target <= nums[index1] && target >= nums[0]){
                return binearySearch(nums, 0, index1, target);
            }else {
                return binearySearch(nums, index2, nums.size() - 1, target);
            }
        }
    }

    int binearySearch(vector<int>& nums, int index1, int index2, int target){
        while(index1 <= index2){
            int mid = (index1 + index2) / 2;
            if(nums[mid] > target){
                index2 = mid - 1;
            }else if(nums[mid] < target){
                index1 = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
