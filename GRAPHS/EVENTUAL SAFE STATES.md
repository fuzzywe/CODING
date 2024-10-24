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
