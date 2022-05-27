/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii
 *
 * Medium (33.27%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 *
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 *
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 *
 *
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
 *
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> solution;
        std::sort(candidates.begin(), candidates.end());
        getCombinationSum2(res, solution, 0, 0, candidates, target);
        return res;
    }

    void getCombinationSum2(vector<vector<int>>& res, vector<int>& solution, int sum, int level, vector<int>& candidates, int target){
        if(sum > target) return;
        if(sum == target){
            res.push_back(solution);
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            sum += candidates[i];
            solution.push_back(candidates[i]);
            getCombinationSum2(res, solution, sum, i + 1, candidates, target);
            solution.pop_back();
            sum -= candidates[i];
            while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]) //剪枝条件
                i++;
        }
    }
};
