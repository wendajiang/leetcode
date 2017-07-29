/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings
 *
 * Easy (41.28%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        int sum = 0;
        int i2 = num2.size() - 1;
        int i1 = num1.size() - 1;
        while(i2 >= 0 && i1 >= 0){
            sum = (carry + (num2[i2] - '0') + (num1[i1] - '0')) % 10;
            res.insert(0, to_string(sum));
            carry = (carry + (num2[i2] - '0') + (num1[i1] - '0')) / 10;
            i2--;
            i1--;
        }
        if(i2 >= 0){
            while(i2 >= 0){
                sum = (carry + (num2[i2] - '0')) % 10;
                res.insert(0, to_string(sum));
                carry = (carry + (num2[i2] - '0')) / 10;
                i2--;
            }
        }else{
            while(i1 >= 0){
                sum = (carry + (num1[i1] - '0')) % 10;
                res.insert(0, to_string(sum));
                carry = (carry + (num1[i1] - '0')) / 10;
                i1--;
            }
        }
        if(carry != 0)
            res.insert(0, to_string(carry));
        return res;
    }
};
