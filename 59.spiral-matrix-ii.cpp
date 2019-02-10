/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (41.03%)
 * Total Accepted:    100.2K
 * Total Submissions: 244.2K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int row = 0, col = 0;
        int u = 0, d = n - 1, l = 0, r = n - 1;
        int i = 1;
        while(true){
            for(col = l; col <= r; col++) res[u][col] = i++;
            if(++u > d) break;
            for(row = u; row <= d; row++) res[row][r] = i++;
            if(--r < l) break;
            for(col = r; col >= l; col--) res[d][col] = i++;
            if(--d < u) break;
            for(row = d; row >= u; row--) res[row][l] = i++;
            if(++l > r) break;
        }
        return res;
    }
};
