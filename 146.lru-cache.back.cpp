/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache
 *
 * Hard (17.34%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:

    struct CacheEntry{
    public:
        int key;
        int value;
        CacheEntry(int k, int v):key(k), value(v){}
    };

    LRUCache(int capacity) {
        m_capacity = capacity;        
    }
    
    int get(int key) {
        if(m_map.find(key) == m_map.end())
            return -1;
        MoveToHead(key);
        return m_map[key]->value;
    }
    
    void put(int key, int value) {
        if(m_map.find(key) == m_map.end()){
            CacheEntry newItem(key, value);
            if(m_LRU_cache.size() >= m_capacity){
                //remove from tail
                m_map.erase(m_LRU_cache.back(). key);
                m_LRU_cache.pop_back();
            }
            //insert in the head
            m_LRU_cache.push_front(newItem);
            m_map[key] = m_LRU_cache.begin();
            return ;
        }
        m_map[key]->value = value;
        MoveToHead(key);
    }
private:
    unordered_map<int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    int m_capacity;
    void MoveToHead(int key){
        //Move key from current location to head
        auto updateEntry = *m_map[key];
        m_LRU_cache.erase(m_map[key]);
        m_LRU_cache.push_front(updateEntry);
        m_map[key] = m_LRU_cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
