Odd or Even
Difficulty: BasicAccuracy: 60.6%Submissions: 105K+Points: 1
Given a positive integer n, determine whether it is odd or even. Return a string "even" if the number is even and "odd" if the number is odd.

Examples:

Input: n = 15
Output: odd
Explanation: The number is not divisible by 2
Input: n = 44
Output: even
Explanation: The number is divisible by 2
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

---

```cpp
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string oddEven(int n) {
        // code here
        int num = n&1;
        if(num==1) return "odd";
        return "even";
    }
};

```
---
One simple solution is to find the remainder after dividing by 2. 

Method 1:





  ```cpp
#include <iostream> 
using namespace std; 
  
// Returns true if n is 
// even, else odd 
bool isEven(int n) { return (n % 2 == 0); } 
  
// Driver code 
int main() 
{ 
    int n = 101; 
    isEven(n) ? cout << "Even" : cout << "Odd"; 
  
    return 0; 
}

```
Output
Odd
Time Complexity: O(1)
Auxiliary Space: O(1)

Method 2 :

A better solution is to use bitwise operators. We need to check whether the last bit is 1 or not. If the last bit is 1 then the number is odd, otherwise always even.

Explanation: 

 input : 5    // odd
   00000101              
 & 00000001                
--------------                
   00000001       
--------------

input : 8     //even
   00001000              
 & 00000001                 
--------------               
   00000000        
--------------
Below is the implementation of the idea. 




```cpp
#include <iostream> 
using namespace std; 
  
// Returns true if n is 
// even, else odd 
bool isEven(int n) 
{ 
  
    // n & 1 is 1, then 
    // odd, else even 
    return (!(n & 1)); 
} 
  
// Driver code 
int main() 
{ 
    int n = 101; 
    isEven(n) ? cout << "Even" : cout << "Odd"; 
  
    return 0; 
}

```
Output
Odd
Time Complexity: O(1)
Auxiliary Space: O(1)

Method 3: Another approach is by using bitwise left-shift and right-shift operators. The logic behind this implementation is about regenerating the value after the right shift and left shift. We all know even numbers have zero as the last bit and odd have one as the last bit. When we bitwise right shift any number then the last bit of the number piped out whenever it is even or odd. Next, we did a bitwise left shift, then our bit shifted by one. Now last bit placed is empty which is by default filled by a zero. During all these odd numbers changed their value but even remains the same. That’s how by comparing the initial and final value we decide number is even or odd.


 

below is the implementation of the above logic.



```cpp
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
  
    int a = 4; 
    // To take input from user, prefer below code 
    // int a ; 
    // cout<<"Enter an number: " <<"\n"; 
    // cin>>a; 
  
    if (a == (a >> 1) << 1) { 
        cout << "Number is Even: " << a << endl; 
    } 
    else { 
        cout << "Number is Odd: " << a << endl; 
    } 
  
    // below is short hand 
    // a==(a>>1)<<1? printf("Number %d is 
    // even.\n",a):printf("Number %d is odd.\n",a); 
  
    return 0; 
}

```

Output
Number 4 is even.
Number is Even: 4
 
Time Complexity: O(1)
Auxiliary Space: O(1)
