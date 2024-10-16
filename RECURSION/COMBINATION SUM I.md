https://leetcode.com/problems/combination-sum/description/

https://takeuforward.org/data-structure/combination-sum-1/
see how does combination works in the above link

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
**Time complexity: O(2 t )**

**Space complexity: O(t+k)**

```cpp

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;        
    }

private:
    void makeCombination(std::vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }    
};

```
Sure! Let’s go through a **detailed dry run** of the `combinationSum` function, explaining **each line** of the code and how the logic unfolds, step-by-step. The goal is to help you understand the mechanics of the code, so you can apply the same logic to solve other similar problems.

Here's the code again:

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; // Step 1: Create a 2D vector to store valid combinations.
        vector<int> comb;        // Step 2: Temporary vector to store current combination.
        makeCombination(candidates, target, 0, comb, 0, res); // Step 3: Recursively form combinations.
        return res;              // Step 4: Return the result of all combinations.
    }

private:
    void makeCombination(vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {   // Step 5: If we reach the target sum, we add the current combination.
            res.push_back(comb); // Add the valid combination to the result.
            return;              // Stop recursion.
        }

        if (total > target || idx >= candidates.size()) { // Step 6: If total exceeds target or index goes out of bounds, return.
            return;
        }

        comb.push_back(candidates[idx]); // Step 7: Add the current candidate to the combination.
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res); // Step 8: Continue with the same candidate.
        comb.pop_back();                  // Step 9: Backtrack by removing the last added candidate.
        makeCombination(candidates, target, idx + 1, comb, total, res); // Step 10: Try next candidate.
    }
};
```

### Line-by-Line Dry Run

We’ll use the example:

- **candidates = [2, 3, 6, 7]**
- **target = 7**

#### **Main Function: `combinationSum`**
1. **Line 1**:
   - The function `combinationSum` is called with `candidates = [2, 3, 6, 7]` and `target = 7`.

2. **Line 2**:
   - `vector<vector<int>> res` is created. This will store all the valid combinations that sum to `target`.

3. **Line 3**:
   - `vector<int> comb` is created. This is a temporary vector used to build each individual combination.
   
4. **Line 4**:
   - The recursive function `makeCombination` is called:
     - `candidates` is passed in.
     - `target` is passed in.
     - `idx = 0` is passed in, meaning we start considering candidates from the first one.
     - `comb` is passed as an empty vector.
     - `total = 0` is passed in, meaning we start with a sum of 0.
     - `res` is passed to collect valid combinations.
     
5. **Line 5**:
   - Once all valid combinations are collected, the `res` vector is returned.

---

#### **Helper Function: `makeCombination`**
This is where the recursive logic happens. The function tries to build combinations by adding candidates and checks if the sum reaches the target.

Let’s run through the **first call** to `makeCombination`.

### 1st Recursive Call: `makeCombination([2, 3, 6, 7], 7, 0, [], 0, res)`

1. **Line 8** (`total == target`):
   - At this point, `total = 0` and `target = 7`. This check fails, so we continue.

2. **Line 9** (`total > target` or `idx >= candidates.size()`):
   - Neither condition is true (`total = 0`, `idx = 0`), so we move on.

3. **Line 10** (`comb.push_back(candidates[idx])`):
   - `candidates[0] = 2`, so we push `2` into `comb`.
   - Now `comb = [2]`.

4. **Line 11** (`makeCombination`):
   - We recursively call `makeCombination` with updated values:
     - `idx` remains 0 (allowing the reuse of `2`).
     - `total` becomes `total + candidates[idx] = 0 + 2 = 2`.
     - `comb = [2]` and `res` is still empty.

---

### 2nd Recursive Call: `makeCombination([2, 3, 6, 7], 7, 0, [2], 2, res)`

1. **Line 8** (`total == target`):
   - Now `total = 2` and `target = 7`. This check fails, so we continue.

2. **Line 9** (`total > target` or `idx >= candidates.size()`):
   - Neither condition is true (`total = 2`, `idx = 0`), so we move on.

3. **Line 10** (`comb.push_back(candidates[idx])`):
   - `candidates[0] = 2`, so we push another `2` into `comb`.
   - Now `comb = [2, 2]`.

4. **Line 11** (`makeCombination`):
   - We recursively call `makeCombination` again with updated values:
     - `idx` remains 0 (we can still reuse `2`).
     - `total = 2 + 2 = 4`.
     - `comb = [2, 2]` and `res` is still empty.

---

### 3rd Recursive Call: `makeCombination([2, 3, 6, 7], 7, 0, [2, 2], 4, res)`

1. **Line 8** (`total == target`):
   - Now `total = 4` and `target = 7`. This check fails, so we continue.

2. **Line 9** (`total > target` or `idx >= candidates.size()`):
   - Neither condition is true (`total = 4`, `idx = 0`), so we move on.

3. **Line 10** (`comb.push_back(candidates[idx])`):
   - `candidates[0] = 2`, so we push another `2` into `comb`.
   - Now `comb = [2, 2, 2]`.

4. **Line 11** (`makeCombination`):
   - We recursively call `makeCombination` again:
     - `idx` remains 0 (we can still reuse `2`).
     - `total = 4 + 2 = 6`.
     - `comb = [2, 2, 2]`.

---

### 4th Recursive Call: `makeCombination([2, 3, 6, 7], 7, 0, [2, 2, 2], 6, res)`

1. **Line 8** (`total == target`):
   - Now `total = 6` and `target = 7`. This check fails, so we continue.

2. **Line 9** (`total > target` or `idx >= candidates.size()`):
   - Neither condition is true (`total = 6`, `idx = 0`), so we move on.

3. **Line 10** (`comb.push_back(candidates[idx])`):
   - `candidates[0] = 2`, so we push another `2` into `comb`.
   - Now `comb = [2, 2, 2, 2]`.

4. **Line 11** (`makeCombination`):
   - We recursively call `makeCombination`:
     - `total = 6 + 2 = 8`, which exceeds the `target`.

---

### Backtracking Begins (4th Recursive Call)

1. **Line 9** (`total > target` or `idx >= candidates.size()`):
   - Now `total = 8`, which is **greater** than `target = 7`, so this condition is **true**.
   - We return from this call (end this branch of recursion).

2. **Line 12** (`comb.pop_back()`):
   - Backtrack by removing the last element, so `comb` becomes `[2, 2, 2]`.

3. **Line 13** (`makeCombination(candidates, target, idx + 1, comb, total, res)`):
   - Try the next candidate (`idx = 1`), which is `3`.

--- 

This process continues recursively, exploring all possibilities, until we find all combinations that sum to `7`, like `[2, 2, 3]` and `[7]`.

### How this helps for future problems:
1. **Recursive exploration**: This solution explores all possible combinations by recursion. You can apply this concept to problems involving combinations, permutations, and subsets.
2. **Backtracking**: The backtracking mechanism (using `pop_back`) allows undoing choices and trying new ones. This is critical for solving problems involving exploration of solution spaces.
