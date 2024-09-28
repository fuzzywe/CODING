Delete Last Node of Linked List






Examples
Example 1:

Examples:

Input Format: 0->1->2

Result: 0->1


Explanation: The tail of the list is the last node. After removing the tail, and updating the linked list, this result is what we get.

Example 2:

Input Format: 12->5->8->7

Result: 12->5->8

Explanation: Again, after deleting the tail and updating the linked list, the list ends at the second last node, which is the new tail.

Solution
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Approach:
The main intuition is to point the second last node to null to get the updated linked list. Hence, we will iterate till the second last node and make it point to NULL. This will effectively skip the last node of the list therefore, we will free up the memory being occupied by this node (Only in the case of C++).

Two edge cases to consider are:

If the input linked list is empty, we return null.
If there is only one node in the list, that node itself will be the tail, therefore we return null after deleting that node.
Algorithm:
Start by initializing a pointer to the head of the list that will be used to iterate through the linked list. Iterate up to the second last node, this node will be our new tail of the list.

After reaching the second-to-last node, free up the memory occupied by the former tail or the last node of the list.
Note: In the case of languages like Java, Python, and Javascript, there is no need for the deletion of objects or nodes because these have an automatic garbage collection mechanism that automatically identifies and reclaims memory that is no longer in use.

Finally, point the second last node or the new tail to NULL to obtain the updated linked list.

Code:

C++
Java
Python
// Node class for a linked list
class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}
int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    head = deleteTail(head);
    // Print the linked list after deletion
    printLL(head);
}
Output: 12 5 8

Time Complexity: O(N) for traversing the linked list and updating the tail.


Space Complexity: O(1), as we have not used any extra space.








    There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.
 

Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};



The task here is to delete a node from a singly-linked list. However, you are not given access to the head of the list, but only to the node that needs to be deleted.

To simulate deletion, the solution replaces the current node's value with the value of the next node and then bypasses the next node by pointing the current node to the next node’s next pointer.

Code Dry-Run:
Linked List Example:

Let's assume we have the following linked list:

rust
Copy code
4 -> 5 -> 1 -> 9
You are given the node with value 5 that needs to be deleted.

Before Function Call:

node is a pointer to the node with value 5.
node is part of the list: 4 -> 5 -> 1 -> 9.
Function Execution: Now let's break down the function deleteNode line by line for this situation.

Step 1:

cpp
Copy code
node->val = node->next->val;
Here, node->val refers to the value of the current node (which is 5).
node->next->val is the value of the next node (which is 1).
This line replaces the value 5 with the value 1, so the linked list now looks like:
rust
Copy code
4 -> 1 -> 1 -> 9
Step 2:

cpp
Copy code
node->next = node->next->next;
node->next points to the next node (which is the node with value 1).
node->next->next points to the node after that (which is the node with value 9).
This line changes node->next to bypass the node with value 1 and point directly to the node with value 9.
After this, the list looks like:
rust
Copy code
4 -> 1 -> 9
After Function Call:

The node with value 5 has been effectively "deleted" by overwriting its value with the next node's value and adjusting the pointer.
The final linked list is:
rust
Copy code
4 -> 1 -> 9
Summary of Steps:
The current node’s value (node->val) is replaced with the value of the next node (node->next->val).
The next pointer of the current node (node->next) is updated to point to the next node’s next node (node->next->next), effectively removing the next node from the list.
This approach deletes the given node from the list without needing the head of the list.

Dry-Run of the Code:
Input List: 4 -> 5 -> 1 -> 9
Given node: 5
After Step 1: Replace 5 with 1, so list becomes 4 -> 1 -> 1 -> 9
After Step 2: Bypass the second 1, so list becomes 4 -> 1 -> 9
