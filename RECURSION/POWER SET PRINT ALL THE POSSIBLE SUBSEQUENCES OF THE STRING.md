**Power Set: Print all the possible subsequences of the String**



Problem Statement: Given a string, find all the possible subsequences of the string.

Examples:

Example 1:
Input: str = "abc"

Output: a ab abc ac b bc c

Explanation: Printing all the 7 subsequence for the string "abc".

Example 2:
Input: str = "aa"

Output: a a aa 

Explanation: Printing all the 3 subsequences for the string "aa"

Solution

Solution 1: Using bit manipulation
Approach: Prerequisites: To check whether the ith bit is set or not.If n&(1<<i) != 0,

then the ith bit is set.
First, write down all the numbers from 0 to 2^(n)-1 

and their bit representation.0 means I am not picking the character in my subsequence,
and 1 means I am picking the character.



Basically, we traverse from 0 to 2^(n)-1 and check for every number if their bit is set or not. If the bit is set add that character to your subsequence.





```cpp
#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}
Output:

All possible subsequences are
a ab abc ac b bc c

Time Complexity: O(2^n * n)

Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.

Space Complexity: O(1)
```
Solution 2: Using recursion(Backtracking)
Intuition: Since we are generating subsets two cases will be possible, either you can pick the character or you cannot pick the character and move to the next character.

Approach:



Maintain a temp string (say f),which is empty initally.
Now you have two options,either you can pick the character or not pick the character and move to the next index.
Firstly we pick the character at ith index and then move to the next index.(f + s[i])
If the base condition is hit,i.e i==s.length() ,then we print the temp string and return.
Now while backtracking we have to pop the last character since now we have to implement the non-pick condition and then move to next index.
```cpp


#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}
Output:

All possible subsequences are:
abc ab ac a bc b c

Time Complexity: O(2^n)

Space Complexity: O(n), recursion stack.

```
