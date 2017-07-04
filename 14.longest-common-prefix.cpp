/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.39%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1)
            return "";
        if(strs.size() == 1){
            return strs[0];
        }
        int maxIndex = strs[0].size() - 1;
        for(int i = 1; i < strs.size(); i++){
            int tmp = commonPrefixIndex(strs[i], strs[i-1]);
            maxIndex = (maxIndex > tmp) ? tmp : maxIndex;
            if(maxIndex == -1)
                return "";
        }
        string result = strs[0].substr(0, maxIndex + 1);
        return result;
    }
    int commonPrefixIndex(string& s1,string& s2){
        int result = -1;
        if(s1.size() == 0 || s2.size() == 0)
            return result;
        int maxR = (s1.size() > s2.size()) ? s2.size() : s1.size();
        for(int i = 0; i < maxR; i++){
            if(s1[i] != s2[i]){
                break;
            }else{
                result = i;
            }
        }
        return result;
    }
};
