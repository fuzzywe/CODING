Remove duplicates from a sorted linked list
Last Updated : 07 Sep, 2024
Given a linked list sorted in non-decreasing order. Return the list by deleting the duplicate nodes from the list. The returned list should also be in non-decreasing order.

Example:

Input : Linked List = 11->11->11->21->43->43->60
Output : 11->21->43->60
Explanation:


Remove-duplicates-from-a-sorted-linked-list


[Expected Approach] By Changing Next Pointer – O(n) Time and O(1) Space:
The idea is to traverse the linked list and for each node, if the next node has the same data, skip and delete the duplicate node.


Follow the steps below to solve the problem:

Ttraverse the linked list starting from the head node.
Iterate through the list, comparing each node with the next node.
If the data in the next node is same as the curr node adjust pointers to skip the next node.
Below is the implementation of the above approach: 





// C++ Program to remove duplicates from a
// sorted linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


Node *removeDuplicates(Node *head) {
    Node *curr = head;

    // Traverse the list
    while (curr != NULL && curr->next != NULL) {
      
        // Check if next value is same as current
        if (curr->data == curr->next->data) {
            Node *next_next = curr->next->next;
            curr->next = next_next;
        }
        else
            curr = curr->next;
    }
    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    // Create a sorted linked list
    // 11->11->11->13->13->20
    Node *head = new Node(11);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(20);

    cout << "Linked list before duplicate removal:" << endl;
    printList(head);

    head = removeDuplicates(head);

    cout << "Linked list after duplicate removal:" << endl;
    printList(head);

    return 0;
}

Output
Linked list before duplicate removal:
11 11 11 13 13 20 
Linked list after duplicate removal:
11 13 20 
Time Complexity: O(n) where n is the number of nodes in the given linked list.
Auxiliary Space: O(1)

[Alternate Approach] Using Recursion – O(n) Time and O(n) Space:
The idea is similar to the iterative approach. Here we are using the recursion to check each node and its next for duplicates. Please note that the iterative approach would be better in terns of time and space. The recursive approach can be good fun exercise or a question in an interview / exam.


Follow the steps below to solve the problem:

If the curr node or its next node is NULL, return the curr node.
If the current node’s data equals the next node’s data, adjust pointers to skip the duplicate.
If no duplicate, recursively process the next node.
Below is the implementation of the above approach: 





// C++ Program to remove duplicates from a
// sorted linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to remove duplicates
void removeDuplicates(Node *head) {
  
    // Base case: if the list is empty, return
    if (head == NULL)
        return;
  
    // Check if the next node exists
    if (head->next != NULL) {
      
        // If current node has duplicate
        // data with the next node
        if (head->data == head->next->data) {
            head->next = head->next->next;
            removeDuplicates(head);
        }
        else{
            removeDuplicates(head->next);
        }
    }
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    // Create a sorted linked list
    // 11->11->11->13->13->20
    Node *head = new Node(11);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(20);

    cout << "Linked list before duplicate removal:" << endl;
    printList(head);

    removeDuplicates(head);

    cout << "Linked list after duplicate removal:" << endl;
    printList(head);

    return 0;
}

Output
Linked list before duplicate removal:
11 11 11 13 13 20 
Linked list after duplicate removal:
11 13 20 
Time Complexity: O(n) , where n is the number of nodes in the given linked list.
Auxiliary Space: O(n)
Remove duplicates from a sorted linked list

Input : Linked List = 5->10->10->20
Output : 5->10->20 (After removing duplicate elements)

