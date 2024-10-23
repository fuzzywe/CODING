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