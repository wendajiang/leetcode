/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    9729
 * Dislikes: 384
 * Total Accepted:    839K
 * Total Submissions: 2.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (_mp.find(key) == _mp.end()) {
            return -1;
        }
        MoveToHead(key);
        return _mp[key]->value;
    }

    void put(int key, int value) {
        if (_mp.find(key) == _mp.end()) {
            Item item(key, value);
            if (_lru_list.size() >= _capacity) {
                _mp.erase(_lru_list.back().key);
                _lru_list.pop_back();
            }
            _lru_list.push_front(item);
            _mp[key] = _lru_list.begin();
            return;
        } else {
            _mp[key]->value = value;
            MoveToHead(key);
        }
    }
private:
    typedef struct Item {
        int key;
        int value;
        Item(int _k, int _v): key(_k), value(_v) {}
    }Item;
    list<Item> _lru_list;
    unordered_map<int, list<Item>::iterator> _mp;
    int _capacity;
    void MoveToHead(int key) {
        auto update_item = *_mp[key];
        _lru_list.erase(_mp[key]);
        _lru_list.push_front(update_item);
        _mp[key] = _lru_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
