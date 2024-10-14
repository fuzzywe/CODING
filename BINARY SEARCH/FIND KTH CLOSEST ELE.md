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

