Implement Queue using Linked List
Difficulty: BasicAccuracy: 45.6%Submissions: 123K+Points: 1
Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Example 2:

Input:
Q = 4
Queries = 1 2 2 2 1 3 
Output: 2 -1
Explanation: In the second testcase 
1 2 the queue will be {2}
2   poped element will be {2} then
    the queue will be empty. 
2   the queue is empty and hence -1
1 3 the queue will be {3}.
Your Task:
Complete the function push() which takes an integer as input parameter and pop() which will remove and return an element(-1 if queue is empty).

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).


  void MyQueue:: push(int x)
{
      QueueNode *newnode=new QueueNode(x);
      if(rear==NULL){
         rear= front=newnode;
          return;
      }
      else{
      rear->next=newnode;
     rear=newnode;
      }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
if(front==NULL){
    return -1;
}    
QueueNode *oldhead=front;
int temp=front->data;
front=front->next;
if(front==NULL){
    rear=NULL;
}
delete oldhead;
return temp;

}

Dry Run of Each Line:
Operation 1: push(10)
cpp
Copy code
QueueNode *newnode = new QueueNode(x);
A new node is created with data = 10.
Let's call this node newnode.
State of newnode:

r
Copy code
newnode: [ data = 10, next = NULL ]
cpp
Copy code
if (rear == NULL) {
    rear = front = newnode;
    return;
}
Since both front and rear are NULL (the queue is empty), both pointers are set to the new node (newnode).
The queue now has one element.
State of the queue:

r
Copy code
front = rear = [ data = 10, next = NULL ]
Operation 2: push(20)
cpp
Copy code
QueueNode *newnode = new QueueNode(x);
A new node is created with data = 20.
Let's call this node newnode.
State of newnode:

r
Copy code
newnode: [ data = 20, next = NULL ]
cpp
Copy code
rear->next = newnode;
rear = newnode;
The current rear node's next pointer is updated to point to the new node (newnode).
The rear pointer is moved to the new node.
State of the queue:

r
Copy code
front: [ data = 10, next = → [ data = 20, next = NULL ] ]
rear: [ data = 20, next = NULL ]
Operation 3: push(30)
cpp
Copy code
QueueNode *newnode = new QueueNode(x);
A new node is created with data = 30.
Let's call this node newnode.
State of newnode:

r
Copy code
newnode: [ data = 30, next = NULL ]
cpp
Copy code
rear->next = newnode;
rear = newnode;
The current rear node's next pointer is updated to point to the new node (newnode).
The rear pointer is moved to the new node.
State of the queue:

r
Copy code
front: [ data = 10, next = → [ data = 20, next = → [ data = 30, next = NULL ] ] ]
rear: [ data = 30, next = NULL ]
Operation 4: pop()
cpp
Copy code
if (front == NULL) {
    return -1;
}
Since front is not NULL, we continue.
cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
A pointer oldhead is created to store the current front node (data = 10).
The value of the front node is stored in temp (temp = 10).
cpp
Copy code
front = front->next;
The front pointer is moved to the next node (data = 20).
State of the queue:

r
Copy code
front: [ data = 20, next = → [ data = 30, next = NULL ] ]
rear: [ data = 30, next = NULL ]
cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
Since front is not NULL, we don't change the rear.
cpp
Copy code
delete oldhead;
return temp;
The node with data = 10 (pointed by oldhead) is deleted.
The function returns temp = 10.
Operation 5: pop()
cpp
Copy code
if (front == NULL) {
    return -1;
}
Since front is not NULL, we continue.
cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
A pointer oldhead is created to store the current front node (data = 20).
The value of the front node is stored in temp (temp = 20).
cpp
Copy code
front = front->next;
The front pointer is moved to the next node (data = 30).
State of the queue:

r
Copy code
front: [ data = 30, next = NULL ]
rear: [ data = 30, next = NULL ]
cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
Since front is not NULL, we don't change the rear.
cpp
Copy code
delete oldhead;
return temp;
The node with data = 20 (pointed by oldhead) is deleted.
The function returns temp = 20.
Operation 6: pop()
cpp
Copy code
if (front == NULL) {
    return -1;
}
Since front is not NULL, we continue.
cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
A pointer oldhead is created to store the current front node (data = 30).
The value of the front node is stored in temp (temp = 30).
cpp
Copy code
front = front->next;
The front pointer is moved to NULL since there are no more nodes.
State of the queue:

arduino
Copy code
front = NULL
rear = [ data = 30 ] → NULL
cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
Since front is NULL, we set rear to NULL as well (queue is now empty).
cpp
Copy code
delete oldhead;
return temp;
The node with data = 30 (pointed by oldhead) is deleted.
The function returns temp = 30.
Final State:
After all operations, the queue is empty.
Both front and rear are NULL.
Summary of Operations:
push(10) → Queue: [ 10 ]
push(20) → Queue: [ 10, 20 ]
push(30) → Queue: [ 10, 20, 30 ]
pop() → Output: 10 → Queue: [ 20, 30 ]
pop() → Output: 20 → Queue: [ 30 ]
pop() → Output: 30 → Queue: [] (empty)
Output:
Copy code
10 20 30
