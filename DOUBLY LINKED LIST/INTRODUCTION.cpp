Doubly Linked List Tutorial
Last Updated : 12 Aug, 2024
A doubly linked list is a more complex data structure than a singly linked list, but it offers several advantages. The main advantage of a doubly linked list is that it allows for efficient traversal of the list in both directions. This is because each node in the list contains a pointer to the previous node and a pointer to the next node. This allows for quick and easy insertion and deletion of nodes from the list, as well as efficient traversal of the list in both directions.

What is a Doubly Linked List?
A doubly linked list is a data structure that consists of a set of nodes, each of which contains a value and two pointers,
one pointing to the previous node in the list and one pointing to the next node in the list. 
This allows for efficient traversal of the list in both directions, making it suitable for applications 
where frequent insertions and deletions are required.

Insertion-at-the-End-in-Doubly-Linked-List-copy
Doubly Linked List
Representation of Doubly Linked List in Data Structure
In a data structure, a doubly linked list is represented using nodes that have three fields:

Data
A pointer to the next node (next)
A pointer to the previous node (prev)

Node Definition
Here is how a node in a Doubly Linked List is typically represented:






struct Node {

    // To store the Value or data.
    int data;

    // Pointer to point the Previous Element
    Node* prev;

    // Pointer to point the Next Element
    Node* next;
  
    // Constructor
    Node(int d) {
       data = d;
       prev = next = nullptr;      
    }
};
Each node in a Doubly Linked List contains the data it holds, a pointer to the next node in the list, and a pointer to the previous node in the list. By linking these nodes together through the next and prev pointers, we can traverse the list in both directions (forward and backward), which is a key feature of a Doubly Linked List.

Operations on Doubly Linked List
Traversal in Doubly Linked List
Searching in Doubly Linked List
Finding Length of Doubly Linked List
Insertion in Doubly Linked List:
Insertion at the beginning of Doubly Linked List
Insertion at the end of the Doubly Linked List
Insertion at a specific position in Doubly Linked List
Deletion in Doubly Linked List:
Deletion of a node at the beginning of Doubly Linked List
Deletion of a node at the end of Doubly Linked List
Deletion of a node at a specific position in Doubly Linked List
Let’s go through each of the operations mentioned above, one by one.

Traversal in Doubly Linked List
To Traverse the doubly list, we can use the following steps:

a. Forward Traversal:

Initialize a pointer to the head of the linked list.
While the pointer is not null:
Visit the data at the current node.
Move the pointer to the next node.
b. Backward Traversal:

Initialize a pointer to the tail of the linked list.
While the pointer is not null:
Visit the data at the current node.
Move the pointer to the previous node.
Below are the implementation of the above approach:





#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data; 
    Node* next; 
    Node* prev; 
  
    // Constructor to initialize Node with data
    Node(int data) : data(data), next(nullptr),
  	prev(nullptr) {}
};

// Function to traverse the doubly linked list 
// in forward direction
void forwardTraversal(Node* head) {
  
    // Start traversal from the head of the list
    Node* curr = head;

    // Continue until current node is not null
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the next node
        curr = curr->next;
    }

    // Print newline after traversal
    cout << endl;
}

// Function to traverse the doubly linked list 
// in backward direction
void backwardTraversal(Node* tail) {
  
    // Start traversal from the tail of the list
    Node* curr = tail;

    // Continue until current node is not null 
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the previous node
        curr = curr->prev;
    }

    // Print newline after traversal
    cout << endl;
}

int main() {
  
    // Sample usage of the doubly linked list and 
    // traversal functions
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Forward Traversal:" << endl;
    forwardTraversal(head);

    cout << "Backward Traversal:" << endl;
    backwardTraversal(third);

    return 0;
}

Output
Forward Traversal:
1 2 3 
Backward Traversal:
3 2 1 
