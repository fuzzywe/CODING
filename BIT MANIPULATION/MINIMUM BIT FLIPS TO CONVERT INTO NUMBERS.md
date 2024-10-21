https://leetcode.com/problems/minimum-bit-flips-to-convert-number/


2220. Minimum Bit Flips to Convert Number
Solved
Easy
Topics
Companies
Hint
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

 

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.


Let me break it down further to explain the mathematics behind the code more clearly:

### Problem
You want to find the minimum number of bit flips needed to change a number `start` into another number `goal`.

### Understanding XOR (`^`):
The XOR operation compares two numbers bit by bit. It returns `1` for a bit position where the bits are different and `0` where they are the same. So:
- If two bits are the same: the XOR result for that bit is `0`.
- If two bits are different: the XOR result for that bit is `1`.

For example, if you XOR two numbers `start` and `goal`:
- `start = 10` (binary: `1010`)
- `goal = 7` (binary: `0111`)

```
Binary of 10:  1 0 1 0
Binary of 7:   0 1 1 1
---------------------
XOR Result:    1 1 0 1
```
This result tells you where the bits differ. The XOR result is `1101`, so the first, second, and fourth bits are different between `start` and `goal`. We need to flip these bits to make `start` equal to `goal`.

Now, we just need to count how many `1`s are in the XOR result because each `1` means that the corresponding bit in `start` needs to be flipped.

### Code Explanation:

Let's go through the code step by step:

```cpp
int minBitFlips(int start, int goal) {
    int xorResult = start ^ goal;
    int ans = 0;
    
    while (xorResult > 0) {
        ans += xorResult & 1;
        xorResult >>= 1;
    }
    
    return ans;
}
```

#### Step-by-Step Breakdown:

1. **XOR the two numbers**:
   ```cpp
   int xorResult = start ^ goal;
   ```
   This line calculates the XOR of `start` and `goal`. The XOR result will give you a binary number where:
   - A `1` means the bits at that position in `start` and `goal` are different.
   - A `0` means the bits at that position in `start` and `goal` are the same.

   Example:
   - `start = 10` (binary: `1010`)
   - `goal = 7` (binary: `0111`)

   The XOR result will be `1101` in binary.

2. **Initialize a counter**:
   ```cpp
   int ans = 0;
   ```
   This variable `ans` will store the number of bit flips required.

3. **Count how many `1`s are in the XOR result**:
   ```cpp
   while (xorResult > 0) {
       ans += xorResult & 1;
       xorResult >>= 1;
   }
   ```

   This loop checks each bit of the XOR result:
   - `xorResult & 1`: This checks if the least significant bit (rightmost bit) of `xorResult` is `1`. If it's `1`, it means the corresponding bit in `start` and `goal` are different, so we increment `ans` by 1.
   - `xorResult >>= 1`: This shifts `xorResult` one position to the right, effectively removing the least significant bit. We do this to check the next bit in the next iteration of the loop.

   Let's go through this step with the XOR result `1101` (binary):

   - **First iteration**:
     - `xorResult = 1101` (binary)
     - `xorResult & 1 = 1` (rightmost bit is `1`)
     - Increment `ans` to `1`
     - Shift `xorResult` right: `xorResult = 110` (binary)

   - **Second iteration**:
     - `xorResult = 110` (binary)
     - `xorResult & 1 = 0` (rightmost bit is `0`)
     - No increment to `ans`
     - Shift `xorResult` right: `xorResult = 11` (binary)

   - **Third iteration**:
     - `xorResult = 11` (binary)
     - `xorResult & 1 = 1` (rightmost bit is `1`)
     - Increment `ans` to `2`
     - Shift `xorResult` right: `xorResult = 1` (binary)

   - **Fourth iteration**:
     - `xorResult = 1` (binary)
     - `xorResult & 1 = 1` (rightmost bit is `1`)
     - Increment `ans` to `3`
     - Shift `xorResult` right: `xorResult = 0` (binary)

   The loop stops when `xorResult` becomes `0`.

4. **Return the result**:
   ```cpp
   return ans;
   ```
   The `ans` variable now contains the number of `1`s in the XOR result, which corresponds to the number of bit flips needed to convert `start` to `goal`.

### Summary:

- The XOR operation helps identify the positions where the bits differ between `start` and `goal`.
- Counting the number of `1`s in the XOR result gives you the number of bit flips needed to make `start` equal to `goal`.
- The loop checks each bit of the XOR result and shifts it right until all bits have been checked.

This approach is efficient and works within the limits of typical bitwise operations in C++.
```
