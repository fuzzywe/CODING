All divisors of a Number
Difficulty: EasyAccuracy: 46.73%Submissions: 37K+Points: 2
Given an integer N, print all the divisors of N in the ascending order.
 

Example 1:

Input : 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely 
divisible by 1, 2, 4, 5, 10 and 20.

Example 2:

Input: 21191
Output: 1 21191
Explanation: As 21191 is a prime number,
it has only 2 factors(1 and the number itself).

```cpp

class Solution {
public:
    void print_divisors(int n) {
        vector<int> res;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0)
                res.push_back(i);
        }
        for (auto r : res) {
            cout << r << " ";
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            int r = res[i];
            if (r != (n / r))
                cout << n / r << " ";
        }
    }
};

```
