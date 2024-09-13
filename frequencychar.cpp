

Problem:
Given a string, compress repeated letters. For example, for input "abccaddeeeeeaa", the output should be "abc2ad2e5a2".

Brute Force Solution
// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

void Printfrequency(string str)
{
  sort(str.begin(), str.end()); // Sort the string

  char ch = str[0];
  int count = 1;

  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      if (count > 1) // Only print character with count if count > 1
        cout << ch << count;
      else
        cout << ch;
      
      count = 1;
      ch = str[i];
    }
  }

  // Handle the last character
  if (count > 1)
    cout << ch << count;
  else
    cout << ch;
}

int main()
{
  string str = "takeuforward";
  Printfrequency(str);  // Expected output: a2d2e5a2
  return 0;
}

Time complexity: 

O(nlogn)
Space complexity: 

O(n)




Example Walkthrough:
For input: "abccaddeeeeeaa"

The algorithm starts with the first character 'a' (count = 1).
The next character is 'b' (count = 1).
For 'c', it counts 2 consecutive occurrences, so it becomes "c2".
For 'a', it counts 1.
For 'd', it counts 2.
For 'e', it counts 5 consecutive occurrences, so it becomes "e5".
For 'a', it counts 2.
The final result is: "abc2ad2e5a2"
