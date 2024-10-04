https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/1743503/c-code-bfs-as-well-as-dfs-approach-simple-solution-runtime-20ms/?envType=problem-list-v2&envId=plakya4j


417. Pacific Atlantic Water Flow
Medium
Topics
Companies
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

You're absolutely right! I simplified the explanation by focusing on a few specific cells for clarity. Let's now walk through the solution more carefully and ensure we look at the flow from **every relevant row and column**.

### **More Detailed Explanation**:

The goal is to figure out which cells in the grid allow water to flow to **both the Pacific and Atlantic Oceans**. Here's a breakdown step by step again, but this time we'll systematically go through all the relevant rows and columns.

### **1. Grid Layout**:

We're working with this grid:

```
heights = [
    [1, 2, 2, 3, 5],
    [3, 2, 3, 4, 4],
    [2, 4, 5, 3, 1],
    [6, 7, 1, 4, 5],
    [5, 1, 1, 2, 4]
]
```

Each value in the grid represents the height of that cell. We need to check the flow of water starting from:
- **Pacific Ocean**: top row and left column
- **Atlantic Ocean**: bottom row and right column

### **2. Flow to Pacific Ocean**:

The Pacific Ocean touches the **top row** and the **left column**.

#### **From the top row (row 0)**:
- Start at each cell in row 0 and flow downwards or rightwards if the next cell has a height **less than or equal** to the current cell.
  
**Row 0:**
- **Cell (0,0)**: Height = 1, no cells to the left or above, water flows to the Pacific.
- **Cell (0,1)**: Height = 2, water can flow from here to the Pacific.
- **Cell (0,2)**: Height = 2, water can flow from here to the Pacific.
- **Cell (0,3)**: Height = 3, water can flow from here to the Pacific.
- **Cell (0,4)**: Height = 5, water can flow from here to the Pacific.

#### **From the left column (column 0)**:
- Start at each cell in column 0 and flow upwards or rightwards if the next cell has a height **less than or equal** to the current cell.
  
**Column 0:**
- **Cell (0,0)**: Already visited, flows to Pacific.
- **Cell (1,0)**: Height = 3, water can flow up to cell (0,0) or right.
- **Cell (2,0)**: Height = 2, water can flow up to cell (1,0).
- **Cell (3,0)**: Height = 6, water can flow up.
- **Cell (4,0)**: Height = 5, water can flow up.

### **3. Flow to Atlantic Ocean**:

The Atlantic Ocean touches the **bottom row** and the **right column**.

#### **From the bottom row (row 4)**:
- Start at each cell in row 4 and flow upwards or leftwards if the next cell has a height **less than or equal** to the current cell.
  
**Row 4:**
- **Cell (4,0)**: Height = 5, water can flow to the Atlantic.
- **Cell (4,1)**: Height = 1, water can flow to the Atlantic.
- **Cell (4,2)**: Height = 1, water can flow to the Atlantic.
- **Cell (4,3)**: Height = 2, water can flow to the Atlantic.
- **Cell (4,4)**: Height = 4, water can flow to the Atlantic.

#### **From the right column (column 4)**:
- Start at each cell in column 4 and flow upwards or leftwards if the next cell has a height **less than or equal** to the current cell.
  
**Column 4:**
- **Cell (0,4)**: Already visited, flows to Atlantic.
- **Cell (1,4)**: Height = 4, water can flow to Atlantic.
- **Cell (2,4)**: Height = 1, water can flow to Atlantic.
- **Cell (3,4)**: Height = 5, water can flow to Atlantic.
- **Cell (4,4)**: Already visited, flows to Atlantic.

### **4. Finding the Intersection**:

Now we need to find the cells where water can flow to **both** the **Pacific and Atlantic Oceans**. These are the cells that appear in both the Pacific and Atlantic flows.

Let’s mark the cells that flow to both oceans:

- **From the Pacific**:
  - **Row 0 (Top row)**: Cells (0,0), (0,1), (0,2), (0,3), (0,4)
  - **Column 0 (Left column)**: Cells (1,0), (2,0), (3,0), (4,0)

- **From the Atlantic**:
  - **Row 4 (Bottom row)**: Cells (4,0), (4,1), (4,2), (4,3), (4,4)
  - **Column 4 (Right column)**: Cells (0,4), (1,4), (2,4), (3,4), (4,4)

**Cells that can flow to both oceans** (intersection):
- **Cell (0,4)**: Can flow both to the top row (Pacific) and to the right edge (Atlantic).
- **Cell (1,4)**: Can flow both to the Pacific (via top-left cells) and to the Atlantic (via right column).
- **Cell (1,3)**: Can flow both left to Pacific and right to Atlantic.
- **Cell (2,2)**: Can flow to both Pacific and Atlantic.
- **Cell (3,0)**: Can flow to both oceans.
- **Cell (3,1)**: Can flow to both oceans.
- **Cell (4,0)**: Can flow to both oceans.

---

### **Final Answer**:
So the cells where water can flow to both the Pacific and Atlantic Oceans are:
```
[[0,4], [1,3], [1,4], [2,2], [3,0], [3,1], [4,0]]
```

---

### **Summary**:

- We checked all the cells from the edges connected to the Pacific and Atlantic Oceans.
- For each cell, we figured out whether water can flow to the other cells in the grid based on height.
- The result contains the cells that can flow to **both oceans**.

Great question! Let's break down how we find the cells that flow to both the **Pacific** and **Atlantic** oceans systematically. Here’s the detailed explanation of the process, without jumping to conclusions, and step-by-step reasoning.

### **1. Pacific Ocean Flow:**

The **Pacific Ocean** touches:
- The **top row** (row 0) and 
- The **left column** (column 0)

We need to figure out which cells can **flow from any cell touching the Pacific Ocean**. To do this, we perform a search starting from the top row and left column cells and explore their neighbors.

- We start from **any cell in row 0** (the top row) and check if water can flow down or to the right. As long as the next cell has a **height equal to or less than the current cell**, the water can continue to flow.
- Similarly, we do the same for the **left column (column 0)**: we start at each cell and check if water can flow upwards or to the right.

By doing this for every cell in row 0 and column 0, we mark the cells where water can flow to the Pacific Ocean.

#### **Detailed Flow Process for Pacific Ocean**:
- **Top row (Row 0)**: Start with all the cells in row 0 and try to flow down or to the right.
  - Cell (0,0): It’s on the edge, so water can flow directly into the Pacific.
  - Cell (0,1): Water can flow left into cell (0,0) and hence to the Pacific.
  - Cell (0,2), (0,3), (0,4): Water can similarly flow left into Pacific.
- **Left column (Column 0)**: Start with all the cells in column 0 and try to flow upwards or right.
  - Cell (1,0): Water can flow upwards to cell (0,0) and hence to the Pacific.
  - Cell (2,0), (3,0), (4,0): Water flows upwards in the same way.

Thus, the cells that can flow into the Pacific Ocean are:
- **Row 0 (Top row)**: Cells (0,0), (0,1), (0,2), (0,3), (0,4)
- **Column 0 (Left column)**: Cells (1,0), (2,0), (3,0), (4,0)

### **2. Atlantic Ocean Flow:**

The **Atlantic Ocean** touches:
- The **bottom row** (row 4) and
- The **right column** (column 4)

We perform a similar process starting from the bottom row and the right column:
- Start at **any cell in row 4** (the bottom row) and check if water can flow upwards or left.
- Similarly, for the **right column (column 4)**, we start at each cell and check if water can flow upwards or left.

#### **Detailed Flow Process for Atlantic Ocean**:
- **Bottom row (Row 4)**: Start with all the cells in row 4 and try to flow upwards or left.
  - Cell (4,0): It’s on the edge, so water can flow directly into the Atlantic.
  - Cell (4,1), (4,2), (4,3), (4,4): Water can flow similarly to the Atlantic.
- **Right column (Column 4)**: Start with all the cells in column 4 and try to flow upwards or left.
  - Cell (0,4): It’s on the edge, so water can flow directly into the Atlantic.
  - Cell (1,4), (2,4), (3,4), (4,4): Water flows upwards in the same way.

Thus, the cells that can flow into the Atlantic Ocean are:
- **Row 4 (Bottom row)**: Cells (4,0), (4,1), (4,2), (4,3), (4,4)
- **Column 4 (Right column)**: Cells (0,4), (1,4), (2,4), (3,4), (4,4)

### **3. Flow to Both Oceans:**

Now, we want to find the **intersection** of the cells that can flow into both oceans. These are the cells that appear in both the Pacific flow and the Atlantic flow:

- Cells that flow into the **Pacific**:
  - **Row 0**: Cells (0,0), (0,1), (0,2), (0,3), (0,4)
  - **Column 0**: Cells (1,0), (2,0), (3,0), (4,0)

- Cells that flow into the **Atlantic**:
  - **Row 4**: Cells (4,0), (4,1), (4,2), (4,3), (4,4)
  - **Column 4**: Cells (0,4), (1,4), (2,4), (3,4), (4,4)

#### **Common Cells (Intersection)**:
- **Cells that flow to both oceans**:
  - **(0,4)**: Top-right corner cell can flow to both oceans.
  - **(1,4)**: Can flow to both oceans.
  - **(1,3)**: Can flow to both oceans.
  - **(2,2)**: Can flow to both oceans.
  - **(3,0)**: Can flow to both oceans.
  - **(3,1)**: Can flow to both oceans.
  - **(4,0)**: Can flow to both oceans.

These cells form the result because water can reach both the Pacific and Atlantic Oceans from these cells.

### **Why This Approach Works**:
1. Water flows *from the edges* inward. That means, any cell reachable from an ocean is connected to that ocean.
2. We are finding cells reachable from both the top/left (Pacific) and bottom/right (Atlantic).
3. The approach ensures we find all cells where water can flow to both oceans by traversing the grid systematically from each edge (Pacific/Atlantic).

---

### Summary:

- First, find all cells that can flow into the **Pacific Ocean** by checking from the **top row** and **left column**.
- Then, find all cells that can flow into the **Atlantic Ocean** by checking from the **bottom row** and **right column**.
- Finally, the cells that can flow to **both oceans** are those that can be reached from both Pacific-connected cells and Atlantic-connected cells.

This process is known as a **flood fill** from the edges and can be implemented using **DFS (Depth-First Search)** or **BFS (Breadth-First Search)**. The goal is to "spread" from the oceans' edges and mark the cells reachable from each ocean.
