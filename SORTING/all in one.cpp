Bubble Sort: Swaps adjacent elements repeatedly to move them to their correct positions.
Selection Sort: Selects the smallest element from the unsorted part and swaps it into the correct position.
Insertion Sort: Inserts elements into their correct positions in a sorted subarray.
All three algorithms are easy to understand but inefficient for large datasets due to their O(n²) 
time complexity in the average and worst cases.
1. Merge Sort
Definition:

Merge Sort is a divide-and-conquer algorithm that splits the input array into smaller subarrays, sorts them,
and then merges them back together to produce a sorted array. It recursively divides the array into two halves
until each subarray has only one element, then merges these subarrays in a sorted manner.
Key Points:

It divides the array into two halves, sorts them, and then merges them.
It is stable, meaning that it preserves the relative order of elements with equal values.
It is not an in-place sorting algorithm because it requires additional memory for merging.
Time Complexity:

Best, Average, and Worst Case: O(n log n)
Space Complexity:O(n), due to the need for additional space to merge subarrays.


2. Heap Sort
Definition:

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. 
It first builds a max-heap from the input data, where the largest element is placed at the root. 
Then, it swaps the root with the last element of the heap and reduces the heap size by one. 
This process is repeated until the entire array is sorted.
Key Points:

A heap is a specialized tree-based data structure that satisfies the heap property (for max-heap, the parent node is always greater than or equal to its children).
Heap Sort first builds a max-heap and then repeatedly extracts the largest element and places it at the end of the array.
It is an in-place sorting algorithm but not a stable one.
Time Complexity: Best, Average, and Worst Case: O(n log n)
Space Complexity: O(1) (in-place sorting, does not require extra space)


3. Quick Sort
Definition:

Quick Sort is a divide-and-conquer algorithm that selects a "pivot" element from the array and partitions 
the other elements into two subarrays, according to whether they are less than or greater than the pivot. 
The subarrays are then sorted recursively. Quick Sort is highly efficient and widely used for large datasets.
Key Points:

It works by selecting a pivot element and partitioning the array into two parts: 
elements smaller than the pivot and elements larger than the pivot.
After partitioning, it recursively sorts the subarrays.
It is an in-place sorting algorithm but not stable.

Time Complexity: Best and Average Case: O(n log n)
Worst Case: O(n²) (occurs when the pivot is poorly chosen, e.g., always selecting the largest or smallest element)
Space Complexity:

O(log n) (due to recursive function calls)


Summary of Differences:

Merge Sort: Uses the divide-and-conquer approach and recursively splits the array before merging sorted subarrays. 
Requires extra space for merging.

Heap Sort: Uses a binary heap to repeatedly extract the largest element, placing it at the end of the array. 
It is an in-place algorithm.

Quick Sort: Also uses divide-and-conquer but partitions the array around a pivot element.
It is an in-place algorithm and faster in practice for large datasets but has a potential worst case of O(n²).
All three algorithms are more efficient than simple algorithms like bubble, insertion, and selection sorts, 
especially for larger datasets.
