
https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897

https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

https://leetcode.com/problems/reverse-linked-list/


https://www.codechef.com/practice/course/interview-dsa/DSAPREP_08/problems/RTLL

Reverse a Linked List

Input Format:

LL: 1   3   2   4 


Output: 3


Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.

Example 2:

Input Format:

LL: 4


Output: 4


Explanation: In this example, the linked list contains only one node hence reversing this linked list will result in the same list as the original.


brute force :

```cpp


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse the
// linked list using a stack
Node* reverseLinkedList(Node* head) {
    // Create a temporary pointer
    // to traverse the linked list
    Node* temp = head;  
    
    // Create a stack to temporarily
    // store the data values
    stack<int> st;     

    // Step 1: Push the values of the
    // linked list onto the stack
    while (temp != nullptr) {
        // Push the current node's
        // data onto the stack
        st.push(temp->data); 
        
        // Move to the next node
        // in the linked list
        temp = temp->next;    
    }
    
    // Reset the temporary pointer to
    // the head of the linked list
    temp = head; 
    
    // Step 2: Pop values from the stack
    // and update the linked list
    while (temp != nullptr) {
        // Set the current node's data to
        // the value at the top of the stack
        temp->data = st.top();  
        
        // Pop the top element from the stack
        st.pop();              
        
        // Move to the next node
        // in the linked list
        temp = temp->next;     
    }
    
    // Return the new head of
    // the reversed linked list
    return head;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}



```

---


```cpp

    class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== NULL || head->next == NULL) return head;
        ListNode* temp= reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return temp;
    }
};


```

---

```cpp

    class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr; // Previous node starts as NULL
        ListNode* next = nullptr; // Next node
        ListNode* curr = head;    // Current node starts at the head

        // Traverse the list
        while (curr != nullptr) {
            // Save the next node
            next = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move pointers forward
            prev = curr; // Move prev to the current node
            curr = next; // Move curr to the next node
        }

        // prev is now the new head of the reversed list
        return prev;
    }
};


```

Complexity
Time complexity:
The time complexity of this solution is O(n), because we reversed the linked list in a single pass, where 𝑛 n is the number of nodes in a linked list.

Space complexity:
The space complexity of this solution is O(1), because no extra memory is used.

---


![image](https://github.com/user-attachments/assets/2ae2c30b-c824-428b-8fe5-0a1f33d67a08)


![image](https://github.com/user-attachments/assets/faf609d5-f7e0-46a0-b3f2-c2c796a486eb)

![image](https://github.com/user-attachments/assets/18f43682-bcad-4ab6-8012-5893a5f3342d)

![image](https://github.com/user-attachments/assets/70583232-6344-4e39-8482-0ef15102049b)

![image](https://github.com/user-attachments/assets/7983695f-21c0-4a24-9750-b4a9f17c9908)


![image](https://github.com/user-attachments/assets/773f86c6-f46b-4150-b37e-9d0fa0b5477c)

![image](https://github.com/user-attachments/assets/a26060ef-ed2a-464d-bc62-2e4027121a82)


![image](https://github.com/user-attachments/assets/e8610794-6f88-46f9-b59b-af573a4c1c7c)


![image](https://github.com/user-attachments/assets/493d356d-36fc-4482-b00b-8bdaf142f57e)

![image](https://github.com/user-attachments/assets/e4e142b6-3f88-41be-aa8d-b6a13d0f838c)


![image](https://github.com/user-attachments/assets/ca77bdf3-3f0b-4622-a896-fbf28a1a38ac)






