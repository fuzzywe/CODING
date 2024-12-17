Examples:

Example 1:
Input: N=5, arr[]={4,2,1,6,7}
Output: 1,2,4,6,7,


Example 2:
Input: N=7,arr[]={3,2,8,5,1,4,23}
Output: 1,2,3,4,5,8,23


![Merge Sort _ Algorithm _ Pseudocode _ Dry Run _ Code _ Strivers A2Z DSA Course 20-17 screenshot](https://github.com/user-attachments/assets/75ba522a-501c-4e85-9262-91028f20ec85)

![Merge Sort _ Algorithm _ Pseudocode _ Dry Run _ Code _ Strivers A2Z DSA Course 20-24 screenshot](https://github.com/user-attachments/assets/f45d4809-b1cc-4af1-bc37-e22654ed1d24)

```cpp
  #include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}

```
Output:

Before Sorting Array:
9 4 7 6 3 1 5
After Sorting Array:
1 3 4 5 6 7 9

Time complexity: O(nlogn) 

Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn

Space complexity: O(n)  

Reason: We are using a temporary array to store elements in sorted order.

Auxiliary Space Complexity: O(n) 

Initial Call: mergeSort(arr, 0, 4)

Array: {4, 2, 1, 6, 7}
Low = 0, High = 4, Mid = 2
Left Half Sorting: mergeSort(arr, 0, 2)

Array: {4, 2, 1}
Low = 0, High = 2, Mid = 1
Left Sub-half Sorting: mergeSort(arr, 0, 1)

Array: {4, 2}
Low = 0, High = 1, Mid = 0
Single Element Arrays (Base Case):
Now, the recursion reaches arrays of size 1, so it returns immediately:

mergeSort(arr, 0, 0) → {4}
mergeSort(arr, 1, 1) → {2}
Merging Sub-arrays: Now, the merge() function is called to merge {4} and {2}.

Temporary array temp[] = {2, 4} (size 2, so auxiliary space = 2).
The sorted array becomes: {2, 4}.
Right Sub-half Sorting: mergeSort(arr, 2, 2) → {1} (Base case, no recursion).

Merge Left Half: Now, the merge() function is called to merge {2, 4} and {1}.

Temporary array temp[] = {1, 2, 4} (size 3, so auxiliary space = 3).
The sorted array becomes: {1, 2, 4}.
Right Half Sorting: mergeSort(arr, 3, 4)

Array: {6, 7}
Low = 3, High = 4, Mid = 3
Right Sub-arrays:

mergeSort(arr, 3, 3) → {6}
mergeSort(arr, 4, 4) → {7}
Merging Right Half: The merge() function is called to merge {6} and {7}.

Temporary array temp[] = {6, 7} (size 2, so auxiliary space = 2).
The sorted array becomes: {6, 7}.
Final Merge: Finally, the merge() function is called to merge {1, 2, 4} and {6, 7}.

Temporary array temp[] = {1, 2, 4, 6, 7} (size 5, so auxiliary space = 5).
The sorted array becomes: {1, 2, 4, 6, 7}.
Summary of Auxiliary Space at Each Merge Step:
When merging {4} and {2}, we use a temporary array of size 2.
When merging {2, 4} and {1}, we use a temporary array of size 3.
When merging {6} and {7}, we use a temporary array of size 2.
When merging {1, 2, 4} and {6, 7}, we use a temporary array of size 5.
