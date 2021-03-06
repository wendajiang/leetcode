/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (44.23%)
 * Total Accepted:    101.7K
 * Total Submissions: 229.9K
 * Testcase Example:  '[1,1]'
 *
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 *
 *
 * Note:
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 *
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     int l = 1, r = nums.size() - 1;
    //     while(l <= r){
    //         int mid = l + (r - l) / 2;
    //         int cnt = 0;
    //         for(int i = 0; i < nums.size(); i++){
    //             if(nums[i] <= mid) cnt++;
    //         }
    //         if(cnt > mid) r = mid - 1;
    //         else l = mid + 1;
    //     }
    //     return l;
    // }

    //https://segmentfault.com/a/1190000003817671 这篇文章写的很好

    int findDuplicate(vector<int>& nums){
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
