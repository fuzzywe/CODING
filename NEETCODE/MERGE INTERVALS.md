56. Merge Intervals
Medium
Topics
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

```cpp

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    sort(begin(intervals),end(intervals));
    int a=intervals[0][0],b=intervals[0][1];
    for(auto v:intervals)
    {
        if(v[0]>b)
        {
            ans.push_back({a,b});
            a=v[0]; b=v[1];
        }
        else if(v[1]>b) b=v[1];
    }
    ans.push_back({a,b});
    return ans;
}
};
```
