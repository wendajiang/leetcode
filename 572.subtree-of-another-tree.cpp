/*
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree
 *
 * Easy (40.68%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 *
 *
 * Example 1:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 *
 *
 * Example 2:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return false.
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

    // //naive thinking ,recursive solution
    // bool isSubtree(TreeNode* s, TreeNode* t) {
    //     if(!s) return false;
    //     if(isSame(s, t)) return true;
    //     return isSubtree(s->left, t) || isSubtree(s->right, t);
    // }
    // bool isSame(TreeNode* s, TreeNode* t){
    //     if(!s && !t) return true;
    //     if(!s || !t) return false;
    //     if(s->val != t->val) return false;
    //
    //     return isSame(s->left, t->left) && isSame(s->right, t->right);
    // }

//     /*
// The key idea is to serialize the tree into a string
// so that any subtree in that tree will be a consecutive substring.
// Then the problem turns into substring finding problem.
// Here is the non-recursive code in case the tree is quite deep (depth > 10000)
// to prevent stack overflow.
//     */
//
//     vector<int> preKMP(string substr) {
//         int m = substr.size();
//         vector<int> f(m);
//         int k;
//         f[0] = -1;
//         for (int i = 1; i < m; i++) {
//             k = f[i - 1];
//             while (k >= 0) {
//                 if (substr[k] == substr[i - 1])
//                     break;
//                 else
//                     k = f[k];
//             }
//             f[i] = k + 1;
//         }
//         return f;
//     }
//
//     bool KMP(string substr, string str) {
//         int m = substr.size();
//         int n = str.size();
//         vector<int> f;
//         f = preKMP(substr);
//         int i = 0;
//         int k = 0;
//         while (i < n) {
//             if (k == -1) {
//                 i++;
//                 k = 0;
//             }
//             else if (str[i] == substr[k]) {
//                 i++;
//                 k++;
//                 if (k == m) {
//                     return true;
//                 }
//             }
//             else {
//                 k = f[k];
//             }
//         }
//         return false;
//     }
//
//     string postOrderTraversal(TreeNode* root) {
//         string str;
//         stack<pair<TreeNode*, int>> s;
//         s.push(pair<TreeNode*, int>(root, 0));
//         while (!s.empty()) {
//             pair<TreeNode*, int> p = s.top();
//             TreeNode* node = p.first;
//             int idx = p.second;
//             if (node == NULL) {
//                 s.pop();
//                 continue;
//             }
//             if (idx == 0) {
//                 str.push_back('(');
//                 s.top().second++;
//                 s.push(pair<TreeNode*, int>(node->left, 0));
//             } else if (idx == 1) {
//                 s.top().second++;
//                 s.push(pair<TreeNode*, int>(node->right, 0));
//             } else {
//                 str += to_string(node->val);
//                 str.push_back(')');
//                 s.pop();
//             }
//         }
//         return str;
//     }
//
//     bool isSubtree(TreeNode* s, TreeNode* t) {
//         string post_t = postOrderTraversal(t);
//         string post_s = postOrderTraversal(s);
//         //int pos = post_s.find(post_t);
//         //return (pos != string::npos);
//         return KMP(post_t, post_s);
//     }


    /*
Two trees are identical when they are recursively identical.
Brute force solution would be recursively compare each node in s with t to check for identical.
Better solution is to only compare nodes in s with the same max depth as t.
First get max depth of t, then recursively check each node in s,
if depth equals, push to a vector. Then compare each node in the vector with t.
    */
    vector<TreeNode*> nodes;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;

        getDepth(s, getDepth(t, -1));

        for (TreeNode* n: nodes)
            if (identical(n, t))
                return true;

        return false;
    }

    int getDepth(TreeNode* r, int d) {
        if (!r)
            return -1;

        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

        // Check if depth equals required value
        // Require depth is -1 for tree t (only return the depth, no push)
        if (depth == d)
            nodes.push_back(r);

        return depth;
    }

    bool identical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
    }
};
