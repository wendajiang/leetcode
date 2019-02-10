/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii
 *
 * Medium (44.52%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 *
 *
 * ⁠Example 1:
 * Input:  k = 3,  n = 7
 * Output:
 *
 * [[1,2,4]]
 *
 *
 * ⁠Example 2:
 * Input:  k = 3,  n = 9
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i = 1; i <= 9; i ++){
            candidates.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> solution;
        getCombinationSum3(res, solution, 0, 0, k, candidates, n);
        return res;
    }
    void getCombinationSum3(vector<vector<int>>& res, vector<int>& solution, int sum, int level, int k, vector<int> candidates, int target){
        if(sum > target) return;
        if(sum == target){
            if(solution.size() == k)
                res.push_back(solution);
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            solution.push_back(candidates[i]);
            sum += candidates[i];
            getCombinationSum3(res, solution, sum, i + 1, k, candidates, target);
            solution.pop_back();
            sum -= candidates[i];
            while(i < candidates.size() - 1 && candidates[i] == candidates[i+1])
                i++;
        }
    }
};
