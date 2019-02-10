/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four
 *
 * Easy (38.33%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '16'
 *
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 *
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        // if(num == 1) return true;
        // int mark = 0x55555554;
        // int notmark = 0xaaaaaaab;
        // int result1 = (num & mark);
        // int count = 0;
        // while(result1){
        //     count++;
        //     result1 = result1 & (result1 - 1);
        // }
        // int result2 = (num & notmark);
        // if(count == 1 && result2 == 0){
        //     return true;
        // }else
        //     return false;

        return fmod((log10(num) / log10(4)), 1) == 0;
    }
};
