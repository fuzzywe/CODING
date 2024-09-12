#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;  // Should never reach here based on the problem statement
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 4};
    cout << "Duplicate element: " << findDuplicate(arr) << endl;
    return 0;
}
Time Complexity:

The time complexity is 

O(N 2) because for each element, we compare it with every other element.
Space Complexity:

The space complexity is 

O(1) because no extra space is used other than a few variables.
Optimal Solution:
The problem can be solved optimally using Floyd’s Tortoise and Hare (Cycle Detection) algorithm. 
  This approach is based on the fact that the array can be seen as a linked list where the value of 
each element points to the next index, and since there's one duplicate, a cycle exists.

Approach:

Use two pointers: a slow pointer and a fast pointer.
Move the slow pointer by 1 step and the fast pointer by 2 steps.
Once they meet, start another pointer at the beginning of the array and move both pointers
one step at a time. The point where they meet again is the duplicate number.
Code (Optimal in C++):

cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];
    
    // Phase 1: Detecting the cycle
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    
    // Phase 2: Finding the entrance to the cycle
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 4};
    cout << "Duplicate element: " << findDuplicate(arr) << endl;
    return 0;
}

For the array {1, 3, 4, 2, 2}, the duplicate value is 2.

Initial setup: slow = arr[0] = 1, fast = arr[0] = 1.
Cycle detection:
Step 1: slow = arr[1] = 3, fast = arr[arr[1]] = arr[3] = 2.
Step 2: slow = arr[3] = 2, fast = arr[arr[2]] = arr[4] = 2 (slow and fast pointers meet).
Finding duplicate:
Reset slow to arr[0] = 1 and move both pointers one step at a time.
Step 1: slow = arr[1] = 3, fast = arr[2] = 2.
Step 2: slow = arr[3] = 2, fast = arr[4] = 2 (both meet at 2, which is the duplicate).
Time Complexity:

The time complexity is 

O(N) because we move through the array in a linear fashion.

Space Complexity:

The space complexity is 

O(1) since we only use two extra pointers (slow and fast).

Brute Force:
Time Complexity: 
𝑂(𝑁2)

Space Complexity: 

O(1)
  
Optimal (Floyd’s Tortoise and Hare):
Time Complexity: 
O(N)
Space Complexity: 
O(1)
