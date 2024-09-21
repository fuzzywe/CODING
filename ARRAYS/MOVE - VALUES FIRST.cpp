Move all negative numbers to beginning and positive to end with constant extra space


Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Naive approach: The idea is to sort the array of elements, this will make sure that all the negative elements will come before all the positive elements.
Below is the implementation of the above approach:


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void move(vector<int>& arr){
  sort(arr.begin(),arr.end());
}
int main() {

    vector<int> arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
      move(arr);
    for (int e : arr)
       cout<<e << " ";
    return 0;
}

// This code is contributed by repakaeshwaripriya

Output
-7 -3 -1 2 4 5 6 8 9 
Time Complexity: O(n*log(n)), Where n is the length of the given array.
Auxiliary Space: O(1)

  Efficient Approach 1:
The idea is to simply apply the partition process of quicksort. 


// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver code
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}

Output
-1 -3 -7 4 5 6 2 8 9 
Time complexity: O(N) 
Auxiliary Space: O(1)


  #include <iostream>
using namespace std;

// Swap Function.
void swap(int &a,int &b){
  int temp =a;
  a=b;
  b=temp;
}
  
// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}
void displayArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main() {
    // Data
    int arr[] = {1, 2,  -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2,  1};
      int n = sizeof(arr)/sizeof(arr[0]);
      reArrange(arr,n);
    displayArray(arr,n);
    return 0;
}

Output
-9 -8 -4 -5 -6 -7 3 2 2 2 1 3 2 1 
Time complexity: O(N) 
Auxiliary Space: O(1)
