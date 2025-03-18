https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1

```cpp


class Solution{
public:
  long long unsigned int decimalValue(Node *head)
{
        string num;
        
        // Convert the linked list to a string
        while (head != NULL) {
            num += to_string(head->data);
            head = head->next;
        }
        
        int res = 0, pv = 1;
        
        // Traverse the string in reverse, multiplying each bit by increasing powers of 2
        for (int i = num.size() - 1; i >= 0; i--) {
            res += pv * (stoi(num.substr(i, 1)));
            pv = (pv * 2) % 1000000007; // Update power of 2 modulo 10^9+7
            res %= 1000000007; // Update result modulo 10^9+7
        }
        
        return res;
    
}
};


```


Complexity
Time Complexity:

Traversing Linked List and Building String: O(n)
Traversing Binary String in Reverse: O(n)
Space Complexity:

StringBuilder for Binary String: O(n)
Additional Integer Variables: O(1)



---

expected

Complexity
Time Complexity :O(n) 

Space Complexity :O(1)


```cpp
class Solution {
  public:
    // Function to calculate the decimal value of a linked list
    long long unsigned int decimalValue(struct Node *head) {
        // Initialize result variable
        long long unsigned int res = 0;

        // Traverse the linked list
        while (head != NULL) {
            // Calculate the decimal value by multiplying the result by 2 and adding
            // current node's data Also, use modular division to ensure the result
            // doesn't exceed the maximum value
            res = ((res * 2) % MOD + head->data) % MOD;

            // Move to the next node
            head = head->next;
        }

        // Return the final decimal value
        return res;
    }
};


```
