Trapping Rain Water

Examples:

Input: arr[] = [3,0,0,2,0,4]
Output: 10
Explanation: 

Input: arr[] = [7,4,0,9]
Output: 10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Input: arr[] = [6,9,9]
Output: 0
Explanation:
No water will be trapped.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


   Brute force

Approach: For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

Code:

C++
Java
Python
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
Output: The water that can be trapped is 6

Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.

Space Complexity: O(1).

Let's walk through a **dry run** of the **brute force approach** line by line using the code provided to find the amount of water that can be trapped between the bars. We will go through each line in detail to understand the step-by-step process.

### Input:
```cpp
arr = {0,1,0,2,1,0,1,3,2,1,2,1}
```

### Objective:
To calculate the total amount of water that can be trapped between the bars after raining.

---

### Code:

```cpp
#include<bits/stdc++.h>
using namespace std;
```
- **Include necessary libraries** for input-output operations and standard functions.

---

```cpp
int trap(vector<int> &arr) {
```
- The function `trap` takes in a reference to a vector `arr` which contains the heights of bars. The goal is to compute how much water is trapped after rainfall.

---

```cpp
int n = arr.size();
```
- **Calculate the size** of the array `arr` and store it in `n`. 

For our input:
- `n = 12` (since there are 12 elements in the array).

---

```cpp
int waterTrapped = 0;
```
- **Initialize `waterTrapped`** to store the total water trapped. Initially, no water is trapped.

---

```cpp
for (int i = 0; i < n; i++) {
```
- This `for` loop iterates over each index `i` in the array, and for each index, we calculate how much water can be trapped above it.

For the first iteration, `i = 0`.

---

```cpp
int j = i;
int leftMax = 0, rightMax = 0;
```
- We initialize two variables, `leftMax` and `rightMax`, which will store the maximum height of bars to the left and right of the current bar at index `i`.
- Also, `j` is initialized to `i` so that we can iterate over the left and right sides of the current index `i`.

At the beginning:
- `leftMax = 0`, `rightMax = 0`, and `j = 0`.

---

```cpp
while (j >= 0) {
    leftMax = max(leftMax, arr[j]);
    j--;
}
```
- **Find the maximum bar height to the left** of index `i`. This `while` loop starts from `i` and goes to the left, updating `leftMax` to store the highest bar seen so far.

For `i = 0`:
- `j = 0`: `leftMax = max(0, arr[0]) = 0`
- `j = -1`: The loop exits as `j` is now less than `0`.

At the end of this loop:
- `leftMax = 0` (since there are no bars to the left of index 0).

---

```cpp
j = i;
while (j < n) {
    rightMax = max(rightMax, arr[j]);
    j++;
}
```
- **Find the maximum bar height to the right** of index `i`. This `while` loop starts from `i` and goes to the right, updating `rightMax` to store the highest bar seen so far.

For `i = 0`:
- `j = 0`: `rightMax = max(0, arr[0]) = 0`
- `j = 1`: `rightMax = max(0, arr[1]) = 1`
- `j = 2`: `rightMax = max(1, arr[2]) = 1`
- `j = 3`: `rightMax = max(1, arr[3]) = 2`
- The loop continues until `j = 11`: `rightMax = max(3, arr[11]) = 3`.

At the end of this loop:
- `rightMax = 3`.

---

```cpp
waterTrapped += min(leftMax, rightMax) - arr[i];
```
- **Calculate the water trapped** at index `i`. The water trapped is the minimum of the maximum heights to the left and right, minus the height at the current index `i`.

For `i = 0`:
- `min(leftMax, rightMax) = min(0, 3) = 0`
- `waterTrapped += 0 - arr[0] = 0 - 0 = 0`.

Thus, after the first iteration, `waterTrapped = 0`.

---

The loop repeats for all values of `i`:

#### Second iteration (`i = 1`):
- `leftMax = 1`, `rightMax = 3`
- `min(leftMax, rightMax) = 1`
- `waterTrapped += 1 - arr[1] = 1 - 1 = 0`.

#### Third iteration (`i = 2`):
- `leftMax = 1`, `rightMax = 3`
- `min(leftMax, rightMax) = 1`
- `waterTrapped += 1 - arr[2] = 1 - 0 = 1`.

Thus, `waterTrapped = 1`.

#### Fourth iteration (`i = 3`):
- `leftMax = 2`, `rightMax = 3`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[3] = 2 - 2 = 0`.

#### Fifth iteration (`i = 4`):
- `leftMax = 2`, `rightMax = 3`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[4] = 2 - 1 = 1`.

Thus, `waterTrapped = 2`.

#### Sixth iteration (`i = 5`):
- `leftMax = 2`, `rightMax = 3`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[5] = 2 - 0 = 2`.

Thus, `waterTrapped = 4`.

#### Seventh iteration (`i = 6`):
- `leftMax = 2`, `rightMax = 3`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[6] = 2 - 1 = 1`.

Thus, `waterTrapped = 5`.

#### Eighth iteration (`i = 7`):
- `leftMax = 3`, `rightMax = 3`
- `min(leftMax, rightMax) = 3`
- `waterTrapped += 3 - arr[7] = 3 - 3 = 0`.

#### Ninth iteration (`i = 8`):
- `leftMax = 3`, `rightMax = 2`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[8] = 2 - 2 = 0`.

#### Tenth iteration (`i = 9`):
- `leftMax = 3`, `rightMax = 2`
- `min(leftMax, rightMax) = 2`
- `waterTrapped += 2 - arr[9] = 2 - 1 = 1`.

Thus, `waterTrapped = 6`.

#### Eleventh iteration (`i = 10`):
- `leftMax = 3`, `rightMax = 1`
- `min(leftMax, rightMax) = 1`
- `waterTrapped += 1 - arr[10] = 1 - 2 = 0`.

#### Twelfth iteration (`i = 11`):
- `leftMax = 3`, `rightMax = 1`
- `min(leftMax, rightMax) = 1`
- `waterTrapped += 1 - arr[11] = 1 - 1 = 0`.

---

### Final Output:

```cpp
return waterTrapped;
```
- After processing all indices, the total water trapped is `6`.

Thus, the output is:
```cpp
The water that can be trapped is 6
```


  best solution:
Optimal Solution(Two pointer approach)
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
Output: The water that can be trapped is 6

Time Complexity: O(N) because we are using 2 pointer approach.

Space Complexity: O(1) because we are not using anything extra.
  Let's walk through a **dry run** of the optimized two-pointer approach using the given code to calculate the amount of water trapped between the bars.

### Input:
```cpp
arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
```

### Objective:
To compute the total amount of water trapped between the bars after rainfall using the two-pointer technique.

---

### Code Walkthrough:

```cpp
#include<bits/stdc++.h>
using namespace std;
```
- **Include necessary libraries** for input-output operations and standard functions.

---

```cpp
int trap(vector<int> &height) {
    int n = height.size();
```
- The function `trap` accepts a reference to a vector `height` containing the heights of the bars. We first calculate the size of the array and store it in `n`.

For the given input:
- `n = 12` (since there are 12 elements in the array).

---

```cpp
int left = 0, right = n - 1;
```
- Initialize two pointers:
  - `left` points to the start of the array (`left = 0`).
  - `right` points to the end of the array (`right = n - 1 = 11`).

---

```cpp
int res = 0;
```
- `res` will store the total amount of water trapped. Initially, no water is trapped, so `res = 0`.

---

```cpp
int maxLeft = 0, maxRight = 0;
```
- `maxLeft` keeps track of the maximum bar height to the left of the current position.
- `maxRight` keeps track of the maximum bar height to the right of the current position.

Initially:
- `maxLeft = 0`
- `maxRight = 0`

---

```cpp
while (left <= right) {
```
- We start a loop that continues as long as `left` is less than or equal to `right`.

For the first iteration:
- `left = 0`, `right = 11`.

---

```cpp
if (height[left] <= height[right]) {
```
- We compare the heights at `left` and `right`. If `height[left]` is less than or equal to `height[right]`, we process the left side; otherwise, we process the right side.

For the first iteration:
- `height[left] = 0` and `height[right] = 1`.
- Since `0 <= 1`, we proceed to handle the left side.

---

```cpp
if (height[left] >= maxLeft) {
    maxLeft = height[left];
} else {
    res += maxLeft - height[left];
}
```
- If `height[left]` is greater than or equal to `maxLeft`, we update `maxLeft`. Otherwise, we add the trapped water (`maxLeft - height[left]`) to the result.

For `left = 0`:
- `height[0] = 0` and `maxLeft = 0`.
- Since `height[0] >= maxLeft`, we update `maxLeft = 0`.
- No water is trapped here, so `res` remains `0`.

```cpp
left++;
```
- Move the `left` pointer one step to the right (`left = 1`).

---

#### Second iteration (`left = 1`, `right = 11`):
- `height[left] = 1`, `height[right] = 1`.
- Since `1 <= 1`, we process the left side.

- `height[1] = 1` and `maxLeft = 0`.
- Since `height[1] >= maxLeft`, we update `maxLeft = 1`.
- No water is trapped here, so `res = 0`.

- Move the `left` pointer one step to the right (`left = 2`).

---

#### Third iteration (`left = 2`, `right = 11`):
- `height[left] = 0`, `height[right] = 1`.
- Since `0 <= 1`, we process the left side.

- `height[2] = 0` and `maxLeft = 1`.
- Since `height[2] < maxLeft`, water is trapped here:
  - `res += maxLeft - height[2] = 1 - 0 = 1`.

- Move the `left` pointer one step to the right (`left = 3`).

---

#### Fourth iteration (`left = 3`, `right = 11`):
- `height[left] = 2`, `height[right] = 1`.
- Since `2 > 1`, we process the right side.

---

```cpp
if (height[right] >= maxRight) {
    maxRight = height[right];
} else {
    res += maxRight - height[right];
}
```
- If `height[right]` is greater than or equal to `maxRight`, we update `maxRight`. Otherwise, we add the trapped water (`maxRight - height[right]`) to `res`.

For `right = 11`:
- `height[11] = 1` and `maxRight = 0`.
- Since `height[11] >= maxRight`, we update `maxRight = 1`.
- No water is trapped here, so `res = 1`.

```cpp
right--;
```
- Move the `right` pointer one step to the left (`right = 10`).

---

#### Fifth iteration (`left = 3`, `right = 10`):
- `height[left] = 2`, `height[right] = 2`.
- Since `2 <= 2`, we process the left side.

- `height[3] = 2` and `maxLeft = 1`.
- Since `height[3] >= maxLeft`, we update `maxLeft = 2`.
- No water is trapped here, so `res = 1`.

- Move the `left` pointer one step to the right (`left = 4`).

---

#### Sixth iteration (`left = 4`, `right = 10`):
- `height[left] = 1`, `height[right] = 2`.
- Since `1 <= 2`, we process the left side.

- `height[4] = 1` and `maxLeft = 2`.
- Since `height[4] < maxLeft`, water is trapped here:
  - `res += maxLeft - height[4] = 2 - 1 = 1`.

- Move the `left` pointer one step to the right (`left = 5`).

---

#### Seventh iteration (`left = 5`, `right = 10`):
- `height[left] = 0`, `height[right] = 2`.
- Since `0 <= 2`, we process the left side.

- `height[5] = 0` and `maxLeft = 2`.
- Since `height[5] < maxLeft`, water is trapped here:
  - `res += maxLeft - height[5] = 2 - 0 = 2`.

- Move the `left` pointer one step to the right (`left = 6`).

---

#### Eighth iteration (`left = 6`, `right = 10`):
- `height[left] = 1`, `height[right] = 2`.
- Since `1 <= 2`, we process the left side.

- `height[6] = 1` and `maxLeft = 2`.
- Since `height[6] < maxLeft`, water is trapped here:
  - `res += maxLeft - height[6] = 2 - 1 = 1`.

- Move the `left` pointer one step to the right (`left = 7`).

---

#### Ninth iteration (`left = 7`, `right = 10`):
- `height[left] = 3`, `height[right] = 2`.
- Since `3 > 2`, we process the right side.

- `height[10] = 2` and `maxRight = 1`.
- Since `height[10] >= maxRight`, we update `maxRight = 2`.
- No water is trapped here, so `res = 5`.

- Move the `right` pointer one step to the left (`right = 9`).

---

#### Tenth iteration (`left = 7`, `right = 9`):
- `height[left] = 3`, `height[right] = 1`.
- Since `3 > 1`, we process the right side.

- `height[9] = 1` and `maxRight = 2`.
- Since `height[9] < maxRight`, water is trapped here:
  - `res += maxRight - height[9] = 2 - 1 = 1`.

- Move the `right` pointer one step to the left (`right = 8`).

---

#### Eleventh iteration (`left = 7`, `right = 8`):
- `height[left] = 3`, `height[right] = 2`.
- Since `3 > 2`, we process the right side.

- `height[8] = 2` and `maxRight = 2`.
- Since `height[8] >= maxRight`, we update `maxRight = 2`.
- No water is trapped here, so `res = 6`.

- Move the `right` pointer one step to the left (`right = 7`).

---

#### Twelfth iteration (`left = 7`, `right = 7`):
- Now `left = 7` and

 `right = 7`, and since `left <= right`, we process the left side.

- `height[7] = 3` and `maxLeft = 2`.
- Since `height[7] >= maxLeft`, we update `maxLeft = 3`.
- No water is trapped here, so `res = 6`.

- Move the `left` pointer one step to the right (`left = 8`), and now `left > right`, so the loop terminates.

---

### Final Output:
The total water trapped is `6`.

```cpp
int main() {
  vector <int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
```

Output:
```
The water that can be trapped is 6
```
