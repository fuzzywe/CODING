Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52


Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5

  #include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;

}
Output:

Before Using Bubble Sort:
13 46 24 52 20 9
After Using bubble sort:
9 13 20 24 46 52

Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Reason: If we carefully observe, we can notice that the outer loop, say i, is running from n-1 to 0 i.e. n times, and for each i, the inner loop j runs from 0 to i-1. For, i = n-1, the inner loop runs n-1 times, for i = n-2, the inner loop runs n-2 times, and so on. So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(1)


1st Pass:
Compare the first two elements, 13 and 46. Since 13 < 46, no swap is needed.

Compare 46 and 24. Since 46 > 24, swap them:


[13, 24, 46, 52, 20, 9]
Compare 46 and 52. Since 46 < 52, no swap is needed.

Compare 52 and 20. Since 52 > 20, swap them:


[13, 24, 46, 20, 52, 9]
Compare 52 and 9. Since 52 > 9, swap them:


[13, 24, 46, 20, 9, 52]
At the end of the first pass, the largest element 52 has "bubbled" up to the last position, and the array looks like this:

[13, 24, 46, 20, 9, 52]
2nd Pass:
Compare 13 and 24. Since 13 < 24, no swap is needed.

Compare 24 and 46. Since 24 < 46, no swap is needed.

Compare 46 and 20. Since 46 > 20, swap them:


[13, 24, 20, 46, 9, 52]
Compare 46 and 9. Since 46 > 9, swap them:


[13, 24, 20, 9, 46, 52]
Now, the second-largest element 46 is in its correct place:


[13, 24, 20, 9, 46, 52]
3rd Pass:
Compare 13 and 24. Since 13 < 24, no swap is needed.

Compare 24 and 20. Since 24 > 20, swap them:

[13, 20, 24, 9, 46, 52]
Compare 24 and 9. Since 24 > 9, swap them:


[13, 20, 9, 24, 46, 52]
Now, the third-largest element 24 is in its correct place:


[13, 20, 9, 24, 46, 52]
4th Pass:
Compare 13 and 20. Since 13 < 20, no swap is needed.

Compare 20 and 9. Since 20 > 9, swap them:


[13, 9, 20, 24, 46, 52]
Now, the fourth-largest element 20 is in its correct place:


[13, 9, 20, 24, 46, 52]
5th Pass:
Compare 13 and 9. Since 13 > 9, swap them:

[9, 13, 20, 24, 46, 52]
Now, the smallest element 9 has "bubbled" up to the first position:


[9, 13, 20, 24, 46, 52]
At this point, the array is fully sorted, and the algorithm stops.

Final Sorted Array:
csharp
Copy code
[9, 13, 20, 24, 46, 52]
Bubble Sort Recap:
Each pass through the array "bubbles" the largest unsorted element to the correct position at the end of the array.
After each pass, the last element is sorted, so the next pass works on the remaining unsorted portion.
Time Complexity:
Worst-case time complexity: O(n^2) because it may need to compare every pair in the array.
Best-case time complexity: O(n) if the array is already sorted.


  

best case by reduce the better case
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;
}
Output: 

Before Using Bubble Sort:

13 46 24 52 20 9

After Using bubble sort:

9 13 20 24 46 52

Time Complexity: O(N2) for the worst and average cases and O(N) for the best case. Here, N = size of the array.

Space Complexity: O(1)
1st Pass:
Initial array: [13, 46, 24, 52, 20, 9]

Compare 13 and 46. Since 13 < 46, no swap is needed.

Compare 46 and 24. Since 46 > 24, swap them:

csharp
Copy code
[13, 24, 46, 52, 20, 9]
Compare 46 and 52. Since 46 < 52, no swap is needed.

Compare 52 and 20. Since 52 > 20, swap them:

csharp
Copy code
[13, 24, 46, 20, 52, 9]
Compare 52 and 9. Since 52 > 9, swap them:

csharp
Copy code
[13, 24, 46, 20, 9, 52]
At the end of the first pass, the array looks like this:

csharp
Copy code
[13, 24, 46, 20, 9, 52]
The largest element 52 has bubbled up to its correct position.

2nd Pass:
Initial array: [13, 24, 46, 20, 9, 52]

Compare 13 and 24. Since 13 < 24, no swap is needed.

Compare 24 and 46. Since 24 < 46, no swap is needed.

Compare 46 and 20. Since 46 > 20, swap them:

csharp
Copy code
[13, 24, 20, 46, 9, 52]
Compare 46 and 9. Since 46 > 9, swap them:

csharp
Copy code
[13, 24, 20, 9, 46, 52]
At the end of the second pass, the array looks like this:

csharp
Copy code
[13, 24, 20, 9, 46, 52]
The second largest element 46 is now in its correct position.

3rd Pass:
Initial array: [13, 24, 20, 9, 46, 52]

Compare 13 and 24. Since 13 < 24, no swap is needed.

Compare 24 and 20. Since 24 > 20, swap them:

csharp
Copy code
[13, 20, 24, 9, 46, 52]
Compare 24 and 9. Since 24 > 9, swap them:

csharp
Copy code
[13, 20, 9, 24, 46, 52]
At the end of the third pass, the array looks like this:

csharp
Copy code
[13, 20, 9, 24, 46, 52]
The third largest element 24 is now in its correct position.

4th Pass:
Initial array: [13, 20, 9, 24, 46, 52]

Compare 13 and 20. Since 13 < 20, no swap is needed.

Compare 20 and 9. Since 20 > 9, swap them:

csharp
Copy code
[13, 9, 20, 24, 46, 52]
At the end of the fourth pass, the array looks like this:

csharp
Copy code
[13, 9, 20, 24, 46, 52]
The fourth largest element 20 is now in its correct position.

5th Pass:
Initial array: [13, 9, 20, 24, 46, 52]

Compare 13 and 9. Since 13 > 9, swap them:

csharp
Copy code
[9, 13, 20, 24, 46, 52]
At the end of the fifth pass, the array looks like this:

csharp
Copy code
[9, 13, 20, 24, 46, 52]
Now, the smallest element 9 has bubbled up to the first position, and the array is fully sorted.

Since swaps were made in the previous passes, the algorithm continued. But now, after the 5th pass, the array is fully sorted.

6th Pass:
When the 6th pass starts, no swaps will occur since the array is already sorted. 
  The didSwap variable will remain 0, and the algorithm will break out of the loop early, saving time.

Time Complexity with Optimization:
In the worst-case scenario (when the array is reverse sorted), the time complexity is still O(n^2).

In the best-case scenario (when the array is already sorted), the time complexity improves to O(n) 
  because the algorithm can detect that no swaps were made and terminate early.

Output:
Before Bubble Sort:

Copy code
13 46 24 52 20 9
After Bubble Sort:

Copy code
9 13 20 24 46 52
Summary of Optimization:
The check if (didSwap == 0) ensures that if the array is already sorted, the loop will stop early and avoid
unnecessary passes, making the algorithm more efficient in cases where the array is close to being sorted.
