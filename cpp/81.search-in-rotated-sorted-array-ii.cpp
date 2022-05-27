/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.69%)
 * Total Accepted:    118.8K
 * Total Submissions: 363.3K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 *
 * Example 1:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 *
 * Follow up:
 *
 *
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 *
 *
 */
class Solution {
public:

    bool search(vector<int>& A, int t) {
        if (A.empty())
            return false;

        int l = 0, r = A.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] == t) return true;
            if (A[l] < A[m]) {
                if (A[l] <= t && t < A[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (A[m] < A[r]) {
                if (A[m] < t && t <= A[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (A[l] == A[m]) l++;
                if (A[m] == A[r]) r--;
            }
        }

        return A[l] == t? true : false;

    }
};
