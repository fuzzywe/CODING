https://leetcode.com/problems/add-digits/description/

258. Add Digits
Easy
Topics
Companies
Hint
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


OPTIMAL 

```cpp

class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        int k=10;
        while(k>9)
        {
            k=0;
            for(int i=0;i<s.size();i++)
            {
                k+=s[i]-48;
            }
            s=to_string(k);
        }
        return k;
    }
};

```
