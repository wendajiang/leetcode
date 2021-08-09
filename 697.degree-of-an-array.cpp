/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (54.35%)
 * Likes:    1506
 * Dislikes: 1039
 * Total Accepted:    119.5K
 * Total Submissions: 217.6K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2,3,1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 * Explanation:
 * The degree is 3 because the element 2 is repeated 3 times.
 * So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, pair<int, int>> mmp;
        for (size_t i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mmp.find(nums[i]) == mmp.end()) {
                mmp[nums[i]] = make_pair(i, i);
            } else {
                mmp[nums[i]].second = i;
            }
        }
        int degree = 0;
        for (auto &p : mp) {
            degree = max(degree, p.second);
        }
        int ret = numeric_limits<int>::max();
        for (auto &p : mp) {
            if (p.second == degree) {
                ret = min(ret, mmp[p.first].second - mmp[p.first].first + 1);
            }
        }
        return ret;
    }
};
// @lc code=end
