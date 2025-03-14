#include <iostream>
#include <algorithm>
using namespace std;
void Printfrequency(string str)
{
  sort(str.begin(), str.end());
  char ch = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      cout << ch << count << " ";
      count = 1;
      ch = str[i];
    }
  }
  cout << ch << count << " ";
}

int main()
{
  string str = "takeuforward";
  Printfrequency(str);
  return 0;
}
Output: a2 d1 e1 f1 k1 o1 r2 t1 u1 w1

Time Complexity: O(nlogn) since sorting function requires nlogn iterations.

Space Complexity: O(1)


Step 1: Sort the string The string "bat" is first sorted to make counting easier. Sorting "bat" alphabetically gives:

arduino
Copy code
"abt"
Now, the string is "abt".

Step 2: Count and Print the Frequency Now we want to count how many times each character appears.

We start with the first character, 'a'. It appears 1 time.
Next, we move to 'b'. It also appears 1 time.
Then, we move to 't'. It appears 1 time.
So, the output would be:

Copy code
a1 b1 t1
This means:

'a' appears once (a1)
'b' appears once (b1)
't' appears once (t1)
Now let’s move to a more complex example, like the original "takeuforward".

Detailed Example with "takeuforward"
Step 1: Sort the String

The input string is "takeuforward". Sorting it alphabetically gives:

arduino
Copy code
"aadefkorrtuw"
Now, the string is "aadefkorrtuw".

Step 2: Count and Print the Frequency

We now count how many times each character appears in the sorted string:

Start with 'a': It appears 2 times.
Move to 'd': It appears 1 time.
Move to 'e': It appears 1 time.
Move to 'f': It appears 1 time.
Move to 'k': It appears 1 time.
Move to 'o': It appears 1 time.
Move to 'r': It appears 2 times.
Move to 't': It appears 1 time.
Move to 'u': It appears 1 time.
Move to 'w': It appears 1 time.
So, the output is:

Copy code
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
This means:

'a' appears twice (a2)
'd' appears once (d1)
'e' appears once (e1)
'f' appears once (f1)
'k' appears once (k1)
'o' appears once (o1)
'r' appears twice (r2)
't' appears once (t1)
'u' appears once (u1)
'w' appears once (w1)
Why Sorting?
By sorting the string, characters that are the same (like both 'r's) end up next to each other. This makes it easier to count them in one pass.

Step 1: Sort the String

Before sorting:
"takeuforward"

After sorting (using sort(str.begin(), str.end())):
"aadefkorrtuw"

Sorting the string ensures that identical characters are grouped together, making it easier to count their frequencies.

Step 2: Initialize the Variables

ch is initialized to the first character of the sorted string, which is 'a'.
count is initialized to 1 because we start by counting the first character 'a'.
Step 3: Traverse the Sorted String

The sorted string is: "aadefkorrtuw"

Now, let's walk through each character:

Character 'a' (i = 1):
The second character is also 'a', so the count becomes 2.
Character 'd' (i = 2):
The third character is 'd', which is different from 'a'.
We print "a2" and reset count = 1 for the new character 'd'.
Character 'e' (i = 3):
The fourth character is 'e', different from 'd'.
We print "d1" and reset count = 1 for the new character 'e'.
Character 'f' (i = 4):
The fifth character is 'f', different from 'e'.
We print "e1" and reset count = 1 for 'f'.
Character 'k' (i = 5):
The sixth character is 'k', different from 'f'.
We print "f1" and reset count = 1 for 'k'.
Character 'o' (i = 6):
The seventh character is 'o', different from 'k'.
We print "k1" and reset count = 1 for 'o'.
Character 'r' (i = 7, 8):
The eighth and ninth characters are 'r'.
The count becomes 2 because 'r' appears twice.
Character 't' (i = 9):
The tenth character is 't', different from 'r'.
We print "r2" and reset count = 1 for 't'.
Character 'u' (i = 10):
The eleventh character is 'u', different from 't'.
We print "t1" and reset count = 1 for 'u'.
Character 'w' (i = 11):
The twelfth character is 'w', different from 'u'.
We print "u1" and reset count = 1 for 'w'.
Step 4: Print the Last Character

At the end of the loop, the last character 'w' is printed with its count:
"w1"

Final Output
The program prints:

Copy code
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1







#include <iostream>
using namespace std;

void Printfrequency(string str)
{
  int freq[26] = {0};
  for (int i = 0; i < str.length(); i++)
  {
    freq[str[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
    {
      cout << (char)(i + 'a') << freq[i] << " ";
    }
  }
}

int main()
{
  string str = "takeuforward";
  Printfrequency(str);
  return 0;
}
Output: a2 d1 e1 f1 k1 o1 r2 t1 u1 w1

Time Complexity: O(n) where n is the length of string

Space Complexity: O(1) 
Code Explanation:
Input String: The program takes a string (in this case, "takeuforward") and counts the frequency of each character in the string.

Frequency Array:

int freq[26] = {0}; creates an array of size 26, initialized to 0, representing the frequency of each lowercase letter from 'a' to 'z'. Since there are 26 letters in the English alphabet, each position in the array corresponds to a letter.
freq[str[i] - 'a']++; increments the count at the position corresponding to the character in the string. For example, if the character is 'a', then str[i] - 'a' will be 0, which means the count in freq[0] is incremented by 1.
Loop through string:

The for loop goes through each character of the string and updates the frequency array.
After the loop, the program prints only those characters whose frequency is greater than 0.
Example Walkthrough:
Let’s walk through the example with the string "takeuforward":

Initial freq array (size 26):

csharp
Copy code
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
Now, as each character in "takeuforward" is processed, the frequency array gets updated:

't': freq['t' - 'a'] becomes 1.
'a': freq['a' - 'a'] becomes 1.
'k': freq['k' - 'a'] becomes 1.
'e': freq['e' - 'a'] becomes 1.
'u': freq['u' - 'a'] becomes 1.
'f': freq['f' - 'a'] becomes 1.
'o': freq['o' - 'a'] becomes 1.
'r': freq['r' - 'a'] becomes 1.
'w': freq['w' - 'a'] becomes 1.
'a': freq['a' - 'a'] becomes 2 (since 'a' appears twice).
'r': freq['r' - 'a'] becomes 2 (since 'r' appears twice).
'd': freq['d' - 'a'] becomes 1.
After processing the string, the freq array becomes:

csharp
Copy code
[2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 1, 1, 0, 1, 0, 0, 0]
The program then loops through this frequency array and prints characters with non-zero frequencies:

Copy code
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
Time Complexity:
O(n): The program loops through the input string exactly once to calculate the frequency of each character, where n is the length of the string. Then, it loops through the frequency array (which is of constant size 26) to print the characters. The dominant factor is the string traversal, making the time complexity O(n), where n is the length of the input string.
Space Complexity:
O(1): The space complexity is considered O(1) because the size of the frequency array freq[26] is constant (26 letters in the alphabet). Regardless of the input string size, this array always has a fixed size of 26. Hence, it uses constant space.
Example Summary:
For the string "takeuforward", the program outputs:

Copy code
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
Time complexity: O(n), where n is the length of the input string (12 in this case).
Space complexity: O(1) because the space used by the frequency array is constant.


Program Explanation:
Input String:
The string used is "takeuforward".
Printfrequency Function:
The function takes a string str as input.
It initializes an array freq[26] = {0} to store the frequency of each character from 'a' to 'z'. The size 26 corresponds to the 26 lowercase English letters.
The loop goes through each character of the string and increments the corresponding index in the freq array. The index is calculated using str[i] - 'a', which gives the difference between the ASCII values of the character and 'a'. This difference serves as the index in the freq array.
After that, another loop prints the characters whose frequency is greater than 0. The character is reconstructed by adding 'a' to the index i.
Example Walkthrough:
Let's trace the code with the input "takeuforward".

Step 1: Initialize Frequency Array

cpp
Copy code
int freq[26] = {0};
Initially, the frequency array is:
makefile
Copy code
freq = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
Step 2: Iterate through the String and Update Frequencies

For each character in "takeuforward", the freq array is updated:

't' → freq['t' - 'a'] = freq[19]++, so freq[19] = 1.
'a' → freq['a' - 'a'] = freq[0]++, so freq[0] = 1.
'k' → freq['k' - 'a'] = freq[10]++, so freq[10] = 1.
'e' → freq['e' - 'a'] = freq[4]++, so freq[4] = 1.
'u' → freq['u' - 'a'] = freq[20]++, so freq[20] = 1.
'f' → freq['f' - 'a'] = freq[5]++, so freq[5] = 1.
'o' → freq['o' - 'a'] = freq[14]++, so freq[14] = 1.
'r' → freq['r' - 'a'] = freq[17]++, so freq[17] = 1.
'w' → freq['w' - 'a'] = freq[22]++, so freq[22] = 1.
'a' → freq['a' - 'a'] = freq[0]++, so freq[0] = 2 (as 'a' appears twice).
'r' → freq['r' - 'a'] = freq[17]++, so freq[17] = 2 (as 'r' appears twice).
'd' → freq['d' - 'a'] = freq[3]++, so freq[3] = 1.
After this loop, the freq array looks like:

makefile
Copy code
freq = {2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 1, 1, 0, 1, 0, 0, 0}
Step 3: Print Frequencies

In this step, we iterate through the freq array and print the characters with a non-zero frequency:

Copy code
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
