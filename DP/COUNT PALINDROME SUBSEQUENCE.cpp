Brute Force Approach:
Intuition
The idea is to divide the problem into smaller subproblems, and using them to calculate the answer for original problem.

Implementation
Let func(i,j) be the count of palindromic subsequences in string Str[i..j] (substring of string Str from index i to j, both inclusive),
then this function can be defined as:

if i == j :
  return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j]) :
  return   func(i+1, j) + func(i, j-1) + 1

Else :
  // check for rest sub-sequence and  remove common
  // palindromic subsequences as they are counted
  // twice when we do func(i+1, j) + func(i,j-1)
  return func(i+1, j) + func(i, j-1) - func(i+1, j-1).

Complexity
Time Complexity: O(3^(n*n)), it is exponential increasing which can see using recursion tree, it is not a tight bound.
Auxiliary Space: O(n), as max number of stack frames in recursion tree of it will have n frames.


class Solution{
    public:
    const long long int mod = 1000000007;
    long long int add(long long int x, long long int y) {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int func(int i, int j, string &str){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        else if(str[i]==str[j]){
            return add(add(func(i+1, j, str), func(i, j-1, str)), 1);
        }
        else
            return add(func(i+1, j, str), sub(func(i, j-1, str), func(i+1, j-1, str)));
    }
    long long int  countPS(string str){
       int n=str.size();
       return func(0, n-1, str);
    }
};


Let's walk through this C++ code step by step and break down its logic, particularly for solving the problem of counting palindromic subsequences in a string.

### Code Structure Overview:

- The code defines a class `Solution` that contains a set of functions for performing operations on a string:
  - **`add`**: Safely adds two numbers under modulo `1000000007`.
  - **`sub`**: Safely subtracts two numbers under modulo `1000000007`.
  - **`func`**: A recursive function that computes the number of palindromic subsequences between indices `i` and `j` in a string `str`.
  - **`countPS`**: The main function that returns the count of all palindromic subsequences in the string.

### Detailed Dry Run:

1. **Constants and Modulo Arithmetic:**
   ```cpp
   const long long int mod = 1000000007;
   ```
   - We define a constant `mod` with a large prime value `1000000007` (a standard mod value in many competitive programming problems) to avoid integer overflow and handle large numbers.

2. **Addition with Modulo:**
   ```cpp
   long long int add(long long int x, long long int y) {
       return ((x % mod) + (y % mod)) % mod;
   }
   ```
   - This function takes two values `x` and `y`, applies modulo to both of them, and then adds them together, taking the modulo of the result. It ensures the sum always remains within the range of `mod`.

3. **Subtraction with Modulo:**
   ```cpp
   long long int sub(long long int x, long long int y) {
       return ((x % mod) - (y % mod) + mod) % mod;
   }
   ```
   - Similar to the `add` function, this performs subtraction under modulo. We ensure the result is always positive by adding `mod` after the subtraction (in case the result of subtraction becomes negative).

4. **Recursive Function `func` to Count Palindromic Subsequences:**
   ```cpp
   long long int func(int i, int j, string &str) {
       if (i > j) {
           return 0;
       }
       if (i == j) {
           return 1;
       }
       else if (str[i] == str[j]) {
           return add(add(func(i + 1, j, str), func(i, j - 1, str)), 1);
       }
       else {
           return add(func(i + 1, j, str), sub(func(i, j - 1, str), func(i + 1, j - 1, str)));
       }
   }
   ```
   - **Base Case 1 (`i > j`)**: 
     - If the starting index `i` is greater than the ending index `j`, this means we've gone beyond the bounds, so no palindromic subsequences exist. The function returns `0`.
   - **Base Case 2 (`i == j`)**: 
     - If `i` is equal to `j`, it means we are looking at a single character, which is always a palindrome itself. The function returns `1`.
   - **Case 3 (`str[i] == str[j]`)**: 
     - If the characters at positions `i` and `j` are equal, we have found a new palindromic subsequence, which is at least the subsequence `str[i] + subsequences_between(i+1, j-1) + str[j]`. So, we recursively compute:
       1. The subsequences from `i + 1` to `j`.
       2. The subsequences from `i` to `j - 1`.
       3. We add `1` to count the palindrome formed by `str[i]` and `str[j]`.
       - The total is computed as:
         ```cpp
         add(add(func(i + 1, j, str), func(i, j - 1, str)), 1)
         ```
   - **Case 4 (`str[i] != str[j]`)**: 
     - If `str[i]` and `str[j]` are not equal, we don't have a new palindrome involving both. Instead, we need to compute:
       1. The subsequences from `i + 1` to `j`.
       2. The subsequences from `i` to `j - 1`.
       3. Subtract the overlapping part (`i + 1` to `j - 1`), which is double-counted.
       - The total is computed as:
         ```cpp
         add(func(i + 1, j, str), sub(func(i, j - 1, str), func(i + 1, j - 1, str)))
         ```

5. **Main Function to Count All Palindromic Subsequences:**
   ```cpp
   long long int countPS(string str) {
       int n = str.size();
       return func(0, n - 1, str);
   }
   ```
   - This function simply calls the recursive function `func(0, n - 1, str)`, passing the entire string (`n = str.size()`) and asking it to compute the number of palindromic subsequences between indices `0` and `n-1`.

---

### Dry Run with an Example:

Let’s take an example to see how the function works.

#### Example: 
```cpp
str = "aba"
```

- Call `countPS("aba")`:
  - This calls `func(0, 2, "aba")`.

1. `func(0, 2, "aba")`:
   - `str[0] == str[2]`, so we compute:
     ```cpp
     add(add(func(1, 2, "aba"), func(0, 1, "aba")), 1)
     ```

2. `func(1, 2, "aba")`:
   - `str[1] != str[2]`, so we compute:
     ```cpp
     add(func(2, 2, "aba"), sub(func(1, 1, "aba"), func(2, 1, "aba")))
     ```

3. `func(2, 2, "aba")`:
   - Base case: `i == j`, so return `1` (since "a" is a palindrome).
   
4. `func(1, 1, "aba")`:
   - Base case: `i == j`, so return `1` (since "b" is a palindrome).

5. `func(2, 1, "aba")`:
   - Base case: `i > j`, so return `0`.

- Now compute `func(1, 2, "aba")`:
   ```cpp
   add(1, sub(1, 0)) = add(1, 1) = 2
   ```

6. `func(0, 1, "aba")`:
   - `str[0] != str[1]`, so we compute:
     ```cpp
     add(func(1, 1, "aba"), sub(func(0, 0, "aba"), func(1, 0, "aba")))
     ```

7. `func(1, 1, "aba")`:
   - Base case: return `1`.

8. `func(0, 0, "aba")`:
   - Base case: return `1`.

9. `func(1, 0, "aba")`:
   - Base case: return `0`.

- Now compute `func(0, 1, "aba")`:
   ```cpp
   add(1, sub(1, 0)) = add(1, 1) = 2
   ```

- Now compute `func(0, 2, "aba")`:
   ```cpp
   add(add(2, 2), 1) = add(4, 1) = 5
   ```

### Result:

The total number of palindromic subsequences in `"aba"` is `5`. These are: `"a"`, `"b"`, `"a"`, `"aba"`, and `"aa"`.

### Time Complexity:
- The time complexity of the recursive approach is quite large (exponential), and it can be improved with dynamic programming or memoization. But for this direct recursive method, the worst-case complexity is exponential due to overlapping subproblems.


  
 

Expected Approach:
Intuition
The idea is to use dynamic programming as above recursive solution is having overlapping subproblems.

Implementation
Implementation is same as that of brute force approach, but we will keep a 2D vector cps of size (n+1)*(n+1) to store result of each state(i, j) so that we do not have to calculate the same state again. We can do it iteratively also.

Let us understand it with the help of an example:
Input: str = "abca"

cps dp table:         a     b     c     a
                         a    1     2     3     7 
                         b    0     1     2     3 
                         c     0     0     1     2 
                         a     0     0     0     1 
Here cps[i][j] stores number of subsequence of strings str from index i to j (str[i]...str[j]), which are palindrome.
For all i>j, cps[i][j] will be 0 as such string is not possible.
For i==j, cps[i][j]=1 as a single character forms a palindrome.
For rest pairs of (i,j), cps[i][j] is equal to:
                                case1) cps[i+1][j] + cps[i][j-1] + 1, when str[i]==str[j] as (adding 1 as subsequence having characters str[i] and str[j] forms a palindromic subsequence).
                                            Here we can see, cps[0][3] = (cps[1][3]+cps[0][2]+1) = (3+3+1) = 7.
                                            func("abca") = func("bca") + func("abc") + 1.
                                case2)  cps[i+1][j] + cps[i][j-1] - cps[i+1][j-1], when str[i] not equals str[j].
                                            Here we can see, cps[0][2] = (cps[1][2]+cps[0][1]-cps[1][1]) = (2+2-1) = 3.
                                            func("abc") = func("bc") + func("ab") - func("b").
                                Here func(string str) -> returns count of palindromic subsequence of string str.
Return  cps[0][3] = 7 as answer.
 

Complexity
Time Complexity: O(n*n), as there are at n*n states and for calculating each state we need at max of 3 operations.
Auxiliary Space: O(n*n), as we are using 2D vector cps of size n*n.


class Solution {
public:
    const long long int mod = 1000000007;
    long long int add(long long int x, long long int y) {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int  countPS(string str)
    {
        long long int  N = str.length();

        // create a 2D array to store the count of palindromic
        // subsequence
        long long int  cps[N + 1][N + 1];
        memset(cps, 0 , sizeof(cps));

        // palindromic subsequence of length 1
        for (long long int  i = 0; i < N; i++)
            cps[i][i] = 1;

        // check subsequence of length L is palindrome or not
        for (long long int  L = 2; L <= N; L++)
        {
            for (long long int  i = 0; i <= N - L; i++)
            {
                long long int  k = L + i - 1;
                if (str[i] == str[k])
                    cps[i][k] = add(cps[i][k - 1] , add(cps[i + 1][k] , 1LL)) % mod;
                else
                    cps[i][k] = add(cps[i][k - 1] , sub(cps[i + 1][k] , cps[i + 1][k - 1])) % mod;
            }
        }

        // return total palindromic subsequence
        return cps[0][N - 1] % mod;
    }
}
