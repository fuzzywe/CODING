Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
Your Task:
You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

---

![image](https://github.com/user-attachments/assets/a6f065e8-2117-4072-9e81-c1831e878733)



![image](https://github.com/user-attachments/assets/6088b985-e152-44ef-aa00-f6b2a5341513)


---

```cpp

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> dist(100000,1e9);
        dist[start]=0;
        q.push({start,0});
        int mod=100000;
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                    if(num==end) return step+1;
                    q.push({num,step+1});
                }
            }
        }
        if(start==end) return 0;
        return -1;
    }
};

```

Certainly, here’s the provided code with an in-depth dry run for each line. This code is meant to find the **minimum number of multiplications** needed to transform a `start` number into an `end` number using a set of multipliers from the array `arr`, and each multiplication result is taken modulo 100,000 to keep numbers within a reasonable range. 

The code uses **Breadth-First Search (BFS)** to achieve this goal since BFS is ideal for finding the shortest path in an unweighted graph.

---

```cpp
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
```
- **Explanation**: 
    - The `Solution` class defines a function `minimumMultiplications` that accepts a vector `arr` (containing multipliers), and two integers, `start` and `end`.
    - The goal is to transform `start` to `end` with the fewest multiplications using elements of `arr`.

```cpp
        queue<pair<int,int>> q;
```
- **Explanation**: 
    - We initialize a queue `q` which stores pairs of integers in the format `{current_number, steps}`.
    - `current_number` represents the number we're currently working with, and `steps` tracks the number of multiplications taken to reach this number from `start`.

```cpp
        vector<int> dist(100000, 1e9);
```
- **Explanation**:
    - `dist` is a vector of size `100,000`, initialized with a very large number (`1e9`), representing infinity.
    - This vector records the minimum number of multiplications required to reach each number from `0` to `99,999`.

```cpp
        dist[start] = 0;
```
- **Explanation**:
    - We set `dist[start] = 0` because it takes `0` steps to reach `start` from itself.

```cpp
        q.push({start, 0});
```
- **Explanation**:
    - We add the `start` number along with `0` steps to the queue, marking the beginning of our BFS.

```cpp
        int mod = 100000;
```
- **Explanation**:
    - We set `mod = 100,000`, which is used to ensure every calculated number remains within the bounds of `0` to `99,999`.

```cpp
        while (!q.empty()) {
```
- **Explanation**:
    - We start a loop that continues until the queue is empty, meaning we have checked all possible paths to reach `end`.

```cpp
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
```
- **Explanation**:
    - We extract the first element in the queue and assign `node` as the current number and `step` as the number of steps taken to reach `node`.
    - Then, we remove this element from the queue.

```cpp
            for (auto it : arr) {
```
- **Explanation**:
    - We iterate over each multiplier in `arr`. Each `it` is a possible multiplier that can be applied to `node`.

```cpp
                int num = (it * node) % mod;
```
- **Explanation**:
    - We calculate `num` as the result of multiplying `node` by `it` (current multiplier) and taking the result modulo `100,000` to keep it within bounds.

```cpp
                if (step + 1 < dist[num]) {
```
- **Explanation**:
    - We check if the number of steps taken to reach `num` (i.e., `step + 1`) is smaller than the current recorded value in `dist[num]`.
    - If `step + 1` is smaller, it means we found a shorter path to `num`, so we proceed with updating it.

```cpp
                    dist[num] = step + 1;
```
- **Explanation**:
    - We update `dist[num]` with `step + 1`, which is the new minimum steps to reach `num`.

```cpp
                    if (num == end) return step + 1;
```
- **Explanation**:
    - If `num` equals `end`, we immediately return `step + 1` because this is the minimum number of multiplications needed to reach `end`.

```cpp
                    q.push({num, step + 1});
```
- **Explanation**:
    - We add `{num, step + 1}` to the queue to continue exploring this path in the next BFS iterations.

```cpp
        }
```
- **Explanation**:
    - This `for` loop iterates over all elements in `arr`, allowing all possible transformations of `node`.

```cpp
        if (start == end) return 0;
```
- **Explanation**:
    - After the BFS loop, if `start` is equal to `end`, it means no multiplication is needed, so we return `0`.

```cpp
        return -1;
```
- **Explanation**:
    - If no valid sequence was found to reach `end`, we return `-1`, indicating that `end` is unreachable.

---

### Dry Run Example:

Let’s dry run this code with `arr = {2, 3}`, `start = 3`, and `end = 18`.

#### Initial Queue:
```
q = [(3, 0)]
dist[3] = 0
```

#### BFS Steps:

1. **Iteration 1**:
    - **Queue**: `[(3, 0)]`
    - `node = 3`, `step = 0`
    - **Multipliers in `arr`**:
        - `2`: `num = (2 * 3) % 100000 = 6`, update `dist[6] = 1`, push `(6, 1)` into `q`.
        - `3`: `num = (3 * 3) % 100000 = 9`, update `dist[9] = 1`, push `(9, 1)` into `q`.
    - **Updated Queue**: `[(6, 1), (9, 1)]`

2. **Iteration 2**:
    - **Queue**: `[(6, 1), (9, 1)]`
    - `node = 6`, `step = 1`
    - **Multipliers in `arr`**:
        - `2`: `num = (2 * 6) % 100000 = 12`, update `dist[12] = 2`, push `(12, 2)` into `q`.
        - `3`: `num = (3 * 6) % 100000 = 18`, update `dist[18] = 2`, push `(18, 2)` into `q`.
    - **Updated Queue**: `[(9, 1), (12, 2), (18, 2)]`

3. **Iteration 3**:
    - **Queue**: `[(9, 1), (12, 2), (18, 2)]`
    - `node = 9`, `step = 1`
    - We proceed, but since `dist[18]` was updated, **we’ve already reached `end`**, so we return `2`.

### Final Output:
```cpp
2
```
This result means it takes a minimum of **2 multiplications** to go from `start = 3` to `end = 18` using multipliers from `arr`.
