```cpp

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    s+=" ";
    stack<string> st;
    string str="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();// The last word should'nt have a space after it
    cout<<"After reversing words: "<<endl;
    cout<<ans;
    return 0;
}

```

---
Output:

Before reversing words:
TUF is great for interview preparation
After reversing words:
preparation interview for great is TUF

Time Complexity: O(N), Traversing the entire string

Space Complexity: O(N), Stack and ans variable
Let's perform a detailed **dry run** for each line of the provided code to understand how it works:

### **Initial Input**
```cpp
string s = "TUF is great for interview preparation";
```

The initial string `s` contains `"TUF is great for interview preparation"`.

### **Step 1: Print the initial string**
```cpp
cout<<"Before reversing words: "<<endl;
cout<<s<<endl;
```
This prints:
```
Before reversing words: 
TUF is great for interview preparation
```

### **Step 2: Add a space at the end of the string**
```cpp
s += " ";
```
Now, `s` becomes:  
`"TUF is great for interview preparation "`

### **Step 3: Create a stack to store words and a temporary string to collect characters**
```cpp
stack<string> st;
string str = "";
```
- A `stack` `st` is created to store words.
- `str` is initialized to an empty string, which will temporarily hold each word from the input string.

### **Step 4: Loop through the string to extract words**
```cpp
for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
        st.push(str);  // Push the word to the stack
        str = "";  // Reset str to store the next word
    }
    else {
        str += s[i];  // Add the character to the current word
    }
}
```

- **First Iteration (i=0)**: `s[0]` is `'T'`. So, `str = "T"`.
- **Second Iteration (i=1)**: `s[1]` is `'U'`. So, `str = "TU"`.
- **Third Iteration (i=2)**: `s[2]` is `'F'`. So, `str = "TUF"`.
- **Fourth Iteration (i=3)**: `s[3]` is a space `' '`. The word `"TUF"` is pushed into the stack, and `str` is reset:
  - Stack now contains: `["TUF"]`
  - `str` becomes `""`.

- **Continue for the rest of the string**:
  - **"is"** is extracted and pushed into the stack.
  - **"great"**, **"for"**, **"interview"**, and **"preparation"** are also extracted and pushed.
  - At the end of the loop, the stack looks like this:
    - Stack: `["TUF", "is", "great", "for", "interview", "preparation"]`

### **Step 5: Reverse the words using the stack**
```cpp
string ans = "";
while (st.size() != 1) {
    ans += st.top() + " ";  // Add the top word to the answer
    st.pop();  // Remove the top word from the stack
}
```

- **First pop**: `"preparation"` is added to `ans`, and stack becomes `["TUF", "is", "great", "for", "interview"]`.
  - `ans = "preparation "`
  
- **Second pop**: `"interview"` is added to `ans`, and stack becomes `["TUF", "is", "great", "for"]`.
  - `ans = "preparation interview "`

- **Third pop**: `"for"` is added to `ans`, and stack becomes `["TUF", "is", "great"]`.
  - `ans = "preparation interview for "`

- **Fourth pop**: `"great"` is added to `ans`, and stack becomes `["TUF", "is"]`.
  - `ans = "preparation interview for great "`

- **Fifth pop**: `"is"` is added to `ans`, and stack becomes `["TUF"]`.
  - `ans = "preparation interview for great is "`

### **Step 6: Add the last word without a space**
```cpp
ans += st.top();
```
- The last word `"TUF"` is added without a space:
  - `ans = "preparation interview for great is TUF"`

### **Step 7: Print the final result**
```cpp
cout<<"After reversing words: "<<endl;
cout<<ans;
```
This prints:
```
After reversing words: 
preparation interview for great is TUF
```

### **Summary of Execution Flow**
- **Input String**: `"TUF is great for interview preparation"`
- Words are extracted and pushed onto a stack: `["TUF", "is", "great", "for", "interview", "preparation"]`.
- Stack is used to reverse the word order, and the final result is constructed:  
  `"preparation interview for great is TUF"`

### **Output**
```
Before reversing words: 
TUF is great for interview preparation
After reversing words: 
preparation interview for great is TUF
```


The code appends an extra space (s += " ";) at the end of the sentence to make sure the last word is processed correctly.

After this, the string becomes:
"TUF is great for interview preparation "

Using a Stack to Store Words:

The stack is used to hold words. As we iterate over the string, we build words by concatenating characters. When a space is encountered, the word is pushed onto the stack.
Iterating through the String:

Start with an empty string str.
Traverse through each character of the input string s.
Example steps for each word:

For the first word "TUF":
str = "TUF"
On encountering a space, push "TUF" to the stack.
Similarly for the remaining words:
str = "is" → Push "is" to the stack.
str = "great" → Push "great" to the stack.
str = "for" → Push "for" to the stack.
str = "interview" → Push "interview" to the stack.
str = "preparation" → Push "preparation" to the stack.
Reversing Words Using the Stack:

Now, the stack contains the words in reverse order:
mathematica
Copy code
Stack: {"preparation", "interview", "for", "great", "is", "TUF"}
The words are popped one by one from the stack and concatenated to form the reversed sentence.
Reconstructing the Sentence:

As we pop each word, we append it to the ans string along with a space (except the last word to avoid trailing spaces).
After popping all words, the final ans string will be:
arduino
Copy code
"preparation interview for great is TUF"
Math Behind the Stack Operations:
Stack Push: For each word, you push it onto the stack.

Total pushes = number of words.
If the input sentence contains W words, the push operation happens W times.

Example: For "TUF is great for interview preparation", we have 6 words, so we perform 6 push operations.

Stack Pop: After all words are pushed, we pop them one by one, which reverses the order of words.

Total pops = number of words.
Again, for W words, we perform W pop operations.

Time and Space Complexity:
Time Complexity:

The time complexity is proportional to the length of the string 
𝑛
n, as we traverse the string once and push each word to the stack, then pop them.
Therefore, the time complexity is 

O(n), where 

n is the length of the input string.
Space Complexity:

We use a stack to store the words, which requires space proportional to the number of words in the string.
If there are 
𝑊
W words, the space complexity is 

O(W), which can be simplified to 

O(n) because in the worst case, each character is part of a different word.
Conclusion:
The code efficiently reverses the words using a stack. By iterating through the string, identifying the words, and pushing them onto the stack, it leverages the stack’s Last In First Out (LIFO) property to reverse the order of the words.

The final output for the input string "TUF is great for interview preparation" will be:










```cpp



class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;

        string temp = "";
        string ans = "";

        // Remove leading spaces
        while (left <= right && s[left] == ' ') left++;

        // Iterate the string to form words
        while (left <= right) {
            char ch = s[left];

            // Form the word if it's not a space
            if (ch != ' ') {
                temp += ch;
            } 
            // If space is encountered, add the current word to the result
            else if (ch == ' ') {
                // Only add the word to the result if it's non-empty
                if (!temp.empty()) {
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                }
                temp = "";
                
                // Skip multiple spaces
                while (left <= right && s[left] == ' ') left++;
                continue;
            }

            left++;
        }

        // Add the last word (if any)
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;
    }
};

```
Output:
Let's dry run the code with the input string:  
`"  hello   world  "`  
which contains leading, trailing, and multiple spaces between words.

### **Initial Values:**
- `s = "  hello   world  "`
- `left = 0`
- `right = 16` (index of the last character in `s`)
- `temp = ""` (to store individual words)
- `ans = ""` (to store the final result)

---

### **Step 1: Remove Leading Spaces**
```cpp
while (left <= right && s[left] == ' ') left++;
```
- `left = 0`, `s[0] == ' '` → increment `left`
- `left = 1`, `s[1] == ' '` → increment `left`
- `left = 2`, `s[2] == 'h'` (not a space) → exit loop
- Now `left = 2`

---

### **Step 2: Main Loop: Iterating Through the String**

#### **First Iteration (left = 2)**
```cpp
char ch = s[left];  // ch = 'h'
```
- `ch != ' '` → `temp += ch` → `temp = "h"`
```cpp
left++;  // left = 3
```

#### **Second Iteration (left = 3)**
```cpp
char ch = s[left];  // ch = 'e'
```
- `ch != ' '` → `temp += ch` → `temp = "he"`
```cpp
left++;  // left = 4
```

#### **Third Iteration (left = 4)**
```cpp
char ch = s[left];  // ch = 'l'
```
- `ch != ' '` → `temp += ch` → `temp = "hel"`
```cpp
left++;  // left = 5
```

#### **Fourth Iteration (left = 5)**
```cpp
char ch = s[left];  // ch = 'l'
```
- `ch != ' '` → `temp += ch` → `temp = "hell"`
```cpp
left++;  // left = 6
```

#### **Fifth Iteration (left = 6)**
```cpp
char ch = s[left];  // ch = 'o'
```
- `ch != ' '` → `temp += ch` → `temp = "hello"`
```cpp
left++;  // left = 7
```

#### **Sixth Iteration (left = 7)**
```cpp
char ch = s[left];  // ch = ' '
```
- `ch == ' '` (space detected):
  - `temp = "hello"` (non-empty), so:
    ```cpp
    if (!ans.empty()) ans = temp + " " + ans;
    else ans = temp;  // ans = "hello"
    ```
  - Reset `temp = ""`
  - Skip any extra spaces:
    - `left = 7`, `s[7] == ' '` → increment `left`
    - `left = 8`, `s[8] == ' '` → increment `left`
    - `left = 9`, `s[9] == 'w'` → exit inner loop
  - Now `left = 9`

---

#### **Seventh Iteration (left = 9)**
```cpp
char ch = s[left];  // ch = 'w'
```
- `ch != ' '` → `temp += ch` → `temp = "w"`
```cpp
left++;  // left = 10
```

#### **Eighth Iteration (left = 10)**
```cpp
char ch = s[left];  // ch = 'o'
```
- `ch != ' '` → `temp += ch` → `temp = "wo"`
```cpp
left++;  // left = 11
```

#### **Ninth Iteration (left = 11)**
```cpp
char ch = s[left];  // ch = 'r'
```
- `ch != ' '` → `temp += ch` → `temp = "wor"`
```cpp
left++;  // left = 12
```

#### **Tenth Iteration (left = 12)**
```cpp
char ch = s[left];  // ch = 'l'
```
- `ch != ' '` → `temp += ch` → `temp = "worl"`
```cpp
left++;  // left = 13
```

#### **Eleventh Iteration (left = 13)**
```cpp
char ch = s[left];  // ch = 'd'
```
- `ch != ' '` → `temp += ch` → `temp = "world"`
```cpp
left++;  // left = 14
```

#### **Twelfth Iteration (left = 14)**
```cpp
char ch = s[left];  // ch = ' '
```
- `ch == ' '` (space detected):
  - `temp = "world"` (non-empty), so:
    ```cpp
    if (!ans.empty()) ans = temp + " " + ans;  // ans = "world hello"
    ```
  - Reset `temp = ""`
  - Skip any extra spaces:
    - `left = 14`, `s[14] == ' '` → increment `left`
    - `left = 15`, `s[15] == ' '` → increment `left`
    - `left = 16`, `s[16] == ' '` → increment `left`
    - `left = 17` (out of bounds) → exit inner loop

---

### **Step 3: Add the Last Word**
```cpp
if (!temp.empty()) {
    if (!ans.empty()) ans = temp + " " + ans;
    else ans = temp;
}
```
- Since `temp = ""` at this point, this block is skipped.

---

### **Final Result:**
The final reversed sentence is stored in `ans`, which is:
```cpp
ans = "world hello"
```

### **Output:**
The function returns `"world hello"`.

Before reversing words:
TUF is great for interview preparation
After reversing words:
preparation interview for great is TUF
Explanation of Changes:
Skip leading spaces: The initial while loop removes leading spaces from the left of the string.
Form words: While iterating over the string, characters are added to the temp string to form words.
Skip multiple spaces: When a space is encountered, we check if it's a single space or multiple consecutive spaces. Multiple spaces are skipped by advancing the left pointer to the next non-space character.
Avoid trailing spaces: After each word, if there is a valid word (temp is non-empty), it's added to the result. We ensure no trailing spaces are added by checking the condition of ans.empty().
Add the last word: At the end, any leftover word (temp) is added to the result string.
Time and Space Complexity:
Time Complexity: 

O(n), where 
𝑛
n is the length of the input string. We iterate over the string once.
Space Complexity: 

O(n), where 
𝑛
n is the length of the input string. The space is used for the result string and intermediate variables.
