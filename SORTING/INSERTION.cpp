Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: 
After sorting the array is: 9,13,20,24,46,52


Example 2:
Input: N=5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting the array is: 1,2,3,4,5


ALGORITHM
  
Steps of Insertion Sort:
Start from the second element (index 1) and assume that the first element (index 0) is already sorted.
Compare the current element with the elements before it.
If the current element is smaller than any of the elements before it, move those elements one position to the right.
Insert the current element into its correct position.
Repeat this process for all elements in the array.

  code:

  #include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}

Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-1 i.e. n times, and for each i, the inner loop j runs from i to 1 i.e. i times. For, i = 1, the inner loop runs 1 time, for i = 2, the inner loop runs 2 times, and so on. So, the total steps will be approximately the following: 1 + 2 + 3 +......+ (n-2) + (n-1). The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(1)

  Example with the input [13, 46, 24, 52, 20, 9]
Initial array: [13, 46, 24, 52, 20, 9]

The first element 13 is already sorted.
Pass 1: Compare 46 and 13

Compare 46 (index 1) with 13 (index 0). No swap is needed because 46 > 13.
Array after Pass 1: [13, 46, 24, 52, 20, 9]
Pass 2: Compare 24 with 46 and 13

Compare 24 (index 2) with 46 (index 1). Since 24 < 46, swap them.
Compare 24 (now at index 1) with 13 (index 0). No swap is needed.
Array after Pass 2: [13, 24, 46, 52, 20, 9]
Pass 3: Compare 52 with 46, 24, and 13

Compare 52 (index 3) with 46 (index 2). No swap is needed because 52 > 46.
Array after Pass 3: [13, 24, 46, 52, 20, 9]
Pass 4: Compare 20 with 52, 46, 24, and 13

Compare 20 (index 4) with 52 (index 3). Since 20 < 52, swap them.
Compare 20 (now at index 3) with 46 (index 2). Since 20 < 46, swap them.
Compare 20 (now at index 2) with 24 (index 1). Since 20 < 24, swap them.
Compare 20 (now at index 1) with 13 (index 0). No swap is needed.
Array after Pass 4: [13, 20, 24, 46, 52, 9]
Pass 5: Compare 9 with 52, 46, 24, 20, and 13

Compare 9 (index 5) with 52 (index 4). Since 9 < 52, swap them.
Compare 9 (now at index 4) with 46 (index 3). Since 9 < 46, swap them.
Compare 9 (now at index 3) with 24 (index 2). Since 9 < 24, swap them.
Compare 9 (now at index 2) with 20 (index 1). Since 9 < 20, swap them.
Compare 9 (now at index 1) with 13 (index 0). Since 9 < 13, swap them.
Array after Pass 5: [9, 13, 20, 24, 46, 52]
Final Sorted Array:
[9, 13, 20, 24, 46, 52]

Time Complexity:
Best Case: O(n) (when the array is already sorted)
Worst Case and Average Case: O(n²) (when the array is sorted in reverse order or elements are random)
Space Complexity:
O(1) (in-place sorting algorithm; it uses constant extra space)
