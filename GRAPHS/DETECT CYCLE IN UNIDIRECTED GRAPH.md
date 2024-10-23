https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:

Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
Output: 1
Explanation: 

![image](https://github.com/user-attachments/assets/925b8628-cab3-4824-a233-46953fdc8024)

1->2->3->4->1 is a cycle.
Input: adj = [[], [2], [1,3], [2]]
Output: 0



Explanation: 
![image](https://github.com/user-attachments/assets/931adaee-3b84-485e-be50-51ee4b90e943)
No cycle in the graph.


```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool detect(int src, vector<vector<int>> adj, vector<int>& vis){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i, node});
                }
                else if(parent != i) {
                     return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> adj) {
        // Code here
        int V = adj.size();
        vector<int> vis(V,0);
        for(int i = 0; i < V;i++){
            if(!vis[i]){
                if(detect(i, adj,vis))
                return true;
            }
        }return false;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

```
---

I understand you want a **line-by-line dry run** with detailed explanations of what's happening. Let's go through the **full code** along with a **dry run** of an example.

We'll assume the following undirected graph with 4 vertices and 4 edges:

### Graph Representation:
```
0 -- 1
|    |
2 -- 3
```

- **Vertices**: 4 (0, 1, 2, 3)
- **Edges**: 4
- **Adjacency List**:
  ```
  adj[0] = [1, 2]
  adj[1] = [0, 3]
  adj[2] = [0, 3]
  adj[3] = [1, 2]
  ```

Now, let's go line by line through the code and perform a dry run for the graph above.

---

### Code Breakdown with Dry Run

#### Step 1: Include Libraries

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- **Explanation**: Includes the necessary libraries. The header `bits/stdc++.h` includes most C++ standard libraries.
- **Math Behind**: No mathematical operation, just library inclusions.

#### Step 2: Define the Class and `detect` Function

```cpp
class Solution {
private:
    bool detect(int src, vector<vector<int>> adj, vector<int>& vis){
```

- **Explanation**: Defines the `Solution` class and a private helper function `detect` which will perform the BFS traversal. It accepts the starting node (`src`), the adjacency list (`adj`), and the visited array (`vis`).

---

#### Step 3: Mark the Source Node as Visited

```cpp
    vis[src] = 1;
```

- **Explanation**: Marks the `src` node (source node) as visited in the `vis` array by setting `vis[src] = 1`.

- **Dry Run** (starting with `src = 0`):
  ```
  vis = [1, 0, 0, 0]
  ```

---

#### Step 4: Create a Queue for BFS

```cpp
    queue<pair<int, int>> q;
    q.push({src, -1});
```

- **Explanation**: Initializes a queue `q` to perform the BFS traversal. The pair `{src, -1}` is pushed into the queue, where `src` is the current node, and `-1` is its "parent" (since the first node has no parent).

- **Dry Run**:
  - Queue contents: `[(0, -1)]` (node 0 with no parent)

---

#### Step 5: Begin BFS Traversal

```cpp
    while (!q.empty()) {
```

- **Explanation**: Starts a `while` loop that continues as long as the queue is not empty.

---

#### Step 6: Extract the Front of the Queue

```cpp
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
```

- **Explanation**: The front element of the queue (current node and its parent) is popped. The `node` variable holds the current node being processed, and `parent` holds the node's parent.

- **Dry Run** (first iteration):
  - Current `node = 0`, `parent = -1`
  - Queue after popping: `[]`

---

#### Step 7: Explore Neighbors of the Current Node

```cpp
    for (auto i : adj[node]) {
```

- **Explanation**: Loops through all the neighbors of the current `node`.

- **Dry Run** (for `node = 0`):
  - Neighbors of node 0: `[1, 2]`

---

#### Step 8: Check if Neighbor is Unvisited

```cpp
    if (!vis[i]) {
        vis[i] = 1;
        q.push({i, node});
```

- **Explanation**: If a neighbor (`i`) has not been visited (`!vis[i]`), it is marked as visited (`vis[i] = 1`), and the neighbor is pushed into the queue along with its parent (`node`).

- **Dry Run** (neighbor `i = 1`):
  - Mark `vis[1] = 1`
  - Push `{1, 0}` into the queue: `q = [{1, 0}]`
  - Visited array: `[1, 1, 0, 0]`

- **Dry Run** (neighbor `i = 2`):
  - Mark `vis[2] = 1`
  - Push `{2, 0}` into the queue: `q = [{1, 0}, {2, 0}]`
  - Visited array: `[1, 1, 1, 0]`

---

#### Step 9: Check for Cycle

```cpp
    } else if (parent != i) {
        return true;
    }
```

- **Explanation**: If a neighbor (`i`) has already been visited but is **not** the parent of the current node (`parent != i`), then a cycle is detected, and the function returns `true`.

- **Dry Run** (no cycle detected in this step).

---

#### Step 10: End of BFS for Current Node

```cpp
    }
    }
    return false;
}
```

- **Explanation**: The inner `for` loop ends. If no cycle was detected during the traversal of the current node, the function returns `false` after visiting all nodes connected to `src`.

---

#### Step 11: Main Function to Detect Cycle

```cpp
public:
    bool isCycle(vector<vector<int>> adj) {
```

- **Explanation**: This is the main function that checks for cycles in the graph. It takes the adjacency list (`adj`) as input.

---

#### Step 12: Get the Number of Vertices

```cpp
    int V = adj.size();
    vector<int> vis(V, 0);
```

- **Explanation**: The number of vertices (`V`) is set to the size of the adjacency list. A visited array `vis` of size `V` is created, initialized with 0 (indicating all vertices are unvisited).

- **Dry Run**:
  - `V = 4`
  - `vis = [0, 0, 0, 0]`

---

#### Step 13: Loop Over All Vertices

```cpp
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis)) return true;
        }
    }
    return false;
}
```

- **Explanation**: Loops through all the vertices. If a vertex is unvisited (`!vis[i]`), it calls the `detect` function to check for cycles starting from that vertex. If a cycle is detected, `isCycle` returns `true`. If no cycles are detected after checking all vertices, it returns `false`.

- **Dry Run** (starting from `i = 0`):
  - `vis[0] = 0`, so we call `detect(0, adj, vis)`. 
  - We already performed the BFS for `src = 0` and did not find any cycles.

- **Continue Dry Run**:
  - The `for` loop continues with `i = 1`, `i = 2`, and `i = 3`, but all these nodes are already visited.

---

#### Step 14: Final Output

```cpp
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
```

- **Explanation**: The main function reads the number of test cases, the number of vertices and edges, builds the adjacency list for each test case, and calls the `isCycle` function to check for cycles. If a cycle is found, it prints `1`; otherwise, it prints `0`.

---

### Dry Run Summary:
For the graph provided:
- No cycle was detected starting from node 0.
- The function will return `0` because the graph does not contain any cycle in this scenario.



---

DFS
---

  ```cpp

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//{ Driver Code Starts


// } Driver Code Ends
class Solution {
  private:
    // DFS function to detect a cycle in an undirected graph
    bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;  // Mark the current node as visited
        
        // Traverse through all the connected nodes (neighbors)
        for (int neighbor : adj[node]) {
            // If the neighbor is not visited, perform DFS on it
            if (!vis[neighbor]) {
                if (dfs(neighbor, node, adj, vis)) 
                    return true;  // Cycle detected in the DFS subtree
            }
            // If the neighbor is visited and is not the parent of the current node
            else if (neighbor != parent) {
                return true;  // Cycle found
            }
        }
        return false;  // No cycle found in this DFS path
    }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(const vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);  // Visited array to keep track of visited nodes

        // Loop through all nodes to handle disconnected components
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {  // If the node is not visited, perform DFS
                if (dfs(i, -1, adj, vis)) 
                    return true;  // If any component contains a cycle
            }
        }
        return false;  // No cycle found in any component
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

```
