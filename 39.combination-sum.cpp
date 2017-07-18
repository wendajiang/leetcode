/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum
 *
 * Medium (38.06%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T.
 *
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 *
 *
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 * A solution set is:
 *
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> solution;
        std::sort(candidates.begin(), candidates.end());
        getCombinationSum(res, solution, 0, 0, candidates, target);
        return res;
    }
    void getCombinationSum(vector<vector<int>>& res, vector<int>& solution, int sum, int level, vector<int>& candidates, int target){
        if(sum > target) return;
        if(sum == target) {
            res.push_back(solution);
        }
        for(int i = level; i < candidates.size(); i++){
            sum += candidates[i];
            solution.push_back(candidates[i]);
            getCombinationSum(res, solution, sum, i, candidates, target);
            solution.pop_back();
            sum -= candidates[i];
        }
    }
};
