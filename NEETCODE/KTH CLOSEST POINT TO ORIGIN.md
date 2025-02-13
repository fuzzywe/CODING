https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=plakya4j

```cpp

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};


```


Here’s a step-by-step explanation of the given C++ code for finding the **K closest points to the origin** \((0,0)\) using **partial_sort**.  

---

### **Problem Understanding**
We are given a list of points in a 2D plane. Each point is represented as \([x, y]\). The **distance** of a point from the origin \((0,0)\) is calculated using the **Euclidean distance formula**:

\[
\text{distance}^2 = x^2 + y^2
\]

Since we only need to compare distances, we avoid computing the square root because it is unnecessary for comparison.

Our goal is to find the **K closest** points to the origin.

---

### **Code Breakdown**
```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
```

---

### **Step-by-Step Execution**
#### **Step 1: Function Definition**
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
```
- The function takes:
  - `points`: A vector of 2D points.
  - `K`: The number of closest points to return.

#### **Step 2: Sorting Using `partial_sort`**
```cpp
partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
    return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
});
```
✅ **What `partial_sort` does?**
- It **partially sorts** the first `K` elements in `points`, ensuring that the **K smallest** elements are at the beginning.
- However, unlike `sort`, which sorts the entire array, `partial_sort` **does not fully sort the remaining elements**.

✅ **How does the comparator work?**
- The **lambda function** compares two points **p** and **q** based on their squared Euclidean distances.
- Instead of computing the actual distance, we compare **p[0]² + p[1]²** with **q[0]² + q[1]²**.

✅ **Time Complexity:**  
- `partial_sort()` runs in **O(N log K)** on average, making it more efficient than a full sort (`O(N log N)`).

#### **Step 3: Returning the First K Points**
```cpp
return vector<vector<int>>(points.begin(), points.begin() + K);
```
- This **returns only the first `K` closest points** from the sorted list.

---

### **Example Execution**
#### **Input**
```cpp
points = {{3, 3}, {5, -1}, {-2, 4}};
K = 2;
```
#### **Step 1: Compute Squared Distances**
| Point  | Distance² |
|--------|----------|
| (3,3)  | \(3^2 + 3^2 = 9 + 9 = 18\) |
| (5,-1) | \(5^2 + (-1)^2 = 25 + 1 = 26\) |
| (-2,4) | \((-2)^2 + 4^2 = 4 + 16 = 20\) |

#### **Step 2: Apply `partial_sort`**
`partial_sort` moves the two smallest distance points to the front.

Sorted order:
```
[(3,3), (-2,4), (5,-1)]
```
(The order of (3,3) and (-2,4) may vary as long as they remain in the first `K` positions.)

#### **Step 3: Return First `K` Points**
Output:
```cpp
{{3, 3}, {-2, 4}}
```

---

### **Key Takeaways for Interview**
✅ **Why use `partial_sort` instead of `sort`?**
- **Efficiency:** `partial_sort` only sorts the first `K` elements → **O(N log K)** instead of **O(N log N)**.

✅ **Why compare squared distances instead of actual distances?**
- Computing the square root (√) is **unnecessary** for comparison.

✅ **Alternative Approach**
- Instead of sorting, we could use a **max heap (priority queue)** to maintain only the top `K` smallest distances in **O(N log K)**.

---No worries! Let's break it down step by step.  

---

### **Understanding This Line:**
```cpp
return vector<vector<int>>(points.begin(), points.begin() + K);
```
This line **creates and returns a new vector** containing only the first `K` points from `points`.

---

### **Breaking It Down**
#### **1️⃣ `points.begin()` and `points.begin() + K`**
- `points.begin()` → **Iterator to the first element** of `points`.
- `points.begin() + K` → **Iterator to the (K+1)th element** of `points` (i.e., the element **after** the first `K` elements).

#### **2️⃣ `vector<vector<int>>(...)`**
- This creates a **new vector** of `vector<int>` (2D vector).
- It **copies** the elements from `points.begin()` **up to (but not including)** `points.begin() + K`.

---

### **Equivalent Code Without Using Iterators**
If you find iterators confusing, the above line is equivalent to:
```cpp
vector<vector<int>> result;
for (int i = 0; i < K; i++) {
    result.push_back(points[i]); // Copy the first K elements
}
return result;
```
- This does the same thing as `return vector<vector<int>>(points.begin(), points.begin() + K);` but in a more explicit way.

---

### **Example Execution**
#### **Given:**
```cpp
vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
int K = 2;
```
After sorting, assume `points` becomes:
```cpp
points = {{3,3}, {-2,4}, {5,-1}};
```
Then:
```cpp
vector<vector<int>>(points.begin(), points.begin() + 2);
```
creates a new vector:
```cpp
{{3, 3}, {-2, 4}}
```
and returns it.

---

### **Key Takeaways**
✅ **`points.begin() + K` acts like an index limit** → It **excludes** the element at `K`.  
✅ **Creates a new vector** containing **only the first `K` elements**.  
✅ **Equivalent to using a loop** but written in a **shorter, more optimized** way.  

This C++ solution finds the **K closest points to the origin** using a **Max Heap (Priority Queue)**. Let's go step by step. 🚀  

---

## **Understanding the Approach**
- Instead of sorting all points (which takes \(O(N \log N)\)), we use a **max heap** to efficiently keep track of the K closest points.
- A **max heap** ensures that the **farthest point** among the current K points is always at the top.
- If the heap size exceeds **K**, we remove the farthest point.
- Finally, we extract the K closest points.

---

## **Code Breakdown**
### **Step 1: Function Definition**
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
```
- **Input:**  
  - `points`: A 2D vector where each point is \([x, y]\).
  - `k`: Number of closest points to return.
- **Output:**  
  - A new 2D vector containing `k` closest points to the origin \((0,0)\).

---

### **Step 2: Max Heap Initialization**
```cpp
priority_queue<pair<int, vector<int>>> maxHeap;
```
- We use a **max heap (priority queue)** that stores:
  - **Pair:** `{distance, point}`
  - **Max heap behavior:** The point with the **largest distance** stays at the top.

---

### **Step 3: Iterate Over All Points**
```cpp
for (auto& point : points) {
    int distance = point[0] * point[0] + point[1] * point[1]; // Compute squared distance
    maxHeap.push({distance, point}); // Insert point into max heap
    
    if (maxHeap.size() > k) maxHeap.pop(); // Remove farthest point if size > K
}
```
🔹 **How it works?**
1. **Calculate the squared distance** to avoid unnecessary square roots:
   \[
   \text{distance}^2 = x^2 + y^2
   \]
2. **Push** `{distance, point}` into `maxHeap`.
3. If the heap size **exceeds `K`**, **remove the farthest point** (this keeps only the K closest points).

🔹 **Why use a max heap?**  
- The **farthest point** in the heap is **always on top**.
- When we exceed `K`, we **remove the farthest** point → ensuring the heap always contains the K closest points.

✅ **Heap size never exceeds `K` → Better efficiency than sorting all points.**  

---

### **Step 4: Extract `K` Closest Points**
```cpp
vector<vector<int>> ans;
while (!maxHeap.empty()) {
    ans.push_back(maxHeap.top().second); // Extract the closest point
    maxHeap.pop();
}
```
- Extracts **the `K` closest points** from the heap and stores them in `ans`.

---

## **Example Execution**
### **Input:**
```cpp
points = {{3, 3}, {5, -1}, {-2, 4}};
k = 2;
```

### **Step 1: Compute Distances**
| Point  | Squared Distance |
|--------|-----------------|
| (3,3)  | \(3^2 + 3^2 = 9 + 9 = 18\) |
| (5,-1) | \(5^2 + (-1)^2 = 25 + 1 = 26\) |
| (-2,4) | \((-2)^2 + 4^2 = 4 + 16 = 20\) |

### **Step 2: Heap Operations**
#### **Iteration 1: Push (3,3)**
Heap:  
```
[(18, (3,3))]
```

#### **Iteration 2: Push (5,-1)**
Heap:  
```
[(26, (5,-1)), (18, (3,3))]  // Max heap (sorted by distance)
```

#### **Iteration 3: Push (-2,4)**
Heap:  
```
[(26, (5,-1)), (18, (3,3)), (20, (-2,4))]
```
- Since `heap.size() > k (3 > 2)`, **pop the farthest (5,-1)**:
```
[(20, (-2,4)), (18, (3,3))]
```
(K closest points remain.)

### **Step 3: Extract `K` Closest Points**
Heap contents:
```
(20, (-2,4))
(18, (3,3))
```
Final output:
```cpp
{{-2, 4}, {3, 3}}
```
(*Order may vary since we’re not sorting at the end.*)

---

## **Time Complexity Analysis**
🔹 **Building the Heap:**  
- Each push/pop operation takes **O(log K)**.
- Since we process **N points**, total time is **O(N log K)**.

🔹 **Extracting K elements:**  
- Takes **O(K log K)** (but usually smaller than O(N log K)).

✅ **Overall Complexity: O(N log K)** (better than **O(N log N)** sorting).  

---

## **Why Use a Max Heap Instead of Sorting?**
| Approach       | Time Complexity | Space Complexity |
|---------------|---------------|----------------|
| Sorting (`sort()`) | **O(N log N)** | **O(1)** |
| Partial Sort (`partial_sort()`) | **O(N log K)** | **O(1)** |
| **Max Heap (`priority_queue`)** | **O(N log K)** | **O(K)** |

- The **heap approach is faster** than sorting for large `N` and small `K`.
- Sorting is overkill when we only need `K` closest elements.

---

## **Key Takeaways for Interview**
✅ **Uses a Max Heap (`priority_queue`)** to efficiently track `K` closest points.  
✅ **Maintains heap size ≤ `K`** → ensuring only the `K` closest points remain.  
✅ **Time Complexity: O(N log K)** → Faster than full sorting (`O(N log N)`).  
✅ **Avoids unnecessary sqrt calculations** by comparing squared distances.  

---

### **Alternative Approach: Min Heap**
Instead of using a **max heap** with size `K`, we can:
- Use a **min heap** of size `N` and extract `K` elements → takes **O(N + K log N)**.
- But **max heap is more space-efficient** for large `N`.

---

🚀 **Hope this helps! Let me know if you have any doubts!** 😊
