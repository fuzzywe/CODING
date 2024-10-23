Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 135K+Points: 8
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return "".
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

---

The problem of the **Alien Dictionary** can be understood as finding the order of characters in an alien language based on a sorted dictionary of words. The challenge is to derive the sequence in which the characters appear, similar to figuring out the alphabetical order for the characters based on the input.

### Key Insights:
1. The words in the dictionary are **sorted** according to the rules of the alien language.
2. You need to determine the relative order of characters based on the comparison of adjacent words.
3. The problem can be visualized as a **graph problem** where each character is a node, and an edge from one character to another signifies that the first character appears before the second character in the alien language.
4. The final task is to determine a **topological ordering** of the characters in the alien language.

### Solution Approach:
1. **Build the Graph**: 
    - Each character is a node.
    - For each adjacent pair of words in the dictionary, the first mismatch between characters of the two words determines the order between them.
    - Create a directed edge from the first mismatched character in the first word to the first mismatched character in the second word. This implies that the character in the first word comes **before** the character in the second word in the alien language.

2. **Topological Sorting**:
    - After building the graph, perform a **topological sort** to get the order of characters. If the graph contains a cycle, no valid ordering is possible, and an empty string should be returned.
  
3. **Edge Case**:
    - If all the words are the same up to the length of the shortest word, no edges are added, and there might be multiple valid outputs.

### Steps:

1. **Graph Construction**:
    - We compare adjacent words and create a graph of characters where each character points to the characters that come after it in the alien language.

2. **Topological Sort**:
    - This is used to get a valid ordering of characters. We can use **Kahn’s Algorithm** or **DFS (Depth-First Search)** to perform the topological sort.

### Example Walkthrough:

#### Example 1:
```
Input:
n = 5, k = 4, dict = ["baa","abcd","abca","cab","cad"]
```

Here, we have the dictionary:
- "baa"
- "abcd"
- "abca"
- "cab"
- "cad"

**Step 1: Build the Graph**:
- Compare "baa" and "abcd":
  - The first mismatch is 'b' in "baa" and 'a' in "abcd", so 'b' must come before 'a'. Add edge: `b -> a`.
- Compare "abcd" and "abca":
  - The first mismatch is 'd' in "abcd" and 'a' in "abca", so 'd' must come before 'a'. Add edge: `d -> a`.
- Compare "abca" and "cab":
  - The first mismatch is 'a' in "abca" and 'c' in "cab", so 'a' must come before 'c'. Add edge: `a -> c`.
- Compare "cab" and "cad":
  - The first mismatch is 'b' in "cab" and 'd' in "cad", so 'b' must come before 'd'. Add edge: `b -> d`.

**Step 2: Topological Sort**:
- The graph now looks like:
```
b -> a
d -> a
a -> c
b -> d
```
- To get the topological order, perform a topological sort:
  - Start with nodes that have no incoming edges. In this case, 'b' has no incoming edges.
  - Process 'b', then 'd', then 'a', then 'c'.
  
Thus, one possible valid order is `"bdac"`.

**Final Output**: 1 (indicating a correct order).

---

#### Example 2:
```
Input:
n = 3, k = 3, dict = ["caa", "aaa", "aab"]
```

Here, we have the dictionary:
- "caa"
- "aaa"
- "aab"

**Step 1: Build the Graph**:
- Compare "caa" and "aaa":
  - The first mismatch is 'c' in "caa" and 'a' in "aaa", so 'c' must come before 'a'. Add edge: `c -> a`.
- Compare "aaa" and "aab":
  - The first mismatch is 'a' in "aaa" and 'b' in "aab", so 'a' must come before 'b'. Add edge: `a -> b`.

**Step 2: Topological Sort**:
- The graph now looks like:
```
c -> a
a -> b
```
- Perform topological sort:
  - Start with nodes that have no incoming edges. In this case, 'c' has no incoming edges.
  - Process 'c', then 'a', then 'b'.
  
Thus, one possible valid order is `"cab"`.

**Final Output**: 1 (indicating a correct order).

---

### Conclusion:
- This problem can be solved using **graph construction** and **topological sorting**.
- We compare adjacent words to build a directed graph of characters.
- A topological sort on this graph gives us the valid order of characters in the alien language.
- If no valid order is possible (i.e., the graph contains a cycle), return `""`.

  ---

  ```cpp
  class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int> indegree(k);
        vector<int> adj[k];
        
        for(int i = 0; i < n - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int len = min(s1.size(),s2.size());
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    break;
                }
            }
        }
        
        queue<int>q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(char(node + 'a'));
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};
  ```

The given code solves the problem of finding the order of characters in an alien language based on a sorted dictionary. The approach used here is **Topological Sorting** in a **Directed Acyclic Graph (DAG)**, using Kahn's algorithm (BFS approach). Let’s walk through the code step by step and perform a dry run to understand each line.

### Code Explanation:
#### **1. Input and Setup**
```cpp
vector<int> indegree(k);
vector<int> adj[k];
```
- We have a sorted dictionary `dict[]` of `n` words, and `k` represents the number of distinct characters in the alien language.
- We initialize:
  - **`indegree[k]`**: This array stores the indegree of each character (how many nodes/characters point to a particular character).
  - **`adj[k]`**: This is the adjacency list, where each index corresponds to a character, and the list at each index contains the characters that follow this character.

#### **2. Building the Graph**
```cpp
for(int i = 0; i < n - 1; i++){
    string s1 = dict[i];
    string s2 = dict[i + 1];
    
    int len = min(s1.size(), s2.size());
    
    for(int j = 0; j < len; j++){
        if(s1[j] != s2[j]){
            adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            indegree[s2[j] - 'a']++;
            break;
        }
    }
}
```
- We loop over the given `dict[]` to compare each consecutive pair of words (`s1` and `s2`).
- For each word pair, we compare their characters one by one.
- The first character mismatch between two words tells us the order of characters in the alien language. We:
  1. Create a directed edge from the first mismatching character in `s1` to the first mismatching character in `s2`. This means `s1[j]` comes before `s2[j]` in the alien alphabet.
  2. Increase the indegree of the character `s2[j]` because `s1[j]` comes before `s2[j]`.
  
- **Explanation of the Math:**
  - For each adjacent pair of words, we determine which character should come before another by finding the first character that differs.
  - If two words are the same up to the length of the shorter word, they don’t contribute to the order, so we move on to the next pair.
  
**Example Dry Run**:
- **Input**: `dict[] = {"baa", "abcd", "abca", "cab", "cad"}`, `n = 5`, `k = 4`
  
- Comparing the first two words:
  - **"baa"** and **"abcd"**:
    - The first mismatch is at index 0: 'b' vs. 'a'. So, 'b' comes before 'a'.
    - We add an edge `b -> a` and increase the indegree of 'a' by 1.
  
- Comparing **"abcd"** and **"abca"**:
  - The first mismatch is at index 3: 'd' vs. 'a'. So, 'd' comes before 'a'.
    - We add an edge `d -> a` and increase the indegree of 'a' by 1.
  
- Comparing **"abca"** and **"cab"**:
  - The first mismatch is at index 0: 'a' vs. 'c'. So, 'a' comes before 'c'.
    - We add an edge `a -> c` and increase the indegree of 'c' by 1.
  
- Comparing **"cab"** and **"cad"**:
  - The first mismatch is at index 2: 'b' vs. 'd'. So, 'b' comes before 'd'.
    - We add an edge `b -> d` and increase the indegree of 'd' by 1.

At this point, we have the following graph:
- `b -> a`
- `d -> a`
- `a -> c`
- `b -> d`

**Indegree Array**:
- `indegree['a'] = 2`, `indegree['b'] = 0`, `indegree['c'] = 1`, `indegree['d'] = 1`

#### **3. Topological Sorting**
```cpp
queue<int> q;
for(int i = 0; i < indegree.size(); i++){
    if(indegree[i] == 0) q.push(i);
}
```
- We create a queue `q` to store all characters with an **indegree of 0** (i.e., characters that have no other characters before them in the ordering). These are the starting points of the topological sort.
- In our case:
  - `indegree['b'] = 0`, so we enqueue 'b'.

#### **4. BFS for Topological Sort**
```cpp
string ans = "";
while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(char(node + 'a'));
    
    for(auto it : adj[node]){
        indegree[it]--;
        if(indegree[it] == 0) q.push(it);
    }
}
```
- We perform a **BFS** (Kahn’s algorithm):
  - Dequeue the character at the front of the queue and append it to the result string `ans`.
  - For each character adjacent to this node (i.e., the characters that come after it in the graph), decrease their indegree by 1.
  - If any adjacent character's indegree becomes 0, enqueue that character.
  
**BFS Process**:
1. **Step 1**: Queue = ['b']
   - Dequeue 'b', add it to `ans`: `ans = "b"`.
   - 'b' points to 'a' and 'd'. Decrease indegree of 'a' and 'd'.
   - New indegree: `indegree['a'] = 1`, `indegree['d'] = 0`.
   - Enqueue 'd': Queue = ['d'].
  
2. **Step 2**: Queue = ['d']
   - Dequeue 'd', add it to `ans`: `ans = "bd"`.
   - 'd' points to 'a'. Decrease indegree of 'a'.
   - New indegree: `indegree['a'] = 0`.
   - Enqueue 'a': Queue = ['a'].
  
3. **Step 3**: Queue = ['a']
   - Dequeue 'a', add it to `ans`: `ans = "bda"`.
   - 'a' points to 'c'. Decrease indegree of 'c'.
   - New indegree: `indegree['c'] = 0`.
   - Enqueue 'c': Queue = ['c'].
  
4. **Step 4**: Queue = ['c']
   - Dequeue 'c', add it to `ans`: `ans = "bdac"`.
   - 'c' has no outgoing edges, so the queue is now empty.

#### **5. Final Result**
```cpp
return ans;
```
- The final topological order is `"bdac"`, which represents one possible valid ordering of characters in the alien language.

### Summary:
- The code builds a graph based on character order deduced from adjacent words.
- It performs a topological sort using BFS to find a valid order of characters.
- If the graph is acyclic, we get a valid topological order, else, the function would return an empty string.

