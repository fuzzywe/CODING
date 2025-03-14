```cpp

#include <iostream>
using namespace std;
 
int main() {
  string text = "takeuforward";
  string pattern = "forward";
  auto foundIdx = text.find(pattern);
  cout <<"The substring starts from the index: " <<foundIdx << endl;
  return 0;
}
Output: The substring starts from the index: 5

Time Complexity: O(N)

Space Complexity: O(1)


```

---


```cpp

User
Find the Position of a Substring within a String


24

0
In this article we will solve the most asked interview question: "Find the Position of a Substring within a String"

Problem statement: “Given two strings text and pattern find the first occurrence of str1 in str2 if found print it’s index if not found print -1.”

Examples:

Example 1:
Input: str1 = "takeuforward"
       str2 = “forward”
Output: 5
Explanation: "Forward" is present in the 5th index in "takeuforward"

Example 2:
Input: str1 = “hello”
       str2 = “az”
Output: -1
Explanation: "az" is not a substring of "hello"
Solution:

Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1: Naive Approach

Run two for loops i,j.
i looping from [0, N - M - 1] and j looping from [0, M -1]. Here N is the length of text and M is the length of pattern.
Why is the outer loop running for N - M - 1 ??

For a given string to have a substring of another string it must contain the length of the substring to be found in the string.If it doesn’t have the length of the substring there is no point in searching any further.
Now run an outer loop from i -> [0, N - M - 1]  for every index i check for the substring this can be done by storing the index of i into some variable temp and running an inner loop from j -> [0, M] check if the characters of text and pattern are matching or not from the index [temp, temp + M]. after coming out of the inner loop check if (j == M) then return i.

If the substring is not found return -1.

Code:

C++
Java
#include <iostream>

#include<string>

using namespace std;

int foundPattern(string text, string pattern) {
  int N = text.length();
  int M = pattern.length();

  for (int i = 0; i < N; i++) {
    int temp = i;
    int j = 0;
    for (j = 0; j < M; j++) {
      if (text[temp] != pattern[j]) {
        break;
      }
      temp++;
    }
    if (j == M) {
      return i;
    }
  }

  return -1;
}

int main() {
  string text = "takeuforward";
  string pattern = "forward";
  int foundIdx = foundPattern(text, pattern);
  cout << "The substring starts from the index: "<<foundIdx << endl;
  return 0;
}

Output: The substring starts from the index: 5

Time Complexity: O(N^2)

Space Complexity: O(1)

```
