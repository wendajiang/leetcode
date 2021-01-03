/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (53.85%)
 * Likes:    592
 * Dislikes: 90
 * Total Accepted:    47.1K
 * Total Submissions: 87.4K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
  '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * Implement the MapSum class:
 * 
 * 
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key
 * starts with the prefix.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output
 * [null, null, 3, null, 5]
 * 
 * Explanation
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);    
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MapSum {
public:
    struct node {
        int ch[26];
        int val;
        node() {
            memset(ch, 0, sizeof(ch));
            val = 0;
        }
    };
    vector<node> tree;
    /** Initialize your data structure here. */
    MapSum() {
        tree.emplace_back(node());
    }
    
    void insert(string key, int val) {
        int add = 0;
        for (int i = 0; i < key.size(); i++) {
            int x = key[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back(node());
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].val = val;
    }
    
    int sum(string prefix) {
        int add = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int x = prefix[i] - 'a';
            if (!tree[add].ch[x]) return 0;
            add = tree[add].ch[x];
        }
        int sum = 0;
        sumCore(add, sum);
        return sum;
    }

    void sumCore(int add, int & sum) {
        if (tree[add].val) sum += tree[add].val;
        for (int i = 0; i < 26; i++) {
            if (tree[add].ch[i]) sumCore(tree[add].ch[i], sum);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

