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
Certainly! Continuing with the remaining linked list interview questions:

### **Advanced Questions:**

16. **Explain the concept of a doubly linked list and provide C++ code to implement it.**
    - **Doubly Linked List**: Each node has two pointers: one pointing to the next node and one to the previous node. This allows traversal in both directions.

    ```cpp
    struct DoublyNode {
        int data;
        DoublyNode* next;
        DoublyNode* prev;
    };

    void insertAtBeginning(DoublyNode*& head, int data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(DoublyNode*& head, int data) {
        DoublyNode* newNode = new DoublyNode();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void traverseForward(DoublyNode* head) {
        DoublyNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void traverseBackward(DoublyNode* head) {
        if (head == nullptr) return;
        DoublyNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    ```

17. **What is a circular linked list? How does it differ from a normal linked list?**
    - **Circular Linked List**: The last node points back to the first node, forming a circle.
    - **Differences**:
      - **Normal Linked List**: Ends with a `nullptr`.
      - **Circular Linked List**: Ends with a pointer to an earlier node, creating a loop.

18. **Implement a circular linked list and demonstrate insertion and traversal.**

    ```cpp
    struct CircularNode {
        int data;
        CircularNode* next;
    };

    void insertAtEnd(CircularNode*& head, int data) {
        CircularNode* newNode = new CircularNode();
        newNode->data = data;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CircularNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void traverseList(CircularNode* head) {
        if (head == nullptr) return;
        CircularNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    ```

19. **How would you find the length of a circular linked list?**

    ```cpp
    int getLength(CircularNode* head) {
        if (head == nullptr) return 0;
        int length = 0;
        CircularNode* temp = head;
        do {
            length++;
            temp = temp->next;
        } while (temp != head);
        return length;
    }
    ```

20. **Explain the difference between a linked list and a stack/queue.**

    - **Linked List**: Linear data structure where each element points to the next.
    - **Stack**: Follows LIFO (Last In First Out) principle. Implemented using linked lists or arrays.
    - **Queue**: Follows FIFO (First In First Out) principle. Implemented using linked lists or arrays.

21. **How do you implement a stack using a linked list?**

    ```cpp
    struct StackNode {
        int data;
        StackNode* next;
    };

    class Stack {
    private:
        StackNode* top;
    public:
        Stack() : top(nullptr) {}

        void push(int data) {
            StackNode* newNode = new StackNode();
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top != nullptr) {
                StackNode* temp = top;
                top = top->next;
                delete temp;
            }
        }

        int peek() {
            if (top != nullptr) return top->data;
            throw runtime_error("Stack is empty");
        }

        bool isEmpty() {
            return top == nullptr;
        }
    };
    ```

22. **How do you implement a queue using a linked list?**

    ```cpp
    struct QueueNode {
        int data;
        QueueNode* next;
    };

    class Queue {
    private:
        QueueNode* front;
        QueueNode* rear;
    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void enqueue(int data) {
            QueueNode* newNode = new QueueNode();
            newNode->data = data;
            newNode->next = nullptr;
            if (rear != nullptr) {
                rear->next = newNode;
            }
            rear = newNode;
            if (front == nullptr) {
                front = rear;
            }
        }

        void dequeue() {
            if (front != nullptr) {
                QueueNode* temp = front;
                front = front->next;
                if (front == nullptr) {
                    rear = nullptr;
                }
                delete temp;
            }
        }

        int peek() {
            if (front != nullptr) return front->data;
            throw runtime_error("Queue is empty");
        }

        bool isEmpty() {
            return front == nullptr;
        }
    };
    ```

23. **What is the use of a sentinel node in a linked list?**
    - **Sentinel Node**: A dummy node used to simplify edge cases, such as inserting or deleting nodes at the beginning or end of the list. It can prevent the need for special cases in algorithms.

24. **How would you split a linked list into two halves?**

    ```cpp
    void splitList(Node* head, Node*& firstHalf, Node*& secondHalf) {
        if (head == nullptr || head->next == nullptr) {
            firstHalf = head;
            secondHalf = nullptr;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        firstHalf = head;
        secondHalf = slow->next;
        slow->next = nullptr;
    }
    ```

25. **How do you remove duplicates from a linked list?**

    - **Using a Hash Set**:

      ```cpp
      void removeDuplicates(Node*& head) {
          unordered_set<int> seen;
          Node* current = head;
          Node* prev = nullptr;
          while (current != nullptr) {
              if (seen.find(current->data) != seen.end()) {
                  prev->next = current->next;
                  delete current;
              } else {
                  seen.insert(current->data);
                  prev = current;
              }
              current = prev->next;
          }
      }
      ```

26. **How would you rotate a linked list to the right by `k` places?**

    ```cpp
    void rotateRight(Node*& head, int k) {
        if (head == nullptr || k == 0) return;

        Node* oldTail = head;
        int length = 1;

        while (oldTail->next != nullptr) {
            oldTail = oldTail->next;
            length++;
        }

        k = k % length;
        if (k == 0) return;

        Node* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        oldTail->next = head;
        head = newHead;
    }
    ```

27. **How do you check if a linked list is a palindrome?**

    ```cpp
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (head == nullptr || head->next == nullptr) return true;

        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverseList(slow);
        Node* firstHalf = head;

        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) return false;
            firstHalf = firstHalf->next;
            second

Half = secondHalf->next;
        }

        return true;
    }
    ```

28. **How would you merge k sorted linked lists?**

    ```cpp
    class Compare {
    public:
        bool operator()(Node* l1, Node* l2) {
            return l1->data > l2->data;
        }
    };

    Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        for (Node* list : lists) {
            if (list != nullptr) minHeap.push(list);
        }

        Node* dummy = new Node();
        Node* tail = dummy;

        while (!minHeap.empty()) {
            Node* minNode = minHeap.top();
            minHeap.pop();
            tail->next = minNode;
            tail = tail->next;
            if (minNode->next != nullptr) minHeap.push(minNode->next);
        }

        return dummy->next;
    }
    ```

29. **How do you find the intersection point of two linked lists?**

    ```cpp
    Node* getIntersectionNode(Node* headA, Node* headB) {
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

30. **How would you flatten a multi-level linked list?**

    ```cpp
    struct MultiLevelNode {
        int data;
        MultiLevelNode* next;
        MultiLevelNode* child;
    };

    MultiLevelNode* mergeTwoLists(MultiLevelNode* l1, MultiLevelNode* l2) {
        MultiLevelNode dummy;
        MultiLevelNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }

    MultiLevelNode* flatten(MultiLevelNode* head) {
        if (head == nullptr) return nullptr;

        MultiLevelNode dummy;
        MultiLevelNode* tail = &dummy;
        MultiLevelNode* current = head;

        while (current != nullptr) {
            tail->next = current;
            tail = tail->next;

            MultiLevelNode* child = current->child;
            current->child = nullptr;
            if (child != nullptr) {
                MultiLevelNode* next = current->next;
                tail->next = flatten(child);
                while (tail->next != nullptr) tail = tail->next;
                current->next = next;
            }

            current = current->next;
        }

        return dummy.next;
    }
    ```

