Longest prefix which is also suffix
Last Updated : 29 Mar, 2024
Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.

Examples: 

Input : S = aabcdaabc
Output : 4
Explanation: The string “aabc” is the longest prefix which is also suffix.

Input : S = abcab
Output : 2

Input : S = aaaa
Output : 2

Recommended Problem
Longest Prefix Suffix
Companies:
Accolite
Amazon
+2 more
Show Topics 
Solve Problem
Hard
27.91%
1.1L
Naive approach:

Since overlapping prefixes and suffixes is not allowed, we break the string from the middle and start matching left and right strings. If they are equal return size of one string, else they try for shorter lengths on both sides.

Below is a solution to the above approach:


// CPP program to find length of the 
// longest prefix which is also suffix 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find largest prefix 
// which is also a suffix 
int largest_prefix_suffix(const std::string& str) 
{ 
    int n = str.length(); 
  
    // If the length of the string is less than 2, there 
    // can't be a non-overlapping prefix and suffix, so 
    // return 0. 
    if (n < 2) { 
        return 0; 
    } 
  
    // Initialize the length of the longest prefix which is 
    // also a suffix. 
    int len = 0; 
    int i = 0; 
  
    // Iterate through the first half of the string. 
    while (i < n / 2) { 
        int j1 = 0, j2 = (n - 1) - i; 
        int isPrefixSuffix = 1; 
  
        // Check if characters at corresponding positions in 
        // the first half (j1) and the second half (j2) of 
        // the string are equal. 
        while (j1 <= i) { 
  
            // If any pair of characters doesn't match, it's 
            // not a prefix-suffix. 
            if (str[j1] != str[j2]) { 
                isPrefixSuffix = 0; 
            } 
            j1++; 
            j2++; 
        } 
  
        // If it's a prefix-suffix, update the length. 
        if (isPrefixSuffix == 1) 
            len = i + 1; 
        i++; 
    } 
  
    // Return the length of the longest prefix which is also 
    // a suffix. 
    return len; 
} 
  
// Driver code 
int main() 
{ 
    string s = "blablabla"; 
  
    // Function Call to find the length of the longest 
    // prefix which is also a suffix 
    cout << largest_prefix_suffix(s); 
  
    return 0; 
}
Output
3


Time Complexity: O(n^2)
Auxiliary Space: O(1)

Longest prefix which is also suffix using KMP algorithm:
The idea is to use the preprocessing algorithm KMP search. In the preprocessing algorithm, we build lps array which stores the following values.

lps[i] = the longest proper prefix of pat[0..i] 
which is also a suffix of pat[0..i].

Below is the implementation:


// Efficient CPP program to find length of  
// the longest prefix which is also suffix 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns length of the longest prefix 
// which is also suffix and the two do 
// not overlap. This function mainly is 
// copy computeLPSArray() of in below post 
// https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/ 
int longestPrefixSuffix(string str) 
{ 
          vector<int> A(str.size(), 0); 
        int j = 0, i = 1; 
          
        // Loop to calculate the prefix array 
        while(i < str.size()) 
        { 
            if(str[i] == str[j]) 
            { 
                // Increment j by 1 and assign the value to the prefix array 
                A[i] = j+1; 
                j++; 
                i++; 
            } 
            else
            { 
                if(j==0) 
                    i++; 
                else
                    // Set j to the previous value in the prefix array 
                    j = A[j-1]; 
                  
            } 
        } 
  
        // Return the last element of the prefix array 
        return A.back(); 
} 
  
// Driver program to test above function 
int main() 
{ 
    string s = "abadabab"; 
    cout << longestPrefixSuffix(s); 
    return 0; 
} 
  
// Corrected by Nilanshu Yadav 
Output
2


Time Complexity: O(n) 
Auxiliary Space: O(n)
