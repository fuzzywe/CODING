Minimum number of swaps required to sort an array


Examples: 

Input: {4, 3, 2, 1}
Output: 2
Explanation: Swap index 0 with 3 and 1 with 2 to form the sorted array {1, 2, 3, 4}

Input: {1, 5, 4, 3, 2}
Output: 2

  brute force using greedy algorithm
// C++ program to find minimum number
// of swaps required to sort an array
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int indexOf(vector<int>& arr, int ele)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == ele) {
            return i;
        }
    }
    return -1;
}

// Return the minimum number
// of swaps required to sort the array
int minSwaps(vector<int> arr, int N)
{
    int ans = 0;
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    for (int i = 0; i < N; i++) {

        // This is checking whether
        // the current element is
        // at the right place or not
        if (arr[i] != temp[i]) {
            ans++;

            // Swap the current element
            // with the right index
            // so that arr[0] to arr[i] is sorted
            swap(arr, i, indexOf(arr, temp[i]));
        }
    }
    return ans;
}

// Driver Code
int main()
{

    vector<int> a
        = { 101, 758, 315, 730, 472, 619, 460, 479 };

    int n = a.size();

    // Output will be 5
    cout << minSwaps(a, n);
}

// This code is contributed by mohit kumar 29

The minimum number of swaps required to sort an array using Hash-Map: 

// C++ program to find
// minimum number of swaps
// required to sort an array
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int> arr, int N)
{
    int ans = 0;
    vector<int> temp = arr;

    // Hashmap which stores the
    // indexes of the input array
    map<int, int> h;

    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        h[arr[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        // This is checking whether
        // the current element is
        // at the right place or not
        if (arr[i] != temp[i]) {
            ans++;
            int init = arr[i];

            // If not, swap this element
            // with the index of the
            // element which should come here
            swap(arr, i, h[temp[i]]);

            // Update the indexes in
            // the hashmap accordingly
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}

// Driver code
int main()
{
    vector<int> a
        = { 101, 758, 315, 730, 472, 619, 460, 479 };
    int n = a.size();
   
    cout << minSwaps(a, n);
}

// This code is contributed by Stream_Cipher
Let's go through a **dry run** of the given code to understand how it works step by step. The goal of this program is to find the **minimum number of swaps** required to sort an array.

### Initial Setup:
The input array is:

```
arr = {101, 758, 315, 730, 472, 619, 460, 479}
```

Size of array (`N`) = 8

### Step-by-step Breakdown:

1. **Step 1: Create a sorted version of the array**:
   The array `temp` is a sorted version of `arr`. The sorting operation is done here:
   ```cpp
   sort(temp.begin(), temp.end());
   ```

   So, `temp` will be:
   ```
   temp = {101, 315, 460, 472, 479, 619, 730, 758}
   ```

2. **Step 2: Create a hash map (`h`) to store the original indexes of elements**:
   This step creates a hash map (`h`) where the keys are the elements of the original array, and the values are their indices in `arr`.

   After this loop:
   ```cpp
   for (int i = 0; i < N; i++) {
       h[arr[i]] = i;
   }
   ```

   The hash map (`h`) looks like this:
   ```
   h = {
       101: 0,
       758: 1,
       315: 2,
       730: 3,
       472: 4,
       619: 5,
       460: 6,
       479: 7
   }
   ```

3. **Step 3: Compare and swap elements to their correct position**:
   Now, the program checks if each element of the original array (`arr`) is already in its correct position as per the sorted array (`temp`).

   For each element:
   - If `arr[i]` is not in the right place (i.e., if `arr[i] != temp[i]`), a swap is performed.
   - The `swap` function is called to swap the current element with the element that should be in the current position based on `temp`.
   - After each swap, the hash map (`h`) is updated to reflect the new positions of the swapped elements.

### Dry Run:

#### Initial State:
```
arr  = {101, 758, 315, 730, 472, 619, 460, 479}
temp = {101, 315, 460, 472, 479, 619, 730, 758}
h    = {
    101: 0,
    758: 1,
    315: 2,
    730: 3,
    472: 4,
    619: 5,
    460: 6,
    479: 7
}
```

- `ans = 0` (this is the counter for the number of swaps)

#### Iteration 1 (i = 0):
- `arr[0] = 101` and `temp[0] = 101` → They are the same, no swap needed.

#### Iteration 2 (i = 1):
- `arr[1] = 758` and `temp[1] = 315` → They are not the same, a swap is needed.
  
  Swap `arr[1]` with `arr[h[temp[1]]]`, which is `arr[2]` (since `h[315] = 2`):
  ```
  Swap(arr, 1, 2)
  ```

  After the swap, the array becomes:
  ```
  arr = {101, 315, 758, 730, 472, 619, 460, 479}
  ```

  Update the hash map:
  ```
  h[758] = 2
  h[315] = 1
  ```

  Increment `ans`:
  ```
  ans = 1
  ```

#### Iteration 3 (i = 2):
- `arr[2] = 758` and `temp[2] = 460` → They are not the same, a swap is needed.
  
  Swap `arr[2]` with `arr[h[temp[2]]]`, which is `arr[6]` (since `h[460] = 6`):
  ```
  Swap(arr, 2, 6)
  ```

  After the swap, the array becomes:
  ```
  arr = {101, 315, 460, 730, 472, 619, 758, 479}
  ```

  Update the hash map:
  ```
  h[758] = 6
  h[460] = 2
  ```

  Increment `ans`:
  ```
  ans = 2
  ```

#### Iteration 4 (i = 3):
- `arr[3] = 730` and `temp[3] = 472` → They are not the same, a swap is needed.
  
  Swap `arr[3]` with `arr[h[temp[3]]]`, which is `arr[4]` (since `h[472] = 4`):
  ```
  Swap(arr, 3, 4)
  ```

  After the swap, the array becomes:
  ```
  arr = {101, 315, 460, 472, 730, 619, 758, 479}
  ```

  Update the hash map:
  ```
  h[730] = 4
  h[472] = 3
  ```

  Increment `ans`:
  ```
  ans = 3
  ```

#### Iteration 5 (i = 4):
- `arr[4] = 730` and `temp[4] = 479` → They are not the same, a swap is needed.
  
  Swap `arr[4]` with `arr[h[temp[4]]]`, which is `arr[7]` (since `h[479] = 7`):
  ```
  Swap(arr, 4, 7)
  ```

  After the swap, the array becomes:
  ```
  arr = {101, 315, 460, 472, 479, 619, 758, 730}
  ```

  Update the hash map:
  ```
  h[730] = 7
  h[479] = 4
  ```

  Increment `ans`:
  ```
  ans = 4
  ```

#### Iteration 6 (i = 5):
- `arr[5] = 619` and `temp[5] = 619` → They are the same, no swap needed.

#### Iteration 7 (i = 6):
- `arr[6] = 758` and `temp[6] = 730` → They are not the same, a swap is needed.
  
  Swap `arr[6]` with `arr[h[temp[6]]]`, which is `arr[7]` (since `h[730] = 7`):
  ```
  Swap(arr, 6, 7)
  ```

  After the swap, the array becomes:
  ```
  arr = {101, 315, 460, 472, 479, 619, 730, 758}
  ```

  Update the hash map:
  ```
  h[730] = 6
  h[758] = 7
  ```

  Increment `ans`:
  ```
  ans = 5
  ```

#### Iteration 8 (i = 7):
- `arr[7] = 758` and `temp[7] = 758` → They are the same, no swap needed.

### Final Output:
After all the iterations, the array is sorted with a total of `5` swaps. Therefore, the function will return:
```
5
```

### Conclusion:
- The minimum number of swaps required to sort the array is **5**.

