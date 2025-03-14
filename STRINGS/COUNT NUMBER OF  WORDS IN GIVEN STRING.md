

https://takeuforward.org/data-structure/count-the-number-of-words-in-a-given-string/


```cpp

#include <bits/stdc++.h>

using namespace std;

int main() {

  string str = "HI AMY AND JAY";
  int n = str.length();
  int spaces=0;
  
  for(int i=0; i<n; i++){
      if(str[i]==' ')
        spaces= spaces+1;
  }
  
  cout<<"The number of words are "<< spaces+1;

}
Output: The number of words is 4

Time Complexity: O(N)

Reason: We iterate for the length of the string

Space Complexity: O(1)

Reason: We are not using any extra space.


```
