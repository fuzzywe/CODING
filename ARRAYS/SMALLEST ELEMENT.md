```cpp

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
int SmallestElement(int arr[], int n) {
 
  int min = arr[0];
  for (int i = 0; i < n; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int min = SmallestElement(arr1, n);
  cout << "The smallest element in the array is: " << min << endl;


```

Output:

The smallest element in the array is: 0
The smallest element in the array is: 5

Time Complexity: O(N)

Space Complexity: O(1)


---

```cpp

#include<bits/stdc++.h>
using namespace std;
 
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[0];
}
 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The smallest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The smallest element in the array is: "<<sortArr(arr2);
   
    return 0;
}
Output:

The smallest element in the array is: 0
The smallest element in the array is: 5

Time Complexity: O(N*log(N))

Space Complexity: O(1)


```
