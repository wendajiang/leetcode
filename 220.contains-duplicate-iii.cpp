/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii
 *
 * Medium (19.11%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n0\n0'
 *
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 *
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long)nums[i] - (long)t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && std::abs(*pos - nums[i]) <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
