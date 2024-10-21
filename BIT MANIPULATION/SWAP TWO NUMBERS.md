Swap two numbers
Difficulty: BasicAccuracy: 70.02%Submissions: 70K+Points: 1
Swap given two numbers and print them. (Try to do it without a temporary variable.) and return it.

https://geeksforgeeks.org/problems/swap-two-numbers3844/1

Example 1:

Input: a = 13, b = 9
Output: 9 13
Explanation: after swapping it
becomes 9 and 13.
Example 2:

Input: a = 15, b = 8
Output: 8 15
Explanation: after swapping it
becomes 8 and 15.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function get() which takes a, b as inputs and returns the list of integers contains the new value of a and b after swap.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

---

https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1

---

```cpp

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        pair<int , int>p1 = {b,a};
        return p1;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        
        Solution ob;
        pair<int, int>p = ob.get(a, b);
        cout << p.first << ' ' << p.second << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends
```
