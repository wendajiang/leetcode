/**
 * @lc app=leetcode id=1 lang=cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mapping;

        for (int i = 0; i < nums.size(); i++) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int searched = target - nums[i];
            if (mapping.find(searched) != mapping.end() &&
                i != mapping[searched]) {
                result.push_back(i);
                result.push_back(mapping[searched]);
                break;
            }
        }
        return result;
    }
};
// @lc code=end
