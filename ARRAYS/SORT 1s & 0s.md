https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :

Input: arr[] = [0, 0, 1, 1, 0]

Output: [0, 0, 0, 1, 1]

Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].

Input: arr[] = [1, 1, 1, 1]

Output: [1, 1, 1, 1]

Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]

Expected Time Complexity: O(n)

Expected Auxiliary Space: O(1)

```cpp

two pointer approach : 

 

void segregate0and1(vector<int> &arr) {
        // code here
        int start=0,end=arr.size()-1;
        
        while(start<end){
            
            if(arr[start]==0){
                start++;
            }
            
            else{
                
                if(arr[end]==0){
                    swap(arr[start],arr[end]);
                    start++,end--;
                }
                else{
                    end--;
                }
            }
        }
    }

```

---

```cpp

int n = arr.size();
        int count0  = 0 ; 
        int count1 = 0 ; 
        for ( int i = 0  ; i < n ; i++)
        {
            if ( arr[i]== 0 )
            {
                count0 ++;
            }
            else
            {
            count1++;
            }
        }
        for ( int i = 0 ; i < count0 ; i++)
        {
            arr[i]= 0;
        }
        for ( int i = count0 ; i< n ; i++)
        {
            arr[i] = 1;
        }



```
