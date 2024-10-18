K-th Element of two sorted arrays

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
