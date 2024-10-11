related to no of islands question 
Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false



Complexity
Time complexity: O(m∗n∗4 en(word))
Space complexity: O(4 len(word))


```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<string> visited;

        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            if (k == word.length()) {
                return true;
            }

            if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(to_string(r) + "," + to_string(c)) || board[r][c] != word[k]) {
                return false;
            }

            visited.insert(to_string(r) + "," + to_string(c));
            bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(to_string(r) + "," + to_string(c));
            return res;
        };

        unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }

        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0, dfs)) {
                    return true;
                }
            }
        }

        return false;        
    }
};
```
Approach
Simply check 4 directions from every place and if we find the next target character, then move to that place.

But problem is that we don't know current length of path(= word), so every time we move to a new place, count 1 as a length of path, so that when the path length is equal to input word, we can return True.

Discussion points
imagine this metrics and a word.

["A","A","A","A"]
["A","A","A","B"]
["A","A","B","A"]

word = "AAAAAAAABB"
If we check the word from beginning(= A), we have to move a lot of places. But if we start from end(= B), we can immediately return False in many places.

This is depends on input word, but we might reverse the input word if number of the first character is greater than number of the last character.

I implemented that logic. I think it's a good point to discuss with interviewers in real interview.
