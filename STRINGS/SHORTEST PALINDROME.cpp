Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 class Solution {
public:
    string shortestPalindrome(string s) {
        string reversedString = s;
        // Reverse the original string
        reverse(reversedString.begin(), reversedString.end());

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < s.size(); ++i) {
            // memcmp to avoid creating substrings
            if (!memcmp(s.c_str(), reversedString.c_str() + i, s.size() - i)) {
                // Append the necessary part to make the palindrome
                return reversedString.substr(0, i) + s;
            }
        }
        // Fallback case, append the whole reversed string to the original
        // string
        return reversedString + s;
    }
};
Complexity Analysis
Let n be the length of the input string s.

Time complexity: O(n2)

The reversal of the string s involves traversing the string once, which has a time complexity of O(n).
Space complexity: O(n)

Creating the reversed string involves additional space proportional to the length of the input string, i.e., O(n).

The substring operations in the for loop do not require additional space proportional to the length of the string but do create new string objects temporarily, which is still O(n) space for each substring.

Therefore, the overall space complexity is O(n).
best solution:

class Solution {
public:
    string shortestPalindrome(string s) {
        // Reverse the original string
        string reversedString = string(s.rbegin(), s.rend());

        // Combine the original and reversed strings with a separator
        string combinedString = s + "#" + reversedString;

        // Build the prefix table for the combined string
        vector<int> prefixTable = buildPrefixTable(combinedString);

        // Get the length of the longest palindromic prefix
        int palindromeLength = prefixTable[combinedString.length() - 1];

        // Construct the shortest palindrome by appending the reverse of the
        // suffix
        string suffix = reversedString.substr(0, s.length() - palindromeLength);
        return suffix + s;
    }

private:
    // Helper function to build the KMP prefix table
    vector<int> buildPrefixTable(const string& s) {
        vector<int> prefixTable(s.length(), 0);
        int length = 0;

        // Build the table by comparing characters
        for (int i = 1; i < s.length(); i++) {
            while (length > 0 && s[i] != s[length]) {
                length = prefixTable[length - 1];
            }
            if (s[i] == s[length]) {
                length++;
            }
            prefixTable[i] = length;
        }
        return prefixTable;
    }
};
Complexity Analysis
Let n be the length of the input string.

Time complexity: O(n)

Creating the reversed string requires a pass through the original string, which takes O(n) time.

Concatenating s, #, and reversedString takes O(n) time, as concatenating strings of length n is linear in the length of the strings.

Constructing the prefix table involves iterating over the combined string of length 2n+1. The buildPrefixTable method runs in O(m) time, where m is the length of the combined string. In this case, m=2n+1, so the time complexity is O(n).

Extracting the suffix and reversing it are both O(n) operations.

Combining these, the overall time complexity is O(n).

Space complexity: O(n)

The reversedString and combinedString each use O(n) space.

The prefixTable array has a size of 2n+1, which is O(n). Other variables used (such as length and indices) use O(1) space.

Combining these, the overall space complexity is O(n).

