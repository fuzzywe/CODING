**Number of Provinces**

https://leetcode.com/problems/number-of-provinces/description/

Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

547. Number of Provinces
Medium
Topics
Companies
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

![image](https://github.com/user-attachments/assets/7c9991aa-b752-4168-8cda-63b77b5db83e)


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
![image](https://github.com/user-attachments/assets/06d57bb4-f290-49c3-8660-54ad192b0263)


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

This problem is about finding **the number of provinces**, where a **province** is defined as a group of cities that are connected either directly or indirectly. The cities are represented as nodes in a graph, and the connections between them are the edges.

The input is given as an `n x n` matrix `isConnected`:
- `isConnected[i][j] = 1` means that city `i` is directly connected to city `j`.
- `isConnected[i][j] = 0` means there is no direct connection between city `i` and city `j`.

### Example 1

#### Input: 
`isConnected = [[1,1,0], [1,1,0], [0,0,1]]`

The matrix represents the following connections between cities:
- `City 0` is connected to `City 1` (since `isConnected[0][1] = 1` and `isConnected[1][0] = 1`).
- `City 2` is not connected to either `City 0` or `City 1` (because `isConnected[2][0] = 0` and `isConnected[2][1] = 0`).

#### Visualization:
```
  City 0 --- City 1

  City 2 (isolated)
```

#### Output: `2` (there are 2 provinces)
- **Province 1**: {City 0, City 1}
- **Province 2**: {City 2}

### Example 2

#### Input: 
`isConnected = [[1,0,0], [0,1,0], [0,0,1]]`

The matrix represents the following situation:
- `City 0`, `City 1`, and `City 2` are all isolated from each other (no direct or indirect connections between any of them).

#### Visualization:
```
  City 0 (isolated)
  
  City 1 (isolated)
  
  City 2 (isolated)
```

#### Output: `3` (there are 3 provinces)
- **Province 1**: {City 0}
- **Province 2**: {City 1}
- **Province 3**: {City 2}

---

### Explanation of the Approach:

The task can be viewed as finding **connected components** in a graph:
- Each city is a **node**.
- If `isConnected[i][j] = 1` (where `i != j`), there is an **edge** between city `i` and city `j`.
- We need to find how many **disconnected groups** of cities exist.

We can use either **Depth-First Search (DFS)** or **Breadth-First Search (BFS)** to explore the graph and count how many connected components (provinces) there are.

### Approach:
1. **Convert the matrix into a graph** representation (adjacency list) or treat it as an adjacency matrix.
2. **Visit each city** (node):
   - If the city hasn't been visited yet, it means we found a new province.
   - **Perform a DFS** or BFS to mark all cities connected to this one.
3. Keep counting the provinces until all cities have been visited.

---



### Explanation of the Code:

1. **Adjacency List Construction**:
   - The nested `for` loop converts the `isConnected` matrix into an adjacency list representation of the graph.
   - It adds edges between cities `i` and `j` if they are directly connected (`isConnected[i][j] == 1`).

2. **DFS Function**:
   - The `dfs` function recursively visits all cities connected to a given city and marks them as visited.
   
3. **Province Count**:
   - For each unvisited city, it counts a new province, and then uses DFS to visit all cities in that province.
   
4. **Return Result**:
   - The function returns the total number of provinces.

### Summary:
- The goal is to count the number of connected components (provinces) in the graph.
- Each time we find an unvisited city, we perform DFS to mark all cities in its province.
- The number of times we start a DFS gives the number of provinces.

---

```cpp

class Solution {
public:
     void dfs(vector<int> &vis, vector<int> adj[],int i){
          vis[i]=1;
          for(auto it:adj[i]){
              if(vis[it]==0){
                  dfs(vis,adj,it);
              }
          }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                cnt++;
                dfs(vis,adj,i);
            }
        }
        return cnt;
    }
};

```


Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.

---

I apologize for the confusion! Let’s go through **each line** of the code and understand the mathematical **steps**, focusing on the **exact operations** performed. This will show how many operations are done for each part of the code in terms of calculations and comparisons.

### Code Overview
```cpp
class Solution {
public:
     void dfs(vector<int> &vis, vector<int> adj[], int i) {
          vis[i] = 1;
          for (auto it: adj[i]) {
              if (vis[it] == 0) {
                  dfs(vis, adj, it);
              }
          }
     }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(vis, adj, i);
            }
        }
        return cnt;
    }
};
```

### **1. `findCircleNum` function**:

#### **Line 1:** `int n = isConnected.size();`
- **Mathematical operation**: This simply retrieves the size of the `isConnected` matrix, which is an `n x n` matrix. 
  - **Exact calculation**: `n` is assigned the value of `isConnected.size()`. This operation counts the number of rows and takes **1 operation**.

#### **Line 2:** `vector<int> adj[n];`
- **Mathematical operation**: This creates an array of vectors called `adj`, where each vector corresponds to a node (city) and stores its neighbors.
  - **Exact calculation**: Memory allocation happens for `n` empty vectors, so **1 operation per element**. The total number of operations is **n operations**.

#### **Lines 3–8:** Nested loop for building the adjacency list:
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && i != j) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}
```

##### **Outer loop (i from 0 to n-1)**:
- **Mathematical operation**: This loop runs `n` times (once for each row).

##### **Inner loop (j from 0 to n-1)**:
- **Mathematical operation**: For each iteration of `i`, this loop runs `n` times, checking each `isConnected[i][j]`.
  - For every `isConnected[i][j] == 1 && i != j` condition:
    - It pushes `j` into `adj[i]` and `i` into `adj[j]`.
  - **Exact calculation**: The condition `isConnected[i][j] == 1 && i != j` requires 2 comparisons:
    - `isConnected[i][j] == 1`
    - `i != j`
  - If the condition is true, each `push_back` involves inserting `j` and `i` into `adj[i]` and `adj[j]` respectively, which are **2 insertions**.

- **Total operations for the inner loop**:
  - **`n` comparisons** for the `if` conditions.
  - **2 insertions** per true condition.

##### **Example for `n = 3`:**
For `i = 0`, the inner loop runs 3 times:
- When `j = 0`, the condition `isConnected[0][0] == 1 && 0 != 0` is false.
- When `j = 1`, if `isConnected[0][1] == 1`, two `push_back` operations are done.
- This is repeated for every `i`, so for `n = 3`, there are **9 comparisons** (3 outer loops × 3 inner loops) and potentially up to **6 insertions** (if all non-diagonal `isConnected[i][j] == 1`).

#### **Line 9:** `vector<int> vis(n, 0);`
- **Mathematical operation**: This creates a vector `vis` of size `n`, initialized to `0`. Each element is initialized to zero, so **n assignments** are performed.

#### **Line 10:** `int cnt = 0;`
- **Mathematical operation**: This initializes a counter `cnt` to zero. This is **1 operation**.

#### **Lines 11–16:** DFS loop:
```cpp
for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
        cnt++;
        dfs(vis, adj, i);
    }
}
```

##### **Outer loop (i from 0 to n-1)**:
- **Mathematical operation**: This loop runs `n` times. For each unvisited node (`vis[i] == 0`), it:
  - **Checks** if `vis[i] == 0`, a comparison.
  - **Increments** the counter `cnt`.
  - **Calls** the `dfs` function to traverse the connected component.

- **Exact calculation**: 
  - **n comparisons** for `vis[i] == 0`.
  - **cnt++** increments whenever a new connected component is found.
  - The DFS call depends on the number of nodes in the connected component.

### **2. `dfs` function**:

#### **Line 1:** `vis[i] = 1;`
- **Mathematical operation**: Marks node `i` as visited. This is **1 assignment operation**.

#### **Line 2:** `for (auto it: adj[i]) {`
- **Mathematical operation**: Loops through all the neighbors of node `i` stored in `adj[i]`.
  - If node `i` has `deg(i)` neighbors, this loop runs `deg(i)` times.

#### **Line 3:** `if (vis[it] == 0) {`
- **Mathematical operation**: Checks if neighbor `it` has been visited.
  - This is **1 comparison** for each neighbor.

#### **Line 4:** `dfs(vis, adj, it);`
- **Mathematical operation**: Recursively calls `dfs` for unvisited neighbors.
  - **Exact calculation**: The recursive call depends on the number of neighbors, i.e., `deg(i)`.

#### **Example**:
For each call to `dfs(i)`, the recursion explores all the neighbors of `i`, which are stored in `adj[i]`. The DFS will continue visiting unvisited neighbors, marking them visited, and checking their neighbors recursively.

If `i` has 3 neighbors, the `dfs` function will:
1. Mark `i` as visited.
2. Loop 3 times to visit each neighbor:
   - For each neighbor `it` that hasn’t been visited, recursively call `dfs(it)`.

Each recursion follows the same steps, leading to the entire connected component being explored. The recursion continues until there are no more unvisited neighbors.

### **Conclusion**:
The **mathematical breakdown** of operations depends on:
1. **Matrix size `n × n`**: `n^2` checks to build the adjacency list.
2. **Adjacency list construction**: For each `isConnected[i][j] == 1`, there are 2 insertions.
3. **DFS**: Each node and edge is explored once in the DFS traversal.



