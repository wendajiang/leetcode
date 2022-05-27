/*
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (39.06%)
 * Total Accepted:    105.4K
 * Total Submissions: 269.9K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 *
 *
 * For example,
 *
 * Consider the following matrix:
 *
 *
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 *
 *
 * Given target = 5, return true.
 * Given target = 20, return false.
 */
class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    //     int m = matrix.size(), n = matrix[0].size();
    //     int row = 0, col = n - 1;
    //     while (row < m && col >= 0) {
    //         if (target == matrix[row][col]) return true;
    //         else if (target < matrix[row][col]) col--;
    //         else row++;
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target){

    }
};
