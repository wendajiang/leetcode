/*
 * [546] Remove Boxes
 *
 * https://leetcode.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (35.81%)
 * Total Accepted:    5.9K
 * Total Submissions: 16.5K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]'
 *
 * Given several boxes with different colors represented by different positive
 * numbers.
 * You may experience several rounds to remove boxes until there is no box
 * left. Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k*k points.
 * Find the maximum points you can get.
 *
 *
 * Example 1:
 * Input:
 *
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 *
 * Output:
 *
 * 23
 *
 * Explanation:
 *
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
 * ----> [1, 3, 3, 3, 1] (1*1=1 points)
 * ----> [1, 1] (3*3=9 points)
 * ----> [] (2*2=4 points)
 *
 *
 *
 * Note:
 * The number of boxes n would not exceed 100.
 *
 *
 */
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        int len = boxes.size();
        return dfs(boxes, 0, len - 1, 0);
    }

private:
    int dp[101][101][101];
    int dfs(vector<int>& boxes, int l, int r, int k){
        if(l > r) return 0;
        if(dp[l][r][k]) return dp[l][r][k];

        while(r > l && boxes[r] == boxes[r - 1]) {r --; k ++;}
        dp[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for(int i = l; i < r; i++){
            if(boxes[r] == boxes[i])
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
        }
        return dp[l][r][k];
    }

};
