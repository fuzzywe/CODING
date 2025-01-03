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


The provided code snippet is part of a binary addition algorithm, where two binary strings are being added. Let’s break down what each part of the code does:

ans += carry % 2 + '0';
carry /= 2;

Step-by-Step Explanation:

1. carry % 2:

This computes the remainder when carry is divided by 2.

Since binary addition only deals with two digits (0 and 1), the remainder of carry % 2 gives the current binary digit (either 0 or 1) to be added to the result.


2. + '0':

Binary addition outputs digits (0 or 1). In the code, the result carry % 2 is converted to a character by adding the ASCII value of '0' (which is 48). This ensures that the binary digit becomes a character suitable for appending to the string ans.

For example:

If carry % 2 == 1, then 1 + '0' becomes '1'.

If carry % 2 == 0, then 0 + '0' becomes '0'.



3. ans += ...:

This appends the resulting character ('0' or '1') to the string ans.

Since addition processes the binary strings from right to left (least significant digit to most significant digit), the resulting binary string is constructed in reverse order.


4. carry /= 2;:

This updates the carry by dividing it by 2.

In binary addition, carry can either be 0, 1, or 2:

If carry is 2, dividing by 2 reduces it to 1, which represents the carry-over for the next higher bit.

If carry is 0 or 1, dividing by 2 reduces it to 0, as no further carry-over exists.



Example:

Let’s walk through an example binary addition of "101" and "11":

1. Initial Variables:
a = "101", b = "11", carry = 0, ans = ""


2. Iteration 1 (Rightmost digits):

Add 1 (a) + 1 (b) + 0 (carry) = 2.

carry % 2 = 0 → Append '0' to ans → ans = "0".

carry /= 2 = 1 → Carry is now 1.



3. Iteration 2 (Next digits):

Add 0 (a) + 1 (b) + 1 (carry) = 2.

carry % 2 = 0 → Append '0' to ans → ans = "00".

carry /= 2 = 1 → Carry is now 1.



4. Iteration 3 (Leftmost digits):

Add 1 (a) + 0 (b, none left) + 1 (carry) = 2.

carry % 2 = 0 → Append '0' to ans → ans = "000".

carry /= 2 = 1 → Carry is now 1.



5. Final Carry:

After processing all digits, append the remaining carry:
carry % 2 = 1 → Append '1' → ans = "1000".



6. Result:
The final binary sum is "1000" (the reverse of ans, since it was built backward).



This snippet ensures that each binary digit is calculated correctly and carry-over is handled for the next iteration.



