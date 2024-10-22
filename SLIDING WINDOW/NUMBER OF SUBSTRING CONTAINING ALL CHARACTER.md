1358. Number of Substrings Containing All Three Characters

https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1

 ---

 VARIABLE APPROACH:

 ```cpp
int numberOfSubstrings(string s) {
        int i=0,j=0,n=s.length(), count=0;
        int m[3]={0,0,0};

        while(j<n)
        {
            m[s[j]-'a']++;

            while(m[0] && m[1] && m[2])
                count+= n-j,
                m[s[i++]-'a']--;
            
            j++;
        }

        return count;
```

for more details:


https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/5669090/simple-approaches-wise-approach-slay-it-simple-concise-code-c-code-reference/
