https://leetcode.com/problems/kth-largest-element-in-an-array/description/
**Problem Statement: Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.**

Examples:

Example 1:
Input: Array = [1,2,6,4,5,3] , K = 3 
Output: kth largest element = 4, kth smallest element = 3

Example 2:
Input: Array = [1,2,6,4,5] , k = 3
Output : kth largest element = 4,  kth smallest element = 4
Solution
Disclaimer: Don't jump directly to the solution, try it out yourself first.  

### Problem Statement Explanation:

The task is to find the **K-th largest** and **K-th smallest** elements from an **unsorted array**. 

Given:
- An **unsorted array** of integers.
- A value **K** which represents the position of the element to find in both sorted orders (ascending for smallest, descending for largest).

### Understanding the Problem:

1. **K-th Largest Element**:
   - If the array is sorted in descending order (from largest to smallest), the K-th element from the start of this sorted array will be the **K-th largest element**.

2. **K-th Smallest Element**:
   - If the array is sorted in ascending order (from smallest to largest), the K-th element from the start of this sorted array will be the **K-th smallest element**.

### Example 1:
- **Input**: `Array = [1, 2, 6, 4, 5, 3]`, `K = 3`
- **Sorted Ascending**: `[1, 2, 3, 4, 5, 6]`
  - The **3rd smallest element** is **3**.
- **Sorted Descending**: `[6, 5, 4, 3, 2, 1]`
  - The **3rd largest element** is **4**.
- **Output**: 3rd largest element = 4, 3rd smallest element = 3

### Example 2:
- **Input**: `Array = [1, 2, 6, 4, 5]`, `K = 3`
- **Sorted Ascending**: `[1, 2, 4, 5, 6]`
  - The **3rd smallest element** is **4**.
- **Sorted Descending**: `[6, 5, 4, 2, 1]`
  - The **3rd largest element** is **4**.
- **Output**: 3rd largest element = 4, 3rd smallest element = 4

### Key Insights:
- Sorting the array helps us directly access the K-th largest or smallest element.
- We can solve this using efficient sorting algorithms or heap-based approaches to avoid fully sorting the array for larger datasets.

### Approach:

1. **Sort the Array**:
   - First, sort the array in ascending order.
   - The K-th smallest element is simply at index `K-1`.
   - The K-th largest element can be found from the reverse side of the sorted array.

2. **Optimized Approach** (without full sort):
   - You could use **heaps** or the **QuickSelect** algorithm to directly find the K-th largest or smallest element without fully sorting the array. This reduces the time complexity compared to sorting the entire array.



****__Solution 1: Sorting the Array****

The most naive approach is to sort the given array in descending order.

The index of kth Largest element = k-1 ( zero-based indexing ) 

The index of kth Smallest element = n-k 

The array can also be sorted in ascending order.

The index of kth Largest element = n-k 

The index of kth Smallest element = k-1 ( zero based indexing )__


```cpp

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
```

Solution 2: Using Heap
The idea is to construct a max-heap of elements. Since the top element of the max heap is the largest element of the heap, we will remove the top K-1 elements from the heap.  The top element will be Kth's Largest element.
To get the Kth Smallest element, we will use a min-heap. After the removal of the top k-1 elements, the Kth Smallest element is top of the Priority queue.
Let the array be
[17,7,2,30,21] and k = 3

**dont study this one study last approach**

Similarly, for the smallest kth element we will be using Min-Heap. After, extracting the top k-1 values will be having Kth Smallest element.

Code:

```cpp
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

```
Output:

Kth Largest element 4
Kth Smallest element 3

Time complexity: O(k+(n-k)*log(k))  , n = size of array

Space complexity: O(k)



**2. APPROACH**

Yes, the code can be optimized further by reducing the need to store all elements in a heap. Instead of pushing all elements into the heap, we can maintain a **min-heap** for the K-th largest element and a **max-heap** for the K-th smallest element using the following approach:

### Optimized Approach:
1. **K-th Largest Element**:
   - Instead of using a max heap with all the elements, we can maintain a **min-heap** of size `K`. The top element of the heap will give us the K-th largest element.
   - **How it works**: We push elements into the heap, but once the heap size exceeds `K`, we pop the smallest element, ensuring the heap only contains the `K` largest elements. The smallest element in the heap will then be the K-th largest.

2. **K-th Smallest Element**:
   - Similarly, we maintain a **max-heap** of size `K` for the K-th smallest element.
   - **How it works**: We push elements into the heap, but once the heap size exceeds `K`, we pop the largest element, ensuring the heap only contains the `K` smallest elements. The largest element in the heap will be the K-th smallest.

### Optimized Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find Kth largest element using min-heap
    void kth_Largest_MinHeap(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Push elements into the heap
        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);
            
            // If heap size exceeds k, remove the smallest element (top)
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top element is the Kth largest element
        cout << "Kth Largest element: " << minHeap.top() << "\n";
    }

    // Function to find Kth smallest element using max-heap
    void kth_Smallest_MaxHeap(vector<int>& arr, int k) {
        priority_queue<int> maxHeap;
        
        // Push elements into the heap
        for (int i = 0; i < arr.size(); i++) {
            maxHeap.push(arr[i]);
            
            // If heap size exceeds k, remove the largest element (top)
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // The top element is the Kth smallest element
        cout << "Kth Smallest element: " << maxHeap.top() << "\n";
    }
};
```

### Explanation of the Optimized Code:

#### 1. **For Finding K-th Largest Element (`kth_Largest_MinHeap`)**:
- **Min Heap (`minHeap`)** is used to maintain only the `K` largest elements.
- After inserting an element, if the heap size exceeds `K`, we pop the smallest element, leaving the K largest elements.
- The top of the min heap will be the K-th largest element because the heap holds the K largest elements, with the smallest of those K at the top.

#### 2. **For Finding K-th Smallest Element (`kth_Smallest_MaxHeap`)**:
- **Max Heap (`maxHeap`)** is used to maintain only the `K` smallest elements.
- After inserting an element, if the heap size exceeds `K`, we pop the largest element, leaving the K smallest elements.
- The top of the max heap will be the K-th smallest element because the heap holds the K smallest elements, with the largest of those K at the top.

### Dry Run for Optimized Code:

For `arr = [3, 2, 1, 5, 6, 4]` and `k = 2`:

- **For K-th Largest**:
  - Insert 3: Heap = `[3]`
  - Insert 2: Heap = `[2, 3]`
  - Insert 1: Heap = `[1, 3, 2]`, pop 1 (since heap size > 2), new heap = `[2, 3]`
  - Insert 5: Heap = `[2, 3, 5]`, pop 2, new heap = `[3, 5]`
  - Insert 6: Heap = `[3, 5, 6]`, pop 3, new heap = `[5, 6]`
  - Insert 4: Heap = `[4, 6, 5]`, pop 4, new heap = `[5, 6]`
  - Result: The top of the heap is `5`, which is the 2nd largest element.

- **For K-th Smallest**:
  - Insert 3: Heap = `[3]`
  - Insert 2: Heap = `[3, 2]`
  - Insert 1: Heap = `[3, 2, 1]`, pop 3 (since heap size > 2), new heap = `[2, 1]`
  - Insert 5: Heap = `[5, 2, 1]`, pop 5, new heap = `[2, 1]`
  - Insert 6: Heap = `[6, 2, 1]`, pop 6, new heap = `[2, 1]`
  - Insert 4: Heap = `[4, 2, 1]`, pop 4, new heap = `[2, 1]`
  - Result: The top of the heap is `2`, which is the 2nd smallest element.

### Time Complexity:
- **Inserting into the heap** takes O(log K) for each element.
- Since we process `n` elements, the overall time complexity for both functions is:
  - **O(n log K)**, where `n` is the size of the array and `K` is the rank of the element to be found.

### Space Complexity:
- The heap maintains only `K` elements, so the space complexity is **O(K)**.

This optimization reduces the space complexity and speeds up the operation, especially when `K` is much smaller than `n`.

Let’s walk through the optimized solution for finding the K-th largest and K-th smallest element in an unsorted array using heaps. The code contains two main functions:

- `kth_Largest_MinHeap`: Finds the K-th largest element using a **min-heap**.
- `kth_Smallest_MaxHeap`: Finds the K-th smallest element using a **max-heap**.

I’ll provide an **explanation** and **dry run** for each line of the code below.

### Optimized Code Explanation (Line by Line):

```cpp
#include <iostream>
#include <vector>
#include <queue>  // Needed for priority_queue (min-heap and max-heap)
using namespace std;

class Solution {
public:
    // Function to find Kth largest element using min-heap
    void kth_Largest_MinHeap(vector<int>& arr, int k) {
        // Step 1: Declare a min-heap (priority_queue with greater<int>)
        priority_queue<int, vector<int>, greater<int>> minHeap;
```
- **Explanation**: A **min-heap** is initialized using `priority_queue`. In a min-heap, the smallest element is always at the top.
- **Dry Run**: We initialize an empty min-heap: `minHeap = {}`.

```cpp
        // Step 2: Iterate over the array and push elements into the min-heap
        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);
```
- **Explanation**: We iterate over the array `arr` and insert each element into the min-heap. Initially, the heap can grow larger than size `K`, but we will control its size later.
- **Dry Run**: Suppose `arr = [3, 2, 1, 5, 6, 4]`. After inserting the first 3 elements, `minHeap = {1, 2, 3}`.

```cpp
            // Step 3: If heap size exceeds K, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element to keep only K elements
            }
        }
```
- **Explanation**: If the heap size exceeds `K`, we remove the smallest element using `minHeap.pop()`. This ensures the heap always contains the `K` largest elements.
- **Dry Run**: 
    - After inserting `5`: `minHeap = {2, 3, 5}` (popped `1`).
    - After inserting `6`: `minHeap = {3, 5, 6}` (popped `2`).
    - After inserting `4`: `minHeap = {4, 5, 6}` (popped `3`).
  
```cpp
        // Step 4: The top element is the K-th largest
        cout << "Kth Largest element: " << minHeap.top() << "\n";
    }
```
- **Explanation**: The top element of the min-heap is the K-th largest element because the heap contains exactly the K largest elements, and the smallest among them (which is at the top of the heap) is the K-th largest.
- **Dry Run**: The heap now contains `{4, 5, 6}`, and the top element is `4`. Therefore, the 3rd largest element is `4`.

---

```cpp
    // Function to find Kth smallest element using max-heap
    void kth_Smallest_MaxHeap(vector<int>& arr, int k) {
        // Step 1: Declare a max-heap (default priority_queue is a max-heap)
        priority_queue<int> maxHeap;
```
- **Explanation**: A **max-heap** is initialized using `priority_queue`. In a max-heap, the largest element is always at the top.
- **Dry Run**: We initialize an empty max-heap: `maxHeap = {}`.

```cpp
        // Step 2: Iterate over the array and push elements into the max-heap
        for (int i = 0; i < arr.size(); i++) {
            maxHeap.push(arr[i]);
```
- **Explanation**: We iterate over the array `arr` and insert each element into the max-heap.
- **Dry Run**: Suppose `arr = [3, 2, 1, 5, 6, 4]`. After inserting the first 3 elements, `maxHeap = {3, 2, 1}`.

```cpp
            // Step 3: If heap size exceeds K, remove the largest element
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove the largest element to keep only K elements
            }
        }
```
- **Explanation**: If the heap size exceeds `K`, we remove the largest element using `maxHeap.pop()`. This ensures the heap always contains the `K` smallest elements.
- **Dry Run**:
    - After inserting `5`: `maxHeap = {3, 2, 1}` (popped `5`).
    - After inserting `6`: `maxHeap = {3, 2, 1}` (popped `6`).
    - After inserting `4`: `maxHeap = {3, 2, 1}` (popped `4`).
  
```cpp
        // Step 4: The top element is the K-th smallest
        cout << "Kth Smallest element: " << maxHeap.top() << "\n";
    }
};
```
- **Explanation**: The top element of the max-heap is the K-th smallest element because the heap contains exactly the K smallest elements, and the largest among them (which is at the top of the heap) is the K-th smallest.
- **Dry Run**: The heap now contains `{3, 2, 1}`, and the top element is `3`. Therefore, the 3rd smallest element is `3`.

---

### Final Dry Run for Both Functions:

Let’s dry run the code with `arr = [3, 2, 1, 5, 6, 4]` and `k = 3`.

- **For K-th Largest Element**:
    - Initially, `minHeap = {}`.
    - Insert `3`: `minHeap = {3}`.
    - Insert `2`: `minHeap = {2, 3}`.
    - Insert `1`: `minHeap = {1, 3, 2}`. Since size > 3, pop `1`: `minHeap = {2, 3}`.
    - Insert `5`: `minHeap = {2, 3, 5}`.
    - Insert `6`: `minHeap = {2, 3, 5, 6}`. Since size > 3, pop `2`: `minHeap = {3, 5, 6}`.
    - Insert `4`: `minHeap = {3, 4, 5, 6}`. Since size > 3, pop `3`: `minHeap = {4, 5, 6}`.
    - **Result**: The 3rd largest element is `4`.

- **For K-th Smallest Element**:
    - Initially, `maxHeap = {}`.
    - Insert `3`: `maxHeap = {3}`.
    - Insert `2`: `maxHeap = {3, 2}`.
    - Insert `1`: `maxHeap = {3, 2, 1}`.
    - Insert `5`: `maxHeap = {5, 3, 2, 1}`. Since size > 3, pop `5`: `maxHeap = {3, 2, 1}`.
    - Insert `6`: `maxHeap = {6, 3, 2, 1}`. Since size > 3, pop `6`: `maxHeap = {3, 2, 1}`.
    - Insert `4`: `maxHeap = {4, 3, 2, 1}`. Since size > 3, pop `4`: `maxHeap = {3, 2, 1}`.
    - **Result**: The 3rd smallest element is `3`.

### Time and Space Complexity:

- **Time Complexity**: O(n log K)
    - Inserting into a heap takes O(log K) time, and we do this `n` times, where `n` is the size of the array.
- **Space Complexity**: O(K)
    - The heap will contain at most `K` elements at any time.

This is more efficient than using heaps of size `n`!






Solution 3: Using Quickselect Algorithm
Choose any random element as PIVOT.
Use Partition Algorithm to partition the given array into 2 parts and place the PIVOT at its correct position ( called as index ).
Partition Algorithm: All the elements are compared to the PIVOT, and the elements less than the PIVOT are shifted toward the left side of the array and greater ones are shifted toward the right side of the array.
Now since all elements right to the PIVOT are greater and left to the PIVOT are smaller, compare the index with N-k ( where N = size of the array )  and recursively find the part to find the Kth largest element.
The worst-case time complexity of this method is O(n^2) but its Average time complexity is O(n).



**Code for kth largest element:**
```cpp
#include <bits/stdc++.h>
using namespace std ;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left] ;
    int l = left + 1 ;
    int r = right;
    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) {
            swap(arr[l], arr[r]);
            l++ ;
            r-- ;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        int idx = partition(arr, left, right);
        if (idx == k - 1) {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
}



int main() {

    vector<int>arr ;
    arr.push_back(12) ;
    arr.push_back(3)  ;
    arr.push_back(5) ;
    arr.push_back(7)  ;
    arr.push_back(4) ;
    arr.push_back(19)  ;
    arr.push_back(26) ;

    int n = arr.size(), k = 1;
    cout << "Kth Largest element is " << kth_Largest_Element(arr, k);
    return 0 ;
}
Output: Kth Largest element is 26
```

Time complexity: O(n) , where n = size of the array

Space complexity: O(1) 


****code for Kth Smallest element:****

```cpp


#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int l, int r)
{
	int f = arr[r] ;
	int i = l;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= f) {
			swap(arr[i], arr[j]) ;
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


int kth_Smallest_Element(vector<int>&arr, int l, int r, int k)
{
	if (k <= r - l + 1 && k > 0) {

		int ind = partition(arr, l, r);


		if (ind - l == k - 1) {
			return arr[ind];
		}
		if (ind - l > k - 1) {
			return kth_Smallest_Element(arr, l, ind - 1, k);
		}


		return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
	}
	return INT_MAX;
}

int main()
{

	vector<int>arr ;
	arr.push_back(12) ;
	arr.push_back(3)  ;
	arr.push_back(5) ;
	arr.push_back(7)  ;
	arr.push_back(4) ;
	arr.push_back(19)  ;
	arr.push_back(26) ;

	int n = arr.size(), k = 1;
	cout << "Kth smallest element is " << kth_Smallest_Element(arr, 0, n - 1, k);
	return 0;
}
Output: Kth smallest element is 3

Time complexity: O(n) ,where n = size of the array

Space complexity: O(1)



```
