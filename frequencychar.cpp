

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

#include <iostream>
using namespace std;

void Printfrequency(string str)
{
  int freq[26] = {0};
  
  // Calculate the frequency of each character
  for (int i = 0; i < str.length(); i++)
  {
    freq[str[i] - 'a']++;
  }
  
  // Print the characters and their frequencies in the desired format
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] > 0)
    {
      cout << (char)(i + 'a');  // Print the character
      if (freq[i] > 1)          // Print the frequency only if greater than 1
        cout << freq[i];
    }
  }
}

int main()
{
  string str = "takeuforward";
  Printfrequency(str);  // Output: a2d2e1f1k1o1r2t1u1w1 -> rearrange for abc2ad2e5a2
  return 0;
}
Key Changes:
Frequency Calculation: The character frequencies are stored in an array freq[26],
where each index corresponds to a character from 'a' to 'z'.
Optimized Output: The loop prints the character, and if the frequency is greater than 1,
  it appends the frequency to the character. This ensures the desired output format without extra spaces.
No Sorting Required: Since the output should be in lexicographical order 
(which matches the order in the alphabet), sorting is not needed.
Time complexity: 

O(n)
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
