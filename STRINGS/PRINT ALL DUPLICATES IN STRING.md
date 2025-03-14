```cpp

#include <bits/stdc++.h>

#include<iostream>

using namespace std;

int main() {
  string str = "sinstriiintng";

  map < char, int > countsMap;

  for (int i = 0; i < str.length(); i++)
    countsMap[str[i]]++;

  for (pair < char, int > entry: countsMap)
    if (entry.second > 1)
      cout << entry.first << " - " << entry.second << "\n";

  return 0;
}
Output:

i - 4
n - 3
s - 2
t - 2

Time Complexity: O(n log(n)), since accessing HashMap takes log(n) time and we access the map for each character in the string (total of n characters).

Space Complexity: O(1), since the string has only characters from ‘a’ to ‘z’, the size of the HashMap doesn’t exceed 26, irrespective of how big the input string is.

---


```cpp

#include<iostream>

using namespace std;

int main() {
  string str = "sinstriiintng";

  int counts[26] = {
    0
  };

  for (int i = 0; i < str.length(); i++)
    counts[str[i] - 'a']++;

  for (int i = 0; i < 26; i++)
    if (counts[i] > 1)
      cout << (char)(i + 'a') << " - " << counts[i] << "\n";

  return 0;
}
Output:

i - 4
n - 3
s - 2
t - 2

Time Complexity: O(n), we traverse each character in the string, and accessing the array takes only constant time (n is the length of the string).

Space Complexity: O(1), since the string has only characters from ‘a’ to ‘z’, the maximum size of the array is 26.

Special thanks to Prathap P for contributing to this article on takeUforward. If you also wish to share your knowledge with the

```


```
