#include <bits/stdc++.h>

class MyHashSet {
private:
    vector<int> keys;
    
public:
    MyHashSet() {
    }
    
    void add(int key) {
        if(find(keys.begin(), keys.end(), key) == keys.end()) {
            keys.push_back(key);
        }
    }
    
    void remove(int key) {
        auto it = find(keys.begin(), keys.end(), key);
        if(it != keys.end()) {
            keys.erase(it);
        }
    }
    
    bool contains(int key) {
        return find(keys.begin(), keys.end(), key) != keys.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */