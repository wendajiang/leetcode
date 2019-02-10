/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum
 *
 * Medium (21.56%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int target = 0 - nums[i];
            int start = i + 1, end = len - 1;
            while(start < end){
                if(nums[start] + nums[end] == target){
                    {
                        vector<int> solution;
                        solution.push_back(nums[i]);
                        solution.push_back(nums[start]);
                        solution.push_back(nums[end]);
                        result.push_back(solution);
                        start++;
                        end--;
                        while(start < end && nums[start] == nums[start - 1])
                            start++;
                        while(start < end && nums[end] == nums[end + 1])
                            end--;
                    }
                }else if(nums[start] + nums[end] < target){
                    start++;
                }else{
                    end--;
                }
            }
            if(i < len){
                while(nums[i] == nums[i + 1])
                    i++;
            }
        }
        return result;
    }
};
