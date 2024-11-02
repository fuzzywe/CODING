https://leetcode.com/problems/add-strings/description/

415. Add Strings
Solved
Easy
Topics
Companies
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
---

```cpp

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0, sum;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');  // Append the last digit of sum as a character
            carry = sum / 10;  // Update carry for the next iteration
        }

        reverse(result.begin(), result.end());  // Reverse the result to get the correct order
        return result;
    }
};


```
