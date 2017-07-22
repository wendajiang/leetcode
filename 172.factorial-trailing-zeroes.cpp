/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes
 *
 * Easy (35.84%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    //思路是没变的，但是因为是1...n之间，有规律，5因子肯定比2因子多，所以只需要求5因子的个数
    //又因为是连续的，所以5, 5*5, 5*5*5...这样
    int trailingZeroes(int n){
        int res = 0;
        for(long long i = 5; n / i > 0; i *= 5){
            res += (n / i);
        }
        return res;
    }

    // //TLE case 500/502 1808548329
    // int trailingZeroes(int n) {
    //     if(n == 0) return 0;
    //     int sumt = 0;
    //     int sumf = 0;
    //     getSum(1, n, sumt, sumf);
    //     if(sumt > sumf){
    //         return sumf;
    //     }else{
    //         return sumt;
    //     }
    // }
    // void getSum(int start, int end, int& sumt, int& sumf){
    //     if(start >= end){
    //         getSum(start, sumt, sumf);
    //         return;
    //     }
    //     int mid = (start + end) / 2;
    //     getSum(start, mid, sumt, sumf);
    //     getSum(mid + 1, end, sumt, sumf);
    // }
    // void getSum(int e, int& sumt, int& sumf){
    //     while(e && e % 2 == 0){
    //         sumt++;
    //         e = e / 2;
    //     }
    //     while(e && e % 5 == 0){
    //         sumf++;
    //         e = e / 5;
    //     }
    // }
};
