1899. Merge Triplets to Form Target Triplet
Medium
Topics
Companies
Hint
A triplet is an array of three integers. You are given a 2D integer array triplets, where triplets[i] = [ai, bi, ci] describes the ith triplet. You are also given an integer array target = [x, y, z] that describes the triplet you want to obtain.

To obtain target, you may apply the following operation on triplets any number of times (possibly zero):

Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be updated to [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

 

Example 1:

Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.
Example 2:

Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.
Example 3:

Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],[5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)] = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
- Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],[5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
The target triplet [5,5,5] is now an element of triplets.

code:
```
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first =0,second=0,third=0;
        for(auto tr:triplets)
        {
            if (tr[0] ==target[0] && tr[1] <=target[1] && tr[2] <=target[2]) first = 1;
            if (tr[0] <=target[0] && tr[1] ==target[1] && tr[2] <=target[2]) second = 1;
            if (tr[0] <=target[0] && tr[1] <=target[1] && tr[2] ==target[2]) third = 1;
        }return first && second && third;
    }
};
```

Let's break down the code step by step and perform a dry run to understand how it works.

### Problem Context:
The problem is about determining whether we can merge certain triplets (from a list of triplets) to form a target triplet. A triplet is a set of three values, and the goal is to check if there are triplets from the list that, when combined, match the target triplet. The combination happens by selecting values from multiple triplets, but from each triplet, only one value from each position (index 0, 1, or 2) is selected.

### Code Explanation:

```cpp
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Step 1: Initialize three variables to track if the target can be achieved.
        int first = 0, second = 0, third = 0;
        
        // Step 2: Iterate over each triplet in the triplets array.
        for(auto tr: triplets) {
            // Step 3: Check if the current triplet matches the first condition of the target.
            // The first element must be equal to the target's first element,
            // and the second and third elements must be less than or equal to the target's corresponding elements.
            if (tr[0] == target[0] && tr[1] <= target[1] && tr[2] <= target[2]) 
                first = 1;

            // Step 4: Check if the current triplet matches the second condition of the target.
            // The second element must be equal to the target's second element,
            // and the first and third elements must be less than or equal to the target's corresponding elements.
            if (tr[0] <= target[0] && tr[1] == target[1] && tr[2] <= target[2]) 
                second = 1;

            // Step 5: Check if the current triplet matches the third condition of the target.
            // The third element must be equal to the target's third element,
            // and the first and second elements must be less than or equal to the target's corresponding elements.
            if (tr[0] <= target[0] && tr[1] <= target[1] && tr[2] == target[2]) 
                third = 1;
        }
        
        // Step 6: Return true if all three conditions have been met (i.e., first, second, and third are all 1).
        return first && second && third;
    }
};
```

### Key Concepts:
- The `target` triplet has three elements: `target[0]`, `target[1]`, and `target[2]`.
- For the function to return `true`, it needs to find at least one triplet in `triplets` that matches each of the following conditions:
  - There is a triplet where the first element matches `target[0]`, and the other two elements are less than or equal to the target's corresponding elements.
  - There is a triplet where the second element matches `target[1]`, and the other two elements are less than or equal to the target's corresponding elements.
  - There is a triplet where the third element matches `target[2]`, and the other two elements are less than or equal to the target's corresponding elements.

- If we can find triplets that satisfy all three conditions, we can "merge" them to form the `target` triplet.

### Dry Run Example:

Let's dry-run the code with an example.

```cpp
triplets = [[2, 5, 3], [1, 8, 4], [2, 6, 3]]
target = [2, 5, 3]
```

1. **Initial State:**
   - `first = 0`, `second = 0`, `third = 0`.

2. **First Triplet: [2, 5, 3]**
   - **First Condition:**
     - `tr[0] == target[0]` → `2 == 2` (True)
     - `tr[1] <= target[1]` → `5 <= 5` (True)
     - `tr[2] <= target[2]` → `3 <= 3` (True)
     - Since all are true, `first = 1`.

   - **Second Condition:**
     - `tr[1] == target[1]` → `5 == 5` (True)
     - `tr[0] <= target[0]` → `2 <= 2` (True)
     - `tr[2] <= target[2]` → `3 <= 3` (True)
     - Since all are true, `second = 1`.

   - **Third Condition:**
     - `tr[2] == target[2]` → `3 == 3` (True)
     - `tr[0] <= target[0]` → `2 <= 2` (True)
     - `tr[1] <= target[1]` → `5 <= 5` (True)
     - Since all are true, `third = 1`.

   After this triplet, we have `first = 1`, `second = 1`, and `third = 1`.

3. **Second Triplet: [1, 8, 4]**
   - **First Condition:**
     - `tr[0] == target[0]` → `1 == 2` (False), so no update to `first`.

   - **Second Condition:**
     - `tr[1] == target[1]` → `8 == 5` (False), so no update to `second`.

   - **Third Condition:**
     - `tr[2] == target[2]` → `4 == 3` (False), so no update to `third`.

4. **Third Triplet: [2, 6, 3]**
   - **First Condition:**
     - `tr[0] == target[0]` → `2 == 2` (True)
     - `tr[1] <= target[1]` → `6 <= 5` (False), so no update to `first`.

   - **Second Condition:**
     - `tr[1] == target[1]` → `6 == 5` (False), so no update to `second`.

   - **Third Condition:**
     - `tr[2] == target[2]` → `3 == 3` (True)
     - `tr[0] <= target[0]` → `2 <= 2` (True)
     - `tr[1] <= target[1]` → `6 <= 5` (False), so no update to `third`.

### Conclusion:
At the end of the loop, we have:
- `first = 1`, `second = 1`, `third = 1`.

Since `first && second && third` is `true`, the function will return `true`, meaning it is possible to merge triplets to form the `target`.

### Summary of What the Code Does:
- It checks if there are triplets in the input that can provide values to match each of the target's three positions.
- It uses three flags (`first`, `second`, `third`) to track if each part of the target can be achieved by the available triplets.
- If all three flags are set to `1` by the end of the loop, the function returns `true`, indicating that the target triplet can be formed.
