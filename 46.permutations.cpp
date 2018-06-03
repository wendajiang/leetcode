/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (47.37%)
 * Total Accepted:    232.6K
 * Total Submissions: 490.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
class Solution {
public:
    void recurse(vector<int>& nums, int s, int end, vector<vector<int>>& res){
        if(s == end){
            res.push_back(nums);
            return;
        }
        for(int i = s; i < nums.size(); i++){
            swap(nums[s], nums[i]);
            recurse(nums, s + 1, end, res);
            swap(nums[s], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        // sort(nums.begin(), nums.end());
        recurse(nums, 0, nums.size(), res);
        return res;
    }
};
