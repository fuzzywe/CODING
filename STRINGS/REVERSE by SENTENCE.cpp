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



optimized solution
#include<bits/stdc++.h>
using namespace std;
string result(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
}
int main()
{
    string st="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<st<<endl;
    cout<<"After reversing words: "<<endl;
    cout<<result(st);
    return 0;
}
Output:

Before reversing words:
TUF is great for interview preparation
After reversing words:
preparation interview for great is TUF

Time Complexity: O(N), N~length of string

Space Complexity: O(1), Constant Space
