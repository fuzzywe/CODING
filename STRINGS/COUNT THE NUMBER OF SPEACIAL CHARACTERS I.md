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
        vector<bool> s('z' + 1);
        for (char& c : word) {
            s[c] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += s['a' + i] && s['A' + i];
        }
        return ans;
    }
};

```

BIT MANIPULATION


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

---

```cpp

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> st; 
        for(int i=0;i<word.size();i++){
            int temp = word[i];
            st.insert(temp);
        }
        int count = 0;
        for(auto it:st){
            if(it>=65 && it<=90){
                if(st.find(it+32) != st.end()){
                    count++;
                }
            }
        }
        return count;
    }
};

```

---

```cpp

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> st; 
        
        // Step 1: Insert all characters from 'word' into the unordered set 'st'
        for(int i = 0; i < word.size(); i++) {
            int temp = word[i];    // Store the ASCII value of each character in 'temp'
            st.insert(temp);       // Insert 'temp' into the set 'st' (only unique values will be stored)
            
            // Dry Run for word = "aaAbcBC"
            // i = 0, temp = 'a' (ASCII 97) --> st = {97}
            // i = 1, temp = 'a' (ASCII 97) --> st = {97} (no change, 'a' is already in the set)
            // i = 2, temp = 'A' (ASCII 65) --> st = {97, 65}
            // i = 3, temp = 'b' (ASCII 98) --> st = {97, 65, 98}
            // i = 4, temp = 'c' (ASCII 99) --> st = {97, 65, 98, 99}
            // i = 5, temp = 'B' (ASCII 66) --> st = {97, 65, 98, 99, 66}
            // i = 6, temp = 'C' (ASCII 67) --> st = {97, 65, 98, 99, 66, 67}
        }
        
        int count = 0;  // Initialize count to 0 to keep track of special characters
        
        // Step 2: Check for each uppercase character if it has a corresponding lowercase character in the set
        for(auto it : st) {
            if(it >= 65 && it <= 90) {  // If 'it' is an uppercase letter (ASCII range 65 to 90)
                
                // Dry Run continued for the set st = {97, 65, 98, 99, 66, 67}
                // it = 97 ('a') --> skip (not uppercase)
                // it = 65 ('A') --> uppercase, check for lowercase 'a' (ASCII 97)
                if(st.find(it + 32) != st.end()) {  // it + 32 converts 'A' (65) to 'a' (97)
                    count++;  // Found 'a' before 'A', so 'a'/'A' is special
                    // count = 1
                }
                
                // it = 98 ('b') --> skip (not uppercase)
                // it = 99 ('c') --> skip (not uppercase)
                
                // it = 66 ('B') --> uppercase, check for lowercase 'b' (ASCII 98)
                if(st.find(it + 32) != st.end()) {  // it + 32 converts 'B' (66) to 'b' (98)
                    count++;  // Found 'b' before 'B', so 'b'/'B' is special
                    // count = 2
                }
                
                // it = 67 ('C') --> uppercase, check for lowercase 'c' (ASCII 99)
                if(st.find(it + 32) != st.end()) {  // it + 32 converts 'C' (67) to 'c' (99)
                    count++;  // Found 'c' before 'C', so 'c'/'C' is special
                    // count = 3
                }
            }
        }
        
        return count;  // Return the final count of special characters
        // Final count = 3, which is the answer
    }
};

```
