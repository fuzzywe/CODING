https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1

Power of 2
Difficulty: EasyAccuracy: 32.58%Submissions: 404K+Points: 2
Given a non-negative integer n. The task is to check if it is a power of 2. 

Examples

Input: n = 8
Output: true
Explanation: 8 is equal to 2 raised to 3 (23 = 8).
Input: n = 98
Output: false
Explanation: 98 cannot be obtained by any power of 2.
Input: n = 1
Output: true
Explanation: (20 = 1).
Expected Time Complexity: O(log n).
Expected Auxiliary Space: O(1).

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
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n) {

         return n > 0 && (n & (n - 1)) == 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++) {
        long long n; // input a number n
        cin >> n;
        // if (n == 11) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we
                                // are sure raising 2 to this value
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends

```
---

```cpp
Intuition:
By using __builtin_popcount function, this function returns number of set bits in an integer.

Implementation
Steps:-

Use __builtin_popcountll function to count the number of setBit.
If number of setBit == 1 then return true
Else return false.
 


class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here  
        return (__builtin_popcountll(n) == 1);
    }
};
 

Complexity
Time Complexity: O(1), __builtin_popcount function takes O(1) time.
Auxiliary Space: O(1), We are not using any extra space.
```
