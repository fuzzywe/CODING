2149. Rearrange Array Elements by Sign

https://www.naukri.com/code360/problems/alternate-numbers_6783445?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM


https://leetcode.com/problems/rearrange-array-elements-by-sign/description/



![30 10 2024_07 23 48_REC](https://github.com/user-attachments/assets/af6244cd-e841-41e4-ad7f-df4fe6ee1197)


https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].


OPTIMAL APPROACH


```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int p_ind = 0;
        int n_ind = 1;
        for(int ele: nums) {
            if( ele < 0) {
                res[n_ind] = ele;
                n_ind += 2;
            } else {
                res[p_ind] = ele;
                p_ind += 2;
            }
        }
        return res;
    }
};

```

BRUTE FORCE:

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // [3,1,-2,-5,2,-4]
     vector<int>pos;
     vector<int>neg;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i]>0) pos.push_back(nums[i]);// [3,1,2]
        else neg.push_back(nums[i]);// [-2,-5,-4] 
     }
        
        for(int i =0;i<nums.size()/2;i++)
        {
           nums[2*i] = pos[i];
           nums[2*i+1] = neg[i];
        }return nums; // [3,-2,1,-5,2,-4].
    }
};

```