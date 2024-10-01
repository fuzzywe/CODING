Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false



class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
private:
    stack <int> s1,s2;
};



DRY RUN THIS CODE:


Let’s dry run the MyQueue implementation step-by-step. The class uses two stacks (s1 and s2) to implement a queue (FIFO behavior) using stack operations (LIFO).

Code Overview:
push(int x): Moves elements from s1 to s2, pushes x onto s1, and then moves elements back from s2 to s1.
pop(): Removes and returns the top element from s1.
peek(): Returns the top element of s1 without removing it.
empty(): Checks if s1 is empty.
Example of Operations:
push(1)
push(2)
push(3)
pop()
peek()
empty()
Initial State:
s1 = []
s2 = []
Operation 1: push(1)
cpp
Copy code
while(!s1.empty()) {
    s2.push(s1.top()); // s1 is empty, so this loop doesn't execute.
    s1.pop();
}
s1.push(1);  // Push 1 onto s1.
while(!s2.empty()) {
    s1.push(s2.top()); // s2 is empty, so this loop doesn't execute.
    s2.pop();
}
State after push(1):
s1 = [1]
s2 = []
Operation 2: push(2)
cpp
Copy code
while(!s1.empty()) {
    s2.push(s1.top());  // Move 1 from s1 to s2: s1 = [], s2 = [1]
    s1.pop();
}
s1.push(2);  // Push 2 onto s1: s1 = [2]
while(!s2.empty()) {
    s1.push(s2.top());  // Move 1 back from s2 to s1: s1 = [2, 1], s2 = []
    s2.pop();
}
State after push(2):
s1 = [2, 1]
s2 = []
Operation 3: push(3)
cpp
Copy code
while(!s1.empty()) {
    s2.push(s1.top());  // Move 1 from s1 to s2: s1 = [2], s2 = [1]
    s1.pop();
    s2.push(s1.top());  // Move 2 from s1 to s2: s1 = [], s2 = [1, 2]
    s1.pop();
}
s1.push(3);  // Push 3 onto s1: s1 = [3]
while(!s2.empty()) {
    s1.push(s2.top());  // Move 2 back from s2 to s1: s1 = [3, 2], s2 = [1]
    s2.pop();
    s1.push(s2.top());  // Move 1 back from s2 to s1: s1 = [3, 2, 1], s2 = []
    s2.pop();
}
State after push(3):
s1 = [3, 2, 1]
s2 = []
Operation 4: pop()
cpp
Copy code
int n = s1.top();  // n = 1 (the front of the queue, but the top of the stack)
s1.pop();          // Remove 1: s1 = [3, 2]
return n;          // Return 1
State after pop():
s1 = [3, 2]
Output: 1
Operation 5: peek()
cpp
Copy code
return s1.top();  // Return the top element of s1, which is 2 (the front of the queue).
State after peek():
s1 = [3, 2]
Output: 2
Operation 6: empty()
cpp
Copy code
return s1.empty();  // Check if s1 is empty. Since s1 has [3, 2], it is not empty.
State after empty():
s1 = [3, 2]
Output: false (queue is not empty)
Summary of Stack States after Each Operation:
After push(1): s1 = [1]
After push(2): s1 = [2, 1]
After push(3): s1 = [3, 2, 1]
After pop(): Popped element is 1, queue becomes s1 = [3, 2]
After peek(): Front element is 2
After empty(): Queue is not empty (false)
Explanation of Logic:
push(): Moves all elements from s1 to s2, pushes the new element to s1, then moves elements back to maintain the correct queue order.
pop(): Removes the top element of s1, which corresponds to the front of the queue.
peek(): Returns the front element of the queue by looking at the top of s1.
empty(): Checks if s1 is empty, indicating whether the queue is empty.
