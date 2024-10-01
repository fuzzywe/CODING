
Implement Queue using array
Difficulty: BasicAccuracy: 47.24%Submissions: 183K+Points: 1
Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the popped element)

We just have to implement the functions push and pop and the driver code will handle the output.

Examples:

Input: Q = 5, Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation:
In the first test case for query 
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3 
Input: Q = 4, Queries = 1 3 2 2 1 4   
Output: 3 -1
Explanation:
In the second testcase for query 
1 3 the queue will be {3}
2   poped element will be 3 the
    queue will be empty
2   there is no element in the
    queue and hence -1
1 4 the queue will be {4}. 
Expected Time Complexity: O(1) for both push() and pop().
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 ≤ Q ≤ 105
0 ≤ x ≤ 105


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends


/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        // Your Code
        if(rear ==0){
            arr[front] =x;
            rear = rear+1;
        }
        else{
            arr[rear] =x;
            rear=rear+1;
        }
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code 
        if(front ==rear) return -1;
        else{
            int x =arr[front];
            front = front+1;
            return x;
        }
}


DRY RUN 

Sure, let's perform a dry run for the code you provided step-by-step. We will use a specific example and simulate how each part of the code behaves during the run.

Code Breakdown and Dry Run:
1. Initial Definitions:
cpp
Copy code
class MyQueue {
private:
    int arr[100005];  // Queue implemented using an array.
    int front;        // Pointer to the front of the queue.
    int rear;         // Pointer to the rear of the queue.

public:
    MyQueue() { front = 0; rear = 0; }  // Constructor initializing front and rear to 0.
    void push(int);  // Method to push an element into the queue.
    int pop();       // Method to pop an element from the queue.
};
Data members:
arr: An array to store queue elements.
front: Tracks the first element of the queue (to be removed next).
rear: Tracks the last element of the queue (where the next element is inserted).
Constructor:
Initializes both front and rear to 0, indicating an empty queue.
Step-by-Step Dry Run:
Let’s use the following input as an example:

Copy code
1
6
1 10
1 20
2
1 30
2
2
Test Case 1: There is 1 test case.
Query 6: There are 6 operations to be performed.
1. Main Function:
cpp
Copy code
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        MyQueue *sq = new MyQueue();  // Dynamically creates a new queue for this test case.

        int Q;
        cin >> Q;  // Number of queries.
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)  // Push operation.
            {
                int a;
                cin >> a;
                sq->push(a);  // Pushes element 'a' into the queue.
            }
            else if (QueryType == 2)  // Pop operation.
            {
                cout << sq->pop() << " ";  // Pops and prints the front element.
            }
        }
        cout << endl;
        delete sq;  // Deletes the queue after the test case.
    }
}
2. Initial Setup:
T = 1, so the outer while(T--) loop runs once.
Q = 6, so the inner while(Q--) loop runs six times, processing six operations.
3. Processing Queries:
Query 1: Push 10
cpp
Copy code
int QueryType = 1;  // Push operation
int a = 10;  // Element to be pushed
sq->push(a);  // Calls the push function
Push Function:

cpp
Copy code
void MyQueue::push(int x) {
    if (rear == 0) {           // Queue is empty initially
        arr[front] = x;        // Insert element at front (arr[0] = 10)
        rear = rear + 1;       // Increment rear to 1
    } else {
        arr[rear] = x;         // Insert element at arr[1] (not executed for the first push)
        rear = rear + 1;       // Increment rear (not executed for the first push)
    }
}
Initial State: front = 0, rear = 0.
After Push: arr = [10], front = 0, rear = 1 (queue has 1 element).
Query 2: Push 20
cpp
Copy code
int QueryType = 1;  // Push operation
int a = 20;  // Element to be pushed
sq->push(a);  // Calls the push function
Push Function:

cpp
Copy code
void MyQueue::push(int x) {
    if (rear == 0) {           // Condition not met as rear = 1
        arr[front] = x;
        rear = rear + 1;
    } else {
        arr[rear] = x;         // Insert element at arr[1] = 20
        rear = rear + 1;       // Increment rear to 2
    }
}
State Before Push: arr = [10], front = 0, rear = 1.
State After Push: arr = [10, 20], front = 0, rear = 2 (queue has 2 elements).
Query 3: Pop
cpp
Copy code
int QueryType = 2;  // Pop operation
cout << sq->pop() << " ";  // Calls the pop function and prints the result
Pop Function:

cpp
Copy code
int MyQueue::pop() {
    if (front == rear) return -1;  // Queue is not empty (front = 0, rear = 2)
    else {
        int x = arr[front];        // x = arr[0] = 10
        front = front + 1;         // Increment front to 1
        return x;                  // Return 10
    }
}
State Before Pop: arr = [10, 20], front = 0, rear = 2.
Output: 10.
State After Pop: arr = [10, 20], front = 1, rear = 2 (queue has 1 element remaining).
Query 4: Push 30
cpp
Copy code
int QueryType = 1;  // Push operation
int a = 30;  // Element to be pushed
sq->push(a);  // Calls the push function
Push Function:

cpp
Copy code
void MyQueue::push(int x) {
    if (rear == 0) {           // Condition not met as rear = 2
        arr[front] = x;
        rear = rear + 1;
    } else {
        arr[rear] = x;         // Insert element at arr[2] = 30
        rear = rear + 1;       // Increment rear to 3
    }
}
State Before Push: arr = [10, 20], front = 1, rear = 2.
State After Push: arr = [10, 20, 30], front = 1, rear = 3 (queue has 2 elements).
Query 5: Pop
cpp
Copy code
int QueryType = 2;  // Pop operation
cout << sq->pop() << " ";  // Calls the pop function and prints the result
Pop Function:

cpp
Copy code
int MyQueue::pop() {
    if (front == rear) return -1;  // Queue is not empty (front = 1, rear = 3)
    else {
        int x = arr[front];        // x = arr[1] = 20
        front = front + 1;         // Increment front to 2
        return x;                  // Return 20
    }
}
State Before Pop: arr = [10, 20, 30], front = 1, rear = 3.
Output: 20.
State After Pop: arr = [10, 20, 30], front = 2, rear = 3 (queue has 1 element remaining).
Query 6: Pop
cpp
Copy code
int QueryType = 2;  // Pop operation
cout << sq->pop() << " ";  // Calls the pop function and prints the result
Pop Function:

cpp
Copy code
int MyQueue::pop() {
    if (front == rear) return -1;  // Queue is not empty (front = 2, rear = 3)
    else {
        int x = arr[front];        // x = arr[2] = 30
        front = front + 1;         // Increment front to 3
        return x;                  // Return 30
    }
}
State Before Pop: arr = [10, 20, 30], front = 2, rear = 3.
Output: 30.
State After Pop: arr = [10, 20, 30], front = 3, rear = 3 (queue is now empty).
Final Output:
Copy code
10 20 30 
Summary of Operations:
Push 10 → Queue: [10].
Push 20 → Queue: [10, 20].
Pop → Output: 10, Queue: [20].
Push 30 → Queue: [20, 30].
Pop → Output: 20, Queue: [30].
Pop → Output: 30, Queue is now empty.
