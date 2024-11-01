K-th Element of two sorted arrays


https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array



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

### Code Explanation:

```cpp
// Create a merged array with size equal to arr1 + arr2
vector<int> mergedArr(arr1.size() + arr2.size());
```
- **Explanation**: 
  - This line creates a new `vector<int>` named `mergedArr` to hold the merged elements of `arr1` and `arr2`. 
  - The size of `mergedArr` is the sum of the sizes of `arr1` and `arr2`.
- **Dry Run**:
  - Assume `arr1 = {2, 3, 1}` and `arr2 = {6, 5, 4}`.
  - `arr1.size()` is `3`, and `arr2.size()` is `3`. So, the size of `mergedArr` will be `3 + 3 = 6`.
  - Now `mergedArr` is initialized as a vector of size 6: `mergedArr = { _, _, _, _, _, _ }`.

---

```cpp
// Copy elements from arr1 into mergedArr
int index = 0;
for (int i = 0; i < arr1.size(); i++) {
    mergedArr[index] = arr1[i];
    index++;
}
```
- **Explanation**:
  - We initialize `index` to `0`. This `index` will track the current position in the `mergedArr`.
  - The `for` loop iterates over all elements of `arr1` and copies them into `mergedArr` at the current `index`.
  - After each copy, `index` is incremented to move to the next position.
- **Dry Run**:
  - Start with `index = 0`.
  - On the first iteration (`i = 0`), `arr1[0] = 2`, so `mergedArr[0] = 2`. Now `mergedArr = { 2, _, _, _, _, _ }`.
  - Increment `index` to `1`.
  - On the second iteration (`i = 1`), `arr1[1] = 3`, so `mergedArr[1] = 3`. Now `mergedArr = { 2, 3, _, _, _, _ }`.
  - Increment `index` to `2`.
  - On the third iteration (`i = 2`), `arr1[2] = 1`, so `mergedArr[2] = 1`. Now `mergedArr = { 2, 3, 1, _, _, _ }`.
  - Increment `index` to `3`.

---

```cpp
// Copy elements from arr2 into mergedArr
for (int i = 0; i < arr2.size(); i++) {
    mergedArr[index] = arr2[i];
    index++;
}
```
- **Explanation**:
  - This `for` loop iterates over all elements of `arr2` and copies them into `mergedArr` starting from the current value of `index` (which is `3` after copying `arr1`).
  - After each copy, `index` is incremented.
- **Dry Run**:
  - Start with `index = 3` (from the previous step).
  - On the first iteration (`i = 0`), `arr2[0] = 6`, so `mergedArr[3] = 6`. Now `mergedArr = { 2, 3, 1, 6, _, _ }`.
  - Increment `index` to `4`.
  - On the second iteration (`i = 1`), `arr2[1] = 5`, so `mergedArr[4] = 5`. Now `mergedArr = { 2, 3, 1, 6, 5, _ }`.
  - Increment `index` to `5`.
  - On the third iteration (`i = 2`), `arr2[2] = 4`, so `mergedArr[5] = 4`. Now `mergedArr = { 2, 3, 1, 6, 5, 4 }`.
  - Increment `index` to `6`.

---

```cpp
// Sort the merged array
sort(mergedArr.begin(), mergedArr.end());
```
- **Explanation**:
  - This line sorts the `mergedArr` in non-decreasing order using `std::sort()`, which sorts the elements in-place.
- **Dry Run**:
  - Before sorting: `mergedArr = { 2, 3, 1, 6, 5, 4 }`.
  - After sorting: `mergedArr = { 1, 2, 3, 4, 5, 6 }`.

---

```cpp
// Return the k-1 element (since arrays are 0-indexed)
return mergedArr[k - 1];
```
- **Explanation**:
  - We return the element at the `(k-1)` index because arrays in C++ are 0-indexed. 
  - This means the 1st element is at index `0`, the 2nd element is at index `1`, and so on.
- **Dry Run**:
  - Let's assume `k = 4`. We need to return the 4th element, which is located at index `k-1 = 4-1 = 3`.
  - The sorted `mergedArr` is `{ 1, 2, 3, 4, 5, 6 }`.
  - The element at index `3` is `4`.
  - So, the function will return `4`.

---

### Summary of Dry Run with Example:




1. **Input**: `arr1 = {2, 3, 1}`, `arr2 = {6, 5, 4}`, `k = 4`
2. **After Merging**: `mergedArr = { 2, 3, 1, 6, 5, 4 }`
3. **After Sorting**: `mergedArr = { 1, 2, 3, 4, 5, 6 }`
4. **Return**: The 4th element (index `3`), which is `4`.

This step-by-step dry run helps to understand how the algorithm merges two arrays, sorts them, and retrieves the `k`-th smallest element.

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
