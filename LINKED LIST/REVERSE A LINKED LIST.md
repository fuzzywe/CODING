
https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897

https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

https://leetcode.com/problems/reverse-linked-list/


https://www.codechef.com/practice/course/interview-dsa/DSAPREP_08/problems/RTLL

Reverse a Linked List

Input Format:

LL: 1   3   2   4 


Output: 3


Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.

Example 2:

Input Format:

LL: 4


Output: 4


Explanation: In this example, the linked list contains only one node hence reversing this linked list will result in the same list as the original.


brute force 

Your approach to **reversing a linked list** using a **stack** is a valid one, though it's not the most optimal in terms of space complexity. Let’s break it down step by step so you can explain it impressively in an interview.

---

### 🔹 **Understanding the Problem**  
You are given a **singly linked list**, and the goal is to reverse it.  

**Example:**  
```
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1
```

🔹 **Approach Used**: **Stack (LIFO - Last In, First Out)**
- A stack follows **Last In, First Out (LIFO)** order.  
- We first push all the values from the linked list into the stack.
- Then, we **pop** values from the stack and reassign them to the linked list nodes, effectively reversing the list.

---

## 🔹 **Step-by-Step Explanation**
### **Step 1: Create a Temporary Pointer**
```cpp
ListNode* temp = head;
```
- We create a pointer `temp` and set it to `head`.  
- This pointer will be used to traverse the linked list.

### **Step 2: Create a Stack to Store Values**
```cpp
stack<int> st;
```
- We initialize an empty **stack** (`st`) to store the values of the linked list.

### **Step 3: Traverse the Linked List and Push Values into Stack**
```cpp
while (temp != nullptr) {
    st.push(temp->val);  
    temp = temp->next;    
}
```
- We iterate through the linked list.
- For each node, we push its `val` into the stack.
- **Example Execution for List [1 → 2 → 3 → 4 → 5]:**
  - Push `1`, stack = `[1]`
  - Push `2`, stack = `[1, 2]`
  - Push `3`, stack = `[1, 2, 3]`
  - Push `4`, stack = `[1, 2, 3, 4]`
  - Push `5`, stack = `[1, 2, 3, 4, 5]`
- At the end of this loop, the stack holds values in **reverse order**.

### **Step 4: Reset temp to Head**
```cpp
temp = head;
```
- We reset `temp` to `head` so we can traverse the linked list again.

### **Step 5: Pop Values from Stack and Reassign to Nodes**
```cpp
while (temp != nullptr) {
    temp->val = st.top();  
    st.pop();              
    temp = temp->next;     
}
```
- Now, we iterate through the linked list **again**.
- For each node, we:
  1. Assign `temp->val = st.top()` (retrieve top value from stack).
  2. `st.pop()` (remove the top value).
  3. Move `temp` to the next node.
- **Example Execution (Rewriting Values):**
  - `temp->val = 5`, stack becomes `[1, 2, 3, 4]`
  - `temp->val = 4`, stack becomes `[1, 2, 3]`
  - `temp->val = 3`, stack becomes `[1, 2]`
  - `temp->val = 2`, stack becomes `[1]`
  - `temp->val = 1`, stack becomes `[]`
- Now, the list is reversed.

### **Step 6: Return the Reversed Linked List**
```cpp
return head;
```
- We return the head of the modified linked list.

---

## 🔹 **Complexity Analysis**
- **Time Complexity:**  
  - `O(N)`: Traversing the linked list takes `O(N)`.  
  - `O(N)`: Reassigning values takes `O(N)`.  
  - Total: **O(N) + O(N) = O(N)**.
  
- **Space Complexity:**  
  - **O(N)** (Because of the extra stack storing `N` values).

---

## 🔹 **Alternative Optimized Approach (In-Place Reversal)**
Instead of using a **stack**, we can reverse the list **in-place** using **three pointers**:  
- `prev`: Tracks the previous node  
- `curr`: Tracks the current node  
- `next`: Stores the next node temporarily  



---

## 🔹 **How to Impress in an Interview**
### **🔹 If Asked Why You Used a Stack:**
- **Explain the intuition:**  
  "A stack follows **LIFO (Last In, First Out)**, which naturally helps in reversing the order of elements."
- **Justify your choice:**  
  "By using a stack, we can retrieve values in reversed order without modifying the original structure until reassignment."

### **🔹 If Asked About Space Complexity:**
- "This approach uses **O(N) extra space** because the stack stores all the node values."
- "A more efficient approach would be **reversing the pointers in place**, reducing space to **O(1)**."

### **🔹 If Asked About Edge Cases:**
- **Empty List (`head == nullptr`)** → Returns `nullptr` (Handled automatically).  
- **Single Node (`1 -> nullptr`)** → Remains unchanged.  
- **Already Reversed List (`5 -> 4 -> 3 -> 2 -> 1`)** → Still works correctly.  

---

## 🔹 **Final Takeaway**
🔹 The **stack approach** is intuitive and simple but uses **extra space**.  
🔹 **In-place reversal using pointers** is the **best approach** for efficiency.  
🔹 Be ready to **explain time/space complexity** and **compare different solutions**.  

This explanation will help you **impress interviewers** with your deep understanding! 🚀💡
---


```cpp

    class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== NULL || head->next == NULL) return head;
        ListNode* temp= reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return temp;
    }
};


```

---

```cpp

    class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr; // Previous node starts as NULL
        ListNode* next = nullptr; // Next node
        ListNode* curr = head;    // Current node starts at the head

        // Traverse the list
        while (curr != nullptr) {
            // Save the next node
            next = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move pointers forward
            prev = curr; // Move prev to the current node
            curr = next; // Move curr to the next node
        }

        // prev is now the new head of the reversed list
        return prev;
    }
};


```

Complexity
Time complexity:
The time complexity of this solution is O(n), because we reversed the linked list in a single pass, where 𝑛 n is the number of nodes in a linked list.

Space complexity:
The space complexity of this solution is O(1), because no extra memory is used.

---


![image](https://github.com/user-attachments/assets/2ae2c30b-c824-428b-8fe5-0a1f33d67a08)


![image](https://github.com/user-attachments/assets/faf609d5-f7e0-46a0-b3f2-c2c796a486eb)

![image](https://github.com/user-attachments/assets/18f43682-bcad-4ab6-8012-5893a5f3342d)

![image](https://github.com/user-attachments/assets/70583232-6344-4e39-8482-0ef15102049b)

![image](https://github.com/user-attachments/assets/7983695f-21c0-4a24-9750-b4a9f17c9908)


![image](https://github.com/user-attachments/assets/773f86c6-f46b-4150-b37e-9d0fa0b5477c)

![image](https://github.com/user-attachments/assets/a26060ef-ed2a-464d-bc62-2e4027121a82)


![image](https://github.com/user-attachments/assets/e8610794-6f88-46f9-b59b-af573a4c1c7c)


![image](https://github.com/user-attachments/assets/493d356d-36fc-4482-b00b-8bdaf142f57e)

![image](https://github.com/user-attachments/assets/e4e142b6-3f88-41be-aa8d-b6a13d0f838c)


![image](https://github.com/user-attachments/assets/ca77bdf3-3f0b-4622-a896-fbf28a1a38ac)






