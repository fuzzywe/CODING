Introduction to Graph


272

3
What is a graph data structure?
There are two types of data structures

Linear
Non - linear
We are aware of linear data structures such as arrays, stacks, queues, and linked lists. They are called linear because data elements are arranged in a linear or sequential manner.

The only non-linear data structure that we’ve seen so far is Tree. In fact, a tree is a special type of graph with some restrictions. Graphs are data structures that have a wide-ranging application in real life. These include analysis of electrical circuits, finding the shortest routes between two places, building navigation systems like Google Maps, even social media using graphs to store data about each user, etc. To understand and use the graph data structure, let’s get familiar with the definitions and terms associated with graphs. 

Definitions and Terminology
A graph is a non-linear data structure consisting of nodes that have data and are connected to other nodes through edges.

![image](https://github.com/user-attachments/assets/80716e33-5492-4617-81cd-608f1acd84b3)


Nodes are circles represented by numbers. Nodes are also referred to as vertices. They store the data. The numbering of the nodes can be done in any order, no specific order needs to be followed.

In the following example, the number of nodes or vertices = 5


![image](https://github.com/user-attachments/assets/25bd6c27-0626-4b35-834a-2eb92cfd0a0c)

Two nodes are connected by a horizontal line called Edge. Edge can be directed or undirected. Basically, pairs of vertices are called edges.

In the above example, the edge can go from 1 to 4 or from 4 to 1, i.e. a bidirectional edge can be in both directions, hence called an undirected edge. Thus, the pairs (1,4) and (4,1) represent the same edge.

Types of Graphs

![image](https://github.com/user-attachments/assets/606bab8e-4215-428d-a8bd-23184a7cd38f)

An undirected graph is a graph where edges are bidirectional, with no direction associated with them, i.e, there will be an undirected edge. In an undirected graph, the pair of vertices representing any edge is unordered. Thus, the pairs (u, v) and (v, u) represent the same edge.
A directed graph is a graph where all the edges are directed from one vertex to another, i.e, there will be a directed edge. It contains an ordered pair of vertices. It implies each edge is represented by a directed pair <u, v>. Therefore, <u, v> and <v, u> represent two different edges.
There can be multi-directed edges, hence bidirectional edges, as shown in the example below.

![image](https://github.com/user-attachments/assets/ad56f162-29dd-42f8-8344-56ca6f94dd04)


Structure of Graph 
Does every graph have a cycle? 

The answer is No! Let us consider the following examples to understand this. 


![image](https://github.com/user-attachments/assets/75cdfd19-9b1e-4355-be7c-4a02cee0251b)

Fig. 1 does not form a cycle but still, it is a graph. 

Fig. 2 is an example of a binary tree. It can also be called a graph because it follows all the rules. We’ve nodes and edges, and this is the minimal condition to be called a graph. 

So a graph does not necessarily mean to be an enclosed structure, it can be an open structure as well. A graph is said to have a cycle if it starts from a node and ends at the same node. There can be multiple cycles in a graph.
![image](https://github.com/user-attachments/assets/e20c59bd-5977-42ac-8cb6-43754c49379b)



If there is at least one cycle present in the graph then it is called an Undirected Cyclic Graph.

In the following examples of directed graphs, the first directed graph is not cyclic as we can’t start from a node and end at the same node. Hence it is called Directed Acyclic Graph, commonly called DAG.

![image](https://github.com/user-attachments/assets/5b98a1d8-5fd6-4665-a99e-f141fabebab3)


If we just add an edge to the directed graph, then at least one cycle is present in the graph, hence it becomes Directed Cyclic Graph.

Path in a Graph  
![image](https://github.com/user-attachments/assets/9133e935-31c4-41ca-98f6-6a2b74019d5f)

The path contains a lot of nodes and each of them is reachable.

Consider the given graph,

![image](https://github.com/user-attachments/assets/9d900b23-49d5-43e6-ab83-25aad2db72d5)


1 2 3 5 is a path.
1 2 3 2 1 is not a path, because a node can’t appear twice in a path.
1 3 5 is not a path, as adjacent nodes must have an edge and there is no edge between 1 and 3.
Degree of Graph

It is the number of edges that go inside or outside that node.

For undirected graphs, the degree is the number of edges attached to a node.

Example, 
D(3) = 3
D(4) = 2
![image](https://github.com/user-attachments/assets/7c91b7e2-6222-462b-b5c4-3930c501608c)


Property: It states that the total degree of a graph is equal to twice the number of edges. This is because every edge is associated/ connected to two nodes.

![image](https://github.com/user-attachments/assets/f54392a4-e082-4cae-8650-7f53a262cfb9)


Total Degree of a graph = 2 x E
Example, (2+2+3+2+3) = 2 x 6 => 12 = 12 

![image](https://github.com/user-attachments/assets/dbafe94c-b170-48f7-9288-4cb75529c649)

For directed graphs, we’ve Indegree and Outdegree. The indegree of a node is the number of incoming edges. The outdegree of a node is the number of outgoing edges.

Edge Weight
A graph may have weights assigned on its edges. It is often referred to as the cost of the edge.

![image](https://github.com/user-attachments/assets/220cc83e-4bc5-4564-b5a9-ef8f1c9145ae)


If weights are not assigned then we assume the unit weight, i.e, 1. In applications, weight may be a measure of the cost of a route. For example, if vertices A and B represent towns in a road network, then weight on edge AB may represent the cost of moving from A to B, or vice versa.

---
Graph and Vertices
Difficulty: EasyAccuracy: 59.13%Submissions: 28K+Points: 2
Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.

 

Example 1:

Input: 2
Output: 2
Example 2:

Input: 5
Output: 1024
 

Your Task:

Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.

 

Expected Time Complexity: O(1)

Expected Space Complexity: O(1)



 ---
 ```cpp
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        int sum=((n-1)*n)/2;
        return (1LL<<sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends
```

The expression provided:

```cpp
int sum = ((n-1) * n) / 2;
return (1LL << sum);
```

is a combination of two mathematical concepts. Let’s break down each part to understand the meaning behind it and its application in graph theory.

### 1. **Understanding the `sum = ((n-1) * n) / 2` Expression:**

- This formula calculates the total number of edges in a **complete graph** with `n` nodes.
- A **complete graph** is a graph where every node is connected to every other node. If there are `n` nodes, the number of edges in a complete graph is given by the formula:
  
  \[
  \text{Number of Edges} = \frac{(n-1) \times n}{2}
  \]

- Why is this the case? The total number of ways to pick 2 nodes out of `n` nodes (i.e., the number of edges) is given by the **combinatorial formula** for choosing 2 items from `n` items:

  \[
  C(n, 2) = \frac{n \times (n-1)}{2}
  \]
  Number of Edges= 
2
(n−1)×n
​
 


  This formula gives the total number of **distinct pairs** of nodes that can form an edge.

So, in the code snippet:

```cpp
int sum = ((n-1) * n) / 2;
```

The `sum` variable represents the **total number of edges** in a complete graph with `n` nodes.

### 2. **Understanding `(1LL << sum)` Operation:**

- The expression `(1LL << sum)` is a **bitwise left shift** operation. Let's break it down:
  
  - `1LL` is a constant representing the integer `1` of type `long long` (to ensure that it can hold large values).
  
  - The operation `1LL << sum` shifts the binary representation of `1` to the left by `sum` positions.
  
  - This is equivalent to calculating:

    \[
    2^{\text{sum}}
    \]

- Why use this expression in graph problems?

  - In graph theory, if you have a **complete graph** with `n` nodes, the total number of edges is `sum`. For a graph with `sum` edges, the **number of distinct subgraphs** that can be formed is `2^{\text{sum}}`.

  - Each of the `sum` edges can either be present or absent in a subgraph. Thus, there are `2` possibilities for each edge, and for `sum` edges, the total number of combinations (i.e., distinct subgraphs) is `2^{\text{sum}}`.

### 3. **Putting It All Together:**

- `int sum = ((n-1) * n) / 2;`
  - This calculates the total number of edges in a **complete graph** with `n` nodes.

- `return (1LL << sum);`
  - This calculates `2^{\text{sum}}`, which represents the **total number of distinct subgraphs** that can be formed in a complete graph with `n` nodes.

### Example:

Let’s see this with a small example:

1. Suppose `n = 3` (a complete graph with 3 nodes):
  
   - Total number of edges = \(\frac{(3-1) \times 3}{2} = 3\).

2. The value of `sum` would be `3`.

3. `1LL << 3` is `2^3 = 8`.

Thus, there are `8` distinct subgraphs that can be formed in a complete graph with 3 nodes.

### Application in Graph Theory:

This concept is often used to count the **total number of distinct subgraphs** in a complete graph or to analyze **all possible configurations** of edges in a graph. It provides a way to enumerate all possible subgraphs and analyze them for various properties, such as connectedness or specific subgraph patterns.

Hope this helps clarify the mathematical meaning behind the code!
