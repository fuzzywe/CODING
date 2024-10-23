127. Word Ladder

https://leetcode.com/problems/word-ladder/description/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

---
The **Word Ladder** problem is about finding the shortest transformation sequence from a **beginWord** to an **endWord** by changing only one letter at a time. Each transformation must be a valid word from a given dictionary **wordList**, and each transformed word must differ from the previous one by exactly one letter.

### Problem Breakdown:
1. **beginWord**: This is the starting word.
2. **endWord**: This is the final target word. We want to transform the **beginWord** into the **endWord**.
3. **wordList**: A list of valid words that we can use during the transformation process. Note that every transformed word (except for the beginWord) must be from this list.

### Rules:
- Each transformation can change only **one letter** at a time.
- The new word generated after each transformation must exist in the **wordList**.
- The **endWord** must also be in the **wordList** to form a valid sequence.
- The output should be the length of the shortest sequence of transformations. If there is no valid transformation, return `0`.

### Approach to Solve:
The best way to solve this problem is using **Breadth-First Search (BFS)**. BFS is ideal for finding the shortest path in an unweighted graph-like problem. Here's how the transformation can be viewed as a graph problem:
- Each word is a node.
- An edge exists between two nodes if the two words differ by exactly one letter.
- We need to find the shortest path from the node corresponding to **beginWord** to the node corresponding to **endWord**.

### Example 1:
#### Input:
```
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
```

#### Explanation:
- We need to find the shortest transformation from "hit" to "cog".
- Valid transformations where words differ by one letter:
  - "hit" → "hot" → "dot" → "dog" → "cog"
- Therefore, the transformation sequence is 5 words long: `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`.
- So, the output is `5`.

#### Visualization of the Graph:
```
"hit" -> "hot"
"hot" -> "dot"
"dot" -> "dog"
"dog" -> "cog"
```

### Example 2:
#### Input:
```
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
```

#### Explanation:
- We start with "hit".
- The transformation process begins, but there's no valid path to reach "cog" because "cog" is missing from the **wordList**.
- Since we can't reach the **endWord**, the function returns `0`.

### Key Points to Note:
1. **endWord must be in wordList**: If the endWord is not present in the wordList, it is impossible to transform beginWord to endWord, and hence we return `0`.
2. **BFS guarantees the shortest path**: Since BFS explores all possibilities level by level (one word change at a time), it ensures that the first time we reach the endWord, we've found the shortest path.
3. **Graph Representation**: Every word can be treated as a node, and we create an edge between two words if they differ by exactly one letter.

### Steps of BFS:
1. Add the **beginWord** to a queue and mark it as visited.
2. For each word in the queue, try changing each letter of the word to every possible letter (from 'a' to 'z') to generate new words.
3. If a generated word exists in the **wordList** and hasn't been visited yet, add it to the queue.
4. Continue this process until you find the **endWord** or exhaust all possibilities.
5. If you find the **endWord**, return the number of transformations; otherwise, return `0`.

### Time Complexity:
- **O(N * M * 26)** where:
  - `N` is the length of the **wordList**.
  - `M` is the length of each word.
  - We check all possible transformations for each word in the list.

This makes the BFS approach efficient for the problem.



---
Time Complexity: O(N * M * 26)

Where N = size of wordList Array and M = word length of words present in the wordList..

Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }

Where N = size of wordList Array.
---
```
Approach:
The problem is solved using a Breadth-First Search (BFS) approach, where each word in the sequence is treated as a node, and the goal is to find the shortest path (smallest number of transformations) from the beginWord to the endWord. The BFS guarantees the shortest path due to its level-by-level exploration.
```
---
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs appraoch as level wise 
        //set also works
        unordered_set<string>s(wordList.begin(),wordList.end());//stores all word 
        queue<pair<string,int>>q;
        //push beginWord with step=1 in queue
        int step=1; 
        q.push({beginWord,step}); 
         //erase beginWord from set 
         s.erase(beginWord);
         
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second ; 
            q.pop();
            //see if end word found 
            if(word==endWord){
                return step;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i] ; 

                //replace ch with a to z and see which word exist in set 
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //see if word exist in set 
                    if(s.find(word)!=s.end()){
                        //it exist remove from set as found 
                        s.erase(word); 
                     /* we can return answer from here as well 
                        //see if end word found 
                     if(word==endWord){
                       return step+1; //counted this step as well
                     }
                     */
                        //push in queue with increment in step 
                        q.push({word,step+1});
                    }
                }
                //replace word[i] after we are done with changing it from a to z by original char which was there in it
            word[i] = original;   
            }
        }
        return 0;//if not found
    }
};
```

I'll break down the code **line by line**, explaining how each part works along with a **dry run** using the input example: 

### Input Example:
```
beginWord = "hit"
endWord = "cog"
wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
```

### Code with Dry Run:

```cpp
class Solution { 
public: 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
```
- **Explanation**: This function takes the `beginWord`, `endWord`, and a list of words (`wordList`) as input. The goal is to find the shortest transformation sequence from `beginWord` to `endWord`.
  
**Dry Run Start**:  
- Inputs: `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot", "dot", "dog", "lot", "log", "cog"]`.

---

```cpp
        unordered_set<string> s(wordList.begin(), wordList.end()); 
```
- **Explanation**: We convert `wordList` into a `set` for **O(1) lookup** time when checking if a word exists. This avoids redundant searching and improves performance.

**Dry Run**:  
- Set `s = {"hot", "dot", "dog", "lot", "log", "cog"}`.

---

```cpp
        queue<pair<string, int>> q;
```
- **Explanation**: A queue is used for **Breadth-First Search (BFS)**, where each element in the queue stores a pair of the word and the current step count. This allows us to explore transformations level by level.

**Dry Run**:  
- Initialize the queue `q` which is empty at this point.

---

```cpp
        int step = 1; 
        q.push({beginWord, step});
```
- **Explanation**: We initialize the step count to `1` (since the `beginWord` is the first word in the sequence) and push the `beginWord` along with the step count to the queue.

**Dry Run**:  
- Queue `q = [("hit", 1)]`.

---

```cpp
        s.erase(beginWord);
```
- **Explanation**: Since we've already started with the `beginWord`, we remove it from the set `s` to avoid revisiting it in future transformations.

**Dry Run**:  
- Set `s = {"hot", "dot", "dog", "lot", "log", "cog"}` (no change because "hit" wasn't in `wordList`).

---

```cpp
        while (!q.empty()) {
```
- **Explanation**: Start the BFS loop, which continues until the queue is empty (i.e., all possible transformations have been explored).

**Dry Run**:  
- The queue is not empty, so we proceed inside the loop.

---

```cpp
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
```
- **Explanation**: Extract the front element of the queue, which contains the current word and the step count. After processing it, we remove it from the queue using `q.pop()`.

**Dry Run**:  
- `word = "hit"`, `step = 1`.  
- Queue `q = []` after popping.

---

```cpp
            if (word == endWord) {
                return step;
            }
```
- **Explanation**: If the current word is the `endWord`, we return the step count as the result. This indicates the shortest transformation sequence has been found.

**Dry Run**:  
- `word` is "hit", which is not equal to `endWord` ("cog"), so we continue.

---

```cpp
            for (int i = 0; i < word.size(); i++) {
```
- **Explanation**: Loop through each character of the current word to try changing it to every possible letter from 'a' to 'z'.

**Dry Run**:  
- `word = "hit"`, so the loop will iterate 3 times (for `i = 0`, `i = 1`, and `i = 2`).

---

```cpp
                char original = word[i];
```
- **Explanation**: Store the original character of the current position `i` in the word. This is necessary so that after trying different letters, we can restore the original word.

**Dry Run**:  
- For `i = 0`, `original = 'h'`.

---

```cpp
                for (char ch = 'a'; ch <= 'z'; ch++) {
```
- **Explanation**: Try replacing the character at position `i` with every letter from 'a' to 'z'.

**Dry Run**:  
- We start trying with `ch = 'a'`.

---

```cpp
                    word[i] = ch;
```
- **Explanation**: Replace the character at position `i` with `ch`.

**Dry Run**:  
- For `i = 0` and `ch = 'a'`, `word = "ait"`.  
- For `ch = 'b'`, `word = "bit"`.  
- ...  
- For `ch = 'h'`, `word = "hit"`.

---

```cpp
                    if (s.find(word) != s.end()) {
```
- **Explanation**: Check if the modified word exists in the set `s`. If it exists, it's a valid transformation.

**Dry Run**:  
- For `word = "hot"`, it's found in the set `s`.

---

```cpp
                        s.erase(word);
```
- **Explanation**: Once we find a valid transformation, we remove the word from the set `s` to avoid revisiting it in future transformations.

**Dry Run**:  
- Remove `"hot"` from the set:  
  Set `s = {"dot", "dog", "lot", "log", "cog"}`.

---

```cpp
                        q.push({word, step + 1});
```
- **Explanation**: Push the transformed word into the queue with the step count incremented by 1, as it represents the next level of transformation.

**Dry Run**:  
- Push `("hot", 2)` to the queue.  
- Queue `q = [("hot", 2)]`.

---

```cpp
                }
                word[i] = original;
```
- **Explanation**: After trying all possible transformations for the character at position `i`, we restore the original word.

**Dry Run**:  
- After restoring, `word = "hit"`.

---

```cpp
            }
        }
```
- **Explanation**: End of the loop for changing each character in the word.

**Dry Run**:  
- Continue processing the next word in the queue.

---

```cpp
        return 0;
```
- **Explanation**: If we exhaust all possibilities and don't find the `endWord`, return `0` indicating that no valid transformation sequence exists.

**Dry Run**:  
- This line won't be reached in our case since there is a valid sequence.

---

### Summary of BFS Traversal:

1. `q = [("hit", 1)]`, step 1.
   - "hit" -> "hot", push `("hot", 2)`.
2. `q = [("hot", 2)]`, step 2.
   - "hot" -> "dot", push `("dot", 3)`.
   - "hot" -> "lot", push `("lot", 3)`.
3. `q = [("dot", 3), ("lot", 3)]`, step 3.
   - "dot" -> "dog", push `("dog", 4)`.
   - "lot" -> "log", push `("log", 4)`.
4. `q = [("dog", 4), ("log", 4)]`, step 4.
   - "dog" -> "cog", push `("cog", 5)`.
   - Found `endWord = "cog"`.

Output: `5` (steps: "hit" -> "hot" -> "dot" -> "dog" -> "cog").
