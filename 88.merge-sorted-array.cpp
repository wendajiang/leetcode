/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array
 *
 * Easy (31.92%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int indexNum1 = m - 1;
        int indexNum2 = n - 1;
        while(index >= 0){
            if(indexNum1 == -1){
                nums1[index] = nums2[indexNum2];
                index--;
                indexNum2--;
            }
            else if(indexNum2 == -1){
                nums1[index] == nums1[indexNum1];
                index--;
                indexNum1--;
            }
            else if(nums1[indexNum1] < nums2[indexNum2]){
                nums1[index] = nums2[indexNum2];
                indexNum2--;
                index--;
            }else{
                nums1[index] = nums1[indexNum1];
                indexNum1--;
                index--;
            }
        }
    }
};
