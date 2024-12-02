brute force

```cpp
#include <bits/stdc++.h>
using namespace std;

string bin(unsigned int n) {
    string ans = "";
    while (n > 0) {
        ans = to_string(n & 1) + ans;
        n >>= 1;
    }
    return ans;
}

bool checkPalindrome(unsigned int n) {
    string s1 = bin(n);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    unsigned int x;

    x = (1 << 15) + (1 << 16);
    cout << "Is binary of " << x << " a palindrome? " << (checkPalindrome(x) ? "Yes" : "No") << endl;

    x = 10;
    cout << "Is binary of " << x << " a palindrome? " << (checkPalindrome(x) ? "Yes" : "No") << endl;

    return 0;
}


```

Time Complexity:bin() function: Each time we shift the number to the right, the number is reduced in half, so the function runs in O(log₂(n)) time where n is the input number.checkPalindrome() function:Converting the number to binary takes O(log₂(n)) time.Reversing the string and comparing it takes O(log₂(n)) time.Overall, the time complexity is O(log₂(n)).

Space Complexity:bin() function: The binary string uses space proportional to the number of bits in the binary representation of n, which is O(log₂(n)).

example

Let's walk through the code step by step and use `10` as the input to explain the logic.

### 1. **Function: `bin(unsigned n)`**
This function converts an integer `n` into its binary string representation. The main steps are:
- **Loop**: As long as `n > 0`, the loop will execute.
- **n & 1**: This extracts the least significant bit (LSB) of `n` and converts it into a string using `to_string(n&1)`.
- **ans = (to_string(n&1)) + ans**: The LSB is added to the front of the current string `ans`.
- **n >>= 1**: This shifts `n` to the right by 1 bit (dividing `n` by 2 in binary terms).
- The loop continues until `n` becomes `0`.

For example, with `n = 10` (in decimal):
- **Step 1**: `10 & 1` gives `0` → `ans = "0"`
- **Step 2**: `10 >>= 1` makes `n = 5`
- **Step 3**: `5 & 1` gives `1` → `ans = "10"`
- **Step 4**: `5 >>= 1` makes `n = 2`
- **Step 5**: `2 & 1` gives `0` → `ans = "010"`
- **Step 6**: `2 >>= 1` makes `n = 1`
- **Step 7**: `1 & 1` gives `1` → `ans = "1010"`
- **Step 8**: `1 >>= 1` makes `n = 0` and the loop ends.

So, the binary representation of `10` is `"1010"`.

### 2. **Function: `checkPalindrome(unsigned int n)`**
This function checks if the binary representation of `n` is a palindrome (reads the same backward as forward).

Steps:
- Call `bin(n)` to convert `n` into its binary string format.
- **s1 = bin(n)**: This stores the binary string (in our case, `s1 = "1010"`).
- **s2 = s1**: A copy of `s1` is made into `s2`.
- **reverse(s2.begin(), s2.end())**: The binary string `s2` is reversed (`"1010"` becomes `"0101"`).
- **return s1 == s2**: It checks if the original binary string `s1` is the same as the reversed binary string `s2`. If they are the same, it means the binary representation is a palindrome; otherwise, it is not.

For `n = 10`:
- Binary representation of `10` is `"1010"`.
- Reversed binary string is `"0101"`.
- Since `"1010"` is not equal to `"0101"`, the function returns `false`, meaning the binary representation of `10` is **not** a palindrome.

### 3. **Driver Code:**
In the `main()` function:
- The first call to `checkPalindrome(x)` uses `x = (1 << 15) + (1 << 16)`. This value is not important for the example, but this is just a large number.
- The second call to `checkPalindrome(x)` uses `x = 10`. Based on our previous explanation, this call will return `false` because `10` is not a palindrome in binary.

### **Time Complexity:**
- **`bin()` function**: It iterates over each bit of the number, which takes `O(log₂(n))` time where `n` is the input number. For `n = 10`, it requires checking 4 bits, which is proportional to `log₂(10)`.
  
- **`checkPalindrome()` function**: 
  - Converting the number to a binary string takes `O(log₂(n))`.
  - Reversing the string and comparing the two strings also takes `O(log₂(n))`.
  
So, the total time complexity is **O(log₂(n))**.

### **Space Complexity:**
- **Auxiliary Space**: The space required for the binary string is proportional to the number of bits in the binary representation of `n`, which is **O(log₂(n))**. Thus, the auxiliary space complexity is **O(log₂(n))** for storing the binary string.


---


optimized code

```cpp
#include <iostream>
using namespace std;

int findReverse(int n) {
    int reverse_bin = 0;
    int temp = n;
    while (temp > 0) {
        reverse_bin = (reverse_bin << 1) | (temp & 1);
        temp >>= 1;
    }
    return reverse_bin;
}

bool isPalindrome(int n) {
    return n == findReverse(n);
}

int main() {
    int n = 10;
    cout << "Is binary representation of " << n << " a palindrome? " << (isPalindrome(n) ? "Yes" : "No") << endl;
    return 0;
}


```
Time complexity: O(log₂(n))

Space complexity: O(1)

Let's break down the example using `n = 10` to see how the code works.

### Step-by-Step Example:
1. **Binary representation of `n = 10`:**
   - The binary representation of `10` is `1010`.

2. **How `findReverse(10)` works:**
   - The goal of this function is to reverse the bits of `10` (`1010`) and return the result.

   - Initial values:  
     `reverse_bin = 0`,  
     `temp = 10` (`1010` in binary).

   - **First iteration**:
     - `temp & 1` gives the least significant bit (LSB) of `temp` 
The calculation of `1010 & 1` is a **bitwise AND** operation between the binary numbers `1010` and `0001`. 

### Step-by-step breakdown:
- **1010 (binary)** is the binary representation of `10` in decimal.
- **0001 (binary)** is the binary representation of `1` in decimal.

Now, perform the bitwise AND operation:

```
   1010  (binary for 10)
&  0001  (binary for 1)
--------
   0000  (result in binary)
```

In a bitwise AND operation, the result is `1` only if both corresponding bits are `1`; otherwise, the result is `0`.

- 1st bit: `0 & 1 = 0`
- 2nd bit: `1 & 0 = 0`
- 3rd bit: `0 & 0 = 0`
- 4th bit: `1 & 0 = 0`

### Result:
- The result of `1010 & 1` is `0000`, which is **0** in decimal.

(i.e., `1010 & 1` = `0`).
     - `reverse_bin = (reverse_bin << 1) | 0` → `reverse_bin` remains `0`.
Let's break down the calculation for the expression:

```cpp
reverse_bin = (reverse_bin << 1) | 0;
```

Assume that `reverse_bin` is currently `0` before this operation.

### Step 1: `reverse_bin << 1`
- `<<` is the **left shift** operator, which shifts the bits of `reverse_bin` to the left by 1 position.
- When you shift `0` to the left, it remains `0`, because there are no bits to shift.

So, at this point:
```
reverse_bin = 0 << 1 = 0
```

### Step 2: `0 | 0`
- `|` is the **bitwise OR** operator. In a bitwise OR operation, if either of the corresponding bits is `1`, the result is `1`. Otherwise, the result is `0`.
- `0 | 0 = 0`.

### Final Result:
The final value of `reverse_bin` after this operation remains `0`:
```
reverse_bin = 0 | 0 = 0
```

### Conclusion:
If `reverse_bin` starts as `0`, and you perform the operation `(reverse_bin << 1) | 0`, it will still be `0`. This operation does not change the value of `reverse_bin` since both shifting `0` and OR'ing it with `0` still result in `0`.


     - `temp = temp >> 1` → shifts `temp` right, making `temp = 5` (`0101` in binary).

   - **Second iteration**:
     - `temp & 1` gives `1` (`0101 & 1 = 1`).
     - `reverse_bin = (reverse_bin << 1) | 1` → shifts `reverse_bin` left and adds `1`, so `reverse_bin = 1`.
     - `temp = temp >> 1` → shifts `temp` right, making `temp = 2` (`0010` in binary).

   - **Third iteration**:
     - `temp & 1` gives `0` (`0010 & 1 = 0`).
     - `reverse_bin = (reverse_bin << 1) | 0` → shifts `reverse_bin` left, so `reverse_bin = 2` (`10` in binary).
     - `temp = temp >> 1` → shifts `temp` right, making `temp = 1` (`0001` in binary).

   - **Fourth iteration**:
     - `temp & 1` gives `1` (`0001 & 1 = 1`).
     - `reverse_bin = (reverse_bin << 1) | 1` → shifts `reverse_bin` left and adds `1`, so `reverse_bin = 5` (`101` in binary).
     - `temp = temp >> 1` → shifts `temp` right, making `temp = 0`.

   - Now that `temp = 0`, the loop terminates, and `reverse_bin = 5` (which is `0101` in binary, the reverse of `1010`).

3. **Checking palindrome:**
   - Now, the original binary number `1010` is compared with its reverse `0101` (which is `5` in decimal).
   - Since `10 != 5`, the number `10` is **not a binary palindrome**.

### Output:
```
Is binary representation of 10 a palindrome? No
```

Great question! Let's dive into why you **first shift `reverse_bin` to the left** (`reverse_bin << 1`) and then **use `temp & 1`** to extract the least significant bit (LSB).

### The Overall Goal:
You want to reverse the bits of a number. To do this, you need to build the reversed number bit by bit, starting from the least significant bit (LSB) of the original number.

### Why Shift Left (`reverse_bin << 1`)?

1. **Shifting `reverse_bin` Left**:
   - Every time we process a bit from `temp`, we want to **append** this bit to the right side of `reverse_bin`. 
   - To do that, we need to shift `reverse_bin` left to make space for the new bit on the right.
   - Initially, `reverse_bin` starts as `0`, and each time a new bit is added, we shift the current value of `reverse_bin` to the left (essentially multiplying it by 2) to make space for the new bit.

   **Example:**
   - Start: `reverse_bin = 0`
   - First, you want to add the bit from `temp`. You do this by shifting `reverse_bin` left to make space for the new bit.

   After the shift, you get:
   - `reverse_bin = 0 << 1 = 0` (nothing has changed yet).

   Now we can **add the bit from `temp`**.

### Why `temp & 1`?

2. **Extracting the LSB with `temp & 1`**:
   - `temp & 1` isolates the least significant bit (LSB) of `temp`. The expression `temp & 1` works because the binary representation of `1` is `0001`, and when we perform a bitwise AND (`&`), it will return only the LSB of `temp`. All other bits in `temp` will be "masked" (i.e., set to 0).
   
   This gives us the bit we want to append to `reverse_bin`.

   **Example:**
   - If `temp = 13` (binary `1101`), the LSB is `1`. 
     - `temp & 1 = 13 & 1 = 1`
   - If `temp = 6` (binary `0110`), the LSB is `0`.
     - `temp & 1 = 6 & 1 = 0`

### Putting It Together:

Now we have the following process:

1. **Shift `reverse_bin` left** to create space for the next bit.
2. **Extract the LSB from `temp`** using `temp & 1`.
3. **Add the LSB to `reverse_bin`** using bitwise OR (`|`), which sets the rightmost bit of `reverse_bin` to the LSB.
4. **Shift `temp` right** (`temp >>= 1`) to remove the LSB and continue processing the next bit.

### Step-by-Step Example:

Let’s take a small example where `temp = 13` (binary `1101`).

#### First iteration:
- `reverse_bin = 0`
- `temp = 13` (binary `1101`)

1. **Shift `reverse_bin` left**: `reverse_bin = 0 << 1 = 0` (no change, just makes space)
2. **Extract LSB of `temp`**: `temp & 1 = 13 & 1 = 1` (the LSB of 13 is 1)
3. **Update `reverse_bin`**: `reverse_bin = 0 | 1 = 1`
4. **Shift `temp` right**: `temp >>= 1` → `temp = 6` (binary `0110`)

#### Second iteration:
- `reverse_bin = 1` (binary `1`)
- `temp = 6` (binary `0110`)

1. **Shift `reverse_bin` left**: `reverse_bin = 1 << 1 = 2` (binary `10`, makes space for the next bit)
2. **Extract LSB of `temp`**: `temp & 1 = 6 & 1 = 0` (the LSB of 6 is 0)
3. **Update `reverse_bin`**: `reverse_bin = 2 | 0 = 2` (no change since the bit was 0)
4. **Shift `temp` right**: `temp >>= 1` → `temp = 3` (binary `0011`)

#### Third iteration:
- `reverse_bin = 2` (binary `10`)
- `temp = 3` (binary `0011`)

1. **Shift `reverse_bin` left**: `reverse_bin = 2 << 1 = 4` (binary `100`, makes space)
2. **Extract LSB of `temp`**: `temp & 1 = 3 & 1 = 1` (the LSB of 3 is 1)
3. **Update `reverse_bin`**: `reverse_bin = 4 | 1 = 5` (binary `101`)
4. **Shift `temp` right**: `temp >>= 1` → `temp = 1` (binary `0001`)

#### Fourth iteration:
- `reverse_bin = 5` (binary `101`)
- `temp = 1` (binary `0001`)

1. **Shift `reverse_bin` left**: `reverse_bin = 5 << 1 = 10` (binary `1010`, makes space)
2. **Extract LSB of `temp`**: `temp & 1 = 1 & 1 = 1` (the LSB of 1 is 1)
3. **Update `reverse_bin`**: `reverse_bin = 10 | 1 = 11` (binary `1011`)
4. **Shift `temp` right**: `temp >>= 1` → `temp = 0` (no bits left)

#### Final result:
- `reverse_bin = 11` (binary `1011`)
- This is the reversed version of `13` (binary `1101`).

### Summary:
- **Shifting `reverse_bin` left** creates space for the new bit.
- **Using `temp & 1`** extracts the LSB of `temp` so it can be added to the right side of `reverse_bin`.
- **Shifting `temp` right** removes the processed bit, so the next bit can be processed in the next iteration.

This bit-reversal process ensures that the bits of `temp` are placed into `reverse_bin` in the opposite order, effectively reversing the bits of `temp`.
