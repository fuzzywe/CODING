Palindromic substrings


3

0
Given a string s, return the number of palindromic substrings in it. A string is a palindrome when it reads the same backward as forward. A substring is a contiguous sequence of characters within the string.

Examples:

Example 1:
Input: abc 
Output: 3 
Explanation: palindromic substrings are 'a', 'b' ,'c' 

Example 2:
Input: aaa 
Output: 6 
Explanation: palindromic substrings are 'a', 'a' ,'aa','aa','a','aaa'
Solution 
Disclaimer: Don't jump directly to the solution, try it out yourself first. 

Brute Force Solution 
We can generate all the substrings for the given string, and for each substring check if it is a palindrome. For ex - abc  

We take 2 loops i=0 and j=i , substr1 is from 0 to 0,substr2 is from 0 to 1, substr3 is from 0 to 2 For i=1 , j=1 , substr4 is 1 to 1 , substr5 is from 1 to 2 For i=2,j=2, substr6 is 2 to 2, For checking if a string is a palindrome, we take 2 pointers at the beginning and end of string and keep comparing  if a[i]==a[j] 

Code:

C++
#include<bits/stdc++.h>

using namespace std;
bool checkPal(int i, int j, string str) {

  while (i < j) {
    if (str[i] != str[j]) return false;
    i++;
    j--;
  }
  return true;
}

int countSubstrings(string s) {
  int n = s.length();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int p = i; p < n; p++) {
      if (checkPal(i, p, s) == true) {
        sum++;
      }
    }
  }

  return sum;
}
int main() {
  string s = "aaa";
  cout << countSubstrings(s);
  return 0;
}
Output: 6

Time Complexity: O(n2) * O(n) // for generating substrings and to check palindrome

Space Complexity: O(1) 

OPTIMAL SOLUTION 

We can turn this into a O(n2) solution by making a dp table. 


Suppose we have string ="abbc", we create a dp table with respect to start and end points. Rows represent the start of substr and col is the end of substr.

Lets say string starts at 0 and end at 0, we have substr A,

for 0,1 its "ab"
for 0,2 its "abb"
for 0,3 it is "abbc".
Similarly

for 1,1 it is "b".
for 1,2 it is "bb".
for 1,3 it is "bba" and so on.
Now, we can have 3 cases,

If the gap between start and end==0, i.e only one element then we know it is a palindrome. 
If the gap between start and end is 1, then there are 2 elements, for 0,1 ie ab (it's not palindrome) For 1,2 bb (palindrome) for 2,3 ba (not palindrome).
For gap 2, 0,2 ie abb we check if the first and last index elements are equal, as well as if the middle part is a  palindrome (which we get from the dp table) then it is true. Here, a and b are not equal, so directly false. For 1,3 bba (b!=a) so false.
For gap = 3 , ie 0,3 abba , (a==a) so first and last id equal , now we want if middle part bb is a  palindrome , which we get from dp[i+1][j-1] ==true , So true. In the end, for no. of palindromes just count how many truly are present in the dp table.
Code:

C++
#include<bits/stdc++.h>

using namespace std;
int countSubstrings(string s) {
  int n = s.length();
  vector < vector < bool > > dp(n, vector < bool > (n, false));
  int cnt = 0;
  for (int g = 0; g < n; g++) {
    for (int i = 0, j = g; j < n; i++, j++) {
      if (g == 0) dp[i][j] = true;
      else if (g == 1) dp[i][j] = (s[i] == s[j]);
      else {
        if (s[i] == s[j] && dp[i + 1][j - 1] == true) dp[i][j] = true;
      }
      if (dp[i][j] == true) cnt++;
    }
  }
  return cnt;
}
int main() {
  string s = "aaa";
  cout << countSubstrings(s);
  return 0;
}
Output: 6

Time Complexity: O(n2) 

Space Complexity: O(n2) 
