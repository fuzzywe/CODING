https://leetcode.com/problems/rotate-array/

https://prepfortech.io/leetcode-solutions/rotate-array



https://www.naukri.com/code360/problems/rotate-array_1230543?interviewBundleRedirection=true&leftPanelTabValue=PROBLEM

https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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

The issue in your code is the **order of reversal steps** when performing a **left rotation** instead of a **right rotation**.  

---

### **Difference Between Left and Right Rotation**
For **right rotation**, we use:  
1. **Reverse the whole array**  
2. **Reverse the first `k` elements**  
3. **Reverse the remaining `n-k` elements**  

For **left rotation**, we use:  
1. **Reverse the first `k` elements**  
2. **Reverse the remaining `n-k` elements**  
3. **Reverse the entire array**  

---

### **Corrected Code for Left Rotation**
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where k >= n

    // Step 1: Reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: Reverse remaining n-k elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: Reverse the entire array
    reverse(arr.begin(), arr.end());

    return arr;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    vector<int> rotatedArray = rotateLeft(arr, k);

    for (int num : rotatedArray) {
        cout << num << " ";
    }
    return 0;
}
```

---

### **Step-by-Step Explanation for Left Rotation**
Let’s take **Sample Input 1** as an example:  
```
n = 8
arr = [7, 5, 2, 11, 2, 43, 1, 1]
k = 2
```

#### **Step 1: Reverse the first `k = 2` elements**
```cpp
reverse(arr.begin(), arr.begin() + k);
```
🔹 **Before:** `[7, 5, 2, 11, 2, 43, 1, 1]`  
🔹 **After reversing first 2 elements:** `[5, 7, 2, 11, 2, 43, 1, 1]`  

---

#### **Step 2: Reverse the remaining `n-k = 6` elements**
```cpp
reverse(arr.begin() + k, arr.end());
```
🔹 **Before:** `[5, 7, 2, 11, 2, 43, 1, 1]`  
🔹 **After reversing from index 2 to end:** `[5, 7, 1, 1, 43, 2, 11, 2]`  

---

#### **Step 3: Reverse the entire array**
```cpp
reverse(arr.begin(), arr.end());
```
🔹 **Before:** `[5, 7, 1, 1, 43, 2, 11, 2]`  
🔹 **After final reversal:** `[2, 11, 2, 43, 1, 1, 7, 5]` ✅  

This matches the **expected output!** 🎯  

---

### **Key Concept: Why Order of Reversal Matters?**
If we had used the **right rotation approach**:
1. **Reverse the entire array first**  
2. **Reverse first `k` elements**  
3. **Reverse remaining `n-k` elements**  

It would **not work for left rotation** because the elements would end up in the wrong positions.

---

### **Final Thoughts**
✅ **Right Rotation:**
1. Reverse entire array  
2. Reverse first `k` elements  
3. Reverse remaining `n-k` elements  

✅ **Left Rotation:**
1. Reverse first `k` elements  
2. Reverse remaining `n-k` elements  
3. Reverse entire array  
```cpp
//time: O(N), space: O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            ans[(i+k)%n] = nums[i];
        }
        
        for(int i = 0; i < n; ++i){
            nums[i] = ans[i];
        }
    }
};

```

---

### **Step-by-Step Explanation of the Code**  
This solution **rotates an array to the right by `k` steps** using an **extra array (`ans`)**.

---

### **Understanding the Problem**  
Given an array `nums` and an integer `k`, rotate the array to the **right** by `k` positions.  

#### **Example:**
**Input:**  
```cpp
nums = [1, 2, 3, 4, 5, 6, 7], k = 3
```
**Output:**  
```cpp
[5, 6, 7, 1, 2, 3, 4]
```
Each element is **shifted right** by `k` places.

---

### **Step-by-Step Execution**
#### **Step 1: Create a new array `ans` of size `n`**
```cpp
vector<int> ans(n);
```
- We create a new array `ans` of the same size as `nums`.  
- This helps store the rotated elements **without modifying the original array** immediately.  
- **Space Complexity = O(N)** because we use an extra array.

---

#### **Step 2: Place Elements at New Positions**
```cpp
for(int i = 0; i < n; ++i){
    ans[(i + k) % n] = nums[i];
}
```
🔹 **Understanding `(i + k) % n` Formula:**  
- `(i + k) % n` calculates the **new index** for `nums[i]` after rotation.  
- This ensures that when `i + k` exceeds `n`, it wraps around using modulo `% n`.  

**Example:**  
For `nums = [1, 2, 3, 4, 5, 6, 7]` and `k = 3`:

| `i` | `nums[i]` | New Index `(i + k) % n` |
|---|---|---|
| 0 | 1 | `(0 + 3) % 7 = 3` |
| 1 | 2 | `(1 + 3) % 7 = 4` |
| 2 | 3 | `(2 + 3) % 7 = 5` |
| 3 | 4 | `(3 + 3) % 7 = 6` |
| 4 | 5 | `(4 + 3) % 7 = 0` |
| 5 | 6 | `(5 + 3) % 7 = 1` |
| 6 | 7 | `(6 + 3) % 7 = 2` |

After this step, `ans` becomes:
```
[5, 6, 7, 1, 2, 3, 4]
```

---

#### **Step 3: Copy `ans` Back to `nums`**
```cpp
for(int i = 0; i < n; ++i){
    nums[i] = ans[i];
}
```
- Now, we copy elements from `ans` back to `nums`.  
- The `nums` array is modified **in-place** with the rotated values.

---

### **Time and Space Complexity**
| Complexity | Explanation |
|---|---|
| **Time Complexity: O(N)** | We iterate through the array **twice** (`O(N) + O(N) = O(N)`). |
| **Space Complexity: O(N)** | We use an extra array `ans` of size `N`. |

---

### **Alternative Approach (Optimized In-Place)**
If we want to **avoid extra space (O(1) space complexity)**, we can use the **reverse approach**:

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k >= n

        reverse(nums.begin(), nums.end());     // Reverse entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse first k elements
        reverse(nums.begin() + k, nums.end());   // Reverse remaining elements
    }
};
```

✅ **Time Complexity: O(N)**  
✅ **Space Complexity: O(1) (No extra array used)**  

---

### **Final Thoughts**
- **Your Code (Extra Array)** → **Time: O(N), Space: O(N)**
- **Optimized Approach (Reverse Method)** → **Time: O(N), Space: O(1)**
  
🔥 The **optimized approach** is preferred in interviews because it saves extra space. 🚀
