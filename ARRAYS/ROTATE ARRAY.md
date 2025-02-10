https://leetcode.com/problems/rotate-array/


Approach
Reverse the entire array to bring the last k elements to the front (but in reverse order).
Reverse the first k elements to restore their correct order.
Reverse the remaining n-k elements to place them correctly.
This effectively shifts elements in O(n) time with O(1) space.

Explanation:
Example:
📌 Input: nums = [1,2,3,4,5,6,7], k = 3

1️⃣ Reverse the entire array:
Before: [1, 2, 3, 4, 5, 6, 7]
After: [7, 6, 5, 4, 3, 2, 1]

2️⃣ Reverse the first k elements (k = 3):
Before: [7, 6, 5, 4, 3, 2, 1]
After: [5, 6, 7, 4, 3, 2, 1]

3️⃣ Reverse the remaining n-k elements (n-k = 4):
Before: [5, 6, 7, 4, 3, 2, 1]
After: [5, 6, 7, 1, 2, 3, 4] ✅ (Correctly rotated)

Complexity
Time complexity: O(n) (Each reversal operation runs in O(n))
Space complexity: O(1) (In-place modification, no extra space used)
Code
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k >= n

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining n-k elements
    reverse(nums.begin() + k, nums.end());
        
    }
};

```

Here’s a **step-by-step explanation** of the **Rotate Array** function in C++ using the **Reversal Algorithm**, so you can **explain it impressively in an interview**:

---

### **Understanding the Problem**
🔹 **Given:** An array `nums[]` and an integer `k`  
🔹 **Task:** Rotate the array to the **right** by `k` positions  
🔹 **Example:**
   ```cpp
   Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
   Output: [5, 6, 7, 1, 2, 3, 4]
   ```

---

## **Step-by-Step Breakdown of the Code**
```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k >= n
```
🔹 **Why `k = k % n`?**  
- If `k` is greater than the array size `n`, rotating `n` times results in the same array.  
- Example: Rotating `[1, 2, 3, 4, 5]` **5 times** gives back `[1, 2, 3, 4, 5]`.  
- So, we only rotate `k % n` times.  
  - If `n = 7` and `k = 10`, we actually rotate `10 % 7 = 3` times.

---

### **Step 1: Reverse the Entire Array**
```cpp
reverse(nums.begin(), nums.end());
```
🔹 **Before reversal:** `[1, 2, 3, 4, 5, 6, 7]`  
🔹 **After reversal:** `[7, 6, 5, 4, 3, 2, 1]`  
✅ This prepares the elements for correct rotation.

---

### **Step 2: Reverse the First `k` Elements**
```cpp
reverse(nums.begin(), nums.begin() + k);
```
🔹 **Reversing the first `k = 3` elements:**  
- **Before reversal:** `[7, 6, 5, 4, 3, 2, 1]`  
- **After reversal:** `[5, 6, 7, 4, 3, 2, 1]`

---

### **Step 3: Reverse the Remaining `n-k` Elements**
```cpp
reverse(nums.begin() + k, nums.end());
```
🔹 **Reversing elements from index `k` to `n`:**  
- **Before reversal:** `[5, 6, 7, 4, 3, 2, 1]`  
- **After reversal:** `[5, 6, 7, 1, 2, 3, 4]`

✅ **Final output:** `[5, 6, 7, 1, 2, 3, 4]` (which is the rotated array)

---

### **Time Complexity Analysis**
- **Each reversal takes `O(n)` time.**
- **Total complexity: `O(n) + O(k) + O(n-k) = O(n)`.**
- ✅ **Efficient solution compared to brute force `O(n*k)`.**

---

## **Interview Explanation Template**
If asked in an interview, you can explain like this:
> **"We use the **Reversal Algorithm** to rotate the array in-place efficiently.  
> Instead of shifting elements one by one, we take advantage of reversing sections of the array.  
> We first reverse the entire array, then reverse the first `k` elements, and finally reverse the remaining elements.  
> This ensures that the order is correctly restored while achieving the rotation in `O(n)` time, making it much more efficient than shifting each element `O(n*k)` times."**

🔥 **This explanation is short, clear, and impressive!**  

Would you like a **dry run for different cases?** 🚀
