K-th Element of two sorted arrays


https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159

https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/


https://workat.tech/problem-solving/practice/kth-two-sorted


---




naive approach
prerequiste median of two sort array
```cpp

            #include <bits/stdc++.h>
            using namespace std;
            
            int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
                vector<int> arr3;
            
                //apply the merge step:
                int i = 0, j = 0;
                while (i < m && j < n) {
                    if (a[i] < b[j]) arr3.push_back(a[i++]);
                    else arr3.push_back(b[j++]);
                }
            
                //copy the left-out elements:
                while (i < m) arr3.push_back(a[i++]);
                while (j < n) arr3.push_back(b[j++]);
                return arr3[k - 1];
            }
            
            int main()
            {
                vector<int> a = {2, 3, 6, 7, 9};
                vector<int> b = {1, 4, 8, 10};
                cout << "The k-ht element of two sorted array is: " <<
                        kthElement(a, b, a.size(), b.size(), 5) << '\n';
            }

```
Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
Reason: We traverse through both arrays linearly.

Space Complexity: O(m+n), where m and n are the sizes of the given arrays.
Reason: We are using an extra array of size (m+n) to solve this problem.

  
        best soln:


```cpp

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        
       
        int n1 = array1.size();
        int n2 = b.size();
        if(n1> n2) return MedianOfArrays(b, array1);
        int n = n1 + n2;
        int left = ( n1 + n2 + 1) / 2;
        int l = 0, r = n1;
        while(l<=r){
            int mid1 = l + (r-l)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1<n1) r1 = a[mid1];
            if(mid2<n2) r2 = b[mid2];
            if(mid1-1 >= 0) l1 = a[mid1 - 1];
            if(mid2-1 >= 0) l2 = b[mid2 - 1];
            if(l1<=r2 && l2 <= r1){
                if(n%2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }else if(l1 > r2) r = mid1 - 1;
            else l = mid1 + 1;
        }
        return 0;
    
    }
    
    }
};


```


---
 better approach
 ---
```cpp
// Create a merged array with size equal to arr1 + arr2
    vector<int> mergedArr(arr1.size() + arr2.size());

    // Copy elements from arr1 into mergedArr
    int index = 0;
    for (int i = 0; i < arr1.size(); i++) {
        mergedArr[index] = arr1[i];
        index++;
    }

    // Copy elements from arr2 into mergedArr
    for (int i = 0; i < arr2.size(); i++) {
        mergedArr[index] = arr2[i];
        index++;
    }

    // Sort the merged array
    sort(mergedArr.begin(), mergedArr.end());

    // Return the k-1 element (since arrays are 0-indexed)
    return mergedArr[k - 1];

```
        Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).

Space Complexity: O(1), as we are not using any extra space to solve this problem.
Let’s go through each line of the code with a detailed explanation and dry run.



---



```cpp
class Solution {
  public:
    int kthElement(int K, vector<int>& arr1, vector<int>& arr2) 
    {
        // code here
        priority_queue<int,vector<int>,greater<int>>q(arr1.begin(),arr1.end());
        for(int i=0;i<arr2.size();i++)
        {
            q.push(arr2[i]);
        }
        while(K-1)
        {
            q.pop();
            K--;
        }
        return q.top();
        
    }
};

```


---


```cpp

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n =a.size();
        int m = b.size();
        vector<int>ans;
        for(int i =0;i<n;i++)
        {
            ans.push_back(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            ans.push_back(b[i]);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};


```

---

or 


---
Your code has the following issues:

### 🔴 **Issues in Your Code**
1. **Incorrect Vector Resizing**
   - You initialized `ans` with a size of `(n + m)`, but then used `.push_back()`, which increases the size beyond `(n + m)`.  
   - Instead, you should directly assign values to `ans[i]` and `ans[n + j]`.

2. **Incorrect Return Index**
   - `ans[k]` is incorrect because indexing in C++ starts from `0`, but `k` is generally `1-based`.  
   - Correct index: `ans[k-1]`.

### ✅ **Fixed Code**
```cpp
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        vector<int> ans(n + m);

        // Merge both arrays into ans
        for (int i = 0; i < n; i++)
            ans[i] = a[i];
        for (int i = 0; i < m; i++)
            ans[n + i] = b[i];

        // Sort the merged array
        sort(ans.begin(), ans.end());

        // Return the k-th smallest element (1-based index correction)
        return ans[k - 1];
    }
};
```

### 🔷 **Optimized Approach (O(log(min(n, m))))**
Your current approach has a **time complexity of O((n+m) log(n+m))** due to sorting.  
A better approach is **Binary Search on the smaller array**, achieving **O(log(min(n, m)))** time.

 ---

 
 optimized solution

 ---



 ![image](https://github.com/user-attachments/assets/03b130c5-cc8c-4338-99f7-5d9ab759042b)


 
 
 ![image](https://github.com/user-attachments/assets/7decbbc7-5704-4ce1-9527-5fb63bb10fb7)


 
 
 ![image](https://github.com/user-attachments/assets/e2352a2d-f213-4590-a2ca-20610447828e)


 ![image](https://github.com/user-attachments/assets/e9659652-24fb-4836-a5b6-132e6464deb8)


 
 
 ![image](https://github.com/user-attachments/assets/be6c3385-45cd-491f-8fb0-dcb5d5b0c5a4)



 ![image](https://github.com/user-attachments/assets/b1878efa-5e20-40ee-aef9-98d1c61af175)



 ---

 Let's break down the approach step by step so you can both understand it deeply and explain it clearly in an interview. We'll work through the idea, the algorithm, and then a concrete example.

---

## **1. Problem Recap**

You are given **two sorted arrays** (say `A` and `B`) and a number `k`. You need to find the kth smallest element if you merged these arrays (without actually merging them entirely).

**Example:**  
- `A = [2, 3, 6, 7, 9]`
- `B = [1, 4, 8, 10]`  
- If `k = 5`, the merged array would be `[1, 2, 3, 4, 6, 7, 8, 9, 10]`, so the 5th smallest element is **6**.

---

## **2. High-Level Idea**

Instead of merging the two arrays (which takes extra time and space), we use a **binary search** strategy to find the correct “partition” between the two arrays. 

### **The Core Concept:**
- **Partitioning:**  
  Think of splitting each array into two parts: a left part (elements considered as part of the first `k` smallest) and a right part (elements not in the first `k` smallest).  
- We decide to take:
  - `x` elements from array `A`
  - `y` elements from array `B`  
  such that **`x + y = k`**.
  
- **Goal:**  
  We want to ensure that **all elements in the left parts are less than or equal to all elements in the right parts**. In that case, the kth element (i.e., the largest element in the left parts) is our answer.

---

## **3. Setting Up the Binary Search**

### **Step 3.1: Always Binary Search on the Smaller Array**
- To minimize the search space, always apply binary search on the array with fewer elements.  
- Let’s assume `A` is the smaller array. If not, swap `A` and `B`.

### **Step 3.2: Determine the Range for `x`**

- **Lower bound:**  
  You cannot take fewer than `max(0, k - size(B))` elements from `A` because if `B` doesn’t have enough elements, you must take more from `A`.

- **Upper bound:**  
  You cannot take more than `min(k, size(A))` elements from `A` because you cannot take more than all elements in `A` or more than `k`.

So, set:
- `low = max(0, k - size(B))`
- `high = min(k, size(A))`

---

## **4. The Binary Search Loop**

 
 ![image](https://github.com/user-attachments/assets/cdc93391-ebcb-4178-b7e6-0edeadef1b6f)

![image](https://github.com/user-attachments/assets/73456bff-be30-4257-a5a8-3345e5292830)

![image](https://github.com/user-attachments/assets/a5abd19a-438e-422c-a532-cc5ab7060a09)


     
   - **If Not Correct:**
     - If `leftA > rightB`:  
       You've taken too many elements from `A`. Reduce `x` by setting `high = x - 1`.
       
     - If `leftB > rightA`:  
       You need more elements from `A`. Increase `x` by setting `low = x + 1`.

Repeat the loop until the correct partition is found.

---

## **5. Step-by-Step Example**

Let's use our example arrays:
- `A = [2, 3, 6, 7, 9]` (size = 5)
- `B = [1, 4, 8, 10]` (size = 4)
- `k = 5`

### **Step 5.1: Setup**
- Ensure `A` is the smaller array. (Here, both are comparable, so assume `A` is fine.)
- Calculate search boundaries:
  - `low = max(0, k - size(B)) = max(0, 5 - 4) = 1`
  - `high = min(k, size(A)) = min(5, 5) = 5`


![image](https://github.com/user-attachments/assets/66edc726-91ba-4417-9775-0c27c5c1349b)

- **Determine Border Values:**
  - For array A:
    - `leftA = A[3 - 1] = A[2] = 6`
    - `rightA = A[3] = 7`
  - For array B:
    - `leftB = B[2 - 1] = B[1] = 4`
    - `rightB = B[2] = 8`

- **Check Conditions:**
  - Is `leftA (6) <= rightB (8)`? **Yes.**
  - Is `leftB (4) <= rightA (7)`? **Yes.**

Since both conditions are satisfied, the partition is correct.

- **Result:**  
  The kth element is `max(leftA, leftB) = max(6, 4) = 6`.

This matches the expected result!

---

## **6. Explaining It in an Interview**

When explaining this solution in an interview, you can structure your explanation like this:

1. **Problem Understanding:**  
   "We need to find the kth smallest element from two sorted arrays without fully merging them. Since the arrays are sorted, we can use a binary search technique."

2. **Idea of Partitioning:**  
   "The idea is to partition both arrays into a left part and a right part such that the left parts together contain exactly k elements. The kth smallest element will then be the largest element of these left parts."

3. **Binary Search on the Smaller Array:**  
   "We use binary search on the smaller array to determine how many elements to take from it. Let’s denote this count as `x`. Consequently, we take `k - x` elements from the second array."

4. **Validating the Partition:**  
   "We compare the border elements of these partitions. We use `-∞` and `+∞` when partitions touch the boundaries. If `A[x-1] <= B[k-x]` and `B[k-x-1] <= A[x]`, then the partition is correct and the kth smallest is the larger of `A[x-1]` and `B[k-x-1]`."

5. **Edge Cases and Adjustments:**  
   "If the condition isn’t met, we adjust our binary search bounds accordingly: if `A[x-1] > B[k-x]`, it means we have taken too many elements from A, so we reduce `x`; otherwise, we increase `x`."

6. **Walk Through Example:**  
   "For example, given A = [2, 3, 6, 7, 9] and B = [1, 4, 8, 10] with k = 5, we found that taking 3 elements from A and 2 from B leads to a correct partition, with the 5th smallest element being 6."

---

## **7. Full C++ Code**

Here’s the complete C++ code that implements the above logic:

```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int kthElement(const vector<int>& A, const vector<int>& B, int k) {
        int n = A.size(), m = B.size();
        
        // Ensure binary search is on the smaller array.
        if(n > m) return kthElement(B, A, k);
        
        // Determine the range for elements to pick from A.
        int low = max(0, k - m);
        int high = min(k, n);
        
        while(low <= high) {
            int x = (low + high) / 2;  // Number of elements from A
            int y = k - x;             // Number of elements from B
            
            // Handle edges using INT_MIN and INT_MAX
            int leftA = (x == 0) ? INT_MIN : A[x - 1];
            int leftB = (y == 0) ? INT_MIN : B[y - 1];
            int rightA = (x == n) ? INT_MAX : A[x];
            int rightB = (y == m) ? INT_MAX : B[y];
            
            // Check if we have found the correct partition.
            if(leftA <= rightB && leftB <= rightA)
                return max(leftA, leftB);
            else if(leftA > rightB)
                high = x - 1;  // Too many elements from A, decrease x.
            else
                low = x + 1;   // Too few elements from A, increase x.
        }
        
        // If partition is not found (should not happen if k is valid).
        return -1;
    }
};
```

---

## **Summary**

1. **Understand the Problem:**  
   Find the kth smallest element from two sorted arrays without merging them.

2. **Binary Search & Partitioning:**  
   Decide how many elements to take from the smaller array using binary search so that the left partition contains exactly k elements.

3. **Validate the Partition:**  
   Check border elements of the partitions to ensure the left side contains all smaller elements.

4. **Return the kth Element:**  
   Once the partition is correct, the kth element is the maximum of the two left border elements.

This method runs in **O(log(min(n, m)))** time, which is efficient compared to merging and sorting.

Feel free to ask if you need further clarification or more examples!


 
Let's simplify this idea further using plain language and an example.

---

### **The Basic Problem**

When we try to divide (or "partition") an array into two parts, sometimes one of the parts might be empty. In our algorithm, we want to compare the largest number on the left side of the partition with the smallest number on the right side. But if one side is empty, what do we compare?

For example, consider the array:

```
A = [3, 5, 7]
```

- **If we take 0 elements from A:**  
  - **Left part:** _empty_  
  - **Right part:** `[3, 5, 7]`

- **If we take all 3 elements from A:**  
  - **Left part:** `[3, 5, 7]`  
  - **Right part:** _empty_

We need a way to handle these "empty" parts without causing errors.

---

### **Using INT_MIN and INT_MAX**

- **INT_MIN:**  
  Think of `INT_MIN` as representing "negative infinity."  
  **Why?** If a left part is empty (i.e., there is no element on the left), we want to treat it as if it has the smallest possible value, so that any actual number is larger.  
  - **Example:** If the left part of A is empty, we set its value to `INT_MIN` so that when we compare it with something from the right part, it doesn't interfere.

- **INT_MAX:**  
  Think of `INT_MAX` as representing "positive infinity."  
  **Why?** If a right part is empty (i.e., there is no element on the right), we want to treat it as if it has the largest possible value, so that any actual number is smaller.  
  - **Example:** If the right part of A is empty, we set its value to `INT_MAX` so that when we compare something from the left part to it, the left part is always smaller.

---

### **How It Works in the Code**

Imagine you're choosing a number \( x \) that represents how many elements you take from \( A \). Then:
- **Left side of A:**  
  - If \( x > 0 \): The last element taken is \( A[x-1] \).
  - If \( x = 0 \): There is no element, so we use `INT_MIN` to stand in for the "missing" number.

- **Right side of A:**  
  - If \( x \) is less than the total number of elements in \( A \) (say \( n \)): The first element not taken is \( A[x] \).
  - If \( x = n \): There is no element on the right, so we use `INT_MAX`.

The same idea applies to array \( B \) with a count \( y \).

---

### **A Simple Example**

Suppose:
- \( A = [3, 5, 7] \)
- \( B = [2, 6, 8] \)
- And we decide (via our binary search) that \( x = 0 \) (we take 0 elements from A).  
  Then automatically, \( y \) must equal \( k \) (for some \( k \))—but let's focus on \( A \) for now.

**For array A:**
- **Left Side:** Since \( x = 0 \), there is no element in the left part.  
  **So, we set:**  
  ```cpp
  leftA = (x == 0) ? INT_MIN : A[x - 1];
  ```
  This gives `leftA = INT_MIN`.

- **Right Side:**  
  Since \( x = 0 \) and there are elements in A, the right side starts at \( A[0] \).  
  **So, we set:**  
  ```cpp
  rightA = (x == n) ? INT_MAX : A[x];
  ```
  Here, \( x \) is not equal to \( n \) (3), so `rightA = A[0] = 3`.

**For array B:** (Assume \( y \) is chosen so that B has valid partitions; the idea is the same.)

Now, when we compare, we might check:
- Is \( \text{leftA} \leq \text{rightB} \)?  
  Since `leftA` is `INT_MIN`, it is smaller than any actual number in \( B \).

- And if the right side of \( A \) were empty, we'd have `rightA = INT_MAX`, ensuring that any actual number in the left side of \( B \) is less than `rightA`.

---

### **Why This Is Useful**

By using `INT_MIN` and `INT_MAX`:
- **No matter what,** you won't try to access an element that doesn't exist.
- **The comparisons work correctly:**  
  - If a left side is empty, it's like saying, "I have nothing here, so I'll treat it as the smallest possible number."  
  - If a right side is empty, it's like saying, "I have nothing here, so I'll treat it as the largest possible number."

This allows the algorithm to correctly decide if the partition is "balanced" (i.e., all numbers on the left are smaller than all numbers on the right) without running into errors.

---

### **In Summary**

- **INT_MIN:** Used when the left partition is empty to ensure it doesn't mistakenly block a valid partition.
- **INT_MAX:** Used when the right partition is empty to ensure the left partition's numbers are always smaller.

Think of them as safety nets that give your comparisons a definite answer even when one side of the partition has no elements.

I hope this simpler explanation helps! Let me know if you'd like more clarification or another example.






