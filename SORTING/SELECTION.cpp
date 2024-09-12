Selection sort is a simple algorithm that works by selecting the smallest element
from the unsorted part of the array and swapping it with the first element of the unsorted part. 
It is not the most efficient sorting algorithm but can be used 
for educational purposes or small arrays.
code:
 // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  selection_sort(arr, n);
  return 0;
}


Let’s walk through the sorting process of the array [13, 46, 24, 52, 20, 9].

Pass 1:
We start at index 0 and assume 13 is the smallest.
Compare 13 with 46, 24, 52, 20, and 9.
The smallest value is 9, so we swap 9 with 13.
Array after Pass 1: [9, 46, 24, 52, 20, 13]
Pass 2:
Start at index 1 and assume 46 is the smallest.
Compare 46 with 24, 52, 20, and 13.
The smallest value is 13, so we swap 13 with 46.
Array after Pass 2: [9, 13, 24, 52, 20, 46]
Pass 3:
Start at index 2 and assume 24 is the smallest.
Compare 24 with 52, 20, and 46.
The smallest value is 20, so we swap 20 with 24.
Array after Pass 3: [9, 13, 20, 52, 24, 46]
Pass 4:
Start at index 3 and assume 52 is the smallest.
Compare 52 with 24 and 46.
The smallest value is 24, so we swap 24 with 52.
Array after Pass 4: [9, 13, 20, 24, 52, 46]
Pass 5:
Start at index 4 and assume 52 is the smallest.
Compare 52 with 46.
The smallest value is 46, so we swap 46 with 52.
Array after Pass 5: [9, 13, 20, 24, 46, 52]
Time Complexity:
Best, Average, and Worst Case: O(n²), where n is the number of elements in the array.
The algorithm requires two nested loops to compare and swap elements, making it inefficient for large datasets.
Space Complexity:O(1)


Advantages:
Simple to understand and implement.
Useful for small arrays or when memory space is very limited.
Disadvantages:
Inefficient for large datasets because of its O(n²) time complexity.
Not a stable sort (meaning it may not preserve the relative order of equal elements
O(1) because selection sort works in place and does not require extra space for another array.
Advantages:
Simple to understand and implement.
Useful for small arrays or when memory space is very limited.
Disadvantages:
Inefficient for large datasets because of its O(n²) time complexity.
Not a stable sort (meaning it may not preserve the relative order of equal elements).
