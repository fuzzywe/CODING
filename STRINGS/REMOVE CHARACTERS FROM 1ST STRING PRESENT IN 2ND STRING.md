```cpp
#include<bits/stdc++.h>

using namespace std;
string solve(string str1, string str2) {
  unordered_map < char, int > mp;
  string ans = "";
  for (int i = 0; i < str2.length(); i++) {
    mp[str2[i]] = 1;
  }
  for (int i = 0; i < str1.length(); i++) {
    if (!mp[str1[i]]) {
      ans.push_back(str1[i]);
    }
  }
  return ans;
}
int main() {

  // Input string
  string str1 = "abcdef"; // string 1
  string str2 = "cefz"; // string 2

  cout << "Final string 1:" << "\n";
  cout << solve(str1, str2) << "\n";
  return 0;
}


```


```cpp

#include<bits/stdc++.h>

using namespace std;
string solve(string str1, string str2) {
  string ans;
  for (int i = 0; i < str1.length(); i++) {
    int flag = 0;
    for (int j = 0; j < str2.length(); j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (flag != 1)
      ans.push_back(str1[i]);
  }
  return ans;
}
int main() {

  // Input string
  string str1 = "abcdef";
  string str2 = "cefz";

  cout << "Final string 1:" << "\n";
  cout << solve(str1, str2) << "\n";
  return 0;
}


```
