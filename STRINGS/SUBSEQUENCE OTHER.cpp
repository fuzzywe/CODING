PCheck if a String is a subsequence of other
Example 1:
Input: S1= “tuf”, S2 =”takeuforward” 
Output: true
Explanation: 
string S1 can be obtained from the S2 by deleting characters a,k,e,o,r,w,a,r,d. Here the relative ordering of characters of S1 is maintained in S2 . ‘t’ appears before ‘u’ and ‘u’ appears before ‘f’.

Example 2:
Input: S1 = “cdx”,S2 = “coding”
Output: false
Explanation:‘x’ is not present in S2, So in any way we cannot get S1 by deleting some characters in S2.

Example 3:
Input: S1 = “fgn” , S2= “faang”
Output: false
Explanation: 
All the characters in S1 are in S2 but the relative ordering of characters is S1 is different from S2.
In S1 g appears before n, whereas in S2 g appears after n. As relative ordering is different, S1 is not the subsequence of S2.

#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string & S1, string & S2) {
  int i = 0, j = 0; // pointers for string S1 and S2

  // iterating until reaching end of any one string.
  for (; i < S1.length() && j < S2.length(); j++)
    if (S1[i] == S2[j])
      i++; // incrementing i

  return (i == S1.length()); // checking conditon
}

int main()
{
  string S1 = "tuf", S2 = "takeuforward";

  if (isSubsequence(S1, S2))
    cout << S1 << " is subsequence of " << S2 << endl;
  else
    cout << S1 << " is not subsequence of " << S2 << endl;

  return 0;
}
Output:

tuf is subsequence of takeuforward

Time Complexity :  O( min( |S1| , |S2| ) ) Because the for loop runs until the end of any string is reached. The end of the string with minimum length is reached first. So Time complexity is the minimum length of S1 and S2.

Space Complexity: O(1) We are not using any extra space.



  #include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string & s1, string & s2,int n,int m) {
   
  if (n == 0)
    return true; // we reach the end of the s1,so return true;
  if (m == 0)
    return false; 
  // we reached end of S2,with characters 
  // remaining in s1,so return false
  if (s1[n - 1] == s2[m - 1])
    // moving ahead in both strings
    return isSubsequence(s1, s2, n - 1, m - 1); 
  else
    // moving ahead in only S2
    return isSubsequence(s1, s2, n, m - 1); 

}

int main()
{
  string S1 = "tuf", S2 = "takeuforward";
  if (isSubsequence(S1, S2,S1.length(),S2.length()))
    cout << S1 << " is subsequence of " << S2 << endl;
  else
    cout << S1 << " is not subsequence of " << S2 << endl;
  return 0;
}
 Output:

 tuf is subsequence of takeuforward.

Time Complexity:  O( min( |S1|, |S2| ) ) Because the recursion calls are made until the end of any string is reached. The end of the string with minimum length is reached first. So Time complexity is the minimum length of S1 and S2.

Space Complexity :  O( min( |S1| , |S2| ) ) Auxiliary stack space.
