/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays
 *
 * Hard (21.50%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(((nums1.size() + nums2.size()) & 1) == 0){
            return (getMedian(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size()) / 2) +
            getMedian(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }else{
            return getMedian(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size()) / 2 + 1);
        }
    }

    int getMedian(vector<int>& nums1,int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
        if(end1 <= start1) return nums2[start2 + k - 1];
        if(end2 <= start2) return nums1[start1 + k - 1];
        if(k <= 1) return std::min(nums1[start1], nums2[start2]);
        if(nums1[(end1 + start1) / 2] >= nums2[(start2 + end2) / 2]){
            if((end1 - start1)/2 + (end2 - start2)/2 + 1 >= k)
                return getMedian(nums1, start1, (start1 + end1)/2, nums2, start2, end2, k);
            else
                return getMedian(nums1, start1, end1, nums2, start2 + (end2 - start2)/2 + 1, end2, k - (end2 - start2)/2 - 1);

        }else{
            if((end1 - start1)/2 + (end2 - start2)/2 + 1 >= k)
                return getMedian(nums1, start1, end1, nums2, start2, (start2 + end2)/2, k);
            else
                return getMedian(nums1, start1 + (end1 - start1)/2 + 1, end1, nums2, start2, end2, k - (end1 - start1)/2 - 1);
        }
    }
};
