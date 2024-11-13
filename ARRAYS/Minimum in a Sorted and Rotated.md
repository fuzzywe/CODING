https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

A sorted(in ascending order) array arr[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Examples:

Input: arr[] = [4 ,5 ,1 ,2 ,3]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [50, 40, 30, 20, 10, 5]
Output: 5
Explanation: Here 5 is the minimum element.
Input: arr[] = [4]
Output: 4
Explanation: Here 4 is the only minimum element.


```cpp

int n=arr.size();
        int start=0,end=n-1,ans=arr[0];
        while(start<=end)
         {
            int mid=end+(start-end)/2;
            if(arr[0]<=arr[mid])
                start=mid+1;
            else
            {
                ans=arr[mid];
                end=mid-1;
            }
         }
        return ans;
```
