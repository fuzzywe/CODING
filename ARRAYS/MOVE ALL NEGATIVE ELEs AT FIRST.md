Move all negative numbers to beginning and positive to end with constant extra space


Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Naive approach: The idea is to sort the array of elements, this will make sure that all the negative elements will come before all the positive elements.
Below is the implementation of the above approach:

```cpp
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void move(vector<int>& arr){
  sort(arr.begin(),arr.end());
}
int main() {

    vector<int> arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
      move(arr);
    for (int e : arr)
       cout<<e << " ";
    return 0;
}
```
// This code is contributed by repakaeshwaripriya

Output
-7 -3 -1 2 4 5 6 8 9 
Time Complexity: O(n*log(n)), Where n is the length of the given array.
Auxiliary Space: O(1)

  Efficient Approach 1:
The idea is to simply apply the partition process of quicksort. 


// A C++ program to put all negative
// numbers before positive numbers

```cpp
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver code
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
```
Output
-1 -3 -7 4 5 6 2 8 9

Time complexity: O(N) 

Auxiliary Space: O(1)

Let's break down the provided function `rearrange` that rearranges an array such that all negative numbers are moved to the front while maintaining the order of positive numbers.

### Code Explanation

```cpp
void rearrange(int arr[], int n) {
    int j = 0; // Pointer to track the position for negative numbers
    for (int i = 0; i < n; i++) { // Iterate through each element
        if (arr[i] < 0) { // Check if the current element is negative
            if (i != j) // Only swap if the current index is not the position for negatives
                swap(arr[i], arr[j]); // Swap negative element to the front
            j++; // Increment position for the next negative number
        }
    }
}
```

### Detailed Explanation of Each Line

1. **`void rearrange(int arr[], int n) {`**
   - Declares a function named `rearrange` that takes an array `arr` and its size `n`. This function rearranges the array such that all negative numbers come first.

2. **`int j = 0;`**
   - Initializes a pointer `j` that tracks the position in the array where the next negative number should be placed. Initially, it points to the start of the array.

3. **`for (int i = 0; i < n; i++) {`**
   - Starts a loop to iterate through each element in the array using index `i`.

### Iteration of the For Loop

Let's dry run this code with an example array:
```cpp
arr = [12, -7, 5, -3, -8, 6]
```

#### **Initial State:**
- `arr = [12, -7, 5, -3, -8, 6]`
- `n = 6`
- `j = 0`

### Step-by-Step Execution:

#### **First Iteration (i = 0):**
- **Condition:** `if (arr[i] < 0)` (12 < 0) → false
  - No action taken. `j` remains `0`.

#### **Second Iteration (i = 1):**
- **Condition:** `if (arr[i] < 0)` (-7 < 0) → true
  - **Check:** `if (i != j)` (1 != 0) → true
    - Execute `swap(arr[i], arr[j]);`
    - `swap(arr[1], arr[0]);` (swap -7 and 12)
    - **State:** `arr = [-7, 12, 5, -3, -8, 6]`
  - Increment `j`: `j++` → `j = 1`.

#### **Third Iteration (i = 2):**
- **Condition:** `if (arr[i] < 0)` (5 < 0) → false
  - No action taken. `j` remains `1`.

#### **Fourth Iteration (i = 3):**
- **Condition:** `if (arr[i] < 0)` (-3 < 0) → true
  - **Check:** `if (i != j)` (3 != 1) → true
    - Execute `swap(arr[i], arr[j]);`
    - `swap(arr[3], arr[1]);` (swap -3 and 12)
    - **State:** `arr = [-7, -3, 5, 12, -8, 6]`
  - Increment `j`: `j++` → `j = 2`.

#### **Fifth Iteration (i = 4):**
- **Condition:** `if (arr[i] < 0)` (-8 < 0) → true
  - **Check:** `if (i != j)` (4 != 2) → true
    - Execute `swap(arr[i], arr[j]);`
    - `swap(arr[4], arr[2]);` (swap -8 and 5)
    - **State:** `arr = [-7, -3, -8, 12, 5, 6]`
  - Increment `j`: `j++` → `j = 3`.

#### **Sixth Iteration (i = 5):**
- **Condition:** `if (arr[i] < 0)` (6 < 0) → false
  - No action taken. `j` remains `3`.

### Final State of `arr`:
- After the loop completes, the rearranged array is:
```cpp
arr = [-7, -3, -8, 12, 5, 6]
```
- All negative numbers are now at the beginning of the array, while the positive numbers remain in their relative order.

### Summary
- The function efficiently rearranges the elements of the array in place:
  - It iterates through the array and, whenever it finds a negative number, it swaps it with the element at the `j` index, which tracks the position for the next negative number.
  - This method ensures that all negative numbers are grouped at the beginning of the array while preserving the order of the positive numbers, and it only uses constant extra space (just a couple of integer variables).
 
  - 

```cpp
  #include <iostream>
using namespace std;

// Swap Function.
void swap(int &a,int &b){
  int temp =a;
  a=b;
  b=temp;
}
  
// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}
void displayArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main() {
    // Data
    int arr[] = {1, 2,  -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2,  1};
      int n = sizeof(arr)/sizeof(arr[0]);
      reArrange(arr,n);
    displayArray(arr,n);
    return 0;
}
```

Output
-9 -8 -4 -5 -6 -7 3 2 2 2 1 3 2 1 
Time complexity: O(N) 
Auxiliary Space: O(1)

Sure! Let's break down the provided function `reArrange` that rearranges an array such that all negative numbers are on one side and all positive numbers are on the other side. The method uses two pointers, `low` and `high`, to efficiently swap elements. 

### Code Explanation

```cpp
void reArrange(int arr[], int n) {
    int low = 0, high = n - 1;  // Initialize pointers
    while (low < high) {        // Loop until pointers meet
        if (arr[low] < 0) {     // Check if the left pointer is negative
            low++;               // Move left pointer to the right
        } else if (arr[high] > 0) { // Check if the right pointer is positive
            high--;              // Move right pointer to the left
        } else {
            swap(arr[low], arr[high]); // Swap elements at low and high
        }
    }
}
```

### Detailed Explanation of Each Line

1. **`void reArrange(int arr[], int n) {`**
   - Declares a function named `reArrange` that takes an array `arr` and its size `n`. This function rearranges the array in place.

2. **`int low = 0, high = n - 1;`**
   - Initializes two pointers:
     - `low`: starting from the beginning of the array (index 0).
     - `high`: starting from the end of the array (index `n-1`).

3. **`while (low < high) {`**
   - Begins a loop that continues as long as the `low` pointer is less than the `high` pointer.

### Iteration of the While Loop

Let’s dry run this code with an example array:
```cpp
arr = [12, -7, 5, -3, -8, 6]
```

#### **Initial State:**
- `arr = [12, -7, 5, -3, -8, 6]`
- `n = 6`
- `low = 0`
- `high = 5`

### Step-by-Step Execution:

#### **First Iteration:**
- **Condition:** `low < high` (0 < 5) → true
- **Check:** `if (arr[low] < 0)` (12 < 0) → false
- **Check:** `else if (arr[high] > 0)` (6 > 0) → true
  - Execute `high--;`
  - **State:** `high = 4`

#### **Second Iteration:**
- **Condition:** `low < high` (0 < 4) → true
- **Check:** `if (arr[low] < 0)` (12 < 0) → false
- **Check:** `else if (arr[high] > 0)` (-8 > 0) → false
- **Else Block:** 
  - Execute `swap(arr[low], arr[high]);`
  - `swap(arr[0], arr[4]);` (12 and -8 are swapped)
  - **State:** `arr = [-8, -7, 5, -3, 12, 6]`
  - Then execute `low++` and `high--`.
  - **State:** `low = 1`, `high = 3`

#### **Third Iteration:**
- **Condition:** `low < high` (1 < 3) → true
- **Check:** `if (arr[low] < 0)` (-7 < 0) → true
  - Execute `low++;`
  - **State:** `low = 2`

#### **Fourth Iteration:**
- **Condition:** `low < high` (2 < 3) → true
- **Check:** `if (arr[low] < 0)` (5 < 0) → false
- **Check:** `else if (arr[high] > 0)` (-3 > 0) → false
- **Else Block:**
  - Execute `swap(arr[low], arr[high]);`
  - `swap(arr[2], arr[3]);` (5 and -3 are swapped)
  - **State:** `arr = [-8, -7, -3, 5, 12, 6]`
  - Then execute `low++` and `high--`.
  - **State:** `low = 3`, `high = 2`

#### **Fifth Iteration:**
- **Condition:** `low < high` (3 < 2) → false
- Exit the while loop.

### Final State of `arr`:
- After the loop completes, the rearranged array is:
```cpp
arr = [-8, -7, -3, 5, 12, 6]
```
- All negative numbers are now on the left side, and all positive numbers are on the right side.

### Summary
- The function efficiently rearranges the elements of the array in place using two pointers:
  - The `low` pointer finds positive numbers and the `high` pointer finds negative numbers.
  - When a positive number is found at the `low` index and a negative number is found at the `high` index, they are swapped.
  - The process continues until the two pointers cross each other. This method effectively sorts negative and positive numbers without using extra space for another array.
