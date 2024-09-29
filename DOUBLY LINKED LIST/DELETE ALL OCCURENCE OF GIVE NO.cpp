Delete all occurrences of a given key in a doubly linked list
Difficulty: MediumAccuracy: 50.04%Submissions: 28K+Points: 4
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.

Example2:

Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(1).


  solution 1: optimized:

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *head= *head_ref;
        Node *curr=head;
        while(curr!=NULL){
            if(curr->data==x){
                // two important case
                if(curr->prev!=NULL){
                    curr->prev->next=curr->next;
                }
                else{
                    *head_ref=curr->next;//first node has to delete so head_ref pts. to next of curr. node
                }
                if(curr->next!=NULL){
                    curr->next->prev=curr->prev;
                }
            //  delete curr; //not compulsory
            }
            curr=curr->next;
        }
       return;
    }
};




FULL CODE:
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *head= *head_ref;
        Node *curr=head;
        while(curr!=NULL){
            if(curr->data==x){
                // two important case
                if(curr->prev!=NULL){
                    curr->prev->next=curr->next;
                }
                else{
                    *head_ref=curr->next;//first node has to delete so head_ref pts. to next of curr. node
                }
                if(curr->next!=NULL){
                    curr->next->prev=curr->prev;
                }
            //  delete curr; //not compulsory
            }
            curr=curr->next;
        }
       return;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends


SOLUTION 2 OPTIMIZSED:

/* C++ implementation to delete all occurrences 
   of a given key in a doubly linked list */
#include <bits/stdc++.h>
 
using namespace std;
 
/* a node of the doubly linked list */
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted
       is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted 
       is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);
}
 
/* function to delete all occurrences of the given
    key 'x' */
void deleteAllOccurOfX(struct Node** head_ref, int x)
{
    /* if list is empty */
    if ((*head_ref) == NULL)
        return;
 
    struct Node* current = *head_ref;
    struct Node* next;
 
    /* traverse the list up to the end */
    while (current != NULL) {
 
        /* if node found with the value 'x' */
        if (current->data == x) {
 
            /* save current's next node in the 
               pointer 'next' */
            next = current->next;
 
            /* delete the node pointed to by 
              'current' */
            deleteNode(head_ref, current);
 
            /* update current */
            current = next;
        }
 
        /* else simply move to the next node */
        else
            current = current->next;
    }
}
 
/* Function to insert a node at the beginning 
   of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = 
             (struct Node*)malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* since we are adding at the beginning,
    prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print nodes in a given doubly
   linked list */
void printList(struct Node* head)
{
    /* if list is empty */
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Create the doubly linked list:
           2<->2<->10<->8<->4<->2<->5<->2 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    push(&head, 2);
    push(&head, 2);
 
    cout << "Original Doubly linked list:n";
    printList(head);
 
    int x = 2;
 
    /* delete all occurrences of 'x' */
    deleteAllOccurOfX(&head, x);
 
    cout << "\nDoubly linked list after deletion of "
         << x << ":n";
    printList(head);
 
    return 0;
}
Output
Original Doubly linked list:n2 2 10 8 4 2 5 2 
Doubly linked list after deletion of 2:n10 8 4 5 
Time Complexity: O(n)
Auxiliary Space: O(1) because no extra space is required 

Certainly! Let's delve into the code line by line, explaining each part thoroughly, including why specific constructs like struct and double pointers (**) are used.

Code Overview
The function deleteAllOccurOfX is designed to delete all occurrences of a given value x from a doubly linked list. The doubly linked list is represented using nodes that contain data and pointers to both the previous and next nodes.

Understanding the Node Structure
First, let's recall the structure of a node in a doubly linked list:

cpp
Copy code
struct Node {
    int data;        // The data stored in the node
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
struct Node: The struct keyword is used to define a structure in C++. Structures are user-defined data types that group variables of different data types under a single name. In this case, Node is a structure representing a node in a doubly linked list.

Why use struct?
Using struct allows us to create a custom data type that can hold multiple related pieces of data (data, prev, and next) together.
It provides a clear and organized way to represent complex data structures like linked lists.
Function Signature
cpp
Copy code
void deleteAllOccurOfX(struct Node** head_ref, int x)
void: The function does not return any value.

deleteAllOccurOfX: The name of the function.

struct Node** head_ref:

struct Node*: A pointer to a Node structure.

struct Node**: A double pointer to a Node structure (i.e., a pointer to a pointer).

Why use a double pointer (Node**)?

When we need to modify the actual pointer passed to a function (in this case, head_ref), we use a pointer to that pointer.
If we only used a single pointer (Node* head), any changes to head inside the function would not affect the original head pointer outside the function.
Using Node** head_ref allows us to modify the head pointer itself, which is necessary if the head node needs to be deleted or updated.
int x: The value to be deleted from the list.

Function Body
1. Initializing Pointers
cpp
Copy code
Node *head = *head_ref;
Node *curr = head;
Node *head = *head_ref;
We dereference head_ref to get the actual head pointer of the list.
head_ref is a pointer to the head pointer, so *head_ref gives us the head pointer.
Node *curr = head;
We initialize curr (current node pointer) to start from the head of the list.
curr will be used to traverse the list.
2. Traversing the List
cpp
Copy code
while (curr != NULL) {
    // Loop body
    curr = curr->next;
}
while (curr != NULL)
This loop continues as long as curr is not NULL, i.e., until we reach the end of the list.
We traverse the list node by node.
3. Checking for Nodes to Delete
cpp
Copy code
if (curr->data == x) {
    // Deletion logic
}
if (curr->data == x)
We check if the data in the current node matches the value x that we want to delete.
If it matches, we proceed to delete this node.
4. Deleting the Node
Deletion in a doubly linked list requires careful updating of the surrounding nodes' pointers to maintain the integrity of the list.

a. Node is Not the Head Node
cpp
Copy code
if (curr->prev != NULL) {
    curr->prev->next = curr->next;
}
if (curr->prev != NULL)

We check if the current node has a previous node.
If curr->prev is not NULL, it means curr is not the head node.
curr->prev->next = curr->next;

We update the next pointer of the previous node to point to the node after curr.
This effectively skips over curr, removing it from the list.
b. Node is the Head Node
cpp
Copy code
else {
    *head_ref = curr->next;
}
else

If curr->prev is NULL, it means curr is the head node.
*head_ref = curr->next;

We update the head pointer by dereferencing head_ref and setting it to curr->next.

This effectively moves the head of the list to the next node, since the current head node is being deleted.

Why dereference head_ref?

Since we passed a pointer to the head pointer (Node** head_ref), we need to dereference it to modify the actual head pointer.
This ensures that the change to the head pointer persists outside the function.
c. Updating the Next Node's prev Pointer
cpp
Copy code
if (curr->next != NULL) {
    curr->next->prev = curr->prev;
}
if (curr->next != NULL)

We check if there is a node after the current node.
If curr->next is not NULL, it means curr is not the tail node.
curr->next->prev = curr->prev;

We update the prev pointer of the next node to point to the node before curr.
This maintains the correct linkage after curr is removed.
d. Optional Deletion of the Current Node
cpp
Copy code
// delete curr; // not compulsory
delete curr;
This line is commented out but would be used to deallocate the memory occupied by curr.

Since the function might be expected to manage memory, including this line ensures there are no memory leaks.

Why is it commented as "not compulsory"?

In some contexts, the deletion of nodes might be handled elsewhere, or the environment (e.g., an online judge) may not require explicit deletion.
However, in good practice, especially in C++, we should delete dynamically allocated memory when it's no longer needed to prevent memory leaks.
5. Moving to the Next Node
cpp
Copy code
curr = curr->next;
curr = curr->next;
After handling the current node (whether we deleted it or not), we move curr to the next node in the list.

This continues the traversal.

Potential Issue:

Important Note: If we delete curr, we need to be careful when moving to the next node.
Since curr might have been deleted, accessing curr->next could lead to undefined behavior.
To avoid this, we might need to store curr->next before deleting curr.
Improved Version:

cpp
Copy code
Node* nextNode = curr->next;
// Deletion logic
curr = nextNode;
6. Function Return
cpp
Copy code
return;
return;
The function is of type void, so it does not return a value.
This line indicates the end of the function.
Putting It All Together with Improvements
Given the potential issue with moving to the next node after deletion, here's an improved version of the function:

cpp
Copy code
void deleteAllOccurOfX(struct Node** head_ref, int x) {
    Node *curr = *head_ref;

    while (curr != NULL) {
        Node* nextNode = curr->next; // Store the next node

        if (curr->data == x) {
            // Deletion logic
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                *head_ref = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            delete curr; // Free the memory occupied by curr
        }

        curr = nextNode; // Move to the next node
    }
}
Why store nextNode before deletion?
If we delete curr, accessing curr->next afterward is unsafe because curr no longer exists.
By storing curr->next in nextNode before potentially deleting curr, we ensure we have a valid pointer to the next node.
Summary
Double Pointer (Node**) Usage:

Allows modification of the original head pointer in the calling function.
Necessary when the head node itself might be deleted, requiring an update to the head pointer.
struct Usage:

Defines a custom data type (Node) to represent nodes in the linked list.
Groups related data (data, prev, next) into a single unit.
Deletion Logic in Doubly Linked List:

Update the next pointer of the previous node (if it exists).
Update the prev pointer of the next node (if it exists).
Handle the case where the node to delete is the head node.
Ensure memory is properly managed by deleting nodes when necessary.
Traversing the List:

Move through the list using a loop.
Be cautious when deleting nodes during traversal to avoid invalid memory access.
Example Walkthrough
Let's consider an example to illustrate how the function works.

Linked List:

rust
Copy code
Head -> [1] <-> [2] <-> [3] <-> [2] <-> [4] -> NULL
Value to Delete: 2

Step-by-Step Execution:

Initialization:

curr = head (points to node with data 1).
First Iteration (curr->data = 1):

Data does not match x.
Move to next node: curr = curr->next (node with data 2).
Second Iteration (curr->data = 2):

Data matches x.
Deletion Logic:
curr->prev is not NULL (points to node with data 1).
Update curr->prev->next to curr->next (node with data 3).
curr->next is not NULL (points to node with data 3).
Update curr->next->prev to curr->prev (node with data 1).
Delete curr (node with data 2).
Move to next node: curr = curr->next (node with data 3).
Third Iteration (curr->data = 3):

Data does not match x.
Move to next node: curr = curr->next (node with data 2).
Fourth Iteration (curr->data = 2):

Data matches x.
Deletion Logic:
curr->prev is not NULL (points to node with data 3).
Update curr->prev->next to curr->next (node with data 4).
curr->next is not NULL (points to node with data 4).
Update curr->next->prev to curr->prev (node with data 3).
Delete curr (node with data 2).
Move to next node: curr = curr->next (node with data 4).
Fifth Iteration (curr->data = 4):

Data does not match x.
Move to next node: curr = curr->next (NULL).
End of Loop:

curr is NULL, exit the loop.
Resulting Linked List:

rust
Copy code
Head -> [1] <-> [3] <-> [4] -> NULL
All occurrences of 2 have been deleted from the list.

Conclusion
The function efficiently deletes all occurrences of a specified value from a doubly linked list.
It carefully handles edge cases, such as deleting the head node or nodes in between.
By using a double pointer for head_ref, it ensures that any changes to the head pointer are reflected outside the function.
Proper memory management is considered by deleting nodes that are removed from the list.
The use of struct allows for a clean and organized representation of the linked list nodes.
Additional Notes
Memory Management:

In C++, when you allocate memory dynamically using new, it's important to free that memory using delete to prevent memory leaks.
Even though it's commented as "not compulsory" in the code, it's good practice to include delete curr; when a node is no longer needed.
Avoiding Undefined Behavior:

Accessing or modifying a pointer after it's been deleted leads to undefined behavior.
Always ensure that you save any necessary pointers before deleting a node.
Function Parameters:

Passing pointers by reference (Node** head_ref) allows the function to modify the original pointer.
This is essential when the function needs to update the head of the list.
Robustness:

The function assumes that the input list is valid.
In production code, you might want to include additional checks for null pointers and other potential issues.
I hope this detailed explanation clarifies each part of the code and the reasoning behind the use of specific constructs like struct and double pointers. Let me know if you have any further questions!


Sure! Let’s go through the code line by line, explaining what each line does, along with the reasoning behind using certain structures and operators like struct, **, and more.

The Function Definition:
cpp
Copy code
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
class Solution: We define a class named Solution, where our function will reside. This class encapsulates the function, making it easier to handle multiple operations related to linked lists in a structured way.

void deleteAllOccurOfX(struct Node** head_ref, int x):

void: This means the function does not return any value.
deleteAllOccurOfX: The name of the function that will delete all nodes with value x in the doubly linked list.
struct Node** head_ref:
struct Node: Declares that the Node is a structure. Using struct explicitly reminds us that Node is a custom-defined data structure.
Node** head_ref: This is a pointer to a pointer (**). Why do we use a double pointer (Node**) here?
The reason is that the function may modify the head of the list (like when deleting the first node). If we pass a single pointer, the function would modify a local copy and the changes wouldn't reflect outside the function. A double pointer (**) allows the actual head to be updated, even outside the function.
int x: The value to search for and delete from the list.
Initializing Local Pointers:
cpp
Copy code
        Node *head = *head_ref;
        Node *curr = head;
Node *head = *head_ref;: We create a local pointer head that points to the actual head of the linked list. *head_ref dereferences the double pointer, giving us the actual pointer to the first node.
Node *curr = head;: We create another pointer curr which will traverse through the list, starting at the head. This is the main pointer used in the loop to check each node's value.
Traversing the List:
cpp
Copy code
        while(curr != NULL){
while(curr != NULL): This loop traverses the list node by node, continuing until curr becomes NULL, which indicates the end of the list. The goal here is to check every node in the list for the value x.
Checking if the Current Node Contains the Value x:
cpp
Copy code
            if(curr->data == x){
if(curr->data == x): This condition checks if the data of the current node (curr) is equal to x, which means this is a node we want to delete.
Handling the Deletion of a Node:
Case 1: The Node is Not the First Node
cpp
Copy code
                if(curr->prev != NULL){
                    curr->prev->next = curr->next;
                }
if(curr->prev != NULL): This checks if the current node (curr) has a previous node, i.e., it is not the first node of the list.
In doubly linked lists, the first node has its prev pointer set to NULL, so this condition identifies if curr is not the head.
curr->prev->next = curr->next;: If the current node is not the first node, we update the next pointer of the previous node (curr->prev) to skip the current node and point to the node after curr (curr->next).
Case 2: The Node is the First Node (Head)
cpp
Copy code
                else{
                    *head_ref = curr->next;
                }
else: This block executes when the node to delete is the first node (because curr->prev == NULL).
*head_ref = curr->next;: Since the first node is being deleted, we need to update the head of the list. We assign the next node (curr->next) as the new head. This is why we use *head_ref, so the actual head pointer is modified outside the function.
Updating the prev Pointer of the Next Node (If It Exists):
cpp
Copy code
                if(curr->next != NULL){
                    curr->next->prev = curr->prev;
                }
if(curr->next != NULL): This condition checks if the current node is not the last node in the list. If the current node (curr) is the last node, curr->next will be NULL.
curr->next->prev = curr->prev;: If the current node is not the last, we update the prev pointer of the next node (curr->next) to point to curr->prev. This ensures the doubly linked structure is maintained.
Moving to the Next Node:
cpp
Copy code
            curr = curr->next;
curr = curr->next;: After handling the deletion (if any), we move curr to the next node in the list to continue checking for more occurrences of x.
Completing the Function:
cpp
Copy code
        }
       return;
}: The loop ends when all nodes are checked and deleted if necessary.
return;: The function completes and returns. Since the function is void, no value is returned, but the list will have been modified.
Why Do We Use struct?
struct: In C++, the struct keyword is used to define custom data types (like Node). It creates a structure that can hold multiple members, including data (like data, next, prev) and pointers. In this case, the struct Node defines each node in the doubly linked list, with:
int data: To hold the data of the node.
Node* next: Pointer to the next node.
Node* prev: Pointer to the previous node.
Why Use ** (Double Pointer)?
Double Pointer (Node** head_ref): A single pointer (Node*) is enough to traverse the linked list. However, if the function needs to modify the head of the list (as it does when the first node is deleted), a single pointer won't work.
A single pointer would modify a local copy of the head, leaving the original head unchanged outside the function.
Using a double pointer (Node**) allows the function to change the actual pointer to the head, ensuring that changes made inside the function are reflected outside the function as well.
Summary of Functionality:
The function traverses the entire doubly linked list.
For each node with data equal to x, the node is deleted.
Proper care is taken to handle the cases where the node is the head or tail of the list.
The head_ref is updated if the first node is deleted.
The list is maintained as a doubly linked list by updating the prev and next pointers accordingly.
