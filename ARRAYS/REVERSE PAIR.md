Example 1:
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
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Cast to long long to prevent overflow
                if (nums[i] > 2LL * nums[j]) {
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
