Example 1:

Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime
factors of 100.
Example 2:

Input: N = 35
Output: 5 7
Explanation: 5 and 7 are the unique prime
factors of 35.

```cpp
class Solution{
    
    bool isPrime(int n){
        if(n<=1) return false;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
        
    }
    public:
    vector<int>AllPrimeFactors(int n)
    {
      vector<int>result;
       for(int i=1;i<=n;i++)
       {
           if(n%i==0 && isPrime(i)==true)
           {
            result.push_back(i);
            
           }
       }
       return result;
    }
};
```

Let's go through a dry run of the code step by step using the input `n = 28`.

### Code Breakdown:
```cpp
class Solution{
    
    bool isPrime(int n){        // Step 1: Helper function to check if a number is prime.
        if(n<=1) return false;  // Step 2: If n is less than or equal to 1, return false.

        for(int i=2;i*i<=n;i++){ // Step 3: Loop to check if n has any divisors between 2 and sqrt(n).
            if(n%i==0){          // Step 4: If n is divisible by i, it's not prime.
                return false;
            }
        }
        return true;             // Step 5: If no divisors found, return true (n is prime).
    }

    public:
    vector<int>AllPrimeFactors(int n)  // Step 6: Function to find all prime factors of n.
    {
        vector<int>result;         // Step 7: Initialize an empty vector to store the result.
        for(int i=1;i<=n;i++)      // Step 8: Loop from 1 to n to check all divisors of n.
        {
            if(n%i==0 && isPrime(i))  // Step 9: Check if i is a divisor of n and if i is prime.
            {
                result.push_back(i);  // Step 10: If both conditions are true, add i to the result.
            }
        }
        return result;             // Step 11: Return the result vector containing all prime factors.
    }
};
```

### Dry Run for `n = 28`:

#### Step-by-Step Execution:

- **Initial State**:
  - Input: `n = 28`
  - Result: `[]` (empty vector)
  
---

#### First Loop Iteration (`i = 1`):
- `if (28 % 1 == 0)` → True (1 is a divisor of 28).
- `isPrime(1)` → Since `1 <= 1`, return `false`.
- `1` is not added to the result.

---

#### Second Loop Iteration (`i = 2`):
- `if (28 % 2 == 0)` → True (2 is a divisor of 28).
- `isPrime(2)`:
  - Loop from `i = 2` to `sqrt(2)`. Since `2` has no divisors other than 1 and itself, return `true`.
- `2` is added to the result.
  - Result: `[2]`.

---

#### Third Loop Iteration (`i = 3`):
- `if (28 % 3 == 0)` → False (3 is not a divisor of 28).
- Continue to the next iteration.

---

#### Fourth Loop Iteration (`i = 4`):
- `if (28 % 4 == 0)` → True (4 is a divisor of 28).
- `isPrime(4)`:
  - Loop from `i = 2` to `sqrt(4)`. Since `4 % 2 == 0`, return `false`.
- `4` is not added to the result.

---

#### Fifth Loop Iteration (`i = 5`):
- `if (28 % 5 == 0)` → False (5 is not a divisor of 28).
- Continue to the next iteration.

---

#### Sixth Loop Iteration (`i = 6`):
- `if (28 % 6 == 0)` → False (6 is not a divisor of 28).
- Continue to the next iteration.

---

#### Seventh Loop Iteration (`i = 7`):
- `if (28 % 7 == 0)` → True (7 is a divisor of 28).
- `isPrime(7)`:
  - Loop from `i = 2` to `sqrt(7)`. Since `7` has no divisors other than 1 and itself, return `true`.
- `7` is added to the result.
  - Result: `[2, 7]`.

---

#### Remaining Loop Iterations (`i = 8` to `28`):
- The loop continues, but no further prime divisors are found. Any divisors (like 14, 28) are not prime.

---

### Final Output:
- The prime factors of 28 are `[2, 7]`.

### Time Complexity:
- The outer loop runs `O(n)` times.
- The `isPrime` function runs in `O(sqrt(n))` for each divisor check.
- So, the overall time complexity is approximately **O(n * sqrt(n))**.

### Space Complexity:
- The space complexity is **O(k)**, where `k` is the number of prime factors stored in the result vector.
