/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    2273
 * Dislikes: 125
 * Total Accepted:    160.2K
 * Total Submissions: 421.7K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, handle multiple queries of the following
 * types:
 *
 *
 * Update the value of an element in nums.
 * Calculate the sum of the elements of nums between indices left and right
 * inclusive where left <= right.
 *
 *
 * Implement the NumArray class:
 *
 *
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be
 * val.
 * int sumRange(int left, int right) Returns the sum of the elements of nums
 * between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +
 * ... + nums[right]).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 *
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1, 2, 5]
 * numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 10^4 calls will be made to update and sumRange.
 *
 *
 */
// https://en.wikipedia.org/wiki/Fenwick_tree
// https://oi-wiki.org/ds/fenwick/
// https://oi-wiki.org/ds/seg/
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
   public:
    NumArray(vector<int>& nums) {
        origin_nums = nums;
        f_tree.init(nums);
    }

    void update(int index, int val) {
        int delta = val - origin_nums[index];
        origin_nums[index] = val;
        f_tree.add(index + 1, delta);
    }

    int sumRange(int left, int right) {
        int r = f_tree.getSum(right + 1);
        int l = f_tree.getSum(left);
        return r - l;
    }

   private:
    class FenwickTree {
       public:
        FenwickTree() {}
        void init(vector<int>& nums) {
            bits.resize(nums.size() + 1);
            for (int i = 1; i <= nums.size(); i++) {
                bits[i] += nums[i - 1];
                int j = i + lowbit(i);
                if (j <= nums.size()) bits[j] += bits[i];
            }
        }

        int getSum(int k) {
            int ans = 0;
            while (k) {
                ans += bits[k];
                k = k - lowbit(k);
            }
            return ans;
        }

        void add(int index, int delta) {
            while (index < bits.size()) {
                bits[index] += delta;
                index = index + lowbit(index);
            }
        }

        int rangeSum(int l, int r) {
            int sum = 0;
            for (; r > l; r -= lowbit(r)) sum += bits[r];
            for (; l > r; l -= lowbit(l)) sum -= bits[l];
            return sum;
        }

        int get(int index) { return rangeSum(index, index + 1); }

        void set(int index, int val) { add(index, val - get(index)); }

       private:
        vector<int> bits;
        int lowbit(int x) { return (x & (-x)); }
    };

    FenwickTree f_tree;
    vector<int> origin_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
