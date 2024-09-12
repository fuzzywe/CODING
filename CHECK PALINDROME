If you need a brute-force approach to check if a string is a palindrome, you can follow a straightforward method. This approach involves creating a reversed version of the string and then comparing it to the original string to determine if they are the same.

Here’s the C++ code for this brute-force approach:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Function to reverse a string
string reverseString(const string& s) {
    string reversed;
    for (int i = s.length() - 1; i >= 0; --i) {
        reversed += s[i];
    }
    return reversed;
}

// Function to check if a string is a palindrome using brute force
bool isPalindrome(const string& s) {
    string reversed = reverseString(s);
    return s == reversed;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input); // Read the entire line including spaces

    bool palindrome = isPalindrome(input);

    cout << "Is the string \"" << input << "\" a palindrome? " << (palindrome ? "Yes" : "No") << endl;

    return 0;
}
```

### Explanation:

1. **`reverseString(const string& s)`**:
   - Reverses the given string by iterating from the end to the start of the string and appending each character to a new string `reversed`.

2. **`isPalindrome(const string& s)`**:
   - Uses the `reverseString` function to get the reversed version of the string.
   - Compares the original string `s` with the reversed string to determine if they are equal.

3. **`main()`**:
   - Prompts the user to input a string.
   - Calls `isPalindrome()` to check if the string is a palindrome.
   - Prints the result.

### Time and Space Complexity

- **Time Complexity**: **O(n)**, where **n** is the length of the string. This is because:
  - Reversing the string takes **O(n)** time.
  - Comparing the original and reversed strings also takes **O(n)** time.
  
- **Space Complexity**: **O(n)**, where **n** is the length of the string. This is due to:
  - The space required to store the reversed string, which is proportional to the length of the input string.

In summary:
- **Time Complexity**: **O(n)**
- **Space Complexity**: **O(n)**
#include <iostream>
using namespace std;

bool palindrome(int i, string& s){
    
    // Base Condition
    // If i exceeds half of the string means all the elements 
    // are compared, we return true.
    if(i>=s.length()/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[s.length()-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(i+1,s);
}

int main() {
	
	// Example string.
	string s = "madam";
	cout<<palindrome(0,s);
	cout<<endl;
	return 0;
}
Output:

True

Time Complexity: O(N) { Precisely, O(N/2) as we compare the elements N/2 times and swap them}.

Space Complexity: O(1) { The elements of the given array are swapped in place so no extra space is required}.
**example**
palindrome Function:

Base Case:

if(i >= s.length()/2) return true;

This checks if the current index i has reached or passed the middle of the string. If it has, it means that all the characters have been successfully compared and the string is a palindrome, so it returns true.
Recursive Case:

if(s[i] != s[s.length()-i-1]) return false;

This checks if the character at the i-th position from the start (s[i]) is equal to the character at the i-th position from the end (s[s.length()-i-1]).
If they are not equal, it returns false because the string is not a palindrome.
If they are equal, the function calls itself recursively with i+1, moving inward to check the next pair of characters.
In main():

The string "madam" is passed to the recursive function palindrome(0, s) starting from index 0.
The result is printed as 1 for true if the string is a palindrome and 0 for false if it is not.
Example: "madam"
We want to check if "madam" is a palindrome. Here’s how the recursive function works:

First Call: palindrome(0, "madam")

i = 0, s[i] = 'm', s[s.length() - i - 1] = s[5 - 0 - 1] = 'm'.
'm' == 'm', so it moves to the next recursion: palindrome(1, "madam").
Second Call: palindrome(1, "madam")

i = 1, s[i] = 'a', s[s.length() - i - 1] = s[5 - 1 - 1] = 'a'.
'a' == 'a', so it moves to the next recursion: palindrome(2, "madam").
Third Call: palindrome(2, "madam")

i = 2, s[i] = 'd', s[s.length() - i - 1] = s[5 - 2 - 1] = 'd'.
'd' == 'd', and since i >= s.length() / 2 (middle of the string), the base condition is satisfied, and it returns true.
Returning from Recursion:

Since the third call returns true, the second call also returns true, and then the first call returns true.
Final Output:

The result is true (1 in the output), indicating that "madam" is a palindrome




**best case**

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {

        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;

}
int main() {

  string str = "ABCDCBA";
  bool ans = isPalindrome(str);

  if (ans == true) {
    cout << "Palindrome";
  } else {
    cout << "Not Palindrome";
  }
  return 0;
}
Output: Palindrome

Time Complexity:  O(N)

Space Complexity: O(1)


**example**

The string s = "ABCDCBA".
We initialize two pointers: left = 0 (pointing to the first character) and right = 6 (pointing to the last character).
First Iteration:

left = 0, right = 6.
Characters: s[left] = 'A', s[right] = 'A'.
Both characters are alphanumeric (isalnum() check passes) and are the same when converted to lowercase (tolower('A') == tolower('A')).
So, we move both pointers inward: left++, right-- → left = 1, right = 5.
Second Iteration:

left = 1, right = 5.
Characters: s[left] = 'B', s[right] = 'B'.
Both are alphanumeric and the same: tolower('B') == tolower('B').
Move inward again: left = 2, right = 4.
Third Iteration:

left = 2, right = 4.
Characters: s[left] = 'C', s[right] = 'C'.
Both are alphanumeric and the same: tolower('C') == tolower('C').
Move inward: left = 3, right = 3.
Fourth Iteration:

left = 3, right = 3.
Now, left and right both point to the middle character s[3] = 'D'.
Since left is no longer less than right (left == right), the loop exits.
Conclusion:

Since all the characters matched as we moved the left and right pointers towards the center, the function returns true, indicating that the string is a palindrome
