Find the Length of a Linked List


19

1
Problem Statement: Given the head of a linked list, print the length of the linked list.

Examples
Example 1:

Input Format: 0->1->2

Result: 3

Explanation: The list has a total of 3 nodes, thus the length of the list is 3.


Example 2:

Input Format: 2->5->8->7

Result: 4

Explanation: Again, the list has 4 nodes, hence, the list length is 4.

Solution:
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Approach:
The most naive method to find the length of a linked list is to count the number of nodes in the list by doing a traversal in the Linked list.

Algorithm:
Start by initializing a pointer to the head that will be used for traversing and initializing a cnt variable to 0.

Traverse the linked list using the pointer, and at every node, increment cnt.

After reaching the end of the linked list, return cnt, this will be your total number of nodes which is the length of the linked list.

Code:

C++
Java
Python
class Node {
public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to calculate the length of a linked list
int lengthOfLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL) {
        temp = temp->next;
        cnt++; // increment cnt for every node traversed
    }
    return cnt;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    
    // Create a linked list
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    
    // Print the length of the linked list
    cout << lengthOfLinkedList(head) << '\n';
}
Output: 4

Time Complexity: 

Since we are iterating over the entire list,  time complexity is O(N).

Space Complexity:

We are not using any extra space, thus space complexity is O(1) or constant.
