/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number
 *
 * Medium (37.51%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1\n[2,3,5]'
 *
 * 
 * ⁠   Write a program to find the nth super ugly number.
 * 
 * 
 * 
 * ⁠   Super ugly numbers are positive numbers whose all prime factors are in
 * the given prime list
 * ⁠   primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28,
 * 32]
 * ⁠is the sequence of the first 12 super ugly numbers given primes
 * ⁠   = [2, 7, 13, 19] of size 4.
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   (1) 1 is a super ugly number for any given primes.
 * ⁠   (2) The given numbers in primes are in ascending order.
 * ⁠   (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * ⁠   (4) The nth super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> tmpMin(k, 0);
        int *UglyNumbers = new int[n];
        int* *pMk = new int*[k];
        for(int i = 0; i < k; i++){
            pMk[i] = UglyNumbers;
        }
        UglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        while(nextUglyIndex < n){
            for(int i = 0; i < k; i++){
                tmpMin[i] = *pMk[i] * primes[i];
            }
            int min = Min(tmpMin, k);
            UglyNumbers[nextUglyIndex] = min;
            for(int i = 0; i < k; i++){
                while(*pMk[i] * primes[i] <= UglyNumbers[nextUglyIndex])
                    pMk[i] ++;
            }
            nextUglyIndex ++;
        }
        int ugly = UglyNumbers[nextUglyIndex - 1];
        delete[] UglyNumbers;
        delete[] pMk;
        return ugly;
        
        
    }
    
    int Min(vector<int> &tmp, int k){
        int min = INT_MAX;
        for(int i = 0; i < k; i++){
            min = (min < tmp[i]) ? min : tmp[i];
        }
        return min;
    }
};
