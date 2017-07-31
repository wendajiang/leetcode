/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row
 *
 * Easy (59.98%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 *
 *
 *
 * Note:
 *
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 *
 *
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp{{'q',1},{'Q',1},{'w',1},{'W',1},{'e',1},{'E',1},{'r',1},{'R',1},{'t',1},{'T',1},{'y',1},{'Y',1},
                            {'u',1},{'U',1},{'i',1},{'I',1},{'o',1},{'O',1},{'p',1},{'P',1},
                            {'a',2},{'A',2},{'s',2},{'S',2},{'d',2},{'D',2},{'f',2},{'F',2},{'g',2},{'G',2},{'h',2},{'H',2},{'j',2},{'J',2},{'k',2},{'K',2},{'l',2},{'L',2},
                            {'z',3},{'Z',3},{'x',3},{'X',3},{'c',3},{'C',3},{'v',3},{'V',3},{'b',3},{'B',3},{'n',3},{'N',3},{'m',3},{'M',3}};
        vector<string> res;
        bool flag = true;
        for(int i = 0; i < words.size(); i++){
            int tmp = mp[words[i][0]];
            for(int j = 0; j < words[i].size(); j++){
                if(mp[words[i][j]] != tmp)
                    flag = false;
            }
            if(!flag){

            }else{
                res.push_back(words[i]);
            }
            flag = true;
        }
        return res;
    }
};
