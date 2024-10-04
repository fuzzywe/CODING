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
