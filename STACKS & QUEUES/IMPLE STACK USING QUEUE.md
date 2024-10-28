Implement Stack using single Queue



Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

Note: Queue is a data structure that follows the First In First Out (FIFO) rule.

Example:



Explanation: 
push(): Insert the element in the stack.
pop(): Remove and return the topmost element of the stack.
top(): Return the topmost element of the stack
size(): Return the size of the stack
Solution:

Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Intuition: As we know stack follows last in first out, which means we get the most recently inserted element whenever we remove an element from the stack. But queue follows first in first out, it means we get that element which we inserted in the starting at each deletion, it means if we want to use the queue like a stack we have to arrange elements in the queue such that we get the most recent element at each deletion.

Approach:

Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.
Repeat step3 at every insertion of the element.

```cpp

class MyStack {
public:
    MyStack() {
       //no need
    }
    queue<int>q;
    void push(int x) {
        q.push(x);
        int length = q.size();
        for(int i=0;i<length-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

Time Complexity: O(N)

Space Complexity: O(N)

  Code Explanation:
This MyStack class simulates a stack using a single queue (q). It includes the following methods:

push(int x): Adds element x to the stack.
pop(): Removes and returns the top element.
top(): Returns the top element without removing it.
empty(): Checks if the stack is empty.
The stack is implemented using a queue but rotates the queue elements after every push to maintain the "Last In, First Out" (LIFO) behavior of a stack.

Dry Run Example:
Let's consider a series of operations:

push(1)
push(2)
push(3)
top()
pop()
empty()
Initial State:
Queue q is empty: q = [].
Operation 1: push(1)
```cpp

q.push(1);  // Push 1 into the queue
Queue becomes: q = [1].
cpp
Copy code
int length = q.size();  // length = 1
for (int i = 0; i < length - 1; i++) {
    q.push(q.front());  // No iterations since length-1 = 0
    q.pop();            // No operations
}

```

The queue remains unchanged: q = [1].
Operation 2: push(2)
```cpp
Copy code
q.push(2);  // Push 2 into the queue
Queue becomes: q = [1, 2].
    ```
```cpp
Copy code
int length = q.size();  // length = 2
for (int i = 0; i < length - 1; i++) {
    q.push(q.front());  // Push 1 to the back of the queue: [2, 1]
    q.pop();            // Remove the front (1): [2, 1]
}
```
The queue now simulates a stack: q = [2, 1].
Operation 3: push(3)
```cpp

q.push(3);  // Push 3 into the queue
Queue becomes: q = [2, 1, 3].

```
```cpp
Copy code
int length = q.size();  // length = 3
for (int i = 0; i < length - 1; i++) {
    q.push(q.front());  // Push 2 to the back of the queue: [1, 3, 2]
    q.pop();            // Remove the front (2): [1, 3, 2]

    q.push(q.front());  // Push 1 to the back of the queue: [3, 2, 1]
    q.pop();            // Remove the front (1): [3, 2, 1]
}
```
The queue now simulates a stack: q = [3, 2, 1].
Operation 4: top()
```cpp
Copy code
return q.front();  // Return the front element of the queue (which is the top of the stack)
The top element is 3.
Operation 5: pop()
```
```cpp
Copy code
int topElement = q.front();  // topElement = 3 (the front of the queue)
q.pop();                     // Remove the front element: [2, 1]
return topElement;            // Return 3
The popped element is 3, and the queue is now: q = [2, 1].
Operation 6: empty()
 ```
```cpp
Copy code
return q.empty();  // Check if the queue is empty. q = [2, 1], so it's not empty.
The output is false because the queue still has elements (2, 1).
```
Summary of Queue State after each operation:
After Push(1): q = [1]
After Push(2): q = [2, 1]
After Push(3): q = [3, 2, 1]
After Top(): The top element is 3.
After Pop(): Popped element is 3, queue becomes q = [2, 1].
After Empty(): Queue is not empty (false).
Conclusion:
The queue behaves like a stack due to the rotations after each push, ensuring the most recently pushed element always becomes the front of the queue, simulating LIFO behavior.
