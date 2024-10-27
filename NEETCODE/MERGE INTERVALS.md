maximum no of pairs (all are same code)

435. Non-overlapping Intervals

56. Merge Intervals

1353. Maximum Number of Events That Can Be Attended


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

Let's go through the code step by step, explaining each line and providing examples to clarify how it works.

### Code:

```cpp
class Solution {
```
- **Explanation**: Defines a class named `Solution`. This is the typical structure for submitting solutions on coding platforms like LeetCode.

---

```cpp
public:
```
- **Explanation**: The `public` keyword makes the methods inside this block accessible from outside the class.

---

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
```
- **Explanation**: This is the function `merge`, which takes a reference to a 2D vector `intervals` as input and returns a 2D vector. The goal is to merge overlapping intervals and return the merged intervals.
- **Input Example**: If `intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]`, the function will merge overlapping intervals into `[[1, 6], [8, 10], [15, 18]]`.

---

```cpp
vector<vector<int>> ans;
```
- **Explanation**: Declares a 2D vector `ans` to store the merged intervals.
- **Example**: Initially, `ans` is empty. After merging, it will contain the merged intervals, such as `[[1, 6], [8, 10]]`.

---

```cpp
sort(begin(intervals), end(intervals));
```
- **Explanation**: Sorts the intervals in non-decreasing order based on the starting times of each interval. Sorting is crucial because merging is easier when the intervals are ordered by their starting points.
- **Example**: If `intervals = [[2, 6], [1, 3], [8, 10], [15, 18]]`, after sorting, `intervals` becomes `[[1, 3], [2, 6], [8, 10], [15, 18]]`.

---

```cpp
int a = intervals[0][0], b = intervals[0][1];
```
- **Explanation**: Initializes two variables `a` and `b` with the start and end of the first interval. These variables keep track of the current interval being merged.
- **Example**: If `intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]`, `a = 1` and `b = 3`. This means the current interval starts at `1` and ends at `3`.

---

```cpp
for(auto v : intervals) {
```
- **Explanation**: Iterates over each interval `v` in the sorted `intervals`. Each `v` is a vector representing an interval, where `v[0]` is the start and `v[1]` is the end.
- **Example**: For each interval in `[[1, 3], [2, 6], [8, 10], [15, 18]]`, the loop will iterate through `v = [1, 3]`, then `v = [2, 6]`, and so on.

---

```cpp
if(v[0] > b) {
```
- **Explanation**: This checks if the current interval's start time (`v[0]`) is greater than the end time (`b`) of the previously merged interval. If true, it means the current interval doesn't overlap with the previous one, so we can finalize the previous interval and start a new one.
- **Example**: If `v = [8, 10]` and `b = 6` (after processing the first two intervals), `v[0] = 8` is greater than `b = 6`, so the previous interval is finalized, and the new interval `[8, 10]` starts.

---

```cpp
ans.push_back({a, b});
```
- **Explanation**: If the current interval doesn't overlap with the previous one, this line adds the previous merged interval `{a, b}` to the `ans` vector.
- **Example**: After processing the first two intervals `[1, 3]` and `[2, 6]`, `a = 1` and `b = 6`. The merged interval `[1, 6]` is added to `ans`.

---

```cpp
a = v[0]; b = v[1];
```
- **Explanation**: This updates the values of `a` and `b` to the start (`v[0]`) and end (`v[1]`) of the current interval. This initializes a new interval to track for future merging.
- **Example**: After finalizing the merged interval `[1, 6]`, the new interval starts with `v = [8, 10]`, so `a = 8` and `b = 10`.

---

```cpp
} else if (v[1] > b) b = v[1];
```
- **Explanation**: If the current interval `v` overlaps with the previous one (i.e., `v[0] <= b`), this checks if the end of the current interval (`v[1]`) extends beyond the previous merged interval. If true, it updates `b` to extend the merged interval.
- **Example**: For `v = [2, 6]` and the current merged interval `[1, 3]`, `b = 6` updates the merged interval to `[1, 6]`.

---

```cpp
}
```
- **Explanation**: Closes the `for` loop block. The loop continues with the next interval.

---

```cpp
ans.push_back({a, b});
```
- **Explanation**: After the loop finishes, this adds the final merged interval `{a, b}` to `ans`.
- **Example**: After processing all intervals, the final interval `[15, 18]` is added to `ans`.

---

```cpp
return ans;
```
- **Explanation**: The function returns the `ans` vector, which contains all the merged intervals.
- **Example**: If `intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]`, the output will be `[[1, 6], [8, 10], [15, 18]]`.

---

### Dry Run Example:

**Input**:  
`intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]`

**Step 1**: Sort the intervals:  
`[[1, 3], [2, 6], [8, 10], [15, 18]]` (already sorted).

**Step 2**: Initialize `a = 1`, `b = 3` (first interval).

**Step 3**: Iterate through the intervals:
- First interval `v = [1, 3]`: Since it’s the first interval, no merging happens. Continue.
- Second interval `v = [2, 6]`: Overlaps with `[1, 3]`, so extend `b = 6`. Now the interval is `[1, 6]`.
- Third interval `v = [8, 10]`: No overlap with `[1, 6]`, so add `[1, 6]` to `ans`, and start a new interval `[8, 10]`.
- Fourth interval `v = [15, 18]`: No overlap with `[8, 10]`, so add `[8, 10]` to `ans`, and start a new interval `[15, 18]`.

**Step 4**: Add the final interval `[15, 18]` to `ans`.

**Output**:  
`ans = [[1, 6], [8, 10], [15, 18]]`
