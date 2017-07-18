/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations
 *
 * Medium (39.29%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '4\n2'
 *
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 *
 *
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> candidates;
        for(int i = 1; i <= n; i ++){
            candidates.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> solution;
        getCombination(res, solution, 0, 0, k, candidates, n);
        return res;
    }
    void getCombination(vector<vector<int>>& res, vector<int>& solution, int sum, int level, int k, vector<int> candidates, int target){
        if(solution.size() == k){
            res.push_back(solution);
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            solution.push_back(candidates[i]);
            getCombination(res, solution, sum, i + 1, k, candidates, target);
            solution.pop_back();
        }
    }
};
