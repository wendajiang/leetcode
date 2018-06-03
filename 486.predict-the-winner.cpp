/*
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (45.33%)
 * Total Accepted:    27.7K
 * Total Submissions: 61.1K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins.
 *
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score.
 *
 * Example 1:
 *
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2
 * (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5,
 * then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 +
 * 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you
 * need to return False.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose
 * 233.Finally, player 1 has more score (234) than player 2 (12), so you need
 * to return True representing player1 can win.
 *
 *
 *
 * Note:
 *
 * 1
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 *
 *
 */
class Solution {
public:
    // bool PredictTheWinner(vector<int>& nums) {
    //     int len = nums.size();
    //     if(len <= 1) return true;
    //     vector<vector<int>> dp(len, vector<int>(len, 0));
    //
    //     for (int i = 0; i < len; i++) {
    //         dp[i][i] = nums[i];
    //     }
    //     for (int i = len - 2; i >= 0; i--) {
    //         for (int j = i + 1; j < len; j++){
    //             dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
    //         }
    //     }
    //     return dp[0][len - 1] >= 0;
    // }



//     //不是DP，只是简单的递归 O(2^n)
//     bool PredictTheWinner(vector<int>& nums){
//         return GetScore(nums, 0, nums.size() - 1) >= 0;
//     }
// private:
//     int GetScore(vector<int>& nums, int l, int r){
//         if(l == r) return nums[l];
//         return max(nums[l] - GetScore(nums, l + 1, r),
//                     nums[r] - GetScore(nums, l, r - 1));
//     }

    //记忆化搜索/DP
    bool PredictTheWinner(vector<int>& nums){
        m_ = vector<int>(nums.size() * nums.size(), 0);
        return GetScore(nums, 0, nums.size() - 1) >= 0;
    }
private:
    vector<int> m_;
    int GetScore(vector<int>& nums, int l, int r){
        if(l == r) return nums[l];
        int k = l * nums.size() + r;
        if(m_[k] > 0) return m_[k];
        m_[k] =  max(nums[l] - GetScore(nums, l + 1, r),
                nums[r] - GetScore(nums, l, r - 1));
        return m_[k];
    }


};
