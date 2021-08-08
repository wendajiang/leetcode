/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (54.52%)
 * Likes:    1679
 * Dislikes: 79
 * Total Accepted:    148K
 * Total Submissions: 271.5K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -2^28 to 2^28 - 1 and the result
 * is guaranteed to be at most 2^31 - 1.
 *
 * Example:
 *
 *
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int len = A.size();
    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        mp[A[i] + B[j]]++;
      }
    }
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        auto res = 0 - (C[i] + D[j]);
        if (mp.count(res)) {
          cnt += mp[res];
        }
      }
    }
    return cnt;
  }
};
// @lc code=end
