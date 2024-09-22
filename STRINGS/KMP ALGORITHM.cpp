KMP Algorithm


4

2
Problem Statement: Implement the Knuth-Morris-Pratt KMP string matching algorithm.

Examples:

Example 1:
Input: String = ”aaaaaaaamaaaaaab”  and Pattern = “aaaaaab”
Output: 9
Explanation: The underlined string is the pattern string 
successfully matched. The first index where the pattern has 
matched is 9. So result is 9.

Example 2:
Input: String = ”Manav” and pattern=”nav”
Output: 2
Explanation: The underlined string is the pattern string 
successfully matched. The first index where the pattern 
has matched is 2. So result is 2.
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Solution 1: Brute force
Approach:

This is the naive brute force approach. You start at each index i in the given string and compare it with the first character of the pattern. If there is a match, then you head on to match the next character of both the string and the pattern. You do this until there is a mismatch in comparison. If there is a mismatch, then you stop the process and then repeat the same process again starting from the next index. 

Suppose you have string aaaaaaab and pattern aaaab, then you compare the string and pattern from the first index to discover that it fails in the fifth comparison of ‘a’ and ‘b’. So like this, when you compare starting from each index of string, finally you get the pattern matched. If the pattern is not present, then return the index value as -1. 

Code:

C++
Java
#include<bits/stdc++.h>
 
using namespace std;
int kmpBrute(string String, string pattern) {
  int n = String.size(), m = pattern.size();
  for (int i = 0; i < n + 1 - m; i++) {
    int j = 0;
    while (j < m && String[i + j] == pattern[j])
      j++;
    if (j == m) return i;
  }
  return -1;
}
int main() {
  string pattern="aaaaaab", String="aaaaaaaamaaaaaab";

  int index = kmpBrute(String, pattern);
  if (index == -1) cout << "The pattern is not found";
  else cout << "The pattern " << pattern << " is found in the given string " 
  << String << " at " << index;
  return 0;
}
Output: The pattern aaaaaab is found in the given string aaaaaaaamaaaaaab at 9

Time Complexity: O(mn) where m and n are patterns and string lengths respectively.

Since at each index, all m index values are to be compared in this approach, in total we will have m*n comparisons and hence O(mn).

Space Complexity: O(1) as no space is made use of. 

Solution 2: KMP Algorithm
Since we need to compare all m indices at each index in the given string, we need to come up with a more optimal approach. 

Intuition: 

Here we make use of the common prefix concepts. Whenever we find that prefixes are common, then we make a note of them so that those common prefixes are not compared again in subsequent searches.

Approach:

We make a pi Table here so keep track of common prefixes. We have to shift indices of the pattern by 1 to make the process easier, ie, the pattern begins at index 1 and we always compare pattern[j+1] with string[i] and not the jth index of the pattern. Then the only change is that whenever there is a mismatch, then we go to the index pointed to by our pi table and do not stop the search. Like this, we keep on going to previous indices of the pi table on mismatch until there is a mismatch or that j=0( refer to code for more understanding). So like this, when we find that j is m, we stop as we have found the pattern, else return -1 when i reaches n.



Code:

C++
Java
#include<bits/stdc++.h>
 
using namespace std;
int kmp(string String, string pattern) {
  int i = 0, j = 0, m = pattern.length(), n = String.length();
  pattern = ' ' + pattern; //just shifting the pattern indices by 1
  vector < int > piTable(m + 1, 0);
  for (int i = 2; i <= m; i++) {
    while (j <= m && pattern[j + 1] == pattern[i])
      piTable[i++] = ++j;
    j = 0;
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    if (pattern[j + 1] != String[i]) {
      while (j != 0 && pattern[j + 1] != String[i])
        j = piTable[j];
    }
    j++;
    if (j == m) return i - m + 1;
  }
  return -1;

}
int main() {
  string pattern="aaaaaab", String="aaaaaaaamaaaaaab";

  int index = kmp(String, pattern);
  if (index == -1) cout << "The pattern is not found";
  else cout << "The pattern " << pattern << " is found in the given string " 
  << String << " at " << index;
  return 0;
}
Output: The pattern aaaaaab is found in the given string aaaaaaaamaaaaaab at 9

Time Complexity: O(m+n) where m and n are patterns and string lengths respectively.
  
