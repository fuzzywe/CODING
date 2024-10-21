78. Subsets

https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

 ---
 ```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;        
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }    
};

```

---
**90. Subsets II**
Solved
Medium
Topics
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

---

```cpp
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index) {
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Start the recursive process
        solve(nums, ans, output, 0);
        
        return ans;
        // Base case: If we have processed all elements, return
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        // Include the current element and recurse
        output.push_back(nums[index]);
        solve(nums, ans, output, index + 1);
        
        // Backtrack by removing the current element
        output.pop_back();
        
        // Skip all duplicates of the current element
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        
        // Move to the next element without including the current one
        solve(nums, ans, output, index + 1);
    }
    
    
    }
};
```
