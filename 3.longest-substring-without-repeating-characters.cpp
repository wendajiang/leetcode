/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * Medium (24.20%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:

    int lengthOfLongestSubstring(string s){
        vector<int> mp(128, 0);
        int start = 0, end = 0, counter = 0, d = 0;
        while(end < s.size()){
            if(mp[s[end++]] ++ > 0) counter++;
            while(counter > 0)
                if(mp[s[start++]] -- > 1)
                    counter --;
            d = std::max(d, end - start);
        }
        return d;
    }
    // int lengthOfLongestSubstring(string s) {
    //     int count[256];
    //     memset(count, -1, 256*sizeof(int));
    //     int len = 0, maxL = 0;
    //     for(int i = 0; i < s.size(); i++,len++){
    //         if(count[s[i]] >= 0){
    //             maxL = max(len, maxL);
    //             len = 0;
    //             i = count[s[i]] + 1;
    //             memset(count, -1, 256*sizeof(int));
    //         }
    //         count[s[i]] = i;
    //     }
    //     return max(len, maxL);
    // }

};
