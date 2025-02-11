https://leetcode.com/problems/non-decreasing-array/description/

https://www.naukri.com/code360/problems/non-decreasing-array_699920?interviewBundleRedirection=true

---

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& N) {
        for (int i = 1, err = 0; i < N.size(); i++)
            if (N[i] < N[i-1])
                if (err++ || (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1]))
                    return false;
        return true;
    }
};

```
---

```cpp

#include <bits/stdc++.h> 
bool isPossible(int *arr, int n)
{
    int err = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) { 
            if (err++ || (i > 1 && i < n - 1 && arr[i-2] > arr[i] && arr[i+1] < arr[i-1])) 
                return false;
        }
    }
    return true;
}



```
---
There are a few issues with your code. Let's go through them step by step and fix them.

---

### **Errors in Your Code**
1. ❌ **Incorrect use of `arr.size()`**
   - `arr` is a raw pointer (`int *arr`), not a `vector<int>`. 
   - Pointers do not have a `.size()` method.
   - Instead, you should use `n` (the given size of the array).

2. ❌ **Incorrect loop condition `arr.size()`**
   - Since `arr` is a pointer, `arr.size()` is invalid. The loop should iterate based on `n` instead.

3. ❌ **Index out of bounds**
   - `arr[i+1]` is accessed in `(arr[i+1] < arr[i-1])`, but what if `i == n - 1`? It will go **out of bounds**.
   - The loop condition must ensure that `i+1` is within bounds.

---

### **Fixed Code**
```cpp
#include <bits/stdc++.h> 
bool isPossible(int *arr, int n)
{
    int err = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) { 
            if (err++ || (i > 1 && i < n - 1 && arr[i-2] > arr[i] && arr[i+1] < arr[i-1])) 
                return false;
        }
    }
    return true;
}
```
---

  

---

### **What Does This Condition Mean?**
```cpp
if (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1])
```
It **checks if the array is impossible to fix** by modifying just one number.  
Let’s break it **one tiny piece at a time**.  

---

### **First, What Does `N[i]` Mean?**  
🟢 Suppose we have this array:  
```cpp
N = {3, 4, 2, 3};
```
Each element has an **index** like this:
```
Index:  0   1   2   3
Value:  3   4   2   3
```
Now, let's understand each part of the condition:

---

### **1️⃣ `i > 1`**
- We only check this condition when `i` is **at least 2**.
- This **prevents accessing `N[i-2]`** when `i = 1` (to avoid an error).

#### ✅ Example where `i > 1` is true:
If `i = 2`, then:
- `N[i-2]` means `N[0]` → **3**
- `N[i]` means `N[2]` → **2**

So `N[i-2] > N[i]` checks:
```
Is N[0] > N[2] ? → Is 3 > 2 ? ✅ Yes
```

---

### **2️⃣ `i < N.size() - 1`**
- We only check this when `i` is **before the last element**.
- This **prevents accessing `N[i+1]`** if `i` is at the last index.

For example:
- `N.size() = 4`, so `N.size() - 1 = 3`
- If `i = 2`, then:
  - `N[i+1]` is `N[3]` → **3**
  - `N[i-1]` is `N[1]` → **4**

---

### **3️⃣ `N[i-2] > N[i]`**
👉 Checks if the element **two steps before** is **bigger** than the current one.

From our example:
```
N = {3, 4, 2, 3};
```
For `i = 2`:
- `N[i-2] = N[0] = 3`
- `N[i] = N[2] = 2`

So, it checks:
```
Is N[0] > N[2] ? → Is 3 > 2 ? ✅ Yes
```

---

### **4️⃣ `N[i+1] < N[i-1]`**
👉 Checks if the **next element** is **smaller** than the one before.

For `i = 2`:
- `N[i+1] = N[3] = 3`
- `N[i-1] = N[1] = 4`

So, it checks:
```
Is N[3] < N[1] ? → Is 3 < 4 ? ✅ Yes
```

---

### **Final Meaning of the Condition**
```cpp
if (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1])
```
🔹 If **both** `N[i-2] > N[i]` and `N[i+1] < N[i-1]` are **true**, then **one change cannot fix the array** → Return `false`.  

---

### **Final Example**
```cpp
N = {3, 4, 2, 3};
```
For `i = 2`:
- `N[0] > N[2]` (3 > 2) ✅
- `N[3] < N[1]` (3 < 4) ✅
- **Since both are true, we return `false`.**

---

### **TL;DR (Too Long; Didn't Read)**
💡 **This condition checks if one fix is NOT enough.**
- It checks whether `N[i]` is too small compared to `N[i-2]`.  
- It also checks whether `N[i+1]` is too small compared to `N[i-1]`.  
- If both are **true**, **one modification won’t be enough**, so we return `false`.  



---
---

### **Fixes and Explanation**
✅ **Use `n` instead of `arr.size()`**  
   - Since `arr` is a pointer, you need to use `n` to get the size of the array.

✅ **Loop runs from `1` to `n-1`**  
   - `i = 1` ensures we have `i-1` valid.
   - `i < n` ensures `i` stays within bounds.

✅ **Proper boundary check for `arr[i+1]`**  
   - `(i < n - 1)` ensures `arr[i+1]` is within bounds.

---

### **Example Test Cases**
#### ✅ Test Case 1 (Valid case)
```cpp
int arr[] = {4, 2, 3};
int n = 3;
cout << isPossible(arr, n); // Output: true
```
- Modify `4 → 2` to make it `{2,2,3}`, which is non-decreasing.

#### ❌ Test Case 2 (Invalid case)
```cpp
int arr[] = {4, 2, 1};
int n = 3;
cout << isPossible(arr, n); // Output: false
```
- It needs **two** changes, which is not allowed.

---

Since `arr` is a **raw pointer** (`int *arr`), there is no built-in method like `.size()` to determine its size. You must rely on the **integer `n`** that is passed to the function. 

---

### **Ways to Find the Size of an Array in C++**

#### **1️⃣ If You Have a Raw Array Inside `main()`**
If you are working with a **statically allocated array** inside `main()`, you can use:
```cpp
int arr[] = {4, 2, 3};
int n = sizeof(arr) / sizeof(arr[0]);  // Gives the number of elements
```
👉 This works **only inside the same scope** where `arr` is defined.

---

#### **2️⃣ If You Are Passing an Array to a Function**
When you pass an array to a function, it **decays into a pointer** (`int *arr`), and you **cannot** use `sizeof(arr)`.  
So, you **must pass the size (`n`) explicitly**:
```cpp
bool isPossible(int *arr, int n) {
    // Use n directly since arr is a pointer
}
```
✅ This is why `n` is given in function parameters.

---

#### **3️⃣ If You Use `vector<int>` Instead**
If you can use `vector<int>` instead of a raw array, you can find its size using:
```cpp
vector<int> arr = {4, 2, 3};
int n = arr.size();  // Works with vectors
```
✅ This is safer and avoids decay issues.

---

### **Final Summary**
| Case | How to Get Size? |
|------|----------------|
| **Inside `main()` with a raw array** | `sizeof(arr) / sizeof(arr[0])` |
| **Inside a function with `int* arr`** | Must pass `n` explicitly |
| **With `vector<int>`** | Use `arr.size()` |

---

### **Example Fix**
```cpp
#include <bits/stdc++.h> 
using namespace std;

bool isPossible(int *arr, int n) {
    int err = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            if (err++ || (i > 1 && i < n - 1 && arr[i-2] > arr[i] && arr[i+1] < arr[i-1])) 
                return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);  // Get size correctly
    cout << isPossible(arr, n);  // Output: true
}
```
