Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 38K+Points: 2
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

---
```cpp
class Solution {
    
    int f(int n){
        
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        if(n % 4 == 3) return 0;
        else return n;
        
    }
    
    public:
    
    int findXOR(int l, int r) {
        
        return f(l - 1) ^ f(r);
        
    }
};
```
Time Complexity : O(1)

Space Complexity : O(1)

---

```cpp
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int ans = 0;
    for (int i = l; i <= r; i++) {
        ans = ans ^ i;
    }
    return ans;
    }
};


```
Time complexity: O(n)
Auxiliary Space: O(1)

Test Cases Passed: 
1005 /2005
Time limit exceeded.

Your program took more time than expected.Expected Time Limit : 1.12sec
Hint : Please optimize your code and submit again.