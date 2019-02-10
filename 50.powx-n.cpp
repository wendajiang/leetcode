/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n
 *
 * Medium (26.45%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '8.88023\n3'
 *
 * Implement pow(x, n).
 *
 */
class Solution {
public:
    //origin -> TLE
    // double myPow(double x, int n) {
    //     if(n == 0) return 1.0;
    //     double result = 1.0;
    //     if(n < 0){
    //         for(int i = n; i > 0; n--){
    //             result *= x;
    //         }
    //         result = 1.0 / result;
    //     }else{
    //         for(int i = n; i > 0; n--){
    //             result *= x;
    //         }
    //     }
    //     return result;
    // }

    //第二种解法，使用二分法，可以得到O(logn)的解法
    /*
        一个很有趣的问题
        n & 1 != 0 可以很好的判断为奇数
        n & 1 == 0　判断偶数会出错？？
        =>结论：(n & 1) == 0是没错的，所以& 优先级比 == 低
    */
    // double power(double x, int n){
    //     if(n == 0) return 1.0;
    //     double v = power(x, n / 2);
    //     if((n & 0x01) == 0){
    //         return v * v;
    //     }else{
    //         return v * v * x;
    //     }
    // }
    // double myPow(double x, int n){
    //     if(n < 0){
    //         return  1.0 / power(x, -n);
    //     }else{
    //         return power(x, n);
    //     }
    // }

    //第三种解法
    double myPow(double x, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(n<0)
            {
                if(n==INT_MIN)
                    return 1.0 / (myPow(x,INT_MAX)*x);
                else
                    return 1.0 / myPow(x,-n);
            }
            if(n==0)
                return 1.0;
            double ans = 1.0 ;
            for(;n>0; x *= x, n>>=1)
            {
                if(n&1>0)
                    ans *= x;
            }
            return ans;
        }


};
