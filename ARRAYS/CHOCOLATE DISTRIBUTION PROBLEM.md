

https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1



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



```cpp

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
         sort(a.begin(),a.end());
        int n= a.size();
       int mini = INT_MAX; 
       int i = 0; 
       int j = m-1; 
       while(j < n){
            int diff = a[j]- a[i]; 
           mini = min(mini , diff); 
           i++, j++; 
       }
       return mini;
      
    }
};

```
