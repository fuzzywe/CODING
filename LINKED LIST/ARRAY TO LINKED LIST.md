https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list


Create linked list from a given array
Last Updated : 01 Aug, 2024
Given an array arr[] of size N. The task is to create linked list from the given array.
Examples: 
 

Input : arr[] = {1,  2,  3,  4,  5}
Output : 1->2->3->4->5

Input :arr[] = {10,  11,  12,  13,  14}
Output : 10->11->12->13->14

Simple Approach: For each element of an array arr[] we create a node in a linked list and insert it at the end. 
 





//{ Driver Code Starts
// Initial Template for C++
```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

```
// } Driver Code Ends
// User function Template for C++
```cpp
class Solution {
  public:
    // Function to construct the linked list from a vector of integers
    Node* constructLL(vector<int>& arr) {
        // Initialize root as NULL
        Node* root = NULL;
        
        // Iterate over the array and add elements to the linked list
        for (int i = 0; i < arr.size(); i++) {
            root = insertEnd(root, arr[i]);
        }
        return root;
    }
    
    // Function to insert a node at the end of the list
    Node* insertEnd(Node* root, int item) {
        // Create a new node with the given data
        Node* temp = new Node(item);
        
        // If the list is empty, return the new node as the root
        if (root == NULL) {
            return temp;
        }
        
        // Traverse to the last node
        Node* last = root;
        while (last->next != NULL) {
            last = last->next;
        }
        
        // Link the new node at the end of the list
        last->next = temp;
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

```
Output
1 2 3 4 5
Time Complexity : O(n*n)
Efficient Approach: We traverse array from end and insert every element at the beginning of the list. 
 



```cpp

#include <iostream>
using namespace std;

// Representation of a node
struct Node {
    int data;
    Node* next;
    Node(int d){
       data = d;
       next = NULL;
    }
};

// Function to insert node
void insert(Node** root, int item)
{
    Node* temp = new Node(item);
    temp->next = *root;
    *root = temp;
}

void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}

Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = n-1; i >= 0 ; i--)
        insert(&root, arr[i]);
    return root;
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}
```
Output
1 2 3 4 5
Time Complexity : O(n)

Let's break down the code you provided, which converts an array to a singly linked list, inserts nodes at the end, and displays the list.

### Explanation of Each Line

```cpp
#include <iostream>
using namespace std;
```
- **`#include <iostream>`**: This is a preprocessor directive that includes the input/output stream library, which allows us to use `cout` for printing to the console.
- **`using namespace std;`**: This allows us to use the standard namespace (so we can write `cout` instead of `std::cout`).

### Structure Definition
```cpp
struct Node {
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
```
- **`struct Node`**: This defines a `Node` structure. Each node has two members:
  - `data`: Stores an integer value (the actual data).
  - `next`: A pointer to the next node in the list.
  
- **`Node(int d)`**: A constructor for the `Node` struct. It initializes the `data` with the value `d` passed as an argument and sets the `next` pointer to `NULL`.

### Function to Insert Node at the End
```cpp
Node* insertEnd(Node* root, int item)
{
    Node* temp = new Node(item);
    if (root == NULL)
        return temp;
  
    Node* last = root;
    while (last->next != NULL) {
        last = last->next;
    }
  
    last->next = temp;
    return root;
}
```
- **`Node* insertEnd(Node* root, int item)`**: This function inserts a new node with the value `item` at the end of the linked list. It takes two arguments:
  - `root`: The root node (head) of the linked list.
  - `item`: The value of the new node to be inserted.
  
- **`Node* temp = new Node(item);`**: Creates a new node `temp` with the data `item`.
  
- **`if (root == NULL) return temp;`**: If the list is empty (i.e., `root` is `NULL`), it directly returns the new node as the root of the list.

- **`Node* last = root;`**: Initializes a pointer `last` to traverse the list starting from `root`.

- **`while (last->next != NULL)`**: Traverses the list to find the last node (i.e., the node where `next` is `NULL`).

- **`last->next = temp;`**: Once the last node is found, the new node (`temp`) is linked to the end of the list.

- **`return root;`**: Returns the original `root` pointer of the list (updated with the new node at the end).

### Function to Convert Array to Linked List
```cpp
Node* arrayToList(int arr[], int n)
{
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEnd(root, arr[i]);
    }
    return root;
}
```
- **`Node* arrayToList(int arr[], int n)`**: This function converts an array into a linked list. It takes two arguments:
  - `arr[]`: The array of integers to be converted.
  - `n`: The size of the array.

- **`Node* root = NULL;`**: Initializes the `root` pointer to `NULL`, indicating an empty list.

- **`for (int i = 0; i < n; i++)`**: Iterates through each element of the array.

- **`root = insertEnd(root, arr[i]);`**: For each element `arr[i]`, it calls `insertEnd` to insert it at the end of the linked list. The updated `root` is saved back after each insertion.

- **`return root;`**: Returns the head of the newly created linked list.

### Function to Display the Linked List
```cpp
void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}
```
- **`void display(Node* root)`**: This function prints the linked list. It takes the root (head) of the list as an argument.

- **`while (root != NULL)`**: Iterates through each node in the linked list until it reaches the end (i.e., `NULL`).

- **`cout << root->data << " ";`**: Prints the `data` of the current node followed by a space.

- **`root = root->next;`**: Moves the pointer `root` to the next node in the list.

### Driver Code
```cpp
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}
```
- **`int arr[] = { 1, 2, 3, 4, 5 };`**: Initializes an array `arr` with elements `1, 2, 3, 4, 5`.

- **`int n = sizeof(arr) / sizeof(arr[0]);`**: Calculates the size of the array `n` using `sizeof`. `sizeof(arr)` gives the total size of the array in bytes, and `sizeof(arr[0])` gives the size of one element in bytes. Dividing these gives the number of elements in the array.

- **`Node* root = arrayToList(arr, n);`**: Calls the `arrayToList` function to convert the array into a linked list, with `root` as the head of the list.

- **`display(root);`**: Calls the `display` function to print the linked list.

- **`return 0;`**: Indicates that the program ended successfully.

---

### Dry Run

Let’s do a dry run for the array `{1, 2, 3, 4, 5}`.

1. **Initialize the array**: `arr = {1, 2, 3, 4, 5}`, `n = 5`.
2. **Convert array to linked list**:
   - `insertEnd(NULL, 1)` → Creates a new node with `data = 1`, returns it as the root.
   - `insertEnd(root, 2)` → Traverses the list, inserts `2` at the end.
   - `insertEnd(root, 3)` → Traverses the list, inserts `3` at the end.
   - `insertEnd(root, 4)` → Traverses the list, inserts `4` at the end.
   - `insertEnd(root, 5)` → Traverses the list, inserts `5` at the end.
   
   The linked list is now: `1 -> 2 -> 3 -> 4 -> 5 -> NULL`.

3. **Display the linked list**:
   - Start from `root` (which is `1`).
   - Print `1`, move to `2`.
   - Print `2`, move to `3`.
   - Print `3`, move to `4`.
   - Print `4`, move to `5`.
   - Print `5`, move to `NULL` (end of list).

Output: `1 2 3 4 5`. 

This successfully converts the array to a linked list and prints it.


