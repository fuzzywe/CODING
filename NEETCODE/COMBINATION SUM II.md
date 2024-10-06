40. Combination Sum II
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector < vector < int >> ans;
        vector < int > ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
};
```

Let's go through the code step by step, explain each line, and provide examples to clarify the concepts.

### Code:

```cpp
class Solution {
```
- **Explanation**: This defines a class named `Solution`. In competitive programming and coding platforms, the solution is often encapsulated in a class.

---

```cpp
public:
```
- **Explanation**: The keyword `public` indicates that the methods and members inside this block are accessible from outside the class.

---

```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
```
- **Explanation**: This is the main function that will be called. It takes:
  - `candidates`: A reference to a vector of integers containing the input numbers.
  - `target`: The target sum we are trying to achieve using the numbers in `candidates`.

  It returns a `vector<vector<int>>`, which contains all the unique combinations of numbers that sum up to the target.

---

```cpp
sort(candidates.begin(), candidates.end());
```
- **Explanation**: This line sorts the `candidates` array in non-decreasing order. Sorting helps in efficiently skipping duplicates and optimizing the process.
- **Example**: If `candidates = [10, 1, 2, 7, 6, 1, 5]`, after sorting, it becomes `[1, 1, 2, 5, 6, 7, 10]`.

---

```cpp
vector<vector<int>> ans;
```
- **Explanation**: This declares a 2D vector `ans` to store all the unique combinations of numbers that sum up to the target.
- **Example**: Initially, `ans` is empty (`[]`). As combinations are found, valid ones like `[1, 1, 6]`, `[1, 2, 5]` will be added to `ans`.

---

```cpp
vector<int> ds;
```
- **Explanation**: This declares a vector `ds` to store the current combination being explored. As we recursively explore different possibilities, we add elements to this vector.
- **Example**: If the current combination being explored is `[1, 2, 5]`, `ds` will store these values during recursion.

---

```cpp
findCombination(0, target, candidates, ans, ds);
```
- **Explanation**: This calls the helper function `findCombination` to explore possible combinations starting from index `0`. It uses `target` as the remaining sum to reach.
- **Example**: The parameters passed are:
    - `0`: Start index of the search.
    - `target`: The target sum (for example, `8`).
    - `candidates`: The sorted list of numbers `[1, 1, 2, 5, 6, 7, 10]`.
    - `ans`: The empty vector to store the valid combinations.
    - `ds`: The empty vector to store the current combination during recursion.

---

```cpp
return ans;
```
- **Explanation**: After all combinations are explored, the function returns `ans`, which contains all the unique combinations that sum up to the target.
- **Example**: If the input `candidates = [1, 1, 2, 5, 6, 7, 10]` and `target = 8`, the result might be `[[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]`.

---

### Helper Function: `findCombination`

```cpp
void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
```
- **Explanation**: This is a recursive helper function that finds all the unique combinations. It takes several parameters:
  - `ind`: The index from which the search starts in the `arr` (or `candidates`) array.
  - `target`: The remaining target sum we want to achieve.
  - `arr`: The sorted list of numbers.
  - `ans`: The result vector to store valid combinations.
  - `ds`: The current combination being formed.

---

```cpp
if (target == 0) {
```
- **Explanation**: This checks if the `target` has become `0`. If it has, it means the current combination in `ds` adds up to the original target.
- **Example**: If `target = 0`, and `ds = [1, 2, 5]`, this means that `1 + 2 + 5 = 8`, which is the target.

---

```cpp
ans.push_back(ds);
```
- **Explanation**: When the `target` becomes `0`, this pushes the current combination stored in `ds` into `ans`.
- **Example**: If `ds = [1, 1, 6]`, it gets added to `ans`, making `ans = [[1, 1, 6]]`.

---

```cpp
return;
```
- **Explanation**: After adding the valid combination to `ans`, the function returns, stopping further exploration in this recursion branch.

---

```cpp
for (int i = ind; i < arr.size(); i++) {
```
- **Explanation**: This `for` loop iterates over all elements in `arr` starting from the index `ind`. It tries to form combinations using the current element and the following elements.

---

```cpp
if (i > ind && arr[i] == arr[i - 1]) continue;
```
- **Explanation**: This line is crucial to avoid duplicates. If `arr[i]` is the same as `arr[i - 1]` and we are not at the start of the loop (`i > ind`), we skip this iteration to prevent using the same number multiple times.
- **Example**: If `arr = [1, 1, 2]`, and the second `1` is encountered, it skips to avoid using both `1`s in different combinations.

---

```cpp
if (arr[i] > target) break;
```
- **Explanation**: If the current element `arr[i]` is greater than the remaining `target`, we stop further processing (break the loop). Since the array is sorted, any subsequent elements will also be too large.
- **Example**: If `arr[i] = 7` and `target = 6`, there’s no point in continuing because `7` is too large to form a valid combination.

---

```cpp
ds.push_back(arr[i]);
```
- **Explanation**: This adds the current element `arr[i]` to the combination vector `ds`.
- **Example**: If `arr[i] = 2`, and `ds = [1]`, after this line `ds` becomes `[1, 2]`.

---

```cpp
findCombination(i + 1, target - arr[i], arr, ans, ds);
```
- **Explanation**: This recursively calls the `findCombination` function, but now starts from the next index (`i + 1`), and the target is reduced by the current element (`target - arr[i]`).
- **Example**: If `arr[i] = 2` and `target = 8`, after this call, the new target will be `6`.

---

```cpp
ds.pop_back();
```
- **Explanation**: After the recursive call, this removes the last element added to `ds` (backtracking). This allows us to explore other combinations without the current element.
- **Example**: If `ds = [1, 2]`, after this line, it becomes `[1]` again.

---

```cpp
}
```
- **Explanation**: This marks the end of the `for` loop, where we iterate over all elements in the sorted array.

```cpp
}
```
- **Explanation**: This marks the end of the `findCombination` function.

```cpp
};
```
- **Explanation**: This marks the end of the class `Solution`.

---

### Dry Run Example:

**Input**:
- `candidates = [10, 1, 2, 7, 6, 1, 5]`
- `target = 8`

**Step 1**: Sort the `candidates` array:  
`[1, 1, 2, 5, 6, 7, 10]`

**Step 2**: Call `findCombination(0, 8, [1, 1, 2, 5, 6, 7, 10], ans, ds)`.

**Recursive Exploration**:
1. Start with `i = 0`, pick `1`.  
   `ds = [1]`, target becomes `7`.
   
2. Next, pick `1` again (at `i = 1`).  
   `ds = [1, 1]`, target becomes `6`.

3. Pick `6` (at `i = 4`).  
   `ds = [1, 1, 6]`, target becomes `0`.  
   This is a valid combination, so add it to `ans`.

4. Backtrack, remove `6`.  
   Now, `ds = [1, 1]`, and try `7` (at `i = 5`).  
   `ds = [1, 7]`, target becomes `0`.  
   This is another valid combination, so add it to `ans`.

5. Backtrack, remove `7`.  
   Now, `ds = [1]`, and try `2` (at `i = 2`).  
