/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (33.20%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> ss;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                ss.push_back(s[i]);
            }else{
                if(ss.size() == 0)
                    return false;
                char tmp = ss[ss.size() - 1];
                ss.pop_back();
                if(s[i] == ')' && tmp != '(')
                    return false;
                else if(s[i] == ']' && tmp != '[')
                    return false;
                else if(s[i] == '}' && tmp != '{')
                    return false;
            }
        }
        if(ss.size() > 0) return false;
        return true;
    }
};
