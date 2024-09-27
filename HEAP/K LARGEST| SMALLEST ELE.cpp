Kth largest/smallest element in an array



Examples:

Example 1:
Input: Array = [1,2,6,4,5,3] , K = 3 
Output: kth largest element = 4, kth smallest element = 3

Example 2:
Input: Array = [1,2,6,4,5] , k = 3
Output : kth largest element = 4,  kth smallest element = 4

Solution 1: Sorting the Array
The most naive approach is to sort the given array in descending order.
The index of kth Largest element = k-1 ( zero-based indexing ) 
The index of kth Smallest element = n-k 
The array can also be sorted in ascending order.
The index of kth Largest element = n-k 
The index of kth Smallest element = k-1 ( zero based indexing )




#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

void kth_Largest_And_Smallest_By_AscendingOrder(vector<int>&arr, int k) {

        sort(arr.begin(), arr.end())  ;
        int n = arr.size()  ;

        cout << "kth Largest element " << arr[n - k] << ", " << 
        "kth Smallest element " << arr[k - 1];
    }
} ;
int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    
    obj.kth_Largest_And_Smallest_By_AscendingOrder(arr, 3) ;

    return 0 ;
}
Output: kth Largest element 4, kth Smallest element 3

Time complexity: O(nlogn)

Space complexity: O(1)

  Solution 2: Using Heap
The idea is to construct a max-heap of elements. Since the top element of the max heap is the largest element of the heap, we will remove the top K-1 elements from the heap.  The top element will be Kth's Largest element.
To get the Kth Smallest element, we will use a min-heap. After the removal of the top k-1 elements, the Kth Smallest element is top of the Priority queue.
Let the array be
[17,7,2,30,21] and k = 3




Similarly, for the smallest kth element we will be using Min-Heap. After, extracting the top k-1 values will be having Kth Smallest element.

Code:

C++
Java
Python
#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

    void kth_Largest_MaxHeap(vector<int>&arr, int k) {

        priority_queue<int>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Largest element " << pq.top() << "\n"  ;
    }

    void kth_Smallest_MinHeap(vector<int>&arr, int k) {

        priority_queue<int, vector<int>, greater<int>>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Smallest element " << pq.top() << "\n"  ;
    }
} ;
int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    obj.kth_Largest_MaxHeap(arr, 3)  ;
    obj.kth_Smallest_MinHeap(arr, 3)  ;

    return 0 ;
}
Output:

Kth Largest element 4
Kth Smallest element 3

Time complexity: O(k+(n-k)*log(k))  , n = size of array

Space complexity: O(k)




  priority_queue<int>:

This is a standard priority queue in C++. By default, the priority queue is a Max Heap. It means the largest element has the highest priority, and the elements are arranged in descending order. The top of the heap (pq.top()) is the largest element.
vector<int>:

This specifies the underlying data structure used by the priority queue, which is a vector of integers (int).
vector<int> is the default container for storing elements in the priority queue. It can also use other containers like deque, but vector is most common.
greater<int>:

This is a comparator function. It tells the priority queue to prioritize elements in ascending order, which makes the queue behave like a Min Heap.
By default, priority queues use less<int>, meaning they behave like a Max Heap (with larger elements on top). When we specify greater<int>, it reverses the ordering to create a Min Heap (with smaller elements on top).
Purpose:
The purpose of using greater<int> in this context is to find the kth smallest element. A Min Heap always keeps the smallest element at the top. So, by using this Min Heap, we can efficiently find the smallest elements.

Simplified View:
The line priority_queue<int, vector<int>, greater<int>> pq; essentially does this:

It creates a Min Heap where:
Elements are stored in a vector<int>.
The smallest element will always be on the top (accessible by pq.top()).
Example for Clarity:
Imagine you insert the following numbers into the priority queue: 5, 2, 8, 1.

For a Min Heap (which this line creates), the heap will always arrange itself like this:

yaml
Copy code
Step 1: Insert 5 -> Heap: {5}
Step 2: Insert 2 -> Heap: {2, 5}
Step 3: Insert 8 -> Heap: {2, 5, 8}
Step 4: Insert 1 -> Heap: {1, 2, 8, 5}
As you can see, 1 is the smallest element and is always at the top of the Min Heap (pq.top()).

Why Min Heap Here?
Since we want to find the kth smallest element, the Min Heap helps by always giving the smallest elements first. By popping the smallest elements k - 1 times, we can then access the kth smallest element at the top of the heap.

Putting It All Together:
So, this line:

cpp
Copy code
priority_queue<int, vector<int>, greater<int>> pq;
creates a Min Heap where:

Smallest element has the highest priority.
This allows efficient extraction of the kth smallest element in the array.
Does that make more sense now?

#include <bits/stdc++.h>
using namespace std;
The #include <bits/stdc++.h> header file includes all standard C++ libraries.
The using namespace std; allows using standard C++ functions and objects without having to prefix them with std::.
Class Definition:
cpp
Copy code
class Solution {
public:
    // Function to find the Kth largest element using Max Heap
    void kth_Largest_MaxHeap(vector<int>& arr, int k) {
A class Solution is defined.
The function kth_Largest_MaxHeap takes two arguments:
A vector arr of integers (the array of numbers).
An integer k, representing which largest element we need to find.
cpp
Copy code
        priority_queue<int> pq;
        int n = arr.size();
A Max Heap (priority queue) pq is initialized. This heap automatically stores elements in descending order.
n is assigned the size of the arr vector.
Let's go ahead with the **correct dry run** for the **`kth_Largest_MaxHeap`** function, which uses a Max Heap to find the **kth largest element**. We will use the vector `{1, 2, 6, 4, 5, 3}` and look for the **3rd largest element**.

### Function for `kth_Largest_MaxHeap`:
```cpp
void kth_Largest_MaxHeap(vector<int>& arr, int k) {
    // Create a Max Heap
    priority_queue<int> pq;
    
    // Insert all elements of the array into the Max Heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    // Pop k-1 elements from the Max Heap to find the kth largest
    int f = k - 1;
    while (f > 0) {
        pq.pop();
        f--;
    }

    // The top of the heap is now the kth largest element
    cout << "Kth Largest element: " << pq.top() << "\n";
}
```

### Dry Run Example:

- **Input**: `arr = {1, 2, 6, 4, 5, 3}`, `k = 3` (we want the 3rd largest element)

#### Step 1: Initialize the Max Heap
- A Max Heap is created using the line `priority_queue<int> pq;`.

#### Step 2: Insert all elements into the Max Heap
- Iterating through the array `arr`, each element is inserted into the Max Heap:
  1. Insert `1`: Max Heap = `{1}`
  2. Insert `2`: Max Heap = `{2, 1}` (Max Heap always has the largest on top)
  3. Insert `6`: Max Heap = `{6, 1, 2}`
  4. Insert `4`: Max Heap = `{6, 4, 2, 1}`
  5. Insert `5`: Max Heap = `{6, 5, 2, 1, 4}`
  6. Insert `3`: Max Heap = `{6, 5, 3, 1, 4, 2}`

At this point, the Max Heap structure keeps the largest elements at the top, and the current heap looks like this: `{6, 5, 3, 1, 4, 2}`, where `6` is at the top.

#### Step 3: Pop `k-1` elements to find the `k`th largest
Since `k = 3`, we need to pop `k-1 = 2` elements from the heap to reach the 3rd largest element.

- **First pop**: Remove `6` (top of the Max Heap)
  - Max Heap after popping: `{5, 4, 3, 1, 2}`
  
- **Second pop**: Remove `5` (new top of the Max Heap)
  - Max Heap after popping: `{4, 2, 3, 1}`

#### Step 4: The top element is the `k`th largest
- Now, the top of the heap is `4`, which is the **3rd largest element**.

#### Output:
```cpp
Kth Largest element: 4
```

### Summary:
- After inserting all elements into the Max Heap, and popping `k-1` elements, the top of the heap gives us the `k`th largest element. 
- For the array `{1, 2, 6, 4, 5, 3}` with `k = 3`, the **3rd largest element** is **4**.

cpp
Copy code
    void kth_Smallest_MinHeap(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
A Min Heap pq is initialized. This stores elements in ascending order.
cpp
Copy code
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
The elements of the array arr are pushed into the Min Heap pq.
After insertion, the heap will automatically organize elements in ascending order.
Dry run with the same array {1, 2, 6, 4, 5, 3}:

First iteration: pq.push(1). Min heap: {1}.
Second iteration: pq.push(2). Min heap: {1, 2}.
Third iteration: pq.push(6). Min heap: {1, 2, 6}.
Fourth iteration: pq.push(4). Min heap: {1, 2, 6, 4}.
Fifth iteration: pq.push(5). Min heap: {1, 2, 6, 4, 5}.
Sixth iteration: pq.push(3). Min heap: {1, 2, 3, 4, 5, 6}.
cpp
Copy code
        int f = k - 1;
        while (f > 0) {
            pq.pop();
            f--;
        }
The loop pops elements f times from the heap until we reach the kth smallest element.
First iteration: pq.pop(), Min heap: {2, 3, 6, 4, 5} (smallest 1 is popped).
Second iteration: pq.pop(), Min heap: {3, 4, 6, 5} (second smallest 2 is popped).
cpp
Copy code
        cout << "Kth Smallest element " << pq.top() << "\n";
After the while loop, the top of the heap (pq.top()) is the kth smallest element.
Output: "Kth Smallest element 3" (3 is the third smallest element).
Main Function:
cpp
Copy code
int main() {
    vector<int> arr = {1, 2, 6, 4, 5, 3};
    Solution obj;
    obj.kth_Largest_MaxHeap(arr, 3);
    obj.kth_Smallest_MinHeap(arr, 3);
    return 0;
}
The array arr = {1, 2, 6, 4, 5, 3} is passed.
The kth_Largest_MaxHeap function is called to find the 3rd largest element.
Output: "Kth Largest element 4".
The kth_Smallest_MinHeap function is called to find the 3rd smallest element.
Output: "Kth Smallest element 3".
Final Output:
Copy code
Kth Largest element 4
Kth Smallest element 3






  coding platform 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
       return nums[k-1];
    }
};

for second one;

The error you're seeing (heap-buffer-overflow) occurs because of incorrect indexing in your loop. Specifically, this happens because in the findKthLargest function, the loop condition is i <= nums.size() (which includes an out-of-bounds access at index nums.size()). The correct loop condition should be i < nums.size() to avoid accessing outside the bounds of the vector.

Here's the corrected code with explanation
  class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int f = k-1;
        while(f>0){
            pq.pop();
            f--;
        }
        int findkthsmallest(vector<int>& nums,int k);
        return pq.top();
    }
    int findkthsmallest(vector<int>&nums, int k){
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int f = k-1;
        while(f<0){
            pq.pop();
            f--;
        }
        return pq.top();
    }
};

