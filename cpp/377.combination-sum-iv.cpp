/*
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv
 *
 * Medium (41.77%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,3]\n4'
 *
 * ⁠Given an integer array with all positive numbers and no duplicates, find
 * the number of possible combinations that add up to a positive integer
 * target.
 *
 * Example:
 *
 * nums = [1, 2, 3]
 * target = 4
 *
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 *
 * Note that different sequences are counted as different combinations.
 *
 * Therefore the output is 7.
 *
 *
 *
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 *
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    /*
    错误答案：先求出各种序列的一种情况，然后对
    */
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<vector<int>> res;
    //     vector<int> solution;
    //     std::sort(nums.begin(), nums.end());
    //     getCombinationSum4(res, solution, 0, 0, nums, target);
    //     vector<int> tmp;
    //     for(int i = 0; i < res.size(); i++){
    //         vector<int> seq = res[i];
    //         int count = 0;
    //         for(int j = 0; j < seq.size(); j++){
    //             while(j < seq.size() - 1 && seq[j] == seq[j + 1]){
    //                 j++;
    //                 count++;
    //             }
    //         }
    //
    //         tmp.push_back(AC(seq.size(), count+1));
    //     }
    //     int sum = 0;
    //     for(auto x : tmp){
    //         sum += x;
    //         cout << x << endl;
    //     }
    //     return sum;
    // }
    // void getCombinationSum4(vector<vector<int>>& res, vector<int>& solution, int sum, int level, vector<int>& candidates, int target){
    //     if(sum > target) return;
    //     if(sum == target) {
    //         res.push_back(solution);
    //     }
    //     for(int i = level; i < candidates.size(); i++){
    //         sum += candidates[i];
    //         solution.push_back(candidates[i]);
    //         getCombinationSum4(res, solution, sum, i, candidates, target);
    //         solution.pop_back();
    //         sum -= candidates[i];
    //     }
    // }
    // int AC(int n, vector<int> k){
    //     int tmp = 1;
    //     for(int i = n; i > k; i--){
    //         tmp *= i;
    //     }
    //     return tmp;
    // }

    int combinationSum4(vector<int>& nums, int target){
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
