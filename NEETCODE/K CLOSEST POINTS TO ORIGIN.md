973. K Closest Points to Origin
Medium
Topics
Companies
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.



```
#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pii>> pq;//max priority queue so that besi durot thaka point tu agot thake in the priorirty queue
        for(int i=0;i<points.size();i++){
            int d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push(make_pair(d,make_pair(points[i][0],points[i][1])));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(pq.empty()==false){
            auto it=pq.top();
            pq.pop();
            res.push_back(vector<int> {it.second.first,it.second.second});
        }
        return res;
        
    }
};
```
Let's go through this code step-by-step to understand how it works and dry run each part of the algorithm to find the `k` closest points to the origin.

### Input:
The input consists of:
1. A 2D array `points`, where each element is a vector representing the coordinates of a point `(x, y)`.
2. An integer `k`, which represents the number of closest points to return.

### Code Breakdown:

#### Line-by-Line Explanation:

1. **`#define pii pair<int,int>`**  
   - This is a macro that defines `pii` as a shorthand for `pair<int, int>`. It makes the code easier to read, especially when dealing with pairs of integers.

2. **`vector<vector<int>> kClosest(vector<vector<int>>& points, int k)`**  
   - This is the function header that takes the `points` and the integer `k`, and it returns a vector of `k` closest points to the origin.

3. **`priority_queue<pair<int,pii>> pq;`**  
   - Declares a max-priority queue `pq` that stores pairs of the form `(distance, pair(x, y))`. This queue helps in keeping track of the `k` closest points to the origin, with the farthest point at the top.

4. **`for(int i=0;i<points.size();i++)`**  
   - This loop iterates over each point in the `points` array. Let's break down what happens inside this loop:

   1. **`int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];`**  
      - Calculates the squared distance `d` from the origin for the current point `(x, y)`. The squared distance formula is used to avoid computing the square root (which is unnecessary for comparison purposes).  
      - Squared distance = `x^2 + y^2`.
      
   2. **`pq.push(make_pair(d, make_pair(points[i][0], points[i][1])));`**  
      - Pushes the current point along with its squared distance into the priority queue. Since the priority queue is a max-heap by default, the point with the largest squared distance will be at the top of the queue.
      
   3. **`if(pq.size() > k) { pq.pop(); }`**  
      - If the size of the priority queue exceeds `k`, the point with the largest squared distance (at the top of the heap) is removed. This ensures that the priority queue only holds the `k` closest points at any given time.

5. **`vector<vector<int>> res;`**  
   - Declares a result vector `res` to store the `k` closest points.

6. **`while(pq.empty() == false)`**  
   - This loop continues until the priority queue is empty. It extracts the points stored in the priority queue and adds them to the result vector.

   1. **`auto it = pq.top(); pq.pop();`**  
      - Retrieves the top element from the priority queue (`it`) and removes it.
      
   2. **`res.push_back(vector<int> {it.second.first, it.second.second});`**  
      - Adds the point (stored in `it.second` as `x, y`) to the result vector.

7. **`return res;`**  
   - Returns the result vector containing the `k` closest points to the origin.

---

### Dry Run Example:

#### Input:
```plaintext
points = [[1, 3], [-2, 2], [5, 8], [0, 1]]
k = 2
```

1. **First point: [1, 3]**
   - Squared distance: `1^2 + 3^2 = 1 + 9 = 10`
   - Push `(10, (1, 3))` to the priority queue.
   - Queue state: `[(10, (1, 3))]`
   - Size of queue is not greater than `k`, so no popping.

2. **Second point: [-2, 2]**
   - Squared distance: `(-2)^2 + 2^2 = 4 + 4 = 8`
   - Push `(8, (-2, 2))` to the priority queue.
   - Queue state: `[(10, (1, 3)), (8, (-2, 2))]`
   - Size of queue is not greater than `k`, so no popping.

3. **Third point: [5, 8]**
   - Squared distance: `5^2 + 8^2 = 25 + 64 = 89`
   - Push `(89, (5, 8))` to the priority queue.
   - Queue state: `[(89, (5, 8)), (8, (-2, 2)), (10, (1, 3))]`
   - Queue size is greater than `k` (3 > 2), so pop the largest element, which is `(89, (5, 8))`.
   - Queue state: `[(10, (1, 3)), (8, (-2, 2))]`

4. **Fourth point: [0, 1]**
   - Squared distance: `0^2 + 1^2 = 0 + 1 = 1`
   - Push `(1, (0, 1))` to the priority queue.
   - Queue state: `[(10, (1, 3)), (8, (-2, 2)), (1, (0, 1))]`
   - Queue size is greater than `k` (3 > 2), so pop the largest element, which is `(10, (1, 3))`.
   - Queue state: `[(8, (-2, 2)), (1, (0, 1))]`

---

### Final Result:

The points in the priority queue are `[(8, (-2, 2)), (1, (0, 1))]`.

- These correspond to the points `[-2, 2]` and `[0, 1]`, which are the two closest points to the origin.

### Output:
```plaintext
[[ -2, 2 ], [ 0, 1 ]]
```

Thus, the final output would be `[[ -2, 2 ], [ 0, 1 ]]`.

These two lines calculate the squared distance of a point from the origin and then store this information in a **max-priority queue**. Let's break it down step by step:

### 1. **Calculate the Squared Distance:**
```cpp
int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
```
This line calculates the squared distance `d` of the point `points[i]` from the origin `(0, 0)`.

- `points[i][0]`: The `x` coordinate of the point.
- `points[i][1]`: The `y` coordinate of the point.

Using the **Euclidean distance formula**, the actual distance between a point `(x, y)` and the origin `(0, 0)` is:

\[
\text{distance} = \sqrt{x^2 + y^2}
\]

However, to avoid computing the square root (which is computationally expensive and unnecessary for comparison purposes), we calculate the **squared distance** instead:

\[
d = x^2 + y^2
\]

This squared distance `d` will be used to compare how far a point is from the origin without needing to compute the square root.

### Example:
For a point `(1, 3)`, the squared distance would be:

\[
d = 1^2 + 3^2 = 1 + 9 = 10
\]

### 2. **Store the Distance and Point in the Priority Queue:**
```cpp
pq.push(make_pair(d, make_pair(points[i][0], points[i][1])));
```

This line pushes a **pair** into the priority queue `pq`. 

- **`d`**: This is the squared distance from the origin (which we just calculated).
- **`make_pair(points[i][0], points[i][1])`**: This creates a pair `(x, y)` that represents the point's coordinates.

Thus, you are pushing a pair of the form:

\[
(d, (x, y))
\]

This way, the priority queue `pq` stores both the distance of a point and the point's coordinates. Since `priority_queue` by default is a **max-heap**, the element with the largest `d` (farthest point) will be at the top of the queue.

### Example:
For a point `(1, 3)` with a squared distance `d = 10`, the push operation would add the following pair to the priority queue:

\[
(10, (1, 3))
\]

This ensures that the farthest points can be easily removed (using `pq.pop()` when needed) to maintain only the `k` closest points in the priority queue.

### How the Priority Queue Works:
- The priority queue is a **max-heap**. It organizes pairs based on the squared distance `d`. The farthest point (with the largest `d`) will be at the top.
- As you iterate over all points and push them into the queue, the queue keeps track of the `k` closest points by removing the farthest points (using `pq.pop()`) when its size exceeds `k`.

This part of the code extracts the closest points from the **priority queue** (`pq`) and stores them in a result vector (`res`). Let’s walk through the code step by step:

### 1. **Declaring the Result Vector:**
```cpp
vector<vector<int>> res;
```
- This declares an empty `2D vector` named `res` that will store the `k` closest points.
- Each element of `res` will be a vector representing a point `(x, y)`.

### 2. **Extracting Points from the Priority Queue:**
```cpp
while(pq.empty() == false) {
    auto it = pq.top();
    pq.pop();
    res.push_back(vector<int> {it.second.first, it.second.second});
}
```
Let’s break this down:

- **`while(pq.empty() == false)`**: This loop continues until the priority queue `pq` is empty. The condition checks whether the priority queue contains any elements.

- **`auto it = pq.top();`**: This retrieves the element at the top of the priority queue without removing it. Since the priority queue is a max-heap, the top element will have the largest squared distance.

    - `it` is a `pair<int, pii>`, where:
      - `it.first` is the squared distance.
      - `it.second` is a pair `(x, y)` representing the coordinates of the point.

- **`pq.pop();`**: This removes the top element from the priority queue (the point with the largest squared distance).
  
- **`res.push_back(vector<int> {it.second.first, it.second.second});`**: This line constructs a `vector<int>` using the `x` and `y` coordinates from `it.second` and pushes it into the result vector `res`.
    - `it.second.first`: This is the `x` coordinate of the point.
    - `it.second.second`: This is the `y` coordinate of the point.
    - The `push_back` operation adds the point `(x, y)` to the `res` vector.

### Example:

Let’s assume that after processing the points, the priority queue contains:

```cpp
pq = [
    (8, (-2, 2)),
    (1, (0, 1))
]
```

The while loop will:
- First retrieve `(8, (-2, 2))`, pop it from the queue, and add `[-2, 2]` to `res`.
- Then retrieve `(1, (0, 1))`, pop it from the queue, and add `[0, 1]` to `res`.

At the end, the `res` vector will look like this:

```cpp
res = [
    [-2, 2],
    [0, 1]
]
```

### 3. **Returning the Result:**
```cpp
return res;
```
- Finally, the result vector `res` is returned. It contains the `k` closest points to the origin, sorted by the distance from the farthest to the closest (because of how they were popped from the max-heap).

### Summary of Steps:
- The **priority queue** stored the `k` closest points to the origin.
- The **while loop** extracted each point from the priority queue and added it to the result vector `res`.
- The function then returned `res`, which contains the `k` closest points.
