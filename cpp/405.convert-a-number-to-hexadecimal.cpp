/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal
 *
 * Easy (41.04%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '26'
 *
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 *
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 *
 *
 *
 * Example 2:
 *
 * Input:
 * -1
 *
 * Output:
 * "ffffffff"
 *
 *
 */
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return {"0"};
        string res;
        int mask = 0xf0000000;
        int i = 1;
        int tmp;
        while(i <= 8){
            tmp = ((num & mask) >> 28) & 0x0000000f;
            num <<= 4;
            i++;
            if(tmp == 0 && res.empty()){
                continue;
            }
            res.push_back(getHexChar(tmp));
        }
        return res;
    }
    char getHexChar(int n){
        if(n >= 0 && n <= 9){
            return '0' + n;
        }else{
            return 'a' + n - 10;
        }
    }

};
