https://leetcode.com/problems/find-k-closest-elements/description/

658. Find K Closest Elements
Medium
Topics
Companies
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

Complexity
Time complexity: O(log N)
Space complexity: O(N)

Sure! I'll break down each line of the code and explain it in a way that's easy to understand.
```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lft = 0, rgt = arr.size() - k;
        while (lft < rgt) {
            int mid = lft + (rgt - lft) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                lft = mid + 1;
            } else {
                rgt = mid;
            }
        }
        vector<int> sol(arr.begin() + lft, arr.begin() + lft + k);
        return sol;
    }
};
```
### Problem:
You are given a sorted array `arr`, and you need to find the `k` closest elements to a given value `x`. The "closest" means elements that have the smallest difference with `x`. If there are ties (i.e., two numbers have the same difference), we pick the smaller number. The solution uses a technique called **binary search** to efficiently solve this problem.

---

### Code Explanation and Dry Run:

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
```
- **Line:** We are creating a class `Solution` that has a public function `findClosestElements`.
- **What the function does:** The function takes three inputs:
  - `arr`: A sorted array of integers.
  - `k`: The number of closest elements to `x` that we want to find.
  - `x`: The value we want to find the closest elements to.

---

```cpp
int lft = 0, rgt = arr.size() - k;
```
- **Line:** This initializes two variables, `lft` and `rgt`:
  - `lft` starts at `0`, which means the left end of the array.
  - `rgt` starts at `arr.size() - k`, which means the right end of the array, but **`k` elements before the end**. This is because we are searching for a block of `k` elements.

---

```cpp
while (lft < rgt) {
```
- **Line:** This starts a **loop** that will run until `lft` and `rgt` meet. The loop helps us **narrow down the window** (the block of `k` elements) where the closest numbers to `x` are located.

---

```cpp
int mid = lft + (rgt - lft) / 2;
```
- **Line:** This calculates the middle point (`mid`) between `lft` and `rgt`. This is done using the formula:
  - `mid = lft + (rgt - lft) / 2`  
  - The **`(rgt - lft) / 2`** part ensures we're dividing the range between `lft` and `rgt` in half, so we get the middle position. This is a common formula used in **binary search**.

---

```cpp
if (x - arr[mid] > arr[mid + k] - x) {
```
- **Line:** This checks which side of the middle (`mid`) is **closer to `x`**.
  - **`x - arr[mid]`**: This calculates how far `arr[mid]` is from `x`. If this value is large, it means `arr[mid]` is far from `x`.
  - **`arr[mid + k] - x`**: This calculates how far the element `k` positions ahead of `mid` (`arr[mid + k]`) is from `x`.
  - If **`x - arr[mid] > arr[mid + k] - x`**, it means the elements to the right of `mid` are closer to `x` than those on the left.

---

```cpp
lft = mid + 1;
```
- **Line:** If the elements to the right of `mid` are closer to `x`, we **move the left pointer** `lft` to the right by updating it to `mid + 1`. This means we ignore the elements before `mid` and look at the ones on the right.

---

```cpp
} else {
    rgt = mid;
}
```
- **Line:** If the elements to the left of or at `mid` are closer to `x`, we **move the right pointer** `rgt` to `mid`. This means we ignore the elements after `mid` and focus on the left side.

---

```cpp
}
```
- **Line:** This ends the `while` loop. By the time the loop finishes, the `lft` pointer will point to the starting index of the `k` closest elements.

---

```cpp
vector<int> sol(arr.begin() + lft, arr.begin() + lft + k);
```
- **Line:** After the loop, we create a vector `sol` which stores the `k` closest elements. We do this by **slicing the array** from `arr[lft]` to `arr[lft + k]`.
  - `arr.begin() + lft`: This gives the position of the element at index `lft`.
  - `arr.begin() + lft + k`: This gives the position `k` elements after `lft`.

---

```cpp
return sol;
```
- **Line:** Finally, we return the result stored in the `sol` vector, which contains the `k` closest elements to `x`.

---

### Dry Run Example

Let's dry run this code with an example:

```cpp
arr = [1, 2, 3, 4, 5]
k = 2
x = 3
```

1. **Initialization:**
   - `lft = 0` and `rgt = arr.size() - k = 5 - 2 = 3`
   - So, `lft = 0` and `rgt = 3`.

2. **First iteration of the `while` loop:**
   - Calculate `mid = 0 + (3 - 0) / 2 = 1`.
   - Check the condition: `x - arr[mid] = 3 - arr[1] = 3 - 2 = 1`.
   - Check `arr[mid + k] - x = arr[1 + 2] - 3 = arr[3] - 3 = 4 - 3 = 1`.
   - Since `1 <= 1`, move `rgt = mid = 1`.

3. **Second iteration of the `while` loop:**
   - Calculate `mid = 0 + (1 - 0) / 2 = 0`.
   - Check the condition: `x - arr[mid] = 3 - arr[0] = 3 - 1 = 2`.
   - Check `arr[mid + k] - x = arr[0 + 2] - 3 = arr[2] - 3 = 3 - 3 = 0`.
   - Since `2 > 0`, move `lft = mid + 1 = 1`.

4. **End of the loop:**
   - Now `lft = 1` and `rgt = 1`, so the loop ends.

5. **Final step:**
   - We create `sol` from `arr.begin() + lft` to `arr.begin() + lft + k`, which is from `arr[1]` to `arr[1 + 2]`:
   - So, `sol = [2, 3]`.

### Final Output:
The closest 2 elements to `3` are `[2, 3]`.

---

### Summary:
- The code uses **binary search** to find the starting position of the `k` closest elements.
- The goal is to narrow down a "window" in the array where the `k` closest elements to `x` are located.
- The formula `mid = lft + (rgt - lft) / 2` helps us efficiently divide the search space into halves, which speeds up the process.

Let’s break down the process visually to help understand how the algorithm works. I'll use an example and a step-by-step visualization to explain the logic of the binary search approach.

---

### Problem Recap:

You are given a sorted array `arr`, and you need to find `k` closest elements to a target `x`. The code uses **binary search** to efficiently find the starting position of the `k` elements.

Let's consider this example:
```cpp
arr = [1, 2, 3, 4, 5]
k = 2
x = 3
```
We want to find **2 closest elements** to `3` in the sorted array `[1, 2, 3, 4, 5]`.

---

Let’s go through the updated scenario where the result would be `[1, 2, 3, 4]`. Here's the corrected explanation using an example that matches this output.

---

### Problem Recap:

You are given a sorted array `arr`, and you need to find `k` closest elements to a target `x`. The code uses **binary search** to efficiently find the starting position of the `k` elements.

Let’s use this example for clarity:
```cpp
arr = [1, 2, 3, 4, 5]
k = 4
x = 3
```

We need to find the **4 closest elements** to `3` in the sorted array `[1, 2, 3, 4, 5]`.

---

### Step-by-Step Dry Run:

The binary search helps find the starting index of the window of `k` closest elements.

#### 1. Initial Setup:
- `lft = 0` (the left pointer starts at index `0`).
- `rgt = arr.size() - k = 5 - 4 = 1` (the right pointer starts at index `1`, which leaves a window of size `k = 4`).

```
arr = [1, 2, 3, 4, 5]
        ^     ^
       lft   rgt
```
- `lft` starts at index `0`, and `rgt` starts at index `1` because we need a window of size `4`.

#### 2. First Iteration of the `while` Loop:
We calculate the middle of the current range (`mid`) using:
```cpp
mid = lft + (rgt - lft) / 2
```
In this case:
```cpp
mid = 0 + (1 - 0) / 2 = 0
```
Now, `mid` points to index `0` in the array (`arr[0] = 1`):

```
arr = [1, 2, 3, 4, 5]
     ^     ^
    mid   rgt
```

Next, we check which side is closer to `x` using:
```cpp
if (x - arr[mid] > arr[mid + k] - x)
```
In this case:
```cpp
x - arr[0] = 3 - 1 = 2
arr[0 + 4] - x = arr[4] - 3 = 5 - 3 = 2
```
Since both differences are equal (`2`), we move the `rgt` pointer to `mid`:
```cpp
rgt = mid = 0
```

Now `lft` and `rgt` both point to index `0`:
```
arr = [1, 2, 3, 4, 5]
     ^
    lft
    rgt
```

#### 3. End of the Loop:
At this point, `lft = rgt`, so the `while` loop terminates.

#### 4. Final Step:
We now know that the starting index of the `k` closest elements is `lft = 0`. We can slice the array from index `lft` to `lft + k`:
```cpp
vector<int> sol(arr.begin() + lft, arr.begin() + lft + k);
```
This gives us the subarray `[1, 2, 3, 4]`.

---

### Visual Summary:

1. **Initial state:**
   ```
   arr = [1, 2, 3, 4, 5]
          ^     ^
         lft   rgt
   ```

2. **First iteration:**
   ```
   arr = [1, 2, 3, 4, 5]
       ^     ^
      mid   rgt
   rgt = mid (moved left)
   ```

3. **End of loop:**
   ```
   arr = [1, 2, 3, 4, 5]
       ^
      lft
      rgt
   ```

4. **Result:**
   ```
   sol = [1, 2, 3, 4]
   ```

---

### Formula Explanation:

The key formula used in this code is:
```cpp
if (x - arr[mid] > arr[mid + k] - x)
```
- **`x - arr[mid]`**: This calculates how far `arr[mid]` is from `x` (how close the current middle element is to the target).
- **`arr[mid + k] - x`**: This calculates how far the element `k` positions ahead of `mid` is from `x`.

By comparing these two values, the algorithm determines which side (left or right) has elements closer to `x`. If the left side is closer, the window moves left. If the right side is closer, the window moves right.

This way, we find the starting point for the window of size `k` that contains the closest elements to `x`.

The binary search approach used in your code is already highly optimized for this problem, with a time complexity of **O(log(n - k) + k)**:

- The **binary search** part has a time complexity of **O(log(n - k))**, where `n` is the size of the array, and `k` is the number of closest elements.
- The **slicing of the array** to get the result has a time complexity of **O(k)**.

This is efficient because the binary search narrows down the range of `k` closest elements in logarithmic time, and then the slicing only involves copying the `k` elements.

However, if you want an alternative solution or a slight improvement for readability, you can consider this **two-pointer approach**. It's also efficient but may not be as fast as binary search in certain cases.

### Two-pointer Approach:
```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lft = 0;
        int rgt = arr.size() - 1;

        // Shrink the window from both sides until the window size is `k`
        while (rgt - lft >= k) {
            if (abs(arr[lft] - x) > abs(arr[rgt] - x)) {
                lft++;  // If the left element is farther from `x`, move the left pointer
            } else {
                rgt--;  // If the right element is farther from `x`, move the right pointer
            }
        }

        // Return the `k` closest elements in the window
        return vector<int>(arr.begin() + lft, arr.begin() + lft + k);
    }
};
```

### Explanation:

1. **Two pointers (`lft` and `rgt`)**: The left pointer starts at `0` and the right pointer starts at `n - 1`.
2. **Shrink the window**: We shrink the window from both ends until the window size is `k`. We compare the distance of the current elements from `x`:
   - If the element at `lft` is farther from `x` than the element at `rgt`, we increment `lft`.
   - If the element at `rgt` is farther from `x`, we decrement `rgt`.
3. **Stop when window size becomes `k`**: When the difference between `rgt` and `lft` becomes `k`, we stop.
4. **Return the result**: The `k` closest elements are in the range `[lft, lft + k)`.

### Time Complexity:
- **O(n)** in the worst case, where `n` is the size of the array, because we may end up moving both pointers across the entire array.
- This approach is not better than the binary search solution but might be easier to understand.

---

### Why Binary Search is Better:
- The **binary search** approach is more optimal, especially for large input sizes, because it reduces the search space logarithmically.
- The **two-pointer** approach is simple but can become less efficient when the array size `n` is large.

So, the binary search solution you already have is considered the most optimized solution for this problem.
