/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (37.74%)
 * Likes:    2385
 * Dislikes: 167
 * Total Accepted:    122K
 * Total Submissions: 323.1K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for a Least Frequently Used (LFU)
 * cache.
 *
 * Implement the LFUCache class:
 *
 *
 * LFUCache(int capacity) Initializes the object with the capacity of the data
 * structure.
 * int get(int key) Gets the value of the key if the key exists in the cache.
 * Otherwise, returns -1.
 * void put(int key, int value) Update the value of the key if present, or
 * inserts the key if not already present. When the cache reaches its capacity,
 * it should invalidate and remove the least frequently used key before
 * inserting a new item. For this problem, when there is a tie (i.e., two or
 * more keys with the same frequency), the least recently used key would be
 * invalidated.
 *
 *
 * To determine the least frequently used key, a use counter is maintained for
 * each key in the cache. The key with the smallest use counter is the least
 * frequently used key.
 *
 * When a key is first inserted into the cache, its use counter is set to 1
 * (due to the put operation). The use counter for a key in the cache is
 * incremented either a get or put operation is called on it.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 * Explanation
 * // cnt(x) = the use counter for key x
 * // cache=[] will show the last used order for tiebreakers (leftmost element
 * is  most recent)
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // return 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
 * invalidate 2.
 * // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate
 * 1.
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // return 4
 * ⁠                // cache=[3,4], cnt(4)=2, cnt(3)=3
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 *
 *
 */

// @lc code=start
class LFUCache {
public:
    LFUCache(int cap) {
        capacity = cap;
        time = 0;
        mp_index.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = mp_index.find(key);
        if (it == mp_index.end()) return -1;
        Node cache = it->second;
        S.erase(cache);
        cache.cnt += 1;
        cache.time = ++time;
        S.insert(cache);
        it->second = cache;
        return cache.val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = mp_index.find(key);
        if (it == mp_index.end()) {
            if (mp_index.size() == capacity) {
                mp_index.erase(S.begin()->key);
                S.erase(S.begin());
            }
            Node cache{key, value, ++time, 1};
            mp_index.insert(make_pair(key, cache));
            S.insert(cache);
        } else {
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.val = value;
            S.insert(cache);
            it->second = cache;
        }
    }

private:
    struct Node {
        int key, val, time, cnt;
        Node(int k, int v, int t, int c): key(k), val(v), time(t), cnt(c) {}

        bool operator < (const Node &rhs) const {
            return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
        }
    };
    int capacity, time;
    unordered_map<int, Node> mp_index;
    set<Node> S;
};

// class LFUCache {
// public:
    // LFUCache(int capacity) {
        // this->capacity = capacity;
        // min_freq = 0;
        // mp_index.clear();
        // mp_container.clear();
    // }

    // int get(int key) {
        // if (capacity == 0) return -1;
        // auto it = mp_index.find(key);
        // if (it == mp_index.end()) return -1;
        // list<Node>::iterator node = it->second;
        // int val = node->value, cnt = node->cnt;
        // mp_container[cnt].erase(node);
        // if (mp_container[cnt].size() == 0) {
            // mp_container.erase(cnt);
            // if (min_freq == cnt) min_freq += 1;
        // }
        // mp_container[cnt + 1].push_front(Node(key, val, cnt + 1));
        // mp_index[key] = mp_container[cnt + 1].begin();
        // return val;

    // }

    // void put(int key, int value) {
        // if (capacity == 0) return;
        // auto it = mp_index.find(key);
        // if (it == mp_index.end()) {
            // if (mp_index.size() == capacity) {
                // auto it2 = mp_container[min_freq].back();
                // mp_index.erase(it2.key);
                // mp_container[min_freq].pop_back();
                // if (mp_container[min_freq].size() == 0) {
                    // mp_container.erase(min_freq);
                // }
            // }
            // mp_container[1].push_front(Node(key, value, 1));
            // mp_index[key] = mp_container[1].begin();
            // min_freq = 1;

        // } else {
            // list<Node>::iterator node = it->second;
            // int cnt = node->cnt;
            // mp_container[cnt].erase(node);
            // if (mp_container[cnt].size() == 0) {
                // mp_container.erase(cnt);
                // if (min_freq == cnt) min_freq += 1;
            // }
            // mp_container[cnt + 1].push_front(Node(key, value, cnt + 1));
            // mp_index[key] = mp_container[cnt + 1].begin();
        // }
    // }
// private:
    // struct Node {
        // int key, value, cnt;
        // Node(int k, int v, int c) :key(k), value(v), cnt(c) {}
    // };
    // int capacity;
    // unordered_map<int, list<Node>> mp_container;
    // unordered_map<int, list<Node>::iterator> mp_index;
    // int min_freq;
// };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
