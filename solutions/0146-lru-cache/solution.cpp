#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<int> dll;  // Doubly linked list to store keys
    unordered_map<int, pair<list<int>::iterator, int>> mp;  // key -> {iterator in list, value}

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void moveToFront(int key) {
        dll.erase(mp[key].first);           // Remove current position
        dll.push_front(key);                // Move to front
        mp[key].first = dll.begin();        // Update iterator
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            moveToFront(key);
            return mp[key].second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;         // Update value
            moveToFront(key);               // Move key to front
        } else {
            if (dll.size() == capacity) {
                int lruKey = dll.back();    // Least recently used key
                dll.pop_back();             // Remove from list
                mp.erase(lruKey);           // Remove from map
            }
            dll.push_front(key);            // Insert at front
            mp[key] = {dll.begin(), value}; // Add to map
        }
    }
};

