A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 Approach 3: Using string manipulation

Continuously search for the substring “()” in the input string.
If the substring “()” is found, replace it with an empty string.
Repeat steps 1 and 2 until the substring “()” can no longer be found.
The length of the resulting string is the minimum number of parentheses needed to make the string valid.
Here is the implementation of above approach:

   
#include <iostream>
#include <string>
 
using namespace std;
 
int minParentheses(string s) {
    while (s.find("()") != -1) {
        s.replace(s.find("()"), 2, "");
    }
    return s.length();
}
 
int main() {
    string s = "(((";
    cout << minParentheses(s) << endl;
    return 0;
}

Output
3
Time Complexity: O(n^2) where n is the length of the input string. This is because the find() and replace() operations are called repeatedly in a loop.

Auxiliary Space: O(n) where n is the length of the input string. This is because the string s is being replaced in place and no additional data structures are being used.

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3


class Solution {
public:
    int minAddToMakeValid(string s) {
        string stk;
        for (char c : s) {
            if (c == ')' && stk.size() && stk.back() == '(')
                stk.pop_back();
            else
                stk.push_back(c);
        }
        return stk.size();
    }
};


class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, cnt = 0;
        for (char c : s) {
            if (c == '(')
                ++cnt;
            else if (cnt)
                --cnt;
            else
                ++ans;
        }
        ans += cnt;
        return ans;
    }
};
