/*
 * @lc app=leetcode id=235 lang=rust
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.04%)
 * Likes:    4371
 * Dislikes: 159
 * Total Accepted:    624.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
 *
 *
 */
// use rustgym_util::*;
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
// @lc code=start
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn lowest_common_ancestor(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let p_val = p.unwrap().borrow().val;
        let q_val = q.unwrap().borrow().val;
        while let Some(node) = root.clone() {
            let mut node = node.borrow_mut();
            let val = node.val;
            if val > p_val && val > q_val {
                root = node.left.take();
                continue;
            }
            if val < p_val && val < q_val {
                root = node.right.take();
                continue;
            }
            node.left.take();
            node.right.take();
            break;
        }
        root
    }
}
// @lc code=end
struct Solution;

pub type TreeLink = Option<Rc<RefCell<TreeNode>>>;

#[macro_export]
macro_rules! tree_node {
    ($e:expr) => {
        TreeLink::leaf($e)
    };
    ($e:expr, $l:expr, $r:expr) => {
        TreeLink::branch($e, $l, $r)
    };
}

pub trait TreeMaker {
    fn branch(val: i32, left: TreeLink, right: TreeLink) -> TreeLink {
        Some(Rc::new(RefCell::new(TreeNode { val, left, right })))
    }
    fn leaf(val: i32) -> TreeLink {
        Some(Rc::new(RefCell::new(TreeNode {
            val,
            left: None,
            right: None,
        })))
    }
}

impl TreeMaker for TreeLink {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let root = tree_node!(
            6,
            tree_node!(
                2,
                tree_node!(0),
                tree_node!(4, tree_node!(3), tree_node!(5))
            ),
            tree_node!(8, tree_node!(7), tree_node!(9))
        );
        let p = tree_node!(2);
        let q = tree_node!(8);
        let res = tree_node!(6);
        assert_eq!(Solution::lowest_common_ancestor(root, p, q), res);
        let root = tree_node!(
            6,
            tree_node!(
                2,
                tree_node!(0),
                tree_node!(4, tree_node!(3), tree_node!(5))
            ),
            tree_node!(8, tree_node!(7), tree_node!(9))
        );
        let p = tree_node!(2);
        let q = tree_node!(4);
        let res = tree_node!(2);
        assert_eq!(Solution::lowest_common_ancestor(root, p, q), res);
        let root = tree_node!(2, tree_node!(1), None);
        let p = tree_node!(2);
        let q = tree_node!(1);
        let res = tree_node!(2);
        assert_eq!(Solution::lowest_common_ancestor(root, p, q), res);
    }
}
