/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (53.37%)
 * Likes:    8
 * Dislikes: 14
 * Total Accepted:    147.2K
 * Total Submissions: 275.7K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Given an integer array nums, design an algorithm to randomly shuffle the
 * array.
 * 
 * Implement the Solution class:
 * 
 * 
 * Solution(int[] nums) Initializes the object with the integer array nums.
 * int[] reset() Resets the array to its original configuration and returns
 * it.
 * int[] shuffle() Returns a random shuffling of the array.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["Solution", "shuffle", "reset", "shuffle"]
 * [[[1, 2, 3]], [], [], []]
 * Output
 * [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
 * 
 * Explanation
 * Solution solution = new Solution([1, 2, 3]);
 * solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
 * Any permutation of [1,2,3] must be equally likely to be returned. Example:
 * return [3, 1, 2]
 * solution.reset();      // Resets the array back to its original
 * configuration [1,2,3]. Return [1, 2, 3]
 * solution.shuffle();    // Returns the random shuffling of array [1,2,3].
 * Example: return [1, 3, 2]
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^6 <= nums[i] <= 10^6
 * All the elements of nums are unique.
 * At most 5 * 10^4 calls will be made to reset and shuffle.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> toshuffle = nums_;
        for (int i = toshuffle.size() - 1; i >= 0; i--) {
            int rand_j = rand() % (i + 1);
            swap(toshuffle[i], toshuffle[rand_j]);
        }
        return toshuffle;
    }

private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

