https://leetcode.com/problems/median-of-two-sorted-arrays/

Input: arr1[] = {1, 12, 15, 26, 38}, arr2[] = {2, 13, 17, 30, 45}
Output: 16
Explanation: The merged sorted array is {1, 2, 12, 13, 15, 17, 26, 30, 38, 45}. The middle two elements are 15 and 17, so median = (15 + 17)/2 = 16

Input: arr1[] = {10}, arr2[] = {21}
Output : 15.5
Explanation : The merged sorted array is {10, 21}. The middle two elements are 10 and 21, so median = (10 + 21)/2 = 15.5

// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Sorting
```cpp
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

```

// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Merge of Merge Sort
```cpp
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

```

[Expected Approach] Using Binary Search – O(log n) Time and O(1) Space

// C++ Program to find the median of merged sorted
// array using Binary Search

```cpp
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



```
![17 11 2024_11 11 37_REC](https://github.com/user-attachments/assets/6f600608-31bb-4b48-8f5f-eb1b4f0022a8)

![17 11 2024_11 12 09_REC](https://github.com/user-attachments/assets/d1c39dd5-7b14-498f-bc99-ee7d3870355e)



![17 11 2024_11 12 25_REC](https://github.com/user-attachments/assets/74f26bcc-090a-4058-8f45-6f72b5a902f2)
