Count numbers from 1 to n that have 4 as a digit
Last Updated : 20 Feb, 2023
Given a number n, find count of all numbers from 1 to n that have 4 as a digit.

Examples : 

Input:   n = 5
Output:  1
Only 4 has '4' as digit

Input:   n = 50
Output:  14

Input:   n = 328
Output:  60
This problem is mainly a variation of previous article on Compute sum of digits in all numbers from 1 to n.

Naive Solution: A naive solution is to go through every number x from 1 to n, and check if x has 4. To check if x has or not, we can traverse all digits of x. Below is the implementation of above idea:
 ```cpp

class Solution {
  public:
  int solve(int p)
        {
            while(p!=0)
            {
                if(p%10 ==4)
                {
                    return 1;
                } p =p/10;
            }return 0;
        }
    int countNumberswith4(int n) {
        // code here
        int cnt =0;
        if(n<4) return 0;
        if (n ==4) return 1;
        int j =4;
        while(j<=n)
        {
            cnt += solve(j);
            j+=1;
        }return cnt;
        
    }
};

```
