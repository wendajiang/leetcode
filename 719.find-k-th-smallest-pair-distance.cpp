/*
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (27.05%)
 * Total Accepted:    6.9K
 * Total Submissions: 25.4K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B.
 *
 * Example 1:
 *
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 *
 *
 *
 * Note:
 *
 * 2 .
 * 0 .
 * 1 .
 *
 *
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int l = 0;
        int r = nums[len - 1] - nums[0];
        for(int cnt = 0; l < r; cnt = 0){
            int m = l + (r - l) / 2;
            for(int i = 0, j = 0; i < len; i++){
                while(j < len && nums[j] <= nums[i] + m) j++;
                cnt += j - i - 1;
            }
            if(cnt < k){
                l = m + 1;
            }else {
                r = m;
            }
        }
        return l;
    }
};
