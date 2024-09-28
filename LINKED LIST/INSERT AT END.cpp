Insert at the head of a Linked List

https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

Examples
Example 1:

Input Format: 0->1->2, val = 5

Result: 5->0->1->2


Explanation: We need to insert the value 5 before the head of the given Linked List.

Example 2:

Input Format:12->5->8->7, val = 100

Result: 100->12->5->8->7

Explanation: Again, we need to insert the value 100 before the head of the Linked List.

Solution
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Approach:
To insert a new node with a value before the head of the list, create a new node with the given value val pointing to the head. This node will be the new head of the linked list.

Algorithm:
Create a new node with data as the given value and pointing to the head. This node will be our new head of the linked list.

Now, return the new node as the head of the updated Linked List.

Code:

C++
Java
Python
class Node {
public:
    int data;
    Node* next;

    // Constructor with both data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data (assuming next is initially null)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to insert a new node at the head of the linked list
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

int main() {
    // Sample array and value for insertion
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertHead(head, val);

    // Printing the linked list
    printLL(head);

    return 0;
}
Output:

100 12 8 5 7

Time Complexity: O(1) for inserting the new head of the linked list and O(N) for printing the linked list.

Space Complexity: O(1), as we have not used any extra space.



    THE MISTAKE I DID IN THE CODE PLATFORM:


class Solution {
  public:
  int data;
        Node* next;
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
        void printList(Node* head){
            while(head != NULL){
                cout<<head->data<<" ";
                head =head->next;
            }
        }
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp = new Node(x,head);
        return temp;
    }
}; I HAVE DECLARED CONSTRUCTOR WITH OTHER NAME NOT WITH THE CLASS NAME WHICH IS SOLUTION.


    //{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Create a new node with data 'x'
        Node* temp = new Node(x);

        // If the linked list is empty, the new node is the head
        if (head == NULL) {
            return temp;
        }

        // Traverse to the end of the linked list
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Link the new node at the end
        current->next = temp;

        // Return the head of the updated list
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* ans = ob.insertAtEnd(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends

THE MISTAKE I DID:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
struct Node{
int data;
        struct Node* next;
        
        Node(int data1){
            data = data1;
            next = NULL;
        }};
        
        void printList(Node* head){
            while(head != NULL){
                cout<<head->data<<" ";
                head =head->next;
            }
        }

class Solution {
  public:
  
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp = new Node(x);
        if (head==NULL){
        return temp;}
        Node* last = head;
        while(last->next != NULL){
            last =last ->next;
        }
        last->next = temp;
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* ans = ob.insertAtEnd(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends./Solution.cpp:35:8: error: redefinition of 'struct Node'
 struct Node{
        ^
./Solution.cpp:6:8: error: previous definition of 'struct Node'
 struct Node {
        ^
./Solution.cpp: In function 'void printList(Node*)':
./Solution.cpp:44:14: error: redefinition of 'void printList(Node*)'
         void printList(Node* head){
              ^
./Solution.cpp:16:6: note: 'void printList(Node*)' previously defined here
 void printList(Node* node) {
      ^

Expected Output: 


THE SOLUTION:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
     
        
class Solution {
  public:
  
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp = new Node(x);
        if (head==NULL){
        return temp;}
        Node* last = head;
        while(last->next != NULL){
            last =last ->next;
        }
        last->next = temp;
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* ans = ob.insertAtEnd(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends
