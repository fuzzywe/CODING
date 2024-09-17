Palindromic substrings
Example 1:
Input: abc 
Output: 3 
Explanation: palindromic substrings are 'a', 'b' ,'c' 

Example 2:
Input: aaa 
Output: 6 
Explanation: palindromic substrings are 'a', 'a' ,'aa','aa','a','aaa'

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
