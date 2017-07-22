/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range
 *
 * Medium (31.31%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        vector<int> res;
        int start = getStart(nums, target);
        int end = getEnd(nums, target);
        res.push_back(start);
        res.push_back(end);
        return res;
    }

    int getEnd(vector<int> &nums, int target){
        int start = -1;
        int end = nums.size();
        while(start != end - 1){
            int mid = (start + end) / 2;
            if(nums[mid] <= target){
                start = mid;
            }else{
                end = mid;
            }
        }
        if(start >= nums.size() || nums[start] != target)
            start = -1;
        return start;
    }
    int getStart(vector<int>& nums, int target){
        int start = -1;
        int end = nums.size();
        while(start != end - 1){
            int mid = (start + end) / 2;
            if(nums[mid] >= target){
                end = mid;
            }else
                start = mid;
        }
        if(end >= nums.size() || nums[end] != target)
            end = -1;
        return end;
    }
};
