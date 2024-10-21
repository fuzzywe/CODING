Number of 1 Bits

https://www.geeksforgeeks.org/problems/set-bits0143/1

Given a positive integer n. Your task is to return the count of set bits.

Examples:

Input: n = 6
Output: 2
Explanation: Binary representation is '110', so the count of the set bit is 2.
Input: n = 8
Output: 1
Explanation: Binary representation is '1000', so the count of the set bit is 1.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

---
```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        while(n != 1){
            count += n&1;
            n = n>>1;
        }
        count++;
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
```

---
https://www.geeksforgeeks.org/problems/set-bits0143/1

