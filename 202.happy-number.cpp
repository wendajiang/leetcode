/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number
 *
 * Easy (40.37%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isHappy(int n) {
        int low = n, fast = n;
        do{
            low = powerByN(low);
            fast = powerByN(fast);
            fast = powerByN(fast);
        }while(low != fast);
        if(low == 1)
            return true;
        return false;
    }
    
    int powerByN(int n){
        int result = 0, tmp = 0;
        while(n){
            tmp = n % 10;
            result += tmp * tmp;
            n /= 10;
        }
        return result;
    }
};
