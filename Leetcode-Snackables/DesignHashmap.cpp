// Problem
// Design a HashMap without using built-in hash table libraries.

// Approach
// Use a fixed-size array to directly map keys to values.

// Initialize array with -1 (indicates no value)
// put(key, value): store value at index = key
// get(key): return value at index
// remove(key): reset value to -1

// Complexity

// Time: O(1) for all operations
// Space: O(10^6)

// Key Insight
// Direct addressing gives constant time operations but uses more memory.

class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        memset(data,-1,sizeof(data));
    }
    
    void put(int key, int value) {
        data[key]=value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
