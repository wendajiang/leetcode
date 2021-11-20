/*
 * @lc app=leetcode id=1026 lang=rust
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (70.76%)
 * Likes:    1559
 * Dislikes: 46
 * Total Accepted:    96.3K
 * Total Submissions: 136.1K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value v for which there
 * exist different nodes a and b where v = |a.val - b.val| and a is an ancestor
 * of b.
 * 
 * A node a is an ancestor of b if either: any child of a is equal to b or any
 * child of a is an ancestor of b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: We have various ancestor-node differences, some of which are
 * given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,null,0,3]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5000].
 * 0 <= Node.val <= 10^5
 * 
 * 
 */
use rustgym_util::*;
// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

trait Preorder {
    fn preorder(&self, parent: Option<(i32, i32)>, abs: &mut i32);
}

impl Preorder for Option<Rc<RefCell<TreeNode>>> {
    fn preorder(&self, mut parent: Option<(i32, i32)>, abs: &mut i32) {
        if let Some(node) = self {
            let val = node.borrow().val;
            let left = &node.borrow().left;
            let right = &node.borrow().right;
            parent = if let Some((min, max)) = parent { 
                *abs = (*abs).max((min - val).abs().max((max - val).abs()));
                Some((min.min(val), max.max(val)))
            } else { 
                Some((val, val))
            };
            left.preorder(parent, abs);
            right.preorder(parent, abs);
        }
    }
}

impl Solution {
    pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0;
        root.preorder(None, &mut res);
        res
    }
}
// @lc code=end
struct Solution;

#[cfg(test)]
#[test]
fn test_max_ancestor_diff() {
    let root = tree!(
        8,
        tree!(3, tree!(1), tree!(6, tree!(4), tree!(7))),
        tree!(10, None, tree!(14, tree!(13), None))
    );
    assert_eq!(Solution::max_ancestor_diff(root), 7);
}