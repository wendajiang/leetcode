/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * Easy (38.31%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addNumLen = digits.size();
        vector<int> result;
        int c = (digits[addNumLen - 1] + 1) /10;
        result.insert(result.begin(), (digits[addNumLen - 1] + 1) % 10);
        for(int i = addNumLen - 2; i >= 0; i--){
            result.insert(result.begin(), (c + digits[i]) % 10);
            c = (c + digits[i]) / 10;
        }
        if(c > 0)
            result.insert(result.begin(), c);
        return result;
    }
};
