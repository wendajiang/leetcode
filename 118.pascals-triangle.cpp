/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * Easy (38.30%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> solution;
        for(int i = 0; i < numRows; i++){
            if(i == 0){
                solution.push_back(1);
            }else {
                for(int j = 0; j <= i; j++){
                    if(j == 0 || j == i){
                        solution.push_back(1);
                    }else{
                        solution.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                    }
                }
            }
            res.push_back(solution);
            solution.erase(solution.begin(), solution.end());
        }
        return res;
    }
};
