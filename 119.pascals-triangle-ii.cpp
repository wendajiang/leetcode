/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii
 *
 * Easy (36.57%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 *
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        int lastNum = 1;
        int tmp = 1;
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    continue;
                }
                tmp = res[j];
                res[j] = res[j] + lastNum;
                lastNum = tmp;
            }
        }
        return res;
    }
};
