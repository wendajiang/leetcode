/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome
 *
 * Easy (26.10%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '""'
 *
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 *
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 *
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int start = 0;
        int end = s.size();
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(!check(s[start]))
            start++;
        while(!check(s[end]))
            end--;
        while(start < end){
            if(!check(s[start], s[end]))
                return false;
            start++;
            end--;
            while(!check(s[start]))
                start++;
            while(!check(s[end]))
                end--;
        }
        return true;
    }
    bool check(char c){
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        else
            return false;
    }
    bool check(char c1, char c2){
        if((c1 >= '0' && c1 <= '9') && (c2 >= '0' && c2 <= '9') && (c1 == c2))
            return true;
        else if((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z') && (c1 == c2))
            return true;
        else
            return false;
    }
};
