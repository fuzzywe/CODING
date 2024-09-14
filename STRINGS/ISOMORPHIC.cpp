Input:  str1 = “aab”, str2 = “xxy”
Output: True
Explanation: ‘a’ is mapped to ‘x’ and ‘b’ is mapped to ‘y’.

Input:  str1 = “aab”, str2 = “xyz”
Output: False
Explanation: One occurrence of ‘a’ in str1 has ‘x’ in str2 and other occurrence of ‘a’ has ‘y’.

worst case:
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// Function to check if two strings are isomorphic
bool areIsomorphic(string str1, string str2)
{
    int m = str1.length(), n = str2.length();

    // Length of both strings must be the same
    if (m != n)
        return false;

    // Array to mark visited characters in str2
    bool marked[MAX_CHARS] = { false };

    // Array to store mapping of characters from str1 to str2
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));

    // Process each character of the strings
    for (int i = 0; i < n; i++) {
        // If current character of str1 is seen for the first time
        if (map[str1[i]] == -1) {
            // If current character of str2 is already mapped, return false
            if (marked[str2[i]] == true)
                return false;

            // Mark the character of str2 as visited
            marked[str2[i]] = true;

            // Store the mapping
            map[str1[i]] = str2[i];
        }

        // If character in str1 has been seen before, check mapping
        else if (map[str1[i]] != str2[i])
            return false;
    }

    return true;
}

// Main function to test the isomorphic check
int main()
{
    cout << (areIsomorphic("aab", "xxy") ? "True" : "False") << endl;
    return 0;
}


Time Complexity: O(N), Traversing over the string of size N
Auxiliary Space: O(1)

  
// Array to store mapping of characters from str1 to str2
int map[MAX_CHARS];
memset(map, -1, sizeof(map));
perform the following actions:

1. Declaration of the map Array
cpp
Copy code
int map[MAX_CHARS];
Purpose: This line declares an array named map with a size of MAX_CHARS (256). This array is used to store the mapping from characters in str1 to characters in str2.
Type: The array is of type int, and each element is an integer.
2. Initialization with memset
cpp
Copy code
memset(map, -1, sizeof(map));
Purpose: This line initializes the entire map array to -1. It sets every element in the map array to -1 to indicate that no character mappings have been made yet.
Details of memset
Function: memset is a C++ standard library function used to fill a block of memory with a specific value.
Parameters:
Pointer to the memory block: map - This is the starting address of the array.
Value to set: -1 - This is the value to be set in every element of the array.
Size of the memory block: sizeof(map) - This specifies the number of bytes to be set. sizeof(map) gives the total size in bytes of the map array.
Why -1?
Indicates Unmapped Characters: Setting the value to -1 is a way to mark that no mapping has been assigned yet for any character. If a character is mapped, its corresponding entry in the map array will be updated to reflect the mapped character.
Example
Let’s say MAX_CHARS is 256, so map will have 256 elements. Initially, after memset:

cpp
Copy code
map[0] = -1;
map[1] = -1;
...
map[255] = -1;
Each index in the map array corresponds to an ASCII value of a character. For example, if str1[i] = 'a' and str2[i] = 'x', and we map 'a' to 'x', then:

cpp
Copy code
map['a'] = 'x'; // map[97] = 'x' (ASCII value of 'a' is 97)
This way, the map array is used to store and track the mappings from str1 characters to str2 characters throughout the isomorphism check process.

Summary
Declaration: map is an integer array sized to hold all possible ASCII characters.
Initialization: memset sets all elements of the map array to -1, which signifies that no mappings have been established at the start.
Usage: This initialization helps in determining if a character has been mapped or not during the isomorphism check.

Initialization:

str1 = "aab"
str2 = "xxy"
m = 3 (length of str1)
n = 3 (length of str2)
Since the lengths are equal, we proceed.

Arrays:

marked[MAX_CHARS] = { false } - Keeps track of characters in str2 that have already been mapped.
map[MAX_CHARS] - Stores mappings from str1 to str2, initialized to -1.
Processing Characters:

Iteration 1 (i = 0):

str1[0] = 'a'
str2[0] = 'x'
map['a'] is -1 (not yet mapped), so:
marked['x'] is false (not yet visited).
Map 'a' to 'x': map['a'] = 'x'.
Mark 'x' as visited: marked['x'] = true.
Iteration 2 (i = 1):

str1[1] = 'a'
str2[1] = 'x'
map['a'] is 'x' (previously mapped).
Since map['a'] == 'x', continue.
Iteration 3 (i = 2):

str1[2] = 'b'
str2[2] = 'y'
map['b'] is -1 (not yet mapped), so:
marked['y'] is false (not yet visited).
Map 'b' to 'y': map['b'] = 'y'.
Mark 'y' as visited: marked['y'] = true.
Final Check:

All characters are processed, and mappings are consistent.
The function returns true, indicating the strings are isomorphic.
Why It's Non-Optimal
Fixed-size Arrays: Using arrays of fixed size (256) for ASCII characters consumes unnecessary memory 
if the character set is smaller.
Lack of Dynamic Handling: This method does not handle Unicode or other extended character
sets efficiently. For more complex or 
variable character sets, a hash map or dynamic data structure would be more appropriate.
This non-optimal solution is simple and easy to understand but lacks flexibility and efficiency compared to using hash maps or other dynamic data structures for mapping.

  best case:
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to check if two strings are isomorphic
bool areIsomorphic(string str1, string str2) {
    // Length of both strings must be the same
    if (str1.length() != str2.length()) {
        return false;
    }

    // Maps to store the character mappings from str1 to str2 and vice versa
    unordered_map<char, char> map1;
    unordered_map<char, char> map2;

    for (int i = 0; i < str1.length(); ++i) {
        char char1 = str1[i];
        char char2 = str2[i];

        // Check mapping from str1 to str2
        if (map1.find(char1) != map1.end()) {
            if (map1[char1] != char2) {
                return false;
            }
        } else {
            map1[char1] = char2;
        }

        // Check mapping from str2 to str1
        if (map2.find(char2) != map2.end()) {
            if (map2[char2] != char1) {
                return false;
            }
        } else {
            map2[char2] = char1;
        }
    }

    return true;
}

// Main function to test the isomorphic check
int main() {
    // Example strings for worst-case scenario
    string str1 = "aab";
    string str2 = "yyx";

    if (areIsomorphic(str1, str2)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
Explanation
Initialization: Two unordered_map structures are used to keep track of the mappings between characters of the two strings.
Mapping Check: For each character in str1, we check if it has already been mapped to a character in str2. Similarly, 
for each character in str2, we check if it has already been mapped from a character in str1.
Unique Mapping: We ensure that each character in str1 maps uniquely to a character in str2, and each character in 
str2 maps uniquely to a character in str1.
Complexity Analysis
Time Complexity: O(n), where n is the length of the strings. We iterate over the strings once, and operations 
in the hash maps are O(1) on average.
Space Complexity: O(1) (excluding input size), as the number of unique characters (e.g., 256 for ASCII)
is constant and the space required for the maps is 
proportional to the number of unique characters, which is bounded. 
   

### **What Does Isomorphic Mean?**
Two strings are isomorphic if you can map each character in the first string to exactly one character in the second string, and vice versa, while preserving the order of characters. In other words:
- No two characters in the first string should map to the same character in the second string.
- Similarly, no two characters in the second string should map to the same character in the first string.

### 

- `str1 = "abcabc"`
- `str2 = "xyzxyz"`

In this case, the two strings are isomorphic because:
- 'a' in `str1` maps to 'x' in `str2`.
- 'b' in `str1` maps to 'y' in `str2`.
- 'c' in `str1` maps to 'z' in `str2`.

Here's how the code works for these strings:

1. **Initialization**:
   - The lengths of both strings are checked. If they are not equal, the strings are immediately determined to not be isomorphic.
   - Two maps (`map1` and `map2`) are created to store character mappings between the two strings.

2. **Iteration**:
   - We iterate through each character in the two strings, comparing the corresponding characters at each position.
   
3. **First Iteration** (`i = 0`):
   - `char1 = 'a'` from `str1` and `char2 = 'x'` from `str2`.
   - Since 'a' is not yet mapped in `map1`, the code stores the mapping `'a' -> 'x'` in `map1`.
   - Similarly, 'x' is not yet mapped in `map2`, so it stores the mapping `'x' -> 'a'` in `map2`.

4. **Second Iteration** (`i = 1`):
   - `char1 = 'b'` from `str1` and `char2 = 'y'` from `str2`.
   - 'b' is not yet mapped in `map1`, so the mapping `'b' -> 'y'` is stored in `map1`.
   - 'y' is not yet mapped in `map2`, so the mapping `'y' -> 'b'` is stored in `map2`.

5. **Third Iteration** (`i = 2`):
   - `char1 = 'c'` from `str1` and `char2 = 'z'` from `str2`.
   - 'c' is not yet mapped in `map1`, so the mapping `'c' -> 'z'` is stored in `map1`.
   - 'z' is not yet mapped in `map2`, so the mapping `'z' -> 'c'` is stored in `map2`.

6. **Fourth Iteration** (`i = 3`):
   - `char1 = 'a'` from `str1` and `char2 = 'x'` from `str2`.
   - 'a' is already mapped to 'x' in `map1` and 'x' is already mapped to 'a' in `map2`, so the check continues.

7. **Fifth Iteration** (`i = 4`):
   - `char1 = 'b'` from `str1` and `char2 = 'y'` from `str2`.
   - 'b' is already mapped to 'y' in `map1` and 'y' is already mapped to 'b' in `map2`, so the check continues.

8. **Sixth Iteration** (`i = 5`):
   - `char1 = 'c'` from `str1` and `char2 = 'z'` from `str2`.
   - 'c' is already mapped to 'z' in `map1` and 'z' is already mapped to 'c' in `map2`, so the check continues.

At the end of the iteration, the strings are found to be isomorphic because all the character mappings are consistent.

### **Example of a Non-Isomorphic Case**

Consider `str1 = "foo"` and `str2 = "bar"`. In this case, the strings are **not** isomorphic. Here's why:

1. **First Iteration**: 'f' in `str1` maps to 'b' in `str2`.
2. **Second Iteration**: 'o' in `str1` maps to 'a' in `str2`.
3. **Third Iteration**: 'o' in `str1` should map to 'r' in `str2`, but it was previously mapped to 'a'. This inconsistency means the strings are not isomorphic.

// Check mapping from str1 to str2
if (map1.find(char1) != map1.end()) {
    if (map1[char1] != char2) {
        return false;
    }
}
Let's take two strings:

str1 = "foo"
str2 = "bar"
When the loop reaches the second 'o' in str1 and the second 'a' in str2, here's what happens:

First Iteration (i = 0):
char1 = 'f' from str1 and char2 = 'b' from str2.
map1['f'] is not set yet, so we set map1['f'] = 'b'.
Second Iteration (i = 1):
char1 = 'o' from str1 and char2 = 'a' from str2.
map1['o'] is not set yet, so we set map1['o'] = 'a'.
Third Iteration (i = 2):
char1 = 'o' from str1 and char2 = 'r' from str2.
Now, map1['o'] already exists, and it's mapped to 'a', but the current char2 is 'r'. Since 'o' has already been mapped to 'a' (not 'r'), this inconsistency is detected, and the function returns false.
Summary:
The code checks if char1 has already been mapped.
If it has been mapped, it verifies whether the previous mapping matches the current char2.
    If it doesn't, it returns false, indicating that the strings are not isomorphic.







Strings:
str1 = "paper"
str2 = "title"
We want to check if these two strings are isomorphic, meaning if there's a one-to-one mapping between the characters of str1 and str2.


Step-by-Step:
1st Iteration (i = 0):
Characters:
char1 = 'p' (from str1)
char2 = 't' (from str2)
Check Mapping from str1 to str2:
map1['p'] does not exist yet.
Map 'p' to 't': map1['p'] = 't'.
Check Mapping from str2 to str1:
map2['t'] does not exist yet.
Map 't' to 'p': map2['t'] = 'p'.
2nd Iteration (i = 1):
Characters:
char1 = 'a' (from str1)
char2 = 'i' (from str2)
Check Mapping from str1 to str2:
map1['a'] does not exist yet.
Map 'a' to 'i': map1['a'] = 'i'.
Check Mapping from str2 to str1:
map2['i'] does not exist yet.
Map 'i' to 'a': map2['i'] = 'a'.
3rd Iteration (i = 2):
Characters:
char1 = 'p' (from str1)
char2 = 't' (from str2)
Check Mapping from str1 to str2:
map1['p'] already exists and is mapped to 't'.
Since char2 = 't', this is consistent, so we proceed.
Check Mapping from str2 to str1:
map2['t'] already exists and is mapped to 'p'.
This is also consistent, so we move on to the next iteration.
4th Iteration (i = 3):
Characters:
char1 = 'e' (from str1)
char2 = 'l' (from str2)
Check Mapping from str1 to str2:
map1['e'] does not exist yet.
Map 'e' to 'l': map1['e'] = 'l'.
Check Mapping from str2 to str1:
map2['l'] does not exist yet.
Map 'l' to 'e': map2['l'] = 'e'.
5th Iteration (i = 4):
Characters:
char1 = 'r' (from str1)
char2 = 'e' (from str2)
Check Mapping from str1 to str2:
map1['r'] does not exist yet.
Map 'r' to 'e': map1['r'] = 'e'.
Check Mapping from str2 to str1:
map2['e'] does not exist yet.
Map 'e' to 'r': map2['e'] = 'r'.

Mappings at the End:
map1 (from str1 to str2):
'p' -> 't'
'a' -> 'i'
'e' -> 'l'
'r' -> 'e'
map2 (from str2 to str1):
't' -> 'p'
'i' -> 'a'
'l' -> 'e'
'e' -> 'r'
Final Output:
The strings "paper" and "title" are isomorphic.
