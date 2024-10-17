90. Subsets II
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
Intuition
The problem asks us to generate all possible subsets (the power set) from an array that may contain duplicates. The primary challenge is to ensure that no duplicate subsets are returned in the final solution.

The intuition is to:

Sort the input array so that duplicate elements are adjacent.
Use a recursive backtracking approach to explore two possibilities at each step: either include the current element in the subset or skip it.
To avoid duplicate subsets, we skip duplicate elements when they appear consecutively after being processed.

Approach
Sort the Input: Sorting the array ensures that duplicate elements are grouped together. This allows us to easily skip over consecutive duplicate elements during the recursive process.

Recursive Backtracking:

At each index, we have two choices: either include the element in the subset or skip it.
After including an element, recursively call the function to process the next element.
After excluding an element, we skip all subsequent duplicate elements by moving the index forward.
Every time we reach the end of the array, we store the current subset.
Skip Duplicates: To avoid generating duplicate subsets, after processing a particular element (whether included or excluded), we skip over any adjacent duplicate elements by checking the condition nums[i] == nums[i-1].

Complexity
Time complexity:
The time complexity is O(2^n), where
𝑛
n is the number of elements in the input array. This is because we are generating all possible subsets (the power set), which consists of 2^n subsets. Sorting the array takes 𝑂(𝑛log𝑛) but the dominant factor is the subset generation, resulting in an overall time complexity of O(2^n).
Space complexity:
he space complexity is O(n) due to the space required for recursion and the space used to store the subsets temporarily in the recursive function. Specifically, the depth of the recursive calls will be proportional to n, and the space needed to store the current subset is also 𝑂(𝑛)
Code

```cpp
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index) {
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Start the recursive process
        solve(nums, ans, output, 0);
        
        return ans;
    }
};
```
