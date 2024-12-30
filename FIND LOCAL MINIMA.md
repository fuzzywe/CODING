https://www.naukri.com/code360/problems/indices-of-all-local-minima-and-local-maxima_873365?leftPanelTabValue=PROBLEM


Finding a **local minima** in an array means finding an element such that it is smaller than both its neighbors. Here's a **C++ solution** to find a local minima in an array, followed by the **time complexity** and **space complexity**.

### **Approach**:
- A local minima is defined as an element that is smaller than its adjacent elements.
- For the boundary elements (first and last), only one neighbor needs to be considered.
- We'll use a binary search approach, as this can help us find the local minima in **O(log n)** time.

### **Code: Local Minima using Binary Search**

```cpp
#include <iostream>
using namespace std;

// Function to find a local minima in the array
int findLocalMinima(int arr[], int low, int high, int n) {
    // Find the mid index
    int mid = low + (high - low) / 2;

    // Check if the mid element is a local minima
    if ((mid == 0 || arr[mid - 1] > arr[mid]) && 
        (mid == n - 1 || arr[mid + 1] > arr[mid])) {
        return mid;
    }

    // If the left neighbor is smaller, move to the left half
    else if (mid > 0 && arr[mid - 1] < arr[mid]) {
        return findLocalMinima(arr, low, mid - 1, n);
    }

    // If the right neighbor is smaller, move to the right half
    return findLocalMinima(arr, mid + 1, high, n);
}

int main() {
    int arr[] = {9, 6, 3, 14, 5, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = findLocalMinima(arr, 0, n - 1, n);
    cout << "Local minima found at index: " << index << ", value: " << arr[index] << endl;
    return 0;
}
```



### **Time Complexity**:
- **Binary Search**: At each step, the size of the problem is reduced by half.
- Hence, the **time complexity** is **O(log n)**.

### **Space Complexity**:
- **Recursive Stack**: Since binary search is used recursively, the depth of the recursive call stack is **log n**.
- Hence, the **space complexity** is **O(log n)** due to the recursive function call stack.

Let me break down the formula for you:

### Context:
The formula is used in the context of finding a **local minima** in an array. A local minima is an element that is smaller than both of its neighbors. For the array element at index `mid`, the conditions and logic aim to determine:
1. If the element at `mid` is a local minima.
2. If not, whether to search for the local minima in the left or right half of the array.

---

### **Condition 1: Checking if `mid` is a local minima**
```cpp
if ((mid == 0 || arr[mid - 1] > arr[mid]) && 
    (mid == n - 1 || arr[mid + 1] > arr[mid])) {
    return mid;
}
```

- `(mid == 0 || arr[mid - 1] > arr[mid])`:  
  - If `mid == 0`: This means `mid` is the first element of the array, so it has no left neighbor. In this case, the condition is true.
  - Otherwise (`mid != 0`), the condition `arr[mid - 1] > arr[mid]` checks if the left neighbor is greater than the element at `mid`.

- `(mid == n - 1 || arr[mid + 1] > arr[mid])`:  
  - If `mid == n - 1`: This means `mid` is the last element of the array, so it has no right neighbor. In this case, the condition is true.
  - Otherwise (`mid != n - 1`), the condition `arr[mid + 1] > arr[mid]` checks if the right neighbor is greater than the element at `mid`.

If both conditions are true, then the element at `mid` is smaller than both of its neighbors (or it has no neighbors). In this case, `mid` is returned as the index of the local minima.

---

### **Condition 2: If the left neighbor is smaller**
```cpp
else if (mid > 0 && arr[mid - 1] < arr[mid]) {
    return findLocalMinima(arr, low, mid - 1, n);
}
```

- `mid > 0`: Ensures that `mid` is not the first element, so the left neighbor exists.
- `arr[mid - 1] < arr[mid]`: This checks if the left neighbor is smaller than the element at `mid`.  
If this condition is true, the local minima must lie in the **left half** of the array (from `low` to `mid - 1`), because:
  - The array has at least one local minima (proven mathematically), and a smaller element on the left implies the potential presence of a local minima in that direction.

The function then recursively searches in the left half.

---

### **Condition 3: Otherwise, search the right half**
If neither of the above conditions is true, it implies:
- The element at `mid` is not a local minima.
- The right neighbor (`arr[mid + 1]`) is smaller than `mid`.  

This means the local minima must be in the **right half** of the array, and the function will recurse there:
```cpp
else {
    return findLocalMinima(arr, mid + 1, high, n);
}
```

---

### Recap:
1. **Condition 1**: If `mid` satisfies the local minima conditions, return `mid`.
2. **Condition 2**: If the left neighbor is smaller, search in the left half.
3. **Condition 3**: Otherwise, search in the right half.

This approach uses **binary search** to find a local minima efficiently in \(O(\log n)\) time.

### **Optimized Solution: Binary Search for Local Minima**

#### **Approach:**
- A **local minima** is defined as an element that is smaller than both of its adjacent elements.
- If an element at position `mid` is greater than its left neighbor, a local minima must exist on the left side.
- Similarly, if the element at `mid` is greater than its right neighbor, a local minima must exist on the right side.
- We can apply **binary search** to recursively divide the array in half until we find a local minima.

#### **Code:**

```cpp
#include <iostream>
using namespace std;

// Function to find a local minima using binary search
int findLocalMinima(int arr[], int low, int high, int n) {
    // Base condition: if the search space is reduced to a single element
    if (low == high)
        return low;

    int mid = low + (high - low) / 2;

    // Check if mid is a local minima
    if ((mid == 0 || arr[mid - 1] > arr[mid]) && (mid == n - 1 || arr[mid + 1] > arr[mid]))
        return mid;

    // If the left neighbor is smaller, search in the left half
    if (mid > 0 && arr[mid - 1] < arr[mid])
        return findLocalMinima(arr, low, mid - 1, n);

    // Otherwise, search in the right half
    return findLocalMinima(arr, mid + 1, high, n);
}

int main() {
    int arr[] = {9, 6, 3, 14, 5, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = findLocalMinima(arr, 0, n - 1, n);
    cout << "Local minima found at index: " << index << ", value: " << arr[index] << endl;
    return 0;
}
```

#### **Explanation:**
- **Input Array:** `{9, 6, 3, 14, 5, 7, 4}`
- In the code, we use binary search to find the local minima:
  - We first check the middle element. If it is smaller than its neighbors, we have found the local minima.
  - If the middle element is not a local minima, we check which side of the array has a smaller neighbor and search in that half.
  
- **Example Walkthrough:**
  - Array: `{9, 6, 3, 14, 5, 7, 4}`
  - **Step 1:** Start with `low = 0`, `high = 6`, and calculate `mid = 3`. The element at index 3 is `14`.
  - **Step 2:** Since `14 > 3` (left neighbor), the local minima must be in the left half, so we now search in the range `[0, 2]`.
  - **Step 3:** Calculate `mid = 1`. The element at index 1 is `6`. Since `6 > 3` (right neighbor), we now search in the right half `[2, 2]`.
  - **Step 4:** Now, `low == high == 2`, meaning we have found the local minima, which is `3`.

#### **Example Output:**

```
Local minima found at index: 2, value: 3
```

#### **Time Complexity:**
- **Binary Search**: At each step, we divide the array in half, so the time complexity is **O(log n)**.
  
#### **Space Complexity:**
- **Recursive Stack**: The space complexity is **O(log n)** due to the recursive calls used in binary search. If you use an iterative version, space complexity would be **O(1)**.

### **Optimized Explanation:**
- **Efficiency**: The binary search approach is highly efficient because it reduces the number of comparisons needed by half at each step, unlike a linear search, which checks every element.
  
#### **Example for Understanding:**
Consider an array like `{10, 8, 6, 7, 9}`.
- The array has a local minima at index 2 (`6`), as it is smaller than both its neighbors `8` and `7`.


---
find both maxi and minima 

Sample Input 1 :
2
3
-10 0 -10
2
4 -2
Sample Output 1 :
0 2
1 
1
0
Explanation for sample 1:
For the first test case, the element at index 1 is greater than its neighbours (element at index 0, and 2), thus it is the local maxima, and the elements at index 0 and index 2 are corner elements and also smaller than their one neighbours, thus they are the local minima.

For the second test case, the element at index 0 is the corner element and also greater than its one neighbour, thus it is local maxima, and the element at index 1 is also the corner element and also smaller than its one neighbour thus it is local minima.
Sample Input 2 :
2
7
10 5 20 30 40 35 50
3
1 2 2
Sample Output 2 :
1 5
0 4 6
0
-1  


```cpp

#include <bits/stdc++.h>
vector<vector<int>> findLocalMinimaAndMaxima(int *arr, int n) {
  // Write your code here

  vector<int> maxi, mini;
  if (arr[0] > arr[1])
    maxi.push_back(0);
  if (arr[0] < arr[1])
    mini.push_back(0);

  for (int i = 1; i < n - 1; i++)
{
	if(arr[i]<arr[i-1] && arr[i] <arr[i+1]) mini.push_back(i);
	if(arr[i]>arr[i-1]&& arr[i]>arr[i+1]) maxi.push_back(i);
}
if(arr[n-1]>arr[n-2]) maxi.push_back(n-1);
if(arr[n-1]<arr[n-2]) mini.push_back(n-1);
if(maxi.size()==0)maxi.push_back(-1);
if(mini.size()==0) mini.push_back(-1);
vector<vector<int>>ans = {mini,maxi};
return ans;
}

```

- 
Your code aims to find both local minima and maxima in an array, and it does a good job. Let me provide a step-by-step explanation of what it does and verify its correctness.

---

### **Logic Breakdown**

1. **Initialization**:
   ```cpp
   vector<int> maxi, mini;
   ```
   - `maxi`: To store the indices of local maxima.
   - `mini`: To store the indices of local minima.

2. **Check the first element**:
   ```cpp
   if (arr[0] > arr[1])
       maxi.push_back(0);
   if (arr[0] < arr[1])
       mini.push_back(0);
   ```
   - Since the first element only has one neighbor (`arr[1]`), check whether it's greater (local maxima) or smaller (local minima) than its neighbor.

3. **Iterate through the middle elements**:
   ```cpp
   for (int i = 1; i < n - 1; i++) {
       if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
           mini.push_back(i);
       if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
           maxi.push_back(i);
   }
   ```
   - For each element from index `1` to `n - 2`:
     - If the current element is smaller than both its neighbors, it's a local minima.
     - If it's larger than both its neighbors, it's a local maxima.
   - Add the index of the element to the respective vector.

4. **Check the last element**:
   ```cpp
   if (arr[n - 1] > arr[n - 2])
       maxi.push_back(n - 1);
   if (arr[n - 1] < arr[n - 2])
       mini.push_back(n - 1);
   ```
   - Like the first element, the last element only has one neighbor (`arr[n - 2]`). Check if it's greater (local maxima) or smaller (local minima).

5. **Handle edge cases where no local minima or maxima are found**:
   ```cpp
   if (maxi.size() == 0)
       maxi.push_back(-1);
   if (mini.size() == 0)
       mini.push_back(-1);
   ```
   - If no local minima or maxima are found, store `-1` as a placeholder.

6. **Combine the results**:
   ```cpp
   vector<vector<int>> ans = {mini, maxi};
   return ans;
   ```
   - Return the results as a 2D vector where the first row contains the indices of local minima and the second row contains the indices of local maxima.

---

### **Edge Cases to Consider**
1. **Single element array (`n == 1`)**:
   - Both minima and maxima are undefined.
   - You might need to handle this case explicitly, as accessing `arr[1]` or `arr[-1]` would cause an out-of-bounds error.

2. **Strictly increasing or decreasing arrays**:
   - In a strictly increasing array, only the last element is a maxima, and the first element is a minima.
   - In a strictly decreasing array, only the first element is a maxima, and the last element is a minima.

3. **Flat array (all elements are equal)**:
   - No local minima or maxima exist, so both should return `-1`.

---

### **Improvements**
1. **Edge Case for Single Element**:
   Add a special case at the start:
   ```cpp
   if (n == 1) {
       return {{-1}, {-1}};
   }
   ```

2. **Avoid Redundant Comparisons**:
   When checking `arr[0]` or `arr[n-1]`, you can combine the conditions into one block to avoid redundancy.

3. **Code Formatting for Readability**:
   Using comments and better formatting improves clarity.

---

### **Optimized Code**
Here’s the optimized and clean version of your function:
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findLocalMinimaAndMaxima(int *arr, int n) {
    vector<int> maxi, mini;

    // Handle single element case
    if (n == 1) {
        return {{-1}, {-1}};
    }

    // Check first element
    if (arr[0] > arr[1]) maxi.push_back(0);
    if (arr[0] < arr[1]) mini.push_back(0);

    // Check middle elements
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            mini.push_back(i);
        }
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            maxi.push_back(i);
        }
    }

    // Check last element
    if (arr[n - 1] > arr[n - 2]) maxi.push_back(n - 1);
    if (arr[n - 1] < arr[n - 2]) mini.push_back(n - 1);

    // Handle no minima or maxima case
    if (maxi.empty()) maxi.push_back(-1);
    if (mini.empty()) mini.push_back(-1);

    return {mini, maxi};
}
```

---

### **Example**
#### Input:
```cpp
int arr[] = {1, 3, 2, 4, 1, 5};
int n = 6;
vector<vector<int>> result = findLocalMinimaAndMaxima(arr, n);
```

#### Output:
```cpp
Minima indices: [0, 2, 4]
Maxima indices: [1, 3, 5]
```
