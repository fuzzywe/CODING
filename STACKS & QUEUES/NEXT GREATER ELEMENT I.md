Next Greater Element Using Stack
 
![WhatsApp Image 2024-10-28 at 18 01 50_880d4259](https://github.com/user-attachments/assets/521e8df8-9fc3-4207-8f24-d78c65218ef8)

![WhatsApp Image 2024-10-28 at 18 02 09_d12451d4](https://github.com/user-attachments/assets/799b0355-b09e-4a38-beba-d29d552a8415)


7
Problem Statement: Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

Examples:

Example 1: 

Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}

Output: 10,-1,6,6,2,6,7,7,9,9,10

Explanation: For the first element in A ,i.e, 3, the greater element which comes next to it while traversing and is closest to it is 10. Hence,10 is present on index 0 in the resultant array. Now for the second element,i.e, 10, there is no greater number and hence -1 is it’s next greater element (NGE). Similarly, we got the NGEs for all other elements present in A.  


Example 2:

Input:  N = 6, A[] = {5,7,1,7,6,0}

Output: 7,-1,7,-1,7,5
Let's perform a dry run for the given code to understand how it works step by step. The code is designed to find the **next greater element** of each element in `nums1` based on `nums2`.

### Code Breakdown

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(); // Step 1
        int n2=nums2.size(); // Step 2
        map<int,int> m;      // Step 3
        stack<int> st;       // Step 4

        // Step 5: Traverse nums2 in reverse to build the map of next greater elements
        for(int i=n2-1;i>=0;i--){ 
            while(!st.empty() && st.top()<nums2[i]) // Step 6
                st.pop(); // Step 7

            if(st.empty()){ // Step 8
                m[nums2[i]]=-1;  // Step 9
            }
            else{
                m[nums2[i]]=st.top(); // Step 10
            }
            st.push(nums2[i]); // Step 11
        }

        vector<int> ans; // Step 12
        for(int i=0;i<n1;i++) // Step 13
            ans.push_back(m[nums1[i]]); // Step 14
        return ans; // Step 15
    }
};
```

### Dry Run Example

#### Input:
- `nums1 = [4, 1, 2]`
- `nums2 = [1, 3, 4, 2]`

#### Step-by-step Dry Run:

1. **Step 1**: `n1 = nums1.size()` -> `n1 = 3`
   - This stores the size of `nums1`.

2. **Step 2**: `n2 = nums2.size()` -> `n2 = 4`
   - This stores the size of `nums2`.

3. **Step 3**: `map<int, int> m;`
   - Initialize an empty map `m` to store the next greater element of each number in `nums2`.

4. **Step 4**: `stack<int> st;`
   - Initialize an empty stack `st` to assist in finding the next greater element.

5. **Step 5**: Start traversing `nums2` from right to left.
   - **Iteration 1**: `i = 3`, `nums2[3] = 2`
     - **Step 6**: The stack is empty, so we skip the `while` loop.
     - **Step 8**: The stack is empty, so `m[2] = -1` (no greater element).
     - **Step 11**: Push `2` onto the stack. `st = [2]`.

   - **Iteration 2**: `i = 2`, `nums2[2] = 4`
     - **Step 6**: `st.top() = 2` and `2 < 4`, so pop `2` from the stack. `st = []`.
     - **Step 8**: The stack is empty, so `m[4] = -1` (no greater element).
     - **Step 11**: Push `4` onto the stack. `st = [4]`.

   - **Iteration 3**: `i = 1`, `nums2[1] = 3`
     - **Step 6**: `st.top() = 4` and `4 > 3`, so skip the `while` loop.
     - **Step 10**: Set `m[3] = st.top() = 4` (next greater element for 3 is 4).
     - **Step 11**: Push `3` onto the stack. `st = [4, 3]`.

   - **Iteration 4**: `i = 0`, `nums2[0] = 1`
     - **Step 6**: `st.top() = 3` and `3 > 1`, so skip the `while` loop.
     - **Step 10**: Set `m[1] = st.top() = 3` (next greater element for 1 is 3).
     - **Step 11**: Push `1` onto the stack. `st = [4, 3, 1]`.

   After this loop, the map `m` looks like this:
   ```
   m = {2: -1, 4: -1, 3: 4, 1: 3}
   ```

6. **Step 12**: `vector<int> ans;`
   - Initialize an empty vector `ans` to store the results.

7. **Step 13**: Traverse `nums1` to build the result vector `ans` based on the map `m`.
   - **Iteration 1**: `i = 0`, `nums1[0] = 4`
     - **Step 14**: `m[4] = -1`, so `ans = [-1]`.
   - **Iteration 2**: `i = 1`, `nums1[1] = 1`
     - **Step 14**: `m[1] = 3`, so `ans = [-1, 3]`.
   - **Iteration 3**: `i = 2`, `nums1[2] = 2`
     - **Step 14**: `m[2] = -1`, so `ans = [-1, 3, -1]`.

8. **Step 15**: Return the result vector `ans = [-1, 3, -1]`.

#### Output:
```cpp
[-1, 3, -1]
```

### Explanation of Output:
- For `4` in `nums1`, there is no greater element in `nums2`, so `-1`.
- For `1` in `nums1`, the next greater element in `nums2` is `3`.
- For `2` in `nums1`, there is no greater element in `nums2`, so `-1`.
- Time Complexity: O(N)

Space Complexity: O(N)
