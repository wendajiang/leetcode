//  Category: algorithms
//  Level: Easy
//  Percent: 54.417778%

//  Given a string s which consists of lowercase or uppercase letters, return
//  the length of the longest palindrome that can be built with those letters.
//
//  Letters are case sensitive, for example, "Aa" is not considered a palindrome
//  here.
//
//   
//  Example 1:
//
//  Input: s = "abccccdd"
//  Output: 7
//  Explanation: One longest palindrome that can be built is "dccaccd", whose
//  length is 7.
//
//
//  Example 2:
//
//  Input: s = "a"
//  Output: 1
//  Explanation: The longest palindrome that can be built is "a", whose length
//  is 1.
//
//
//   
//  Constraints:
//
//
//  	1 <= s.length <= 2000
//  	s consists of lowercase and/or uppercase English letters only.
//
#include <bits/stdc++.h>
using namespace std;

//  @lc code=start
class Solution {
   public:
    int longestPalindrome(string s) {
        vector<int> mp(256 + 1, 0);
        for (auto c : s) {
            mp[c]++;
        }
        int longest = 0;
        bool flag = false;
        for (auto count : mp) {
            if (count != 1 && (count & 1) != 0) {
                longest += count - 1;
                flag = true;
            } else if (count == 1) {
                flag = true;
            } else if ((count & 1) == 0) {
                longest += count;
            }
        }
        if (flag) longest += 1;
        return longest;
    }
};
//  @lc code=end
