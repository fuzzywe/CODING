
Bit Difference
Difficulty: BasicAccuracy: 75.23%Submissions: 101K+Points: 1
You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.
Example 2:

Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need 
to be flipped are 10100. If we flip 
these bits, we get 11001, which is B.


https://www.geeksforgeeks.org/problems/bit-difference-1587115620/1

---
THis is the best solution


```cpp
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int count =0;
        int ans;
     ans=a^b;
     for ( int i=0;i<31;i++)
     {
         if ( ans&(1<<i))
            count+=1;
     }
    return count; 
        
    }
};

```
---

Alternate Approach:
Intuition:
By using xor and __builtin_popcount function.

Implementation
Take the xor of a and b which gives only different bits as a set bit.
Now call the function __builtin_popcount to count the number of set bit.
Return the count of setBit.
 

```cpp
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        // Your logic here
        return __builtin_popcount(a^b);
    }
};
 ```

Complexity
Time Complexity: O(1), __builtin_popcount function and xor both takes O(1) time.
Auxiliary Space: O(1), We are not using any extra space.
