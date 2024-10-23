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
