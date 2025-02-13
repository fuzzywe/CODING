
![Sorting - Part 1 _ Selection Sort, Bubble Sort, Insertion Sort _ Strivers A2Z DSA Course 23-33 screenshot](https://github.com/user-attachments/assets/8e8e4de1-5f84-4580-ace4-f617f86cdef8)


Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5


---

```cpp
  #include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;

}

```
### **Bubble Sort - Step-by-Step Execution in Tabular Format**  

| **Pass** | **Comparisons & Swaps** | **Array After Each Pass** |
|----------|------------------------|---------------------------|
| **Initial** | -- | **[13, 46, 24, 52, 20, 9]** |
| **1st Pass** | (13 < 46) ✅ No swap <br> (46 > 24) ❌ Swap → **[13, 24, 46, 52, 20, 9]** <br> (46 < 52) ✅ No swap <br> (52 > 20) ❌ Swap → **[13, 24, 46, 20, 52, 9]** <br> (52 > 9) ❌ Swap → **[13, 24, 46, 20, 9, 52]** | **[13, 24, 46, 20, 9, 52]** (52 is sorted) |
| **2nd Pass** | (13 < 24) ✅ No swap <br> (24 < 46) ✅ No swap <br> (46 > 20) ❌ Swap → **[13, 24, 20, 46, 9, 52]** <br> (46 > 9) ❌ Swap → **[13, 24, 20, 9, 46, 52]** | **[13, 24, 20, 9, 46, 52]** (46 is sorted) |
| **3rd Pass** | (13 < 24) ✅ No swap <br> (24 > 20) ❌ Swap → **[13, 20, 24, 9, 46, 52]** <br> (24 > 9) ❌ Swap → **[13, 20, 9, 24, 46, 52]** | **[13, 20, 9, 24, 46, 52]** (24 is sorted) |
| **4th Pass** | (13 < 20) ✅ No swap <br> (20 > 9) ❌ Swap → **[13, 9, 20, 24, 46, 52]** | **[13, 9, 20, 24, 46, 52]** (20 is sorted) |
| **5th Pass** | (13 > 9) ❌ Swap → **[9, 13, 20, 24, 46, 52]** | **[9, 13, 20, 24, 46, 52]** (Sorted) |

### **Final Sorted Array:**  
✅ **[9, 13, 20, 24, 46, 52]**  

### **Key Observations:**  
- **Largest element bubbles up** in each pass.
- **Each pass reduces the unsorted portion** of the array.
- **Total Passes = (N - 1)** for an array of size **N**.
- **Time Complexity:** O(N²) (Worst & Average Case).  
- **Space Complexity:** O(1) (In-place sorting).  

This tabular format clearly shows how Bubble Sort sorts the array step by step. 🚀

Worst-case time complexity: O(n^2) because it may need to compare every pair in the array.
Best-case time complexity: O(n) if the array is already sorted.



---



best case by reduce the better case

---

```cpp

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;
}

```
Output: 

Before Using Bubble Sort:

13 46 24 52 20 9

After Using bubble sort:

9 13 20 24 46 52

