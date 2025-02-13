https://leetcode.com/problems/kth-largest-element-in-an-array/description/


https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1



Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)

```cpp
Time complexity: O(n log n) (because of inserting all elements and popping from the heap).
Space complexity: O(n) (because the heap stores all n elements).
int kthSmallest(vector<int> &arr, int k) {
       priority_queue<int> maxHeap;
        
        // Push elements into the heap
        for (int i = 0; i < arr.size(); i++) {
            maxHeap.push(arr[i]);
            
            // If heap size exceeds k, remove the largest element (top)
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // The top element is the Kth smallest element
        cout << "Kth Smallest element: " << maxHeap.top() << "\n";

}
```

```cpp
Time complexity: O(n log n) (because of inserting all elements and popping from the heap).
Space complexity: O(n) (because the heap stores all n elements).
int n = arr.size(); // Get the size of the array

// Step 1: Create a max-heap (priority_queue) with all the elements
priority_queue<int> pq(arr.begin(), arr.end()); 

// Step 2: Pop elements until the remaining top element is the k-th smallest
for(int i = 0; i < n - k; i++) {
    pq.pop(); 
}

// Step 3: Return the k-th smallest element
return pq.top(); 

```


**BRUTE FORCE ALGO**
```cpp
int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
 ```

---

selection sort


---


```cpp
 int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            int smallestElement = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[smallestElement])
                {
                    smallestElement=j;
                }
            }
            swap(arr[i],arr[smallestElement]);
        }return arr[k-1];
        
    }

    ```

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

  
