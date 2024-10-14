155. Min Stack
Medium
Topics
Companies
Hint
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

It makes sense and maybe slightly more efficient if your de-couple stack-elements and min-elements. In your case, you are always storing min with every stack element, effectively double the total space usage required by a normal stack.

By keeping the stack elements separately in one structure and the min elements (indices) in another as below, it may lead to lower space usage in most cases :
```cpp
class MinStack {
    vector<int> s, minIdx;
public:
    void push(int val) {
        if(minIdx.empty() || val < s[minIdx.back()]) minIdx.push_back(s.size());
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        if(minIdx.back() == s.size()) minIdx.pop_back();
    }

    int top() { return s.back(); }
    int getMin() { return s[minIdx.back()]; }
};
```
Time Complexity:
Push:
Time Complexity: O(1)
Checking whether to update minIdx and adding the element to s and minIdx both take constant time.
Pop:
Time Complexity: O(1)
Removing the top element from s and potentially from minIdx takes constant time.
Top:
Time Complexity: O(1)
Accessing the top element of the stack using s.back() is a constant-time operation.
GetMin:
Time Complexity: O(1)
Accessing the minimum element using minIdx.back() and indexing into s takes constant time.
Space Complexity:
Space Complexity: O(n)
We store the stack elements in s, which requires O(n) space where n is the number of elements in the stack.
The minIdx vector stores only the indices of elements that are the current minimum. In the worst case, every new element could be a new minimum, requiring O(n) space, but typically it will be much smaller in size than storing the minimum value with each stack element.

Let's go through each line of the code and perform a **dry run** to understand how the `MinStack` implementation works.

### Class Declaration:
```cpp
class MinStack {
    vector<int> s, minIdx;
```
- **`vector<int> s`**: This vector stores the stack elements (the numbers being pushed).
- **`vector<int> minIdx`**: This vector stores the **indices** of the minimum elements in the stack. The idea is to track the positions of the minimum values as they are encountered.

### `push(int val)` Method:
```cpp
void push(int val) {
    if(minIdx.empty() || val < s[minIdx.back()]) minIdx.push_back(s.size());
    s.push_back(val);
}
```
- **Purpose**: Adds a value to the stack and checks if it's the new minimum.
- **Dry run** of each part:
  1. **`if(minIdx.empty() || val < s[minIdx.back()])`**:
     - If `minIdx` is empty (i.e., no minimum yet), or the new value `val` is smaller than the current minimum (`s[minIdx.back()]`), we add the index of the new minimum (`s.size()`) to `minIdx`.
     - `minIdx.back()` refers to the **index** of the current minimum value in `s`.
  2. **`minIdx.push_back(s.size())`**: 
     - If the new value is smaller, we push the current size of `s` (which is the index where the new element will be stored) to `minIdx`. This helps in tracking the index of the new minimum.
  3. **`s.push_back(val)`**: 
     - Add the value `val` to the stack `s`.

#### Example Dry Run of `push()`:
**Initial state**:  
- `s = []`, `minIdx = []`

**Push(5)**:  
- `minIdx` is empty, so we push the index `0` to `minIdx`.
- `s = [5]`, `minIdx = [0]`

**Push(3)**:  
- `minIdx` is not empty, and `3` is less than `s[minIdx.back()] = 5`, so we push index `1` to `minIdx`.
- `s = [5, 3]`, `minIdx = [0, 1]`

**Push(7)**:  
- `7` is greater than `s[minIdx.back()] = 3`, so we don't update `minIdx`.
- `s = [5, 3, 7]`, `minIdx = [0, 1]`

### `pop()` Method:
```cpp
void pop() {
    s.pop_back();
    if(minIdx.back() == s.size()) minIdx.pop_back();
}
```
- **Purpose**: Removes the top element from the stack and checks if it was the current minimum.
- **Dry run of each part**:
  1. **`s.pop_back()`**:
     - Removes the last element from `s`.
  2. **`if(minIdx.back() == s.size())`**:
     - After removing the element from `s`, we check if the index stored in `minIdx.back()` matches the new size of `s`. This means that the popped element was the current minimum.
  3. **`minIdx.pop_back()`**:
     - If the popped element was the minimum, remove its index from `minIdx`.

#### Example Dry Run of `pop()`:
**State** after pushing `5, 3, 7`:  
- `s = [5, 3, 7]`, `minIdx = [0, 1]`

**Pop()**:
- `s.pop_back()` removes `7`.
- `minIdx.back() = 1`, `s.size() = 2`, so we don't update `minIdx`.
- **New state**: `s = [5, 3]`, `minIdx = [0, 1]`

**Pop()**:
- `s.pop_back()` removes `3`.
- `minIdx.back() = 1` matches `s.size() = 1`, so we remove index `1` from `minIdx`.
- **New state**: `s = [5]`, `minIdx = [0]`

### `top()` Method:
```cpp
int top() { return s.back(); }
```
- **Purpose**: Returns the top element of the stack without removing it.
- **Dry run**:
  - Simply returns the last element of `s` using `s.back()`.

#### Example:
- If `s = [5, 3, 7]`, `top()` will return `7`.

### `getMin()` Method:
```cpp
int getMin() { return s[minIdx.back()]; }
```
- **Purpose**: Returns the minimum element currently in the stack.
- **Dry run**:
  - It returns the element at the index stored in `minIdx.back()`. This is the current minimum element in the stack.

#### Example:
- If `s = [5, 3, 7]` and `minIdx = [0, 1]`, `getMin()` will return `s[1] = 3`.

---

### Full Example Dry Run:
Let's walk through an example with a series of operations on the stack.

**Operations**:  
1. **Push(5)**  
2. **Push(3)**  
3. **Push(7)**  
4. **GetMin()**  
5. **Pop()**  
6. **GetMin()**  
7. **Pop()**  
8. **Top()**

**State after each operation**:

1. **Push(5)**:  
   - `s = [5]`, `minIdx = [0]`
   - Current minimum: 5

2. **Push(3)**:  
   - `s = [5, 3]`, `minIdx = [0, 1]`
   - Current minimum: 3

3. **Push(7)**:  
   - `s = [5, 3, 7]`, `minIdx = [0, 1]`
   - Current minimum: 3

4. **GetMin()**:  
   - Returns `s[1] = 3`

5. **Pop()**:  
   - `s = [5, 3]`, `minIdx = [0, 1]` (no change to `minIdx` because `7` wasn’t the minimum)

6. **GetMin()**:  
   - Returns `s[1] = 3`

7. **Pop()**:  
   - `s = [5]`, `minIdx = [0]` (we removed the minimum element `3`, so `minIdx` is updated)

8. **Top()**:  
   - Returns `s[0] = 5`

---

### Time Complexity:
- **Push**: O(1) (constant time for inserting elements into both `s` and `minIdx`).
- **Pop**: O(1) (constant time for removing elements from `s` and `minIdx`).
- **Top**: O(1) (constant time for accessing the top of the stack).
- **GetMin**: O(1) (constant time for accessing the current minimum).

### Space Complexity:
- **Space**: O(n), where `n` is the number of elements in the stack. This is because both `s` and `minIdx` can store up to `n` elements in the worst case (if every pushed element is a new minimum).

This approach ensures we maintain O(1) time complexity for all operations while reducing the extra space usage compared to storing the minimum with each element in the stack.
