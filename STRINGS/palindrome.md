
				

									
Method 1 Algorithm:-
For a user input num, create variables reverse = 0, rem, temp
Assign reverse = num
Extract last digit of temp as ‘rem’
Construct reverse as reverse = reverse * 10 + rem
Reduce length of temp as temp = temp / 10
Keep doing until temp becomes 0
If num == reverse
Print palindrome else print its not
								

				

				

				

																														

				

				

				

									
```cpp
//C++ Program to check whether a number is palindrome or not
#include <iostream>
using namespace std;

//main program
int main ()
{
    //variables initialization
    int num, reverse = 0, rem, temp;
    num=12321;
    cout <<"\nThe number is: "<<num; 
   
 
    temp = num;
    //loop to find reverse number
    while(temp != 0)
    {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp /= 10;
    };
    
    // palindrome if num and reverse are equal
    if (num == reverse)
        cout << num << " is Palindrome";
    else
        cout << num << " is not a Palindrome";

}
// Time Complexity : O(N)
// Space Complexity : O(1)
// where N is the number of digits in num
								

				

				
```

---
				

									
Output
The number is: 12321
12321 is Palindrome
								

				

				

				

									
Method 2
This method uses recursion in C++
								

				

				

				

									
```cpp
#include<iostream> 
using namespace std;

// Recursive way to find reverse of a number
int getReverse(int num, int rev){
    if(num == 0)
        return rev;
    
    int rem = num % 10;
    rev = rev * 10 + rem;
    
    return getReverse(num / 10, rev);
}

//main program
int main ()
{
    int num, reverse = 0;
    num=123454321;
    cout <<"\nThe number is: "<<num; 
    
    
    // palindrome if num and reverse are equal
    if (getReverse(num, reverse) == num)
        cout << num << " is Palindrome";
    else
        cout << num << " is not a Palindrome";

}
// Time Complexity : O(N)
// Space Complexity : O(1)
// where N is the number of digits in num
// Auxilliary Space Complexity : O(N)
// Due to function call stack
								

				

				
```
				

									
Output
The number is: 123454321
123454321 is Palindrome
								

				

					
		
				
---
			

						

				

							

							

					

												
					

					

								

				

				

				

									
Method 3
For a String of Length: Len
Run an iterative loop in an iteration of i
If encounter any index such that string[i] != string[len – i -1], then the string is not palindrome
Otherwise if no condition such found in the whole iteration in the loop then string is a palindrome
								

				

				

				

									

```cpp

#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
    char string[10] = "radar";
    int i, len;
    bool flag = false;
    
    len = strlen(string);

    for (i = 0; i < len; i++) 
    {
        // Checking if string is palindrome or not
        if (string[i] != string[len - i - 1]) {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << string << " is not palindrome";
    else
        cout << string << " is palindrome";
        
    return 0;
}
								

				

				
```
				

									
Output
radar is palindrome
								

				

				

				

									
Method 4
This method is the same as the above method with two minor differences –
Difference 1
For loop runs only till len/2 not the whole length of the string
Since the other half, the string will be the same as the first half. If the string is a palindrome
Difference 2
We also handle capitalization
The previous method would have said “Radar” is not palindrome as R is not equal to r
This method converts the whole string into lowercase and thus will say that “Naman” is palindrome
								

				

				

				

---

```cpp

#include <iostream>
#include <string.h>
using namespace std;

void lowerCase(char str[]){
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] > 64 && str[i] < 91) 
      str[i] += 32; 
    i++;
  }
}
int main() 
{
    char string[10] = "Radar";
    int i, len, flag = 0;
    
    lowerCase(string);
    
    len = strlen(string);
    
    // only need to check till half of the array
    for (i = 0; i < len / 2; i++) 
    {
        // Checking if string is palindrome or not.
        if (string[i] != string[len - i - 1]){
            flag++;
            break;
        }
    }

    if (flag)
        cout << string << " is not palindrome";
    else
        cout << string << " is palindrome";
        
    return 0;
}


```					

				

				

				

									
Output
radar is palindrome
								

				

				

				
---

Method 5
This method is the same as the above method. However, instead of for loop, we use a whole loop.
The approach is very similar to Binary search looping
								

				

				

				

									


```cpp
#include <iostream>
#include <string.h>
using namespace std;

void Lower_case(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91) str[i] += 32;
        i++;
    }
}

void CheckPalindrome(char string[]) 
{
    // to mark left most and right most indexes of string
    int left = 0;
    int right = strlen(string) - 1;
    
    // Keep comparing characters while they are same
    // until left and right overlap one another
    // inspiration for this approach taken from binary search
    while (right > left) 
    {
        if (string[left++] != string[right--]) {
            cout << string << " is not palindrome";
            return;
        }
    }
        cout << string << " is palindrome";
}
int main() 
{
    char str1[50] = "Radar";
    
    Lower_case(str1);
    CheckPalindrome(str1);
    
    return 0;
}


								

				

				
```
				

									
Output
radar is palindrome
								

				
