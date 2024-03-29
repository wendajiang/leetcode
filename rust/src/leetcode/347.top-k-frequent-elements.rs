/*
 * @lc app=leetcode id=347 lang=rust
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.78%)
 * Likes:    6544
 * Dislikes: 308
 * Total Accepted:    726K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

// @lc code=start

use std::collections::BinaryHeap;
use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ump = HashMap::new();
        for num in nums {
            let counter = ump.entry(num).or_insert(0);
            *counter += 1;
        }
        let mut sort_q = BinaryHeap::new();
        for (k, v) in ump {
            sort_q.push((v, k));
        }

        let mut res = Vec::new();
        for _ in 0..k {
            res.push(sort_q.pop().unwrap().1);
        }
        res
    }
}
// @lc code=end


struct Solution;


#[cfg(test)]
#[test]
fn test_() {
    todo!()
}
