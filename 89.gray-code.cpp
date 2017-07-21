/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code
 *
 * Medium (40.84%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 */
class Solution {
public:

    //成熟的数学解决方案
    vector<int> grayCode(int n){
        vector<int> res;
        int size = 1 << n;
        for(int i = 0; i < size; i++){
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }

    // //通过观察可以发现n = k时的格雷码，就是n = k - 1时的格雷码逆序加上1 << k
    // vector<int> grayCode(int n) {
    //     vector<int> res;
    //     int highBit = 0;
    //     res.push_back(0);
    //     for(int i = 0; i < n; i++){
    //         int len = res.size();
    //         highBit = 1 << i;
    //         for(int j = len - 1; j >= 0; j--){
    //             res.push_back(highBit + res[j]);
    //         }
    //     }
    //     return res;
    // }
};
