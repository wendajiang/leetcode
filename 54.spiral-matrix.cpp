/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.31%)
 * Total Accepted:    140.6K
 * Total Submissions: 514.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int row = 0, col = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int u = 0, d = rows - 1, l = 0, r = cols - 1;
        while(true){
            for(col = l; col <= r; col++) res.push_back(matrix[u][col]);
            if(++u > d) break;
            for(row = u; row <= d; row++) res.push_back(matrix[row][r]);
            if(--r < l) break;
            for(col = r; col >= l; col--) res.push_back(matrix[d][col]);
            if(--d < u) break;
            for(row = d; row >= u; row--) res.push_back(matrix[row][l]);
            if(++l > r) break;
        }
        return res;
    }
};
