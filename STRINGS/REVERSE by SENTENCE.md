
https://leetcode.com/problems/reverse-words-in-a-string/description/

```cpp

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }
};

```


Okay, let's break down this C++ code for reversing words in a string step by step. I'll add comments to the code to explain each section, and then provide a more detailed explanation afterwards.



text
class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;   // Start index of the current word
        int right = 0;  // End index (exclusive) of the current word being built
        int i = 0;      // Main iterator through the string

        while (i < n) {
            // 2. Skip leading spaces
            while (i < n && s[i] == ' ')
                i++;

            // 3. If we reached the end after skipping spaces, break
            if (i == n)
                break;

            // 4. Copy a word from the reversed string to the correct place
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // 5. Reverse the extracted word
            reverse(s.begin() + left, s.begin() + right);

            // 6. Add a space after the word
            s[right++] = ' ';

            // 7. Update the start index of the next word
            left = right;

            // 8. Move past the space that ended the previous word in the original reversed string
            i++;
        }

        // 9. Remove the trailing space
        s.resize(right - 1);

        return s;
    }
};



Explanation


The reverseWords function reverses the order of words in a given string s. Here's a breakdown of the code:




Reverse the Entire String:




reverse(s.begin(), s.end());




This line reverses the entire string. For example, if the input is "the sky is blue", after this step, s becomes "eulb si yks eht".






Skip Leading Spaces:




while (i < n && s[i] == ' ') i++;




This loop skips any leading spaces in the (reversed) string. The variable i is the main iterator that moves through the string.






Break if End Reached:




if (i == n) break;




If, after skipping spaces, we've reached the end of the string, it means there are no more words to process, so we exit the loop.






Copy a Word:




while (i < n && s[i] != ' ') { s[right++] = s[i++]; }




This loop copies characters of a word from the reversed string (starting at index i) to the beginning of the string (starting at index right).  The right variable keeps track of where to place the next character of the reversed word. i advances through the reversed string.




For example, if s is "eulb si yks eht", this loop will copy "eulb" to the beginning of the string.






Reverse the Extracted Word:




reverse(s.begin() + left, s.begin() + right);




This line reverses the word that was just copied. left marks the beginning of the current word, and right marks the end (exclusive). In our example, "eulb" becomes "blue".






Add a Space:




s[right++] = ' ';




A space is added after the reversed word.






Update left:




left = right;




The left pointer is updated to the current position of right, which is the start of the next word.






Move Past Space in Original String:




i++;




Move i to the next character in the original reversed string, skipping the space after the word.






Remove Trailing Space:




s.resize(right - 1);




After the loop finishes, there might be a trailing space at the end of the string. This line removes that trailing space by resizing the string to exclude the last character.






Example Walkthrough


Let's trace the example "the sky is blue":




Initial: s = "the sky is blue"




Reverse entire string: s = "eulb si yks eht"




Loop:




"eulb": Copied and then reversed to "blue". s becomes "blue ". left and right are updated.




"si": Copied and then reversed to "is". s becomes "blue is ".




"yks": Copied and then reversed to "sky". s becomes "blue is sky ".




"eht": Copied and then reversed to "the". s becomes "blue is sky the ".






Remove trailing space: s becomes "blue is sky the".




In Summary


The code efficiently reverses the words in a string by first reversing the entire string and then iterating through it, extracting and reversing each word individually. The use of left and right pointers helps to keep track of the start and end of each word. The resize call at the end cleans up any trailing spaces.

Answer from Perplexity: https://www.perplexity.ai/search/class-solution-public-string-r-bWR3xmRITjiDlIg5hHeIkg?utm_source=copy_output
