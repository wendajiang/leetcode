/*
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break
 *
 * Medium (45.69%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '2'
 *
 * 
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * 
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10
 * = 3 + 3 + 4).
 * 
 * 
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int result = INT_MIN;
        int tmp = 0;
        for(int i = 2; i <= n / 2; i++){
            int remainders = n % i;
            int multiplier = n / i;
            int count = i;
            tmp = productofnum(count,multiplier,remainders);
            if(tmp > result)
                result = tmp;
        }
        return result;
    }
    int productofnum(int count, int multiplier,int remainders){
        int result = 1;
        for(int i = 1; i <= count - remainders; i++){
            result *= multiplier;
        }
        for(int i = 1; i <= remainders; i++){
            result *= (multiplier + 1);
        }
        return result;
    }
};
