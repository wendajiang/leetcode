/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Medium (34.15%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 *
 *
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 *
 *
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        int length = digits.size();
        string solution;
        vector<string> res;
        map<char, vector<char>> dict{
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}},
            {'0',{'+'}}
        };
        getCombinations(digits, res, dict, solution, 0);
        return res;
    }

    void getCombinations(string digits, vector<string>& res, map<char,vector<char>> dict, string& solution, int level){

        if(level == digits.size()){
            res.push_back(solution);
            return;
        }
        vector<char> tmp = dict[digits[level]];
        for(auto x : tmp){
            solution.push_back(x);
            getCombinations(digits, res, dict, solution, ++level);
            level--;
            solution.pop_back();
        }
    }
};
