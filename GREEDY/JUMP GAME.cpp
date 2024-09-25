Jump Game - I


22

0
Problem Statement: Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

Examples
Example 1:
Input:nums = [2, 3, 1, 0, 4]
                
Output: True
Explanation: 
                
We start at index 0, with value 2 this means we can jump to index 1 or 2.
From index 1, with value 3, we can jump to index 2, 3, or 4. However, if we jump to index 2 with value 1, we can only jump to index 3.
So we jump to index 1 then index 4 reaching the end of the array.
Hence, we return true.

Example 2:
Input:nums = [3, 2, 1, 0, 4]
                
Output: False
Explanation: 
                
We start at index 0, with value 3 which means we can jump to index 1, 2, or 3.
From index 1, with value 2 we can only jump to index 2 or 3.
From index 2, with value 1 we can only jump to index 3.
From index 3, with value 0 we cannot jump any further.
Hence, from all possibilities we are unable to jump to the last index so we return false.


#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to determine if
// you can reach the last index
bool canJump(vector<int>& nums) {
    // Initialize the maximum
    // index that can be reached
    int maxIndex = 0;

    // Iterate through each
    // index of the array
    for(int i = 0; i < nums.size(); i++){
        // If the current index is greater
        // than the maximum reachable index
        // it means we cannot move forward
        // and should return false
        if (i > maxIndex){
            return false;
        }

        // Update the maximum index
        // that can be reached by comparing
        // the current maxIndex with the sum of
        // the current index and the
        // maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }
    
    // If we complete the loop,
    //it means we can reach the
    // last index
    return true;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    bool ans = canJump(nums);
    
    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }
    
    return 0;
}
                            
                        
Output Array representing maximum jump from each index: 4 3 7 1 2

It is possible to reach the last index.

Complexity Analysis

Time Complexity: O(N) where N is the length of the input array. We iterate through the input array exactly once and at each element perform constant time operations.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.


  Let's dry run the code using the input `nums = {4, 3, 7, 1, 2}`:

The goal of the code is to determine whether we can jump from the first index to the last index in the array, where each element in the array represents the maximum number of steps that can be jumped from that index.

### Code Walkthrough:

#### Initial Setup:
```cpp
vector<int> nums = {4, 3, 7, 1, 2};
```
- We initialize `nums` with the values `{4, 3, 7, 1, 2}`.

#### Printing the Array:
```cpp
cout << "Array representing maximum jump from each index: ";
for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
}
cout << endl;
```
- This loop prints out the array, so the output will be:
  ```
  Array representing maximum jump from each index: 4 3 7 1 2
  ```

#### CanJump Function Execution:
```cpp
bool ans = canJump(nums);
```
Now, the `canJump()` function is called with `nums` as input. Let’s dry run this function step by step:

1. **Initialize `maxIndex` to 0:**
   ```cpp
   int maxIndex = 0;
   ```

2. **Start the loop from `i = 0` to `i = 4` (because `nums.size() = 5`):**
   ```cpp
   for(int i = 0; i < nums.size(); i++){
   ```

#### Iteration 1 (`i = 0`):
- **Check if `i > maxIndex` (i.e., `0 > 0`)**:
  ```cpp
  if (i > maxIndex) {
      return false;
  }
  ```
  - Since `0` is not greater than `0`, this check passes, and we don't return `false`.

- **Update `maxIndex`:**
  ```cpp
  maxIndex = max(maxIndex, i + nums[i]);  // max(0, 0 + 4) = 4
  ```
  - Now, `maxIndex` becomes `4`.

#### Iteration 2 (`i = 1`):
- **Check if `i > maxIndex` (i.e., `1 > 4`)**:
  - Since `1` is not greater than `4`, this check passes.

- **Update `maxIndex`:**
  ```cpp
  maxIndex = max(maxIndex, i + nums[i]);  // max(4, 1 + 3) = 4
  ```
  - The value of `maxIndex` remains `4`.

#### Iteration 3 (`i = 2`):
- **Check if `i > maxIndex` (i.e., `2 > 4`)**:
  - Since `2` is not greater than `4`, this check passes.

- **Update `maxIndex`:**
  ```cpp
  maxIndex = max(maxIndex, i + nums[i]);  // max(4, 2 + 7) = 9
  ```
  - Now, `maxIndex` becomes `9`.

#### Iteration 4 (`i = 3`):
- **Check if `i > maxIndex` (i.e., `3 > 9`)**:
  - Since `3` is not greater than `9`, this check passes.

- **Update `maxIndex`:**
  ```cpp
  maxIndex = max(maxIndex, i + nums[i]);  // max(9, 3 + 1) = 9
  ```
  - The value of `maxIndex` remains `9`.

#### Iteration 5 (`i = 4`):
- **Check if `i > maxIndex` (i.e., `4 > 9`)**:
  - Since `4` is not greater than `9`, this check passes.

- **Update `maxIndex`:**
  ```cpp
  maxIndex = max(maxIndex, i + nums[i]);  // max(9, 4 + 2) = 9
  ```
  - The value of `maxIndex` remains `9`.

#### End of Loop:
- The loop completes without returning `false`, which means we can reach the last index.

- **Return `true`:**
  ```cpp
  return true;
  ```

### Final Output:
```cpp
if (ans) {
    cout << "It is possible to reach the last index." << endl;
} else {
    cout << "It is not possible to reach the last index." << endl;
}
```
- Since `ans = true`, the final output will be:
  ```
  It is possible to reach the last index.
  ```

### Conclusion:
The dry run shows that with the input `{4, 3, 7, 1, 2}`, it is possible to jump to the last index of the array. The algorithm correctly determines that the maximum reachable index becomes `9`, which exceeds the last index (`4`).
