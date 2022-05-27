/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes
 *
 * algorithms
 * Medium (35.94%)
 * Total Accepted:    108.7K
 * Total Submissions: 302.4K
 * Testcase Example:  '[[0]]'
 *
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 *
 *
 * click to show follow up.
 *
 * Follow up:
 *
 *
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 *
 */
class Solution {
public:
    // //34.98%
    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<int> rows;
    //     vector<int> columns;
    //     for(int i = 0; i < matrix.size(); i++){
    //         for(int j = 0; j < matrix[i].size(); j++){
    //             if(matrix[i][j] == 0){
    //                 rows.push_back(i);
    //                 columns.push_back(j);
    //             }
    //         }
    //     }
    //     for(auto e : rows){
    //         for(int j = 0; j < matrix[e].size(); j++){
    //             matrix[e][j] = 0;
    //         }
    //     }
    //     for(auto e : columns){
    //         for(int i = 0; i < matrix.size(); i++){
    //             matrix[i][e] = 0;
    //         }
    //     }
    // }

    // discuss 89.1%  (59 - 7) ms
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), columns = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < columns; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = rows - 1; i >= 0; i--){
            for(int j = columns - 1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};
