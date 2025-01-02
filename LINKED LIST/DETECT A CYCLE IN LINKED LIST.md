Detect a Cycle in a Linked List


Examples
Example 1:

Input Format:

LL: 1 2 3 4 5


Result: True

Explanation: The last node with the value of 5 has its 'next' pointer pointing back to a previous node with the value of 3. This has resulted in a loop, hence we return true.

Example 2:

Input Format:

LL: 1 2 3 4 9 9


Result: False

Explanation: : In this example, the linked list does not have a loop hence returns false.


```cpp

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;

        unordered_map<ListNode* ,int>mp;
        while(temp!=NULL){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }return false;
    }
};


```
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }

        }return false;
    }
};

```

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the linked list. This is because in the worst-case scenario, the fast pointer, which moves quicker, will either reach the end of the list (in case of no loop) or meet the slow pointer (in case of a loop) in a linear time relative to the length of the list.

The key insight into why this is O(N) and not something slower is that each step of the algorithm reduces the distance between the fast and slow pointers (when they are in the loop) by one. Therefore, the maximum number of steps needed for them to meet is proportional to the number of nodes in the list.


Space Complexity : O(1) The code uses only a constantamount of additionalspace, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constantspace complexity, O(1).


  THE MISTAKE I DID ON CODE PLATFORM:
```cpp
ListNode* temp = head;

        unordered_map<int,int>mp;
        while(temp!=NULL){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }return false;
    }

Line 16: Char 19: error: no matching member function for call to 'find'
   16 |             if(mp.find(temp) != mp.end()){
      |                ~~~^~~~
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/unordered_map.h:875:7: note: candidate function not viable: no known conversion from 'ListNode *' to 'const key_type' (aka 'const int') for 1st argument
  870 |       find(const key_type& __x)
      |       ^    ~~~~~~~~~~~~~~~~~~~
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/unordered_map.h:886:7: note: candidate function not viable: no known conversion from 'ListNode *' to 'const key_type' (aka 'const int') for 1st argument
```

CORRECT ANSWER:
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;

        unordered_map<ListNode* ,int>mp;
        while(temp!=NULL){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }return false;
    }
};


DRY RUN 
bool detectLoop(Node* head) {
    Node* temp = head;  // Step 1: Initialize a pointer 'temp' at the head
    std::unordered_map<Node*, int> nodeMap;  // Step 2: Create a map to store visited nodes

    while (temp != nullptr) {  // Step 3: Traverse the linked list
        if (nodeMap.find(temp) != nodeMap.end()) {  // Step 4: Check if 'temp' is already in the map
            return true;  // If found, a loop is detected
        }
        nodeMap[temp] = 1;  // Step 5: Otherwise, store the current node in the map
        temp = temp->next;  // Move to the next node
    }
    
    return false;  // If the loop finishes without finding a loop, return false
}
```
Linked List Structure:
We are given a linked list with the following structure:

rust
Copy code
1 -> 2 -> 3 -> 4 -> 5 -> (points back to node 3)
This creates a loop between nodes 5 and 3.

Dry Run:
Initialization:

temp initially points to head, which is node 1.
nodeMap is an empty map.
First Iteration (temp = Node 1):

The while loop begins: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) does not find node 1 in the map.
So, we add node 1 to the map: nodeMap[Node(1)] = 1.
Move temp to the next node: temp = temp->next, which now points to node 2.
Second Iteration (temp = Node 2):

The while loop continues: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) does not find node 2 in the map.
So, we add node 2 to the map: nodeMap[Node(2)] = 1.
Move temp to the next node: temp = temp->next, which now points to node 3.
Third Iteration (temp = Node 3):

The while loop continues: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) does not find node 3 in the map.
So, we add node 3 to the map: nodeMap[Node(3)] = 1.
Move temp to the next node: temp = temp->next, which now points to node 4.
Fourth Iteration (temp = Node 4):

The while loop continues: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) does not find node 4 in the map.
So, we add node 4 to the map: nodeMap[Node(4)] = 1.
Move temp to the next node: temp = temp->next, which now points to node 5.
Fifth Iteration (temp = Node 5):

The while loop continues: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) does not find node 5 in the map.
So, we add node 5 to the map: nodeMap[Node(5)] = 1.
Move temp to the next node: temp = temp->next, which now points back to node 3 due to the loop.
Sixth Iteration (temp = Node 3 again):

The while loop continues: temp is not nullptr.
The map nodeMap is checked: nodeMap.find(temp) finds node 3 already present in the map, meaning the current node has been visited before. This indicates a loop.
The function returns true, indicating that a loop has been detected.
Conclusion:
The dry run shows that once the temp pointer revisits a node (node 3 in this case), the function identifies the loop by checking the presence of the node in the unordered_map. The loop is successfully detected, and the function returns true.

In summary:

The function successfully detects the loop in the list after the pointer revisits node 3, which has been previously added to the map during traversal.
