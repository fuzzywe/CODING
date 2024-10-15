https://leetcode.com/problems/longest-word-in-dictionary/solutions/

720. Longest Word in Dictionary
Medium
Topics
Companies
Hint
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 

 

Example 1:

Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Intuition
Trie dfs traversal

Complexity
Time complexity: O(sumoflengthofallwords)

Space complexity:O(sumoflengthofallwords)
```cpp
class Solution {

    struct Trie {
        vector<Trie*> children;
        bool isEndOfWord;
        Trie() {
            children.resize(26, nullptr);
            isEndOfWord = false;
        }
    }*root;

    void insertToTrie(string &word) {
        Trie* currentNode = root;
        for(char &c : word) {
            if(!currentNode->children[c-'a']) {
                currentNode->children[c-'a'] = new Trie();
            }
            currentNode = currentNode->children[c-'a'];
        }
        currentNode->isEndOfWord = true;
    }

    void traverse(Trie* currentNode, string &cur, string &res) {
        if(cur.size()>res.size()) {
            res = cur;
        }
        for(int i=0;i<26;i++) {
            if(currentNode->children[i] && currentNode->children[i]->isEndOfWord) {
                cur.push_back('a'+i);
                traverse(currentNode->children[i], cur, res);
                cur.pop_back();
            }
        }
    }

public:
    string longestWord(vector<string>& words) {
        root = new Trie();
        for(string &word : words) {
            insertToTrie(word);
        }
        string res, cur;
        traverse(root, cur, res);
        return res;
    }
};

```


