/*
 * [777] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (57.78%)
 * Total Accepted:    17.4K
 * Total Submissions: 30.2K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same element.
 *
 * Now given an M x N matrix, return True if and only if the matrix is
 * Toeplitz.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: True
 * Explanation:
 * 1234
 * 5123
 * 9512
 *
 * In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2,
 * 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the
 * answer is True.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2],[2,2]]
 * Output: False
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 *
 *
 * Note:
 *
 *
 * matrix will be a 2D array of integers.
 * matrix will have a number of rows and columns in range [1, 20].
 * matrix[i][j] will be integers in range [0, 99].
 *
 *
 *
 */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return true;
        for(int i = 0, j = 0; i < matrix.size(); i++, j = 0){
            int row = i, col = j;
            while(row < matrix.size() - 1 && col < matrix[0].size() - 1){
                if(matrix[row][col] == matrix[++row][++col]) continue;
                else return false;
            }
        }
        for(int i = 0, j = 1; j < matrix[0].size(); i = 0, j++){
            int row = i, col = j;
            while(row < matrix.size() - 1 && col < matrix[0].size() - 1){
                if(matrix[row][col] == matrix[++row][++col]) continue;
                else return false;
            }
        }
        return true;
    }
};
