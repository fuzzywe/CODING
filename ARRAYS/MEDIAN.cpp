Median of two Sorted Arrays of Different Sizes


Input: arr1[] = {-5, 3, 6, 12, 15}, arr2[] = {-12, -10, -6, -3, 4, 10}
Output: The median is 3.
Explanation: The merged array is arr3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15}. So the median of the merged array is 3.

Input: arr1[] = {2, 3, 5, 8}, arr2[] = {10, 12, 14, 16, 18, 20}
Output: The median is 11.
Explanation : The merged array is arr3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}. The total number of the elements are even, so there are two middle elements.
Take the average between the two: (10 + 12) / 2 = 11

Input: arr1[] = {}, arr2[] = {2, 4, 5, 6}
Output: The median is 4.5
Explanation: The merges array is arr3[] = {2, 4, 5, 6}. The total number of elements are even, so there are two middle elements.
Take the average between the two: (4 + 5) / 2 = 4.5


  Example 1:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result:
 3.5
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result:
 3
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.

  
