1851. Minimum Interval to Include Each Query
Hard
Topics
Companies
Hint
You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

Return an array containing the answers to the queries.

 

Example 1:

Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
Example 2:

Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.

  The problem asks us to find the smallest interval that contains each query and return the size of that interval for each query. If no interval contains the query, the answer should be `-1`.

### Problem Breakdown:

1. **Intervals:** Each interval is defined by a pair `[lefti, righti]`, meaning it starts at `lefti` and ends at `righti` (inclusive). The size of an interval is calculated as:
   \[
   \text{size of interval} = (\text{righti} - \text{lefti} + 1)
   \]

2. **Queries:** We need to find the smallest interval that contains each query, where the query `q` is considered to be inside the interval if:
   \[
   \text{lefti} \leq q \leq \text{righti}
   \]
   Once we find the smallest interval for a query, we return its size. If no interval contains the query, we return `-1`.

### Approach:

- For each query, check which intervals contain it.
- Among the intervals that contain the query, choose the smallest one (the one with the smallest size).
- If no interval contains the query, return `-1` for that query.

### Example 1:

#### Input:
- Intervals: `[[1, 4], [2, 4], [3, 6], [4, 4]]`
- Queries: `[2, 3, 4, 5]`

#### Processing the Queries:

1. **Query = 2:**
   - Check all intervals to see which ones contain `2`:
     - Interval `[1, 4]`: Contains `2` since `1 ≤ 2 ≤ 4` → size = `4 - 1 + 1 = 4`
     - Interval `[2, 4]`: Contains `2` since `2 ≤ 2 ≤ 4` → size = `4 - 2 + 1 = 3`
     - Interval `[3, 6]`: Does not contain `2`
     - Interval `[4, 4]`: Does not contain `2`
   - The smallest interval is `[2, 4]` with size `3`. The answer for query `2` is `3`.

2. **Query = 3:**
   - Check all intervals to see which ones contain `3`:
     - Interval `[1, 4]`: Contains `3` since `1 ≤ 3 ≤ 4` → size = `4 - 1 + 1 = 4`
     - Interval `[2, 4]`: Contains `3` since `2 ≤ 3 ≤ 4` → size = `4 - 2 + 1 = 3`
     - Interval `[3, 6]`: Contains `3` since `3 ≤ 3 ≤ 6` → size = `6 - 3 + 1 = 4`
     - Interval `[4, 4]`: Does not contain `3`
   - The smallest interval is `[2, 4]` with size `3`. The answer for query `3` is `3`.

3. **Query = 4:**
   - Check all intervals to see which ones contain `4`:
     - Interval `[1, 4]`: Contains `4` since `1 ≤ 4 ≤ 4` → size = `4 - 1 + 1 = 4`
     - Interval `[2, 4]`: Contains `4` since `2 ≤ 4 ≤ 4` → size = `4 - 2 + 1 = 3`
     - Interval `[3, 6]`: Contains `4` since `3 ≤ 4 ≤ 6` → size = `6 - 3 + 1 = 4`
     - Interval `[4, 4]`: Contains `4` since `4 ≤ 4 ≤ 4` → size = `4 - 4 + 1 = 1`
   - The smallest interval is `[4, 4]` with size `1`. The answer for query `4` is `1`.

4. **Query = 5:**
   - Check all intervals to see which ones contain `5`:
     - Interval `[1, 4]`: Does not contain `5`
     - Interval `[2, 4]`: Does not contain `5`
     - Interval `[3, 6]`: Contains `5` since `3 ≤ 5 ≤ 6` → size = `6 - 3 + 1 = 4`
     - Interval `[4, 4]`: Does not contain `5`
   - The only interval that contains `5` is `[3, 6]` with size `4`. The answer for query `5` is `4`.

#### Final Output:
```
[3, 3, 1, 4]
```

### Example 2:

#### Input:
- Intervals: `[[2, 3], [2, 5], [1, 8], [20, 25]]`
- Queries: `[2, 19, 5, 22]`

#### Processing the Queries:

1. **Query = 2:**
   - Check all intervals to see which ones contain `2`:
     - Interval `[2, 3]`: Contains `2` since `2 ≤ 2 ≤ 3` → size = `3 - 2 + 1 = 2`
     - Interval `[2, 5]`: Contains `2` since `2 ≤ 2 ≤ 5` → size = `5 - 2 + 1 = 4`
     - Interval `[1, 8]`: Contains `2` since `1 ≤ 2 ≤ 8` → size = `8 - 1 + 1 = 8`
     - Interval `[20, 25]`: Does not contain `2`
   - The smallest interval is `[2, 3]` with size `2`. The answer for query `2` is `2`.

2. **Query = 19:**
   - Check all intervals to see which ones contain `19`:
     - None of the intervals contain `19`.
   - The answer for query `19` is `-1`.

3. **Query = 5:**
   - Check all intervals to see which ones contain `5`:
     - Interval `[2, 3]`: Does not contain `5`
     - Interval `[2, 5]`: Contains `5` since `2 ≤ 5 ≤ 5` → size = `5 - 2 + 1 = 4`
     - Interval `[1, 8]`: Contains `5` since `1 ≤ 5 ≤ 8` → size = `8 - 1 + 1 = 8`
     - Interval `[20, 25]`: Does not contain `5`
   - The smallest interval is `[2, 5]` with size `4`. The answer for query `5` is `4`.

4. **Query = 22:**
   - Check all intervals to see which ones contain `22`:
     - Interval `[2, 3]`: Does not contain `22`
     - Interval `[2, 5]`: Does not contain `22`
     - Interval `[1, 8]`: Does not contain `22`
     - Interval `[20, 25]`: Contains `22` since `20 ≤ 22 ≤ 25` → size = `25 - 20 + 1 = 6`
   - The only interval that contains `22` is `[20, 25]` with size `6`. The answer for query `22` is `6`.

#### Final Output:
```
[2, -1, 4, 6]
```

### Summary of Steps:
1. **Iterate through each query** and check which intervals contain it.
2. **Find the smallest interval** (in terms of size) that contains the query.
3. If no interval contains the query, return `-1` for that query.
4. Collect the results for all queries and return the final answer.


 This code solves the problem of finding the smallest interval containing each query using an **event-driven approach** and a **multiset** for efficient size management. Let’s go line by line, explain the math behind it, and perform a dry run.

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
	vector<vector<int>> events;

	for (int i = 0; i < intervals.size(); i++) {
		events.push_back({intervals[i][0], 0, intervals[i][1] - intervals[i][0] + 1});
		events.push_back({intervals[i][1], 2, intervals[i][1] - intervals[i][0] + 1});
	}
	for (int i = 0; i < queries.size(); i++) {
		events.push_back({queries[i], 1, i});
	}

	sort(events.begin(), events.end());

	multiset<int> sizes;
	vector<int> ans(queries.size(), -1);

	for (auto event : events) {
		if (event[1] == 0) sizes.insert(event[2]);
		else if (event[1] == 1) { if (sizes.size() > 0) ans[event[2]] = (*sizes.begin()); }
		else sizes.erase(sizes.lower_bound(event[2]));
	}

	return ans;
}
};

### Code Explanation (Line by Line):

```cpp
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
```
- The function takes two inputs:
  1. `intervals`: A 2D vector representing intervals where each interval is defined by two integers `[lefti, righti]`.
  2. `queries`: A vector of integers representing queries for which we need to find the smallest interval containing the query.

```cpp
vector<vector<int>> events;
```
- Create a vector `events` to hold all the interval and query events. Each event will be represented as a vector `[position, type, value]` where:
  - `position`: The current event point (either start/end of an interval or a query point).
  - `type`: Indicates whether the event is starting (0), ending (2), or a query (1).
  - `value`: The size of the interval for start/end events, or the index of the query for query events.

```cpp
for (int i = 0; i < intervals.size(); i++) {
	events.push_back({intervals[i][0], 0, intervals[i][1] - intervals[i][0] + 1});
	events.push_back({intervals[i][1], 2, intervals[i][1] - intervals[i][0] + 1});
}
```
- This loop iterates over all intervals and creates two events for each interval:
  - **Start Event** at `lefti`: `{intervals[i][0], 0, size}` where `size = righti - lefti + 1`. This marks the start of the interval.
  - **End Event** at `righti`: `{intervals[i][1], 2, size}`. This marks the end of the interval.
  
  This setup helps us manage the interval when it begins and when it ends.

```cpp
for (int i = 0; i < queries.size(); i++) {
	events.push_back({queries[i], 1, i});
}
```
- This loop adds query events into the `events` vector. Each query is represented as `{queries[i], 1, i}` where:
  - `queries[i]`: The query point.
  - `1`: Denotes it's a query event.
  - `i`: The index of the query in the `queries` vector (to help assign results later).

```cpp
sort(events.begin(), events.end());
```
- This sorts the `events` by `position` (the first element in each event). Sorting ensures that we process the events in the order of their positions (intervals and queries will be handled together in increasing order of their positions).

```cpp
multiset<int> sizes;
vector<int> ans(queries.size(), -1);
```
- `sizes`: A multiset to keep track of the sizes of the currently active intervals. A multiset is used because it maintains elements in sorted order, allowing us to efficiently get the smallest interval at any point.
- `ans`: A vector to store the results for each query. It is initialized with `-1` for each query, meaning "no interval contains this query" by default.

```cpp
for (auto event : events) {
```
- This loop iterates over all events in the sorted order.

```cpp
if (event[1] == 0) sizes.insert(event[2]);
```
- If the event is a **start event** (type `0`), insert the size of the interval into the `sizes` multiset. This means the interval has started and should be considered when processing queries.

```cpp
else if (event[1] == 1) {
	if (sizes.size() > 0) ans[event[2]] = (*sizes.begin());
}
```
- If the event is a **query event** (type `1`):
  - Check if there are any active intervals in `sizes`.
  - If `sizes` is not empty, assign the smallest interval size (the smallest value in the multiset, `*sizes.begin()`) to the answer for the query (`ans[event[2]]` where `event[2]` is the index of the query).

```cpp
else sizes.erase(sizes.lower_bound(event[2]));
```
- If the event is an **end event** (type `2`), remove the corresponding interval size from the `sizes` multiset. This means the interval has ended and should no longer be considered when processing future queries.

```cpp
return ans;
}
```
- Finally, return the results for all queries.

---

### Dry Run:

Let’s dry run the code with an example:

#### Input:
- `intervals = [[1,4],[2,4],[3,6],[4,4]]`
- `queries = [2,3,4,5]`

#### Step 1: Create events:
```cpp
events = [
	{1, 0, 4},  // Start of interval [1,4] (size = 4)
	{4, 2, 4},  // End of interval [1,4]
	{2, 0, 3},  // Start of interval [2,4] (size = 3)
	{4, 2, 3},  // End of interval [2,4]
	{3, 0, 4},  // Start of interval [3,6] (size = 4)
	{6, 2, 4},  // End of interval [3,6]
	{4, 0, 1},  // Start of interval [4,4] (size = 1)
	{4, 2, 1},  // End of interval [4,4]
	{2, 1, 0},  // Query 2
	{3, 1, 1},  // Query 3
	{4, 1, 2},  // Query 4
	{5, 1, 3}   // Query 5
]
```

#### Step 2: Sort events:
```cpp
events = [
	{1, 0, 4}, {2, 0, 3}, {2, 1, 0}, {3, 0, 4}, {3, 1, 1},
	{4, 0, 1}, {4, 1, 2}, {4, 2, 4}, {4, 2, 3}, {4, 2, 1},
	{5, 1, 3}, {6, 2, 4}
]
```

#### Step 3: Process events:
- Start processing from the first event:
  - `{1, 0, 4}`: Add interval `[1, 4]` (size = 4) to `sizes`.
  - `{2, 0, 3}`: Add interval `[2, 4]` (size = 3) to `sizes`.
  - `{2, 1, 0}`: Query 2. Smallest size = `3`, so `ans[0] = 3`.
  - `{3, 0, 4}`: Add interval `[3, 6]` (size = 4) to `sizes`.
  - `{3, 1, 1}`: Query 3. Smallest size = `3`, so `ans[1] = 3`.
  - `{4, 0, 1}`: Add interval `[4, 4]` (size = 1) to `sizes`.
  - `{4, 1, 2}`: Query 4. Smallest size = `1`, so `ans[2] = 1`.
  - `{4, 2, 4}`: Remove interval `[1, 4]` (size = 4) from `sizes`.
  - `{4, 2, 3}`: Remove interval `[2, 4]` (size = 3) from `sizes`.
  - `{4, 2, 1}`: Remove interval `[4, 4]` (size = 1) from `sizes`.
  - `{5, 1, 3}`: Query 5. Smallest size = `4`, so `ans[3] = 4`.
  - `{6, 2, 4}`: Remove interval `[3, 6]` (size = 4) from `sizes`.

#### Final Answer:
```cpp
ans = [3, 3, 1, 4]
```

This matches the expected result!
