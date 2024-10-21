
https://leetcode.com/problems/single-number/description/
---

136. Single Number
Solved
Easy
Topics
Companies
Hint
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1

---

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it:nums)
        {
            freq[it]++;
        }
        for(auto it:freq)
        {
            if(it.second ==1) return it.first;

        }return -1;
    }
};

```
