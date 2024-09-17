Longest Palindromic Substring
Last Updated : 01 Sep, 2024
Given a string str, the task is to find the longest substring which is a palindrome. If there are multiple answers, then return the first appearing substring.

Examples:

Input: str = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.

Input: str = “Geeks” 
Output: “ee”

Input: str = “abc” 
Output: “a”

Input: str = “” 
Output: “”
#include <bits/stdc++.h>
using namespace std;

// Function to find the longest palindrome substring
string longestPalSubstr(string &s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    int maxLen = 1;
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // Check for sub-string of length 2
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check for lengths greater than 2
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                if (k > maxLen) {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

// Driver Code
int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalSubstr(s) << endl;
    return 0;
}

Time complexity: O(N2). A nested traversal is needed.
Auxiliary Space: O(N2). A matrix of size N*N is needed to store the table.


#include <bits/stdc++.h>
using namespace std;

string longestPalSubstr(string &s) {
    int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    // Traverse the input string
    for (int i = 0; i < n; i++) {

        // THIS RUNS TWO TIMES 
        // for both odd and even length
        // palindromes. j = 0 means odd
        // and j = 1 means odd length
        for (int j = 0; j <= 1; j++) {
            int low = i;
            int hi = i + j; 

            // Expand substring while it is a palindrome
            // and in bounds
            while (low >= 0 && hi < n && s[low] == s[hi]) {
                int currLen = hi - low + 1;
                if (currLen > maxLen) {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                hi++;
            }
        }
    }

    return s.substr(start, maxLen);
}

// Driver code
int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalSubstr(s) << endl;
    return 0;
}
Time complexity: O(N2), where N is the length of the input string
Auxiliary Space: O(1), No extra space used.

