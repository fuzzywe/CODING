
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

### **Understanding `auto it = mp[key].upper_bound(timestamp);`**

This line is part of the `get` function:

```cpp
string get(string key, int timestamp) {
    auto it = mp[key].upper_bound(timestamp);
```

Let's break it down step by step:

---

### **1. What is `mp[key]`?**
- `mp` is defined as:
  ```cpp
  unordered_map<string, map<int, string>> mp;
  ```
- So, `mp[key]` returns a **sorted `map<int, string>`**, where:
  - The **key** (`int`) represents timestamps.
  - The **value** (`string`) represents the stored data at that timestamp.

#### **Example Map (`mp`)**
```cpp
mp = {
    "foo": { 1 -> "bar", 4 -> "bar2" }
}
```

For `mp["foo"]`, the sorted `map<int, string>` is:
```cpp
{ 1 -> "bar", 4 -> "bar2" }
```

---

### **2. What is `.upper_bound(timestamp)`?**
- `upper_bound(x)` is a function in `map` that:
  - Finds the **first element whose key is greater than `x`**.
  - If **no such element exists**, it returns `end()`.

#### **Example Cases**
```cpp
auto it = mp["foo"].upper_bound(3);
```
- `mp["foo"] = { 1 -> "bar", 4 -> "bar2" }`
- `upper_bound(3)` will return **the first timestamp greater than `3`**, which is `4`.

```cpp
auto it = mp["foo"].upper_bound(4);
```
- The first timestamp **greater than `4`** is **not present**, so it returns `end()`.

---

### **3. Why Do We Do `it--`?**
```cpp
if (it == mp[key].begin()) return ""; // No valid timestamp
it--; // Move to the largest timestamp ≤ given timestamp
```
- `upper_bound(timestamp)` finds the first timestamp **greater than** `timestamp`.
- But we need the **largest timestamp ≤ timestamp**.
- So, we **move one step back (`it--`)** to find the required value.

---

### **4. Dry Run of `get("foo", timestamp)`**

#### **Case 1: `get("foo", 3)`**
- `mp["foo"] = { 1 -> "bar", 4 -> "bar2" }`
- `upper_bound(3)` returns **timestamp `4`**.
- Move back (`it--`), so `it` now points to **timestamp `1`**.
- **Output:** `"bar"`

#### **Case 2: `get("foo", 4)`**
- `upper_bound(4)` returns **timestamp `4`**.
- Move back (`it--`), so `it` still points to **timestamp `4`**.
- **Output:** `"bar2"`

#### **Case 3: `get("foo", 5)`**
- `upper_bound(5)` returns `end()` (no timestamp > 5).
- Move back (`it--`), so `it` now points to **timestamp `4`**.
- **Output:** `"bar2"`

#### **Case 4: `get("foo", 0)`**
- `upper_bound(0)` returns **timestamp `1`**.
- `it == mp[key].begin()`, so return `""`.
- **Output:** `""` (no valid timestamp).

---

### **5. Summary**
- `upper_bound(timestamp)` finds the **smallest timestamp greater than `timestamp`**.
- We use `it--` to move back and get the **largest timestamp ≤ `timestamp`**.
- If no valid timestamp exists, return `""`.

🚀 **This makes `get()` efficient with `O(logN)` complexity using binary search!**

No worries! Let’s go step by step with a **real example** so that everything makes sense.  

---

### **🔹 What does the `get()` function do?**  
The goal of `get(key, timestamp)` is to find **the latest value before or at** the given `timestamp`.

---

## **🔹 Example Execution with Step-by-Step Dry Run**
### **Step 1: Set Values**
We start by inserting values into our `mp` map using the `set()` function.  

```cpp
TimeMap tm;
tm.set("foo", "bar", 1);
tm.set("foo", "bar2", 4);
```

Now, the internal map (`mp`) looks like this:  

```cpp
mp["foo"] = { 1 -> "bar", 4 -> "bar2" };
```
This means:
- At **timestamp 1**, the value is `"bar"`.
- At **timestamp 4**, the value is `"bar2"`.

---

### **Step 2: Call `get("foo", 3)`**
We want to find the latest value **before or at `timestamp = 3`**.

#### **Inside `get()` Function**
```cpp
auto it = mp["foo"].upper_bound(3);
```
💡 **What does `upper_bound(3)` do?**
- It finds the **first timestamp that is greater than `3`**.
- In `mp["foo"] = { 1 -> "bar", 4 -> "bar2" }`, the first timestamp greater than `3` is `4`.

So now, `it` points to `{ 4 -> "bar2" }`.

---

#### **Step 3: Check if `it == mp[key].begin()`**
```cpp
if (it == mp["foo"].begin()) {
    return "";
}
```
- `it` is **not** at the beginning (`1` is the smallest timestamp).
- So we skip this condition.

---

#### **Step 4: Move `it` One Step Back (`it--`)**
```cpp
it--;
```
- Now, `it` moves back to `{ 1 -> "bar" }`.

---

#### **Step 5: Return the Found Value**
```cpp
return mp["foo"][it->first];
```
- `it->first = 1`, so we return `"bar"`.

✅ **Final Output for `get("foo", 3)` = `"bar"`**.

---

## **🔹 Another Example: Call `get("foo", 0)`**
We now try to get a value for `timestamp = 0`.

#### **Inside `get()` Function**
```cpp
auto it = mp["foo"].upper_bound(0);
```
💡 **What does `upper_bound(0)` do?**
- It finds the **first timestamp that is greater than `0`**.
- The first timestamp in `mp["foo"]` is `1`, so `it` points to `{ 1 -> "bar" }`.

---

#### **Step 3: Check if `it == mp[key].begin()`**
```cpp
if (it == mp["foo"].begin()) {
    return "";
}
```
- Here, `it` **is at** `begin()`, meaning there is **no smaller timestamp**.
- We return an **empty string** (`""`).

✅ **Final Output for `get("foo", 0)` = `""` (empty string).**

---

## **🔹 Final Summary**
✔ **What does `upper_bound(timestamp)` do?**  
   → Finds the first timestamp **greater than** `timestamp`.

✔ **Why check `if (it == mp[key].begin())`?**  
   → If there’s no earlier timestamp, we return `""`.

✔ **Why do `it--`?**  
   → To get the **largest timestamp ≤ timestamp**.

---

## **Final Expected Outputs**
| Function Call          | Explanation                                | Output   |
|------------------------|--------------------------------------------|----------|
| `set("foo", "bar", 1)`  | Store "bar" at timestamp `1` | `null`   |
| `set("foo", "bar2", 4)` | Store "bar2" at timestamp `4` | `null`   |
| `get("foo", 1)`        | Exact match at `1` → return `"bar"` | `"bar"`  |
| `get("foo", 3)`        | Nearest timestamp ≤ `3` is `1` → `"bar"` | `"bar"`  |
| `get("foo", 4)`        | Exact match at `4` → return `"bar2"` | `"bar2"` |
| `get("foo", 5)`        | Nearest timestamp ≤ `5` is `4` → `"bar2"` | `"bar2"` |
| `get("foo", 0)`        | No earlier timestamp → return `""` | `""` |

---

I hope this makes it **clear** now! 😊 Let me know if anything is still confusing. 🚀
