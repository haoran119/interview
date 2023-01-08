/*
https://leetcode.com/problems/lfu-cache/description/
https://leetcode.com/problems/lfu-cache/solutions/2815229/lfu-cache/
https://www.geeksforgeeks.org/least-frequently-used-lfu-cache-implementation/?ref=lbp

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:
    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
    When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. 
    For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is 
the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is 
incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 
Constraints:
    0 <= capacity <= 104
    0 <= key <= 105
    0 <= value <= 109
    At most 2 * 105 calls will be made to get and put.

Time: O(1)
Space: O(k), k is the capacity of cache
*/

class LFUCache {
public:
    LFUCache(int capacity) : m_capacity(capacity), m_min_frequency(0) {}
    
    int get(int key) {
        if (!m_cache.count(key)) {
            return -1;
        }

        // note that should not use auto& as m_cache.at(key) will be erased later
        const auto [k, v, f] = *(m_cache.at(key));  
        m_frequencies.at(f).erase(m_cache.at(key));

        if (m_frequencies.at(f).empty() && m_min_frequency == f) {
            ++ m_min_frequency;
        }

        insert(k, v, f + 1);        

        return v;
    }
    
    void put(int key, int value) {
        if (m_capacity <= 0) {
            return;
        }

        if (auto it = m_cache.find(key); it != m_cache.end()) {
            std::get<1>(*(it->second)) = value;
            get(key);   // tricky to reuse get() here
            return;
        }

        if (m_cache.size() == m_capacity) {
            // pop the lease recent from the front
            m_cache.erase(std::get<0>(m_frequencies.at(m_min_frequency).front()));
            m_frequencies.at(m_min_frequency).pop_front();            
        }

        m_min_frequency = 1;    // set m_min_frequency here
        insert(key, value, 1);        
    }

private:
    int m_capacity;
    int m_min_frequency;
    // frequency : { {key, value, frequency} ... }
    std::unordered_map<int, std::list<std::tuple<int, int, int> > > m_frequencies;    
    // key : iterator of { {key, value, frequency} ... }
    std::unordered_map<int, std::list<std::tuple<int, int, int> >::iterator> m_cache;

    void insert(int key, int value, int frequency)
    {
        // push the most recent to the back
        m_frequencies[frequency].emplace_back(key, value, frequency);
        m_cache[key] = std::prev(m_frequencies.at(frequency).end());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
