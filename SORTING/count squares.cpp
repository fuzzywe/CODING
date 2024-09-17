//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        // This function calculates the number of perfect squares less than or equal to the given number N.
// It takes an integer N as input and returns an integer representing the count of perfect squares.
        // Calculate the square root of N-1 and store it in the variable ans.
        int ans = sqrt(N-1);
        
        // Return the value of ans as the count of perfect squares.
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends

Complexity
Time Complexity: The time complexity is O(sqrt(N)), where N is the input, due to the square root calculation.
Space Complexity: The space complexity is O(1) as the algorithm uses only a constant amount of space for variables, irrespective of the input size.


class Solution:
    def countSquares(self, N):
        if N==1:
            return 0
        low, high = 1, N
        result = 0

        # Binary search
        while low <= high:
            mid = (low + high) // 2
            if mid * mid == N:
                return mid - 1
            elif mid * mid < N:
                result = mid
                low = mid + 1
            else:
                high = mid - 1

        return result
Complexity
Time Complexity :O(log(N)), where the binary search reduces the search space exponentially.
Space Complexity: O(1), as the algorithm uses only a constant amount of space for variables


-

best code:


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int i =2;
        int count =0;
        int square= 1;
        while(square<N)
        {
            square = i*i;
            count++;
            i++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
