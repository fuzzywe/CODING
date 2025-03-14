```cpp

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

```

---

This C++ program calculates and prints the frequency of each character in a given string. Let’s break it down step by step to understand how it works.

---

### Code Explanation:

#### 1. **Header Files and Namespace**
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
```
- `#include <iostream>`: Includes the input/output library for using `cin` and `cout`.
- `#include <algorithm>`: Includes the algorithm library for using the `sort()` function.
- `using namespace std;`: Allows us to use standard library functions (like `cout`, `sort`, etc.) without the `std::` prefix.

---

#### 2. **Function: `Printfrequency(string str)`**
This function takes a string `str` as input and prints the frequency of each character in the string.

```cpp
void Printfrequency(string str)
{
  sort(str.begin(), str.end()); // Sort the string
  char ch = str[0]; // Initialize with the first character
  int count = 1; // Initialize count for the first character
```

- **`sort(str.begin(), str.end());`**:
  - Sorts the string in **ascending order** of characters.
  - For example, if `str = "takeuforward"`, after sorting, it becomes `"aadeefkorrtuw"`.

- **`char ch = str[0];`**:
  - Initializes `ch` with the first character of the sorted string.

- **`int count = 1;`**:
  - Initializes `count` to 1 because the first character has already appeared once.

---

#### 3. **Loop Through the Sorted String**
```cpp
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch) // If the current character matches the previous character
      count++; // Increment the count
    else
    {
      cout << ch << count << " "; // Print the character and its count
      count = 1; // Reset the count for the new character
      ch = str[i]; // Update `ch` to the new character
    }
  }
  cout << ch << count << " "; // Print the last character and its count
}
```

- **`for (int i = 1; i < str.length(); i++)`**:
  - Loops through the sorted string starting from the second character (index 1).

- **`if (str[i] == ch)`**:
  - If the current character (`str[i]`) is the same as the previous character (`ch`), increment the `count`.

- **`else`**:
  - If the current character is different from the previous character:
    - Print the previous character (`ch`) and its count (`count`).
    - Reset `count` to 1 for the new character.
    - Update `ch` to the new character.

- **`cout << ch << count << " ";`**:
  - After the loop ends, print the last character and its count.

---

#### 4. **Main Function**
```cpp
int main()
{
  string str = "takeuforward";
  Printfrequency(str); // Call the function
  return 0;
}
```

- **`string str = "takeuforward";`**:
  - Initializes the string `str` with the value `"takeuforward"`.

- **`Printfrequency(str);`**:
  - Calls the `Printfrequency()` function to calculate and print the frequency of each character in the string.

---

### How It Works:
1. The string `"takeuforward"` is sorted to `"aadeefkorrtuw"`.
2. The function iterates through the sorted string and counts the frequency of each character:
   - `a` appears 2 times.
   - `d` appears 1 time.
   - `e` appears 1 time.
   - `f` appears 1 time.
   - `k` appears 1 time.
   - `o` appears 1 time.
   - `r` appears 2 times.
   - `t` appears 1 time.
   - `u` appears 1 time.
   - `w` appears 1 time.
3. The function prints the frequency of each character.

---

### Output:
For the input string `"takeuforward"`, the output will be:
```
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
```

---

### Key Points:
1. **Sorting**:
   - Sorting the string ensures that all occurrences of the same character are grouped together, making it easier to count their frequency.

2. **Counting**:
   - The function uses a loop to count the frequency of each character by comparing it with the previous character.

3. **Edge Case**:
   - The last character and its count are printed after the loop ends.

---

### Example Walkthrough:
Let’s walk through the function step by step for the string `"takeuforward"`.

#### Step 1: Sort the String
- Original string: `"takeuforward"`
- Sorted string: `"aadeefkorrtuw"`

#### Step 2: Initialize Variables
- `ch = 'a'` (first character)
- `count = 1`

#### Step 3: Loop Through the Sorted String
| Index (`i`) | Character (`str[i]`) | `ch` | `count` | Action                          |
|-------------|-----------------------|------|---------|---------------------------------|
| 1           | `'a'`                 | `'a'`| 2       | Increment `count`               |
| 2           | `'d'`                 | `'a'`| 2       | Print `'a'` and `2`, reset `count` to 1, update `ch` to `'d'` |
| 3           | `'e'`                 | `'d'`| 1       | Print `'d'` and `1`, reset `count` to 1, update `ch` to `'e'` |
| 4           | `'e'`                 | `'e'`| 2       | Increment `count`               |
| 5           | `'f'`                 | `'e'`| 2       | Print `'e'` and `2`, reset `count` to 1, update `ch` to `'f'` |
| 6           | `'k'`                 | `'f'`| 1       | Print `'f'` and `1`, reset `count` to 1, update `ch` to `'k'` |
| 7           | `'o'`                 | `'k'`| 1       | Print `'k'` and `1`, reset `count` to 1, update `ch` to `'o'` |
| 8           | `'r'`                 | `'o'`| 1       | Print `'o'` and `1`, reset `count` to 1, update `ch` to `'r'` |
| 9           | `'r'`                 | `'r'`| 2       | Increment `count`               |
| 10          | `'t'`                 | `'r'`| 2       | Print `'r'` and `2`, reset `count` to 1, update `ch` to `'t'` |
| 11          | `'u'`                 | `'t'`| 1       | Print `'t'` and `1`, reset `count` to 1, update `ch` to `'u'` |
| 12          | `'w'`                 | `'u'`| 1       | Print `'u'` and `1`, reset `count` to 1, update `ch` to `'w'` |

#### Step 4: Print the Last Character
- After the loop ends, print `'w'` and its count (`1`).

---

### Final Output:
```
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
```

---

Let me know if you have further questions! 😊


```cpp

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

```
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
