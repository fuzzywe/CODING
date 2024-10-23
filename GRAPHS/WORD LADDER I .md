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


