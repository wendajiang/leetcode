//Given a binary tree, imagine yourself standing on the right side of it, return
// the values of the nodes you can see ordered from top to bottom. 
//
// Example: 
//
// 
//Input: [1,2,3,null,5,null,4]
//Output: [1, 3, 4]
//Explanation:
//
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
// Related Topics Tree Depth-first Search Breadth-first Search 
// 👍 2192 👎 131

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        vector<int> res;
        int s = 0, e = nodes.size();
        while(s < e) {
            int tmp_e = e;
            for (int i = s; i < tmp_e; i++) {
                if (nodes[i]->left != nullptr) nodes.push_back(nodes[i]->left);
                if (nodes[i]->right != nullptr) nodes.push_back(nodes[i]->right);
                if (i == tmp_e - 1) res.push_back(nodes[i]->val);
            }
            s = tmp_e;
            e = nodes.size();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}