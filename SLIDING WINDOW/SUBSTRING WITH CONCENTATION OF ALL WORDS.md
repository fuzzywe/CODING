30. Substring with Concatenation of All Words

https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

---
Intuition
The problem requires us to find all starting indices in a string s where a concatenation of all words in words (in any order) forms a valid substring. Each word in words is of the same length. The key insight is to treat this as a sliding window problem:

The window size should match the total length of the concatenation of all words (i.e., word_count * word_length).
As we slide this window across the string, we check whether the words in the current window match the exact count of the words in the words list.
Approach
We use a sliding window and hash maps to keep track of the counts of each word and check if substrings match the concatenation.

Initialize word frequency map:
We first create an unordered map counts that stores the frequency of each word in the words list.
Sliding Window:
We slide over the string s with a window of size total length of all words. This window slides in steps of the length of a single word to make sure we capture exact word boundaries.
For each possible starting point, we check if the substring formed by the concatenation of words exists. We maintain a secondary map mp to count the occurrences of words in the current window.
Handle Overlaps:
If a word appears more times than allowed (as per the counts map), we move the starting point of the window forward until the word count is valid again.
Check if a valid substring is found:
If the count of words in the window matches the number of words in words (i.e., all words are used exactly once), we record the starting index.
Complexity
Time complexity: O(n *word_length), where n is the length of the string s and word_length is the length of each word in words.

Space complexity: O(m) where m is the number of unique words in words.

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> counts;
        for (int i = 0; i < words.size(); i++)
            counts[words[i]]++;

        int n = s.length();
        int wordsize = words.size();
        int len = words[0].size();
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int start = i, count = 0;
            unordered_map<string, int> mp;
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                if (counts.find(word) != counts.end()) {
                    mp[word]++;
                    count++;

                    while (mp[word] > counts[word]) {
                        string leftword = s.substr(start, len);
                        mp[leftword]--;
                        count--;
                        start += len;
                    }
                    if (count == wordsize)
                        ans.push_back(start);
                } else {
                    mp.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return ans;
    }
};
```
