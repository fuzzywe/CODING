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


 
