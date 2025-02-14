
https://leetcode.com/problems/time-based-key-value-store/description/?envType=problem-list-v2&envId=adx6f5td

---

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]

[[],
["foo", "bar", 1],
["foo", 1], 
["foo", 3],
["foo", "bar2", 4], 
["foo", 4],
["foo", 5]]

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

---

```cpp

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


Let’s break down the input and output you provided step by step to understand what’s happening in the `TimeMap` class and how it works.

### Input:

```plaintext
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
```

### Explanation:

1. **`TimeMap()`**:  
   This initializes the `TimeMap` object.  
   - **Output**: `null` (no return value for constructor)

2. **`set("foo", "bar", 1)`**:  
   This stores the key `"foo"` with the value `"bar"` and timestamp `1`.  
   - **State**: `mp["foo"] = {1: "bar"}`
   - **Output**: `null` (no return value for `set` method)

3. **`get("foo", 1)`**:  
   This retrieves the value for `"foo"` at timestamp `1`.  
   - **State**: `mp["foo"] = {1: "bar"}`
   - Since there is an exact match at timestamp `1`, it returns `"bar"`.
   - **Output**: `"bar"`

4. **`get("foo", 3)`**:  
   This retrieves the value for `"foo"` at timestamp `3`.  
   - **State**: `mp["foo"] = {1: "bar"}`
   - There is no exact match at timestamp `3`, so the code looks for the closest earlier timestamp, which is `1`.  
   - **Result**: `"bar"`
   - **Output**: `"bar"`

5. **`set("foo", "bar2", 4)`**:  
   This stores the key `"foo"` with the value `"bar2"` and timestamp `4`.  
   - **State**: `mp["foo"] = {1: "bar", 4: "bar2"}`
   - **Output**: `null` (no return value for `set` method)

6. **`get("foo", 4)`**:  
   This retrieves the value for `"foo"` at timestamp `4`.  
   - **State**: `mp["foo"] = {1: "bar", 4: "bar2"}`
   - Since there is an exact match at timestamp `4`, it returns `"bar2"`.
   - **Output**: `"bar2"`

7. **`get("foo", 5)`**:  
   This retrieves the value for `"foo"` at timestamp `5`.  
   - **State**: `mp["foo"] = {1: "bar", 4: "bar2"}`
   - There is no exact match at timestamp `5`, so the code looks for the closest earlier timestamp, which is `4`.  
   - **Result**: `"bar2"`
   - **Output**: `"bar2"`

### Final Outputs:
```plaintext
[null, null, "bar", "bar", null, "bar2", "bar2"]
```

### Detailed Walkthrough:

1. **Initialization (`TimeMap()`)**:
   - A new `TimeMap` object is created with an empty `unordered_map`.
   - **State**: `mp = {}`

2. **First `set("foo", "bar", 1)`**:
   - The `set` method adds `"foo"` with value `"bar"` at timestamp `1`.
   - **State**: `mp = {"foo": {1: "bar"}}`
   - No output for `set` method, so output is `null`.

3. **First `get("foo", 1)`**:
   - The `get` method finds an exact match for `"foo"` at timestamp `1`, returning `"bar"`.
   - **Output**: `"bar"`

4. **Second `get("foo", 3)`**:
   - The `get` method does not find an exact match for `"foo"` at timestamp `3`, so it looks for the closest earlier timestamp. The closest earlier timestamp is `1`, returning `"bar"`.
   - **Output**: `"bar"`

5. **Second `set("foo", "bar2", 4)`**:
   - The `set` method adds `"foo"` with value `"bar2"` at timestamp `4`.
   - **State**: `mp = {"foo": {1: "bar", 4: "bar2"}}`
   - No output for `set` method, so output is `null`.

6. **Third `get("foo", 4)`**:
   - The `get` method finds an exact match for `"foo"` at timestamp `4`, returning `"bar2"`.
   - **Output**: `"bar2"`

7. **Fourth `get("foo", 5)`**:
   - The `get` method does not find an exact match for `"foo"` at timestamp `5`, so it looks for the closest earlier timestamp. The closest earlier timestamp is `4`, returning `"bar2"`.
   - **Output**: `"bar2"`

### Summary:
- The `set` method stores values with timestamps.
- The `get` method retrieves the value at a specific timestamp or the closest earlier one.
- Outputs match exactly what’s expected:
  ```plaintext
  [null, null, "bar", "bar", null, "bar2", "bar2"]
  ```

  ### **Understanding `mp[key][timestamp] = value;`**

This line is part of the `set` function:

```cpp
void set(string key, string value, int timestamp) {
    mp[key][timestamp] = value;
}
```

Let's break it down step by step:

---

### **1. What is `mp`?**
- `mp` is an **unordered_map** of type:
  ```cpp
  unordered_map<string, map<int, string>> mp;
  ```
- This means `mp` is a **hashmap (`unordered_map`)** where:
  - The **key** (`string`) represents a unique identifier (e.g., `"foo"`).
  - The **value** is another **sorted map (`map<int, string>`)**, where:
    - The **key** (`int`) is a **timestamp**.
    - The **value** (`string`) is the **stored value** at that timestamp.

---

### **2. What does `mp[key][timestamp] = value;` do?**
- `mp[key]` accesses the **inner `map<int, string>`** corresponding to `key`.
- `mp[key][timestamp]` accesses the **value** at `timestamp` inside this inner `map<int, string>`.
- The `=` operator assigns `value` to `timestamp` inside this inner map.

#### **Example 1: First Insertion**
```cpp
mp["foo"][1] = "bar";
```
- If `"foo"` does not exist in `mp`, a new **empty map** (`map<int, string>`) is created.
- Then, in this new inner `map`, `1` is added as a key with `"bar"` as its value.

**Effect on `mp`:**
```cpp
mp = {
    "foo": { 1 -> "bar" }
}
```

---

#### **Example 2: Another Insertion**
```cpp
mp["foo"][4] = "bar2";
```
- `"foo"` already exists in `mp`, so we update its inner map.
- We add timestamp `4` with value `"bar2"`.

**Updated `mp`:**
```cpp
mp = {
    "foo": { 1 -> "bar", 4 -> "bar2" }
}
```

---

### **3. Why Use `map<int, string>`?**
- **Maps are sorted:** The timestamps are stored in **ascending order**, making **binary search (`upper_bound`) possible** for efficient retrieval.
- **Efficient retrieval:** We can quickly find the closest timestamp ≤ `timestamp` using `upper_bound()` in `O(log N)` time.
- **Automatic memory allocation:** If `key` does not exist, `mp[key]` creates a new `map<int, string>` automatically.

---

### **4. Summary**
- `mp[key]` ensures a **sorted map (`map<int, string>`)** exists for `key`.
- `mp[key][timestamp] = value;` inserts the value at the specified timestamp.
- This allows us to efficiently **store** and **retrieve** values for a key at different timestamps.

🚀 **This approach makes `set()` efficient (O(1)) and `get()` fast using binary search (O(logN))!**
