

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”


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
    int i;
    string str="";
    for(i=0;i<s.length();i++)
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


```

---

```cpp

Java
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


```
