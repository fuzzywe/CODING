Delete Last Node of Linked List


https://leetcode.com/problems/delete-node-in-a-linked-list/description/?source=submission-ac



Examples
Example 1:

Examples:

Input Format: 0->1->2

Result: 0->1


Explanation: The tail of the list is the last node. After removing the tail, and updating the linked list, this result is what we get.

Example 2:

Input Format: 12->5->8->7

Result: 12->5->8

Explanation: Again, after deleting the tail and updating the linked list, the list ends at the second last node, which is the new tail.

Solution
```cpp

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

```
Disclaimer: Don't jump directly to the solution, try it out yourself first.

```cpp

The given code snippet is modifying a **linked list** by manipulating the values and pointers of the nodes. Here's a detailed breakdown:


node->val = node->next->val;
node->next = node->next->next;
```

### Context
- `node` is assumed to be a pointer to a node in a **singly linked list**.
- A linked list consists of nodes, each containing a value (`val`) and a pointer (`next`) to the next node.

### Explanation
1. **`node->val = node->next->val;`**
   - The value of the current node (`node`) is replaced with the value of the next node (`node->next`).
   - Essentially, the value stored in the next node is "copied" to the current node.

2. **`node->next = node->next->next;`**
   - The `next` pointer of the current node is updated to point to the node after the next node (`node->next->next`).
   - This effectively "skips" the next node, unlinking it from the list.

### Purpose
This snippet is often used to **delete a node** from a singly linked list **without having access to the previous node**. Instead of actually deleting the current node, the contents of the next node are copied to the current node, and the next node is skipped.

### Example
Consider the linked list:  
**10 → 20 → 30 → 40**

- Assume `node` points to the node with value `20`.
- After executing the code:
  1. `node->val = node->next->val;`  
     The value of `node` becomes `30`. The list temporarily looks like this:  
     **10 → 30 → 30 → 40**
  2. `node->next = node->next->next;`  
     The `next` pointer of `node` is updated to skip the next node. The updated list looks like this:  
     **10 → 30 → 40**

Now, the node with value `20` is effectively removed from the linked list.


