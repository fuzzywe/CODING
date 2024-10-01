delete the Middle Node of the Linked List


16

1
Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5 


Output: 1 2 4 5


Explanation: Node with value 3 is at the middle node and deleted.

Example 2:

Input Format:

LL: 1  2  3  4


Output: 1 2 4


Explanation: In this example, the linked list has an even number of nodes hence we return the second middle node which is 3.

Practice:
Solve Problem
code-studio
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Brute Force Approach
Algorithm / Intuition
Using the brute force approach, the middle node of a linked list can be determined by traversing the entire linked list initially to find the total number of nodes, denoted as `n`. Then we reset the temporary node `temp` to the head of the linked list and proceed to traverse to the node positioned at index `[n/2]`, which represents either the middle node in an odd-lengthed list or the node just before the middle node in an even-lengthed linked list.

Algorithm:
Step 1: Traverse the linked list to count the number of nodes and store the length as `n`. Calculate the index of the middle node by dividing the total number of nodes by 2.


Step 2: Traverse the linked list again while keeping track of the node count to reach the middle node. 


Step 3: Once reaching the middle node, delete it by setting the next pointer of the previous node directly to the node after the middle node. Free the memory allocated to the middle node.


Code
C++
Java
Python
JavaScript
Copy

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:

    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to delete the
// middle node of a linked list
Node *deleteMiddle(Node *head) {
    // Initialize a temporary node
    // to traverse the linked list
    Node* temp = head;
    
    // Variable to hold the number
    // of nodes in the linked list
    int n = 0;
    
    // Loop to count the number of
    // nodes in the linked list
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    
    // Calculate the index of the middle node
    int res = n/2;
    
    // Reset the temporary node to
    // the beginning of the linked list
    temp = head;
    
    // Loop to find the
    // middle node to delete
    while(temp!=NULL){
        
        res --;
        
        // If the middle node is found
        if(res==0){
            
            // Create a pointer
            // to the middle node
            Node* middle = temp->next;
            
            // Adjust pointers to
            // skip the middle node
            temp->next = temp->next->next;
            
            // Free the memory allocated
            // to the middle node
            free(middle);
            
            // Exit the loop after
            // deleting the middle node
            break;
        }
        // Move to the next node
        // in the linked list
        temp = temp->next;
    }
    // Return the head of the
    // modified linked list
    return head;
}


void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}


Output: Original Linked List: 1 2 3 4 5  Updated Linked List: 1 2 4 5 

Complexity Analysis

Time Complexity: O(N + N/2) The loop traverses the entire linked list once to count the total number of nodes then the loop iterates halfway through the linked list to reach the middle node. Hence, the time complexity is O(N + N/2) ~ O(N).

Space Complexity : O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 

Optimal Approach
Algorithm / Intuition
The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal.

The 'slow' pointer advances one node at a time while the 'fast' pointer moves two nodes at a time. By doing so, when the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.

Since we require `slow` to reach the node before the middle node, we give `fast` a head start!

Algorithm
Step 1: Check if the list is empty or contains only one node. If so, no middle node exists to delete, return NULL. Initialise 'slow' and 'fast' pointers at the head of the list.

Move ‘fast’ two nodes ahead for the initial position as we have to reach the node previous to the middle node via slow.

Step 2: Move the 'fast' pointer two nodes ahead and the 'slow' pointer one node ahead in each iteration. Continue this process until the 'fast' pointer reaches the end of the list.


Step 3: Once the 'fast' pointer reaches the end, the 'slow' pointer will be at the middle node. Delete the middle node by skipping it from the linked list. 


Step 4: Return the head of the modified linked list.

Code
C++
Java
Python
JavaScript
Copy

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:

    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to delete the
// middle node of a linked list
Node *deleteMiddle(Node *head) {
    // If the list is empty or has only one node,
    // return NULL as there is no middle node to delete
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    slow->next = slow->next->next;
    return head;
}

void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}

Output: Original Linked List: 1 2 3 4 5 Updated Linked List: 1 2 4 5

Complexity Analysis

Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).

Space Complexity: O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 
