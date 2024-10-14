Move all Zeros to the end of the array


230

4
In this article we will learn how to solve the most asked coding interview problem: "Move all Zeros to the end of the array"

Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Example 1:
Input:
 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output:
 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input:
 1,2,0,1,0,4,0
Output:
 1,2,1,4,0,0,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

** OPTIMAL SOLUTION**

 ```cpp
Complexity
Time complexity: O(n)
Space complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }        
    }
};

```

**BRUTE FORCE**

```cpp

Time Complexity: O(n)
Space Complexity: O(n) (due to the extra temp array used).
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int zerocnt =0;
        for(int i=0;i<nums.size();i++)//step 1:traverese the array and get non zero elements
        {
            if(nums[i] !=0)
            {
                temp.push_back(nums[i]);
            }
            zerocnt++;
        }
        for(int i=0;i<temp.size();i++)//Step 2: Copy non-zero elements back to original array
        {
            nums[i] = temp[i];
        }
        for(int i=temp.size();i<nums.size();i++)// Step 3: Append zeros at the end
        {
            nums[i]=0;
        }
    }
};
```
