https://leetcode.com/problems/word-ladder-ii/description/

126. Word Ladder II
Solved
Hard
Topics
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

---
Intuition
The Word Ladder II problem requires finding all the shortest transformation sequences from a start word to an end 

word, where each intermediate word must exist in a given word list, and each transformation can change only one

letter. The problem can be broken down into two main tasks:

Building the Graph: Representing words as nodes and transformations as edges.

Finding All Shortest Paths: Using BFS to determine the shortest paths and DFS to enumerate all possible paths.

The intuition behind the solution is to treat the problem as a graph traversal problem where words are nodes, and 

edges exist between words that differ by exactly one character. Using BFS ensures that we find the shortest path, and 

DFS helps in backtracking to list all such paths.

Approach
Detailed Explanation
Graph Construction:

Treat each word as a node.

Connect nodes (words) with an edge if they differ by exactly one character. This is determined by the isNeighbor function.

BFS for Shortest Path:

Use BFS starting from the beginWord to find the shortest path distances to the endWord.

Maintain a parent list to record all possible predecessors of each word along the shortest paths.

DFS for Path Reconstruction:

Use DFS to backtrack from the endWord to the beginWord using the parent information collected during BFS.

Collect all valid paths during this traversal.

Step-by-Step Process:

Neighbor Check:

The isNeighbor function checks if two words are adjacent (differ by exactly one character).

BFS Traversal:

Initialize distances and parent lists.

Traverse the graph using BFS to calculate the shortest distance from the start word to all other words and maintain 

parent nodes to reconstruct paths later.

DFS Backtracking:

Perform DFS from the endWord to the beginWord, using the parent information from the BFS step to collect all shortest 

paths.

Complexity

Time Complexity:

Graph Construction: O(N^2 * M), where N is the number of words and M is the length of each word.

BFS Traversal: O(N + E), where N is the number of words and E is the number of edges.

DFS Backtracking: O(N * 2^L), where L is the length of the shortest path (in the worst case, each node could have two parents).

Space Complexity:


Graph Storage: O(N^2), for storing adjacency lists.

BFS and DFS Structures: O(N), for distance, parent, and path storage.

```cpp
class Solution {
public:

// Check if two strings are neighbors by counting differing characters
bool isNeighbour(string &s1, string &s2) {
    int n = s1.length(), diff = 0;
    for (int i = 0; i < n; ++i)
        if (s1[i] != s2[i])
            diff++;
    return diff == 1;
}

// Perform BFS to find shortest paths from src to all nodes
void BFS(int src, vector<vector<int>>& graph, vector<vector<int>>& parent, int n) {
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    parent[src].push_back(-1);
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int nbr : graph[node]) {
            if (dist[nbr] > dist[node] + 1) {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
                parent[nbr].clear();
                parent[nbr].push_back(node);
            } else if (dist[nbr] == dist[node] + 1) {
                parent[nbr].push_back(node);
            }
        }
    }
}

// Perform DFS to collect all paths from src to dest
void DFS(int node, vector<vector<int>>& parent, vector<int>& path, vector<vector<int>>& allpath) {
    if (node == -1) {
        allpath.push_back(path);
        return;
    }
    for (int par : parent[node]) {
        path.push_back(par);
        DFS(par, parent, path, allpath);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int src = -1, dest = -1, n = wordList.size();
    for (int i = 0; i < n; ++i) {
        if (wordList[i] == beginWord) src = i;
        if (wordList[i] == endWord) dest = i;
    }

    vector<vector<string>> ans;
    if (dest == -1) return ans;
    if (src == -1) {
        wordList.push_back(beginWord);
        src = n++;
    }

    vector<vector<int>> parent(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isNeighbour(wordList[i], wordList[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    BFS(src, graph, parent, n);
    vector<int> path;
    vector<vector<int>> allpath;
    DFS(dest, parent, path, allpath);

    for (auto& paths : allpath) {
        vector<string> current_path;
        for (int i = paths.size() - 2; i >= 0; --i) {
            current_path.push_back(wordList[paths[i]]);
        }
        current_path.push_back(endWord);
        ans.push_back(current_path);
    }
    return ans;
}
};

```
