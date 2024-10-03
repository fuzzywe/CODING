Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"



class TimeMap {
public:
    
    // declare a map
    
    unordered_map<string, map<int, string>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        // take the upper bound of timestamp
        
        auto it = mp[key].upper_bound(timestamp);
        
        // if there is no. timestamp <= given timestamp
        
        if(it == mp[key].begin())
        {
            return "";
        }
        
        it--;
        
        // find the time
        
        int time = it -> first;
        
        return mp[key][time];
    }
}; dry run this code

Using Hashmap && Binary Search

Time Complexity :- O(1) for Set operation && O(logN) for Get Operation

Space Complexity :- O(N)



Let's dry-run the `TimeMap` class using a sample sequence of operations.

### Class Overview:
- `mp`: A map of key-value pairs, where the key is a string and the value is another map that stores timestamps (`int`) and their corresponding values (`string`).
- **set**: Stores a value for a key at a given timestamp.
- **get**: Retrieves the value of a key at or before a given timestamp.

### Scenario:
We'll consider the following operations:

1. `set("foo", "bar", 1)`
2. `set("foo", "bar2", 4)`
3. `get("foo", 4)`
4. `get("foo", 5)`
5. `get("foo", 2)`
6. `get("foo", 0)`

#### Initial State:

- `mp = {}` (empty)

### Operation 1: `set("foo", "bar", 1)`

- The `set` method inserts the value "bar" for the key "foo" with a timestamp of `1`.
- `mp` becomes:
  ```cpp
  mp["foo"] = {1: "bar"}
  ```

### Operation 2: `set("foo", "bar2", 4)`

- The `set` method inserts the value "bar2" for the key "foo" with a timestamp of `4`.
- `mp` now becomes:
  ```cpp
  mp["foo"] = {1: "bar", 4: "bar2"}
  ```

### Operation 3: `get("foo", 4)`

- We want to get the value for `"foo"` at timestamp `4`.
- `mp["foo"]` contains `{1: "bar", 4: "bar2"}`.
- The `upper_bound(4)` on `mp["foo"]` will return an iterator pointing **past** the entry with timestamp `4`, i.e., it will not include the exact match.
- The iterator points to an entry after `4`, so we move it back with `it--` to get the last timestamp `<= 4`, which is `4`.
- The value corresponding to timestamp `4` is `"bar2"`.
- **Return**: `"bar2"`

### Operation 4: `get("foo", 5)`

- We want to get the value for `"foo"` at timestamp `5`.
- `mp["foo"]` contains `{1: "bar", 4: "bar2"}`.
- The `upper_bound(5)` on `mp["foo"]` will return an iterator pointing **past** the largest timestamp, i.e., it will point to the end of the map.
- Since the iterator points past the last timestamp, we decrement it with `it--` to get the largest timestamp `<= 5`, which is `4`.
- The value corresponding to timestamp `4` is `"bar2"`.
- **Return**: `"bar2"`

### Operation 5: `get("foo", 2)`

- We want to get the value for `"foo"` at timestamp `2`.
- `mp["foo"]` contains `{1: "bar", 4: "bar2"}`.
- The `upper_bound(2)` on `mp["foo"]` will return an iterator pointing to timestamp `4`.
- We decrement the iterator with `it--` to get the largest timestamp `<= 2`, which is `1`.
- The value corresponding to timestamp `1` is `"bar"`.
- **Return**: `"bar"`

### Operation 6: `get("foo", 0)`

- We want to get the value for `"foo"` at timestamp `0`.
- `mp["foo"]` contains `{1: "bar", 4: "bar2"}`.
- The `upper_bound(0)` on `mp["foo"]` will return an iterator pointing to the first entry (timestamp `1`).
- Since `upper_bound` returns an iterator to the first element, there are no timestamps `<= 0`.
- **Return**: `""` (empty string)

### Final State of `mp`:
```cpp
mp["foo"] = {1: "bar", 4: "bar2"}
```

### Summary of Results:
- `get("foo", 4)` → `"bar2"`
- `get("foo", 5)` → `"bar2"`
- `get("foo", 2)` → `"bar"`
- `get("foo", 0)` → `""`

This code efficiently handles timestamped key-value storage and retrieval by utilizing maps with `upper_bound` to locate the appropriate value based on the timestamp.
