/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets
 *
 * algorithms
 * Medium (40.59%)
 * Total Accepted:    174.4K
 * Total Submissions: 429.6K
 * Testcase Example:  '[1,2,3]'
 *
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 *
 *
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 */
class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> solution;
    //     vector<vector<int>> ans;
    //     dfs(nums, 0, solution, ans);
    //     return ans;
    // }
    //
    // void dfs(vector<int>& nums, int start, vector<int>& solution, vector<vector<int>>& ans){
    //     ans.push_back(solution);
    //     for(int i = start; i < nums.size(); i++){
    //         solution.push_back(nums[i]);
    //         dfs(nums, i + 1, solution, ans);
    //         solution.pop_back();
    //     }
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for(int i = 0; i < nums.size(); i ++){
            int n = subs.size();
            for(int j = 0; j < n; j++){
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int subs_size = pow(2, nums.size());
    //     vector<vector<int>> subs(subs_size, vector<int>());
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = 0; j < subs_size; j ++){
    //             if((j >> i) & 1)
    //                 subs[j].push_back(nums[i]);
    //         }
    //     }
    //     return subs;
    // }
};
