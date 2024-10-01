Implement Stack using Array

Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

Example:


Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

Note: The input is given in form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop an element from the stack and print the popped element)
Input contains separated by space and as described above. 

Examples :

Input: 1 2 1 3 2 1 4 2 
Output: 3, 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
Input: 2 1 4 1 5 2
Output: -1, 5
Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
  
Explanation: 

push(): Insert the element in the stack.

pop(): Remove and return the topmost element of the stack.

top(): Return the topmost element of the stack

size(): Return the number of remaining elements in the stack.


           
Advantages of Array Implementation:

Easy to implement.
Memory is saved as pointers are not involved.
Disadvantages of Array Implementation:

It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime. [But in case of dynamic sized arrays like vector in C++, list in Python, ArrayList in Java, stacks can grow and shrink with array implementation as well].
The total size of the stack must be defined beforehand.

Solution
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Intuition: As we know stack works on the principle of last in first out, so we have to put elements in an array such that it keeps track of the most recently inserted element. Hence we can think of using a Top variable which will help in keeping track of recent elements inserted in the array.

Approach:

Declare an array of particular size.
Define a variable “Top” and initialize it as -1.
push(x): insert element is the array by increasing top by one.
pop(): check whether top is not equal to -1 if it is so, return top and decrease its value by one.
size(): return top+1.


Code:

C++
Java
Python
#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
Output:

Top of stack is before deleting any element 7
Size of stack before deleting any element 3
The element deleted is 7
Size of stack after deleting an element 2
Top of stack after deleting an element 3

Time Complexity: O(N)

Space Complexity: O(N)

THE THINGS I LEARNED:

Use arr[top] = x when you want to store the value of x into the array.
Use x = arr[top] when you want to retrieve a value from the array and store it in x.

  1. arr[top] = x
This is an assignment operation where the value of x is stored into the array arr at the index top.
It means that you are writing the value of x into the array.
Example:
cpp
Copy code
int x = 5;
int arr[10];
int top = 0;
arr[top] = x; // Now arr[0] contains the value 5.
Purpose: To store or set a value into the array at the specified index.
2. x = arr[top]
This is also an assignment operation, but here, the value stored in the array arr at index top is retrieved and assigned to x.
It means that you are reading the value from the array and storing it in x.
Example:
cpp
Copy code
int arr[10] = {5, 10, 15};
int top = 1;
int x = arr[top]; // Now x contains the value 10 (which is at arr[1]).
Purpose: To retrieve or get a value from the array and store it in the variable x.
Summary of Differences:
arr[top] = x: You are storing the value of x into the array at index top.
x = arr[top]: You are retrieving the value from the array at index top and storing it in x.



THE CODING MISTAKE I DONE IN CODE PLATFORM:



void MyStack::push(int x) {
    // Increment the top index and insert the element
    if (top < 999) { // Avoid overflow
        top++;
        arr[top] = x;
    }
}

// Function to remove an item from top of the stack.
int MyStack::pop() {
    // Check if the stack is empty
    if (top == -1) {
        return -1; // Return -1 if there are no elements in the stack
    }
    
    // Otherwise, return the top element and decrement top
    int x = arr[top];
    top--;
    return x;
}

Complexity
Time Complexity: O(1), for both push(x) and pop() function as only constant time complexity operations.
Auxiliary Space: O(1), for both push(x) and pop() function as we are not using any extra space.



           
WHOLE CODE:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};

// } Driver Code Ends
// Function to push an integer into the stack.
void MyStack::push(int x) {
    // Increment the top index and insert the element
    if (top < 999) { // Avoid overflow
        top++;
        arr[top] = x;
    }
}

// Function to remove an item from top of the stack.
int MyStack::pop() {
    // Check if the stack is empty
    if (top == -1) {
        return -1; // Return -1 if there are no elements in the stack
    }
    
    // Otherwise, return the top element and decrement top
    int x = arr[top];
    top--;
    return x;
}

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
    return 0;
}

// } Driver Code Ends




















