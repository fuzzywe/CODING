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
```
// DFS Solution
class Solution
{
	public:
	
	void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[]) {
	    vis[start] = 1;
	    
	    for(int nbr : adj[start]) {
	        if(!vis[nbr]) {
	            dfs(nbr, vis, s, adj);
	        }
	    }
	    
	    s.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
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
	vector<int> topoSort(int V, vector<int> adj[]) {
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
