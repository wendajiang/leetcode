/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings
 *
 * Easy (33.63%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    // bool isIsomorphic(string s, string t) {
    //     if(s.size() != t.size()) return false;
    //     map<char,char> mapping;
    //     for(int i = 0; i < s.size(); i++){
    //         if(mapping.find(s[i]) != mapping.cend()){
    //             if(mapping[s[i]] != t[i]) //if the matching postition letter is not matched
    //                 return false;
    //         }else{
    //             for(auto it : mapping){
    //                 if(it.second == t[i])
    //                     return false;
    //             }//if two characters map to the same character
    //             mapping[s[i]] = t[i];
    //         }
    //     }
    //     return true;
    // }
    bool isIsomorphic(string s, string t){
        vector<int> mapping(256 + 1, 0);
        vector<int> mapping2(256 + 1, 0);
        for(int i = 0; i < s.size(); i++){
            if(mapping[s[i]] == 0 && mapping2[t[i]] == 0){
                mapping[s[i]] = t[i];
                mapping2[t[i]] = s[i];
            }else{
                if(mapping[s[i]] != t[i] || mapping2[t[i]] != s[i])
                    return false;
            }
        }
        return true;

        // //问题在于无法判断是否映射到同一个letter上
        // vector<int> mapping(256 + 1, 0);
        // for(int i = 0; i < s.size(); i++){
        //     if(mapping[s[i]] == 0){
        //         mapping[s[i]] = t[i];
        //     }else{
        //         if(mapping[s[i]] != t[i])
        //             return false;
        //     }
        // }
        // return true;
    }
};
