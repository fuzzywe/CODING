Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
brute force 
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // Iterate through each word in the vector
        for(int i = 0; i < words.size(); i++) {
            // Store the word and its reverse
            string original = words[i];
            string reversed = original;
            reverse(reversed.begin(), reversed.end()); // Reverse the word
            
            // Check if the original word is equal to the reversed word
            if(original == reversed) {
                return original; // Return the first palindrome found
            }
        }
        return ""; // If no palindrome is found, return an empty string
    }
};

Time Complexity: 

O(m×n), where m is the number of words, and n is the average length of the words.
Space Complexity: 

O(n), where n is the length of the longest word.

best soln:
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0 ; i < words.size() ; i++)
        {
            int flag = 0;
            int n = words[i].size();
            for(int j = 0 ; j < n/2 ; j++)
            {
                if(words[i][j] != words[i][n-j-1])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                return words[i];
                
        }
        return "";
    }
};

Loop through each word:
for(int i = 0 ; i < words.size() ; i++) loops over all the words in the vector words. i is the index of each word.
Checking if the word is a palindrome:
The variable flag is initialized to 0. This will help us keep track of whether the current word is a palindrome.
n = words[i].size() stores the length of the current word.
The inner loop for(int j = 0 ; j < n/2 ; j++) checks if the characters in the first half of the word match the corresponding characters in the second half. If any mismatch is found, the word is not a palindrome.
words[i][j] != words[i][n-j-1] compares the character at the beginning of the word (j) with the character at the end (n-j-1).
If they are not equal, flag = 1 is set, and the inner loop breaks since it's not a palindrome.
Return the first palindrome:
After the inner loop finishes, if flag == 0, it means the word is a palindrome, and the function returns it (return words[i]).
If no palindrome is found after checking all the words, the function returns an empty string "".
Example:
Let's use an example to understand the flow.

cpp
Copy code
vector<string> words = {"abc", "madam", "hello"};
Iteration 1: i = 0, word = "abc"
Length n = 3. Check if "abc" is a palindrome.
Compare words[0][0] == words[0][2], which is 'a' != 'c'. So, flag = 1, and this word is not a palindrome.
Iteration 2: i = 1, word = "madam"
Length n = 5. Check if "madam" is a palindrome.
Compare words[1][0] == words[1][4] ('m' == 'm') -> true.
Compare words[1][1] == words[1][3] ('a' == 'a') -> true.
The inner loop finishes without setting flag = 1, so "madam" is a palindrome.
The function returns "madam" and stops further checking.
Output:
For the input {"abc", "madam", "hello"}, the function will return "madam", as it's the first palindrome in the list.
