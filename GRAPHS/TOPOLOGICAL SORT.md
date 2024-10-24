Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

Examples:

Input: adj = [[], [0], [0], [0]] 
![image](https://github.com/user-attachments/assets/8b9e3b5a-2b09-42e2-94d3-6b740bbd3e08)

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: adj = [[], [3], [3], [], [0,1], [0,2]]
![image](https://github.com/user-attachments/assets/c3371514-7922-43be-8004-ac336ac27a39)


Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]

---
DFS Approach
Idea

Node that comes at last must be present at last. Hence, the idea is to store last visited at bottom. Thus, Stack comes into picture.

Algorithm

Make visited Array to tackle both disconnected & visited Nodes.
Call DFS on each unvisited node
Call DFS on unvisited Neighbours
After making all calls to Neighbours Store current Node in a Stack.
Finally, pop all the elements of stack into resultant Vector
Source Code
```cpp
// DFS Solution
class Solution {
  public:
  
  void dfs(int start, vector<bool> &vis, stack<int> &s, vector<vector<int>>& adj) {
	    vis[start] = 1;
	    
	    for(int nbr : adj[start]) {
	        if(!vis[nbr]) {
	            dfs(nbr, vis, s, adj);
	        }
	    }
	    
	    s.push(start);
	}
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int V = adj.size();
        vector<bool> vis(V);
	    stack<int> s;
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, s, adj);
	        }
	    }
	    vector<int> res;
	    for(int i = 0; i < V; i++) {
	        res.push_back(s.top()); s.pop();
	    }
	    return res;
    }
};
 ```
Let's break down each line of the **DFS-based topological sort** code with a detailed dry run on the graph. I'll use a graph with 5 vertices (0 to 4) and the following directed edges:

- 0 → 1
- 0 → 2
- 1 → 3
- 2 → 3
- 3 → 4

Adjacency List Representation:
```cpp
adj = {
  {1, 2},  // 0 → 1, 0 → 2
  {3},     // 1 → 3
  {3},     // 2 → 3
  {4},     // 3 → 4
  {}       // 4 has no outgoing edges
};
```

### Code and Dry Run:

```cpp
class Solution {
  public:
  
  // DFS helper function
  void dfs(int start, vector<bool> &vis, stack<int> &s, vector<vector<int>>& adj) {
      vis[start] = 1;  // Mark the current node as visited
  ```
  **Dry Run**:
  - First, `start = 0`. We mark `vis[0] = true`.
  - `vis = {true, false, false, false, false}`.

  ```cpp
      // Visit all its adjacent vertices
      for (int nbr : adj[start]) {
          if (!vis[nbr]) {
              dfs(nbr, vis, s, adj);  // Recursive DFS call on unvisited neighbors
          }
      }
  ```
  **Dry Run** (starting with `start = 0`):
  - For `start = 0`, the neighbors are `nbr = 1` and `nbr = 2` (from `adj[0] = {1, 2}`).
  - First, `nbr = 1` is not visited, so we call `dfs(1, vis, s, adj)`.

  ```cpp
      // Push the current node to the stack after visiting all neighbors
      s.push(start);
  }
  ```
  **Dry Run** (inside `dfs(1, vis, s, adj)`):
  - For `start = 1`, we mark `vis[1] = true`.
  - `vis = {true, true, false, false, false}`.
  - The neighbor of `1` is `nbr = 3` (from `adj[1] = {3}`).
  - Since `nbr = 3` is not visited, we call `dfs(3, vis, s, adj)`.

  **Dry Run** (inside `dfs(3, vis, s, adj)`):
  - For `start = 3`, we mark `vis[3] = true`.
  - `vis = {true, true, false, true, false}`.
  - The neighbor of `3` is `nbr = 4` (from `adj[3] = {4}`).
  - Since `nbr = 4` is not visited, we call `dfs(4, vis, s, adj)`.

  **Dry Run** (inside `dfs(4, vis, s, adj)`):
  - For `start = 4`, we mark `vis[4] = true`.
  - `vis = {true, true, false, true, true}`.
  - Node `4` has no neighbors (`adj[4] = {}`), so we push `4` onto the stack: `s.push(4)`.
  - Stack after this operation: `s = {4}`.

  **Returning to `dfs(3)`**:
  - All neighbors of `3` have been visited, so we push `3` onto the stack: `s.push(3)`.
  - Stack: `s = {3, 4}`.

  **Returning to `dfs(1)`**:
  - All neighbors of `1` have been visited, so we push `1` onto the stack: `s.push(1)`.
  - Stack: `s = {1, 3, 4}`.

  **Returning to `dfs(0)`**:
  - Now the second neighbor of `0`, `nbr = 2`, is checked.
  - Since `nbr = 2` is not visited, we call `dfs(2, vis, s, adj)`.

  **Dry Run** (inside `dfs(2, vis, s, adj)`):
  - For `start = 2`, we mark `vis[2] = true`.
  - `vis = {true, true, true, true, true}`.
  - The neighbor of `2` is `nbr = 3` (from `adj[2] = {3}`), but `3` is already visited, so we skip it.
  - Push `2` onto the stack: `s.push(2)`.
  - Stack: `s = {2, 1, 3, 4}`.

  **Returning to `dfs(0)`**:
  - All neighbors of `0` have been visited, so we push `0` onto the stack: `s.push(0)`.
  - Final Stack: `s = {0, 2, 1, 3, 4}`.

  ```cpp
    // Function to return list containing vertices in Topological order
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();  // Get the number of vertices
  ```
  **Dry Run**:
  - `V = 5` (number of vertices).

  ```cpp
        vector<bool> vis(V);  // Initialize a visited array
        stack<int> s;  // Stack to store the topological order
  ```
  **Dry Run**:
  - `vis = {false, false, false, false, false}`.
  - Stack `s` is empty.

  ```cpp
        // Traverse all vertices and call DFS for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);  // Call DFS if vertex is not visited
            }
        }
  ```
  **Dry Run**:
  - The loop iterates over all vertices from `i = 0` to `i = 4`.
  - For `i = 0`, since `vis[0] = false`, we call `dfs(0, vis, s, adj)`.
  - The DFS visits all vertices and updates the stack as explained above.

  ```cpp
        // Extract elements from stack to get the topological order
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());  // Add the top of the stack to the result
            s.pop();  // Pop the top element
        }
        return res;  // Return the topological order
    }
};
```

**Final Dry Run**:
- After DFS is completed, the stack contains `{0, 2, 1, 3, 4}`.
- We extract elements from the stack and push them into `res`: 
  - `res = {0, 2, 1, 3, 4}`.

This is the **topological order** of the given graph.

### Final Output
The final topological order of vertices is:
```
[0, 2, 1, 3, 4]
```

### Summary of DFS Process:
- We start DFS from each unvisited node and recursively visit all its neighbors.
- After visiting all neighbors of a node, it gets pushed onto the stack.
- After DFS finishes, nodes are popped from the stack to give the topological order.

I hope this step-by-step breakdown helps you understand the code!
BFS Approach || Kahn's Algo
Idea

The idea is that all nodes which will be at starting will have indegree 0. 

Algorithm

Store Indegree of all nodes in Array.
Push nodes in Queue whose indegree == 0.
Now, For each node in Queue.
Pop the current node & Store into resultant Array
Remove indegree count of all neighbours of current node.
If neighbours indegree becomes 0 the push into queue.
Finally, return resultant Array.
Source Code
```cpp
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topologicalSort(vector<vector<int>>& adj) {
	    int V = adj.size();
	    vector<int> res;
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; i++) {
	        for(int nbr : adj[i]) {
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int curr = q.front(); q.pop();
	        res.push_back(curr);
	        
	        for(int nbr : adj[curr]) {
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) q.push(nbr);
	        }
	    }
	    
	    return res;
	}
};
```
