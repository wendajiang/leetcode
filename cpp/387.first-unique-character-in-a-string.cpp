/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string
 *
 * Easy (46.48%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(256 + 1, 0);
        for(auto c : s){
            mp[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
