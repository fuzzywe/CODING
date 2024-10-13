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
