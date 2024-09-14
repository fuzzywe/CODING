Recursively print all sentences that can be formed from list of word lists
BEST CASE:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive function to print all sentences
void printSentences(vector<vector<string>> &lists, vector<string> &currentSentence, int listIndex) {
    // If we have reached beyond the last list, print the sentence
    if (listIndex == lists.size()) {
        for (const string &word : currentSentence) {
            cout << word << " ";
        }
        cout << endl;
        return;
    }

    // Iterate through each word in the current list and recursively build the sentence
    for (int i = 0; i < lists[listIndex].size(); i++) {
        // Add the current word to the sentence
        currentSentence.push_back(lists[listIndex][i]);
        
        // Recurse for the next list
        printSentences(lists, currentSentence, listIndex + 1);
        
        // Backtrack: remove the last word from the sentence
        currentSentence.pop_back();
    }
}

// Helper function to start the recursion
void generateSentences(vector<vector<string>> &lists) {
    vector<string> currentSentence;
    printSentences(lists, currentSentence, 0);
}

// Main function to test the code
int main() {
    vector<vector<string>> wordLists = {
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}
    };

    cout << "All possible sentences are: " << endl;
    generateSentences(wordLists);

    return 0;
}
1. Main Function (main):
cpp
Copy code
int main() {
    vector<vector<string>> wordLists = {
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}
    };

    cout << "All possible sentences are: " << endl;
    generateSentences(wordLists);

    return 0;
}


Time Complexity:
Let the number of word lists be n, and assume each word list has up to k words.
The time complexity is O(k^n) because for each word list, you need to explore k choices, and there are n word lists.
Space Complexity:
The space complexity is O(n) for storing the current sentence in memory (since there are n word lists).
Additional space is used for the recursion stack, which also goes as deep as n.



EXAMPLE:
Initial State:

lists = {{"I", "You"}, {"love", "hate"}, {"coding", "reading"}}
currentSentence = []
listIndex = 0
First Level of Recursion:

At listIndex = 0, we have the list {"I", "You"}.
We iterate over this list and push each word into currentSentence.
For currentSentence = [], iterate over {"I", "You"}:

Word "I":
Push "I" to currentSentence.
Call printSentences(lists, currentSentence, 1).
Word "You":
Push "You" to currentSentence.
Call printSentences(lists, currentSentence, 1).
Second Level of Recursion:

At listIndex = 1, we have the list {"love", "hate"}.
We iterate over this list.
For currentSentence = ["I"], iterate over {"love", "hate"}:

Word "love":
Push "love" to currentSentence.
Call printSentences(lists, currentSentence, 2).
Word "hate":
Push "hate" to currentSentence.
Call printSentences(lists, currentSentence, 2).
Third Level of Recursion:

At listIndex = 2, we have the list {"coding", "reading"}.
We iterate over this list.
For currentSentence = ["I", "love"], iterate over {"coding", "reading"}:

Word "coding":
Push "coding" to currentSentence.
Call printSentences(lists, currentSentence, 3).
Word "reading":
Push "reading" to currentSentence.
Call printSentences(lists, currentSentence, 3).
Base Case:

At listIndex = 3, which is beyond the last list, we print the sentence.
For currentSentence = ["I", "love", "coding"]:

Print "I love coding".
For currentSentence = ["I", "love", "reading"]:

Print "I love reading".
Repeat for currentSentence = ["I", "hate", "coding"] and currentSentence = ["I", "hate", "reading"].

Backtracking:

After printing, we pop the last word and return to previous recursion levels to try other combinations.
Final Output
Given wordLists = {{"I", "You"}, {"love", "hate"}, {"coding", "reading"}}, the function will output:

css
Copy code
I love coding
I love reading
I hate coding
I hate reading
You love coding
You love reading
You hate coding
You hate reading
Summary of the Example
Starting Point: Begin with the first list.
Recursive Calls: For each word in the current list, recurse into the next list.
Base Case: Print the sentence when all lists are processed.
Backtracking: Remove the last word and try other combinations.
This process generates all possible sentences by exploring every combination of words from each list.


  



This part sets up a 2D vector wordLists, where each inner vector contains a list of words.
It then calls generateSentences to generate all possible sentences from these lists.
2. Helper Function (generateSentences):
cpp
Copy code
void generateSentences(vector<vector<string>> &lists) {
    vector<string> currentSentence;  // To store the current sentence being built
    printSentences(lists, currentSentence, 0);  // Start recursion from listIndex = 0
}
generateSentences starts the process of generating sentences. It initializes an empty currentSentence (which will hold the words of a sentence as it's built).
Then, it calls the recursive function printSentences starting with the first word list (index 0).
3. Recursive Function (printSentences):
cpp
Copy code
void printSentences(vector<vector<string>> &lists, vector<string> &currentSentence, int listIndex) {
    // Base case: if we have reached beyond the last list
    if (listIndex == lists.size()) {
        for (const string &word : currentSentence) {
            cout << word << " ";  // Print the current sentence
        }
        cout << endl;
        return;
    }

    // Iterate through each word in the current word list
    for (int i = 0; i < lists[listIndex].size(); i++) {
        currentSentence.push_back(lists[listIndex][i]);  // Add the current word to the sentence
        printSentences(lists, currentSentence, listIndex + 1);  // Recursively build the next word
        currentSentence.pop_back();  // Backtrack to explore other possibilities
    }
}
listIndex == lists.size(): This is the base case of the recursion. 
  When listIndex reaches the total number of lists (i.e., when you've processed all the word lists),
  it prints the current sentence.
Loop through the current word list: The for-loop goes through each word in the current list
(the list at lists[listIndex]).
Push and pop words:
currentSentence.push_back(lists[listIndex][i]): It adds a word from the current word list to currentSentence.
Then it recursively calls itself (printSentences) to process the next word list (listIndex + 1).
After the recursive call returns, it removes the last word (pop_back) to try the next word from the 

current list. This is called backtracking, and it ensures that all possible combinations of words are explored.
Execution Example:
In the first call, listIndex = 0 and the current list is {"you", "we"}. The function first picks "you", 
  then moves to the next word list.
In the second call, listIndex = 1 and the current list is {"have", "are"}. The function first picks "have",
  then moves to the next word list.
In the third call, listIndex = 2 and the current list is {"sleep", "eat", "drink"}. The function first picks 
"sleep" and reaches the base case. It prints the sentence: "you have sleep".
It backtracks by removing "sleep", tries the next word "eat", prints "you have eat", and so on.
After finishing all possibilities for "you", it tries "we" and repeats the process.

Breaking Down the Code:
Base Case:
When listIndex (current list position) reaches the size of lists, it means
we have picked one word from each list. So, print the sentence.
Recursive Call:
We go through every word in the current list, add it to currentSentence, 
and move to the next list by calling the function recursively.
Backtracking:
After exploring one word and printing the sentence, we remove that word
from currentSentence and try the next word.

  . Start with the first list:
We have the first list {"you", "we"}. We will try each word:
First, try "you".
2. Pick "you" and move to the second list:
Now move to the second list {"have", "are"}. Again, try each word:
First, try "have".
3. Pick "have" and move to the third list:
Now move to the third list {"sleep", "eat", "drink"}:
First, try "sleep".
4. We have a full sentence now:
You have picked one word from each list: "you have sleep".
Print this sentence:
you have sleep
5. Backtrack (Go back and try the next word):
Now, go back to the third list and try the next word:
Try "eat".
Now we have the sentence "you have eat".
Print this sentence:
you have eat
6. Keep backtracking and trying other words:
After trying all words in the third list, go back to the second list:
Now, try "are".
Then go to the third list again and try all words: "sleep", "eat", "drink".
Sentences formed would be:
you are sleep
you are eat
you are drink
7. Backtrack to the first list:
After trying all combinations starting with "you", go back to the first list:
Now, try "we".
Repeat the process for all words in the second and third lists.
Sentences formed would be:
we have sleep
we have eat
we have drink
we are sleep
we are eat
we are drink
Visualization of Backtracking Process:
First path:

"you" -> "have" -> "sleep"
Sentence: you have sleep
Next step (Backtrack to try the next word):

"you" -> "have" -> "eat"
Sentence: you have eat
Continue backtracking:

"you" -> "have" -> "drink"
Sentence: you have drink
Go back to the second list and try "are":

"you" -> "are" -> "sleep"
Sentence: you are sleep
Keep following this process until all combinations are printed.


WORST CASE:
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to recursively form sentences
void printAllSentencesUtil(const vector<vector<string>>& wordLists, int index, vector<string>& currentSentence) {
    // Base case: if the index is equal to the number of word lists, print the current sentence
    if (index == wordLists.size()) {
        for (const string& word : currentSentence) {
            cout << word << " ";
        }
        cout << endl;
        return;
    }

    // Recursive case: iterate over the words in the current word list
    for (int i = 0; i < wordLists[index].size(); i++) {
        // Choose one word from the current list and append it to the current sentence
        currentSentence.push_back(wordLists[index][i]);

        // Recurse to the next word list
        printAllSentencesUtil(wordLists, index + 1, currentSentence);

        // Backtrack: remove the last word added to explore other options
        currentSentence.pop_back();
    }
}

// Wrapper function to call the recursive utility function
void printAllSentences(const vector<vector<string>>& wordLists) {
    // Vector to hold the current sentence as we build it
    vector<string> currentSentence;

    // Call the recursive utility function starting from the first word list
    printAllSentencesUtil(wordLists, 0, currentSentence);
}

int main() {
    // Example of word lists (in the worst case, all lists could have multiple words)
    vector<vector<string>> wordLists = {
        {"you", "we"},    // 2 words
        {"have", "are"},  // 2 words
        {"sleeping", "eating", "playing"}  // 3 words
    };

    cout << "All possible sentences:\n";
    printAllSentences(wordLists);

    return 0;
}
ime Complexity (Worst Case):

In the worst case, the number of possible sentences is the product of the number of words in each list.
If there are n word lists, each containing m words, the number of possible sentences is O(m^n).
Space Complexity (Worst Case):

The recursive depth is O(n) (due to the recursion stack and currentSentence storing up to n words).
If we include the space for storing the output (the sentences), the space complexity is also O(m^n).
