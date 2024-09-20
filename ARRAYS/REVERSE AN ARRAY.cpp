Reverse a given Array

Problem Statement: You are given an array. The task is to reverse the array and print it. 

Examples:

Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Example 2:
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.


#include <iostream>
using namespace std;
//Function to print array
void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}
//Function to reverse array using an auxiliary array
void reverseArray(int arr[], int n) {
   int ans[n];
   for (int i = n - 1; i >= 0; i--) {
      ans[n - i - 1] = arr[i];
   }
   printArray(ans, n);
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}
Output:

The reversed array is:-
1 2 3 4 5

Time Complexity: O(n), single-pass for reversing array.

Space Complexity: O(n), for the extra array used.

  #include <algorithm> // for std::reverse
#include <iostream>

int main()
{
    int originalArray[] = { 1, 2, 3, 4, 5 };
    int length
        = sizeof(originalArray) / sizeof(originalArray[0]);

    // Using inbuilt method in C++
    std::reverse(originalArray, originalArray + length);

    // Print the reversed array
    for (int i = 0; i < length; i++) {
        std::cout << originalArray[i] << " ";
    }

    return 0;
}
Time Complexity: O(n) The reverse method typically has linear time complexity.
Auxiliary Space Complexity: O(1)
Additional space is not used to store the reversed array, as the in-built array method “reverse()” swaps the values in a given range in in-place fashion.


Array Reverse Recursion (In-place or Non In-place):
Define a recursive function that takes an array as input.
Swap the first and last elements.
Recursively call the function with the remaining subarray.
Below is the implementation of the above approach :


#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    reverseArray(arr, 0, size - 1);

    cout << "Reversed array is" << endl;
    printArray(arr, size);

    return 0;
}

Output
1 2 3 4 5 6 
Reversed array is
6 5 4 3 2 1 
Time Complexity: O(n). The recursion goes through each element once, so it’s linear.
Auxiliary Space Complexity: O(n) for non in-place, O(log n) for in-place (due to recursion stack).

  #include <iostream>

using namespace std;
//Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}
//Function to reverse array using recursion
void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}
int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1 };
   reverseArray(arr, 0, n - 1);
   printArray(arr, n);
   return 0;
}
Output:

The reversed array is:-
1 2 3 4 5

Time Complexity: O(n)

Space Complexity: O(1)


  
  
  
  
  
  
  IN CODING PLATFORM



  
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> reverseArray(vector<int> &arr) {
        // code here
        
       
        int high = arr.size()-1;
        int ans[high];
        for (int i=high-1;i>=0;i--)
        {
            ans[high-i-1] = arr[i];
        }reverseArray(ans);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        arr = ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends whats wrong with this code
ChatGPT said:
ChatGPT
There are several issues with the provided code that need to be addressed:

1. Incorrect Use of Array ans[]
The ans[] array is declared with a fixed size, but this is unnecessary because you are working with a vector. Instead, you should use a vector directly for dynamic resizing.
2. Improper Reversal Logic
The loop for reversing the array has an off-by-one error. It starts from high-1 and decreases but assigns the values incorrectly. The loop logic needs adjustment.
3. Misuse of reverseArray(ans)
The function reverseArray(ans) inside the reverseArray method makes no sense because ans is not a vector. Additionally, after reversing the array into ans, you should return the reversed array, not recursively call the function.
4. Returning a Vector
The reverseArray function needs to return a vector, but your code does not return anything, which will result in a compilation error.
Corrected Code
Here’s the corrected version:

cpp
Copy code
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> reverseArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);  // Use a vector for dynamic resizing
        for (int i = 0; i < n; i++) {
            ans[i] = arr[n - i - 1]; // Correctly reverse the array
        }
        return ans; // Return the reversed vector
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();  // Ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        arr = ob.reverseArray(arr);  // Get the reversed array
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";  // Print the reversed array
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
Changes Made:
Replaced array ans[] with vector ans to handle dynamic sizing.
Adjusted the reversal loop: It now correctly reverses the array.
Return the reversed vector after processing.
The main function remains the same, but now it correctly receives the reversed vector from the reverseArray method.
Explanation:
We create a new vector ans of the same size as arr.
The loop runs through the original vector arr and fills ans with the reversed elements.
The reverseArray method returns the reversed vector, which is then printed in the main function.
This should fix the issues and run correctly for the given problem.


  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> reverseArray(vector<int> &arr) {
        // code here
        
       
        int high = arr.size();
        vector<int>ans(high);
        for (int i=0;i<high;i++)
        {
            ans[i]=arr[high-i-1] ;
        }return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        arr = ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> reverseArray(vector<int> &arr) {
        // code here
        int left =0;
        int right = arr.size()-1;
        while (left<right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right]=temp;
            left ++;
            right--;
        }return arr;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        arr = ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
  
