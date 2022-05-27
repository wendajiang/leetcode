/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs
 *
 * Easy (39.75%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '1'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Note: Given n will be a positive integer.
 *
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int fn1 = 1, fn2 = 2, fn = 0;
        for(int i = 3; i <= n; i++){
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;
        }
        return fn;
    }
};
