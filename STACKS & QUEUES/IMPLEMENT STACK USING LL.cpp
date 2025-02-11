Here’s a simple **Stack implementation using a Linked List** in C++.

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
