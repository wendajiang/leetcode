/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * Medium (15.97%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0\n1'
 *
 *
 * Divide two integers without using multiplication, division and mod
 * operator.
 *
 *
 * If it is overflow, return MAX_INT.
 *
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;
        bool flag = false;
        if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0))
            flag = true;

        long long c = dividend;
        long long d = divisor;

        long long a = std::abs(c);
        long long b = std::abs(d);
        long long sum = 0;

        long count = 0;
        long n = 0;
        while(a >= b){
            sum = b;
            count = 1;
            while(sum + sum <= a){
                sum += sum;
                count += count;
            }
            a -= sum;
            n += count;
        }
        //处理各种边界情况
        if(!flag){
            if(0 - n < INT_MIN)
                return INT_MIN;
            else
                return 0 - n;
        }else{
            if(n > INT_MAX)
                return INT_MAX;
            else
                return n;
        }

    }
};
