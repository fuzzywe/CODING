What is Stack Data Structure? A Complete Tutorial
Last Updated : 06 Jun, 2024
Stack Data Structure is a linear data structure that follows LIFO (Last In First Out) Principle , 
so the last element inserted is the first to be popped out. 


Table of Content

What is Stack Data Structure?
Representation of Stack Data Structure:
Types of Stack Data Structure:
Basic Operations on Stack Data Structure
Push Operation in Stack Data Structure
Pop Operation in Stack Data Structure
Top or Peek Operation in Stack Data Structure
isEmpty Operation in Stack Data Structure
isFull Operation in Stack Data Structure
Implementation of Stack Data Structure
Implementation of Stack Data Structure using Array
Implementation of Stack Data Structure using Linked List
Complexity Analysis of Operations on Stack Data Structure
Advantages of Stack Data Structure
Disadvantages of Stack Data Structure
Applications of Stack Data Structure

  
What is Stack Data Structure?
Stack is a linear data structure based on LIFO(Last In First Out) principle in 
which the insertion of a new element and removal of an existing element 
takes place at the same end represented as the top of the stack.

To implement the stack, it is required to maintain the pointer to the top of the stack , 
which is the last element to be inserted because we can access the elements only on the top of the stack.

LIFO(Last In First Out) Principle in Stack Data Structure:
This strategy states that the element that is inserted last will come out first. 
You can take a pile of plates kept on top of each other as a real-life example. 
The plate which we put last is on the top and since we remove the plate that is at the top,
we can say that the plate that was put last comes out first.

Representation of Stack Data Structure:
Stack follows LIFO (Last In First Out) Principle so the element which is pushed last is popped first.

Stack-representation-in-Data-Structures-(1)
Types of Stack Data Structure:
Fixed Size Stack : As the name suggests, a fixed size stack has a fixed size and cannot grow or shrink dynamically. 
If the stack is full and an attempt is made to add an element to it, an overflow error occurs. 
If the stack is empty and an attempt is made to remove an element from it, an underflow error occurs.
Dynamic Size Stack : A dynamic size stack can grow or shrink dynamically. When the stack is full,
it automatically increases its size to accommodate the new element, and when the stack is empty, 
it decreases its size. This type of stack is implemented using a linked list, as it allows for easy resizing of the stack.
Basic Operations on Stack Data Structure:
In order to make manipulations in a stack, there are certain operations provided to us.

push() to insert an element into the stack
pop() to remove an element from the stack
top() Returns the top element of the stack.
isEmpty() returns true if stack is empty else false.
isFull() returns true if the stack is full else false.

  
Push Operation in Stack Data Structure:
Adds an item to the stack. If the stack is full, then it is said to be an Overflow condition.

Algorithm for Push Operation:

Before pushing the element to the stack, we check if the stack is full .
If the stack is full (top == capacity-1) , then Stack Overflows and we cannot insert the element to the stack.
Otherwise, we increment the value of top by 1 (top = top + 1) and the new value is inserted at top position .
The elements can be pushed into the stack till we reach the capacity of the stack.
Push-Operation-in-Stack-(1)
Pop Operation in Stack Data Structure:
Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.

Algorithm for Pop Operation:

Before popping the element from the stack, we check if the stack is empty .
If the stack is empty (top == -1), then Stack Underflows and we cannot remove any element from the stack.
Otherwise, we store the value at top, decrement the value of top by 1 (top = top – 1) and return the stored top value.
Pop-Operation-in-Stack-(1)
Top or Peek Operation in Stack Data Structure:
Returns the top element of the stack.

Algorithm for Top Operation:

Before returning the top element from the stack, we check if the stack is empty.
If the stack is empty (top == -1), we simply print “Stack is empty”.
Otherwise, we return the element stored at index = top .
Top-or-Peek-Operation-in-Stack-(1)
isEmpty Operation in Stack Data Structure:
Returns true if the stack is empty, else false.

Algorithm for isEmpty Operation:

Check for the value of top in stack.
If (top == -1) , then the stack is empty so return true .
Otherwise, the stack is not empty so return false .
isEmpty-Operation-in-Stack-(1)
isFull Operation in Stack Data Structure:
Returns true if the stack is full, else false.

Algorithm for isFull Operation:

Check for the value of top in stack.
If (top == capacity-1), then the stack is full so return true.
Otherwise, the stack is not full so return false.
isFull-Operation-in-Stack-(1)
Implementation of Stack Data Structure:
The basic operations that can be performed on a stack include push, pop, and peek. There are two ways to implement a stack –

Using Array
Using Linked List
In an array-based implementation, the push operation is implemented by incrementing the index of the top element and storing the new element at that index. The pop operation is implemented by returning the value stored at the top index and then decrementing the index of the top element.

In a linked list-based implementation, the push operation is implemented by creating a new node with the new element and setting the next pointer of the current top node to the new node. The pop operation is implemented by setting the next pointer of the current top node to the next node and returning the value of the current top node.
