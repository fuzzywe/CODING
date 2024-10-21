https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

Given a number n and a bit number k, check if the kth index bit of n is set or not. A bit is called set if it is 1. The position of set bit '1' should be indexed starting with 0 from the LSB side in the binary representation of the number.
Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

Examples : 

Input: n = 4, k = 0
Output: No
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Input: n = 4, k = 2
Output: Yes
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
Input: n = 500, k = 3
Output: No
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.



```cpp

#include <bits/stdc++.h>
using namespace std;

Time Complexity: O(1)
Auxiliary Space: O(1)


class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Your code here
        // It can be a one liner logic!! Think of it!!
         if((n>>k)&1 == 1){
            return true;
        }
        else{
            return false;
        }
    }
};

```
Check whether the K-th bit is set or not Using Left Shift Operator:
To solve the problem follow the below idea:


Left shift given number 1 by k to create a number that has only set bit as k-th bit.
temp = 1 << k
If bitwise AND of n and temp is non-zero, then result is SET else result is NOT SET.

Below is the implementation of the above approach:


```cpp

// CPP program to check if k-th bit
// of a given number is set or not
#include <bits/stdc++.h>
using namespace std;
 
void isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        cout << "SET";
    else
        cout << "NOT SET";
}
 
// Driver code
int main()
{
    int n = 5, k = 1;
 
    // Function call
    isKthBitSet(n, k);
    return 0;
}

```
