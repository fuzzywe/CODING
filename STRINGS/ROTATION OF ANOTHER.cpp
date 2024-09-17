Check if given strings are rotations of each other or not
Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false

  
class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0 , n = s.size();
        while(i < n){
            s = s.substr(1) + s[0];//s= abcde = [bcde] + [a] = bcdea
            if(s == goal) return true;
            i++;
        }
        return false;
    }
};//his code got simplified to a great extent bcz of the substr stl function. 

Time Complexity: O(n^2) (due to substr and string comparison in each iteration).
Space Complexity: O(n) (due to the space required to store the string s and goal).
Initial Strings:

s = "abcde"
goal = "cdeab"
First Check (No Rotation):

We compare s with goal:
s = "abcde"
goal = "cdeab"
They do not match, so we rotate s.
First Rotation:

We move the first character of s to the end.
New s after rotation:
s = "bcdea"
Compare it with goal:
goal = "cdeab"
They do not match, so we rotate s again.
Second Rotation:

Rotate s again. Move the first character to the end:
New s:
s = "cdeab"
Compare it with goal:
goal = "cdeab"
Now, they match!
So, we return true because goal can be obtained by rotating s.
Summary of Rotations:
Rotation 0: "abcde" → does not match "cdeab"
Rotation 1: "bcdea" → does not match "cdeab"
Rotation 2: "cdeab" → matches "cdeab"
Since we found a match after 2 rotations, the function returns true.

best solution:

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths of s and goal are equal
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate s with itself
        string concatenated = s + s;

        // Check if goal is a substring of concatenated string
        return concatenated.find(goal) != string::npos;
    }
};
Time Complexity: O(n).
Space Complexity: O(n).
  Length Check:

cpp
Copy code
if (s.length() != goal.length()) {
    return false;
}
The first check compares the lengths of s and goal. If the lengths are not the same, it is impossible for goal to be a rotation of s, so the function returns false.
For example, if s = "abcde" and goal = "abcd", we would immediately return false because they have different lengths.
Concatenation of s:

cpp
Copy code
string concatenated = s + s;
We concatenate s with itself to form a new string concatenated.
Example: If s = "abcde", concatenating it with itself results in:
concatenated = "abcdeabcde".
The logic here is that any rotation of s will appear as a substring within s + s. Why? Because when you rotate a string, you're essentially cycling the characters, and concatenating s with itself captures all possible rotations within that single string.
Checking if goal is a substring:

cpp
Copy code
return concatenated.find(goal) != string::npos;
The find() function looks for goal as a substring within concatenated.
find() returns the starting position of goal if it is found, or 
string::npos (a special value indicating "not found") if goal is not a substring.
If goal is found, the function returns true; otherwise, it returns false.
Example Walkthrough:
Example 1:

Input: s = "abcde", goal = "cdeab"
After concatenation:
concatenated = "abcdeabcde"
Check if goal ("cdeab") is a substring of "abcdeabcde":
Yes, "cdeab" is a substring of "abcdeabcde", so the function returns true.
Example 2:

Input: s = "abcde", goal = "abced"
After concatenation:
concatenated = "abcdeabcde"
Check if goal ("abced") is a substring of "abcdeabcde":
No, "abced" is not a substring of "abcdeabcde", so the function returns false.
Time Complexity:
Concatenation: Concatenating s with itself takes O(n), where n is the length of s.
Substring Search: The find() function takes O(n) to search for goal in the concatenated string.
Overall, the time complexity is O(n), which is efficient compared to the brute-force method that could take O(n²).
Space Complexity:
The space complexity is O(n), where n is the length of s, because we create a new string concatenated that is twice the length of s.
