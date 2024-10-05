

```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        
        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = getNextNumber(n);
            if (n == 1) {
                return true;
            }
        }
        
        return false;
    }

private:
    int getNextNumber(int n) {
        int output = 0;
        
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        
        return output;
    }
};
```

Let's break down the code **line by line** with explanations and examples. I'll also explain how each line works in the context of an example where `n = 19`.

### Code Breakdown:

```cpp
class Solution {
```
This defines a class named `Solution` which contains the method `isHappy` and a private helper method `getNextNumber`.

```cpp
public:
```
Marks the start of the **public** section. Methods under this will be accessible to users of the `Solution` class.

```cpp
    bool isHappy(int n) {
```
The function `isHappy` takes an integer `n` and returns `true` if `n` is a happy number, otherwise, it returns `false`.

- Example: Suppose `n = 19`.

```cpp
        unordered_set<int> visit;
```
This creates an empty `unordered_set` called `visit`. It stores numbers that we have already seen in the process to detect loops.

- Example: When starting with `n = 19`, `visit` is initially empty: `{}`.

```cpp
        while (visit.find(n) == visit.end()) {
```
This line starts a **while loop** that continues as long as `n` has **not** been found in `visit`. If `n` is found in `visit`, it means we are in a loop, and the function will exit the loop.

- Example: The first time, `19` is not in `visit`, so the loop runs.
  
```cpp
            visit.insert(n);
```
This line adds the current value of `n` to the `visit` set, so it can be tracked to detect if we encounter the same number again.

- Example: After this line, `19` is added to `visit`. Now, `visit = {19}`.

```cpp
            n = getNextNumber(n);
```
This updates `n` by calling the helper function `getNextNumber(n)`, which calculates the sum of the squares of the digits of `n`.

- Example: For `n = 19`, `getNextNumber(19)` will compute `1² + 9² = 1 + 81 = 82`. So `n` becomes `82`.

```cpp
            if (n == 1) {
                return true;
            }
```
This checks if `n` has become `1`. If it does, the function returns `true`, meaning the number is happy.

- Example: After computing the sum of squares for `19`, `n = 82`. So this condition is not true yet, and the loop continues.

```cpp
        }
        
        return false;
```
If the loop exits (because `n` has been found in `visit`), this means there is a cycle and the number is not happy. In this case, the function returns `false`.

- Example: If `n` had formed a loop (e.g., repeating the same numbers without reaching 1), this line would be executed, returning `false`.

### Private Method Breakdown:

```cpp
private:
    int getNextNumber(int n) {
```
This defines a helper function `getNextNumber` which computes the sum of the squares of the digits of `n`.

- Example: For `n = 19`, this function will calculate `1² + 9² = 1 + 81 = 82`.

```cpp
        int output = 0;
```
This initializes an integer `output` to 0. This will store the sum of the squares of the digits.

- Example: Initially, `output = 0`.

```cpp
        while (n > 0) {
```
This loop runs as long as `n > 0`. The loop extracts each digit from the number `n` one by one.

- Example: For `n = 19`, the loop runs twice, once for each digit (`9` and `1`).

```cpp
            int digit = n % 10;
```
This extracts the last digit of `n` using the modulus operator `%`. `n % 10` gives the remainder when dividing `n` by 10.

- Example: For `n = 19`, `digit = 9` in the first iteration, and in the second iteration, `digit = 1`.

```cpp
            output += digit * digit;
```
This squares the extracted digit and adds it to `output`.

- Example: For `digit = 9`, `output` becomes `9² = 81`. In the next iteration, `digit = 1`, and `output` becomes `81 + 1² = 81 + 1 = 82`.

```cpp
            n = n / 10;
```
This removes the last digit from `n` by dividing it by 10.

- Example: Initially, `n = 19`. After dividing by 10, `n = 1` (integer division). After the second iteration, `n = 0`, so the loop stops.

```cpp
        }
        
        return output;
```
When the loop finishes, this returns the sum of the squares of the digits stored in `output`.

- Example: The function returns `82` for the input `19`.

### Example Execution Walkthrough (n = 19):

1. Start with `n = 19`.
   - `visit = {}` (empty set).
   - `visit.find(19) == visit.end()` is true, so we enter the loop.
   - Add `19` to `visit`: `visit = {19}`.
   - Call `getNextNumber(19)`:
     - `digit = 9`, square of 9 is `81`.
     - `digit = 1`, square of 1 is `1`.
     - Sum of squares: `81 + 1 = 82`.
   - `n = 82`, continue the loop.

2. Now `n = 82`.
   - `visit.find(82) == visit.end()` is true.
   - Add `82` to `visit`: `visit = {19, 82}`.
   - Call `getNextNumber(82)`:
     - `digit = 2`, square of 2 is `4`.
     - `digit = 8`, square of 8 is `64`.
     - Sum of squares: `4 + 64 = 68`.
   - `n = 68`, continue the loop.

3. Now `n = 68`.
   - `visit.find(68) == visit.end()` is true.
   - Add `68` to `visit`: `visit = {19, 82, 68}`.
   - Call `getNextNumber(68)`:
     - `digit = 8`, square of 8 is `64`.
     - `digit = 6`, square of 6 is `36`.
     - Sum of squares: `64 + 36 = 100`.
   - `n = 100`, continue the loop.

4. Now `n = 100`.
   - `visit.find(100) == visit.end()` is true.
   - Add `100` to `visit`: `visit = {19, 82, 68, 100}`.
   - Call `getNextNumber(100)`:
     - `digit = 0`, square of 0 is `0`.
     - `digit = 0`, square of 0 is `0`.
     - `digit = 1`, square of 1 is `1`.
     - Sum of squares: `1`.
   - `n = 1`, return `true` since `n == 1`.

### Conclusion:

The code determines whether a number is a happy number by repeatedly transforming it into the sum of the squares of its digits. If the number eventually becomes `1`, it is a happy number. If it enters a loop, it is not happy.
