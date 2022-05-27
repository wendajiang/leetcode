/*
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number
 *
 * Hard (12.70%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"3"'
 *
 * Validate if a given string is numeric.
 * 
 * 
 * Some examples:
 * "0" => true
 * "   0.1  " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 * 
 * 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button  to reset your code definition.
 * 
 */
class Solution {
public:
    bool isNumber(string s) {
        bool result = false;
        int index = 0;
        int length = s.size();
        while(index < length && s[index] == ' '){
            index ++;
        }
        if(s[index] == '+' || s[index] == '-')
            index ++;
        int nCount = 0, ptCount = 0;
        while(index < length && (s[index] == '.' || (s[index] >= '0' && s[index] <= '9'))){
            if(s[index] == '.')
                ptCount ++;
            else 
                nCount ++;
            index ++;
        }
        if(ptCount > 1 || nCount < 1)
            return false;
        if(s[index] == 'e'){
            index ++;
            if(s[index] == '+' || s[index] == '-')
                index ++;
            for(nCount = 0; s[index] >= '0' && s[index] <= '9'; index ++ , nCount++){}
            if(nCount < 1) return false;
        }
        
        while(index < length && s[index] == ' '){
            index ++;
        }
        if(index == length)
            result = true;
        return result;
    }
};
