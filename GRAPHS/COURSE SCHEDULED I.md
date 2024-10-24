207. Course Schedule

https://leetcode.com/problems/course-schedule/solutions/1787341/c-dfs-20-lines-simple/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

---

The problem you're working with is called **Course Schedule**, and it revolves around determining whether you can complete all the courses given certain prerequisites. It's essentially about detecting **cyclic dependencies** in a directed graph, where courses are represented as vertices, and prerequisites are directed edges between them.

Let's break down the two examples.

### Example 1:

**Input:** `numCourses = 2`, `prerequisites = [[1,0]]`

This means there are 2 courses labeled `0` and `1`. The prerequisite `[1, 0]` means:
- To take course `1`, you must first complete course `0`.

So, the dependency graph looks like this:

```
0 → 1
```

#### Can you finish all the courses?
- You can first take course `0` (no prerequisites for `0`).
- After completing course `0`, you can take course `1` (since you've already completed course `0`).

**Result:** `true` — It is possible to finish all the courses because there are no cycles, and the dependency can be satisfied.

### Example 2:

**Input:** `numCourses = 2`, `prerequisites = [[1,0], [0,1]]`

In this case, the prerequisite pairs are:
- `[1, 0]`: To take course `1`, you must first complete course `0`.
- `[0, 1]`: To take course `0`, you must first complete course `1`.

The dependency graph looks like this:

```
0 → 1
↑    ↓
1 ← 0
```

#### Can you finish all the courses?
- To take course `1`, you need to finish course `0`.
- But to take course `0`, you need to finish course `1`.

This forms a **cycle** where both courses depend on each other, which makes it **impossible** to satisfy both dependencies.

**Result:** `false` — You cannot finish all the courses because the circular dependency creates a deadlock. Neither course can be taken without the other being completed first.

### Key Concept: Cycles in Graphs
- **No Cycles:** If there are no cycles in the graph (as in Example 1), it is possible to finish all courses by following the dependency order (i.e., topological order).
- **Cycle Detected:** If there is a cycle in the graph (as in Example 2), it is **impossible** to finish all courses because there's a circular dependency.

### Approach:
This problem can be solved using **topological sorting** or **cycle detection** algorithms (like DFS or BFS using Kahn’s algorithm for topological sort). The goal is to detect whether there are any cycles in the course dependency graph, as cycles make it impossible to complete all courses.

### Summary:
- **Example 1:** No cycles → return `true`.
- **Example 2:** Cycle detected → return `false`.

---

it's a dfs but usging three types of states.
```cpp

class Solution {
public:
    
    //Normal dfs but using, three sets.
    bool dfs(int v , vector<vector<int>> &adj , vector<int> &visited){
        visited[v] = 1;
        for(int u : adj[v]){
           if(!visited[u]){
              visited[u] = 1; 
              if(dfs(u , adj , visited)) return true;
           //If the node is 1, it means we have a cycle.
           }else if(visited[u] == 1){
               return true;
           }
        }
        //All neighbors visited.
        visited[v] = 2;
        return false;
    } 
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Three sets, not visited = 0 , partial visited = 1 , all visited = 2.
        vector<int> visited(numCourses, 0);
        
        //Build a graph 
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // Check if there is a cycle , run a dfs for every node that is not visited.
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i] && dfs(i , adj , visited)) return false;
        }
        return true;
    }
};
```
Sure! Let’s walk through a detailed dry run of the code, explaining each line of execution. We will dry run it with the following input:

### Input:
- `numCourses = 2`
- `prerequisites = [[1, 0]]`

This means that to take course `1`, you must first take course `0`.

### Dry Run:

#### Initial Input:
- `numCourses = 2`
- `prerequisites = [[1, 0]]`

### Step-by-Step Dry Run:

---

#### **Step 1: Initialization**

```cpp
vector<vector<int>> adj(numCourses);
```
- This line creates an adjacency list `adj` of size `numCourses` (2). 
- Initially, `adj` will look like this:
  ```
  adj = [[], []]
  ```

```cpp
vector<int> visited(numCourses, 0);
```
- This line creates a `visited` vector of size `numCourses` (2), initialized with `0`, meaning that no course has been visited yet.
- Initially, `visited` will look like this:
  ```
  visited = [0, 0]
  ```

---

#### **Step 2: Build the Graph**

```cpp
for(int i = 0; i < prerequisites.size(); i++) {
    adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
}
```
- Here, we loop through the `prerequisites` list to build the adjacency list.

- **First iteration (`i = 0`)**:
  - `prerequisites[0] = [1, 0]` means that to take course `1`, you must first take course `0`.
  - So, we update the adjacency list to add `1` as a neighbor of `0`:
    ```
    adj[0].push_back(1);
    ```
  - Now, `adj` looks like this:
    ```
    adj = [[1], []]
    ```

---

#### **Step 3: Perform DFS to Detect Cycle**

```cpp
for(int i = 0; i < numCourses; i++) {
    if(!visited[i] && dfs(i, adj, visited)) return false;
}
```
- Now, we iterate over each course (from `0` to `1`) to check if it can be completed without encountering a cycle.

- **First iteration (`i = 0`)**:
  - `visited[0] == 0`, so we haven't visited course `0` yet.
  - We call the `dfs()` function to perform DFS starting from course `0`.

---

#### **Step 4: DFS for Course 0**

```cpp
bool dfs(int v, vector<vector<int>> &adj, vector<int> &visited) {
    visited[v] = 1;
```
- We start DFS from course `0` (`v = 0`).
- Set `visited[0] = 1` to mark course `0` as "visiting".
- Now, `visited` looks like this:
  ```
  visited = [1, 0]
  ```

---

```cpp
for(int u : adj[v]) {
```
- This loop goes through all the neighbors of course `0`. In this case, course `1` is a neighbor of `0` (`adj[0] = [1]`).

- **First iteration (`u = 1`)**:
  - Course `1` is a neighbor of course `0`.

---

```cpp
if(!visited[u]) {
    visited[u] = 1;
    if(dfs(u, adj, visited)) return true;
```
- Since `visited[1] == 0`, course `1` hasn't been visited yet.
- We set `visited[1] = 1` to mark course `1` as "visiting".
- Now, `visited` looks like this:
  ```
  visited = [1, 1]
  ```

- We call `dfs(1, adj, visited)` to perform DFS from course `1`.

---

#### **Step 5: DFS for Course 1**

```cpp
visited[v] = 1;
```
- We start DFS from course `1` (`v = 1`).
- Course `1` is already marked as "visiting", so no change to the `visited` vector.

```cpp
for(int u : adj[v]) {
```
- This loop checks the neighbors of course `1`. Since `adj[1] = []`, there are no neighbors for course `1`.

---

```cpp
visited[v] = 2;
return false;
```
- Since there are no neighbors for course `1`, we mark course `1` as "fully visited" by setting `visited[1] = 2`.
- Now, `visited` looks like this:
  ```
  visited = [1, 2]
  ```

- Return `false`, indicating no cycle has been found in this path.

---

#### **Step 6: Back to DFS for Course 0**

- We return to the DFS function call for course `0` (from step 4).

```cpp
visited[v] = 2;
return false;
```
- After processing all neighbors of course `0`, we mark course `0` as "fully visited" by setting `visited[0] = 2`.
- Now, `visited` looks like this:
  ```
  visited = [2, 2]
  ```

- Return `false`, indicating no cycle has been found in this path.

---

#### **Step 7: Continue the Loop**

- We return to the main function `canFinish()` and continue the loop over the courses.

- **Second iteration (`i = 1`)**:
  - Since `visited[1] == 2`, course `1` has already been fully visited, so we skip the DFS for this course.

---

#### **Final Step: Return the Result**

```cpp
return true;
```
- After checking all courses and finding no cycles, we return `true`, meaning it is possible to finish all courses.

---

### Final Output:
The function returns `true`, which means it is possible to complete all courses.

---

### Example of Cyclic Case:

Let's consider the cyclic case with the following input:

**Input:**
- `numCourses = 2`
- `prerequisites = [[1, 0], [0, 1]]`

In this case:
- Course `1` depends on course `0`, and course `0` depends on course `1`. This creates a cycle.

---

#### Dry Run for Cyclic Case:

1. **Graph Construction:**
   - `adj = [[1], [0]]`
   - This means course `0` depends on `1` and vice versa.

2. **DFS from Course 0:**
   - We start DFS from course `0` and mark it as "visiting" (`visited[0] = 1`).
   - We visit course `1` (neighbor of `0`) and mark it as "visiting" (`visited[1] = 1`).
   - From course `1`, we try to visit course `0` (neighbor of `1`), but since `visited[0] = 1` (currently visiting), this indicates a cycle.
   - Return `true`, indicating a cycle has been found.

3. **Return False:**
   - Since a cycle has been detected, the function returns `false`, meaning it is not possible to finish all courses.

---

### Summary of Code:

- The `dfs()` function uses depth-first search to explore all courses and detect cycles.
- The `visited` vector tracks the state of each course (not visited, visiting, or fully visited).
- If a cycle is found, the function returns `false`; otherwise, it returns `true`.

can you please explain why are you marking visited[v]=2 , in the end of the function


when we visit the node we mark 1(was 0) than we iterate through the neighbors u of the node when we 're done with the neighbors we mark the visited node to 2 mean that we completly visited it with their neighbor so we can move to the next node

