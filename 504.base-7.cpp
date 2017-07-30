/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7
 *
 * Easy (44.52%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *
 * Input: 100
 * Output: "202"
 *
 *
 *
 * Example 2:
 *
 * Input: -7
 * Output: "-10"
 *
 *
 *
 * Note:
 * The input will be in range of [-1e7, 1e7].
 *
 */
class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if(num == 0) return {"0"};
        while(num){
            int c = num % 7;
            if(abs(num) < 7){
                res.insert(0, to_string(c));
            }else{
                res.insert(0, to_string(std::abs(c)));
            }
            num /= 7;
        }
        return res;
    }
};
