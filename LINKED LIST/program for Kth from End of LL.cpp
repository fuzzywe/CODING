Kth from End of Linked List
Difficulty: EasyAccuracy: 41.18%Submissions: 393K+Points: 2
Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Example:
Linked List: 1->2->3->4->5, k=3

count= 5
the third node from the last will be (5-3) from the beginning that is the 2nd node from the start hence,
target= 2
return 3

Code:


class Solution{  
public:
  int getKthFromLast(struct Node* head, int k)
  {
      // Your code here
      if (head == NULL)
          return -1;
      int count = 0;
      Node* temp = head;
      while (temp != NULL) {
          count++;
          temp = temp->next;
      }
      if (k > count)
          return -1;
      temp = head;
      while (temp != NULL && count != k) {
          temp = temp->next;
          count--;
      }
      return (temp->data);
  }
};
Complexity:
Time Complexity: O(n), we just have to make a traversal for the complete list.
Space Complexity: O(1), no extra space needed. 

Expected Approach
Intuition
Using two pointers:- As kth node from the end equals to (Length - k + 1)th node from the start, Now rather than finding the exact position of the desired node beforehand from the head, we can make two pointers traverse simultaneously, the first pointer (ref_pointer) will start from the kth node from the beginning, and a pointer main_ptr  that starts from the beginning, so the ref_ptr at last would make (Length - k + 1)th traversals (which is the position of required node from the head) , and so the main_ptr. The main_ptr now contains the target node so we can now return the value of the same.  

Implementation
Run a loop and move a ref pointer till kth Node .
Now start a pointer from first Node and name it as curr/main_ptr pointer.
Run a loop moving both main_ptr pointer and ref pointer until ref pointer reaches last node. 
When the ref pointer will reach the last node, the main pointer will point to the (length of linked list- k+1) postion which is the position of nth node from last but from the head of the linked list.
Now return the data of the node of the main_ptr pointer.
The below carousal is a dry run of the above approach:

1.png1.png


Complexity
Time Complexity: O(n) where n is the length of the linked list.
Space Complexity: O(1), As no any extra space is used. 



// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {

        // using two pointers, similar to finding middle element.
        Node *currNode = head, *kthNode = head;

        // traversing first k elements with first pointer.
        while (k != 0) {
            if (currNode == NULL)
                return -1;
            currNode = currNode->next;
            k--;
        }

        // now traversing with both pointers and when first pointer gives null
        // we have got the kth node from end in second pointer since the first
        // pointer had already traversed n nodes and thus had difference of n
        // nodes with second pointer.
        while (currNode != NULL) {
            kthNode = kthNode->next;
            currNode = currNode->next;
        }

        // returning the data of nth node from end.
        if (kthNode != NULL)
            return kthNode->data;
        else
            return -1;
    }
};
