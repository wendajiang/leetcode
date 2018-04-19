/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.65%)
 * Total Accepted:    156.6K
 * Total Submissions: 452.1K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */
class Solution {
public:
    // int bsearch(vector<vector<int>>& matrix, int row, int target){
    //     int l = 0, r = matrix[row].size() - 1;
    //     while(l < r){
    //         int mid = (l + r) / 2;
    //         if(matrix[row][mid] >= target) r = mid;
    //         else l = mid + 1;
    //     }
    //     return l;
    // }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    //     int row = 0;
    //     for(; row < matrix.size(); row++){
    //         if(target >= matrix[row][0] && target <= matrix[row][matrix[row].size() - 1]){
    //             break;
    //         }
    //     }
    //     if(row == matrix.size()) return false;
    //     int col = bsearch(matrix, row, target);
    //     if(matrix[row][col] == target){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] >= target) r = mid;
            else l = mid + 1;
        }
        int row = l / n;
        int col = l % n;
        if(matrix[row][col] == target) return true;
        else return false;
    }
};
