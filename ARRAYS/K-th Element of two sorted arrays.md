K-th Element of two sorted arrays


https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

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

Do you want the optimized solution? 🚀
