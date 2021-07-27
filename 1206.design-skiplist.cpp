/*
 * @lc app=leetcode id=1206 lang=cpp
 *
 * [1206] Design Skiplist
 *
 * https://leetcode.com/problems/design-skiplist/description/
 *
 * algorithms
 * Hard (58.67%)
 * Likes:    226
 * Dislikes: 25
 * Total Accepted:    7K
 * Total Submissions: 11.9K
 * Testcase Example:
 '["Skiplist","add","add","add","search","add","search","erase","erase","search"]\r\n'
 +
  '[[],[1],[2],[3],[0],[4],[1],[0],[1],[1]]\r'
 *
 * Design a Skiplist without using any built-in libraries.
 *
 * A Skiplist is a data structure that takes O(log(n)) time to add, erase and
 * search. Comparing with treap and red-black tree which has the same function
 * and performance, the code length of Skiplist can be comparatively short and
 * the idea behind Skiplists are just simple linked lists.
 *
 * For example: we have a Skiplist containing [30,40,50,60,70,90] and we want
 * to add 80 and 45 into it. The Skiplist works this way:
 *
 *
 * Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
 *
 * You can see there are many layers in the Skiplist. Each layer is a sorted
 * linked list. With the help of the top layers, add , erase and search can be
 * faster than O(n). It can be proven that the average time complexity for each
 * operation is O(log(n)) and space complexity is O(n).
 *
 * To be specific, your design should include these functions:
 *
 *
 * bool search(int target) : Return whether the target exists in the Skiplist
 * or not.
 * void add(int num): Insert a value into the SkipList. 
 * bool erase(int num): Remove a value in the Skiplist. If num does not exist
 * in the Skiplist, do nothing and return false. If there exists multiple num
 * values, removing any one of them is fine.
 *
 *
 * See more about Skiplist : https://en.wikipedia.org/wiki/Skip_list
 *
 * Note that duplicates may exist in the Skiplist, your code needs to handle
 * this situation.
 *
 *
 *
 * Example:
 *
 *
 * Skiplist skiplist = new Skiplist();
 *
 * skiplist.add(1);
 * skiplist.add(2);
 * skiplist.add(3);
 * skiplist.search(0);   // return false.
 * skiplist.add(4);
 * skiplist.search(1);   // return true.
 * skiplist.erase(0);    // return false, 0 is not in skiplist.
 * skiplist.erase(1);    // return true.
 * skiplist.search(1);   // return false, 1 has already been erased.
 *
 *
 * Constraints:
 *
 *
 * 0 <= num, target <= 20000
 * At most 50000 calls will be made to search, add, and erase.
 *
 */
#include <bits/stdc++.h>
using namespace std;
// https://leetcode-cn.com/problems/design-skiplist/solution/can-kao-redisshi-xian-by-bakezq/

// @lc code=start
static const int kMaxLevel = 16;
static const int kSkipList_P_Val = RAND_MAX / 2;

class Skiplist
{
public:
   struct Node
   {
      int val;
      vector<Node *> level;
      Node(int val, int size = kMaxLevel) : val(val), level(size) {}
   }; 

   Skiplist(): head(INT_MIN, kMaxLevel) {}

   bool search(int target) {
      Node *prev = _search(target)[0];
      return prev->level[0] && prev->level[0]->val == target;
   }

   vector<Node *> _search(int key) {
      Node *cur = &head;
      vector<Node* > prevs(kMaxLevel);
      for (int i = max_level - 1; i >= 0; i--) {
         while(cur->level[i] && cur->level[i]->val < key)
            cur = cur->level[i];
         prevs[i] = cur;
      }
      return prevs;
   }

   void add(int num) {
      auto prevs = _search(num);
        int level = random_level();
        // update max_level and prevs
        if (level > max_level) {
            for (int i = max_level; i < level; i++)
                prevs[i] = &head;
            max_level = level;
        }
        Node * cur = new Node(num, level);
        // from prev->next   to   prev->cur->next
        for (int i = level - 1; i >= 0; i--) {
            cur->level[i] = prevs[i]->level[i];
            prevs[i]->level[i] = cur;
        }
        // if there is backward pointer, need to set both cur and cur.next 's back pointer
        // Note that the back poinet of the first valid node is nullptr instead of head
   }

   bool erase(int num) {
      auto prevs = _search(num);
        if (!prevs[0]->level[0] || prevs[0]->level[0]->val != num)
            return false;
        Node * del = prevs[0]->level[0];
        // from prev->cur->next to prev->next
        for (int i = 0; i < max_level; i++)
            if (prevs[i]->level[i] == del)
                prevs[i]->level[i] = del->level[i];
        delete del;
        // update max_level.
        while (max_level > 1 && !head.level[max_level - 1])
            max_level--;
        // if there is backward poinet, need to set cur.next.back to cur.back
        return true;

   }

   static int random_level() {
      int level = 1;
      while(rand() < kSkipList_P_Val && level < kMaxLevel) level ++;
      return level;
   }
   Node head;
   int max_level = 1;

private:
 
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end
