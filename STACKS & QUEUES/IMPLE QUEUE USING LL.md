https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?interviewBundleRedirection=true

https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

---


Implement Queue using Linked List
```cpp
#include <bits/stdc++.h>
using namespace std;

class Queue {
    int size;
    int rear;
    int qfront;
    int* arr;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() { // Destructor to free memory
        delete[] arr;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size - 1) { // Fixed boundary check
            cout << "Queue is full\n";
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;

        int ans = arr[qfront];
        qfront++;

        if (qfront == rear) qfront = rear = 0; // Reset queue if empty

        return ans;
    }

    int getFront() { // Renamed function to avoid conflict
        return isEmpty() ? -1 : arr[qfront];
    }
};

// Driver Code
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << q.dequeue() << " dequeued.\n";
    cout << "Front element after dequeue: " << q.getFront() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}


```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {  // If queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued to queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        // If front becomes NULL, rear should also be NULL
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << temp->data << " dequeued from queue.\n";
        delete temp;
    }

    // Display queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to calculate the sum of all elements in the queue
    int sum() {
        int total = 0;
        Node* temp = front;
        while (temp) {
            total += temp->data;
            temp = temp->next;
        }
        return total;
    }
};

// Main function to test queue
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();  // Display queue elements

    cout << "Sum of all elements in queue: " << q.sum() << endl;  // Calculate sum

    q.dequeue();
    q.display();

    cout << "Sum after dequeue: " << q.sum() << endl; // Calculate sum after dequeue

    return 0;
}
```

---


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

```cpp
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

```
**Dry Run of Each Line:**
Operation 1: push(10)
```
cpp

QueueNode *newnode = new QueueNode(x);
```

A new node is created with data = 10.
Let's call this node newnode.
State of newnode:
```cpp
Copy code
newnode: [ data = 10, next = NULL ]
cpp
Copy code
if (rear == NULL) {
    rear = front = newnode;
    return;
}
```
Since both front and rear are NULL (the queue is empty), both pointers are set to the new node (newnode).
The queue now has one element.
State of the queue:

```cpp
Copy code
front = rear = [ data = 10, next = NULL ]
```
Operation 2: push(20)
```cpp
Copy code
QueueNode *newnode = new QueueNode(x);
```
A new node is created with data = 20.
Let's call this node newnode.
State of newnode:

```cpp
Copy code
newnode: [ data = 20, next = NULL ]
cpp
Copy code
rear->next = newnode;
rear = newnode;
```
The current rear node's next pointer is updated to point to the new node (newnode).
The rear pointer is moved to the new node.
State of the queue:

```cpp
Copy code
front: [ data = 10, next = → [ data = 20, next = NULL ] ]
rear: [ data = 20, next = NULL ]
```
Operation 3: push(30)
```cpp
Copy code
QueueNode *newnode = new QueueNode(x);
A new node is created with data = 30.
Let's call this node newnode.
State of newnode:
```
```cpp
Copy code
newnode: [ data = 30, next = NULL ]
```
```cpp
Copy code
rear->next = newnode;
rear = newnode;
The current rear node's next pointer is updated to point to the new node (newnode).
The rear pointer is moved to the new node.
State of the queue:
```
```cpp
Copy code
front: [ data = 10, next = → [ data = 20, next = → [ data = 30, next = NULL ] ] ]
rear: [ data = 30, next = NULL ]
```

Operation 4: pop()
```
cpp
Copy code
if (front == NULL) {
    return -1;
}
```

Since front is not NULL, we continue.
```cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
```

A pointer oldhead is created to store the current front node (data = 10).
The value of the front node is stored in temp (temp = 10).
```cpp
Copy code
front = front->next;
```

The front pointer is moved to the next node (data = 20).
State of the queue:

```cpp
Copy code
front: [ data = 20, next = → [ data = 30, next = NULL ] ]
rear: [ data = 30, next = NULL ]
```

```cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
```

Since front is not NULL, we don't change the rear.
```cpp
Copy code
delete oldhead;
return temp;
```

The node with data = 10 (pointed by oldhead) is deleted.
The function returns temp = 10.
Operation 5: pop()
```cpp
Copy code
if (front == NULL) {
    return -1;
}
```

Since front is not NULL, we continue.
```cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
```

A pointer oldhead is created to store the current front node (data = 20).
The value of the front node is stored in temp (temp = 20).
```cpp
Copy code
front = front->next;
The front pointer is moved to the next node (data = 30).
State of the queue:
```
```cpp
Copy code
front: [ data = 30, next = NULL ]
rear: [ data = 30, next = NULL ]
```

```cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
```

Since front is not NULL, we don't change the rear.
```cpp
Copy code
delete oldhead;
return temp;
```

The node with data = 20 (pointed by oldhead) is deleted.
The function returns temp = 20.
Operation 6: pop()
```cpp
Copy code
if (front == NULL) {
    return -1;
}
```

Since front is not NULL, we continue.
```cpp
Copy code
QueueNode *oldhead = front;
int temp = front->data;
```

A pointer oldhead is created to store the current front node (data = 30).
The value of the front node is stored in temp (temp = 30).
```cpp
Copy code
front = front->next;
```

The front pointer is moved to NULL since there are no more nodes.
State of the queue:

```cpp
front = NULL
rear = [ data = 30 ] → NULL
```

```cpp
Copy code
if (front == NULL) {
    rear = NULL;
}
```

Since front is NULL, we set rear to NULL as well (queue is now empty).
```cpp
Copy code
delete oldhead;
return temp;
```

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
