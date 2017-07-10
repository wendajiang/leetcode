/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string
 *
 * Medium (15.71%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '""'
 *
 *
 * Given an input string, reverse the string word by word.
 *
 *
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 *
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 *
 *
 * click to show clarification.
 *
 * Clarification:
 *
 *
 *
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 *
 *
 */

/*
思路整理：
题意要求是要如果有多个空格，将其压缩为一个空格

*/
class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0) return;
        int wordcount = 0;

        int index = 0;

        int begin = 0；
        int end = 0;

        while(true){
            while(index < s.size() && s[index] == ' ')index++;  //slip spaces in front of the word
            if(index == s.size())break;
            if(wordcount) s[end++] = ' ';
            begin = end;
            while(index < s.size() && s[index] != ' '){
                s[end] = s[index];
                index++;
                end++;
            }
            reverse(s, begin, end - 1);
            wordcount++;
        }
        s.resize(end);   //resize the string 
        reverse(s, 0, end - 1);
    }
    void reverse(string& s, int begin, int end){
        while(begin < end){
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
    }
};
