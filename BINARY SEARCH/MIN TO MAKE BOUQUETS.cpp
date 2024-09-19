Minimum days to make M bouquets



Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

Examples
Example 1:
Input Format:
 N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
Result:
 12
Explanation:
 On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2:
Input Format:
 N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
Result:
 -1
Explanation:
 If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.


Let's grasp the question better with the help of an example. Consider an array: {7, 7, 7, 7, 13, 11, 12, 7}. We aim to create bouquets with k, which is 3 adjacent flowers, and we need to make m, which is 2 such bouquets. Now, if we try to make bouquets on the 11th day, the first 4 flowers and the 6th and the last flowers would have bloomed. So, we will be having 6 flowers in total on the 11th day. However, we require two groups of 3 adjacent flowers each. Although we can form one group with the first 3 adjacent flowers, we cannot create a second group. Therefore, 11 is not the answer in this case.

If we choose the 12th day, we can make 2 such groups, one with the first 3 adjacent flowers and the other with the last 3 adjacent flowers. Hence, we need a minimum of 12 days to make 2 bouquets.

Observation: 

Impossible case: To create m bouquets with k adjacent flowers each, we require a minimum of m*k flowers in total. If the number of flowers in the array, represented by array-size, is less than m*k, it becomes impossible to form m bouquets even after all the flowers have bloomed. In such cases, where array-size < m*k, we should return -1.
 Maximum possible answer: The maximum potential answer corresponds to the time needed for all the flowers to bloom. In other words, it is the highest value within the given array i.e. max(arr[]).
Minimum possible answer: The minimum potential answer corresponds to the time needed for atleast one flower to bloom. In other words, it is the smallest value within the given array i.e. min(arr[]).
Note: From the above observations, we can conclude that our answer lies between the range [min(arr[]), max(arr[])].

How to calculate the number of bouquets we can make on dth day:

We will count the number of adjacent bloomed flowers(say cnt) and whenever we get a flower that is not bloomed, we will add the number of bouquets we can make with ‘cnt’ adjacent flowers i.e. floor(cnt/k) to the answer. We will follow the process throughout the array. 

Now, we will write a function possible(), that will return true if, on a certain day, we can make at least m bouquets otherwise it will return false. The steps will be the following:

possible(arr[], day, m, k) algorithm:

We will declare two variables i.e. ‘cnt’ and ‘noOfB’.
cnt -> the number of adjacent flowers,
noOfB -> the number of bouquets.
We will run a loop to traverse the array.
Inside the loop, we will do the following:
If arr[i] <= day: This means the ith flower has bloomed. So, we will increase the number of adjacent flowers i.e. ‘cnt’ by 1.
Otherwise, the flower has not bloomed. Here, we will calculate the number of bouquets we can make with ‘cnt’ adjacent flowers i.e. floor(cnt/k), and add it to the noOfB. Now, as this ith flower breaks the sequence of the adjacent bloomed flowers, we will set the ‘cnt’ 0.
Lastly, outside the loop, we will calculate the floor(cnt/k) and add it to the noOfB.
If noOfB >= m: This means, we can make at least m bouquets. So, we will return true.
Otherwise, We will return false.
Note: We actually pass a particular day as a parameter to the possible() function. The function returns true if it is possible to make atleast m bouquets on that particular day, otherwise, it returns false.

  


#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}


Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Reason: We are running a loop to check our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
Let's perform a detailed **line-by-line dry run** of the code for the input:

```cpp
vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
int k = 3;
int m = 2;
```

The goal is to determine the earliest day when K bouquets can be made, where each bouquet consists of `k` consecutive roses that bloom on or before a certain day.

### Step-by-Step Dry Run

#### **Initial Setup in `main()`**
- **Line 30**: The array of blooming days `arr` is initialized as `{7, 7, 7, 7, 13, 11, 12, 7}`.
- **Line 31**: `k = 3`, which means each bouquet must have 3 consecutive roses.
- **Line 32**: `m = 2`, which means we need to make 2 bouquets.
- **Line 33**: We call `roseGarden(arr, k, m)` to calculate the earliest day when this can happen.

#### **Inside `roseGarden`**

- **Line 12**: The function `roseGarden` is called with `arr = {7, 7, 7, 7, 13, 11, 12, 7}`, `k = 3`, and `m = 2`.
- **Line 13**: Compute the total number of flowers needed to make `m` bouquets with `k` flowers each:
  ```cpp
  long long val = m * 1ll * k * 1ll = 2 * 1ll * 3 * 1ll = 6
  ```
  This means that at least 6 flowers are needed in total to make 2 bouquets of 3 flowers each.
- **Line 14**: The size of the array `n = arr.size()` is `8`, which means there are 8 roses in the garden.
- **Line 15**: If the total number of required flowers (`val = 6`) is greater than the number of roses in the garden (`n = 8`), it would be impossible to make the bouquets. But in this case, `6 <= 8`, so we proceed.

#### **Find the Minimum and Maximum Days**

- **Lines 17-20**: We now loop through `arr` to find the minimum (`mini`) and maximum (`maxi`) bloom days.
  - Initialize `mini = INT_MAX` and `maxi = INT_MIN`.
  - For each element `arr[i]`:
    - `i = 0`: `arr[0] = 7` → `mini = min(INT_MAX, 7) = 7`, `maxi = max(INT_MIN, 7) = 7`
    - `i = 1`: `arr[1] = 7` → `mini = min(7, 7) = 7`, `maxi = max(7, 7) = 7`
    - `i = 2`: `arr[2] = 7` → `mini = min(7, 7) = 7`, `maxi = max(7, 7) = 7`
    - `i = 3`: `arr[3] = 7` → `mini = min(7, 7) = 7`, `maxi = max(7, 7) = 7`
    - `i = 4`: `arr[4] = 13` → `mini = min(7, 13) = 7`, `maxi = max(7, 13) = 13`
    - `i = 5`: `arr[5] = 11` → `mini = min(7, 11) = 7`, `maxi = max(13, 11) = 13`
    - `i = 6`: `arr[6] = 12` → `mini = min(7, 12) = 7`, `maxi = max(13, 12) = 13`
    - `i = 7`: `arr[7] = 7` → `mini = min(7, 7) = 7`, `maxi = max(13, 7) = 13`

  At the end of the loop, `mini = 7` and `maxi = 13`. This means the earliest possible bloom day is 7, and the latest bloom day is 13.

#### **Loop Through the Days**
- **Line 22**: Now, we loop from `mini = 7` to `maxi = 13` to find the earliest day when we can make at least `m = 2` bouquets.

#### **First Iteration (day = 7)**

- **Line 23**: For `day = 7`, we call `possible(arr, 7, m, k)`.

##### Inside `possible(arr, 7, m, k)`
- **Line 4**: The array `arr = {7, 7, 7, 7, 13, 11, 12, 7}`, `day = 7`, `m = 2`, `k = 3`.
- **Line 5**: Initialize variables `cnt = 0` (to count consecutive flowers) and `noOfB = 0` (to count the number of bouquets made).
- **Loop through the array**:
  - **i = 0**: `arr[0] = 7` ≤ `day = 7`, so `cnt++` → `cnt = 1`.
  - **i = 1**: `arr[1] = 7` ≤ `day = 7`, so `cnt++` → `cnt = 2`.
  - **i = 2**: `arr[2] = 7` ≤ `day = 7`, so `cnt++` → `cnt = 3` → `noOfB += (cnt / k) = 1`, reset `cnt = 0`.
  - **i = 3**: `arr[3] = 7` ≤ `day = 7`, so `cnt++` → `cnt = 1`.
  - **i = 4**: `arr[4] = 13` > `day = 7`, so `noOfB += (cnt / k) = 0`, reset `cnt = 0`.
  - **i = 5**: `arr[5] = 11` > `day = 7`, so no action.
  - **i = 6**: `arr[6] = 12` > `day = 7`, so no action.
  - **i = 7**: `arr[7] = 7` ≤ `day = 7`, so `cnt++` → `cnt = 1`.

- **End of Loop**: We add the final batch of flowers: `noOfB += (cnt / k) = 0`.
- **Return**: The number of bouquets made is `noOfB = 1`, which is less than `m = 2`, so return `false`.

#### **Second Iteration (day = 8)**

- **Line 23**: For `day = 8`, we call `possible(arr, 8, m, k)`.
- The process inside `possible` will be the same as above since no flowers bloom at day 8.

  The result will be the same: `false`.

#### **Third Iteration (day = 9, 10, 11)**

- For days 9, 10, and 11, the result of `possible(arr, day, m, k)` will also be `false`, as Koko cannot make enough bouquets.

#### **Fourth Iteration (day = 12)**

- **Line 23**: For `day = 12`, we call `possible(arr, 12, m, k)`.

##### Inside `possible(arr, 12, m, k)`
- **Line 4**: The array `arr = {7, 7, 7, 7, 13, 11, 12, 7}`, `day = 12`, `m = 2`, `k = 3`.
- **Loop through the array**:
  - **i = 0 to i = 3**: The first four roses bloom by day 12, and we make 1 bouquet.
  - **i = 4**: `arr[4] = 13`, so no action.
  - **i = 5**: `arr[5] = 11`, counts for the second bouquet.
  - We successfully make 2 bouquets.
  
The result will be `true`.

---

### Final Result:
At `day = 12`, we can make the required 2 bouquets, so the output will be:

```
We can make bouquets on day 12
```


#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}

Complexity Analysis
Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Reason: We are running a loop to check our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
  Let's walk through the provided code step-by-step, breaking down how it works, particularly focusing on the function of each part, especially the `roseGarden` function and the `possible` helper function.

### Overview

The code aims to determine the earliest day on which Koko can make `m` bouquets of flowers, where each bouquet requires `k` consecutive flowers. Each flower blooms on a specific day.

### Key Functions

1. **`possible`**: Checks if it's feasible to create at least `m` bouquets by a given day.
2. **`roseGarden`**: Uses binary search to find the earliest possible day to create the bouquets.

### Dry Run with Given Input

Let's dry run the code using the example:

```cpp
vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
int k = 3; // flowers per bouquet
int m = 2; // number of bouquets needed
```

### Step-by-Step Execution

#### 1. **Main Function**

- **Line 30**: The `main` function initializes `arr`, `k`, and `m`.
- **Line 31**: Calls `roseGarden(arr, k, m)`.

#### 2. **Inside `roseGarden`**

- **Line 12**: Initializes `val`:
  ```cpp
  long long val = m * 1ll * k * 1ll; // val = 2 * 3 = 6
  ```
- **Line 13**: Gets the size of `arr`:
  ```cpp
  int n = arr.size(); // n = 8
  ```
- **Line 14**: Checks if making the bouquets is possible:
  ```cpp
  if (val > n) return -1; // 6 > 8 is false, so continue
  ```

#### 3. **Finding Minimum and Maximum Bloom Days**

- **Lines 17-20**: Initialize `mini` and `maxi`:
  ```cpp
  int mini = INT_MAX, maxi = INT_MIN;
  ```
- **Loop to find min and max bloom days**:
  - `arr[0] = 7` → `mini = 7`, `maxi = 7`
  - `arr[1] = 7` → `mini = 7`, `maxi = 7`
  - `arr[2] = 7` → `mini = 7`, `maxi = 7`
  - `arr[3] = 7` → `mini = 7`, `maxi = 7`
  - `arr[4] = 13` → `mini = 7`, `maxi = 13`
  - `arr[5] = 11` → `mini = 7`, `maxi = 13`
  - `arr[6] = 12` → `mini = 7`, `maxi = 13`
  - `arr[7] = 7` → `mini = 7`, `maxi = 13`

At the end of this loop:
- `mini = 7`
- `maxi = 13`

#### 4. **Binary Search to Find the Earliest Day**

- **Line 23**: Initializes binary search:
  ```cpp
  int low = mini, high = maxi; // low = 7, high = 13
  ```
- **While Loop (Binary Search)**:
  - **First Iteration**:
    - `mid = (7 + 13) / 2 = 10`
    - Call `possible(arr, 10, m, k)`

#### 5. **Inside `possible(arr, 10, m, k)`**

- **Line 4**: Initializes variables:
  ```cpp
  int cnt = 0, noOfB = 0; // cnt = 0, noOfB = 0
  ```
- **Loop through `arr`**:
  - **i = 0**: `arr[0] = 7` ≤ 10 → `cnt++` → `cnt = 1`
  - **i = 1**: `arr[1] = 7` ≤ 10 → `cnt++` → `cnt = 2`
  - **i = 2**: `arr[2] = 7` ≤ 10 → `cnt++` → `cnt = 3` → `noOfB += (cnt / k) = 1`, reset `cnt = 0`
  - **i = 3**: `arr[3] = 7` ≤ 10 → `cnt++` → `cnt = 1`
  - **i = 4**: `arr[4] = 13` > 10 → `noOfB += (cnt / k) = 0`, reset `cnt = 0`
  - **i = 5**: `arr[5] = 11` > 10 → no action.
  - **i = 6**: `arr[6] = 12` > 10 → no action.
  - **i = 7**: `arr[7] = 7` ≤ 10 → `cnt++` → `cnt = 1`.

- **End of Loop**: Add remaining `cnt`:
  ```cpp
  noOfB += (cnt / k) = 0
  ```

- **Final Bouquets Count**: `noOfB = 1`, which is less than `m = 2`, so return `false`.

#### **Back to `roseGarden`**

- **Update Search Range**: Since `possible` returned `false`, update:
  ```cpp
  low = mid + 1; // low = 11
  ```

- **Second Iteration**:
  - `mid = (11 + 13) / 2 = 12`
  - Call `possible(arr, 12, m, k)`

##### Inside `possible(arr, 12, m, k)`

- **Loop through `arr`**:
  - **i = 0 to i = 3**: Count flowers, and complete first bouquet (`noOfB = 1`).
  - **i = 4**: No action (`13 > 12`).
  - **i = 5**: Count flowers for second bouquet (`noOfB = 2`).

- **Final Count**: `noOfB = 2`, which is equal to `m`, so return `true`.

#### **Back to `roseGarden` Again**

- **Update Search Range**: Since `possible` returned `true`:
  ```cpp
  high = mid - 1; // high = 11
  ```

- **Third Iteration**:
  - `mid = (11 + 11) / 2 = 11`
  - Call `possible(arr, 11, m, k)`

##### Inside `possible(arr, 11, m, k)`

- Similar process as before:
  - Count flowers and create 2 bouquets → `noOfB = 2`.

#### **Final Result**

- **Back to `roseGarden`**: 
  - `possible` returns `true`, so:
  ```cpp
  high = mid - 1; // high = 10
  ```

- The while loop ends since `low > high`.

- **Return the value**: `return low; // low = 12`.

### Output

- Back in `main()`, `ans` will be `12`. So it outputs:
```
We can make bouquets on day 12
```

### Conclusion

The program effectively uses a binary search combined with a helper function to determine the earliest day on which Koko can make the required bouquets based on the blooming days of the flowers.
  The time complexity is efficient due to the use of binary search and the linear scan within the `possible` function.
