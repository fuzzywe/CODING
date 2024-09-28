Search an element in a Linked List


17

0
Problem Statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.

Examples
Example 1:

Input Format: 0->1->2, val = 2

Result True

Explanation: Since element 2 is present in the list, it will return true.


Example 2:

Input Format: 12->5->8->7, val = 6 

Result False

Explanation: The list does not contain element 6. Therefore, it returns false.

Solution:
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Approach:
To check if an element is present in the linked list, traverse the list and at every node, check whether the data matches the specified value val. If a match is found, return true; otherwise, after traversing the entire list, return false.

Algorithm:
To check if an element is present in the linked list, start with a temp pointer pointing to the head. This pointer will be used to traverse the list, ensuring that the reference to the starting point is not lost. During the traversal, check if the data on the current node matches the specified value val. If no match is found, move to the next node using the next pointer of the current node.

At any moment, the data of the node matches with the val, stop, and return 1.

If, during traversal, the temp reaches the end, it means that it has reached the last point, which is NULL, hence, returns false at the end.
Code:

C++
Java
Python
// Node class represents a node in a linked list
class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node in the      list

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to check if a given element is present in the linked list
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    // Traverse the linked list
    while (temp != nullptr) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found

        // Move to the next node
        temp = temp->next;
    }

    return 0;  // Return 0 if the element is not found in the linked list
}

// Main function
int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 5;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    cout << checkifPresent(head, val) << '\n';

    return 0;  // Return 0 to indicate successful execution
}
Output: True

Time Complexity: O(N) in the worst case if the element is not found. O(1) in the best case if the element is the first element. 

Space Complexity: O(1) as we did not use any extra space.



  IN CODE PLATFORM THE MISTAKE I DID:

SEGMENTATION ERROR BECAUSE OF HTIS
  Node* temp = head;
        while(head!=nullptr)
        {
            if(temp->data == key){
                return 1;
            }
            temp = temp->next;
        }return 0;

the CORRECT ANS IS 
bool searchKey(int n, struct Node* head, int key) {
        // Code here
        
        Node* temp = head;
        while(temp!=nullptr)
        {
            if(temp->data == key){
                return 1;
            }
            temp = temp->next;
        }return 0;
    }
};
