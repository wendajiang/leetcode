/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * Easy (27.67%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */
class Solution {
public:
    //牛顿法
    const float EPS = 0.000000001;
    int mySqrt(int x) {
        if(x == 0)return x;
        float dividend = x;
        float val = x;
        float last;
        do{
            last = val;
            val = (val + dividend/val) / 2;
        }while (abs(val - last) > EPS);
        int result = val;
        if(result * result > x){
            result --;
        }
        return result;
    }
};
