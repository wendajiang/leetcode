/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors
 *
 * algorithms
 * Medium (37.95%)
 * Total Accepted:    170.4K
 * Total Submissions: 448.8K
 * Testcase Example:  '[0]'
 *
 *
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 *
 *
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 *
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 *
 * click to show follow up.
 *
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 *
 *
 */

// https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 1;
        int i = 0, j = 0;
        int k = nums.size() - 1;
        while(j <= k) {
            if (nums[j] < mid) {
                swap(nums[i], nums[j]);
                i++; j++;
            } else if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                j++;
            }
        }

    }

    // void sortColors(vector<int>& A) {
    //     int j = 0, k = A.size() - 1;
    //     for (int i=0; i <= k; i++) {
    //         if (A[i] == 0)
    //             swap(A[i], A[j++]);
    //         else if (A[i] == 2)
    //             swap(A[i--], A[k--]);
    //     }
    // }
};
