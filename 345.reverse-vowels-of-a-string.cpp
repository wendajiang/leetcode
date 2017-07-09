/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string
 *
 * Easy (38.32%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 *
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 */
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> sindex;
        map<char, int> vowelMap;
        vowelMap['a'] = 1;
        vowelMap['e'] = 1;
        vowelMap['i'] = 1;
        vowelMap['o'] = 1;
        vowelMap['u'] = 1;
        vowelMap['A'] = 1;
        vowelMap['E'] = 1;
        vowelMap['I'] = 1;
        vowelMap['O'] = 1;
        vowelMap['U'] = 1;
        for(int i = 0; i < s.size(); i++){
            if(vowelMap[s[i]] == 1){
                sindex.push_back(i);
            }
        }
        int begin = 0;
        int end = sindex.size() - 1;
        while(begin < end){
            auto tmp = s[sindex[begin]];
            s[sindex[begin]] = s[sindex[end]];
            s[sindex[end]] = tmp;
            begin++;
            end--;
        }
        return s;
    }
};
