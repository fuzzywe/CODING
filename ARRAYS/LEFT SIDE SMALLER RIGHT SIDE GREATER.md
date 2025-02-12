https://www.geeksforgeeks.org/problems/unsorted-array4925/1

https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/

---

```cpp



class Solution {
  public:
    int findElement(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int>maxi(n);
        
         maxi[0] = arr[0];
        for(int i =1;i<n;i++)
        {
            maxi[i] = max(maxi[i-1],arr[i]);
        }
        int mini = arr[n-1];
        for(int i = n-2;i>0;i--)
        {
            if( arr[i]>=maxi[i]&& arr[i]<=mini) return arr[i];
            mini = min(arr[i],mini);
        }return -1;
        
    }
};


```


