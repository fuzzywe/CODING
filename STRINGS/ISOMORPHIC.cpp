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
    string str1 = "abcdefghijklmnopqrstuvwxyza";
    string str2 = "zyxwvutsrqponmlkjihgfedcba";

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
