/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii
 *
 * Easy (59.92%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        int begin = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] ==  ' ' || i == s.size() - 1){
                reverseCore(s, begin, (i == s.size() - 1) ? end : end - 1);
                begin = i + 1;
                end = begin;
            }else{
                end ++;
            }
        }
        return s;
    }
    void reverseCore(string &s, int begin, int end){
        while(begin <= end){
            auto c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            begin ++;
            end --;
        }
    }
};
