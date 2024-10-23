828. Count Unique Characters of All Substrings of a Given String

https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/

Let's define a function countUniqueChars(s) that returns the number of unique characters in s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

 

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
Example 3:

Input: s = "LEETCODE"
Output: 92

---

For finding the unique characters in each sub string, we'll find the number of contributions of each character in the substring..

i.e If a char 'A' is present in the string, then we'll find the contribution of 'A', the number of substring in which 'A' is present.

let's understand :

![image](https://github.com/user-attachments/assets/4783efa2-6ad7-426b-be85-3bbb69ff2ce4)

![image](https://github.com/user-attachments/assets/187ec2a0-43fc-4c86-98f7-469f79cbcb15)

![image](https://github.com/user-attachments/assets/8d23e440-e199-43a4-9d65-4d2e11c4c5f3)

![image](https://github.com/user-attachments/assets/9318643c-cbc1-4a0d-a700-da11339856b6)

![image](https://github.com/user-attachments/assets/58afe560-7ded-48cb-8d54-b94d5f9f7aa7)

![image](https://github.com/user-attachments/assets/02e54f36-79bf-4287-a72a-98760c06f023)

![image](https://github.com/user-attachments/assets/ba711781-89d4-406f-aca6-4988f040de67)


Code

```
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int> > hash(26);
        for(int i = 0; i < 26; i++) hash[i].push_back(-1);
// pushing -1 for all the 26 characters

        for(int i = 0; i < n; i++) hash[s[i] - 'A'].push_back(i);
// storing the index of each character inside the map

        for(int i = 0; i < 26; i++) hash[i].push_back(n);
// pushing the last index for all the 26 characters

// now calculating the count by taking the product of the left window and the right window

        long long cnt = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 1; j < hash[i].size()-1; j++){
                cnt += (hash[i][j] - hash[i][j-1])*(hash[i][j+1] - hash[i][j]);
            }
        }

        return cnt;
    }
};
```
