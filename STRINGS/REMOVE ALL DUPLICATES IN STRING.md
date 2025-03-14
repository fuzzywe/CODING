Example 1:
Input: s = "bcabc"
Output: “bca"

Explanation: Duplicate Characters are removed
Example 2:
Input: s = "cbacdcbc"
Output: "cbad" 
Explanation: Duplicate Characters are removed

```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
string removeDuplicateLetters(string s) {
  string ans = "";
  for (int i = 0; i < s.length(); i++) 
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j]) //same character found
      {
        break;
      }
    }
    if (i == j) {
      ans += s[i];
    }
  }
  return ans;
}
int main() {
  string str = "cbacdcbc";
  cout<<"Original String: "<<str<<endl;
  cout <<"After removing duplicates: " <<removeDuplicateLetters(str) << endl;
  return 0;
}

Time Complexity: O(N^2)

Space Complexity: O(1)
  
```

---

```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
string removeDuplicateLetters(string s) {
  string ans = "";
  vector < bool > map(26, false);
  for (int i = 0; i < s.length(); i++) {
    if (map[s[i] - 'a'] == false) {
      ans += s[i];
      map[s[i] - 'a'] = true;
    }
  }
  return ans;
}
int main() {
  string str = "cbacdcbc";
  cout << "Original String: "<<str<<endl<<"After removing duplicates: "
  <<removeDuplicateLetters(str) << endl;
  return 0;
}

```

---


Output:

Original String: cbacdcbc
After removing duplicates: cbad

Time Complexity: O(N)

Space Complexity: O(1)


Example: "cbacdcbc"
Let’s walk through the code with this string:

Initial string: "cbacdcbc"
Initial ans: "" (empty string)
Initial map: [false, false, ..., false] (26 elements, all false)
Loop Iterations:

i = 0, character = 'c':

map[2] is false, so add 'c' to ans.
ans = "c", and map[2] becomes true.
i = 1, character = 'b':

map[1] is false, so add 'b' to ans.
ans = "cb", and map[1] becomes true.
i = 2, character = 'a':

map[0] is false, so add 'a' to ans.
ans = "cba", and map[0] becomes true.
i = 3, character = 'c':

map[2] is true (since 'c' was already added), so skip this character.
i = 4, character = 'd':

map[3] is false, so add 'd' to ans.
ans = "cbad", and map[3] becomes true.
i = 5, character = 'c':

map[2] is true, so skip this character.
i = 6, character = 'b':

map[1] is true, so skip this character.
i = 7, character = 'c':

map[2] is true, so skip this character.
Final result:
ans = "cbad"
The original string "cbacdcbc" has been processed,
and the duplicates are removed while maintaining the order of the first occurrences.
