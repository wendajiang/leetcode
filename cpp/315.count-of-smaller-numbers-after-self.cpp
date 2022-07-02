/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.04%)
 * Likes:    5566
 * Dislikes: 159
 * Total Accepted:    228.1K
 * Total Submissions: 542.7K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// Binary Indexed Tree
struct BIT {
    int len;
    vector<int> tree;
    BIT(int size) {
        len = size;
        tree.resize(len + 1);
        fill(tree.begin(), tree.end(), 0);
    }

    void update_bit(int idx, int val) {
        idx++;  // 1 indexing
        while (idx <= len) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int get_sum(int idx) {
        idx++;
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
};
class Solution {
   public:
    //    // tle
    //     vector<int> countSmaller(vector<int>& nums) {
    //         vector<int> t, res(nums.size());

    //         for (int i = nums.size() - 1; i >= 0; i--) {
    //             auto d =
    //                 distance(t.begin(), lower_bound(t.begin(), t.end(),
    //                 nums[i]));
    //             res[i] = d;
    //             t.insert(t.begin() + d, nums[i]);
    //         }
    //         return res;
    //     }

    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        BIT bit(max_val - min_val + 1);

        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = bit.get_sum(nums[i] - 1 - min_val);
            bit.update_bit(nums[i] - min_val, 1);
        }
        return ans;
    }
};
// @lc code=end
