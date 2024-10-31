https://leetcode.com/problems/find-peak-element/

https://www.naukri.com/code360/problems/find-peak-element_1081482?leftPanelTabValue=SUBMISSION

https://www.geeksforgeeks.org/problems/peak-element/1

for geeksforgeeks

User
Nilesh Tiwari
(Edited)
8 months agoMar 01, 2024 03:51 (GMT +5:30)

First approach -> Brute force ✅
Time Complexity -> O(n)

Space Complexity -> O(1)

Thinking Process -> A peak element is defined as an element that is greater than its neighboring elements. Neighboring elements for an index 'i' are the elements at positions 'i-1' and 'i+1'. 

For example, in the array [1, 2, 3], the neighbors of 2 are {1, 3}.

In our approach, we iterate through each element in the array. At each index, we check whether the element is greater than its neighbors. For indices 0 and n-1, there is only one neighbor, and we check accordingly. If a peak element is found, we return its index. If no peak element is found, we return -1.

Edge Case: If the array size is one, the only element is greater than its non-existent neighbors. Therefore, we return 0.

 ```cpp

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
       
        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++)
        {      
            if (i == 0)
            {
                if (arr[i] >= arr[i + 1])
                    return i;
            }
            else if (i == n - 1)
            {
                if (arr[i] >= arr[i - 1])
                    return i;
            }
            else
            {
                if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
                    return i;
            }
        }

        // If no peak element is found, return -1.
        return -1;
    }
};

```
---
Optimize approach -: ✅
Time Complexity - O(log (n))

space complexity - O(1)

Thinking Process -: we will find our ans using binary search which reduces the time complexity to O(log(n)).



 


```cpp
class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n = arr.size();
         int i=1;
        if(n==1)
        {
            return 0;
        }
        if(arr[0]>=arr[1])
        {
             return 0;
        }
        if(arr[n-1]>=arr[n-2])
        {
             return n-1;
        }
        while(i<n-1)
        {
        if(arr[i-1]<=arr[i]&&arr[i]>=arr[i+1])
        {
             return i;
        }
        i++;
        }
        return 0;
    
    }
};
```

162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.


Complexity

Time complexity: O(logn)

Space complexity: O(1)
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;        
    }
};
```

/*

    Time Complexity : O(N), because in the worst case we traverse the <= N element. Where N is the size of the
    Array(nums).
                    
    Space Complexity : O(1), the space complexity is constant.

    Solved using Linear Search.

*/


/***************************************** Approach 1 First Code *****************************************/
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                return i;
            }
        }
        return n-1;
    }
};


```



/***************************************** Approach 1 Second Code *****************************************/
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};


```



/*

    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(logN), Recursion stack space.

    Solved using Binary Search (Recursive Approach).

*/


/***************************************** Approach 2 First Code *****************************************/

```cpp
class Solution {
private: 
    int recursive_binary_search(vector<int>& nums, int low, int high){
        if(low == high){
            return low;
        }
        int mid = (low + high) >> 1;
        if(nums[mid] > nums[mid+1]){
            return recursive_binary_search(nums, low, mid);
        }
        else{
            return recursive_binary_search(nums, mid+1, high);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        return recursive_binary_search(nums, 0, nums.size()-1);
    }
};

```




/*

    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(1), since we stored only some constant number of elements, the space complexity is
    constant.

    Solved using Binary Search (Iterative Approach).

*/


/***************************************** Approach 3 First Code *****************************************/
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = (low + high) >> 1;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

```
