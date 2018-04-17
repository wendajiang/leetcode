/*
 * [804] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (50.60%)
 * Total Accepted:    7.3K
 * Total Submissions: 14.4K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 *
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 *
 * Now given a positive number N, how many numbers X from 1 to N are good?
 *
 *
 * Example:
 * Input: 10
 * Output: 4
 * Explanation:
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 *
 *
 * Note:
 *
 *
 * N  will be in range [1, 10000].
 *
 *
 */
class Solution {
public:
    const int i2j[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    bool judge(int num){
        int origin = num;
        vector<int> nn;
        while(num){
            int x = num % 10;
            num /= 10;
            if(i2j[x] == -1) return false;
            nn.push_back(i2j[x]);
        }
        if(nn.size() == 0) return false;
        int nw = nn[nn.size() - 1];
        for(int i = nn.size() - 2; i >= 0; i--){
            nw = nw * 10 + nn[i];
        }
        if(nw != origin) return true;
        else return false;
    }
    int rotatedDigits(int N) {
        int res = 0;
        for(int i = 2; i <= N; i++){
            if(judge(i)) {
                res++;
            }
        }
        return res;
    }
};
