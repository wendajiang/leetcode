/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence
 *
 * Medium (38.18%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 *
 *
 * Your algorithm should run in O(n2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    // // There's a typical DP solution with O(N^2) Time and O(N) space
    // // DP[i] means the result ends at i
    // // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
    // int lengthOfLIS(vector<int>& nums) {
    //     const int size = nums.size();
    //     if (size == 0) { return 0; }
    //     vector<int> dp(size, 1);
    //     int res = 1;
    //     for (int i = 1; i < size; ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (nums[j] < nums[i]) {
    //                 dp[i] = max(dp[i], dp[j]+1);
    //             }
    //         }
    //         res = max (res, dp[i]);
    //     }
    //     return res;
    // }
    //
    //
    // // NLogN solution from geek for geek
    // int lengthOfLIS(vector<int>& nums) {
    //     if (nums.empty()) { return 0; }
    //     vector<int> tail;  // keep tail value of each possible len
    //     tail.push_back(nums[0]);
    //     for (auto n : nums) {
    //         if (n <= tail[0]) {
    //             tail[0] = n;
    //         } else if (n > tail.back()) { // large than the tail of current largest len
    //             tail.push_back(n);
    //         } else {  // find smallest one which is >= n
    //             int left = 0;
    //             int right = tail.size()-1;
    //             int res = left;
    //             while(left <= right) {
    //                 int mid = left + (right-left)/2;
    //                 if (tail[mid] >= n) {
    //                     res = mid;
    //                     right = mid-1;
    //                 } else { // tail[mid] < n
    //                     left = mid+1;
    //                 }
    //             }
    //             tail[res] = n;
    //         }
    //     }
    //     return tail.size();
    // }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return nums.size();

        vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
        for (int& val : nums) {
            auto it = lower_bound(nums.begin(), m, val);
            *it = val;
            if (it == m)
                m++;
            }
        return m - nums.begin();
    }
};
