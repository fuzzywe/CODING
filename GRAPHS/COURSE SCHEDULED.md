207. Course Schedule
Medium
Topics
Companies
Hint
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
