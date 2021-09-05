/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 *
 * https://leetcode.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (33.28%)
 * Likes:    472
 * Dislikes: 82
 * Total Accepted:    21.1K
 * Total Submissions: 63.3K
 * Testcase Example:  '["Solution","pick","pick","pick","pick","pick","pick","pick"]\n' +
  '[[7,[2,3,5]],[],[],[],[],[],[],[]]'
 *
 * You are given an integer n and an array of unique integers blacklist. Design
 * an algorithm to pick a random integer in the range [0, n - 1] that is not in
 * blacklist. Any integer that is in the mentioned range and not in blacklist
 * should be equally likely returned.
 *
 * Optimize your algorithm such that it minimizes the call to the built-in
 * random function of your language.
 *
 * Implement the Solution class:
 *
 *
 * Solution(int n, int[] blacklist) Initializes the object with the integer n
 * and the blacklisted integers blacklist.
 * int pick() Returns a random integer in the range [0, n - 1] and not in
 * blacklist. All the possible integers should be equally likely returned.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
 * [[7, [2, 3, 5]], [], [], [], [], [], [], []]
 * Output
 * [null, 6, 4, 1, 6, 1, 6, 4]
 *
 * Explanation
 * Solution solution = new Solution(7, [2, 3, 5]);
 * solution.pick(); // return 6, any integer from [1,4,6] should be ok. Note
 * that for every call of pick, 1, 4, and 6 must be equally likely to be
 * returned (i.e., with probability 1/3).
 * solution.pick(); // return 4
 * solution.pick(); // return 1
 * solution.pick(); // return 6
 * solution.pick(); // return 1
 * solution.pick(); // return 6
 * solution.pick(); // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 * 0 <= blacklist.length <- min(10^5, n - 1)
 * 0 <= blacklist[i] < n
 * All the values of blacklist are unique.
 * At most 2 * 10^4 calls will be made to pick.
 *
 *
 */

// @lc code=start
// https://www.cnblogs.com/grandyang/p/10029772.html
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> st;
        kN = n - blacklist.size();
        for (int i = kN; i < n; i++) st.insert(i);
        for (int num : blacklist) st.erase(num);
        auto it = st.begin();
        for (int num : blacklist) {
            if (num < kN) m[num] = *it++;
        }
    }

    int pick() {
        int k = rand() % kN;
        return m.count(k) ? m[k] : k;
    }

private:
    unordered_map<int, int> m;
    int kN;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
