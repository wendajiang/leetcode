/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (49.60%)
 * Likes:    497
 * Dislikes: 66
 * Total Accepted:    49.2K
 * Total Submissions: 99.2K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
#define MAXN 5e6 + 2
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else if((cur % 10 != 9) && (cur + 1 <= n)) {
                cur += 1;
            } else {
                while((cur / 10) % 10 == 9) cur /= 10;
                cur = cur / 10 + 1;
            }
        }
        return res;
    }
};
// @lc code=end
