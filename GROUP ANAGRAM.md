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

**Example**

Let’s explain this code with a concrete example to make it clearer. We'll use the input ["eat", "tea", "tan", "ate", "nat", "bat"].

Example Input:

vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
Step-by-step Explanation:
Initial Setup:

We create an unordered_map<string, vector<string>> ans to store the grouped anagrams.
For each string in strs, we will generate a key that represents its character frequencies and use that key to group strings that are anagrams.
Processing the first string, "eat":

Initialize an array of size 26 to count the frequency of each letter in "eat":


array<int, 26> count = {0};
For each letter in "eat":

'e': count['e' - 'a']++ increments the count at index 4 (since 'e' is the 5th letter of the alphabet).
'a': count['a' - 'a']++ increments the count at index 0.
't': count['t' - 'a']++ increments the count at index 19.
After processing, the count array looks like this:


[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
This represents 1 'a', 1 'e', and 1 't', and 0 of all other letters.

Next, we construct the key string from this count array:


key = "1#0#0#0#0#0#...#1#0#..." // Shortened for readability
This key uniquely represents the frequency of letters in "eat".

Add "eat" to the map ans with this key:


ans["1#0#0#0#0#0#...#1#0#..."].push_back("eat");
Processing the second string, "tea":

Repeat the process for "tea":

't': Increment count at index 19.
'e': Increment count at index 4.
'a': Increment count at index 0.
The frequency count is identical to "eat", so the key is the same:


key = "1#0#0#0#0#0#...#1#0#..."
Add "tea" to the map under the same key:


ans["1#0#0#0#0#0#...#1#0#..."].push_back("tea");
Processing the third string, "tan":

For "tan":

't': Increment count at index 19.
'a': Increment count at index 0.
'n': Increment count at index 13.
The resulting frequency array will be:


[1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
This gives a different key:


key = "1#0#0#0#0#0#...#1#1#0#..."
Add "tan" to the map under its own unique key:


ans["1#0#0#0#0#0#...#1#1#0#..."].push_back("tan");
Processing the remaining strings:

Process "ate", which will have the same frequency count as "eat" and "tea", so it shares the same key:


ans["1#0#0#0#0#0#...#1#0#..."].push_back("ate");
Process "nat", which will have the same frequency count as "tan", so it shares the same key:


ans["1#0#0#0#0#0#...#1#1#0#..."].push_back("nat");
Process "bat", which has a unique frequency count:

'b': Increment count at index 1.
'a': Increment count at index 0.
't': Increment count at index 19.
Key:


key = "1#1#0#0#0#0#...#1#0#..."
Add "bat" to the map:


ans["1#1#0#0#0#0#...#1#0#..."].push_back("bat");
Constructing the result:

Now, ans looks like this:

{
  "1#0#0#0#0#...#1#0#..." : ["eat", "tea", "ate"],
  "1#0#0#0#0#...#1#1#0#..." : ["tan", "nat"],
  "1#1#0#0#0#...#1#0#..." : ["bat"]
}
The function iterates over the map and moves each vector of anagrams into the result vector:

result = [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]];
Returning the result:

The final result, result, contains groups of anagrams, which will be returned:

return result;
Final Output:

[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]


