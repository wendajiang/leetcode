/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note
 *
 * Easy (47.07%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"a"\n"b"'
 *
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 *
 *
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 *
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 *
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(256 + 1, 0);
        for(auto e : magazine){
            mp[e]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(mp[ransomNote[i]]-- <= 0)
                return false;
        }
        return true;
    }
};
