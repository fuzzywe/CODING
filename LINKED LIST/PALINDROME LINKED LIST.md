
https://leetcode.com/problems/palindrome-linked-list/solutions/4908031/interview-approach-4-approach-list-stack-recursion-two-pointer-approach/?envType=problem-list-v2&envId=22bl6amv

---

First push all data in stack, and then traverse linked list and keep popping element from stack one by one, so stack will give you element from last.


```cpp

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;
    }
};

```

---


The main idea to check palindrome is , if the first and last elements are same or not and then check for second and second last.

So I am thinking what if I create new linked list which would be reversed of the original linked list.

And then I can compare each element one by one.
But do I need the whole linked list to reverse and compare ?

No, I just need the second half of linked list to be reversed.

Now the question is how can I get the second half ?
There are two approach

    Count all nodes first and then move to n/2th node, this would be middle node.
    Use two pointer one will move with the speed of 1 and one with the speed of 2, so when the fast pointer reaches the end, slow pointer would be at mid.

After getting middle node, reverse the list after that node.
and then compare each element.
Code
```cpp
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        while (rev != nullptr) {
            if (head->val != rev->val) {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};

```
