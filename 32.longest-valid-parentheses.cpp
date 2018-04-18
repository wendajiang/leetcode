/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.21%)
 * Total Accepted:    123.4K
 * Total Submissions: 531.9K
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 *
 *
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 *
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1) return 0;
        int mx = 0;
        int last = -1;
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty()){
                    last = i;
                }else{
                    st.pop();
                    if(st.empty())
                        mx = max(mx, i - last);
                    else
                        mx = max(mx, i - st.top());
                }
            }
        }
        return mx;
    }
};
