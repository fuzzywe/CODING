Minimum Spanning Tree
Difficulty: MediumAccuracy: 47.82%Submissions: 142K+Points: 4
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).


Expected Auxiliary Space: O(V2).

![G-44  Minimum Spanning Tree - Theory 2-25 screenshot](https://github.com/user-attachments/assets/3c820a22-156e-4c5b-aab6-b4993b79a87b)

![G-44  Minimum Spanning Tree - Theory 4-59 screenshot](https://github.com/user-attachments/assets/e774bbf3-0f93-4e58-aacb-17f6a9677c65)


![G-44  Minimum Spanning Tree - Theory 6-50 screenshot](https://github.com/user-attachments/assets/52cb4587-cb5d-4f49-9d68-9826623b756f)


To provide a detailed dry run and visual representation of each line in the code, let's focus on executing every line step-by-step with an example graph, showing how each part of the code updates variables and the graph's MST construction. I'll also present a visual representation after each significant step.

Here's the example graph we'll use, with 4 nodes (0, 1, 2, 3) and weighted edges:

- (0, 1) - Weight: 10
- (0, 2) - Weight: 6
- (0, 3) - Weight: 5
- (1, 3) - Weight: 15
- (2, 3) - Weight: 4

We can represent this graph in an adjacency list format:
```cpp
adj[0] = {{1, 10}, {2, 6}, {3, 5}};
adj[1] = {{0, 10}, {3, 15}};
adj[2] = {{0, 6}, {3, 4}};
adj[3] = {{0, 5}, {1, 15}, {2, 4}};
```

### Dry Run: Code Execution Line by Line

#### Step-by-Step Code Execution with Explanation

Here’s the code with comments explaining each line:

```cpp
int spanningTree(int V, vector<vector<int>> adj[]) {
    // Initialize a min-heap (priority queue) to pick minimum weight edges.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Visited array to keep track of nodes included in MST.
    vector<int> vis(V, 0);
    
    // Start from node 0 with weight 0.
    pq.push({0, 0});
    
    // Initialize MST sum (total weight).
    int sum = 0;

    // Process until all nodes are included in MST.
    while (!pq.empty()) {
        // Get the edge with the smallest weight.
        auto it = pq.top();
        pq.pop();
        
        int node = it.second;
        int wt = it.first;

        // If node is already visited, skip it to avoid cycles.
        if (vis[node] == 1) continue;

        // Include node in MST.
        vis[node] = 1;
        sum += wt;

        // Process all adjacent edges.
        for (auto& itr : adj[node]) {
            int adjNode = itr[0];
            int edW = itr[1];
            
            // If adjacent node isn't in MST, push it to the priority queue.
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    
    // Return total weight of MST.
    return sum;
}
```

### Dry Run with Visual Representation of Each Step

We’ll trace each line of code with an explanation and update the MST graph visually as we go.

#### Step 1: Initial Setup
- **Initialize priority queue** `pq` and visited array `vis`.
  ```cpp
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(V, 0); // V = 4, so vis = [0, 0, 0, 0]
  pq.push({0, 0});       // Start with node 0 with weight 0
  int sum = 0;           // sum = 0
  ```
  
- **Graph Visualization**:
  ```
     0
    /|\
   10 6 5
  / |  | \
 1   2----3
      \  /
       4
  ```

#### Step 2: Processing Node 0
- Enter the `while` loop and pop `{0, 0}` from `pq`.
  ```cpp
  auto it = pq.top();  // it = {0, 0}
  pq.pop();            // pq becomes empty
  int node = it.second; // node = 0
  int wt = it.first;   // wt = 0
  ```
- Since `vis[0]` is 0, mark `0` as visited and add `wt` (0) to `sum`.
  ```cpp
  if (vis[node] == 1) continue; // skip, node is unvisited
  vis[node] = 1;   // vis = [1, 0, 0, 0]
  sum += wt;       // sum = 0 + 0 = 0
  ```
- Process adjacent edges of `0`: `(0,1,10)`, `(0,2,6)`, and `(0,3,5)`.
  ```cpp
  for (auto& itr : adj[node]) { // adj[0] = {{1, 10}, {2, 6}, {3, 5}}
      pq.push({10, 1});         // push {10, 1}
      pq.push({6, 2});          // push {6, 2}
      pq.push({5, 3});          // push {5, 3}
  }
  ```
  
- **Graph Visualization**:
  ```
    (Current MST: None)
    pq: [{5, 3}, {6, 2}, {10, 1}]
  ```

#### Step 3: Processing Node 3 (Next Minimum Edge)
- Pop `{5, 3}` from `pq` (smallest weight).
  ```cpp
  auto it = pq.top();  // it = {5, 3}
  pq.pop();            // pq = [{6, 2}, {10, 1}]
  int node = it.second; // node = 3
  int wt = it.first;   // wt = 5
  ```
- Since `vis[3]` is 0, mark `3` as visited and add `wt` (5) to `sum`.
  ```cpp
  vis[node] = 1;   // vis = [1, 0, 0, 1]
  sum += wt;       // sum = 0 + 5 = 5
  ```
- Process adjacent edges of `3`: `(3,1,15)`, `(3,2,4)`.
  ```cpp
  pq.push({4, 2});  // push {4, 2}
  pq.push({15, 1}); // push {15, 1}
  ```
  
- **Graph Visualization**:
  ```
       0
         \
          3
         (Weight = 5)
    pq: [{4, 2}, {6, 2}, {10, 1}, {15, 1}]
  ```

#### Step 4: Processing Node 2 (Next Minimum Edge)
- Pop `{4, 2}` from `pq` (smallest weight).
  ```cpp
  auto it = pq.top();  // it = {4, 2}
  pq.pop();            // pq = [{6, 2}, {10, 1}, {15, 1}]
  int node = it.second; // node = 2
  int wt = it.first;   // wt = 4
  ```
- Since `vis[2]` is 0, mark `2` as visited and add `wt` (4) to `sum`.
  ```cpp
  vis[node] = 1;   // vis = [1, 0, 1, 1]
  sum += wt;       // sum = 5 + 4 = 9
  ```
- Process adjacent edges of `2`: `(2,0,6)` and `(2,3,4)`.
  ```cpp
  // No new nodes to add, as 0 and 3 are already visited.
  ```
  
- **Graph Visualization**:
  ```
       0
         \
          3 -- 2
         (Weight = 5, 4)
    pq: [{6, 2}, {10, 1}, {15, 1}]
  ```

#### Step 5: Processing Node 1
- Pop `{6, 1}` from `pq` (smallest weight).
  ```cpp
  auto it = pq.top();  // it = {6, 1}
  pq.pop();            // pq = [{10, 1}, {15, 1}]
  int node = it.second; // node = 1
  int wt = it.first;   // wt = 6
  ```
- Since `vis[1]` is 0, mark `1` as visited and add `wt` (6) to `sum`.
  ```cpp
  vis[node] = 1;   // vis = [1, 1, 1, 1]
  sum += wt;       // sum = 9 + 6 = 15
  ```
  
- **Final MST Visualization**:
  ```
       0
         \
          3 -- 2
         (Weight = 5, 4)
           \
            1
           (Weight = 6)
  MST Total Weight: 15
  ```

All nodes are visited, so the `while` loop ends, and the function returns `sum = 15`, which is the weight of the MST.




