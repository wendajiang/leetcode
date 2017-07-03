/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string
 *
 * Easy (58.86%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        auto begin = s.begin();
        auto end = --s.end();
        
        while(begin <= end){
            auto c = *begin;
            *begin = *end;
            *end = c;
            begin ++;
            end --;
        }
        return s;
    }
};
