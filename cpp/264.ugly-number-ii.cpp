/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii
 *
 * Medium (32.34%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 0)
            return 0;
        int *UglyNumbers = new int[n];
        UglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        
        int *pM2 = UglyNumbers;
        int *pM3 = UglyNumbers;
        int *pM5 = UglyNumbers;
        while(nextUglyIndex < n){
            int min = Min(*pM2 * 2, *pM3 * 3, *pM5 * 5);
            UglyNumbers[nextUglyIndex] = min;
            while(*pM2 * 2 <= UglyNumbers[nextUglyIndex])
                pM2++;
            while(*pM3 * 3 <= UglyNumbers[nextUglyIndex])
                pM3++;
            while(*pM5 * 5 <= UglyNumbers[nextUglyIndex])
                pM5++;
            nextUglyIndex++;
            
        }
        int ugly = UglyNumbers[nextUglyIndex - 1];
        delete[] UglyNumbers;
        return ugly;
    }
    
private:
    int Min(int n1, int n2, int n3){
        int min = (n1 < n2) ? n1 : n2;
        min = (min < n3) ? min : n3;
        return min;
    }
};
