Example 1:

Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element.

Example 2:

Input:
A = 162, B = 934, C = 200
Output:
200
Exaplanation:
Since 200>162 && 200<934,
So, 200 is the middle element.



best solution:

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution{
  public:
    int middle(int a, int b, int c){
        //code here//Position this line where user code will be pasted.
           if(b>a && a>c || a>b && a<c)
            return a;
        else if(b>a && b<c || b<a && b>c)
            return b;
        else
            return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends
Time Complexity: O(1) (constant time)
Space Complexity: O(1) (constant space)
This is an efficient solution since both time and space complexities are constant.

  Sorting Approach:
Sort the three numbers and return the second number in the sorted list. This approach, though simple, has a higher time complexity compared to the original approach.

cpp
Copy code
int middle(int a, int b, int c) {
    vector<int> arr = {a, b, c};
    sort(arr.begin(), arr.end());
    return arr[1];  // The middle element in the sorted array.
}
Time Complexity:
Sorting three numbers takes O(3 log 3), but this simplifies to O(1) since the number of elements is fixed (only 3).
Space Complexity: O(1) (constant space, only 3 numbers).
This method works but is not as efficient as the original solution since sorting is unnecessary for just three elements.

2. Mathematical Approach (Sum of Three Minus Max and Min):
A more mathematical approach can find the middle value by summing all three numbers and subtracting the maximum and minimum values. The result will be the middle number.

cpp
Copy code
int middle(int a, int b, int c) {
    int maximum = max({a, b, c});
    int minimum = min({a, b, c});
    return (a + b + c) - maximum - minimum;  // The remaining number is the middle one.
}
Time Complexity:
Finding the maximum and minimum of three numbers takes O(1) time (constant time).
Summing three numbers is also O(1).
Space Complexity:
Only a few variables are used, so the space complexity is O(1).
