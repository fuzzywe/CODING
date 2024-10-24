Eventual Safe States

https://www.geeksforgeeks.org/problems/eventual-safe-states/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Input:
![image](https://github.com/user-attachments/assets/b96dc8b5-b389-46d3-9d72-c66162a0cb6a)


Output:
2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
Example 2:

Input:

![image](https://github.com/user-attachments/assets/63363bd0-feed-458f-a089-e43811213aaf)

Output:
3
Explanation:
Only node 3 is a terminal node, and every path 
starting at node 3 leads to node 3.
Your Task:
You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

Expected Time Complexity: O(V + E)

Expected Space Complexity: O(V)

```cpp
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> indegrees(V, 0);
        vector<int> adjRev[V];
        vector<int> safeNodes;
        queue<int> q;
        
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                adjRev[it].push_back(i);
                indegrees[i]++;
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(indegrees[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            
            for(auto it : adjRev[node]) {
                indegrees[it]--;
                if(indegrees[it] == 0) q.push(it);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};

```
Sure! Let's do a complete dry run of the code line by line, with a step-by-step explanation and the values for each iteration.

### Problem Recap:
We are trying to find the **eventual safe nodes** in a directed graph. A node is considered safe if it can only reach nodes that eventually lead to terminal nodes (nodes without outgoing edges). The code uses **topological sorting** on a **reversed graph** to identify safe nodes.

---

### Code:

```cpp
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
```
- **V**: Number of vertices (nodes) in the graph.
- **adj[]**: Adjacency list representing the graph. For each node, `adj[i]` contains nodes that can be reached from node `i`.

### Input Example:
Let's assume we have the following graph represented by an adjacency list:

```
V = 5
adj = { {1, 2}, {2, 3}, {3}, {}, {0, 2} }
```

This graph can be visualized as:
```
0 → 1 → 2 → 3
4 → 0 → 2
```

### Step 1: Initialize variables

```cpp
vector<int> indegrees(V, 0);
vector<int> adjRev[V];
vector<int> safeNodes;
queue<int> q;
```
- **indegrees**: An array of size `V` initialized to `0`. This will store the number of incoming edges (indegrees) for each node in the reversed graph.
  - `indegrees = [0, 0, 0, 0, 0]`
- **adjRev**: An array of vectors, where `adjRev[i]` will store the nodes that have an edge pointing to node `i` in the reversed graph.
  - `adjRev = { {}, {}, {}, {}, {} }`
- **safeNodes**: A vector to store the eventual safe nodes.
  - `safeNodes = []`
- **q**: A queue to process nodes with 0 indegree (terminal nodes).
  - `q = {}`

---

### Step 2: Reverse the graph and compute indegrees

```cpp
for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
        adjRev[it].push_back(i);
        indegrees[i]++;
    }
}
```
We will reverse the graph by iterating through each node `i` and its outgoing edges `adj[i]`. For every edge from `i` to `it`, we add `i` to `adjRev[it]` and increase the indegree of `i`.

#### Iteration 1 (`i = 0`):
- `adj[0] = {1, 2}` (i.e., 0 → 1, 0 → 2)
  - `adjRev[1].push_back(0)` → `adjRev = { {}, {0}, {}, {}, {} }`
  - `adjRev[2].push_back(0)` → `adjRev = { {}, {0}, {0}, {}, {} }`
  - Increment `indegrees[0]` by 1 for both edges → `indegrees = [2, 0, 0, 0, 0]`

#### Iteration 2 (`i = 1`):
- `adj[1] = {2, 3}` (i.e., 1 → 2, 1 → 3)
  - `adjRev[2].push_back(1)` → `adjRev = { {}, {0}, {0, 1}, {}, {} }`
  - `adjRev[3].push_back(1)` → `adjRev = { {}, {0}, {0, 1}, {1}, {} }`
  - Increment `indegrees[1]` by 1 for both edges → `indegrees = [2, 2, 0, 0, 0]`

#### Iteration 3 (`i = 2`):
- `adj[2] = {3}` (i.e., 2 → 3)
  - `adjRev[3].push_back(2)` → `adjRev = { {}, {0}, {0, 1}, {1, 2}, {} }`
  - Increment `indegrees[2]` by 1 → `indegrees = [2, 2, 1, 0, 0]`

#### Iteration 4 (`i = 3`):
- `adj[3] = {}` (node 3 has no outgoing edges, so nothing changes)
  - `adjRev = { {}, {0}, {0, 1}, {1, 2}, {} }`
  - `indegrees = [2, 2, 1, 0, 0]`

#### Iteration 5 (`i = 4`):
- `adj[4] = {0, 2}` (i.e., 4 → 0, 4 → 2)
  - `adjRev[0].push_back(4)` → `adjRev = { {4}, {0}, {0, 1}, {1, 2}, {} }`
  - `adjRev[2].push_back(4)` → `adjRev = { {4}, {0}, {0, 1, 4}, {1, 2}, {} }`
  - Increment `indegrees[4]` by 1 for both edges → `indegrees = [2, 2, 2, 0, 0]`

---

### Step 3: Add terminal nodes (nodes with indegree 0) to the queue

```cpp
for (int i = 0; i < V; i++) {
    if (indegrees[i] == 0) q.push(i);
}
```
- Iterate through all nodes and add those with 0 indegree to the queue.
- Nodes with `indegree == 0`: node 3 and node 4.
  - `q = {3, 4}`

---

### Step 4: Process nodes using BFS (Kahn's Algorithm)

```cpp
while (!q.empty()) {
    int node = q.front();
    q.pop();

    safeNodes.push_back(node);

    for (auto it : adjRev[node]) {
        indegrees[it]--;
        if (indegrees[it] == 0) q.push(it);
    }
}
```
We now process each node in the queue, reducing the indegree of its neighbors in the reversed graph. If any neighbor's indegree becomes 0, we add it to the queue.

#### Iteration 1 (`node = 3`):
- `q = {4}` (remove node 3 from the queue)
- Add node 3 to `safeNodes`: `safeNodes = {3}`
- Neighbors of node 3: `{1, 2}`
  - Decrement `indegrees[1]`: `indegrees = [2, 1, 2, 0, 0]`
  - Decrement `indegrees[2]`: `indegrees = [2, 1, 1, 0, 0]`

#### Iteration 2 (`node = 4`):
- `q = {}` (remove node 4 from the queue)
- Add node 4 to `safeNodes`: `safeNodes = {3, 4}`
- Neighbors of node 4: `{0, 2}`
  - Decrement `indegrees[0]`: `indegrees = [1, 1, 1, 0, 0]`
  - Decrement `indegrees[2]`: `indegrees = [1, 1, 0, 0, 0]`
  - Node 2 now has indegree 0, so add it to the queue: `q = {2}`

#### Iteration 3 (`node = 2`):
- `q = {}` (remove node 2 from the queue)
- Add node 2 to `safeNodes`: `safeNodes = {3, 4, 2}`
- Neighbors of node 2: `{0, 1}`
  - Decrement `indegrees[0]`: `indegrees = [0, 1, 0, 0, 0]`
  - Decrement `indegrees[1]`: `indegrees = [0, 0, 0, 0, 0]`
  - Node 0 and node 1 now have indegree 0, so add them to the queue: `q = {0, 1}`

#### Iteration 4 (`node = 0`):
- `q = {1}` (remove node 0 from the queue)
- Add node 0 to `safeNodes`: `safeNodes = {3, 4, 2, 0}`

#### Iteration 5 (`node = 1`):
- `q = {}` (remove node 1 from the queue)
- Add node 1 to `safeNodes`: `safeNodes = {3, 4, 2, 0, 1}`

---

### Step 5: Sort and Return the Result

```cpp
sort(safeNodes.begin(), safeNodes.end());
return safeNodes;
```
- The final `safeNodes` list is `{3, 4, 2, 0, 1}`. Sorting it gives `{0,

 1, 2, 3, 4}`.
- The function returns this sorted list of safe nodes: `{0, 1, 2, 3, 4}`.

### Final Output:
The eventual safe nodes are all the nodes in this graph: `{0, 1, 2, 3, 4}`.
