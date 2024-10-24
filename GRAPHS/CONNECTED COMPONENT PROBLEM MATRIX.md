Number of Provinces
Difficulty: MediumAccuracy: 54.29%Submissions: 124K+Points: 4
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
![image](https://github.com/user-attachments/assets/aa397e25-da77-444d-821c-2bffadd39532)

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1
![image](https://github.com/user-attachments/assets/8bdcfec5-2643-47bf-a34c-e7a26cdaa56d)


---
```cpp
class Solution {
    private: 
    void dfs(int node, vector<bool>&visited, vector<vector<int>>edges){
        visited[node] = 1;
        for(auto i:edges[node]){
            if(!visited[i]) dfs(i,visited,edges);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>edges(V);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                if(i == j) continue;
                if(adj[i][j] == 1) edges[i].push_back(j);
            }
        }
        int count = 0;
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,edges);
            }
        }
        return count;
    
    }
};

```
