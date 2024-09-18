Palindromic Array
Examples:

Input: arr[] = [111, 222, 333, 444, 555]
Output: true
Explanation:
arr[0] = 111, which is a palindrome number.
arr[1] = 222, which is a palindrome number.
arr[2] = 333, which is a palindrome number.
arr[3] = 444, which is a palindrome number.
arr[4] = 555, which is a palindrome number.
As all numbers are palindrome so This will return true.
Input: arr[] = [121, 131, 20]
Output: false
Explanation: 20 is not a palindrome hence the output is false.
Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(1)

 // CPP implementation to check
// if an array is PalinArray or not
#include<bits/stdc++.h>
using namespace std;

// Function to check if a number is palindrome or not
bool isPalindrome(int N)
{
    string str = to_string(N); // Correct way to convert integer to string
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

// Function to check if an array is PalinArray or not
bool isPalinArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        bool ans = isPalindrome(arr[i]);
        if (ans == false)
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {121, 131, 20}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate length of array

    bool res = isPalinArray(arr, n); // Check if it's a PalinArray
    if (res == true)
        cout << "Array is a PalinArray";
    else
        cout << "Array is not a PalinArray";

    return 0;
}

Complexity Analysis:

Time Complexity: O(n2) since we need to traverse every nested array in the worst case.
Auxiliary Space: O(1)

geeksforgeeks 
  //{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
  bool ispalindrome(int N)
        {
            string str = to_string(N);
             int len = str.length();
            for(int i =0;i<len/2;i++)
            {
            if (str[i] != str[len-1-i]) return false;
            
            }return true;
        }
    bool PalinArray(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        for(int i =0;i<n;i++){
            bool ans = ispalindrome(arr[i]);
            if (ans == false) return false;
            
        } return true;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends

Array Initialization:

cpp
Copy code
int arr[] = {121, 131, 20}; 
int n = sizeof(arr) / sizeof(arr[0]); // n = 3 (the array has 3 elements)
Calling isPalinArray(): The function isPalinArray(arr, 3) is called, which will check each element of the array.

First Element: 121:

The first element is 121.
Calling isPalindrome(121):
121 is converted to the string "121".
The string has a length of 3.
The function checks:
str[0] == str[2] → '1' == '1' (true).
str[1] == str[1] → '2' == '2' (true).
All checks are true, so isPalindrome(121) returns true.
Since 121 is a palindrome, the loop in isPalinArray() continues.
Second Element: 131:

The second element is 131.
Calling isPalindrome(131):
131 is converted to the string "131".
The string has a length of 3.
The function checks:
str[0] == str[2] → '1' == '1' (true).
str[1] == str[1] → '3' == '3' (true).
All checks are true, so isPalindrome(131) returns true.
Since 131 is a palindrome, the loop in isPalinArray() continues.
Third Element: 20:

The third element is 20.
Calling isPalindrome(20):
20 is converted to the string "20".
The string has a length of 2.
The function checks:
str[0] == str[1] → '2' != '0' (false).
Since the characters don't match, isPalindrome(20) returns false.
Because 20 is not a palindrome, isPalinArray() returns false immediately.
Output: Since the array contains a non-palindrome element (20), the final output will be:

csharp
Copy code
Array is not a PalinArray





best soln
class Solution {
    public static boolean palinArray(int[] arr) {

        int n= arr.length;
        for(int i=0;i<n;i++){
            String str=Integer.toString(arr[i]);
            if(!isPalindrome(str))
            {
                return false;
            }
        }  
        return true;
   }
   public static boolean isPalindrome(String s){
       int l=0,r=s.length()-1;
       while(l<r){
           if(s.charAt(l)==s.charAt(r)){
               l++;
               r--;
           }
           else{
               return false;
           }
       }
       return true;
   }
}
Complexity
Time Complexity : O(n * log10(max_value)), where 'n' is the number of elements in the array. As the code iterates through each element in the array and performs palindrome checks.

Space Complexity :O(1), indicating constant space usage regardless of the input size.
  O(n * log₁₀(max_value)) is the more efficient solution, especially for large arrays.
O(n²) becomes inefficient and slow when the input size grows larger.
