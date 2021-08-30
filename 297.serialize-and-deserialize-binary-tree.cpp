/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (51.58%)
 * Likes:    4947
 * Dislikes: 216
 * Total Accepted:    489.1K
 * Total Submissions: 948.3K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // bfs method
    string serialize(TreeNode *root) {
        if (!root) return "";
        string out = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) out.append("#,");
            else out.append(to_string(cur->val) + ",");
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return out;
    }

    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream check(data);
        string str;
        vector<string> vec;
        while(getline(check, str, ',')) {
            vec.push_back(str);
        }


        int k = 0, n = vec.size();
        TreeNode *root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            int i = k + 1, j = k + 2;
            if (i < n && vec[i] != "#") {
                cur->left = new TreeNode(stoi(vec[i]));
                q.push(cur->left);
            }
            if (j < n && vec[j] != "#") {
                cur->right = new TreeNode(stoi(vec[j]));
                q.push(cur->right);
            }
            k+= 2;
        }
        return root;
    }

    // origin method, inspired by leetcode.1028
    // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
        // if (!root) return "";
        // string out;
        // dfs(root, 0, out);
        // return out;
    // }

    // // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
        // if (data.empty()) return nullptr;
        // int i = 0, level = 0, val = 0, N = data.size();
        // vector<TreeNode*> st;
        // while(i < N) {
            // for (level = 0; i < N && data[i] == '&'; i++) {
                // level ++;
            // }
            // int sign = 0;
            // if (data[i] == '+') {
                // sign = 1;
                // i++;
            // } else if (data[i] == '-') {
                // sign = -1;
                // i++;
            // }
            // for (val = 0; i < N && isdigit(data[i]); i++) {
                // val = val * 10 + (data[i] - '0');
            // }
            // val *= sign;
            // TreeNode *node = new TreeNode(val);
            // while(st.size() > level) st.pop_back();
            // if (!st.empty()) {
                // if (!st.back()->left) st.back()->left = node;
                // else st.back()->right = node;
            // }
            // st.push_back(node);
        // }
        // dfsClear(st[0]);
        // return st[0];
    // }

// private:
    // void dfs(TreeNode *node, int level, string &out) {
        // for (int i = 0; i < level; i++) {
            // out += "&";
        // }
        // if (!node) {
            // out +=  ("+" + std::to_string(2000));
            // return;
        // } else {
            // if (node->val >= 0) {
                // out += "+";
            // }
            // out += std::to_string(node->val);
        // }
        // dfs(node->left, level + 1, out);
        // dfs(node->right, level + 1, out);
    // }
    // void dfsClear(TreeNode *&node) {
        // if (!node->left && !node->right && node->val == 2000) {
            // node = nullptr;
            // return;
        // }
        // if (node->left) dfsClear(node->left);
        // if (node->right) dfsClear(node->right);
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
