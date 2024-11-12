https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

https://www.naukri.com/code360/problems/largest-subarray-with-equal-number-of-0s-and-1s_839812?leftPanelTabValue=PROBLEM

Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [0, 1, 0, 1]
Output: 4
Explanation: The array from index [0...3] contains equal number of 0's and 1's. Thus maximum length of subarray having equal number of 0's and 1's is 4.
Input: arr[] = [0, 0, 1, 0, 0]
Output: 2
Explnation: The subarray arr[1..2] has one 0 and one 1. Thus the length of the longest subarray with equal 0s and 1s is 2.
 

Input: arr[] = [0]
Output: 0
Explnation: The array does not contain 1, hence the subarray cannot be found haveing equal 0s and 1s. Hence, the answer is 0.

Got it! I'll walk you through each line in detail, explaining what it does, and provide a dry run for each step using a sample array. Let’s use this array: `arr = [1, 0, 0, 1, 0, 1, 1]`.

Here is the code again for reference:

```cpp
int maxLen(int arr[], int N)
{
    int diff = 0, ans = 0;            // Step 1
    unordered_map<int, int> mp;        // Step 2
    mp[0] = -1;                        // Step 3
    
    for (int i = 0; i < N; ++i) {      // Step 4
        diff += (arr[i] ? 1 : -1);     // Step 5
        if (mp.find(diff) != mp.end()) // Step 6
            ans = max(ans, i - mp[diff]); // Step 7
        else
            mp[diff] = i;              // Step 8
    }
    
    return ans;                        // Step 9
}
```


To find the **largest subarray with equal numbers of 0's and 1's**, the approach is based on finding subarrays where the **difference between the count of 1's and 0's is zero**. Here's the breakdown of how you can do that using a formula-like method:

### Concept:
1. **Transform the array**:
   - Replace `0` with `-1` and leave `1` as `1`. This simplifies the problem to finding a subarray whose sum is `0`.

2. **Track the cumulative sum**:
   - As you traverse the array, calculate a **running sum** (`diff`), which represents the difference between the count of 1's and 0's encountered so far.
   
   - `diff[i] = diff[i-1] + (arr[i] == 1 ? 1 : -1)`

3. **Use a hash map**:
   - Store the first occurrence of each `diff` in a hash map. The key is the `diff`, and the value is the index where this `diff` first appeared.
   - If the same `diff` value is encountered again, it means that there is a subarray between the two indices (from the first occurrence to the current index) where the number of `1`s and `0`s are balanced.

4.Calculate the subarray length:

The length of the subarray where the sum is 0 can be calculated as:
length
=
current index
−
first occurrence index of the same diff
**length=current index−first occurrence index of the same diffv**


5. **Find the largest subarray**:
   - Keep track of the largest length of such subarrays.

### Formula:
For an array `arr[]` of size `N`, the steps for finding the largest subarray are:

1. Replace every `0` with `-1` in `arr[]`.

2. Initialize:
   - `diff = 0`
   - `ans = 0` (for the largest subarray length)
   - `mp = {0: -1}` (to store the first occurrence of each `diff` value)

3. Traverse the array:
   - Update the `diff` based on the current value (`arr[i]`):
     - If `arr[i] == 1`, then `diff += 1`
     - If `arr[i] == 0`, then `diff -= 1`

![12 11 2024_21 31 32_REC](https://github.com/user-attachments/assets/e0c0e97d-3817-44b9-abd9-89d5986a2337)

**In the context of finding the largest subarray with an equal number of 1's and 0's, diff is the cumulative difference between the number of ****1's and 0's you have encountered up to the current index in the array.**

The line mp[0] = -1; is crucial for ensuring that the length of a valid subarray is correctly calculated when the subarray starts from the beginning of the array.

Why do we need this?
Initial diff Value:
At the beginning of the loop, diff starts at 0. We need to account for the possibility that the first subarray (from index 0 to some later index i) might already have an equal number of 1's and 0's. For this case, the subarray's length should be calculated from the start of the array.

Handling the Case of diff == 0:
If the diff value reaches 0 at any index (other than the first one), it indicates that the number of 1s and 0s up to that index are balanced. Without the initial mp[0] = -1, when we encounter diff == 0 at some index i, we'd incorrectly calculate the subarray length as i - mp[0] because there would be no entry for 0 in the mp map, and the map lookup would fail.

By explicitly setting mp[0] = -1, we ensure that:

If diff is 0 at index i, then the subarray from index 0 to index i is a valid candidate for having an equal number of 1's and 0's. The length of this subarray would be calculated as i - (-1), which is i + 1.

### Example:

For the array `arr = [1, 0, 0, 1, 0, 1, 1]`:

1. **Transform the array**:  
   `arr = [1, -1, -1, 1, -1, 1, 1]` (replace `0` with `-1`).

2. **Initialize**:
   - `diff = 0`, `ans = 0`, `mp = {0: -1}`.

3. **Loop through the array**:
   
   - **i = 0**: `arr[0] = 1`, `diff = 1`.  
     `mp[1] = 0`.

   - **i = 1**: `arr[1] = -1`, `diff = 0`.  
     `ans = max(ans, 1 - (-1)) = 2`.  
     `mp = {0: -1, 1: 0}`.

   - **i = 2**: `arr[2] = -1`, `diff = -1`.  
     `mp[-1] = 2`.

   - **i = 3**: `arr[3] = 1`, `diff = 0`.  
     `ans = max(ans, 3 - (-1)) = 4`.  
     `mp = {0: -1, 1: 0, -1: 2}`.

   - **i = 4**: `arr[4] = -1`, `diff = -1`.  
     `ans = max(ans, 4 - 2) = 4`.  
     `mp = {0: -1, 1: 0, -1: 2}`.

   - **i = 5**: `arr[5] = 1`, `diff = 0`.  
     `ans = max(ans, 5 - (-1)) = 6`.  
     `mp = {0: -1, 1: 0, -1: 2}`.

   - **i = 6**: `arr[6] = 1`, `diff = 1`.  
     `ans = max(ans, 6 - 0) = 6`.  
     `mp = {0: -1, 1: 0, -1: 2}`.

4. **Result**: The maximum subarray length with an equal number of 1's and 0's is `6`.

### Final Answer:
The length of the largest subarray with an equal number of 0's and 1's is **6**.
### Explanation and Dry Run

We’ll go through each line of code, explaining its role and performing the dry run after each line for clarity.

---

#### **Step 1:** `int diff = 0, ans = 0;`
   - **Purpose**: Initialize `diff` to track the difference between `1`s and `0`s as we process the array.
   - `ans` will store the maximum length of the subarray with equal `1`s and `0`s.

   **Current values**:
   - `diff = 0`
   - `ans = 0`

---

#### **Step 2:** `unordered_map<int, int> mp;`
   - **Purpose**: Creates a hash map `mp` to store each unique `diff` and the earliest index at which it occurred. This will help us find subarrays with equal numbers of `1`s and `0`s.

   **Current values**:
   - `mp` is an empty map.

---

#### **Step 3:** `mp[0] = -1;`
   - **Purpose**: Sets `mp[0]` to `-1`, meaning if `diff` becomes `0` at index `i`, we have a balanced subarray from the beginning up to index `i`.

   **Current values**:
   - `mp = {0: -1}`

---

#### **Step 4:** `for (int i = 0; i < N; ++i)`

   We enter a loop to iterate through each element in `arr`.

---

#### **Step 5:** `diff += (arr[i] ? 1 : -1);`
   - **Purpose**: If `arr[i]` is `1`, increment `diff` by `1`. If `arr[i]` is `0`, decrement `diff` by `1`. This step adjusts the balance of `1`s and `0`s up to the current index.

---

### Dry Run with Example Array `arr = [1, 0, 0, 1, 0, 1, 1]`

We'll go through each iteration of the loop with the array:

---

- **i = 0**: `arr[0] = 1`
  - `diff += (arr[0] ? 1 : -1)` → `diff = 0 + 1 = 1`
  - **Current values**: `diff = 1`
  - `mp` does not contain `1`, so we proceed to Step 8.

#### **Step 8:** `mp[diff] = i;`
   - **Action**: `mp[1] = 0`
   - **Current values**: `mp = {0: -1, 1: 0}`

---

- **i = 1**: `arr[1] = 0`
  - `diff += (arr[1] ? 1 : -1)` → `diff = 1 - 1 = 0`
  - **Current values**: `diff = 0`
  - `mp` contains `0` at index `-1`, so we proceed to Step 7.

#### **Step 7:** `ans = max(ans, i - mp[diff]);`
   - **Calculation**: `ans = max(0, 1 - (-1)) = 2`
   - **Current values**: `ans = 2`

---

- **i = 2**: `arr[2] = 0`
  - `diff += (arr[2] ? 1 : -1)` → `diff = 0 - 1 = -1`
  - **Current values**: `diff = -1`
  - `mp` does not contain `-1`, so we proceed to Step 8.

#### **Step 8:** `mp[diff] = i;`
   - **Action**: `mp[-1] = 2`
   - **Current values**: `mp = {0: -1, 1: 0, -1: 2}`

---

- **i = 3**: `arr[3] = 1`
  - `diff += (arr[3] ? 1 : -1)` → `diff = -1 + 1 = 0`
  - **Current values**: `diff = 0`
  - `mp` contains `0` at index `-1`, so we proceed to Step 7.

#### **Step 7:** `ans = max(ans, i - mp[diff]);`
   - **Calculation**: `ans = max(2, 3 - (-1)) = 4`
   - **Current values**: `ans = 4`

---

- **i = 4**: `arr[4] = 0`
  - `diff += (arr[4] ? 1 : -1)` → `diff = 0 - 1 = -1`
  - **Current values**: `diff = -1`
  - `mp` contains `-1` at index `2`, so we proceed to Step 7.

#### **Step 7:** `ans = max(ans, i - mp[diff]);`
   - **Calculation**: `ans = max(4, 4 - 2) = 4`
   - **Current values**: `ans = 4`

---

- **i = 5**: `arr[5] = 1`
  - `diff += (arr[5] ? 1 : -1)` → `diff = -1 + 1 = 0`
  - **Current values**: `diff = 0`
  - `mp` contains `0` at index `-1`, so we proceed to Step 7.

#### **Step 7:** `ans = max(ans, i - mp[diff]);`
   - **Calculation**: `ans = max(4, 5 - (-1)) = 6`
   - **Current values**: `ans = 6`

---

- **i = 6**: `arr[6] = 1`
  - `diff += (arr[6] ? 1 : -1)` → `diff = 0 + 1 = 1`
  - **Current values**: `diff = 1`
  - `mp` contains `1` at index `0`, so we proceed to Step 7.

#### **Step 7:** `ans = max(ans, i - mp[diff]);`
   - **Calculation**: `ans = max(6, 6 - 0) = 6`
   - **Current values**: `ans = 6`

---

#### **Step 9:** `return ans;`
   - **Action**: Returns `ans = 6` as the maximum length of a subarray with equal `0`s and `1`s.

### Final Result:
The maximum length of a subarray with equal `0`s and `1`s in `[1, 0, 0, 1, 0, 1, 1]` is **6**, covering the subarray from index `0` to `5`.


---

```cpp
#include <bits/stdc++.h> 
int findSubarray(vector<int> arr)
{
    // Write your code here.
    int ans =0;
    int diff =0;
    unordered_map<int,int>mp;
 

    for(int i = 0 ; i < arr.size() ; i++){

      arr[i] =  arr[i]?1 : -1 ;

    }
    for(int i =0; i<arr.size();i++)
    {
        diff += arr[i];
        if(diff==0)
        {
            ans=i+1;
        }

        if(mp.find(diff) !=mp.end())
        {
            if(ans<i-mp[diff])
            {
                ans = i-mp[diff];
            }
        }
        else mp[diff] = i;
    }return ans;
}

```
