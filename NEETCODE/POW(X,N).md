
Editorial
Code
Testcase
Testcase
Test Result
50. Pow(x, n)
Solved
Medium
Topics
Companies
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


```cpp
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};
```

The code you've provided implements an efficient method to calculate the power of a number using **Exponentiation by Squaring**, which reduces the time complexity to **O(log n)** instead of the brute-force **O(n)** approach. It handles both positive and negative powers and uses bit manipulation for efficiency.

Let’s break down the code line by line and perform a dry run with an example to understand it better.

### Code Breakdown

```cpp
double myPow(double x, int n) {
```
- **Purpose**: This function calculates \( x^n \) (x raised to the power of n).
- **Parameters**:
  - `x`: The base number.
  - `n`: The exponent, which can be positive, zero, or negative.

---

```cpp
if(n < 0) {
    x = 1 / x;
}
```
- **Handle negative exponents**:
  - If `n` is negative, instead of calculating \( x^n \), we calculate \( (1/x)^{-n} \). This is based on the mathematical property:
    \[
    x^{-n} = \frac{1}{x^n}
    \]
  - Here, we invert `x` (i.e., replace it with `1/x`), and we will compute the positive power.

---

```cpp
long num = labs(n);
```
- **Convert n to positive**:
  - We use the absolute value of `n` (converted to a `long` to handle the case where `n` is the minimum integer, `-2^{31}`, which cannot be directly negated in a 32-bit integer).
  - This avoids issues with negative values in the upcoming loop.

---

```cpp
double pow = 1;
```
- **Initialize result**:
  - We initialize `pow` to 1 because any number raised to the power of 0 is 1, and we will multiply `pow` by `x` as we go.

---

```cpp
while(num) {
```
- **Main loop**:
  - This loop continues as long as `num` (which represents the absolute value of `n`) is greater than 0.
  - The idea is to repeatedly square `x` and halve `num` (the exponent), performing multiplications only when necessary.

---

```cpp
if(num & 1) {
    pow *= x;
}
```
- **Check if current bit is set (odd exponent)**:
  - This uses bit manipulation: the expression `num & 1` checks if the least significant bit of `num` is 1.
  - If it is, it means the current `num` is odd, and we multiply `pow` by `x` because an odd exponent contributes the base itself (e.g., \( x^5 = x \times x^4 \)).
  - Example:
    - For \( x^5 \), we first need to multiply by \( x \) when `num = 5` (which is odd), and then we reduce the exponent.

---

```cpp
x *= x;
```
- **Square the base**:
  - Each time we halve the exponent, we square the base. This is part of the exponentiation by squaring approach, which makes the algorithm more efficient by reducing the exponent by powers of two at each step.
  - Example:
    - To compute \( x^8 \), we compute \( x^2 \), then \( (x^2)^2 = x^4 \), and finally \( (x^4)^2 = x^8 \), halving the exponent each time.

---

```cpp
num >>= 1;
```
- **Halve the exponent**:
  - The operation `num >>= 1` shifts the bits of `num` to the right by one, effectively dividing `num` by 2.
  - Example:
    - For `num = 5`, binary is `101`. Shifting right gives `10` (which is 2), so we reduce the exponent.

---

```cpp
return pow;
```
- **Return the result**:
  - Once the loop finishes, the final value of `pow` is returned, which is the calculated value of \( x^n \).

---

### Example and Dry Run

#### Example 1: \( x = 2, n = 10 \)
- Goal: Compute \( 2^{10} \).

#### Initialization:
- `x = 2`, `n = 10`
- `num = 10` (positive, no need to invert `x`)
- `pow = 1`

#### Dry Run:

| Step  | `num`  | `x`   | `pow`   | Action |
|-------|--------|-------|---------|--------|
| Start | 10     | 2     | 1       | Check if `num & 1` (even, no action) |
| Loop  | 5      | 4     | 1       | `num` halved, `x` squared (2^2 = 4) |
| Loop  | 5      | 4     | 4       | `num` is odd (`num & 1`), multiply `pow` by 4 |
| Loop  | 2      | 16    | 4       | `num` halved, `x` squared (4^2 = 16) |
| Loop  | 1      | 256   | 4       | `num` halved, `x` squared (16^2 = 256) |
| Loop  | 1      | 256   | 1024    | `num` is odd, multiply `pow` by 256 |
| End   | 0      | -     | 1024    | Return `pow = 1024` |

- **Result**: \( 2^{10} = 1024 \)

---

#### Example 2: \( x = 2, n = -3 \)
- Goal: Compute \( 2^{-3} \).

#### Initialization:
- `x = 2`, `n = -3`
- `x = 1 / 2 = 0.5` (inverted `x`)
- `num = 3` (absolute value of `n`)
- `pow = 1`

#### Dry Run:

| Step  | `num`  | `x`   | `pow`   | Action |
|-------|--------|-------|---------|--------|
| Start | 3      | 0.5   | 1       | `num` is odd (`num & 1`), multiply `pow` by 0.5 |
| Loop  | 1      | 0.25  | 0.5     | `num` halved, `x` squared (0.5^2 = 0.25) |
| Loop  | 1      | 0.25  | 0.125   | `num` is odd, multiply `pow` by 0.25 |
| End   | 0      | -     | 0.125   | Return `pow = 0.125` |

- **Result**: \( 2^{-3} = 0.125 \)

### Time Complexity
- **Time Complexity**: O(log n)
  - The loop iterates by halving `num` on each iteration, which takes approximately `log(n)` steps.
  
This algorithm efficiently computes powers by reducing the number of operations using bit manipulation and squaring the base to handle large exponents in logarithmic time.
