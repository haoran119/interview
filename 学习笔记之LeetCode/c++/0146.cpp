/*
https://leetcode.com/problems/lru-cache/description/
https://www.geeksforgeeks.org/lru-cache-implementation/

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
    If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 
Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.

*/
class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        if (!m_keys.count(key)) {
            return -1;
        }

        // need to store value before iterator invalidation
        auto v = m_keys.at(key)->second;
        m_cache.erase(m_keys.at(key));
        m_cache.emplace_back(key, v);
        m_keys[key] = std::prev(m_cache.end());

        return m_keys.at(key)->second;
    }
    
    void put(int key, int value) {
        if (m_capacity <= 0) {
            return;
        }

        if (auto it = m_keys.find(key); it != m_keys.end()) {
            m_cache.erase(it->second);
        }
        else {
            if (m_cache.size() == m_capacity) {            
                m_keys.erase(m_cache.front().first);
                m_cache.pop_front();
            }
        }

        m_cache.emplace_back(key, value);
        m_keys[key] = std::prev(m_cache.end());
    }

private:
    int m_capacity;
    // key : value
    // use list rather than deque due to O(1) in erase()
    std::list<std::pair<int, int> >   m_cache;
    // key : iterator of m_cache
    std::unordered_map<int, std::list<std::pair<int, int> >::iterator>    m_keys;    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
