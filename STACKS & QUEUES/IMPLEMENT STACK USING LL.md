[Link](https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?interviewBundleRedirection=true&leftPanelTabValue=PROBLEM)



---

### **📌 Explanation**
1. **Each node** will contain:
   - `data`: The value stored in the node.
   - `next`: Pointer to the next node in the stack.
2. **Stack Operations**:
   - **Push**: Insert a new element at the top.
   - **Pop**: Remove and return the top element.
   - **Top**: Return the top element without removing it.
   - **isEmpty**: Check if the stack is empty.
   - **Print**: Display stack elements.

---

### **📝 C++ Code**
```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp; // Free memory
        return poppedValue;
    }

    // Top operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Print stack elements
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver Code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack(); // Output: 30 20 10

    cout << "Top element: " << s.peek() << endl; // Output: 30

    cout << "Popped: " << s.pop() << endl; // Output: 30
    s.printStack(); // Output: 20 10

    cout << "Popped: " << s.pop() << endl; // Output: 20
    cout << "Popped: " << s.pop() << endl; // Output: 10
    cout << "Popped: " << s.pop() << endl; // Output: Stack Underflow!

    return 0;
}
```

---

### **🔍 How It Works?**
| Operation | Description | Stack After Operation |
|-----------|------------|----------------------|
| `push(10)` | Insert 10 | **10** |
| `push(20)` | Insert 20 | **20 → 10** |
| `push(30)` | Insert 30 | **30 → 20 → 10** |
| `peek()` | View top | Returns `30` |
| `pop()` | Remove top | **20 → 10** |
| `pop()` | Remove top | **10** |
| `pop()` | Remove top | **Empty** |
| `pop()` | Underflow | Shows warning |

---

### **📌 Key Points**
✅ Uses **linked list** (dynamic memory, no size limit).  
✅ `push()` → O(1) (insert at head).  
✅ `pop()` → O(1) (delete head).  
✅ `isEmpty()` → O(1) (just check `top`).  
✅ **Avoids stack overflow** unlike array-based stacks.

---

### **Hope this helps! 😊 Let me know if you have doubts. 🚀**

No worries! I'll explain **Stack using Linked List** in detail right here. Let me know which part is confusing. 😊  

---

## **📌 What is a Stack?**  
A **stack** is a **LIFO** (Last-In, First-Out) data structure. It has two main operations:  
1. **Push** → Insert an element at the top.  
2. **Pop** → Remove the top element.  

---

## **📌 Stack using Linked List (Explanation)**  

### **🔹 Why use a Linked List?**  
✅ **No fixed size** (unlike array-based stack).  
✅ **Efficient** (push & pop are **O(1)** operations).  
✅ **No memory wastage** (only uses memory for needed elements).  

### **🔹 Structure of a Node**  
Each node has:  
- `data` → Stores value.  
- `next` → Pointer to the next node.  

### **🔹 How Operations Work?**  
1️⃣ **Push (Insert at Head)**  
   - Create a new node.  
   - Make `newNode->next = top`.  
   - Update `top = newNode`.  

2️⃣ **Pop (Remove from Head)**  
   - Store `top->data` (to return later).  
   - Move `top = top->next`.  
   - Delete old top node.  

3️⃣ **Peek (Get Top Element)**  
   - Return `top->data`.  

4️⃣ **isEmpty (Check if Stack is Empty)**  
   - Return `top == nullptr`.  

---

## **📌 C++ Implementation**
```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) {  // Constructor
        data = value;
        next = nullptr;
    }
};

// Stack using linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack() { top = nullptr; }  // Constructor

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;  // Free memory
        return poppedValue;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() { return top == nullptr; }

    // Print stack elements
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver Code
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();  // Output: 30 20 10

    cout << "Top element: " << s.peek() << endl; // Output: 30

    cout << "Popped: " << s.pop() << endl; // Output: 30
    s.printStack();  // Output: 20 10

    return 0;
}
```

---

## **📌 Dry Run Example**
### **Operations**
```cpp
s.push(10);
s.push(20);
s.push(30);
```
### **Stack Structure**
```
TOP →  30
        20
        10
```
```cpp
s.pop();
```
### **After Pop**
```
TOP →  20
        10
```
### **Time Complexity**
✅ `push()` → O(1)  
✅ `pop()` → O(1)  
✅ `peek()` → O(1)  
✅ `isEmpty()` → O(1)  

---

## **📌 Summary**
- Stack follows **LIFO** (Last-In, First-Out).  
- Uses a **linked list** instead of an array.  
- **Push → Insert at Head**.  
- **Pop → Remove from Head**.  
- **Efficient operations** (`O(1)`).  

---

**💡 Need help with any part? I’ll explain more! 😊**

---

nakuri

---

```cpp

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    //Write your code here
    Node* top;
    int size=0;

public:
    Stack()
    {
        //Write your code here
        top = nullptr;
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        return top == nullptr;
    }

    void push(int data)
    {
        //Write your code here
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
       
        size++;

    }

    void pop()
    {
        //Write your code here
        if(isEmpty()) return;
        int poppedvalue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        
    }

    int getTop()
    {
        //Write your code here
        if(isEmpty()) return -1;
        return top->data;
    }
};

```
