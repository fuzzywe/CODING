

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

Solution 2 - two pointers
Solution 2 is based on almost the same idea as Solution 1. How can we quickly find the number 1?

My answer is to use two pointers.

Input: n = 19
1 
2
  + 9 
2
  = 82
8 
2
  + 2 
2
  = 68
6 
2
  + 8 
2
  = 100
1 
2
  + 0 
2
  + 0 
2
  = 1

Let's say we have a slow pointer and a fast pointer.

slow pointer move once.
fast pointer move twice.

If input is 19, we will have

19 → 82 → 68 → 100 → 1 
Let's move the two pointers. Every time slow move once and fast move twice. We stop if both pointers are the same number.


19 → 82 → 68 → 100 → 1 
sf
--------------------------
slow calculated 19.
fast calculated 19 and 82.

19 → 82 → 68 → 100 → 1 
     s    f
--------------------------
slow calculated 82.
fast calculated 68 and 100.

19 → 82 → 68 → 100 → 1 
          s          f
--------------------------
slow calculated 68.
fast calculated 1 and 1. (= 1 produces 1)

19 → 82 → 68 → 100 → 1 → 1 → 1 
                s            f
  
--------------------------
slow calculated 100.
fast calculated 1 and 1. (= 1 produces 1)

19 → 82 → 68 → 100 → 1 → 1 → 1 → 1 → 1 
                     s               f

Now slow and fast pointer are both 1, that means 19 is a happy number.

Moreover, if fast pointer is 1, we can immediately return True because 1 produces 1. We know that in the end slow pointer will become 1 at some point, because slow pointer will touch each number one by one.

But why do you use two pointers?
In solution 1, I use set to prevent revisiting the same number. In other word, I try to prevent an infinity looping. I'm trying to achieve the same thing using two pointers.

To prove that, let's see false case.

20 → 4 →　16 → 37 → 58 → 89 → 145 → 42 → (20...)
sf
------------------------------
slow calculated 20.
fast calculated 20 and 4.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
     s   f 
------------------------------
slow calculated 4.
fast calculated 16 and 37.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
         s          f 
------------------------------
slow calculated 16.
fast calculated 58 and 89.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
              s               f 
------------------------------
slow calculated 37.
fast calculated 145 and 42.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
f                   s               
------------------------------
slow calculated 58.
fast calculated 20 and 4.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
         f              s               
------------------------------
slow calculated 89.
fast calculated 16 and 37.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
                   f          s               
------------------------------
slow calculated 145.
fast calculated 58 and 89.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
                              f    s               
------------------------------
slow calculated 42.
fast calculated 145 and 42.

20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → (20...)
fs               

The fast pointer touched all numbers and we didn't find 1.

Now the slow pointer and the fast pointer are both 20, that means the fast pointer has calculated all the numbers and looped back around because the fast pointer caught up with the slow pointer from behind. That's why we can return false.

Easy!😄
Let's see solution codes!

Complexity
Time complexity: O(logn)

Space complexity: O(1)



```cpp

class Solution {
public:
    bool isHappy(int n) {
        int slow = getNextNumber(n);
        int fast = getNextNumber(getNextNumber(n));

        while (slow != fast) {
            if (fast == 1) return true;
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }

        return slow == 1;
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

Let's break down the code step by step, with examples to explain how each part works.

### Class Definition
```cpp
class Solution {
```
- **Explanation:** This declares a class named `Solution`. In C++, classes group together related data and functions (methods).

---

### Method Declaration: `isHappy(int n)`
```cpp
public:
    bool isHappy(int n) {
```
- **Explanation:** This declares a public method `isHappy` which returns a boolean (`true` or `false`). It takes an integer `n` as input and checks whether `n` is a happy number.

---

### Step 1: Initialize `slow` and `fast` pointers
```cpp
int slow = getNextNumber(n);
int fast = getNextNumber(getNextNumber(n));
```
- **Explanation:** Two variables, `slow` and `fast`, are initialized to keep track of the numbers generated by repeatedly applying the `getNextNumber` function.
    - `slow` is initialized to the result of `getNextNumber(n)` (next number for `n`).
    - `fast` is initialized to `getNextNumber(getNextNumber(n))`, which is the next number for the next number of `n`.

- **Example:**
    - If `n = 19`, `slow = getNextNumber(19)` and `fast = getNextNumber(getNextNumber(19))`.
    - `getNextNumber(19)` computes: \(1^2 + 9^2 = 1 + 81 = 82\), so `slow = 82`.
    - `getNextNumber(82)` computes: \(8^2 + 2^2 = 64 + 4 = 68\), so `fast = getNextNumber(82) = 68`.
    - Then, `fast = getNextNumber(68)` computes \(6^2 + 8^2 = 36 + 64 = 100\).

---

### Step 2: While loop to detect cycles or happiness
```cpp
while (slow != fast) {
    if (fast == 1) return true;
    slow = getNextNumber(slow);
    fast = getNextNumber(getNextNumber(fast));
}
```
- **Explanation:**
    - The loop continues while `slow` and `fast` are different. The idea is to detect a cycle (when `slow == fast`) or find a happy number (when `fast == 1`).
    - If `fast` becomes `1`, the method returns `true`, indicating that `n` is a happy number.
    - Otherwise, the loop updates `slow` and `fast`. `slow` moves one step at a time, while `fast` moves two steps, simulating a fast/slow pointer approach used in cycle detection (Floyd's Cycle Detection Algorithm).

- **Example:** Continuing from the previous values:
    - In the next iteration, `slow = 68`, and `fast = 100`.
    - `getNextNumber(68)` gives 100 for `slow`, and `getNextNumber(100)` gives 1 for `fast`.
    - Since `fast == 1`, the method returns `true` and exits.

---

### Step 3: Return result if no early termination
```cpp
return slow == 1;
```
- **Explanation:** If the loop exits (when `slow == fast`), it checks whether `slow` is 1. If `slow == 1`, the number is a happy number, and the method returns `true`. Otherwise, it returns `false`.

---

### Private Method: `getNextNumber(int n)`
```cpp
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
```
- **Explanation:** This method calculates the next number in the process of checking for happiness. It computes the sum of the squares of the digits of `n`.
    - `output = 0`: Initializes the result to 0.
    - `while (n > 0)`: Loops until there are no digits left in `n`.
    - `int digit = n % 10`: Extracts the last digit of `n` using the modulus operator.
    - `output += digit * digit`: Adds the square of the extracted digit to `output`.
    - `n = n / 10`: Removes the last digit of `n` by dividing `n` by 10.
    - Returns the final `output`, which is the sum of squares of the digits of `n`.

- **Example:** 
    - For `n = 19`:
        - `digit = 9`, `output = 0 + 9^2 = 81`.
        - `n = 1`, `digit = 1`, `output = 81 + 1^2 = 82`.
        - Finally, it returns `82`.

### Summary of Example (n = 19):
- The first few transformations are: 19 → 82 → 68 → 100 → 1.
- Since the sequence reaches 1, 19 is a happy number, and the function returns `true`.
