Input: 
wild = ge*ks
pattern = geeks
Output: Yes
Explanation: Replace the '*' in wild string 
with 'e' to obtain pattern "geeks".
Example 2:

Input: 
wild = ge?ks*
pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in wild string with
'e' and 'forgeeks' respectively to obtain pattern 
"geeksforgeeks"

better approach(tabular approach)


#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    // Initialize the first row and column
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = isAllStars(S1, i);
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (S1[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

    // The value at dp[n][m] contains whether S1 matches S2
    return dp[n][m];
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}

Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M’. Stack Space is eliminated.



The goal of this code is to perform wildcard pattern matching between two strings, S1 and S2. The wildcard string S1 can contain two special characters:

'?': Matches any single character.
'*': Matches any sequence of characters (including an empty sequence).
Function: isAllStars
This function checks if the first i characters of string S1 contain only '*'.

Code:
cpp
Copy code
bool isAllStars(string &S1, int i) {
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}
Explanation:
This function is used to check if the first i characters in S1 are all '*'. It iterates through the first i characters and returns true only if all characters are '*'.
Function: wildcardMatching
This is the main function that checks if the wildcard pattern S1 matches the string S2 using dynamic programming (DP).

Code:
cpp
Copy code
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));
Explanation:
n: The length of S1.
m: The length of S2.
dp[i][j]: A 2D DP table where dp[i][j] represents whether the first i characters of S1 can match the first j characters of S2.
The table is initialized as false and then updated as we proceed with matching.
Code:
cpp
Copy code
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = false;
    }
Explanation:
dp[0][0] = true means an empty pattern S1 can match an empty string S2.
dp[0][j] = false (for all j > 0) means an empty pattern cannot match a non-empty string S2.
Code:
cpp
Copy code
    for (int i = 1; i <= n; i++) {
        dp[i][0] = isAllStars(S1, i);
    }
Explanation:
This loop fills the first column (dp[i][0]), which represents the case where S2 is an empty string.
If all the characters in S1 up to index i are '*', then dp[i][0] = true because a sequence of '*' can match an empty string.
DP Table Filling:
The key part of the DP logic comes next.

Code:
cpp
Copy code
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (S1[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }
Explanation:
If S1[i-1] matches S2[j-1] (either they are the same character or S1[i-1] is ?), then dp[i][j] = dp[i-1][j-1]. This means if the previous part of the strings matched, the current part also matches.

If S1[i-1] is '*', then:

dp[i][j] = dp[i-1][j]: The '*' is treated as an empty sequence, meaning we skip the '*' in S1.
dp[i][j] = dp[i][j-1]: The '*' is treated as matching the current character S2[j-1] (and we continue matching the rest of S2).
If none of the above conditions are true, the characters don’t match and dp[i][j] = false.

Final Check:
cpp
Copy code
    return dp[n][m];
}
Explanation:
The value at dp[n][m] will tell us if the entire string S1 matches S2.
Example:
Let’s take S1 = "ab*cd" and S2 = "abdefcd".

S1 contains a wildcard *, which can match any sequence of characters.
We need to see if S1 can match S2.
DP Table Filling (partial):
Initialization:

dp[0][0] = true (empty pattern matches empty string).
dp[i][0] will be true for S1 where the prefix contains only *.
First few rows of DP table (matching without *):

sql
Copy code
dp[1][1] = true  // 'a' matches 'a'
dp[2][2] = true  // 'ab' matches 'ab'
dp[3][3] = true  // '*' can match 'd'
dp[3][4] = true  // '*' can match 'de'
dp[3][5] = true  // '*' can match 'def'
dp[3][6] = true  // '*' can match 'defc'
dp[4][6] = true  // 'c' matches 'c'
dp[5][7] = true  // 'd' matches 'd'
Output:
bash
Copy code
String S1 and S2 do match
In this case, the pattern "ab*cd" successfully matches "abdefcd", so the program will print that the strings match.

best approach:


#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current rows of matching results
    vector<bool> prev(m + 1, false);
    vector<bool> cur(m + 1, false);

    prev[0] = true; // Initialize the first element of the previous row to true

    for (int i = 1; i <= n; i++) {
        cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                cur[j] = prev[j - 1]; // Characters match or S1 has '?'
            } else {
                if (S1[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
                } else {
                    cur[j] = false; // Characters don't match and S1[i-1] is not '*'
                }
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at prev[m] contains whether S1 matches S2
    return prev[m];
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}


