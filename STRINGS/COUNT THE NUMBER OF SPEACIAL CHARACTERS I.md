https://leetcode.com/problems/count-the-number-of-special-characters-i/description/



3120. Count the Number of Special Characters I
Easy
Topics
Companies
Hint
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.


```cpp

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int or_lower = 0, or_upper = 0;
        for(char ch : word){
            if(islower(ch)){
                or_lower |= (1<< (ch-'a'));
            }else{
                or_upper |= (1<< (ch-'A'));
            }
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(or_lower & (1<<i) && or_upper & (1<<i)) ans++;
        }
        
        return ans;
    }
};

```
