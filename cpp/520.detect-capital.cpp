/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital
 *
 * Easy (51.96%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"USA"'
 *
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 *
 *
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 *
 *
 * Example 1:
 *
 * Input: "USA"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "FlaG"
 * Output: False
 *
 *
 *
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 *
 */
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if(isLowercase(word[0])){
            for(int i = 1; i < word.size(); i++){
                if(isUppercase(word[i]))
                    return false;
            }
            return true;
        }else{
            if(isLowercase(word[1])){
                for(int i = 2; i < word.size(); i++){
                    if(isUppercase(word[i]))
                        return false;
                }
                return true;
            }else {
                for(int i = 2; i < word.size(); i++){
                    if(isLowercase(word[i]))
                        return false;
                }
                return true;
            }
        }
    }
    bool isUppercase(char a){
        return (a >= 'A') && (a <= 'Z');
    }
    bool isLowercase(char a){
        return (a >= 'a') && (a <= 'z');
    }
};
