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

---


```cpp
User
Find the Largest element in an array



#include<bits/stdc++.h>
using namespace std;
 
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2);
   
    return 0;
}

```
---

```cpp

#include <bits/stdc++.h>
 
using namespace std;
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int max = findLargestElement(arr1, n);
  cout << "The largest element in the array is: " << max << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  max = findLargestElement(arr2, n);
  cout << "The largest element in the array is: " << max<<endl;
  return 0;
}




Output:

The largest element in the array is: 5
The largest element in the array is: 10

Complexity Analysis

Time Complexity: O(N)

Space Complexity: O(1)



```


---

```cpp

#include<bits/stdc++.h>
using namespace std;
 
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2);
   
    return 0;
}


Output:

The Largest element in the array is: 5
The Largest element in the array is: 10


```
