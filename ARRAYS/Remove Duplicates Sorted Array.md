https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Remove Duplicates Sorted Array
Difficulty: EasyAccuracy: 38.18%Submissions: 258K+Points: 2
Given a sorted array arr. Return the size of the modified array which contains only distinct elements.
Note:
1. Don't use set or HashMap to solve the problem.
2. You must return the modified array size only where distinct elements are present and modify the original array such that all the distinct elements come at the beginning of the original array.

Examples :

Input: arr = [2, 2, 2, 2, 2]
Output: [2]
Explanation: After removing all the duplicates only one instance of 2 will remain i.e. [2] so modified array will contains 2 at first position and you should return 1 after modifying the array, the driver code will print the modified array elements.
Input: arr = [1, 2, 4]
Output: [1, 2, 4]
Explation:  As the array does not contain any duplicates so you should return 3.


```cpp

class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        
        int i=0;
        for(int j =1;j<arr.size();j++)
        {
            if(arr[j] !=arr[i])
            {
                arr[i+1] = arr[j];
                i++;
            }
        }return i+1;
        // code here
    }
};

```
