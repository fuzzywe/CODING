



Example 1:![Reverse Pairs _ Hard Interview Question 2-52 screenshot](https://github.com/user-attachments/assets/40157d2c-8eb2-45bd-8c54-118c98d4418e)

![Reverse Pairs _ Hard Interview Question 10-12 screenshot](https://github.com/user-attachments/assets/f68219c7-6c4c-4680-bc27-4709c0202912)

![Reverse Pairs _ Hard Interview Question 15-13 screenshot](https://github.com/user-attachments/assets/6da62e9d-22b3-40df-aad6-e417137447e9)

![Reverse Pairs _ Hard Interview Question 19-58 screenshot](https://github.com/user-attachments/assets/03cdd0c7-bfc9-4c2b-80a2-767a10e555b1)

![Reverse Pairs _ Hard Interview Question 22-45 screenshot](https://github.com/user-attachments/assets/71b0179b-4cb7-4abc-9d14-a45e2ccf2c00)


![Reverse Pairs _ Hard Interview Question 24-39 screenshot](https://github.com/user-attachments/assets/1f0329e9-19ac-43b9-8048-bf78265f8ca8)

cnt = cnt + (right - (mid+1))


Input:
 N = 5, array[] = {1,3,2,3,1)

Output
: 2 

Explanation:
 The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Example 2:
Input:
 N = 4, array[] = {3,2,1,4}

Output:
 1

Explaination: 
There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]

---------------------------------------------------------------------------------------------------------------------------

493. Reverse Pairs
Hard
Topics
Companies
Hint
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
-----------------------------------------------------------------------------------------------------------------------------
  BRUTE FORCE

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
       
        long long cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int j = i + 1; j < nums.size(); j++)
             {
                // Cast to long long to prevent overflow
                if (nums[i] >2*(long long)nums[j]) {
                    cnt++;
                }

            }

        }

        return cnt;

    }
};

```

the time complexity of this algorithm would be O(n 2 ) which would work with minor testcases but is not efficient for testcases as large as 10 
4 so we need a more reliable algorithm to work with.


```cpp
class Solution {
public:
    void merge(vector<int>& arr, int start, int end, int& count, vector<int>& temp){
        int mid = start + (end-start)/2;
        int i = start, j = mid+1, k = start;

        while(i <= mid && j <= end){
            if(arr[i] > (long long)2 * arr[j]){
                count += (mid - i + 1);
                j++;
            }
            else{
                i++;
            }
        }

        i = start; j = mid + 1;

        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= end){
            temp[k++] = arr[j++];
        }

        while(start <= end){
            arr[start] = temp[start];
            start++;
        }
    }


    void mergesort(vector<int>& nums, int start, int end, int& count, vector<int>& temp){
        //base case
        if(start >= end){
            return;
        }

        int mid = start + (end-start)/2;
        mergesort(nums, start, mid, count, temp);
        mergesort(nums, mid+1, end, count, temp);
        merge(nums, start, end, count, temp);
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0, start = 0, end = n-1;
        vector<int> temp(n);
        mergesort(nums, start, end, count, temp);
        return count;
    }
};

```
Let’s break down the **dry run** step-by-step in a clearer way, along with each line of execution, using the input `nums = [4, 1, 2]`.

### Code Overview:

The goal of the algorithm is to find **reverse pairs**, where `nums[i] > 2 * nums[j]` for `i < j`. This is done using a **modified merge sort** algorithm, which divides the array and counts reverse pairs during the merge process.

---

### Initialization:

```cpp
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int count = 0, start = 0, end = n - 1;
    vector<int> temp(n);
    mergesort(nums, start, end, count, temp);
    return count;
}
```
- **Input**: `nums = [4, 1, 2]`.
- `n = 3`, `count = 0`, `start = 0`, `end = 2`, and `temp = [0, 0, 0]`.
- We call `mergesort(nums, 0, 2)` to start sorting and counting reverse pairs.

---

### First Call: `mergesort(nums, 0, 2)`

```cpp
mergesort(nums, 0, 2, count, temp);
```

- The array is split at the middle:
  - `mid = (0 + 2) / 2 = 1`.
- Now the array is divided into two parts:
  - Left: `nums[0..1] = [4, 1]`
  - Right: `nums[2..2] = [2]`

#### Recursive Call 1: `mergesort(nums, 0, 1)`

```cpp
mergesort(nums, 0, 1, count, temp);
```

- The left part `[4, 1]` is split again:
  - `mid = (0 + 1) / 2 = 0`.
  - Left: `nums[0..0] = [4]`
  - Right: `nums[1..1] = [1]`

##### Recursive Call 1.1: `mergesort(nums, 0, 0)`
- Base case: `start == end`, so this call returns immediately (no action).

##### Recursive Call 1.2: `mergesort(nums, 1, 1)`
- Base case: `start == end`, so this call also returns immediately.

---

### Merge Call 1: `merge(nums, 0, 1)`

```cpp
merge(nums, 0, 1, count, temp);
```

Now we **merge** the two parts `[4]` and `[1]`:

- `i = 0` (points to `4`), `j = 1` (points to `1`), `k = 0` (start index).
- **Reverse pair counting**:
  - `arr[i] = 4`, `arr[j] = 1`. Check if `4 > 2 * 1`. Yes, so there is one reverse pair.
  - **Count = 1**.
  - Move `j` to the next element (`j = 2`).
  
- **Merging sorted elements**:
  - Since `i` is still pointing to `4` and `j` is out of bounds, merge the elements:
    - `temp = [1, 4, 0]` (sorted).
  
- **Copy back to the original array**:
  - `nums = [1, 4, 2]` after copying back from `temp`.

---

### Returning to `mergesort(nums, 0, 2)`:

#### Recursive Call 2: `mergesort(nums, 2, 2)`

- Base case: `start == end`, so this call returns immediately.

---

### Merge Call 2: `merge(nums, 0, 2)`

```cpp
merge(nums, 0, 2, count, temp);
```

Now we **merge** the two parts `[1, 4]` and `[2]`:

- `i = 0` (points to `1`), `j = 2` (points to `2`), `k = 0`.
- **Reverse pair counting**:
  - `arr[i] = 1`, `arr[j] = 2`. Check if `1 > 2 * 2`. No, move `i` to the next element.
  - `arr[i] = 4`, `arr[j] = 2`. Check if `4 > 2 * 2`. No, move `i` to the next element.
  - No additional reverse pairs are found in this step.

- **Merging sorted elements**:
  - `temp = [1, 2, 4]` (sorted).

- **Copy back to the original array**:
  - `nums = [1, 2, 4]`.

---

### Final Result:

The sorted array is `[1, 2, 4]`, and there is 1 reverse pair (`[4, 1]`).

### Dry Run Summary:

1. **First merge**: Merged `[4]` and `[1]`, found 1 reverse pair (`4 > 2 * 1`).
2. **Second merge**: Merged `[1, 4]` and `[2]`, no additional reverse pairs were found.

### Time Complexity:

- **O(n log n)**:
  - The array is split into halves at each step (log(n) levels).
  - Merging two halves takes linear time (`O(n)`).

### Space Complexity:

- **O(n)**:
  - An auxiliary array `temp` of size `n` is used for the merging process.

---

### Visual Representation:

1. **Input Array**: `[4, 1, 2]`
2. Split into: `[4, 1]` and `[2]`
3. Split `[4, 1]` into `[4]` and `[1]`
4. Merge `[4]` and `[1]` → `[1, 4]`, 1 reverse pair found.
5. Merge `[1, 4]` and `[2]` → `[1, 2, 4]`, no additional reverse pairs.

The final count of reverse pairs is `1`.
