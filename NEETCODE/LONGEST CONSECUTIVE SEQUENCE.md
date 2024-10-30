128. Longest Consecutive Sequence

https://leetcode.com/problems/longest-consecutive-sequence/description/

https://www.naukri.com/code360/problems/longest-successive-elements_6811740?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse


BRUTE FORCE

![Longest Consecutive Sequence _ Google Interview Question _ Brute Better Optimal 5-11 screenshot](https://github.com/user-attachments/assets/3af5206e-d933-4ef5-b66b-37a53ca63ac6)


BETTER APPROACH 


![Longest Consecutive Sequence _ Google Interview Question _ Brute Better Optimal 7-45 screenshot](https://github.com/user-attachments/assets/e50fe097-496e-4691-a039-f8b65e029eeb)

![Longest Consecutive Sequence _ Google Interview Question _ Brute Better Optimal 8-45 screenshot](https://github.com/user-attachments/assets/c552e212-5417-413a-9491-852c0a5bb480)

the last element should be one lesser like before 3 , 2 should be present then i will increase the count and longest.



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


--- 

BETTER APPROACH

```cpp


int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}
```
Time Complexity: O(NlogN) + O(N), N = size of the given array.
Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

Space Complexity: O(1), as we are not using any extra space to solve this problem.

---


```cpp

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

```
Output: The longest consecutive sequence is 4.

Complexity Analysis

Time Complexity: O(N2), N = size of the given array.
Reason: We are using nested loops each running for approximately N times.

Space Complexity: O(1), as we are not using any extra space to solve this problem.

