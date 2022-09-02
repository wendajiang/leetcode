//  Category: algorithms
//  Level: Medium
//  Percent: 32.330627%

//  Given a string s, return the longest palindromic substring in s.
//
//   
//  Example 1:
//
//  Input: s = "babad"
//  Output: "bab"
//  Explanation: "aba" is also a valid answer.
//
//
//  Example 2:
//
//  Input: s = "cbbd"
//  Output: "bb"
//
//
//   
//  Constraints:
//
//
//  	1 <= s.length <= 1000
//  	s consist of only digits and English letters.
//

#include <bits/stdc++.h>
using namespace std;
//  @lc code=start
class Solution {
   public:
    // // 1. 中心扩展法
    // int expandPalindrome(string &s, int left, int right) {
    //     while (left >= 0 && right < s.size()) {
    //         if (s[left] == s[right]) {
    //             left--;
    //             right++;
    //         } else {
    //             break;
    //         }
    //     }
    //     return right - left - 1;
    // }
    // string longestPalindrome(string s) {
    //     if (s.size() == 0) return s;
    //     int l = 0, r = 0;
    //     for (size_t i = 0; i < s.size(); i++) {
    //         int len1 = expandPalindrome(s, i, i);  // s[i] 为中心
    //         int len2 =
    //             expandPalindrome(s, i, i + 1);  // s[i], s[i + 1] 中间为中心
    //         int len = max(len1, len2);
    //         if (len > r - l) {
    //             l = i - (len - 1) / 2;
    //             r = i + len / 2;
    //         }
    //     }
    //     return s.substr(l, r - l + 1);
    // }

    // // 2. dp
    // string longestPalindrome(string s) {
    //     vector<vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
    //     int maxL = 0, start = 0, end = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         for (int j = i - 1; j >= 0; j--) {
    //             dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]));
    //             if (dp[j][i] && maxL < (i - j + 1)) {
    //                 maxL = i - j + 1;
    //                 start = j;
    //                 end = i;
    //             }
    //         }
    //         dp[i][i] = 1;
    //     }
    //     return s.substr(start, end - start + 1);
    // }

    // 3. manacher 马拉车算法
    // 本质还是中心扩散，不过利用了类似 KMP
    // 算法的技巧，遍历过程中记录已经遍历过的子串的信息
    /**
     * @brief manacher 算法
     * https://www.cxyxiaowu.com/2869.html
     *
     * 1. 预处理-添加分隔符
     *  - 新字符串的回文子串长度一定是奇数
     *  - 新字符串的回文子串一定以分隔符作为两边边界
     * 2. 计算辅助数组 p p[i] 表示第 i 个字符同时扩散的最大步数
     *  - 辅助数组 p 的最大值就是最长回文子串的长度
     *
     * 主要问题就是如何高效求辅助数组
     */
    string longestPalindrome(string s) {
        if (s.size() == 0) return s;
        string s1;
        for (int i = 0; i < s.size(); i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";

        int max_right = 0;
        int center = 0;
        int max_len = 1;
        int max_pos = 0;
        vector<int> p(s1.size(), 0);
        for (int i = 0; i < s1.size(); i++) {
            if (i < max_right) {
                // i at left of max_right
                int mirror = center * 2 - i;
                p[i] = min(p[mirror], max_right - i);
            }

            int left = i - (1 + p[i]);
            int right = i + (1 + p[i]);
            // try to push right the p[i]
            while (left >= 0 && right < s1.size() && s1[left] == s1[right]) {
                p[i] += 1;
                left--;
                right++;
            }

            if (i + p[i] > max_right) {
                max_right = i + p[i];
                center = i;
            }

            if (p[i] > max_len) {
                max_len = p[i];
                max_pos = (i - max_len) / 2;
            }
        }
        return s.substr(max_pos, max_len);
    }
};
//  @lc code=end
