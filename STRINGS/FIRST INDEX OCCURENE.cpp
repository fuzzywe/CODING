Find the Position of a Substring within a String


10

0
In this article we will solve the most asked interview question: "Find the Position of a Substring within a String"

Problem statement: “Given two strings text and pattern find the first occurrence of str1 in str2 if found print it’s index if not found print -1.”

Examples:

Example 1:
Input: str1 = "takeuforward"
       str2 = “forward”
Output: 5
Explanation: "Forward" is present in the 5th index in "takeuforward"

Example 2:
Input: str1 = “hello”
       str2 = “az”
Output: -1
Explanation: "az" is not a substring of "hello"
Solution:

Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1: Naive Approach

Run two for loops i,j.
i looping from [0, N - M - 1] and j looping from [0, M -1]. Here N is the length of text and M is the length of pattern.
Why is the outer loop running for N - M - 1 ??

For a given string to have a substring of another string it must contain the length of the substring to be found in the string.If it doesn’t have the length of the substring there is no point in searching any further.
Now run an outer loop from i -> [0, N - M - 1]  for every index i check for the substring this can be done by storing the index of i into some variable temp and running an inner loop from j -> [0, M] check if the characters of text and pattern are matching or not from the index [temp, temp + M]. after coming out of the inner loop check if (j == M) then return i.

If the substring is not found return -1.

Code:

C++
Java
#include <iostream>

#include<string>

using namespace std;

int foundPattern(string text, string pattern) {
  int N = text.length();
  int M = pattern.length();

  for (int i = 0; i < N; i++) {
    int temp = i;
    int j = 0;
    for (j = 0; j < M; j++) {
      if (text[temp] != pattern[j]) {
        break;
      }
      temp++;
    }
    if (j == M) {
      return i;
    }
  }

  return -1;
}

int main() {
  string text = "takeuforward";
  string pattern = "forward";
  int foundIdx = foundPattern(text, pattern);
  cout << "The substring starts from the index: "<<foundIdx << endl;
  return 0;
}

Output: The substring starts from the index: 5

Time Complexity: O(N^2)

Space Complexity: O(1)

Solution 2 : Using Library Functions

In C++ : by using find( ) function

find function:

The find function searches a string to find the first occurrence of a particular substring and returns an unsigned integer value, giving the result of the search.

Syntax:

str1.find(str2)

In Java: By using IndexOf( ) method

IndexOf( ) method:

The indexOf( ) method in java will return the first occurrence of specified characters in a string.

Syntax:

str1.indexOf(str2)

Code:

C++
Java
#include <iostream>
using namespace std;
 
int main() {
  string text = "takeuforward";
  string pattern = "forward";
  auto foundIdx = text.find(pattern);
  cout <<"The substring starts from the index: " <<foundIdx << endl;
  return 0;
}
Output: The substring starts from the index: 5

Time Complexity: O(N)

Space Complexity: O(1)







  Intuition
The strStr function finds the first occurrence of the substring needle in the string haystack. To efficiently solve this problem, we can use the Z-algorithm, which provides a linear time solution to find all occurrences of a pattern within a text.

Approach
Z-Algorithm: The Z-algorithm computes an array where each element represents the length of the longest substring starting from that position in the string s that matches the prefix of s. This helps in matching the needle string in the haystack efficiently.
Concatenation: We concatenate the needle, a special character (to separate the needle from the haystack, ensuring no overlap), and the haystack. The combined string allows us to leverage the Z-array to check where the needle appears in the haystack.
Z-Array Usage: After computing the Z-array for the combined string, we look for the first occurrence where the value in the Z-array equals the length of needle. This position in the Z-array corresponds to the start index of needle in haystack.
Complexity
Time complexity: O(n+m)
Space complexity: O(n+m)
Code
class Solution {
private:
    vector<int> getZ(string s){
        int n = s.size();
        vector<int> z(n);
        z[0]=0;
        int l=0, r=0;
        for(int i=1; i<n; i++){
            if(i>r){
                l=r=i;
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            else{
                int k = i-l;
                if(z[k] < r-i+1){
                    z[i]=z[k];
                }
                else{
                    l=i;
                    while(r<n && s[r-l]==s[r]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    int strStr(string haystack, string needle) {
        string temp = needle + "$" + haystack;
        int l = temp.size();
        vector<int> z = getZ(temp);

        int n=needle.size();
        for(int i=0; i<l; i++){
            if(z[i]==n){
                return i-n-1;
            }
        }

        return -1;
    }
};
