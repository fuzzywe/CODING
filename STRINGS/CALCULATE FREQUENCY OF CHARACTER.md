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
This C++ program calculates and prints the frequency of each character in a given string using an array to store the frequency of each letter. Let’s break it down step by step to understand how it works.

---

### Code Explanation:

#### 1. **Header File and Namespace**
```cpp
#include <iostream>
using namespace std;
```
- `#include <iostream>`: Includes the input/output library for using `cin` and `cout`.
- `using namespace std;`: Allows us to use standard library functions (like `cout`) without the `std::` prefix.

---

#### 2. **Function: `Printfrequency(string str)`**
This function takes a string `str` as input and prints the frequency of each character in the string.

```cpp
void Printfrequency(string str)
{
  int freq[26] = {0}; // Initialize an array to store frequency of each letter
```

- **`int freq[26] = {0};`**:
  - Declares an array `freq` of size 26 (one for each letter in the English alphabet) and initializes all elements to `0`.
  - The index `0` corresponds to `'a'`, `1` corresponds to `'b'`, ..., `25` corresponds to `'z'`.

---

#### 3. **Count the Frequency of Each Character**
```cpp
  for (int i = 0; i < str.length(); i++)
  {
    freq[str[i] - 'a']++; // Increment the count for the corresponding letter
  }
```

- **`for (int i = 0; i < str.length(); i++)`**:
  - Loops through each character in the string `str`.

- **`freq[str[i] - 'a']++;`**:
  - `str[i] - 'a'` calculates the index of the current character in the `freq` array.
    - For example:
      - If `str[i] = 'a'`, then `'a' - 'a' = 0`.
      - If `str[i] = 'b'`, then `'b' - 'a' = 1`.
      - If `str[i] = 'z'`, then `'z' - 'a' = 25`.
  - `freq[str[i] - 'a']++` increments the count for the corresponding letter.

---

#### 4. **Print the Frequency of Each Character**
```cpp
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0) // If the letter appears at least once
    {
      cout << (char)(i + 'a') << freq[i] << " "; // Print the letter and its frequency
    }
  }
}
```

- **`for (int i = 0; i < 26; i++)`**:
  - Loops through the `freq` array (indices `0` to `25`).

- **`if (freq[i] != 0)`**:
  - Checks if the current letter appears at least once in the string.

- **`cout << (char)(i + 'a') << freq[i] << " ";`**:
  - `(char)(i + 'a')` converts the index back to the corresponding letter.
    - For example:
      - If `i = 0`, then `(char)(0 + 'a') = 'a'`.
      - If `i = 1`, then `(char)(1 + 'a') = 'b'`.
      - If `i = 25`, then `(char)(25 + 'a') = 'z'`.
  - `freq[i]` is the frequency of the current letter.
  - Prints the letter and its frequency.

---

#### 5. **Main Function**
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
1. The string `"takeuforward"` is processed character by character.
2. The frequency of each letter is counted and stored in the `freq` array.
3. The function iterates through the `freq` array and prints the frequency of each letter that appears at least once.

---

### Output:
For the input string `"takeuforward"`, the output will be:
```
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
```

---

### Key Points:
1. **Array Initialization**:
   - The `freq` array is initialized to `0` for all 26 letters.

2. **Character to Index Mapping**:
   - `str[i] - 'a'` maps each character to an index between `0` and `25`.

3. **Frequency Counting**:
   - The frequency of each letter is counted by incrementing the corresponding index in the `freq` array.

4. **Printing**:
   - Only letters with a frequency greater than `0` are printed.

---

### Example Walkthrough:
Let’s walk through the function step by step for the string `"takeuforward"`.

#### Step 1: Initialize the `freq` Array
```
freq = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

#### Step 2: Count the Frequency of Each Character
| Character (`str[i]`) | Index (`str[i] - 'a'`) | `freq` Array After Increment |
|-----------------------|-------------------------|------------------------------|
| `'t'`                 | 19                      | `freq[19] = 1`               |
| `'a'`                 | 0                       | `freq[0] = 1`                |
| `'k'`                 | 10                      | `freq[10] = 1`               |
| `'e'`                 | 4                       | `freq[4] = 1`                |
| `'u'`                 | 20                      | `freq[20] = 1`               |
| `'f'`                 | 5                       | `freq[5] = 1`                |
| `'o'`                 | 14                      | `freq[14] = 1`               |
| `'r'`                 | 17                      | `freq[17] = 1`               |
| `'w'`                 | 22                      | `freq[22] = 1`               |
| `'a'`                 | 0                       | `freq[0] = 2`                |
| `'r'`                 | 17                      | `freq[17] = 2`               |
| `'d'`                 | 3                       | `freq[3] = 1`                |

#### Step 3: Final `freq` Array
```
freq = [2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 1, 1, 0, 1, 0, 0, 0]
```

#### Step 4: Print the Frequency of Each Letter
| Index (`i`) | Letter (`(char)(i + 'a')`) | Frequency (`freq[i]`) | Output |
|-------------|----------------------------|------------------------|--------|
| 0           | `'a'`                      | 2                      | `a2`   |
| 3           | `'d'`                      | 1                      | `d1`   |
| 4           | `'e'`                      | 1                      | `e1`   |
| 5           | `'f'`                      | 1                      | `f1`   |
| 10          | `'k'`                      | 1                      | `k1`   |
| 14          | `'o'`                      | 1                      | `o1`   |
| 17          | `'r'`                      | 2                      | `r2`   |
| 19          | `'t'`                      | 1                      | `t1`   |
| 20          | `'u'`                      | 1                      | `u1`   |
| 22          | `'w'`                      | 1                      | `w1`   |

---

### Final Output:
```
a2 d1 e1 f1 k1 o1 r2 t1 u1 w1
```

---

### Advantages of This Approach:
1. **Efficiency**:
   - The time complexity is \(O(n)\), where \(n\) is the length of the string.
   - The space complexity is \(O(1)\) because the `freq` array has a fixed size of 26.

2. **Simplicity**:
   - The logic is straightforward and easy to understand.

3. **No Sorting**:
   - Unlike the previous approach, this method does not require sorting the string.

---

Let me know if you have further questions! 😊
