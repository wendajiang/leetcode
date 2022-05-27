/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 *
 * https://leetcode.com/problems/increasing-decreasing-string/description/
 *
 * algorithms
 * Easy (78.63%)
 * Likes:    99
 * Dislikes: 79
 * Total Accepted:    10.6K
 * Total Submissions: 14K
 * Testcase Example:  '"aaaabbbbcccc"'
 *
 * Given a string s. You should re-order the string using the following
 * algorithm:
 *
 *
 * Pick the smallest character from s and append it to the result.
 * Pick the smallest character from s which is greater than the last appended
 * character to the result and append it.
 * Repeat step 2 until you cannot pick more characters.
 * Pick the largest character from s and append it to the result.
 * Pick the largest character from s which is smaller than the last appended
 * character to the result and append it.
 * Repeat step 5 until you cannot pick more characters.
 * Repeat the steps from 1 to 6 until you pick all characters from s.
 *
 *
 * In each step, If the smallest or the largest character appears more than
 * once you can choose any occurrence and append it to the result.
 *
 * Return the result string after sorting s with this algorithm.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaaabbbbcccc"
 * Output: "abccbaabccba"
 * Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
 * After steps 4, 5 and 6 of the first iteration, result = "abccba"
 * First iteration is done. Now s = "aabbcc" and we go back to step 1
 * After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
 * After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat"
 * Output: "art"
 * Explanation: The word "rat" becomes "art" after re-ordering it with the
 * mentioned algorithm.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "leetcode"
 * Output: "cdelotee"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ggggggg"
 * Output: "ggggggg"
 *
 *
 * Example 5:
 *
 *
 * Input: s = "spo"
 * Output: "ops"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s contains only lower-case English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void cleanmap(map<char, int>& mm) {
        for (auto it = mm.begin(); it != mm.end(); ) {
            if (it->second == 0) {
                mm.erase(it++);
            }
            else {
                it++;
            }
        }
    }
    string sortString(string s) {
        string res = "";
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));

        for (auto c : s) {
            cnt[c - 'a'] ++;
        }

        while(res.size() < s.size()) {
            for (int i = 0 ; i < 26; i++) {
                if (cnt[i] > 0) {
                    cnt[i] --;
                    res.push_back('a' + i);
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (cnt[i] > 0) {
                    cnt[i] --;
                    res.push_back('a' + i);
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    string in("aaaabbbbcccc");
    Solution s;
    string res = s.sortString(in);
    cout << res << endl;
    return 0;

}
