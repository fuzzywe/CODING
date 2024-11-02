https://leetcode.com/problems/add-digits/description/

258. Add Digits
Easy
Topics
Companies
Hint
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


OPTIMAL 

```cpp

class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        int k=10;
        while(k>9)
        {
            k=0;
            for(int i=0;i<s.size();i++)
            {
                k+=s[i]-48;
            }
            s=to_string(k);
        }
        return k;
    }
};

```

Let’s visually walk through the process of how the loop adds two strings digit by digit, just like you would with long addition. Imagine we have two numbers as strings, `num1 = "123"` and `num2 = "7890"`. We’ll start from the right (the least significant digit) and move left, keeping track of any carry.

---

### Initial Setup:
- `num1 = "123"`
- `num2 = "7890"`
- Start from the right:
  - `i = num1.length() - 1 = 2`
  - `j = num2.length() - 1 = 3`
- `carry = 0`
- Result: `str = ""`

### Step-by-Step Addition (Visualized):

#### **First Iteration (Rightmost Digit):**
- **Retrieve digits**:
  - `digit1 = num1[i] - '0' = 3`
  - `digit2 = num2[j] - '0' = 0`
- **Sum**: `3 + 0 + carry = 3 + 0 + 0 = 3`
- **Update carry**: `carry = 3 / 10 = 0`
- **Append `3`** to result: `str = "3"`
- **Move Left**: `i--` (now 1), `j--` (now 2)

#### **Second Iteration:**
- **Retrieve digits**:
  - `digit1 = num1[i] - '0' = 2`
  - `digit2 = num2[j] - '0' = 9`
- **Sum**: `2 + 9 + carry = 2 + 9 + 0 = 11`
- **Update carry**: `carry = 11 / 10 = 1`
- **Append `1`** (last digit of `11`) to result: `str = "31"`
- **Move Left**: `i--` (now 0), `j--` (now 1)

#### **Third Iteration:**
- **Retrieve digits**:
  - `digit1 = num1[i] - '0' = 1`
  - `digit2 = num2[j] - '0' = 8`
- **Sum**: `1 + 8 + carry = 1 + 8 + 1 = 10`
- **Update carry**: `carry = 10 / 10 = 1`
- **Append `0`** (last digit of `10`) to result: `str = "310"`
- **Move Left**: `i--` (now -1), `j--` (now 0)

#### **Fourth Iteration:**
- **Retrieve digits**:
  - `digit1 = 0` (since `i < 0`)
  - `digit2 = num2[j] - '0' = 7`
- **Sum**: `0 + 7 + carry = 0 + 7 + 1 = 8`
- **Update carry**: `carry = 8 / 10 = 0`
- **Append `8`** to result: `str = "3108"`
- **Move Left**: `j--` (now -1)

---

### Final Step:
- **Reverse** `str` to get the correct order: `str.reverse() = "8013"`

So the final result is `"8013"`.

The `'0'` is used in expressions like `num1[i] - '0'` to convert a character representing a digit (e.g., `'3'`) into its corresponding integer value.

### Explanation:
In ASCII (or any other character encoding), each character has a numeric code. For example:
- `'0'` in ASCII has a code of **48**
- `'1'` has a code of **49**
- `'2'` has a code of **50**
- …and so on.

So if we want to convert a character digit, like `'3'`, to its integer form, we subtract the ASCII value of `'0'` from it:
- `'3'` has a value of **51** in ASCII.
- `'0'` has a value of **48** in ASCII.

When we subtract `'3' - '0'`, we get:
- **51 - 48 = 3**

This is why the line `digit1 = num1[i] - '0'` effectively converts the character at `num1[i]` to an integer. This method works for any single character digit and is a standard way in C++ and other languages to convert a character from `0` to `9` into its numeric value.
