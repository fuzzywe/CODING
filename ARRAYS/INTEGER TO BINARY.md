Integer to binary

brute force

```cpp

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";  // Handle the case when n is 0

        vector<int> binaryformat;
        while (n != 0) {
            int remainder = n % -2;
            n /= -2;

            // Adjust remainder and quotient if remainder is negative
            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }

            binaryformat.push_back(remainder);
        }

        // Construct the result string in reverse order
        string result;
        for (int i = binaryformat.size() - 1; i >= 0; i--) {
            result += to_string(binaryformat[i]);
        }

        return result;
    }
};


```
or 
```cpp
class Solution:    
    def baseNeg2(self, n: int) -> str:        
        result = ""

        while n != 0:
            rem = n % -2
            n //= -2
            if rem < 0:
                rem += 2
                n += 1
            result = str(rem) + result

        return max(result, str("0"))
```
This code snippet is adjusting the remainder and quotient for the base -2 conversion when the remainder is negative. Let’s break down why these adjustments are necessary.

### Explanation of the Adjustment Code
When dividing by a negative base (like -2), the modulus (remainder) operation doesn’t work the same way as with positive bases. If the remainder is negative, we need to "fix" it to keep the representation in binary digits (0 and 1). Here’s how it works:

```cpp
if (remainder < 0) {
    remainder += 2;
    n += 1;
}
```
The `-2` base is used in this problem because we are representing numbers in "negative base 2" (base -2). In this numeral system, the base is negative rather than positive, which allows for unique representations of numbers and avoids the need for a negative sign in front of the representation. Here’s a breakdown of why `-2` is chosen and how it works:

### What is Base -2?
In the base -2 system:
- Each digit represents a power of -2, not 2. 
- The place values (moving from right to left) are `1, -2, 4, -8, 16`, etc., following powers of `-2` instead of `+2`.

![08 11 2024_17 51 31_REC](https://github.com/user-attachments/assets/8958ee2b-4c71-4ef8-8af7-adf2b434f6d9)

### Why Use Base -2?
Using base -2 is useful for certain applications, especially in algorithms where signed values (both positive and negative) need to be represented without additional sign indicators. In base -2:
- Positive and negative numbers can be represented without using a separate sign bit.
- You get unique representations of numbers, which can simplify algorithms dealing with binary representations in certain scenarios.

### How Does It Work in Code?
When converting a number to base -2:
1. Each time we calculate `n % -2` (the remainder), we need to account for both positive and negative remainders, which is why we adjust if the remainder is negative.
2. We then adjust `n` by dividing by `-2`, but if the remainder was negative, we also add `1` to `n` to "carry" in base -2 terms.

![08 11 2024_17 51 16_REC](https://github.com/user-attachments/assets/a2e89dc4-6b5a-4cc7-8272-0cf92ff0b9df)


Resulting binary string (from bottom up): `101`

Here’s what each line does:
1. **`remainder += 2;`**: This adjusts the remainder to make it positive. Since we are working in binary (where digits are either 0 or 1), we want the remainder to be a valid binary digit (0 or 1).
   
   - By adding `2` to a negative remainder (such as -1), we ensure it becomes a positive value (like 1), fitting the binary system requirements.

2. **`n += 1;`**: This line adjusts the quotient `n` by increasing it by 1 to balance the adjustment made to the remainder.
   
   - Since we’ve added `2` to the remainder, we must also adjust `n` to account for this change. Adding 1 to `n` effectively "carries" over a value to the next higher place value in base -2, making the division work correctly.

### Why These Adjustments Are Needed
In base -2 conversion, without adjusting the remainder and quotient, we might get a remainder that doesn’t meet the binary representation constraints (0 or 1). This approach ensures that each digit is either 0 or 1, resulting in a correct base -2 representation.

### Example of the Adjustment
Let's say we are converting `n = 7` to base -2.

1. **First Division**:
   - `n = 7`
   - `remainder = 7 % -2 = -1` (negative remainder)
   - Adjust remainder: `remainder = -1 + 2 = 1`
   - Adjust quotient: `n = (7 / -2) + 1 = -3`

2. **Second Division**:
   - `n = -3`
   - `remainder = -3 % -2 = -1`
   - Adjust remainder: `remainder = -1 + 2 = 1`
   - Adjust quotient: `n = (-3 / -2) + 1 = 2`

3. **Third Division**:
   - `n = 2`
   - `remainder = 2 % -2 = 0`
   - `n = 2 / -2 = -1`

4. **Fourth Division**:
   - `n = -1`
   - `remainder = -1 % -2 = -1`
   - Adjust remainder: `remainder = -1 + 2 = 1`
   - Adjust quotient: `n = (-1 / -2) + 1 = 1`

The final result will be constructed from these remainders in reverse order, providing the correct base -2 binary representation.
--- 
optimal

```cpp


```
