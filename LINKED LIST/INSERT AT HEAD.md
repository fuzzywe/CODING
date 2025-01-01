The line 

```cpp
Node* temp = new Node(val, head);
```

is commonly used in **linked list implementations** when you need to create a new node and link it to an existing list.

### Explanation:

1. **`Node* temp`**  
   - `Node*` declares a pointer to a `Node` object.
   - `temp` will hold the memory address of the newly created node.

2. **`new Node(val, head)`**  
   - The `new` operator dynamically allocates memory for a new `Node` object and returns its address.
   - `Node(val, head)` invokes the `Node` constructor, initializing the node with a value (`val`) and a pointer to the next node (`head`).

### Why do you need this?

- **Dynamic Memory Allocation:**  
  In linked lists, nodes are typically created dynamically (at runtime) because the size of the list is not fixed. Using `new` ensures the node persists in memory even after the function scope ends.

- **To Add a New Node to the List:**  
  - This is typically used to add a new node at the beginning of the list. The `head` pointer (which points to the current first node) is passed to the constructor, making the new node point to the existing list.
  - After this, you update `head` to point to `temp`, making the new node the head of the list.

### Example in Context

Suppose you have a `Node` class defined as:

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) : data(val), next(nextNode) {}
};
```

To add a new node to a linked list:

```cpp
Node* head = nullptr; // Initially, the list is empty

// Add a new node with value 10
Node* temp = new Node(10, head); 
head = temp; // Update head to point to the new node

// Add another node with value 20
temp = new Node(20, head); 
head = temp;
```

### Result:
- The list now looks like:  
  **20 -> 10 -> null**  

Without creating `temp` using `new`, the node wouldn’t be dynamically allocated, and it could go out of scope or not persist, breaking the linked list structure.
