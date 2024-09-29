Reverse Linked List in groups of Size K



Problem Statement: Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5  6  7  8  9  10
K = 3


Output: 3  2  1  6  5  4  9  8  7  10


Explanation:

Group 1: Reverse nodes 1 -> 2 -> 3 to become 3 -> 2 -> 1.
Group 2: Reverse nodes 4 -> 5 -> 6 to become 6 -> 5 -> 4.
Group 3: Reverse nodes 7 -> 8 -> 9 to become 9 -> 8 -> 7.
Node 10 remains as is since there are no more groups of size K remaining.
Example 2:

Input Format:

LL: 5  4  3  7  9  2

K = 4


Output: 7 3 4 5 9 2



class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        if(head==NULL || k == 1){
            return head;
        }
        int count = 0;
        struct node* curr = head;
        struct node* prev = NULL;
        struct node* next = NULL;
        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL){
            head->next = reverseIt(next,k);
            
        }
        return prev;
    }
};



//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        if(head==NULL || k == 1){
            return head;
        }
        int count = 0;
        struct node* curr = head;
        struct node* prev = NULL;
        struct node* next = NULL;
        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL){
            head->next = reverseIt(next,k);
            
        }
        return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends
