785. Is Graph Bipartite?

https://leetcode.com/problems/is-graph-bipartite/description/

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:

![image](https://github.com/user-attachments/assets/f29e74bc-cb23-43d3-9370-2e36c4d44cd7)

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:
![image](https://github.com/user-attachments/assets/d6cf9726-58b3-4e98-9e90-b9019f2d25dc)


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

Intuition
The code uses a breadth-first search (BFS) approach to traverse the graph and assigns colors to the nodes. It maintains a queue q to store the nodes to be processed. The BFS starts from a source node s and explores its adjacent nodes.

The color vector is used to assign colors to the nodes. Initially, all nodes are uncolored, indicated by -1 in the color vector. When a node is visited for the first time, its color is assigned as the complement of its parent's color (represented by !color[node]). If the adjacent node already has the same color as its parent, it means the graph is not bipartite, and the function returns false.

The BFS continues until all nodes have been visited or until a conflict in colors is detected. If the BFS completes without any conflicts, it means the graph is bipartite, and the function returns true.

The isBipartite function calls the bfs function for each node in the graph to check bipartiteness. If any of the calls to bfs returns false, indicating that the corresponding subgraph is not bipartite, the overall function returns false. Otherwise, it returns true, indicating that the entire graph is bipartite

Approach
Complexity
The time complexity
Constructing the Graph: The time complexity for constructing the graph represented by an adjacency list is typically O(V + E), where V is the number of vertices and E is the number of edges. This step is not explicitly mentioned in the given code, but assuming the graph is already provided, we can consider it as a preprocessing step.

BFS Traversal: The code performs a BFS traversal starting from each node in the graph. Since the graph is represented using an adjacency list, the time complexity for traversing all the edges from a node is O(deg(v)), where deg(v) is the degree of vertex v. In the worst case, each edge is visited once, resulting in a total time complexity of O(V + E) for the entire BFS traversal.

Checking Color Conflicts: For each edge in the graph, the code checks if there is a color conflict between the source node and the adjacent node. This check is performed in constant time O(1) since it involves a simple comparison of color values.

Therefore, the overall time complexity of the given code can be expressed as O(V + E), where V is the number of vertices and E is the number of edges in the graph.

Space complexity:O(n)
Code


```cpp
class Solution {
private :
    bool bfs(int c,int s,vector<int>& color , vector<vector<int>>& graph){
          queue<int> q;
          q.push(s);

          while(!q.empty()){
              int node = q.front();
              q.pop();
              for(auto it:graph[node]){

                  if(color[it] == -1){
                      color[it] = !color[node];
                      q.push(it);
                  }
                  else if(color[it] == color[node])
                   return false;
              }
          }

        return true;  
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

          int n = graph.size();
          vector<int> color(n,-1);

           for(int i=0;i<n;i++){
               if(!bfs(0,i,color,graph))
                return false;
           }

        return true;
    }
};

```

