/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii
 *
 * Easy (39.81%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    // //straight forward Solution
    // //check every node if there is a path sum matching the target
    // //but the solution is time slow
    // int pathSum(TreeNode* root, int sum) {
    //     int count = 0;
    //     inorder(root, count, sum);
    //     return count;
    // }
    // void inorder(TreeNode* node, int &count, int target){
    //     if(!node) return ;
    //     inorder(node->left, count, target);
    //     dfs(node, count, 0, target);
    //     inorder(node->right, count, target);
    // }
    // void dfs(TreeNode* node, int& count, int sum, int target){
    //     if(!node) return;
    //     sum = sum + node->val;
    //     if(sum == target) count++;
    //     dfs(node->left, count, sum, target);
    //     dfs(node->right, count, sum, target);
    // }

    // //concise solution but the time is slow
    // int pathSum(TreeNode* root, int sum) {
    //     if(!root) return 0;
    //     return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    // }
    // int sumUp(TreeNode* root, int pre, int& sum){
    //     if(!root) return 0;
    //     int current = pre + root->val;
    //     return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    // }

/*the same idea of Two Sum,using HashMap to store
( key : the prefix sum, value : how many ways get to this prefix sum),
and whenever reach a node,
we check if prefix sum - target exists in hashmap or not,
if it does, we added up the ways of prefix sum - target into res.
*/

    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        unordered_map<int, int> prev_sums;
        prev_sums[0] = 1;
        dfs(root, prev_sums, 0, res, sum);
        return res;
    }

    void dfs(TreeNode* root, unordered_map<int, int> &prev_sums, int cur_sum, int &res, int sum){
        if(root == NULL) return;
        cur_sum += root->val;
        if(prev_sums.find(cur_sum - sum) != prev_sums.end()){
            res += prev_sums[cur_sum - sum];
        }
        prev_sums[cur_sum]++;
        dfs(root->left, prev_sums, cur_sum, res, sum);
        dfs(root->right, prev_sums, cur_sum, res, sum);
        prev_sums[cur_sum]--;
    }
};
