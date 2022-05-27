/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.85%)
 * Likes:    1067
 * Dislikes: 1360
 * Total Accepted:    191.7K
 * Total Submissions: 740.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 *
 *
 */

// @lc code=start

// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/duo-qi-dian-hua-dong-chuang-kou-by-yexis-bl51/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {     
        static int x = []() {
            std::ios::sync_with_stdio(false);
            cin.tie(NULL);
            return 0; 
        }();   
        vector<int> res;
        // 设 words中所有单词的长度为 d
        int d = words[0].size();
        int L = 0;
        unordered_map<string, int> mp;
        for (auto &w : words) {
            L += w.size();
            mp[w]++;
        }

        // init: 初始化 d 个起点的 map
        vector<unordered_map<string, int>> vec_mp(d);
        for (int i = 0; i < d && i + L <= s.size(); i++) {
            for (int j = i; j < i + L; j += d) {
                string t = s.substr(j, d);
                vec_mp[i][t]++;
            }
            if (vec_mp[i] == mp) {
                res.push_back(i);
            }
        }

        // sliding window: 滑动窗口，对于每个 vec_mp 来说每次移动 d 个位置
        for (int i = d; i + L <= s.size(); i++) {
            int r = i % d;
            string ta = s.substr(i - d, d);
            string tb = s.substr(i + L - d, d);
            if (--vec_mp[r][ta] == 0) vec_mp[r].erase(ta);
            vec_mp[r][tb]++;
            if (vec_mp[r] == mp) {
                res.push_back(i);
            }
        }
        

        return res;
    }


    // TLE
    // vector<int> findSubstring(string s, vector<string> &words) {
    //     vector<int> res;
    //     if (words.size() == 0)
    //         return res;
    //     unordered_map<string, int> mp;
    //     for (auto &str : words) {
    //         mp[str]++;
    //     }
    //     int len = words[0].size();
    //     for (int i = 0; i < s.size(); i++) {
    //         auto tmp = mp;
    //         int cur = i;
    //         while (cur < s.size()) {
    //             auto str = s.substr(cur, len);
    //             if (tmp.count(str)) {
    //                 tmp[str]--;
    //                 if (0 == tmp[str]) {
    //                     tmp.erase(str);
    //                     if (tmp.size() == 0) {

    //                         res.push_back(i);
    //                         break;
    //                     }
    //                 }
    //                 cur += len;

    //                 if (tmp.size() == 0) break;
    //             } else {
    //                 break;
    //             }
    //         }
    //     }
    //     return res;
    // }

};
// @lc code=end
