Input: arr1[] = {1, 12, 15, 26, 38}, arr2[] = {2, 13, 17, 30, 45}
Output: 16
Explanation: The merged sorted array is {1, 2, 12, 13, 15, 17, 26, 30, 38, 45}. The middle two elements are 15 and 17, so median = (15 + 17)/2 = 16

Input: arr1[] = {10}, arr2[] = {21}
Output : 15.5
Explanation : The merged sorted array is {10, 21}. The middle two elements are 10 and 21, so median = (10 + 21)/2 = 15.5

// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Sorting

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays of equal size
double getMedian(vector<int>& arr1, vector<int>& arr2) {
  
    // Concatenate
    vector<int> arr3(arr1.begin(), arr1.end());
    arr3.insert(arr3.end(), arr2.begin(), arr2.end());

    // Sort the concatenated array
    sort(arr3.begin(), arr3.end());
    
    // Calculate and return the median
    int n = arr3.size();
      
    int mid1 = n / 2;
    int mid2 = mid1 - 1;
    return (arr3[mid1] + arr3[mid2]) / 2.0;
}

int main() {
    vector<int> arr1 = { 1, 12, 15, 26, 38 };
    vector<int> arr2 = { 2, 13, 17, 30, 45 };

    cout << getMedian(arr1, arr2) << endl;
    return 0;
}
Time Complexity: O((2n) * log(2n)), where n is the size of array arr1[] and arr2[].
Auxiliary Space: O(2n), because we are creating a new merged array of size 2n.

// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Merge of Merge Sort

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays 
// of equal size
float getMedian(vector<int>& arr1, vector<int>& arr2) {
      
      int n = arr1.size();
    int i = 0, j = 0;
    int count;
  
    // m1 to store element at index n of merged array
    // m2 to store element at index (n - 1) of merged array
    int m1 = -1, m2 = -1;

    // Loop till n
    for (count = 0; count <= n; count++) {
        m2 = m1;
      
        // If both the arrays have remaining elements
        if (i < n && j < n) {
            if (arr1[i] > arr2[j])
                m1 = arr2[j++];
            else
                m1 = arr1[i++];
        }
        
          // If only arr1 has remaining elements
        else if (i < n)
            m1 = arr1[i++];
          
        // If only arr2 has remaining elements
        else 
            m1 = arr2[j++];
    }

    return (m1 + m2) / 2.0;
}

int main() {
    vector<int> arr1 = { 1, 12, 15, 26, 38 };
    vector<int> arr2 = { 2, 13, 17, 30, 45 };

    cout << getMedian(arr1, arr2) << endl;
    return 0;
}
Time Complexity: O(n), where n is the size of array arr1[] and arr2[].
Auxiliary Space: O(1)

[Expected Approach] Using Binary Search – O(log n) Time and O(1) Space

// C++ Program to find the median of merged sorted
// array using Binary Search

#include <bits/stdc++.h>
using namespace std;

// function to find median of merged sorted array
double getMedian(vector<int> &arr1, vector<int> &arr2) {
        
      int n = arr1.size();
      
      // We can take [0...n] number of elements from arr1[]
      int low = 0, high = n;
  
      while(low <= high) {
        
          // Take mid1 elements from arr1
          int mid1 = (low + high) / 2;
          
          // Take mid2 elements from arr2
          int mid2 = n - mid1;
      
          // Find elements to the left and right of partition in arr1
          int l1 = (mid1 == 0 ? INT_MIN : arr1[mid1 - 1]);
          int r1 = (mid1 == n ? INT_MAX : arr1[mid1]);
      
          // Find elements to the left and right of partition in arr2
          int l2 = (mid2 == 0 ? INT_MIN : arr2[mid2 - 1]);
          int r2 = (mid2 == n ? INT_MAX : arr2[mid2]);
      
          // If it is a valid partition
          if(l1 <= r2 && l2 <= r1) 
            return (max(l1, l2) + min(r1, r2)) / 2.0;
          
          // If we need to take lesser elements from arr1
          if(l1 > r2) 
              high = mid1 - 1;
          // If we need to take more elements from arr1
          else 
              low = mid1 + 1;
    }
      return 0;
}

int main() {
    vector<int> arr1 = { 1, 12, 15, 26, 38 };
    vector<int> arr2 = { 2, 13, 17, 30, 45 };

    cout << getMedian(arr1, arr2) << endl;

    return 0;
}
Let’s work through the concept visually and with formulas to clarify how the partitioning and comparisons work. The goal is to find the **median** of two sorted arrays.

---

### **Problem Recap**

We divide the two arrays into "left" and "right" parts. 

1. Let `mid1` be the partition in `arr1` and `mid2` in `arr2`. 
   - The size of the left part is \((mid1 + mid2)\), and the size of the right part is the remaining elements.

2. The partition is valid when:
   - All elements in the **left parts** are ≤ all elements in the **right parts**:
     \[
     l1 \leq r2 \quad \text{and} \quad l2 \leq r1
     \]

3. The median depends on the combined length:
   - If \((n1 + n2)\) is **odd**, the median is the maximum of the left parts:
     \[
     \text{Median} = \max(l1, l2)
     \]
   - If \((n1 + n2)\) is **even**, the median is the average of the largest left and smallest right:
     \[
     \text{Median} = \frac{\max(l1, l2) + \min(r1, r2)}{2}
     \]

---

### **Key Variables**

- `l1`: Largest element in the left part of `arr1`:
  \[
  l1 = \text{mid1 == 0 ? INT\_MIN : arr1[mid1 - 1]}
  \]
  If `mid1 = 0`, it means there is no left part in `arr1`, so use \(-\infty\) (`INT_MIN`).

- `r1`: Smallest element in the right part of `arr1`:
  \[
  r1 = \text{mid1 == n1 ? INT\_MAX : arr1[mid1]}
  \]
  If `mid1 = n1`, it means there is no right part in `arr1`, so use \(+\infty\) (`INT_MAX`).

Similarly, for `arr2`:
- `l2`: Largest element in the left part of `arr2`.
- `r2`: Smallest element in the right part of `arr2`.

---

### **Visual Example**

#### Input Arrays:
```
arr1 = [1, 3, 8]
arr2 = [7, 9, 10, 11]
```

#### Total Length:
- \( n1 = 3 \), \( n2 = 4 \), \( n = 7 \).

#### Binary Search Steps

1. **Initial Setup**:
   - Binary search on the smaller array (`arr1`), so we divide it at `mid1`.

---

#### **Step 1: Partitioning**

Let’s start with a hypothetical partition:

- `mid1 = 1` → `arr1` is divided as:
  - Left: [1]
  - Right: [3, 8]
- `mid2 = 3` → `arr2` is divided as:
  - Left: [7, 9, 10]
  - Right: [11]

**Visual Partitioning**:
```
arr1: [1] | [3, 8]
arr2: [7, 9, 10] | [11]
```

Now find boundary values:
- \( l1 = 1 \), \( r1 = 3 \)
- \( l2 = 10 \), \( r2 = 11 \)

**Check Valid Partition**:
- \( l1 \leq r2 (1 \leq 11) \) → True.
- \( l2 \leq r1 (10 \leq 3) \) → False.

This is not a valid partition. Adjust `mid1` to search further.

---

#### **Step 2: Adjust Partition**

Move `mid1` right. Now:
- `mid1 = 2` → `arr1` is divided as:
  - Left: [1, 3]
  - Right: [8]
- `mid2 = 2` → `arr2` is divided as:
  - Left: [7, 9]
  - Right: [10, 11]

**Visual Partitioning**:
```
arr1: [1, 3] | [8]
arr2: [7, 9] | [10, 11]
```

Boundary values:
- \( l1 = 3 \), \( r1 = 8 \)
- \( l2 = 9 \), \( r2 = 10 \)

**Check Valid Partition**:
- \( l1 \leq r2 (3 \leq 10) \) → True.
- \( l2 \leq r1 (9 \leq 8) \) → False.

Adjust again.

---

#### **Step 3: Correct Partition**

Move `mid1` right. Now:
- `mid1 = 3` → `arr1` is divided as:
  - Left: [1, 3, 8]
  - Right: []
- `mid2 = 1` → `arr2` is divided as:
  - Left: [7]
  - Right: [9, 10, 11]

**Visual Partitioning**:
```
arr1: [1, 3, 8] | []
arr2: [7] | [9, 10, 11]
```

Boundary values:
- \( l1 = 8 \), \( r1 = \text{INT\_MAX} \) (no right part in `arr1`).
- \( l2 = 7 \), \( r2 = 9 \)

**Check Valid Partition**:
- \( l1 \leq r2 (8 \leq 9) \) → True.
- \( l2 \leq r1 (7 \leq \text{INT\_MAX}) \) → True.

This is a valid partition.

---

#### **Calculate the Median**

- Total length \( n = 7 \) (odd):
  - Median = \( \max(l1, l2) = \max(8, 7) = 8 \).

---

### **Key Math Formulas Recap**

1. Left size = \((mid1 + mid2)\), Right size = \((n - (mid1 + mid2))\).
2. Valid partition condition:
   \[
   l1 \leq r2 \quad \text{and} \quad l2 \leq r1
   \]
3. Median:
   - Odd case:
     \[
     \text{Median} = \max(l1, l2)
     \]
   - Even case:
     \[
     \text{Median} = \frac{\max(l1, l2) + \min(r1, r2)}{2}
     \]
