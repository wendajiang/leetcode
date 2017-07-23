/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array
 *
 * Easy (24.44%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1]\n0'
 *
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 *
 *
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 *
 *
 * Related problem: Reverse Words in a String II
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kk = k % n;
        rotate(nums, 0, n - kk -1);
        rotate(nums, n - kk, n - 1);
        rotate(nums, 0, n - 1);
    }
    void rotate(vector<int>& nums, int start, int end){
        while(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start ++;
            end --;
        }
    }
};
