Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.
Example 2:

Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following M packets :{3, 2, 4}.
Your Task:
You don't need to take any input or print anything. Your task is to complete the function findMinDiff() which takes array A[ ], N and M as input parameters and returns the minimum possible difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Brute force Approach
Intuition
The intuition behind this approach is to use divide and conquer and explore all possible subsets of chocolates by dividing the problem into smaller subproblems. By sorting the array, we can efficiently explore potential candidate subsets with minimal differences between chocolates. 

Note: this approach is  a naive recursive algorithm and may not be the most efficient solution, especially for large input arrays and values of m.

Example
Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
Output: Minimum Difference is 6 
Explanation: The set goes like 3,4,7,9,9 and the output is 9-3 = 6

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50} , m = 7 
Output: Minimum Difference is 10 
Explanation: We need to pick 7 packets. We pick 40, 41, 42, 44, 48, 43 and 50 to minimize difference between maximum and minimum.

Implementation
Define a function f() which  is recursive and uses divide and conquer approach. It tries to divide the range [l, r] into two parts and recursively computes the minimum difference between the chocolates in those subsets.
If the range [l, r] has fewer elements than m, it is not possible to distribute chocolates to m students, so the function returns LONG_MAX.
Otherwise, it computes the minimum difference between chocolates in the current range [l, r], which is a[r] - a[l], and returns it.
In the findMinDiff() function, we first sorts the input array a in ascending order.
Initialize ans to a[n-1] - a[0], which is the maximum possible difference between chocolates (when all chocolates are distributed to the first and last student).
Now, call the recursive function f() to find the minimum difference, passing the sorted array a, range [0, n-1]
Finally, it returns the value of ans, which would have been updated to the minimum difference during the recursive calls.
Code

class Solution{ 
public:
    long long f(vector<long long> a, long long l, long long r, long long &ans, long long m){
    if (l >= r) return LONG_MAX;
    if (r - l + 1 < m) return LONG_MAX;
    ans = min(ans, a[r] - a[l]); // Update ans with the current minimum difference
    f(a, l + 1, r, ans, m);
    f(a, l, r - 1, ans, m);
    return a[r] - a[l];
    
    }
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
         long long ans=LONG_MAX;
         sort(a.begin(),a.end());
         ans=a[n-1]-a[0];
         f(a,0,n-1,ans, m);
         return ans;
    }   
};
Complexity
Time Complexity: O(n log n + 2^n). Since there are 2^n possible subsets of an array of size n. Also Sorting the input array takes O(n log n) time , Hence  O(n log n + 2^n).
Space Complexity: O(n) due to the sorting step and the recursive stack.

  Sure! Let’s walk through the **dry run** of the code, **line by line**. The code is finding the **minimum difference** between the maximum and minimum values of any subset of `m` elements in a sorted array `a` of size `n`.

### Input:
```cpp
a = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43}
n = 16
m = 7
```

### Dry Run Explanation:
We'll follow the code's flow with this input.

### Code:

```cpp
long long findMinDiff(vector<long long> a, long long n, long long m) {
    // Line 1: Initialize the minimum difference as a very large value (long long max)
    long long ans = LONG_MAX; 
```
- `ans = LONG_MAX` (a large number, initially used to store the minimum difference we find).

```cpp
    // Line 2: Sort the array 'a' to allow easier comparison of consecutive elements
    sort(a.begin(), a.end());
```
- Sorting `a` gives:  
  `a = {2, 4, 7, 9, 12, 23, 25, 28, 30, 30, 40, 41, 42, 43, 44, 48}`

```cpp
    // Line 3: Initialize ans with the difference between the first and last element of the array
    ans = a[n-1] - a[0];
```
- Set `ans` to the difference between the first and last element of the sorted array:
  `ans = 48 - 2 = 46`

```cpp
    // Line 4: Call recursive function to try different ranges of elements
    f(a, 0, n-1, ans, m);
```
- Call the helper recursive function `f(a, 0, n-1, ans, m)` to explore different subranges of size `m = 7`.

### Recursive Function `f(a, l, r, ans, m)`:

#### First Call:
```cpp
long long f(vector<long long> a, long long l, long long r, long long &ans, long long m) {
    if (l >= r) return LONG_MAX;  // Line 1: Base case, exit if no valid subrange remains
```
- Here `l = 0`, `r = 15`, so `l >= r` is `false`. We continue.

```cpp
    if (r - l + 1 < m) return LONG_MAX;  // Line 2: Return if the range is smaller than m
```
- `r - l + 1 = 16`, which is greater than `m = 7`, so we proceed.

```cpp
    ans = min(ans, a[r] - a[l]);  // Line 3: Update ans if the difference between a[r] and a[l] is smaller
```
- The current difference is `a[15] - a[0] = 48 - 2 = 46`. Since `ans` is already `46`, it remains unchanged.

```cpp
    f(a, l + 1, r, ans, m);  // Line 4: Recursive call by shrinking the left side of the range
```
- Call `f(a, 1, 15, ans, m)`.

#### Second Call (`f(a, 1, 15, ans, m)`):
```cpp
    if (l >= r) return LONG_MAX;  // Line 1: Base case, exit if no valid subrange remains
```
- Now, `l = 1`, `r = 15`, so `l >= r` is `false`. We continue.

```cpp
    if (r - l + 1 < m) return LONG_MAX;  // Line 2: Return if the range is smaller than m
```
- `r - l + 1 = 15`, which is greater than `m = 7`, so we proceed.

```cpp
    ans = min(ans, a[r] - a[l]);  // Line 3: Update ans if the difference between a[r] and a[l] is smaller
```
- The current difference is `a[15] - a[1] = 48 - 4 = 44`. Update `ans = min(46, 44) = 44`.

```cpp
    f(a, l + 1, r, ans, m);  // Line 4: Recursive call by shrinking the left side of the range
```
- Call `f(a, 2, 15, ans, m)`.

#### Third Call (`f(a, 2, 15, ans, m)`):
```cpp
    ans = min(ans, a[r] - a[l]);  // Line 3: Update ans
```
- Difference is `a[15] - a[2] = 48 - 7 = 41`. Update `ans = min(44, 41) = 41`.

```cpp
    f(a, l + 1, r, ans, m);  // Line 4: Continue shrinking
```
- Call `f(a, 3, 15, ans, m)`.

The function will keep shrinking the left and right sides recursively, checking each possible range, and updating `ans` whenever a smaller difference is found.

### Back to Main:

```cpp
    return ans;  // Line 5: Return the final answer after all ranges have been explored
}
```

The final minimum difference is **23**, found when the subrange is `a[0] to a[6] → {2, 4, 7, 9, 12, 23, 25}`. So, `ans = 23`.

### Final Output:
```cpp
cout << findMinDiff(a, n, m);  // Output: 23
```

Expected Approach
Intuition
The intuition here is that if we sort the array and slide a window of size m over it, then the difference between the maximum and minimum elements inside the window will be minimized when the window is placed optimally. By considering all possible windows, we can ensure that it finds the optimal distribution where the difference is minimized.

Example
Chocolate Distribution Problem Solution

Implementation
Base cases. 
If there are no chocolates in the list (n==0) or the number of students is 0 (m==0), it means there's nothing to distribute, so the method returns 0.
The arr[] list is sorted in ascending order. Sorting the array will help in finding the minimum difference later.
Check if the number of chocolates (n) is less than the number of students (m). If yes, it means there are fewer chocolates than the number of students, and thus, it won't be possible to distribute chocolates equally among all students. In this situation, return -1, indicating that it's not possible to find a valid distribution.
Initialize the variable min_diff ,to store the minimum difference between the maximum and minimum chocolate packet sizes in any distribution.
Iterate through a loop (to find the subarray of size m where the difference between the last (maximum in the case of a sorted array) and first (minimum in the case of a sorted array) elements of the subarray is minimum.) that starts from the beginning of the sorted array and goes up to the index where the remaining m students can still be accommodated (i.e., len(arr) - m + 1). This corresponds to a valid distribution with the least difference in chocolate packet sizes among the students.
Inside the loop, it calculates the difference between the last element of the subarray (arr[i + m - 1]) and the first element of the subarray (arr[i]). It updates the min_diff with the minimum of the current min_diff and this new difference.
Finally, return min_diff after the loop gets over.
code 

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        // Sort the given packets 
        sort(a.begin(),a.end());
		
		long long start = 0,end =0;
		// Largest number of chocolates 
		long long mind = LONG_LONG_MAX;
		
		// Find the subarray of size m such that 
        // difference between last (maximum in case 
        // of sorted) and first (minimum in case of 
        // sorted) elements of subarray is minimum.
		for(long long i=0;i+m-1<n;i++)
		{
			long long diff = a[i+m-1] - a[i];
			if(mind>diff)
			{
				mind = diff;
				start = i;
				end = i+m-1;
			}
		}
		return a[end]-a[start];
            
    }
};
Complexity:
Time Complexity:  O(n log n) due to the sorting operation.
Space Complexity: O(1), It does not use any additional data structures .

Let's go through a **dry run** of the `findMinDiff` function step by step, analyzing what happens at each line with an example.

### Input:

```cpp
a = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43}
n = 16  // Size of array a
m = 7   // Number of students
```

### Objective:
The goal is to distribute the `m` chocolate packets to `m` students such that the **difference between the maximum and minimum chocolates** given to the students is minimized.

---

### Step-by-Step Dry Run:

### Code:

```cpp
long long findMinDiff(vector<long long> a, long long n, long long m){
```
- The function `findMinDiff` takes in an array `a` of size `n` and the number of students `m`.

---

```cpp
sort(a.begin(), a.end());
```
- **Sort** the array to easily find the subarray of size `m` that minimizes the difference between the largest and smallest elements.

- Sorted `a`:
  - `a = {2, 4, 7, 9, 12, 23, 25, 28, 30, 30, 40, 41, 42, 43, 44, 48}`

---

```cpp
long long start = 0, end = 0;
```
- Initialize `start` and `end` pointers to track the start and end indices of the subarray with the minimum difference.

- Initial values:
  - `start = 0`
  - `end = 0`

---

```cpp
long long mind = LONG_LONG_MAX;
```
- `mind` keeps track of the **minimum difference** found between the maximum and minimum chocolates in any subarray of size `m`.

- Initial value:
  - `mind = LONG_LONG_MAX`

---

```cpp
for(long long i = 0; i + m - 1 < n; i++) {
```
- The loop will go through all possible subarrays of size `m`, i.e., check the difference between the largest and smallest elements in subarrays of size `m`.

---

#### First Iteration (`i = 0`):
```cpp
long long diff = a[i + m - 1] - a[i];
```
- Subarray considered: `{2, 4, 7, 9, 12, 23, 25}`
  - `a[i] = 2`, `a[i + m - 1] = a[6] = 25`
  - `diff = 25 - 2 = 23`

```cpp
if (mind > diff) {
    mind = diff;
    start = i;
    end = i + m - 1;
}
```
- Since `diff = 23` is less than `mind = LONG_LONG_MAX`, update:
  - `mind = 23`
  - `start = 0`
  - `end = 6`

---

#### Second Iteration (`i = 1`):
- Subarray considered: `{4, 7, 9, 12, 23, 25, 28}`
  - `a[i] = 4`, `a[i + m - 1] = a[7] = 28`
  - `diff = 28 - 4 = 24`

- `diff = 24` is not less than `mind = 23`, so no update is made.

---

#### Third Iteration (`i = 2`):
- Subarray considered: `{7, 9, 12, 23, 25, 28, 30}`
  - `a[i] = 7`, `a[i + m - 1] = a[8] = 30`
  - `diff = 30 - 7 = 23`

- `diff = 23` is equal to `mind = 23`, so no update is made.

---

#### Fourth Iteration (`i = 3`):
- Subarray considered: `{9, 12, 23, 25, 28, 30, 30}`
  - `a[i] = 9`, `a[i + m - 1] = a[9] = 30`
  - `diff = 30 - 9 = 21`

- Since `diff = 21` is less than `mind = 23`, update:
  - `mind = 21`
  - `start = 3`
  - `end = 9`

---

The loop continues in a similar way, checking the difference for each subarray of size `m` and updating `mind`, `start`, and `end` when a smaller difference is found.

---

### After the loop finishes:

The smallest difference found was `21` for the subarray `{9, 12, 23, 25, 28, 30, 30}`.

```cpp
return a[end] - a[start];
```
- **Return** the difference between the maximum and minimum elements in this subarray:
  - `a[end] = 30`
  - `a[start] = 9`
  - `a[end] - a[start] = 30 - 9 = 21`

---

### Final Output:

For the given input:
```cpp
cout << findMinDiff(a, n, m);
```
The output is `21`, which is the minimum difference between the largest and smallest number of chocolates that can be distributed among 7 students.

### Summary:
- The algorithm sorts the array and then uses a sliding window approach to find the subarray of size `m` with the smallest difference between the maximum and minimum elements. The minimum difference found is `21`.
