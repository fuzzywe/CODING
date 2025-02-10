
https://www.naukri.com/code360/problems/delete-node-in-a-linked-list_1105578?interviewBundleRedirection=true&leftPanelTabValue=PROBLEM

https://leetcode.com/problems/delete-node-in-a-linked-list/


---

```cpp


void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
     node->data = node->next->data;

    node->next = node->next->next;
}
```
