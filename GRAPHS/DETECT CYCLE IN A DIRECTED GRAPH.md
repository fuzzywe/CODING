Detect Cycle in a Directed Graph
Difficulty: MediumAccuracy: 27.88%Submissions: 419K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex ito vertex j.

Example 1:

Input:
![image](https://github.com/user-attachments/assets/e1ab633c-be94-4dff-af2c-abcb207b6900)



Output: 1
Explanation: 3 -> 3 is a cycle
Example 2:
Input:
![image](https://github.com/user-attachments/assets/686407c6-1f52-4c5d-821b-9c85683ec4f2)


Output: 0
Explanation: no cycle in the graph

using khan's algo
```cpp
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
        // code here
        bool isCyclic(int V, vector<vector<int>> adj) {
        
        int count=0;
        vector<int>indeg(V,0);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                indeg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(!indeg[i])
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int j=0; j<adj[node].size(); j++){
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
            }
            
        }
        return count!=V;
        
    


    }
};
```

DFS

```cpp
class Solution {
  public:
  bool DFS(int s, vector<vector<int>>&adj, vector<bool>& visited, vector<bool>& visited_back) {
    visited[s] = true;        // Mark the node as visited
    visited_back[s] = true;   // Mark it as part of the current recursion stack

    for (int i = 0; i < adj[s].size(); i++) {
        int neighbor = adj[s][i];  // Get the neighbor node

        if (!visited[neighbor]) {
            if (DFS(neighbor, adj, visited, visited_back)) {
                return true;
            }
        } 
        else if (visited_back[neighbor]) {
            // If the neighbor is already in the recursion stack, a cycle exists
            return true;
        }
    }

    visited_back[s] = false;  // Remove the node from the recursion stack
    return false;
}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> visited(V, false);
    vector<bool> visited_back(V, false);  // Track nodes in the current DFS path

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(i, adj, visited, visited_back)) {
                return true;  // If a cycle is detected, return true
            }
        }
    }

    return false;  // No cycle detected
    }
};

```
