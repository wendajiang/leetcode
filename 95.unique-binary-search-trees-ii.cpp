/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (32.30%)
 * Total Accepted:    101K
 * Total Submissions: 312.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return genTrees(1, n);
    }
    // 从start - end 构建出BST，返回BST
    vector<TreeNode*> genTrees(int start, int end){
        vector<TreeNode*> ret;
        if(end - start < 0) ret.push_back(nullptr);
        if(end - start == 0) ret.push_back(new TreeNode(start));
        if(end - start > 0){
            //以i为根节点
            for(int i = start; i <= end; i++){
                //递归求解所有左子树和右子树
                vector<TreeNode*> l = genTrees(start, i - 1);
                vector<TreeNode*> r = genTrees(i + 1, end);

                //左子树 * 右子树 ，加上根节点，构成一个start - end的BST
                //这里用两层循环实现了左右子树的组合
                for(int j = 0; j < l.size(); j ++){
                    for(int k = 0; k < r.size(); k++){
                        TreeNode* h = new TreeNode(i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }
};
