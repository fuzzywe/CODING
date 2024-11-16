67. Add Binary

https://leetcode.com/problems/add-binary/description/

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

```cpp

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
```

In the provided code snippet:

carry += a[i--] - '0';
if (j >= 0)
    carry += b[j--] - '0';

The i-- and j-- operators are used to process the characters in the strings a and b from right to left, one at a time, in reverse order.

Here’s the breakdown:

1. Processing the Numbers from Right to Left:
Strings representing numbers are indexed from 0 (leftmost digit) to n-1 (rightmost digit). However, addition starts from the least significant digit (rightmost side) and moves toward the most significant digit (leftmost side). The i-- decrements the index i after accessing the current character, so you move from the end of the string toward the beginning.

a[i--]: Access the current character at index i and then decrement i to prepare for the next iteration.

- '0': Converts the character to its corresponding integer value by subtracting the ASCII value of '0'.



2. Why i-- Instead of i?:
Using i-- ensures that the current digit is accessed before i is decremented, so the code processes the correct digit in the current step. If you use --i, the index would decrement before accessing the digit, causing the loop to skip the last digit.


3. Example:
Suppose a = "1234" and b = "567". The indices and characters would be processed as follows:

Initially, i = 3 (pointing to '4') and j = 2 (pointing to '7').

In the first iteration:

a[i--]: Access '4', then decrement i to 2.

b[j--]: Access '7', then decrement j to 1.


In the next iteration:

a[i--]: Access '3', then decrement i to 1.

b[j--]: Access '6', then decrement j to 0.


Continue until all digits are processed.



4. Without i--:
If i-- is omitted (e.g., just a[i]), the loop will either:

Not decrement the index, resulting in incorrect behavior, or

Require manual decrementing in a separate step, which is less efficient and less clean.




Thus, using i-- (and j--) simplifies the logic and ensures correct processing of the digits in reverse order.


