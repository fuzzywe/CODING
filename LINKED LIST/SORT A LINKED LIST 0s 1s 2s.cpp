Sort a linked list of 0s, 1s and 2s
Difficulty: EasyAccuracy: 60.75%Submissions: 199K+Points: 2
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).


  Expected Approach
Intuition
We can sort the linked list by traversing it once and dividing it into three separate lists. Then, these three lists are in the order 0s, 1s, and 2s, resulting in a sorted linked list without modifying the data in the nodes themselves.

1-(9)
Implementation
Create three dummy nodes as list0, list1 and list2 to point to beginning of three linked lists and keep their heads stored in seperate variable as we would need them while linking these linked list.
Create current pointer curr and assign it to the head of given linked list as (Node* curr = head).
Traverse over the  given linked list with a curr pointer. 
Check data at current node and store the node in it's respective list and update the link part of that list. i.e. if current node is 0 then store it into list0 and update the link of list0 as list0=list0->next.
Attach the three lists containing 0s,1s and 2s respectively using their head.
Update the head of the list to the head of list0's head.
Return head.
Complexity
Time Complexity: O(n), since we have to traverse the complete list for once, where n is the number of nodes in the linked list
Space Complexity: O(1), it uses a constant amount of additional memory.



class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(struct Node* head) {
        if (!head || !(head->next))
            return head;

        // creating three dummy nodes to point to beginning of three linked lists.
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);

        // initializing current pointers for three lists.
        Node *zero = zeroD, *one = oneD, *two = twoD;

        // traversing over the list with a pointer.
        Node* curr = head;
        while (curr) {

            // we check data at current node and store the node in it's respective
            // list and update the link part of that list.
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
                curr = curr->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
                curr = curr->next;
            } else {
                two->next = curr;
                two = two->next;
                curr = curr->next;
            }
        }

        // attaching the three lists containing 0s,1s and 2s respectively.
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;

        // updating the head of the list.
        head = zeroD->next;

        // deleting dummy nodes.
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};
Alternate Approach
Intuition
The Idea is to first traverse the linked list and count total number of zeros, ones and twos, then once again traverse the linked list  and while doing so replace the node values to the first total number of zeros, ones and twos respectively.

Implementation
Initialize an array count[3] of size 3 to store the count of number of zero's, one's and two's.
Now traverse the linked list and count total number of '0', '1' and '2'
Let say count[0] = n1, count[1] = n2 and count[2] = n3 then traverse the linked list again and,
Fill the first n1 nodes with 0's, next n2 nodes with 1's and rest of the nodes with 2's.
Returnt the head of linked list.
Example
For linked list: 1-> 0-> 2-> 0


Code


/*
Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        int count[3] = {0, 0, 0}; 
        Node *ptr = head;
        
        while (ptr != NULL)
        {
        	count[ptr->data] += 1;
        	ptr = ptr->next;
        }
 
        int i = 0;
        ptr = head;
        while (ptr != NULL)
        {
            if (count[i] == 0)
            	++i;
            else
            {
                ptr->data = i;
                --count[i];
                ptr = ptr->next;
            }
        }
        return head;
    }
};
Complexity
Time Complexity: O(n), to traverse the linked list, where n is the number of nodes in the linked list. 
Space Complexity: O(1), as constant extra space is needed to store the count.

Useful links to help you understand the concepts of this problem:
