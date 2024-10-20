204. Count Primes
Medium
Topics
Companies
Hint
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0

**Sieve of Eratosthenes algorithm**


Intuition
Approach
1.Initialize a boolean vector prime of size n, where prime[i] represents whether i is a prime number.
2.Set prime[0] and prime[1] to false since they are not prime.
3.Iterate from 2 to sqrt(n) (inclusive). For each i, if prime[i] is true, mark all multiples of i (greater than i*i) as false.
4.Finally, count the number of true values in the prime vector.
```cpp
Code
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; 
        // Sieve Of Eratosthenes Method
        int cnt = 0;
        std::vector<bool> prime(n, true); 
        prime[0] = prime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        for (int i = 2; i < n; i++) {
            if (prime[i]) cnt++;
        }
        
        return cnt;
    }
};

```
