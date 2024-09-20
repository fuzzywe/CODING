Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

int reverseDigits(int num) 
{ 

	// converting number to string 
	string str = to_string(num); 

	// reversing the string 
	reverse(str.begin(), str.end()); 

	// converting string to integer 
	num = stoll(str); 

	// returning integer 
	return num; 
} 

// Driver Code 
int main() 
{ 
	int num = 4562; 
	cout << "Reverse of no. is " << reverseDigits(num); 

	return 0; 
} 

// This code is contributed by sanjoy_62.
Time Complexity: O(n), where n is the input number
Auxiliary Space: O(1)

  #include <bits/stdc++.h> 
using namespace std; 
  
int reverseDigits(int num) 
{ 
    // converting number to string 
    string strin = to_string(num); 
  
    // reversing the string 
    reverse(strin.begin(), strin.end()); 
  
    // converting string to integer 
    num = stoi(strin); 
  
    // returning integer 
    return num; 
} 
int main() 
{ 
    int num = 4562; 
    cout << "Reverse of no. is " << reverseDigits(num); 
    return 0; 
} 
  
// This Code is contributed by ShubhamSingh10
Output
Reverse of no. is 123456
Time Complexity: O(log10n) where n is the input number
Auxiliary Space: O(1)

  
  best solution
class Solution {
public:
    int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }
};
Complexity
Time complexity: O(log n)
Space complexity: O(1)
