Graph Representation in C++

https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list


Input Format 
In the question, they will mention whether it is a directed or undirected graph. The first line contains two space-separated integers n and m denoting the number of nodes and the number of edges respectively. Next m lines contain two integers u and v representing an edge between u and v. In the case of an undirected graph if there is an edge between u and v, it means there is an edge between v and u as well. Now the question arises if there is any boundation on the number of edges, i.e., the value of m? The answer is NO. If we add more edges, then the value of m will increase.

Graph Representations
After understanding the input format, let us try to understand how the graph can be stored. The two most commonly used representations for graphs are

Adjacency Matrix
Adjacency Lists
Adjacency Matrix
An adjacency matrix of a graph is a two-dimensional array of size n x n, where n is the number of nodes in the graph, with the property that a[ i ][ j ] = 1 if the edge (vᵢ, vⱼ) is in the set of edges, and a[ i ][ j ] = 0 if there is no such edge.

Consider the example of the following undirected graph,

Input:
5 6
1 2
1 3
2 4
3 4 
3 5 
4 5

Explanation:
Number of nodes, n = 5
Number of edges, m = 6
Next m lines represent the edges.

![image](https://github.com/user-attachments/assets/0f0da916-c315-4db1-b995-5e8b7d32eef1)



We need to store these edges so that future algorithms can be performed. Are the nodes zero-based or one-based? In this case, the nodes follow one-based indexing as the last node is 5 and the total number of nodes is also 5. Now, define an adjacency matrix of size (n+1) x (n+1), i.e., adj[n+1][n+1]. If there is an edge between 1 and 2, mark 1 at (1,2) and (2,1) as there is an edge between 2 and 1 as well (in the case of an undirected graph). Similarly, follow for other edges.


![image](https://github.com/user-attachments/assets/1210c9c5-3767-4d73-8d87-02f0a5959dd7)


All the edges are marked in the adjacency matrix, remaining spaces in the matrix are marked as zero or left as it is.

![image](https://github.com/user-attachments/assets/5dc015f8-d7d6-478e-85ba-81385d2b7865)

This matrix will tell if there is an edge between two particular nodes. For example, there is an edge between 5 and 3 as 1 is at (5,3) but there is no edge between 5 and 1 as the space is empty (or can be filled with 0) at position (5,1) in the adjacency matrix.

The space needed to represent a graph using its adjacency matrix is n² locations. Space complexity = (n*n), It is a costly method as n² locations are consumed.

Code:

```C++
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
```
---

Adjacency Lists
In the previous storing method, we saw it was taking n² space to store the graph, this is where the adjacency list comes into the picture, it takes a very less amount of space.

This is a node-based representation. In this representation, we associate with each node a list of nodes adjacent to it. Normally an array is used to store the nodes. The array provides random access to the adjacency list for any particular node.
Consider the example of the following undirected graph,

![image](https://github.com/user-attachments/assets/690af3b6-6636-48e6-8521-4ce29d838722)


To create an adjacency list, we will create an array of size n+1 where n is the number of nodes. This array will contain a list, so in C++ list is nothing but the vector of integers.

vector <int> adj[n+1];
Now every index is containing an empty vector/ list. With respect to the example, 6 indexes contain empty vectors.

What is the motive of the list?

In the example, we can clearly see that node 4 has nodes 2, 3, and 5 as its adjacent neighbors. So, to store its immediate neighbors in any order, we use the list.

![image](https://github.com/user-attachments/assets/16a91ef8-2e1e-4633-829b-1a34e17ce3de)


Hence, we stored all the neighbors in the particular indexes. In this representation, for an undirected graph, each edge data appears twice. For example, nodes 1 and 2 are adjacent hence node 2 appears in the list of node 1, and node 1 appears in the list of node 2. So, the space needed to represent an undirected graph using its adjacency list is 2 x E locations, where E denotes the number of edges.

Space complexity = O(2xE)

This representation is much better than the adjacency matrix, as matrix representation consumes n² locations, and most of them are unused.

Code:

```C++
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
```
---
The provided code builds an **adjacency matrix** representation of a graph. Let's break down the key concepts and the mathematics behind it.

### 1. **Adjacency Matrix Representation:**
An **adjacency matrix** is a way to represent a graph using a 2D array (matrix). In this matrix:

- If there is an edge between node \(u\) and node \(v\), then the value of the matrix at \( \text{adj}[u][v] \) is set to 1.
- If there is no edge between the nodes, the value remains 0 (or is left uninitialized, but for clarity, it is usually set to 0).

#### For an **undirected graph**:
- When an edge exists between two nodes \(u\) and \(v\), both \( \text{adj}[u][v] \) and \( \text{adj}[v][u] \) are set to 1. This is because an undirected graph has **bidirectional edges**, meaning if there is an edge from \(u\) to \(v\), there is also an edge from \(v\) to \(u\).

#### For a **directed graph**:
- The edge between \(u\) and \(v\) is only directed in one way, from \(u\) to \(v\). Hence, only \( \text{adj}[u][v] \) is set to 1, but \( \text{adj}[v][u] \) remains 0 unless there is a reverse edge from \(v\) to \(u\).

### 2. **Code Breakdown:**

```cpp
int adj[n+1][n+1];
```
- This line declares a 2D array of size \((n+1) \times (n+1)\), which is the adjacency matrix. The size is \(n+1\) to account for 1-based indexing (since the node numbers start from 1).
  
- **Space Complexity**: The space required to store the adjacency matrix is \(O(n^2)\) because it stores values for every possible pair of nodes, even if no edge exists between them.

---

```cpp
for(int i = 0; i < m; i++)
{
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;  // for undirected graph
}
```
- This loop runs \(m\) times, where \(m\) is the number of edges in the graph.
  
- For each edge, the two endpoints \(u\) and \(v\) are provided as input, and the matrix is updated:
  - `adj[u][v] = 1;` sets the matrix value to 1, indicating an edge from node \(u\) to node \(v\).
  - `adj[v][u] = 1;` (for undirected graphs) ensures the matrix is symmetric, meaning that an edge exists both ways, from \(u\) to \(v\) and from \(v\) to \(u\).
  
- **Time Complexity**: The loop that reads and stores the edges runs \(m\) times, making the time complexity of this process \(O(m)\). However, the overall time complexity is often considered as \(O(n^2)\) because filling out the adjacency matrix can take time proportional to \(n^2\) in the worst case.

### 3. **Mathematical Explanation:**

#### Adjacency Matrix for an Undirected Graph:

An adjacency matrix for a graph with \(n\) nodes is an \(n \times n\) matrix where:

\[
\text{adj}[u][v] =
\begin{cases}
1, & \text{if there is an edge between nodes } u \text{ and } v \\
0, & \text{if there is no edge between nodes } u \text{ and } v
\end{cases}
\]

For an **undirected graph**, the adjacency matrix is **symmetric** because an edge from node \(u\) to node \(v\) implies an edge from node \(v\) to node \(u\). This is why the code includes:

```cpp
adj[u][v] = 1;
adj[v][u] = 1;
```

In this way, both directions of the edge are represented.

#### For a **directed graph**, the adjacency matrix is **not symmetric**. An edge from \(u\) to \(v\) does not imply an edge from \(v\) to \(u\), so we only set `adj[u][v] = 1` without setting `adj[v][u] = 1`.

### 4. **Space Complexity of Adjacency Matrix:**
- The matrix requires \(O(n^2)\) space, as we are storing information for each pair of nodes, whether an edge exists or not. Even for sparse graphs (where there are very few edges compared to the total possible number of edges), the space requirement remains the same.

### 5. **Time Complexity of Building the Adjacency Matrix:**
- The time complexity for filling the adjacency matrix is \(O(m)\), where \(m\) is the number of edges. Each time an edge is added, two entries in the matrix are updated for undirected graphs.
- Accessing or checking for an edge between any two nodes is very efficient with adjacency matrices, taking \(O(1)\) time.

### Summary of Time and Space Complexity:
- **Time Complexity**: \(O(m)\) to read the edges, and the overall time complexity of operations with adjacency matrices is often considered \(O(n^2)\) due to accessing and updating the matrix.
- **Space Complexity**: \(O(n^2)\), as the adjacency matrix stores information for all possible node pairs.

This method is most efficient for **dense graphs** where the number of edges is close to \(n^2\), but it can be inefficient for sparse graphs due to high space usage.

---

**For directed graphs, **if there is an edge between u and v it means the edge only goes from u to v, i.e., v is the neighbor of u, but vice versa is not true. The space needed to represent a directed graph using its adjacency list is E locations, where E denotes the number of edges, as here each edge data appears only once.

Space complexity = O(E)

Code:

```cpp
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for directed graph
    // time complexity: O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        // u —> v
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}
```
Weighted Graph Representation

As of now, we were considering graphs with unit weight edges (i.e., if there is an edge between two nodes then the weight on the edge is unit weight ), now what if there are weights on its edges as shown in the following example?

![image](https://github.com/user-attachments/assets/99699de1-c970-4f2f-b835-5db2f098a1dd)

For the adjacency matrix, it is much simpler.
![image](https://github.com/user-attachments/assets/50cb50e4-5f12-4e45-ab42-bfed2724a44c)


But how are we going to implement it in the adjacency list?

Earlier in the adjacency list, we were storing a list of integers in each index, but for weighted graphs, we will store pairs (node, edge weight) in it.

vector< pair <int,int> > adjList[n+1];

![image](https://github.com/user-attachments/assets/23ba3dda-f51c-4979-8640-b4f96b8086b4)

