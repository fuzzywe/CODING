347. Top K Frequent Elements
Medium
Topics
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        
        for (auto& entry : counter) {
            heap.push({entry.first, entry.second});
        }
        
        vector<int> res;
        while (k-- > 0) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        
        return res;        
    }
};
```
Complexity
Time complexity: O(nlogk)
Space complexity: O(n)

Here is a detailed explanation of each line of the code with examples using the input:

### Input:
```cpp
nums = [1, 1, 1, 2, 2, 3]
k = 2
```

The task is to find the top `k` most frequent elements in the array `nums`.

### Code Breakdown:

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
```
- **Line 1-3**: We define a class `Solution` with a public function `topKFrequent`. It takes in a vector `nums` (list of integers) and an integer `k`, which represents how many top frequent elements we want to find.

---

```cpp
unordered_map<int, int> counter;
```
- **Line 4**: We declare an unordered map `counter` to store the frequency of each element in the `nums` array.
    - Example: After we process `nums = [1, 1, 1, 2, 2, 3]`, this map will store:
      ```cpp
      counter = {1: 3, 2: 2, 3: 1}
      ```

---

```cpp
for (int n : nums) {
    counter[n]++;
}
```
- **Line 5-7**: This loop iterates through the `nums` array and increments the count of each element in the `counter` map.
    - Example: 
      - For `n = 1`: `counter[1]++` makes `counter[1] = 1`, then again `counter[1]++` makes it `2`, and another `counter[1]++` makes it `3`.
      - Similarly for `n = 2`: `counter[2]++` increases the count to `2`.
      - For `n = 3`: `counter[3]++` makes `counter[3] = 1`.

At the end of the loop, `counter` will be:
```cpp
counter = {1: 3, 2: 2, 3: 1}
```
This means:
- `1` appears 3 times.
- `2` appears 2 times.
- `3` appears 1 time.

---

```cpp
auto comp = [](pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
};
```
- **Line 8-10**: Here we define a custom comparator `comp`. It's a lambda function that compares two pairs of integers. It returns `true` if the second element of pair `a` is smaller than the second element of pair `b`, meaning we want the pair with a larger frequency to be given priority in the heap.
    - Example: 
      - Comparing `(1, 3)` and `(2, 2)`, since `3 > 2`, the pair `(1, 3)` will be placed higher in the heap than `(2, 2)`.

---

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
```
- **Line 11**: We declare a **max heap** `heap`, which stores pairs of `(element, frequency)` from the `counter` map. We use our custom comparator `comp` to sort the pairs by frequency in descending order. The pair with the highest frequency will be on the top of the heap.

---

```cpp
for (auto& entry : counter) {
    heap.push({entry.first, entry.second});
}
```
- **Line 12-14**: We iterate over each element in the `counter` map and push each pair `(element, frequency)` into the heap.
    - Example: 
      - We push `(1, 3)` into the heap.
      - We push `(2, 2)` into the heap.
      - We push `(3, 1)` into the heap.

At the end of this step, the heap contains:
```cpp
heap = [(1, 3), (2, 2), (3, 1)]
```
Where `1` is at the top because it has the highest frequency of `3`.

---

```cpp
vector<int> res;
```
- **Line 15**: We initialize an empty vector `res` to store the result, which will hold the top `k` most frequent elements.

---

```cpp
while (k-- > 0) {
    res.push_back(heap.top().first);
    heap.pop();
}
```
- **Line 16-20**: We perform the following steps until we get `k` elements:
    1. **Heap Top**: Access the element with the highest frequency using `heap.top().first`.
    2. **Add to Result**: Add this element to the result vector `res`.
    3. **Remove from Heap**: Remove this element from the heap using `heap.pop()`.

    - Example:
      - First Iteration: 
        - `heap.top().first` gives `1` (since `(1, 3)` is at the top).
        - Add `1` to `res`: `res = [1]`.
        - Remove `(1, 3)` from the heap. Now the heap is:
          ```cpp
          heap = [(2, 2), (3, 1)]
          ```
      - Second Iteration:
        - `heap.top().first` gives `2` (since `(2, 2)` is now at the top).
        - Add `2` to `res`: `res = [1, 2]`.
        - Remove `(2, 2)` from the heap. Now the heap is:
          ```cpp
          heap = [(3, 1)]
          ```

---

```cpp
return res;
```
- **Line 21**: After extracting `k` elements from the heap, return the result vector `res` which contains the top `k` frequent elements.
    - For our example, the output will be:
    ```cpp
    return [1, 2];
    ```

### Dry Run Recap:
- **Input**: `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`
- **Step 1**: Count frequencies -> `counter = {1: 3, 2: 2, 3: 1}`
- **Step 2**: Insert into max heap -> `heap = [(1, 3), (2, 2), (3, 1)]`
- **Step 3**: Extract top `k = 2` elements -> First `1`, then `2`.
- **Output**: `[1, 2]`

### Output:
```cpp
[1, 2]
```




Let's perform a **dry run** of the provided code for the following input:

### Input:
```cpp
nums = [1, 1, 1, 2, 2, 3]
k = 2
```

We want to find the **top 2 most frequent elements** in the array `nums`.

---

### Step-by-Step Dry Run:

**Step 1: Count Frequencies** (Lines 4-6)

We iterate through `nums` to build a frequency count of each element using an unordered map `counter`.

- For `n = 1`: `counter[1]++`, so `counter = {1: 1}`
- For `n = 1`: `counter[1]++`, so `counter = {1: 2}`
- For `n = 1`: `counter[1]++`, so `counter = {1: 3}`
- For `n = 2`: `counter[2]++`, so `counter = {2: 1}`
- For `n = 2`: `counter[2]++`, so `counter = {2: 2}`
- For `n = 3`: `counter[3]++`, so `counter = {3: 1}`

At the end of this step, the frequency map is:
```cpp
counter = {1: 3, 2: 2, 3: 1}
```

---

**Step 2: Define Custom Comparator** (Lines 8-10)

- We define the `comp` comparator function to sort pairs based on the frequency (i.e., the second element in each pair).

---

**Step 3: Create Priority Queue (Max Heap)** (Lines 11-13)

- We initialize a max heap `heap` using the custom comparator. This heap will store pairs of `(element, frequency)`.

---

**Step 4: Insert Elements into Heap** (Lines 14-16)

We iterate through the `counter` map and insert each pair `(element, frequency)` into the heap:

- Push `(1, 3)` into the heap.
- Push `(2, 2)` into the heap.
- Push `(3, 1)` into the heap.

At the end of this step, the heap will look like:
```cpp
heap = [(1, 3), (2, 2), (3, 1)]
```
In a max heap, the element with the highest frequency (in this case, `1` with a frequency of `3`) is at the top.

---

**Step 5: Pop Top `k` Elements from Heap** (Lines 18-21)

We initialize an empty result vector `res` and start popping the top `k` elements from the heap.

- First pop: The top element in the heap is `(1, 3)`. So, we add `1` to `res` and remove `(1, 3)` from the heap.
  - `res = [1]`
  - Remaining heap: `[(2, 2), (3, 1)]`
  
- Second pop: The top element is now `(2, 2)`. We add `2` to `res` and remove `(2, 2)` from the heap.
  - `res = [1, 2]`
  - Remaining heap: `[(3, 1)]`

After popping `k = 2` elements, we have:
```cpp
res = [1, 2]
```

---

**Step 6: Return Result** (Line 23)

Finally, we return the result vector `res` which contains the top `k` frequent elements:
```cpp
return res;  // Output: [1, 2]
```

---

### Dry Run Summary:

- **Input**: `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`
- **Step 1**: Frequency map `counter = {1: 3, 2: 2, 3: 1}`
- **Step 2**: Define comparator.
- **Step 3**: Initialize heap `heap = [(1, 3), (2, 2), (3, 1)]`
- **Step 4**: Pop two elements from the heap.
  - First pop: `1` (highest frequency)
  - Second pop: `2` (second highest frequency)
- **Output**: `res = [1, 2]`

### Output:
```cpp
[1, 2]
```

---

### Conclusion:
The code correctly finds the top `k` most frequent elements in the array. For the input `nums = [1, 1, 1, 2, 2, 3]` and `k = 2`, the most frequent elements are `1` and `2`, as expected.
