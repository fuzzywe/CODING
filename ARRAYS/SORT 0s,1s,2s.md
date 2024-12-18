https://leetcode.com/problems/sort-colors/description/



Sort 0s, 1s and 2s

Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
  
Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.

  
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
```cpp
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int cnt1 =0,cnt2 =0,cnt3 =0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] ==0) cnt1++;
            else if(arr[i] ==1) cnt2++;
            else if(arr[i] ==2) cnt3++;
        }
        for (int i=0;i<cnt1;i++) {arr[i]=0;}
        for(int i=cnt1;i<cnt1+cnt2;i++){arr[i]=1;}
        for(int i=cnt1+cnt2;i<arr.size();i++) {arr[i] = 2;}
    }//
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
```

Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.

Space Complexity: O(1) as we are not using any extra space.

```cpp
  BETTER:

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

Output:
After sorting:
0 0 1 1 2 2  

Complexity Analysis
Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.

Space Complexity: O(1) as we are not using any extra space.

 

```cpp
  class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>freq(3,0);
        for(auto it:nums){
            freq[it]++;
        }
        int j=0;
        for(int i=0;i<3;i++){
            while(freq[i]>0){
                nums[j]=i;
                j++;
                freq[i]--;
            }
        }
    }
};

```
Complexity
Time complexity: O(n)
Space complexity: O(1)

Let's walk through the code step by step and provide a dry run for each line.

### **Problem Overview:**

The problem is known as "Sort Colors," which asks to sort an array containing the numbers `0`, `1`, and `2` (representing three different colors). The goal is to sort the array **in place**, meaning you must not use extra space beyond a constant amount (ignoring the input/output arguments).

### **Code Explanation:**

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>freq(3,0);  // Step 1: Create a frequency array with 3 elements initialized to 0.
        for(auto it:nums){      // Step 2: Count the occurrences of 0, 1, and 2 in the input array `nums`.
            freq[it]++;         // Step 3: Increment the frequency for each color (0, 1, or 2).
        }
        int j=0;                // Step 4: Initialize an index `j` for the input array `nums`.
        for(int i=0;i<3;i++){   // Step 5: Iterate through the frequency array `freq` (for 0, 1, and 2).
            while(freq[i]>0){   // Step 6: As long as `freq[i]` is greater than 0, place the number `i` in `nums`.
                nums[j]=i;      // Step 7: Set `nums[j]` to the current number `i` (0, 1, or 2).
                j++;            // Step 8: Increment `j` to move to the next position in `nums`.
                freq[i]--;      // Step 9: Decrease the count of the current number `i` in the `freq` array.
            }
        }
    }
};
```

### **Detailed Line-by-Line Explanation:**

1. **`vector<int>freq(3,0);`**
   - We create a `freq` array of size 3 (since there are three colors: 0, 1, and 2) initialized to 0. This will be used to store the frequency (count) of each color in the `nums` array.

2. **`for(auto it: nums)`**
   - We iterate over the input array `nums` using a range-based for loop.
   - `it` represents each element of `nums`.

3. **`freq[it]++;`**
   - For each element in `nums`, we increment its corresponding value in the `freq` array.
   - For example, if `it == 0`, we increment `freq[0]`; if `it == 1`, we increment `freq[1]`, and so on.

4. **`int j = 0;`**
   - We initialize a variable `j` to 0, which will be used as the index for writing sorted values back into `nums`.

5. **`for(int i = 0; i < 3; i++)`**
   - We loop over the `freq` array. Since there are three colors (0, 1, and 2), we iterate over the indices 0, 1, and 2.

6. **`while(freq[i] > 0)`**
   - For each value of `i`, we check if the frequency `freq[i]` is greater than 0.
   - As long as there are occurrences of the color `i`, we will continue placing `i` into the `nums` array.

7. **`nums[j] = i;`**
   - We set the current element of `nums` at index `j` to the value `i`.
   - For example, if `i == 0`, we place `0` in `nums[j]`.

8. **`j++;`**
   - After placing the number `i` in `nums`, we increment `j` to move to the next position.

9. **`freq[i]--;`**
   - We decrement `freq[i]` since we just placed one occurrence of `i` in the `nums` array.
   - When `freq[i]` becomes 0, we stop placing `i` and move on to the next number (either 1 or 2).

### **Dry Run Example:**

Consider an example input array `nums = {2, 0, 2, 1, 1, 0}`.

1. **Step 1: Frequency Count:**
   - The `freq` array will be calculated as:
     - For `nums[0] = 2`, `freq[2]++` → `freq = {0, 0, 1}`
     - For `nums[1] = 0`, `freq[0]++` → `freq = {1, 0, 1}`
     - For `nums[2] = 2`, `freq[2]++` → `freq = {1, 0, 2}`
     - For `nums[3] = 1`, `freq[1]++` → `freq = {1, 1, 2}`
     - For `nums[4] = 1`, `freq[1]++` → `freq = {1, 2, 2}`
     - For `nums[5] = 0`, `freq[0]++` → `freq = {2, 2, 2}`
   
   After this loop, `freq = {2, 2, 2}` (2 occurrences of 0, 2 occurrences of 1, 2 occurrences of 2).

2. **Step 2: Sorting `nums`:**
   - Start iterating over `freq`:
   
   - For `i = 0`, `freq[0] = 2`:
     - Place `0` in `nums[0]`, `j++` → `nums = {0, 0, 2, 1, 1, 0}`, `freq[0]--` → `freq = {1, 2, 2}`
     - Place `0` in `nums[1]`, `j++` → `nums = {0, 0, 2, 1, 1, 0}`, `freq[0]--` → `freq = {0, 2, 2}`

   - For `i = 1`, `freq[1] = 2`:
     - Place `1` in `nums[2]`, `j++` → `nums = {0, 0, 1, 1, 1, 0}`, `freq[1]--` → `freq = {0, 1, 2}`
     - Place `1` in `nums[3]`, `j++` → `nums = {0, 0, 1, 1, 1, 0}`, `freq[1]--` → `freq = {0, 0, 2}`

   - For `i = 2`, `freq[2] = 2`:
     - Place `2` in `nums[4]`, `j++` → `nums = {0, 0, 1, 1, 2, 0}`, `freq[2]--` → `freq = {0, 0, 1}`
     - Place `2` in `nums[5]`, `j++` → `nums = {0, 0, 1, 1, 2, 2}`, `freq[2]--` → `freq = {0, 0, 0}`
   
   Final sorted array: `nums = {0, 0, 1, 1, 2, 2}`.

### **Time Complexity:**

- **Counting Frequencies (Step 1):**
  - We iterate over the input array `nums` once to count the frequencies.
  - **Time:** O(N), where N is the size of the `nums` array.

- **Rebuilding the Array (Step 2):**
  - We iterate over the `freq` array and the input array `nums` to sort the colors.
  - **Time:** O(N), as we iterate through the array a second time to rewrite it.

- **Overall Time Complexity:** O(N)

### **Space Complexity:**

- **Frequency Array:**
  - We use a `freq` array of size 3 to count the occurrences of 0, 1, and 2.
  - **Space:** O(1) (constant space).

- **Input Array:**
  - We are modifying the input array `nums` in place, so no extra space is needed for the result.
  - **Space:** O(1) (constant space).

- **Overall Space Complexity:** O(1)

### **Conclusion:**
This is an efficient algorithm to sort the array of colors in linear time and constant space. The time complexity is O(N), and the space complexity is O(1).

  Dutch National Flag Algo (2 pointer)

Complexity
Time complexity: O(n)
Space complexity: O(1)
Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, m, r;
        l = 0;
        m = 0;
        r = nums.size() - 1;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
                m++;
            else {
                swap(nums[m], nums[r]);
                r--;
            }
        }
    }
};
```
Let's break it down even more step by step, using simpler explanations. We will first explain the **idea behind the algorithm** and then proceed with an **easy-to-follow dry run**. Here's how it works:

### **Understanding the Algorithm:**

This algorithm solves the **Dutch National Flag problem** where we need to sort an array of 0s, 1s, and 2s. The goal is to place:
- All `0`s on the left side,
- All `1`s in the middle, and
- All `2`s on the right side of the array.

We use **three pointers**:
1. `l` (left pointer) — Tracks where the next `0` should go.
2. `m` (middle pointer) — Moves through the array to check each element.
3. `r` (right pointer) — Tracks where the next `2` should go.

**Key Operations:**
- If `nums[m] == 0`, we swap it with the element at `l`, because `0` belongs to the left.
- If `nums[m] == 1`, we do nothing and just move `m` forward, as `1` is already in the correct place.
- If `nums[m] == 2`, we swap it with the element at `r`, because `2` belongs to the right.

### **Step-by-Step Dry Run with Example:**
Let's take an example array `nums = {2, 0, 2, 1, 1, 0}` and follow how the algorithm works step by step.

---

#### **Initial State:**
- **Array:** `nums = {2, 0, 2, 1, 1, 0}`
- **Pointers:** `l = 0`, `m = 0`, `r = 5`

We start with the following positions:
- `l` (left pointer) is at index 0.
- `m` (middle pointer) is at index 0.
- `r` (right pointer) is at index 5 (the last element).

---

#### **Iteration 1 (`m = 0`):**

1. **Check:** The value at `m` (index 0) is `nums[m] = 2`.
2. **Action:** Since `nums[m] == 2`, we swap it with the element at `r` (index 5).
   - **Before Swap:** `nums = {2, 0, 2, 1, 1, 0}`
   - **After Swap:** `nums = {0, 0, 2, 1, 1, 2}`
3. **Update:** After the swap, we decrease `r` to `4` (move the right pointer left). We do **not** move `m` because we need to check the new value at index `m`.

- **Array:** `nums = {0, 0, 2, 1, 1, 2}`
- **Pointers:** `l = 0`, `m = 0`, `r = 4`

---

#### **Iteration 2 (`m = 0`):**

1. **Check:** The value at `m` (index 0) is now `nums[m] = 0`.
2. **Action:** Since `nums[m] == 0`, we swap it with the element at `l` (index 0).
   - **Before Swap:** `nums = {0, 0, 2, 1, 1, 2}`
   - **After Swap:** `nums = {0, 0, 2, 1, 1, 2}` (No change, it's a self-swap)
3. **Update:** After the swap, we increase both `l` and `m` by 1.
   - `l = 1` (move the left pointer right).
   - `m = 1` (move the middle pointer right).

- **Array:** `nums = {0, 0, 2, 1, 1, 2}`
- **Pointers:** `l = 1`, `m = 1`, `r = 4`

---

#### **Iteration 3 (`m = 1`):**

1. **Check:** The value at `m` (index 1) is `nums[m] = 0`.
2. **Action:** Since `nums[m] == 0`, we swap it with the element at `l` (index 1).
   - **Before Swap:** `nums = {0, 0, 2, 1, 1, 2}`
   - **After Swap:** `nums = {0, 0, 2, 1, 1, 2}` (No change, it's a self-swap)
3. **Update:** After the swap, we increase both `l` and `m` by 1.
   - `l = 2`, `m = 2`.

- **Array:** `nums = {0, 0, 2, 1, 1, 2}`
- **Pointers:** `l = 2`, `m = 2`, `r = 4`

---

#### **Iteration 4 (`m = 2`):**

1. **Check:** The value at `m` (index 2) is `nums[m] = 2`.
2. **Action:** Since `nums[m] == 2`, we swap it with the element at `r` (index 4).
   - **Before Swap:** `nums = {0, 0, 2, 1, 1, 2}`
   - **After Swap:** `nums = {0, 0, 1, 1, 2, 2}`
3. **Update:** After the swap, we decrease `r` to `3`. We do **not** move `m` because we need to check the new value at index `m`.

- **Array:** `nums = {0, 0, 1, 1, 2, 2}`
- **Pointers:** `l = 2`, `m = 2`, `r = 3`

---

#### **Iteration 5 (`m = 2`):**

1. **Check:** The value at `m` (index 2) is now `nums[m] = 1`.
2. **Action:** Since `nums[m] == 1`, it is already in the correct position. We just move `m` to the next element.
3. **Update:** `m = 3`.

- **Array:** `nums = {0, 0, 1, 1, 2, 2}`
- **Pointers:** `l = 2`, `m = 3`, `r = 3`

---

#### **Iteration 6 (`m = 3`):**

1. **Check:** The value at `m` (index 3) is `nums[m] = 1`.
2. **Action:** Since `nums[m] == 1`, it is already in the correct position. We just move `m` to the next element.
3. **Update:** `m = 4`.

- **Array:** `nums = {0, 0, 1, 1, 2, 2}`
- **Pointers:** `l = 2`, `m = 4`, `r = 3`

---

#### **Termination:**

- At this point, `m = 4` and `r = 3`, so the condition `m <= r` is **false**, and the loop terminates.
- The array is now sorted: `nums = {0, 0, 1, 1, 2, 2}`.

---

### **Summary of the Steps:**

- The algorithm uses three pointers to sort the array in a single pass.
- If `nums[m] == 0`, we swap it with the left pointer `l` and increment both `l` and `m`.
- If `nums[m] == 1`, we leave it in place and just increment `m`.
- If `nums[m] == 2`, we swap it with the right pointer `r` and decrement `r` (without incrementing `m`).

---

### **Final Sorted Array:**
After the full process, the array is sorted:  
**Result:** `nums = {0, 0, 1, 1, 2, 2}`

---

### **Complexity:**

- **Time Complexity:** O(n), where `n` is the size of the array, because we only traverse the array once.
- **Space Complexity:** O(1), as the sorting is done in place without using any extra space.
