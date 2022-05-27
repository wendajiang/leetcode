/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (35.12%)
 * Total Accepted:    161.5K
 * Total Submissions: 459.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
        for(int i = s; i < end; i++){
            int j = i - 1;
            //judge whether num[i] and num[s...i - 1] are equal
            while(j >= s && nums[j] != nums[i]) j--;
            if(i == s || j == s - 1){
                swap(nums[i], nums[s]);
                recurse(nums, s + 1, end, res);
                swap(nums[i], nums[s]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        // sort(nums.begin(), nums.end());
        recurse(nums, 0, nums.size(), res);
        return res;
    }
};
