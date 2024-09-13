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
Output:

Before reversing words:
TUF is great for interview preparation
After reversing words:
preparation interview for great is TUF

Time Complexity: O(N), Traversing the entire string

Space Complexity: O(N), Stack and ans variable

  Input Sentence:

The input string is "TUF is great for interview preparation".
Adding a Space to the End:

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

arduino
Copy code
"preparation interview for great is TUF"





You said:
i didn't understand
ChatGPT said:
ChatGPT
Let’s go through the code and explain it step by step with a simple analogy and example to make it clearer.

The Code Overview:
This program takes a sentence and reverses the order of the words in the sentence. It uses a stack to achieve this.

Let’s simplify this with an example:

Example Input:
arduino
Copy code
"TUF is great"
The goal is to reverse the order of the words, so the output should be:

arduino
Copy code
"great is TUF"
How It Works:
Stack Analogy: Think of a stack as a vertical pile of plates. You can only put plates on top and take them from the top. This "Last In, First Out" (LIFO) structure is perfect for reversing things.

Key Idea:

We will split the sentence into words and put each word on the stack.
Then we take each word from the stack one by one. Since the stack works in reverse order (LIFO), the words will come out in reverse order.
Step-by-Step Breakdown:
Input Sentence:

Let's say the input is "TUF is great".
Adding a Space to the End:

In the code, a space is added to the string so the last word will be pushed to the stack properly.
After this, the string becomes:
arduino
Copy code
"TUF is great "
Using a Stack to Store Words:

As the program iterates through the string, it builds words one character at a time.
When it encounters a space, it pushes the word onto the stack.
Here’s what happens in each iteration:

First, "TUF" is created and pushed onto the stack.
Then "is" is created and pushed onto the stack.
Finally, "great" is created and pushed onto the stack.
After this process, the stack will look like this:

mathematica
Copy code
Stack: ["TUF", "is", "great"]
Popping Words from the Stack:

Now, we start taking the words out of the stack.
The first word we pop is "great", because it was the last word pushed.
Then, we pop "is", and finally "TUF".
Since the stack is a LIFO (Last In, First Out) structure, the words come out in reverse order.
The output string becomes:

arduino
Copy code
"great is TUF"



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

Output:

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
