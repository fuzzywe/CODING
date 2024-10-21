https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

Examples :

Input: n = 4
Output: 5
Explanation: For numbers from 1 to 4. For 1: 0 0 1 = 1 set bits For 2: 0 1 0 = 1 set bits For 3: 0 1 1 = 2 set bits For 4: 1 0 0 = 1 set bits Therefore, the total set bits is 5.
Input: n = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

---
OPTIMAL

```cpp
//Back-end complete function Template for C++

class Solution{
    public:
    //Function to return sum of count of set bits in the integers from 1 to n. 
    int countSetBits(int n)
    {
        //Ignoring 0 as all the bits are unset. 
        n++;
        int count=0;
        
        //Counting set bits from 1 to n.
        for( int x=2 ; x/2<n ; x=x*2 )
        {
            //Total count of pairs of 0s and 1s.
            int quotient = n/x;
            //quotient gives the complete count of pairs of 1s.
            //Multiplying it with the (current power of 2)/2 will 
            //give the count of 1s in the current bit.
            count += quotient * x / 2;
            
            int remainder = n%x;
            //If the count of pairs is odd then we add the remaining 1s 
            //which could not be grouped together. 
            if(remainder > x/2)
                count += remainder - x/2;
        }
        
        //returning count of set bits.
        return count;
    }
};

```
---

```cpp
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            int x=i;
            while(x){
                if((x&1)==1) cnt++;
                x /= 2;
            }
        }
        return cnt;
    }
};

```


Runtime Error 
Ask Yogi Bot
Test Cases Passed: 
10 /1115
Time limit exceeded.

Your program took more time than expected.Expected Time Limit : 1.01sec
Hint : Please optimize your code and submit again.
