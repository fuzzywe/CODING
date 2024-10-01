 private:
    StackNode *top;

  public:
    void push(int x) {
      StackNode* newNode= new  StackNode(x);
      newNode->next= top;
     top= newNode;
      
    }

    int pop() {
       if(top==nullptr){
           return -1;
       }
       else{
           int data= top->data;
           StackNode* temp= top;
           top= top->next;
           delete(temp);
           return data;
       }
    }

    MyStack() { top = NULL; }
};

DRY RUN 

Let's perform a detailed dry run of the given code.

The code defines a stack using a linked list and simulates a scenario where several queries are performed on the stack. The two main operations implemented in the class MyStack are push() (to insert elements into the stack) and pop() (to remove elements from the stack).

Example Input: "1 5 1 10 1 15 2 2" (which means push 5, push 10, push 15, pop, pop).
The input is processed and split into individual numbers, stored in a vector nums.
Processing Commands:
cpp
Copy code
int n = nums.size();
int i = 0;
while (i < n) {
Now we loop over the numbers in the nums vector.
Command: Push 5
cpp
Copy code
int QueryType = nums[i++];
if (QueryType == 1) {
    int a = nums[i++];
    sq->push(a);
}
The first QueryType is 1 (which means push), so we read the next number 5 and call sq->push(5).

Inside the push function:

cpp
Copy code
StackNode *newNode = new StackNode(x); // Creates a new node with data=5
newNode->next = top;                   // newNode->next = NULL (stack is empty, top is NULL)
top = newNode;                         // Now top points to the new node (5)
Stack after this operation:
css
Copy code
[ 5 ] (top)
Command: Push 10
The next QueryType is 1 again (which means push), so we read the next number 10 and call sq->push(10).

Inside the push function:

cpp
Copy code
StackNode *newNode = new StackNode(x); // Creates a new node with data=10
newNode->next = top;                   // newNode->next = 5 (previous top node)
top = newNode;                         // Now top points to the new node (10)
Stack after this operation:
css
Copy code
[ 10 ] (top)
[ 5  ]
Command: Push 15
The next QueryType is 1 (push again), so we read the next number 15 and call sq->push(15).

Inside the push function:

cpp
Copy code
StackNode *newNode = new StackNode(x); // Creates a new node with data=15
newNode->next = top;                   // newNode->next = 10 (previous top node)
top = newNode;                         // Now top points to the new node (15)
Stack after this operation:
css
Copy code
[ 15 ] (top)
[ 10 ]
[ 5  ]
Command: Pop (First Pop)
The next QueryType is 2 (which means pop), so we call sq->pop().

Inside the pop function:

cpp
Copy code
if (top == nullptr) return -1;         // Stack is not empty, so continue.
int data = top->data;                  // data = 15 (top node's data)
StackNode* temp = top;                 // temp points to the current top node (15)
top = top->next;                       // Move top to the next node (10)
delete(temp);                          // Delete the old top node (15)
return data;                           // Return 15
Output: 15
Stack after this operation:
css
Copy code
[ 10 ] (top)
[ 5  ]
Command: Pop (Second Pop)
The next QueryType is 2 (pop again), so we call sq->pop().

Inside the pop function:

cpp
Copy code
if (top == nullptr) return -1;         // Stack is not empty, so continue.
int data = top->data;                  // data = 10 (top node's data)
StackNode* temp = top;                 // temp points to the current top node (10)
top = top->next;                       // Move top to the next node (5)
delete(temp);                          // Delete the old top node (10)
return data;                           // Return 10
Output: 10
Stack after this operation:
css
Copy code
[ 5 ] (top)
Final State:
After processing all the commands, the stack contains just one element:

css
Copy code
[ 5 ] (top)
The output of the two pop operations is 15 10.

Summary of Commands Executed:
push(5) → Stack: [ 5 ]
push(10) → Stack: [ 10, 5 ]
push(15) → Stack: [ 15, 10, 5 ]
pop() → Output: 15 → Stack: [ 10, 5 ]
pop() → Output: 10 → Stack: [ 5 ]
Output:
Copy code
15 10
  
