/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array
 *
 * Medium (55.41%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 *
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i=0; i<len; i++) {
            int m = abs(nums[i]) - 1; // index start from 0
            nums[m] = -nums[m];
            if(nums[m] > 0)
                res.push_back(m + 1);
        }
        return res;
    }
};
