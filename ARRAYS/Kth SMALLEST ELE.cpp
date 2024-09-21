MISTAKES I MADE DURING CODING PLATFORM I TRIED TO REV THE ARRAY
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int low =0;
        int high = arr.size()-1;
    while (low<=high)
    {
        int temp = arr[low];
        arr[low]=arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
      for(int i=0;i<=high;i++)
      {
          if(i ==k) return arr[i];
      }
      return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends



CORRECT ANSWER:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform partition and return the pivot index
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose the last element as the pivot
        int i = low; // Index to place smaller elements

        // Partitioning the array
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        // Place pivot in its correct position
        swap(arr[i], arr[high]);
        return i; // Return the index of the pivot
    }

    // Quickselect algorithm to find the k-th smallest element
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pivotIndex = partition(arr, low, high);

            // If pivotIndex is the k-1th index, we found the k-th smallest element
            if (pivotIndex == k - 1) {
                return arr[pivotIndex];
            }
            // If pivotIndex is greater than k-1, the k-th smallest element is in the left partition
            else if (pivotIndex > k - 1) {
                return quickSelect(arr, low, pivotIndex - 1, k);
            }
            // If pivotIndex is less than k-1, the k-th smallest element is in the right partition
            else {
                return quickSelect(arr, pivotIndex + 1, high, k);
            }
        }
        return -1; // Should not reach here
    }

    // Function to find the k-th smallest element in the array
    int kthSmallest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k);
    }
};

//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int k;
        vector<int> arr, brr;
        string input;
        
        // Get input for the array arr
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        
        // Get input for k
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            brr.push_back(number);
        }
        k = brr[0];
        
        // Call the kthSmallest function
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

Time Complexity:
Best/Average case: O(n).
Worst case: O(n²).
Space Complexity:
Best/Average case: O(log n).
Worst case: O(n).
The Quickselect algorithm is typically very efficient in practice and is widely used when we want to find the k-th smallest element without fully sorting the array.

Let's walk through a **dry run** of the Quickselect algorithm to understand how it works.
  Let me simplify the explanation of the left and right partitions for you.

### Quickselect Overview:
Quickselect is similar to Quicksort, but instead of fully sorting the array, it only partially sorts it to find the k-th smallest element.

The key idea is to repeatedly "partition" the array around a **pivot** element. After partitioning:
- Elements **smaller than the pivot** go to the left.
- Elements **larger than the pivot** go to the right.

### Steps in Quickselect:
1. **Choose a Pivot:** Typically, we pick the last element of the array as the pivot.
2. **Partition:** Move elements smaller than the pivot to the left of the pivot and larger elements to the right.
3. **Check the Pivot Index:**
   - If the pivot index is `k-1`, the pivot is the k-th smallest element, so return it.
   - If the pivot index is **greater than** `k-1`, the k-th smallest element is in the **left partition**.
   - If the pivot index is **less than** `k-1`, the k-th smallest element is in the **right partition**.

### Key to Understanding Left and Right Partition:
- The **left partition** contains elements **smaller than or equal to the pivot**.
- The **right partition** contains elements **larger than the pivot**.

### Example Walkthrough:
Let's use this array as an example:
```cpp
arr = [7, 10, 4, 3, 20, 15]
k = 3
```
We want to find the **3rd smallest element**.

#### First Partition (Pivot = 15):
- Pivot: `15`
- After partitioning, elements smaller than `15` go to the left:
  - `arr = [7, 10, 4, 3, 15, 20]`
  - Pivot index = 4 (position of `15`).

- Since `pivotIndex = 4` (and we are looking for the 3rd smallest element), we know the 3rd smallest element must be in the **left partition** (`[7, 10, 4, 3]`).
  - So we now focus on the left part: `arr = [7, 10, 4, 3]`.

#### Second Partition (Pivot = 3):
- Pivot: `3`
- After partitioning, elements smaller than `3` go to the left (there are none smaller), so `3` stays at index 0:
  - `arr = [3, 10, 4, 7, 15, 20]`
  - Pivot index = 0 (position of `3`).

- Since `pivotIndex = 0`, we know the 3rd smallest element must be in the **right partition** (`[10, 4, 7]`).

#### Third Partition (Pivot = 7):
- Pivot: `7`
- After partitioning:
  - `arr = [3, 4, 7, 10, 15, 20]`
  - Pivot index = 2 (position of `7`).

- Since `pivotIndex = 2` and `k = 3`, we have found the 3rd smallest element: **7**.

### Summary:
- In each step, we check the pivot index.
- If the pivot index is greater than the target `k`, we explore the left partition.
- If the pivot index is smaller, we explore the right partition.
- We repeat this process until we find the k-th smallest element.

In this case:
- 1st partition led us to search the left.
- 2nd partition led us to search the right.
- 3rd partition found the result. 

I hope this clears up the confusion!

### Example Input:

```cpp
arr = [7, 10, 4, 3, 20, 15]
k = 3
```

We want to find the **3rd smallest element** in this array.

### Step-by-step Dry Run:

#### Initial Call to `kthSmallest(arr, k = 3)`:
- Call: `quickSelect(arr, low = 0, high = 5, k = 3)`.

#### First Call to `partition(arr, low = 0, high = 5)`:
- The pivot is chosen as the last element, `arr[high] = 15`.
- We iterate through the array from `low` to `high-1` and compare each element with the pivot (15).
  
| Index | Element | Action                      |
|-------|---------|-----------------------------|
| 0     | 7       | Swap with itself (<= 15)    |
| 1     | 10      | Swap with itself (<= 15)    |
| 2     | 4       | Swap with itself (<= 15)    |
| 3     | 3       | Swap with itself (<= 15)    |
| 4     | 20      | No action (20 > 15)         |

- After the iteration, the pivot (15) is swapped with the element at index `i = 4`.

**Result after partition**:  
`arr = [7, 10, 4, 3, 15, 20]`

- The pivot index is `4`.

#### First Decision:
- `pivotIndex = 4`, which means the pivot element `15` is the 5th smallest element.
- Since `k = 3` (we need the 3rd smallest), we search the **left half**:
  - Call: `quickSelect(arr, low = 0, high = 3, k = 3)`.

#### Second Call to `partition(arr, low = 0, high = 3)`:
- The pivot is `arr[high] = 3`.
- We iterate through the array from `low` to `high-1` and compare each element with the pivot (3).

| Index | Element | Action                    |
|-------|---------|---------------------------|
| 0     | 7       | No action (7 > 3)         |
| 1     | 10      | No action (10 > 3)        |
| 2     | 4       | No action (4 > 3)         |

- After the iteration, the pivot (3) is swapped with the element at index `i = 0`.

**Result after partition**:  
`arr = [3, 10, 4, 7, 15, 20]`

- The pivot index is `0`.

#### Second Decision:
- `pivotIndex = 0`, which means the pivot element `3` is the 1st smallest element.
- Since `k = 3`, we search the **right half**:
  - Call: `quickSelect(arr, low = 1, high = 3, k = 3)`.

#### Third Call to `partition(arr, low = 1, high = 3)`:
- The pivot is `arr[high] = 7`.
- We iterate through the array from `low` to `high-1` and compare each element with the pivot (7).

| Index | Element | Action                     |
|-------|---------|----------------------------|
| 1     | 10      | No action (10 > 7)         |
| 2     | 4       | Swap with itself (<= 7)    |

- After the iteration, the pivot (7) is swapped with the element at index `i = 2`.

**Result after partition**:  
`arr = [3, 4, 7, 10, 15, 20]`

- The pivot index is `2`.

#### Final Decision:
- `pivotIndex = 2`, which means the pivot element `7` is the 3rd smallest element.
- Since `pivotIndex + 1 = 3`, we have found our result.

### Final Result:
The **3rd smallest element** in the array `[3, 4, 7, 10, 15, 20]` is **7**.

### Conclusion:
- The 3rd smallest element is **7**.

### Dry Run Recap:

1. **First partition** gives pivot index 4 (`15`).
2. **Second partition** gives pivot index 0 (`3`).
3. **Third partition** gives pivot index 2 (`7`).

Finally, the 3rd smallest element is found to be `7`.






//Back-end complete function template for C++

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {

        int max_element = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] > max_element) {
                max_element = arr[i];
            }
        }

        // Create an array to store the frequency of each
        // element in the input array
        int freq[max_element + 1] = {0};
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        // Keep track of the cumulative frequency of elements
        // in the input array
        int count = 0;
        for (int i = 0; i <= max_element; i++) {
            if (freq[i] != 0) {
                count += freq[i];
                if (count >= k) {
                    // If we have seen k or more elements,
                    // return the current element
                    return i;
                }
            }
        }
        return -1;
    }
};
Complexity
Time Complexity: O(n*logn)
The time complexity of the quick select algorithm is on average O(n*logn), where 'n' is the number of elements in the array.
The randomization in choosing the pivot helps achieve this average time complexity.
However, in the worst case, the time complexity can degrade to O(n^2), but this is rare and occurs when consistently bad pivots are chosen.
Space Complexity: O(logn)
The space complexity is O(log n) on average due to the recursive calls in the call stack.
In the worst case, the space complexity can be O(n) if the recursion tree is skewed, but again, this is uncommon.

### Explanation of the Solution

The solution provided is not based on the **QuickSelect** algorithm as mentioned in the time complexity explanation but is instead a **frequency counting algorithm**. Let’s go through the actual algorithm and its dry run to understand the steps and the logic clearly.

### Key Idea:
- The algorithm counts the frequency of each element in the array.
- It uses an auxiliary array (`freq`) where the index represents the value of the elements, and the value at each index represents the count of occurrences of that element.
- The cumulative frequency is used to identify when we reach the k-th smallest element.

### Time Complexity:
- **Time Complexity**: The actual algorithm has a time complexity of **O(n + m)**, where:
  - `n` is the number of elements in the input array.
  - `m` is the maximum value in the input array (since we need an auxiliary array to count frequencies up to the maximum element).
  
- **Space Complexity**: The space complexity is **O(m)** because of the `freq` array, where `m` is the maximum value in the array.

The time complexity explanation provided earlier refers to a different algorithm (likely QuickSelect), but the provided solution uses frequency counting. So the correct time complexity for this solution is **O(n + m)**, not **O(n log n)**.

---

### Dry Run of the Code

Let’s dry run the solution using an example:

#### Input:
- `arr = [7, 10, 4, 3, 20, 15]`
- `k = 3`

We need to find the 3rd smallest element.

#### Step-by-Step Execution:

1. **Step 1: Find the maximum element in the array.**
   - Initialize `max_element = arr[0] = 7`.
   - Loop through the array:
     - Compare `arr[1] = 10` with `max_element`, update `max_element = 10`.
     - Compare `arr[2] = 4` with `max_element`, no change.
     - Compare `arr[3] = 3` with `max_element`, no change.
     - Compare `arr[4] = 20` with `max_element`, update `max_element = 20`.
     - Compare `arr[5] = 15` with `max_element`, no change.
   - At the end of this loop, `max_element = 20`.

2. **Step 2: Create and populate the frequency array.**
   - Initialize the `freq` array with size `max_element + 1 = 21`. All elements in `freq` are initially 0.
   - Loop through the input array and update the `freq` array:
     - For `arr[0] = 7`, increment `freq[7]` by 1 → `freq[7] = 1`.
     - For `arr[1] = 10`, increment `freq[10]` by 1 → `freq[10] = 1`.
     - For `arr[2] = 4`, increment `freq[4]` by 1 → `freq[4] = 1`.
     - For `arr[3] = 3`, increment `freq[3]` by 1 → `freq[3] = 1`.
     - For `arr[4] = 20`, increment `freq[20]` by 1 → `freq[20] = 1`.
     - For `arr[5] = 15`, increment `freq[15]` by 1 → `freq[15] = 1`.

   - Now, the `freq` array looks like this (only non-zero values are shown for clarity):
     ```
     freq = [0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
     ```

3. **Step 3: Find the k-th smallest element.**
   - Initialize `count = 0`.
   - Loop through the `freq` array and keep a cumulative count of elements:
     - For `i = 0`, `freq[0] = 0` → `count = 0`.
     - For `i = 1`, `freq[1] = 0` → `count = 0`.
     - For `i = 2`, `freq[2] = 0` → `count = 0`.
     - For `i = 3`, `freq[3] = 1` → `count = 1`.
     - For `i = 4`, `freq[4] = 1` → `count = 2`.
     - For `i = 5`, `freq[5] = 0` → `count = 2`.
     - For `i = 6`, `freq[6] = 0` → `count = 2`.
     - For `i = 7`, `freq[7] = 1` → `count = 3`.

   - At this point, `count = 3`, which is equal to `k`. Hence, the 3rd smallest element is `i = 7`.

---

### Conclusion:

- The 3rd smallest element in the array `[7, 10, 4, 3, 20, 15]` is `7`, which is returned as the result.
- The algorithm efficiently finds the k-th smallest element using frequency counting without the need to sort the array
, making it faster in certain cases where the maximum value of elements (`max_element`) is not excessively large.


Time Complexity: O(n + max_element).
Space Complexity: O(max_element).

  
