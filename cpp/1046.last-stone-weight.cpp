/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 *
 * https://leetcode.com/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (62.45%)
 * Likes:    246
 * Dislikes: 14
 * Total Accepted:    29K
 * Total Submissions: 46.5K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * We have a collection of rocks, each rock has a positive integer weight.
 * 
 * Each turn, we choose the two heaviest rocks and smash them together.
 * Suppose the stones have weights x and y with x <= y.  The result of this
 * smash is:
 * 
 * 
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of
 * weight y has new weight y-x.
 * 
 * 
 * At the end, there is at most 1 stone left.  Return the weight of this stone
 * (or 0 if there are no stones left.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation: 
 * We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 * we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 * we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we combine 1 and 1 to get 0 so the array converts to [1] then that's the
 * value of last stone.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pri_que;
        for (int i = 0; i < stones.size(); i++) {
            pri_que.push(stones[i]);
        }

        while(pri_que.size() > 1) {
            int x = pri_que.top(); pri_que.pop();
            int y = pri_que.top(); pri_que.pop();
            int diff = x - y;
            if (diff > 0) {
                pri_que.push(diff);
            }
        }
        int res = pri_que.size() > 0 ? pri_que.top() : 0;
        return res;
    }
};
// @lc code=end

