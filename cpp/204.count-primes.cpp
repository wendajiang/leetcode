/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes
 *
 * Easy (26.45%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int countPrimes(int n) {
        int count =0;
        int upper = sqrt(n);
        vector<bool> isPrimer(n + 1, true);
        for(int i = 2; i <= upper; i++){
            if(isPrimer[i]){
                for(int j = 2; j * i <= n; j++)
                    isPrimer[j * i] = false;
            }
        }
        for(int i = 2; i < n; i++){
            if(isPrimer[i])
                count ++;
        }
        return count;
    }
};
