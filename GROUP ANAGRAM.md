not efficient:
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string& s : strs) {//logic is mentioned below
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : ans) {
            result.push_back(entry.second);
        }

        return result;        
    }
};
//Complexity
//Time complexity: O(m∗nlogn)
//Space complexity: O(mn)

```

---

The problem is to group anagrams together from a given list of strings. An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. For example, "listen" and "silent" are anagrams.

### Logic of the Code:
1. **Use a Hash Map (Dictionary) to Group Anagrams**:
   - The key idea is to use a hash map (`unordered_map`) where the **key** is a sorted version of the string, and the **value** is a list of strings that are anagrams of each other.
   - By sorting the characters of a string, all anagrams will produce the same sorted string. For example:
     - "listen" → "eilnst"
     - "silent" → "eilnst"
   - This sorted string acts as a unique identifier for all anagrams.

2. **Iterate Through the Input List**:
   - For each string in the input list `strs`:
     - Sort the string to create the key.
     - Add the original string to the corresponding list in the hash map using this key.

3. **Collect the Results**:
   - After processing all strings, the hash map will contain groups of anagrams.
   - Iterate through the hash map and collect the values (lists of anagrams) into the final result.

### Code Breakdown:
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Hash map to store groups of anagrams
    unordered_map<string, vector<string>> ans;

    // Iterate through each string in the input list
    for (string& s : strs) {
        // Create a sorted version of the string to use as the key
        string key = s;
        sort(key.begin(), key.end());

        // Add the original string to the corresponding group in the hash map
        ans[key].push_back(s);
    }

    // Prepare the result by collecting all groups from the hash map
    vector<vector<string>> result;
    for (auto& entry : ans) {
        result.push_back(entry.second);
    }

    return result;
}
```

### Example:
Input:
```
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
```

Step-by-Step Execution:
1. For "eat":
   - Sorted key: "aet"
   - Hash map: `{"aet": ["eat"]}`
2. For "tea":
   - Sorted key: "aet"
   - Hash map: `{"aet": ["eat", "tea"]}`
3. For "tan":
   - Sorted key: "ant"
   - Hash map: `{"aet": ["eat", "tea"], "ant": ["tan"]}`
4. For "ate":
   - Sorted key: "aet"
   - Hash map: `{"aet": ["eat", "tea", "ate"], "ant": ["tan"]}`
5. For "nat":
   - Sorted key: "ant"
   - Hash map: `{"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"]}`
6. For "bat":
   - Sorted key: "abt"
   - Hash map: `{"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"], "abt": ["bat"]}`

Final Result:
```
[
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]
```

### Complexity Analysis:
1. **Time Complexity**:
   - Sorting each string takes \(O(n \log n)\), where \(n\) is the length of the string.
   - Since there are \(m\) strings, the total time complexity is \(O(m \cdot n \log n)\).

2. **Space Complexity**:
   - The hash map stores all the strings, so the space complexity is \(O(m \cdot n)\), where \(m\) is the number of strings and \(n\) is the average length of the strings.

This approach is efficient and works well for the problem constraints.
**Concept of entry and auto:**
entry: This refers to each individual element in the unordered_map during the loop. Since the unordered_map stores key-value pairs, each entry is a pair consisting of:

entry.first: The key of the map (in this case, a sorted string representing the group of anagrams).

entry.second: The value of the map (in this case, a vector<string> containing the actual anagrams).

auto: This is a keyword in C++ that automatically deduces the type of a variable. Instead of explicitly specifying the type of entry (which would be pair<const string, 

vector<string>>), we use auto to let the compiler figure out the type for us.

auto& entry Explanation:
a
uto&: This tells the compiler to:

Use auto to deduce the type of entry, which in this case is a reference to a key-value pair (pair<const string, vector<string>>).

The & means we are using a reference to each element in the unordered_map. Using a reference avoids copying the pair (which can be more efficient), and we are able to 

modify the original elements if needed.

So, in this line:

cpp
Copy code
**for (auto& entry : ans)**
The loop is iterating over the map ans. In each iteration:

entry refers to the pair {"ant", {"tan", "nat"}}.

entry.first is "ant".

entry.second is {"tan", "nat"}.





**for (string& s : strs)**

**the & is used to define a reference to the string s from the strs vector, rather than creating a copy of each string.**

Here's why using the & (reference) is important:

Efficiency:
When you pass a reference (&s),**you are avoiding making a copy of the string in the loop**.

**Without the &, the loop would create a copy of each string every time it iterates**

This copying process can be costly, especially if the strings are large, because it involves allocating new memory and duplicating the contents of the original string.

**By using a reference, the loop directly operates on the original strings in the strs vector. This saves memory and improves performance.**

Avoid Unnecessary Memory Overhead:
Strings in C++ can vary in size and are typically stored in dynamically allocated memory. Copying them without using references involves not only copying the content but also allocating new memory, which is unnecessary when you just need to read or modify the original strings.

Without & (Copying):
```cpp

for (string s : strs)


This creates a copy of each string, increasing memory usage.
```

For example, if strs contains large strings, the system will need to allocate additional memory for each copy and duplicate their content.

```cpp
With & (Referencing):

for (string& s : strs)
This only references the original strings, avoiding memory duplication.
No extra memory is used for string copying, which results in faster execution and lower memory consumption.

```
Example Impact:
If strs contains large strings like:

cpp
Copy code
vector<string> strs = {"a very long string", "another long string"};
Using for (string s : strs) would create new copies of "a very long string" and "another long string", which is unnecessary since you only need to operate on the original strings.

By using for (string& s : strs), you directly reference the original strings without copying them, improving performance and reducing memory overhead.

In summary:

The & is used to pass a reference to each string in the loop, ensuring that no unnecessary copies of the strings are made, making the loop more efficient.



**Efficient**
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string& s : strs) {
            array<int, 26> count = {0};

            // Count frequency of each letter in the string
            for (char c : s) {
                count[c - 'a']++;
            }

            string key;
            for (int num : count) {
                key += to_string(num) + "#";
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : ans) {
            result.push_back(move(entry.second));
        }

        return result;        
    }
};//o(m*n),O(mn)

```

---

Great question! Let’s break down why we use `c - 'a'` in the code and what it does.

---

### What is `c - 'a'`?
- In C++ (and many other programming languages), characters are represented by their **ASCII values**.
- For example:
  - The character `'a'` has an ASCII value of **97**.
  - The character `'b'` has an ASCII value of **98**.
  - The character `'c'` has an ASCII value of **99**.
  - And so on, up to `'z'`, which has an ASCII value of **122**.

- When we subtract `'a'` from a lowercase character (`c - 'a'`), we are essentially converting the character into an **index**:
  - `'a' - 'a' = 0`
  - `'b' - 'a' = 1`
  - `'c' - 'a' = 2`
  - ...
  - `'z' - 'a' = 25`

This gives us a number between **0 and 25**, which corresponds to the position of the letter in the English alphabet.

---

### Why Do We Need `c - 'a'`?
In the code, we use an array of size 26 to count the frequency of each letter in a word. The array indices represent the letters of the alphabet:
- Index `0` represents `'a'`.
- Index `1` represents `'b'`.
- Index `2` represents `'c'`.
- ...
- Index `25` represents `'z'`.

By using `c - 'a'`, we can map each character to its corresponding index in the array. For example:
- If `c = 'a'`, then `c - 'a' = 0`. This means we increment the count at index `0` in the array.
- If `c = 'b'`, then `c - 'a' = 1`. This means we increment the count at index `1` in the array.
- If `c = 'z'`, then `c - 'a' = 25`. This means we increment the count at index `25` in the array.

---

### Example:
Let’s say we have the word `"eat"`.

1. For the first character `'e'`:
   - `'e' - 'a' = 4` (because `'e'` is the 5th letter in the alphabet, and we start counting from 0).
   - We increment the count at index `4` in the array.

2. For the second character `'a'`:
   - `'a' - 'a' = 0`.
   - We increment the count at index `0` in the array.

3. For the third character `'t'`:
   - `'t' - 'a' = 19` (because `'t'` is the 20th letter in the alphabet).
   - We increment the count at index `19` in the array.

After processing the word `"eat"`, the frequency count array will look like this:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```
This array represents the frequency of each letter in the word `"eat"`.

---

### Why Not Use the Character Directly?
We cannot use the character directly as an index because:
- Array indices must be integers, not characters.
- The ASCII value of `'a'` is 97, `'b'` is 98, etc. If we tried to use these directly as indices, we would need an array of size 123 (to cover all ASCII values up to `'z'`), which is wasteful.
- By subtracting `'a'`, we map the characters to a compact range of indices (0 to 25), which is efficient and easy to work with.

---

### Summary:
- `c - 'a'` converts a lowercase character into an index between 0 and 25.
- This allows us to use a small array of size 26 to count the frequency of each letter in a word.
- It’s a simple and efficient way to map characters to array indices.

---

### Example in Code:
Here’s the relevant part of the code:
```cpp
array<int, 26> count = {0}; // Initialize an array of size 26 with all zeros

for (char c : s) {
    count[c - 'a']++; // Increment the count for the corresponding letter
}
```

For the word `"eat"`:
- `'e' - 'a' = 4` → `count[4]++`
- `'a' - 'a' = 0` → `count[0]++`
- `'t' - 'a' = 19` → `count[19]++`

After this loop, the `count` array will store the frequency of each letter in the word.

---
Great question! Let’s talk about how the `count` array is **initialized** and how it works step by step.

---

### What is the `count` Array?
The `count` array is used to store the frequency of each letter in a word. It has a size of **26** because there are 26 letters in the English alphabet. Each index in the array corresponds to a specific letter:
- Index `0` corresponds to `'a'`.
- Index `1` corresponds to `'b'`.
- Index `2` corresponds to `'c'`.
- ...
- Index `25` corresponds to `'z'`.

---

### How is the `count` Array Initialized?
In the code, the `count` array is initialized like this:
```cpp
array<int, 26> count = {0};
```

This means:
- The array is of size 26.
- All 26 elements are initialized to `0`.

So, initially, the `count` array looks like this:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

This represents that initially, the frequency of every letter (`'a'` to `'z'`) is **0**.

---

### How Does the `count` Array Work?
For each word, we reset the `count` array to all zeros (to start counting fresh). Then, for each character in the word:
1. We calculate its index using `c - 'a'`.
2. We increment the value at that index in the `count` array.

---

### Example:
Let’s take the word `"eat"` and see how the `count` array changes step by step.

#### Step 1: Initialize `count` Array
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

#### Step 2: Process the First Character `'e'`
- `'e' - 'a' = 4` (because `'e'` is the 5th letter in the alphabet, and we start counting from 0).
- Increment `count[4]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

#### Step 3: Process the Second Character `'a'`
- `'a' - 'a' = 0` (because `'a'` is the 1st letter in the alphabet).
- Increment `count[0]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

#### Step 4: Process the Third Character `'t'`
- `'t' - 'a' = 19` (because `'t'` is the 20th letter in the alphabet).
- Increment `count[19]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

---

### Final `count` Array for `"eat"`:
After processing the word `"eat"`, the `count` array looks like this:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

This means:
- `'a'` appears **1** time.
- `'e'` appears **1** time.
- `'t'` appears **1** time.
- All other letters appear **0** times.

---

### Why Do We Reset the `count` Array for Each Word?
We reset the `count` array to all zeros for each new word because:
- Each word has its own unique frequency of letters.
- We don’t want the counts from the previous word to affect the current word.

---

### Key Points:
1. The `count` array is initialized to all zeros at the start of processing each word.
2. For each character in the word, we calculate its index using `c - 'a'` and increment the corresponding value in the `count` array.
3. At the end, the `count` array represents the frequency of each letter in the word.

---

### Example for Another Word:
Let’s take the word `"tea"`.

#### Step 1: Initialize `count` Array
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

#### Step 2: Process the First Character `'t'`
- `'t' - 'a' = 19`.
- Increment `count[19]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

#### Step 3: Process the Second Character `'e'`
- `'e' - 'a' = 4`.
- Increment `count[4]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:0 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

#### Step 4: Process the Third Character `'a'`
- `'a' - 'a' = 0`.
- Increment `count[0]`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

---

### Final `count` Array for `"tea"`:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

This is the same as the `count` array for `"eat"`, which confirms that `"eat"` and `"tea"` are anagrams.

---
Great question! Let’s break down why we use `key += to_string(num) + "#"` in the code and what it does.

---

### What is the Purpose of `key`?
The `key` is a string that uniquely represents the **frequency count** of letters in a word. It is used as the **key** in the hash map (`unordered_map`) to group anagrams together.

For example:
- The word `"eat"` has the frequency count: `1` for `'a'`, `1` for `'e'`, and `1` for `'t'`.
- The word `"tea"` has the same frequency count: `1` for `'a'`, `1` for `'e'`, and `1` for `'t'`.

Both `"eat"` and `"tea"` will have the same `key`, so they will be grouped together in the hash map.

---

### Why Use `to_string(num) + "#"`?
The `count` array stores the frequency of each letter in the word. For example, for the word `"eat"`, the `count` array looks like this:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

To create a unique `key` for this frequency count, we convert the array into a string. However, we need to ensure that the string representation is **unique** and **unambiguous**. For example:
- If we simply concatenate the numbers, `1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0` could be misinterpreted (e.g., is `10` a single number or two separate numbers?).
- To avoid ambiguity, we add a **delimiter** (`#`) between the numbers.

---

### How Does `key += to_string(num) + "#"` Work?
1. **`to_string(num)`**:
   - Converts the integer `num` (which is the frequency count of a letter) into a string.
   - For example, if `num = 1`, `to_string(num)` returns `"1"`.

2. **`+ "#"`**:
   - Adds a delimiter (`#`) after the number to separate it from the next number.
   - For example, if `num = 1`, `to_string(num) + "#"` returns `"1#"`.

3. **`key += ...`**:
   - Appends the string (`to_string(num) + "#"`) to the `key`.

---

### Example:
Let’s take the word `"eat"` and see how the `key` is constructed step by step.

#### Step 1: Initialize `key`
```
key = ""
```

#### Step 2: Process the `count` Array
The `count` array for `"eat"` is:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 0 0 0 1 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

We iterate through the `count` array and append each number followed by `#` to the `key`:
1. `count[0] = 1` → `key += "1#"`
   ```
   key = "1#"
   ```
2. `count[1] = 0` → `key += "0#"`
   ```
   key = "1#0#"
   ```
3. `count[2] = 0` → `key += "0#"`
   ```
   key = "1#0#0#"
   ```
4. `count[3] = 0` → `key += "0#"`
   ```
   key = "1#0#0#0#"
   ```
5. `count[4] = 1` → `key += "1#"`
   ```
   key = "1#0#0#0#1#"
   ```
6. `count[5] = 0` → `key += "0#"`
   ```
   key = "1#0#0#0#1#0#"
   ```
7. Continue this process for all 26 indices.

---

#### Final `key` for `"eat"`:
After processing all 26 indices, the `key` will look like this:
```
key = "1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#"
```

This `key` uniquely represents the frequency count of letters in the word `"eat"`.

---

### Why Use `#` as a Delimiter?
The delimiter (`#`) is used to **separate** the frequency counts of each letter. Without a delimiter, the `key` could become ambiguous. For example:
- Without a delimiter: `"101"` could mean `1`, `0`, `1` or `10`, `1`.
- With a delimiter: `"1#0#1#"` clearly means `1`, `0`, `1`.

---

### Example for Another Word:
Let’s take the word `"bat"`.

#### Step 1: Initialize `key`
```
key = ""
```

#### Step 2: Process the `count` Array
The `count` array for `"bat"` is:
```
Index: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Value:1 1 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
```

We iterate through the `count` array and append each number followed by `#` to the `key`:
1. `count[0] = 1` → `key += "1#"`
   ```
   key = "1#"
   ```
2. `count[1] = 1` → `key += "1#"`
   ```
   key = "1#1#"
   ```
3. `count[2] = 0` → `key += "0#"`
   ```
   key = "1#1#0#"
   ```
4. Continue this process for all 26 indices.

---

#### Final `key` for `"bat"`:
After processing all 26 indices, the `key` will look like this:
```
key = "1#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#"
```

This `key` uniquely represents the frequency count of letters in the word `"bat"`.

---

### Why is This `key` Unique?
The `key` is unique because:
1. It captures the exact frequency of each letter in the word.
2. The delimiter (`#`) ensures that the frequency counts are not misinterpreted.
3. Two words will have the same `key` **if and only if** they are anagrams of each other.

---

### Summary:
- `key += to_string(num) + "#"` converts the frequency count array into a unique string representation.
- The `#` delimiter ensures that the `key` is unambiguous.
- This `key` is used to group anagrams together in the hash map.

---

Let me know if you have more questions! 😊

