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
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector< vector<int>> adj) {
        int V = adj.size();
        queue<int> q;
        vector<int> parent(V);
        vector<int> visited(V, false);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                q.push(i);
                
                while(!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = true;
            
                for(auto &nbr : adj[node]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                    else if(visited[nbr] && parent[node] != nbr){
                        return true;
                    }
                }
        }
            }
        }
        return false;
        
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
