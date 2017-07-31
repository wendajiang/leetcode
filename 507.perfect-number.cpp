/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number
 *
 * Easy (33.66%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself.
 *
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 *
 *
 * Example:
 *
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 *
 *
 *
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 *
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        // return n.count(num);
        vector<int>res(1,1);
        int upper=num;
        for(int i=2;i<upper;i++) if(num%i==0) res.push_back(i),res.push_back(num/i),upper=num/i;
        int sum=0;
        for(auto i:res) sum+=i;
        return sum==num && num!=1;
    }
};
