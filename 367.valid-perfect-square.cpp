/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square
 *
 * Easy (38.10%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 *
 *
 *
 * Example 2:
 *
 * Input: 14
 * Returns: False
 *
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;
        while(low <= high){
            long long  mid = low + ((high - low) >> 1);
            long long sqmid = mid * mid;
            if(sqmid == num){
                return true;
            }else if(sqmid < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;

        // //newthon method
        // long x = num;
        // while (x * x > num) {
        //     x = (x + num / x) >> 1;
        // }
        // return x * x == num;
    }
};
