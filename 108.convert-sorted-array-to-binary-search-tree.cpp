/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *
 * Easy (41.92%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        if(start == end) return new TreeNode(nums[start]);
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBSTCore(nums, start, mid - 1);
        node->right = sortedArrayToBSTCore(nums, mid + 1, end);
        return node;
    }
};
