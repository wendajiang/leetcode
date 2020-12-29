/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 *
 * https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
 *
 * algorithms
 * Medium (38.92%)
 * Likes:    285
 * Dislikes: 16
 * Total Accepted:    11.1K
 * Total Submissions: 28.3K
 * Testcase Example:  '[1,3,5]\r'
 *
 * Given an array of integers arr. Return the number of sub-arrays with odd
 * sum.
 * 
 * As the answer may grow large, the answer must be computed modulo 10^9 +
 * 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 * All sub-arrays sum are [1,4,9,3,8,5].
 * Odd sums are [1,9,3,5] so the answer is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 * All sub-arrays sum are [2,6,12,4,10,6].
 * All sub-arrays have even sum and the answer is 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [100,100,99,99]
 * Output: 4
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 100
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, odd = 0, even = 1;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = (arr[i] + sum) % 2;
            if (sum & 0x1) {
                ans = (ans + even) % MOD;
                odd++;
            }
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }
        return ans;
    }
};
// @lc code=end
