/*
 * @lc app=leetcode id=236 lang=rust
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (52.86%)
 * Likes:    7775
 * Dislikes: 233
 * Total Accepted:    818.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
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
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
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
 * p and q will exist in the tree.
 *
 *
 */
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
pub type TreeLink = Option<Rc<RefCell<TreeNode>>>;
trait Preorder {
    fn preorder(&self, p: i32, q: i32, lca: &mut TreeLink) -> (bool, bool);
}

impl Preorder for TreeLink {
    fn preorder(&self, p: i32, q: i32, lca: &mut TreeLink) -> (bool, bool) {
        if let Some(node) = self {
            let node = node.borrow();
            let l = node.left.preorder(p, q, lca);
            let r = node.right.preorder(p, q, lca);
            let res = (l.0 || r.0 || node.val == p, l.1 || r.1 || node.val == q);
            if lca.is_none() && res.0 && res.1 {
                *lca = Some(Rc::new(RefCell::new(TreeNode::new(node.val))));
            }
            res
        } else { 
            (false, false)
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let p_val = p.as_ref().unwrap().borrow().val;
        let q_val = q.as_ref().unwrap().borrow().val;
        let mut res = None;
        root.preorder(p_val, q_val , &mut res); 
        res
    }
}
// @lc code=end

struct Solution;




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
#[test]
fn test_236() {

    macro_rules! tree_node {
        ($e:expr) => {
            TreeLink::leaf($e)
        };
        ($e:expr, $l:expr, $r:expr) => {
            TreeLink::branch($e, $l, $r)
        };
    }
    // [3,5,1,6,2,0,8,null,null,7,4]
    let root = tree_node!(
        3,
        tree_node!(5, tree_node!(6), tree_node!(2, tree_node!(7), tree_node!(4))),
        tree_node!(1, tree_node!(0), tree_node!(8))
    );
    let p = tree_node!(5);
    let q = tree_node!(1);
    let res = tree_node!(3);
    assert_eq!(Solution::lowest_common_ancestor(root, p, q), res);
    let root = tree_node!(
        6,
        tree_node!(2, tree_node!(0), tree_node!(4, tree_node!(3), tree_node!(5))),
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

