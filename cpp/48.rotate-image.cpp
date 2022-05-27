/*
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image
 *
 * algorithms
 * Medium (38.45%)
 * Total Accepted:    121.4K
 * Total Submissions: 314.9K
 * Testcase Example:  '[[1]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
public:
    // //naive,but 6.89% ,>-<
    // void rotate(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i = 0; i < m; i++){
    //         for(int j = i; j < n; j++){
    //             int tmp = matrix[i][j];
    //             matrix[i][j] = matrix[j][i];
    //             matrix[j][i] = tmp;
    //         }
    //     }
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j <= (n - 1) / 2; j++){
    //             int tmp = matrix[i][j];
    //             matrix[i][j] = matrix[i][n - 1 - j];
    //             matrix[i][n - 1 -j] = tmp;
    //         }
    //     }
    // }

    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    // /*
    //  * anticlockwise rotate
    //  * first reverse left to right, then swap the symmetry
    //  * 1 2 3     3 2 1     3 6 9
    //  * 4 5 6  => 6 5 4  => 2 5 8
    //  * 7 8 9     9 8 7     1 4 7
    // */
    // void anti_rotate(vector<vector<int> > &matrix) {
    //     for (auto vi : matrix) reverse(vi.begin(), vi.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }


    }
};
