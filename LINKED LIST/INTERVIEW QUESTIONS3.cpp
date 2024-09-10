Here are answers to all the Linked List interview questions, with explanations and C++ code where necessary:

### **Basic Questions:**

1. **What is a Linked List? How does it differ from an array?**
   - **Linked List** is a dynamic data structure where each element (node) contains a pointer to the next node in the sequence.
   - **Differences**:
     - **Array**: Fixed size, contiguous memory, random access.
     - **Linked List**: Dynamic size, non-contiguous memory, sequential access.

2. **What are the different types of linked lists?**
   - **Singly Linked List**: Each node points to the next node.
   - **Doubly Linked List**: Each node has two pointers, one to the next node and one to the previous node.
   - **Circular Linked List**: Last node points back to the first node.

3. **How do you represent a node in a singly linked list?**

   ```cpp
   struct Node {
       int data;
       Node* next;
   };
   ```

4. **How do you insert a node at the beginning, middle, and end of a singly linked list?**

   - **Insert at Beginning**:

     ```cpp
     void insertAtBeginning(Node*& head, int data) {
         Node* newNode = new Node();
         newNode->data = data;
         newNode->next = head;
         head = newNode;
     }
     ```

   - **Insert at End**:

     ```cpp
     void insertAtEnd(Node*& head, int data) {
         Node* newNode = new Node();
         newNode->data = data;
         newNode->next = nullptr;
         if (head == nullptr) {
             head = newNode;
         } else {
             Node* temp = head;
             while (temp->next != nullptr) {
                 temp = temp->next;
             }
             temp->next = newNode;
         }
     }
     ```

5. **How would you traverse a linked list?**

   ```cpp
   void traverseList(Node* head) {
       Node* temp = head;
       while (temp != nullptr) {
           cout << temp->data << " ";
           temp = temp->next;
       }
   }
   ```

6. **What is the time complexity for searching an element in a singly linked list?**
   - Time complexity is **O(n)**, since you may need to traverse all nodes in the worst case.

7. **Explain how to delete a node from a linked list (head, middle, and last node).**
   - **Delete at Head**:

     ```cpp
     void deleteAtHead(Node*& head) {
         if (head != nullptr) {
             Node* temp = head;
             head = head->next;
             delete temp;
         }
     }
     ```

   - **Delete in Middle**:

     ```cpp
     void deleteNode(Node*& head, int key) {
         if (head == nullptr) return;
         if (head->data == key) {
             deleteAtHead(head);
             return;
         }
         Node* temp = head;
         while (temp->next != nullptr && temp->next->data != key) {
             temp = temp->next;
         }
         if (temp->next == nullptr) return;
         Node* toDelete = temp->next;
         temp->next = toDelete->next;
         delete toDelete;
     }
     ```

8. **How would you reverse a singly linked list?**

   - **Iterative Method**:

     ```cpp
     void reverseList(Node*& head) {
         Node* prev = nullptr;
         Node* curr = head;
         Node* next = nullptr;
         while (curr != nullptr) {
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
         }
         head = prev;
     }
     ```

   - **Recursive Method**:

     ```cpp
     Node* reverseRecursive(Node* head) {
         if (head == nullptr || head->next == nullptr)
             return head;
         Node* rest = reverseRecursive(head->next);
         head->next->next = head;
         head->next = nullptr;
         return rest;
     }
     ```

9. **How would you detect a loop in a linked list?**
   - **Floyd’s Cycle Detection Algorithm** (Tortoise and Hare):

     ```cpp
     bool hasCycle(Node* head) {
         if (head == nullptr || head->next == nullptr) return false;
         Node* slow = head;
         Node* fast = head;
         while (fast != nullptr && fast->next != nullptr) {
             slow = slow->next;
             fast = fast->next->next;
             if (slow == fast) return true;
         }
         return false;
     }
     ```

10. **How would you find the middle element of a linked list?**
    - **Two Pointer Method**: Use two pointers (slow and fast); slow moves one step, fast moves two steps. When fast reaches the end, slow will be at the middle.

    ```cpp
    Node* findMiddle(Node* head) {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ```

11. **How do you merge two sorted linked lists into a single sorted linked list?**

    ```cpp
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->data < l2->data) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ```

12. **How would you find the nth node from the end of a linked list?**
    - **Two Pointer Method**: Move the first pointer `n` steps ahead, then move both pointers together until the first pointer reaches the end. The second pointer will be at the nth node from the end.

    ```cpp
    Node* findNthFromEnd(Node* head, int n) {
        Node* first = head;
        Node* second = head;
        for (int i = 0; i < n; ++i) {
            if (first == nullptr) return nullptr;
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        return second;
    }
    ```

13. **How do you delete a node given only access to that node in a linked list?**

    ```cpp
    void deleteNode(Node* node) {
        if (node->next != nullptr) {
            node->data = node->next->data;
            Node* temp = node->next;
            node->next = node->next->next;
            delete temp;
        }
    }
    ```

14. **How do you check if two linked lists intersect?**
    - Method 1: Use **hashing**.
    - Method 2: Compare the **last node** of both lists. If they are the same, the lists intersect.

    ```cpp
    Node* getIntersection(Node* headA, Node* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        Node* a = headA;
        Node* b = headB;
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        return a;
    }
    ```

15. **How do you find the starting point of the loop in a linked list?**
    - After detecting a loop with Floyd’s algorithm, reset one pointer to the head and move both pointers one step at a time until they meet.

    ```cpp
    Node* findLoopStart(Node* head) {
        Node* slow = head;
        Node* fast = head;
        bool hasCycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    ```

---

I'll continue with the remaining questions in the next part. Let me know if you want me to go step by step or skip specific sections!
