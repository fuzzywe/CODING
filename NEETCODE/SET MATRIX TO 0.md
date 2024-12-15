The **difference between ordered and unordered sets** lies in their internal implementation and behavior, specifically regarding the ordering of elements, performance characteristics, and supported operations.

---

### **1. Ordered Set**
An **ordered set** (e.g., `std::set` in C++) is a set that:
- **Maintains a specific order** for the elements, typically in ascending order.
- **Underlying implementation**: It is implemented as a self-balancing binary search tree (e.g., Red-Black Tree).
- **Operations**:
  - Insertion, deletion, and search are performed in **O(log n)** time.
  - You can iterate through the set in **sorted order**.
- **Key Features**:
  - Elements are always kept sorted.
  - Supports functions like `lower_bound`, `upper_bound`, and range-based queries.

#### Example:
```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> s; // Ordered set
    s.insert(3);
    s.insert(1);
    s.insert(2);

    for (int x : s) {
        cout << x << " "; // Output: 1 2 3
    }
    return 0;
}
```

---

### **2. Unordered Set**
An **unordered set** (e.g., `std::unordered_set` in C++) is a set that:
- **Does not maintain any specific order** of the elements.
- **Underlying implementation**: It is implemented as a hash table.
- **Operations**:
  - Average-case insertion, deletion, and search are performed in **O(1)** time.
  - However, in the **worst case**, these operations can degrade to **O(n)** time (due to hash collisions).
- **Key Features**:
  - Faster than an ordered set for most operations (in the average case).
  - Does not support range-based queries like `lower_bound` or `upper_bound`.

#### Example:
```cpp
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    unordered_set<int> us; // Unordered set
    us.insert(3);
    us.insert(1);
    us.insert(2);

    for (int x : us) {
        cout << x << " "; // Output: Order is unpredictable, e.g., 3 1 2
    }
    return 0;
}
```

---

### **Comparison Table**

| Feature                        | Ordered Set (`std::set`) | Unordered Set (`std::unordered_set`) |
|--------------------------------|--------------------------|---------------------------------------|
| **Order of elements**          | Sorted                  | Unpredictable                        |
| **Underlying Data Structure**  | Red-Black Tree          | Hash Table                           |
| **Insertion/Deletion/Search**  | `O(log n)`              | `O(1)` (average), `O(n)` (worst)     |
| **Iteration**                  | In sorted order         | In arbitrary order                   |
| **Extra Operations**           | Supports `lower_bound`, `upper_bound`, range queries | Not supported                        |
| **Use Case**                   | When ordering is needed | When performance is critical         |

---

### **When to Use?**
- **Ordered Set**: Use it when you need sorted data or perform operations like finding the smallest/largest element in a range.
- **Unordered Set**: Use it when you need fast lookups, insertions, or deletions and don’t care about the order of elements.


73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 https://leetcode.com/problems/set-matrix-zeroes/description/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> setRows; 
        unordered_set<int> setColumns; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(setRows.count(i) > 0 || setColumns.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};






/*

    Time Complexity : O(N*M), Where N is the number of row and M is number of column of matrix. Here two nested 
    loops creates the time complexity.

    Space Complexity : O(1), Constant space.

    Solved using Matrix.

*/
```

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};






/*

    Time Complexity : O((N*M)*(N+M)), Where N is the number of row and M is number of column of matrix. Here
    nested loops creates the time complexity. O(N*M) for traversing through each element and (N+M)for traversing
    to row and column of elements having value 0.

    Space Complexity : O(1), Constant space.

    Solved using Matrix.

*/
```
