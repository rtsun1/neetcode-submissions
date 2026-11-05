// using itr_t = list<int>::iterator

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto itr = table.find(key);
        if (itr != table.end()) {
            use_key(key);

            return itr->second.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = table.find(key);
        if (itr != table.end()) {
            use_key(key);
            itr->second.second = value;
            return;
        }
        if (table.size() == capacity) {
            int key = last_used.front();
            last_used.pop_front();
            table.erase(key);
        }
        last_used.push_back(key);
        table[key] = {prev(last_used.end()), value};
    }

private:
    unordered_map<int, pair<list<int>::iterator, int>> table; // key: (itr, value)
    int capacity;
    list<int> last_used;
    
    void use_key(int key) {
        last_used.erase(table[key].first);
        last_used.push_back(key);
        table[key].first = prev(last_used.end());
    }
};


using index_itr_t = list<int>::iterator;
using use_itr_t = list<pair<int, list<int>>>::iterator;

// whoops this is an LFU cache
class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity) {
        uses.push_front({0, list<int>()});
    }
    
    int get(int key) {
        auto itr = table.find(key);
        if (itr != table.end()) {
            use_key(itr->second.first);

            return itr->second.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = table.find(key);
        if (itr != table.end()) {
            use_key(itr->second.first);
            itr->second.second = value;
            return;
        }
        if (table.size() == capacity) {
            list<int>& keys = uses.front().second;
            table.erase(keys.front());
            keys.pop_front();
            if (keys.empty()) {
                uses.pop_front();
            }
        }
        if (uses.empty() || uses.front().first != 0) {
            uses.push_front({0, {}});
        }
        list<int>& zero_keys = uses.front().second;
        zero_keys.push_back(key);
        table[key] = {{uses.begin(), prev(zero_keys.end())}, value}; 
    }

private:
    unordered_map<int, pair<pair<use_itr_t, index_itr_t>, int>> table; // key: (use, index, value)
    int capacity;
    list<pair<int, list<int>>> uses;
    
    void use_key(pair<use_itr_t, index_itr_t> use_info) {
        auto [use, index] = use_info;

        int key = *index;
        int count = use->first;
        auto next_use = next(use);

        use->second.erase(index);
        if (use->second.empty()) {
            uses.erase(use);
        }

        if (next_use == uses.end() || count + 1 != next_use->first) {
            next_use = uses.insert(next_use, {count + 1, {key}});
        } else {
            next_use->second.push_back(key);
        }
        table[key].first = {
            next_use,
            prev(next_use->second.end())
        };
    }
};
