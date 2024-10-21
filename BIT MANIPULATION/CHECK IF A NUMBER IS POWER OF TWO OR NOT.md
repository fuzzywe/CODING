231. Power of Two
     
https://leetcode.com/problems/power-of-two/description/

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false

---

Approach 1(Power function) - O(1)
Approach 2(Dividing by 2) - O(logn)
Approach 3(left shift) - O(logn)
Approach 4(Ceil and Floor) - O(1)
Approach 5(And operator) - O(1)
Approach 6(Counting 1's) - O(logn)
Approach 7(Modulo with n) - O(1)
Approach 8(Recursion) - O(logn)

Approaches
(Also explained in the code)

**Approach 1(Using Power Function)**
Generating all possible numbers in the range.
Using pow() function for calculating power of 2.
If n is equal to ans, return true else will return false after the loop end.
Complexity
Time complexity:
O(logn)

Space complexity:
O(1)

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        
        for(int i =0;i<31;i++){
        int ans = pow(2,i);
            
            if(ans == n)return true;

        }
        return false;
    }
};
```
**Approach 2(Dividing n by 2)**

If n is divisible by 2 , every time we will encounter 1 at the end.
And at any point if n isn't divisible by 2 we will return false.
Complexity
Time complexity:
O(logn)

Space complexity:
O(1)
---

```cpp
Code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        
        while(n>0){
            if(n==1)return true;
            if(n %2 !=0)break;
            n /=2;
        }
        return false;
    }
};
```
---

**Approach 3(Left Shift)**

If n is 0 or less will never enter the loop and will return false.

taking x = 1.

example : let n = 8
which be represented as 1000
now we will left left shift x until it get equals to n or exceed it.

1st left shift: x<<1 => 10
2nd left shift: x<<1 => 100
3rd left shift: x<<1 => 1000

now n is equal to x (1000 = 1000) which implies it is divisible by 2 because numbers divisible by 2 will only have a single 1 in their binary representation.

Complexity
Time complexity:
O(logn)

Space complexity:
O(1)
---
```cpp
Code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x =1;
        while(x<=n){
            if(x==n)return true;
            if(x > INT_MAX /2)break;
            x = x<<1;
        }
        return false;
    }
};
```
---

**Approach 4(Ceil and floor)**

Ceil() = rounds up to the nearest integer.
floot() = rounds down to the nearest integer.

example 1 :
ceil(log2(5)) = 2
floor(log2(5)) = 3

example 2 :
ceil(log2(8)) = 3
floor(log2(8)) = 3

Incase of number multiple of 2 ceil and floor will always be equal.

Complexity
Time complexity:
O(1)

Space complexity:
O(1)

---

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;

        return floor(log2(n)) == ceil(log2(n)) ? true : false;
    }
};
```
---

**Approach 5(And Operator)**

And operation between multiple of 2 and next lower number will always give 0 and other wise it will never be 0.

example 1: 8 & 7
1000(8) & 0111(7) => 0000(0)

example 1: = 10 & 9
1010(10) & 1001(9) => 1000(8)

Complexity
Time complexity:
O(1)

Space complexity:
O(1)

---

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        return  (n>0 && (n & (n-1))==0) ? true:false;
    }
};
```
---

**Approach 6(Counting 1's)**

As we know multuple of 2 will only have a single 1 in their binary representation.
So counting it with the help of built-in function.
Complexity
Time complexity:
O(logn)

Space complexity:
O(1)


---

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int cnt = __builtin_popcount(n);
        return  (cnt==1) ? true:false;
    }
};
```
---

**Approach 7(Modulo with n)**

multiple of 2 will always divide 2^30.
example :
16 % 8 = 0
36 % 2 = 0
Complexity
Time complexity:
O(1)

Space complexity:
O(1)

---

```cpp
Code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return ((1<<30) % n == 0)? true:false;
    }
};
```
---

**Approach 8(Recursion)**

Recursively divide n by 2, if we reach 1 then it means it is multiple of 2 and will return true else it will be false.
Complexity
Time complexity:
O(logn)

Space complexity:
O(logn)
---

```cpp
Code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        return (n%2 ==0 && isPowerOfTwo(n/2));
    }
};

```

---

There are several one line solutions for this task - may be interesting!

8


✅Correction :- pow function in c++ have O( log n ) time complexity instead of O(1).



In the ceil() and floor() solution, instead of n == 0 it should be n <= 0


Feb 20, 2024
Why are we not considering any negative integers here? Since constraint is for 2^-31<=n<=2^31-1






3
Reply

user8453v
Feb 20, 2024
Approach 3(left shift) , it should also have complexity of O(1) , since only max 31 shifts are required .
