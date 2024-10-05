435. Non-overlapping Intervals
Solved
Medium
Topics
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


```
 class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];} 
 
int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
 sort(intervals.begin(), intervals.end(),cmp); 
  
 int ans=0; 
 int start=intervals[0][0],end = intervals[0][1]; 
 for(int i=1;i<intervals.size();i++){ 
 if(intervals[i][0] < end){ 
 ans++; 
 } 
 else if(intervals[i][0] >= end){  
 start=intervals[i][0]; 
 end=intervals[i][1]; 
 } 
 } 
 return ans; 
 } 
};
```
Time Complexity: O(n) 

Space Complexity: O(1)


Got it! Let's clarify the behavior of the sorting process using a comparator function (`cmp`) that can return either `true` or `false` and show how it affects the sorting results with specific examples.

### Example 1: Comparator Returns `True`

Let's say we have the following intervals and a comparator that sorts by the second element in ascending order.

#### Intervals
```cpp
vector<vector<int>> intervals = {
    {1, 4},
    {2, 3},
    {3, 6},
    {5, 7}
};
```

#### Comparator Function
```cpp
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1]; // Sort by end times
}
```

#### Sorting Process
When the `sort` function is called:

- **Comparisons made**:
  - Compare `{1, 4}` and `{2, 3}`: `4 < 3` (false, do not swap)
  - Compare `{1, 4}` and `{3, 6}`: `4 < 6` (true, do not swap)
  - Compare `{1, 4}` and `{5, 7}`: `4 < 7` (true, do not swap)
  - Compare `{2, 3}` and `{3, 6}`: `3 < 6` (true, do not swap)
  - Compare `{2, 3}` and `{5, 7}`: `3 < 7` (true, do not swap)
  - Compare `{3, 6}` and `{5, 7}`: `6 < 7` (true, do not swap)

#### Sorted Result
After sorting, the output will be:
```cpp
{{2, 3}, {1, 4}, {3, 6}, {5, 7}}
// Because: 
// 3 < 4 < 6 < 7
```

### Example 2: Comparator Returns `False`

Now, let's define a comparator that always returns `false`.

#### Intervals
```cpp
vector<vector<int>> intervals = {
    {1, 4},
    {2, 3},
    {3, 6},
    {5, 7}
};
```

#### Comparator Function
```cpp
bool cmp(vector<int>& a, vector<int>& b) {
    return false; // Always returns false
}
```

#### Sorting Process
When the `sort` function is called:

- **Comparisons made**:
  - Compare `{1, 4}` and `{2, 3}`: `false` (no swap)
  - Compare `{1, 4}` and `{3, 6}`: `false` (no swap)
  - Compare `{1, 4}` and `{5, 7}`: `false` (no swap)
  - Compare `{2, 3}` and `{3, 6}`: `false` (no swap)
  - Compare `{2, 3}` and `{5, 7}`: `false` (no swap)
  - Compare `{3, 6}` and `{5, 7}`: `false` (no swap)

#### Sorted Result
The output will likely remain unchanged:
```cpp
{{1, 4}, {2, 3}, {3, 6}, {5, 7}}
// Because no comparisons allowed any swaps.
```

### Summary of Sorting Results

- **If the comparator returns `true`**:
  - The sort function will arrange the intervals according to the sorting criteria defined in the comparator.
  - Example Output: `{{2, 3}, {1, 4}, {3, 6}, {5, 7}}` (sorted by the second element).

- **If the comparator returns `false`**:
  - The sort function will still execute, but no swaps will be made, and the order of the elements will likely remain unchanged.
  - Example Output: `{{1, 4}, {2, 3}, {3, 6}, {5, 7}}` (original order).

This illustrates how the behavior of the sort function is dependent on the return value of the comparator.