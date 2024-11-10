442. Find All Duplicates in an Array
Solved
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

 https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     
    int n = nums.size();
    vector<int> result;
    vector<int> freq(n + 1, 0); // Create frequency array initialized to 0
    
    // Count frequencies of elements
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    // Find elements with frequency greater than 1
    for (int i = 0; i <= n; i++) {
        if (freq[i] > 1) {
            result.push_back(i);
        }
    }
    
    return result;
}


    
};

```

OPITMAL 

```cpp
class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        // Your code here
        vector<int>ans;
        for(int i=0;i<n+2;i++)
        {
            int index = abs(arr[i]);
        if(arr[index]<0) ans.push_back(index);
        else arr[index] = -arr[index];
        if(ans.size()==2) break;
        }return ans;
    }
};

```

n = 4
arr = {1, 2, 1, 3, 4, 3}
We are looking for two repeating numbers in the array, which are in the range 1 to n.

Step-by-Step Dry Run
Initial Array State: {1, 2, 1, 3, 4, 3}

First Iteration (i = 0):

Current element: arr[0] = 1
index = abs(arr[0]) = 1
arr[1] is positive, so negate arr[1] to mark 1 as seen.
Array after change: {1, -2, 1, 3, 4, 3}
Second Iteration (i = 1):

Current element: arr[1] = -2
index = abs(arr[1]) = 2
arr[2] is positive, so negate arr[2] to mark 2 as seen.
Array after change: {1, -2, -1, 3, 4, 3}
Third Iteration (i = 2):

Current element: arr[2] = -1
index = abs(arr[2]) = 1
arr[1] is negative, indicating 1 is a duplicate.
Add 1 to ans.
Array remains: {1, -2, -1, 3, 4, 3}
ans = {1}
Fourth Iteration (i = 3):

Current element: arr[3] = 3
index = abs(arr[3]) = 3
arr[3] is positive, so negate arr[3] to mark 3 as seen.
Array after change: {1, -2, -1, -3, 4, 3}
Fifth Iteration (i = 4):

Current element: arr[4] = 4
index = abs(arr[4]) = 4
arr[4] is positive, so negate arr[4] to mark 4 as seen.
Array after change: {1, -2, -1, -3, -4, 3}
Sixth Iteration (i = 5):

Current element: arr[5] = 3
index = abs(arr[5]) = 3
arr[3] is negative, indicating 3 is a duplicate.
Add 3 to ans.
Array remains: {1, -2, -1, -3, -4, 3}
ans = {1, 3}
Exit the loop since ans now contains two elements.
Final Output
ans = {1, 3}
Explanation of the Result
The duplicates 1 and 3 were detected in the order they appear for the second time, resulting in the output 1 3.

---


You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. So, if x and y are repeating numbers, and x's second appearance comes before the second appearance of y, then the order should be (x, y).

Examples:

Input: n = 4, arr[] = [1, 2, 1, 3, 4, 3]
Output: 1 3
Explanation: In the given array, 1 and 3 are repeated two times, and as 1's second appearance occurs before 2's second appearance, so the output should be 1 3.
Input: n = 2, arr[] = [1, 2, 2, 1]
Output: 2 1
Explanation: In the given array, 1 and 2 are repeated two times and second occurence of 2 comes before 1. So the output is 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 



