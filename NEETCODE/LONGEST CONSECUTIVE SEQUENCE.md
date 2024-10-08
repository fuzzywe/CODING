128. Longest Consecutive Sequence
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 ```cpp
Time complexity: O(n)
Space complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
```
Let's walk through the `longestConsecutive` function to explain each line of code in detail and perform a dry run example.

### Code Breakdown:

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
```

### Line-by-Line Explanation:

#### 1. `unordered_set<int> numSet(nums.begin(), nums.end());`
- **Purpose**: Creates an unordered set (`numSet`) containing all the unique elements from the input vector `nums`.
  - **Reason**: Unordered sets provide **O(1)** average time complexity for lookups, making it efficient to check for consecutive numbers.
- **Example**: If `nums = [100, 4, 200, 1, 3, 2]`, then `numSet = {100, 4, 200, 1, 3, 2}`.

#### 2. `int longest = 0;`
- **Purpose**: Initializes a variable `longest` to track the length of the longest consecutive sequence found so far.

#### 3. `for (int num : nums)`
- **Purpose**: Iterates over each number (`num`) in the input array `nums`.
- **Example**: For the input `nums = [100, 4, 200, 1, 3, 2]`, the loop will go through the elements `100, 4, 200, 1, 3, 2` one by one.

#### 4. `if (numSet.find(num - 1) == numSet.end())`
- **Purpose**: Checks if `num - 1` exists in the set (`numSet`).
  - **Reason**: If `num - 1` is not found in the set, it means `num` is the **start of a new sequence**. Otherwise, `num` is part of a sequence that already started with `num - 1`, so we can skip it.
- **Example**: For `num = 1`, `num - 1 = 0` is not in the set, so we treat `1` as the start of a new sequence.

#### 5. `int length = 1;`
- **Purpose**: Initializes a variable `length` to track the length of the current consecutive sequence. Since we have already identified `num` as the start of the sequence, the length starts at 1.

#### 6. `while (numSet.find(num + length) != numSet.end())`
- **Purpose**: This loop checks for the next number in the sequence, i.e., `num + length`. If the next consecutive number exists in the set, it increments the `length` of the sequence.
  - **Example**: If `num = 1`, the loop checks for `2, 3, 4`, and increments `length` accordingly.

#### 7. `length++;`
- **Purpose**: If the next consecutive number is found, increase the length of the current sequence.

#### 8. `longest = max(longest, length);`
- **Purpose**: After finding the length of the current sequence, update `longest` to the maximum of the current value of `longest` and `length`.
  - **Example**: If the current sequence is `[1, 2, 3, 4]`, then `length = 4`. If `longest` was previously 0, it will now be updated to 4.

#### 9. `return longest;`
- **Purpose**: Returns the length of the longest consecutive sequence found.

---

### Dry Run Example:

Let's take the input `nums = [100, 4, 200, 1, 3, 2]` and go through the function step by step.

1. **Initialization**:
   - `numSet = {100, 4, 200, 1, 3, 2}` (unordered set with unique elements).
   - `longest = 0`.

2. **First iteration (`num = 100`)**:
   - `num - 1 = 99` is **not** in `numSet`, so 100 is the start of a new sequence.
   - `length = 1`.
   - Check for `num + 1 = 101`, which is not in the set, so the sequence ends here.
   - Update `longest = max(0, 1) = 1`.

3. **Second iteration (`num = 4`)**:
   - `num - 1 = 3` is in the set, so `4` is **not** the start of a new sequence. Skip this number.

4. **Third iteration (`num = 200`)**:
   - `num - 1 = 199` is **not** in the set, so `200` is the start of a new sequence.
   - `length = 1`.
   - Check for `num + 1 = 201`, which is not in the set, so the sequence ends here.
   - Update `longest = max(1, 1) = 1`.

5. **Fourth iteration (`num = 1`)**:
   - `num - 1 = 0` is **not** in the set, so `1` is the start of a new sequence.
   - `length = 1`.
   - Check for `num + 1 = 2`, `num + 2 = 3`, and `num + 3 = 4`, all of which are in the set. This forms the sequence `[1, 2, 3, 4]`.
   - `length = 4`.
   - Update `longest = max(1, 4) = 4`.

6. **Fifth iteration (`num = 3`)**:
   - `num - 1 = 2` is in the set, so `3` is not the start of a new sequence. Skip this number.

7. **Sixth iteration (`num = 2`)**:
   - `num - 1 = 1` is in the set, so `2` is not the start of a new sequence. Skip this number.

8. **Final result**:
   - Return `longest = 4` as the length of the longest consecutive sequence.

### Final Answer:

For the input `nums = [100, 4, 200, 1, 3, 2]`, the longest consecutive sequence is `[1, 2, 3, 4]`, and the function returns `4`.
