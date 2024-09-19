painters partition problem

similar to minimum book allocation

Example 1:
Input Format:
 N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result:
 10
Explanation:
 We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
Input Format:
 N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result:
 60
Explanation:
 We can divide the first 3 boards for one painter and the last board for the second painter.

We can allocate the boards to the painters in several ways but it is clearly said in the question that we have to allocate the boards in such a way that the painters can paint all the boards in the minimum possible time. The painters will work simultaneously.

Note: Upon close observation, we can understand that this problem is similar to the previous problem: BS-18. Allocate Books or Book Allocation | Hard Binary Search. There we had to allocate books to the students and here we need to allocate walls to the painters.

Assume the given array is {10, 20, 30, 40} and number of painters, k = 2. Now, we can allocate these boards in different ways. Some of them are the following:

10 | 20, 30, 40  → Minimum time required to paint all the boards  = 90
10, 20 | 30, 40  → Minimum time required to paint all the boards = 70
10, 20, 30 | 40  → Minimum time required to paint all the boards = 60
From the above allocations, we can clearly observe that in the last case, the first painter will paint the first 3 walls in 60 units of time and the second painter will take 40 units of time. So, the minimum time required to paint all the boards is 60.

Observations:

Minimum possible answer: We will get the minimum answer when we give n boards of the array to n painters(i.e. Each painter will be allocated 1 board). Now, in this case, the minimum time required to paint all the boards will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
Maximum possible answer: We will get the maximum answer when we give all n boards to a single painter. The total time required is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).
From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].

How to calculate the number of painters we need if we have to paint all the walls within ‘time’ units of time:

In order to calculate the number of painters we will write a function, countPainters(). This function will take the array and ‘time’ as parameters and return the number of painters to whom we can allocate the boards.

countPainters(arr[], time):

  We will first declare two variables i.e. ‘painters’(stores the no. of painters), and ‘boardsPainter’(stores the unit of boards, a painter will paint). As we are starting with the first painter, ‘painters’ should be initialized with 1.
We will start traversing the given array.
If boardsPainter + arr[i] <= time: If upon adding the current board with ‘boardsPainter’ does not exceed the time limit, we can allocate this i-th board to the current painter.
Otherwise, we will move to the next painter(i.e. painters += 1 ) and allocate the i-th board.
Finally, we will return the value of ‘painters’.


  


#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}




We will first declare two variables i.e. ‘painters’(stores the no. of painters), and ‘boardsPainter’(stores the unit of boards, a painter will paint). As we are starting with the first painter, ‘painters’ should be initialized with 1.
We will start traversing the given array.
If boardsPainter + arr[i] <= time: If upon adding the current board with ‘boardsPainter’ does not exceed the time limit, we can allocate this i-th board to the current painter.
Otherwise, we will move to the next painter(i.e. painters += 1 ) and allocate the i-th board.
Finally, we will return the value of ‘painters’.

  Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPainters() function for each number. Now, inside the countPainters() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.

Let's walk through a detailed dry run of the code for the given input:

- **boards = {10, 20, 30, 40}**
- **k = 2** (number of painters)

### Main Function:

```cpp
vector<int> boards = {10, 20, 30, 40};
int k = 2;
int ans = findLargestMinDistance(boards, k);
cout << "The answer is: " << ans << "\n";
```

1. A vector `boards = {10, 20, 30, 40}` is defined, representing the lengths of the boards to be painted.
2. `k = 2` means there are 2 painters available.
3. The `findLargestMinDistance` function is called with `boards` and `k` as arguments.
4. The answer `ans` is printed at the end.

Now, let's break down the `findLargestMinDistance` function step by step.

---

### `findLargestMinDistance` Function:

```cpp
int low = *max_element(boards.begin(), boards.end());
int high = accumulate(boards.begin(), boards.end(), 0);
```

1. **Find `low`**: 
   - `low = *max_element(boards.begin(), boards.end())` finds the largest board, which is `40`.
   - This is because the painter with the longest board must spend at least this amount of time painting it, no matter how you allocate the boards.

2. **Find `high`**:
   - `high = accumulate(boards.begin(), boards.end(), 0)` computes the total sum of all the boards, which is `10 + 20 + 30 + 40 = 100`.
   - This represents the total time if one painter had to paint all the boards.

So, `low = 40` and `high = 100`.

---

### Main Loop (`for` loop):

```cpp
for (int time = low; time <= high; time++) {
    if (countPainters(boards, time) <= k) {
        return time;
    }
}
```

The loop runs from `time = low` (40) to `time = high` (100), checking for each `time` value whether it's possible to paint all the boards with at most `k = 2` painters.

For each value of `time`, the `countPainters` function is called to determine how many painters are needed if they have `time` as their maximum allowable time.

---

### `countPainters` Function:

```cpp
int countPainters(vector<int> &boards, int time) {
    int n = boards.size();
    int painters = 1;  // start with one painter
    long long boardsPainter = 0;  // tracks time for the current painter
```

1. Start with 1 painter (`painters = 1`) and `boardsPainter = 0` (time spent by the current painter).

2. Loop through each board:

```cpp
for (int i = 0; i < n; i++) {
    if (boardsPainter + boards[i] <= time) {
        boardsPainter += boards[i];
    }
    else {
        painters++;
        boardsPainter = boards[i];
    }
}
```

This loop tries to allocate as many boards as possible to the current painter. If adding another board exceeds the `time` limit, it assigns a new painter and starts counting from the next board.

---

### Dry Run for Specific `time` Values:

We'll try some values of `time` to see how `countPainters` works.

1. **First iteration (`time = 40`)**:

    - `painters = 1`, `boardsPainter = 0`.
    - Process boards:
        - Board 1 (10): `boardsPainter = 10`.
        - Board 2 (20): `boardsPainter = 30`.
        - Board 3 (30): Exceeds 40, so assign a new painter:
            - `painters = 2`, `boardsPainter = 30`.
        - Board 4 (40): Exceeds 40, so assign a new painter:
            - `painters = 3`, `boardsPainter = 40`.
    - **Painters used = 3**.
    - Since 3 > 2, this `time` value is too small.

2. **Next iteration (`time = 50`)**:

    - `painters = 1`, `boardsPainter = 0`.
    - Process boards:
        - Board 1 (10): `boardsPainter = 10`.
        - Board 2 (20): `boardsPainter = 30`.
        - Board 3 (30): Exceeds 50, so assign a new painter:
            - `painters = 2`, `boardsPainter = 30`.
        - Board 4 (40): Exceeds 50, so assign a new painter:
            - `painters = 3`, `boardsPainter = 40`.
    - **Painters used = 3**.
    - Still too many painters.

3. **Try `time = 60`**:

    - `painters = 1`, `boardsPainter = 0`.
    - Process boards:
        - Board 1 (10): `boardsPainter = 10`.
        - Board 2 (20): `boardsPainter = 30`.
        - Board 3 (30): `boardsPainter = 60`.
        - Board 4 (40): Exceeds 60, so assign a new painter:
            - `painters = 2`, `boardsPainter = 40`.
    - **Painters used = 2**.
    - Since 2 <= 2, we have a valid solution. The function returns `time = 60`.

---

### Final Output:

Thus, the minimum largest time for any painter is `60`. The output is:

```
The answer is: 60
```

### Conclusion:
- The `findLargestMinDistance` function finds the minimum time in which all the boards can be painted by exactly 2 painters, with the largest time any painter spends being minimized to `60`.


  

  


#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPainters() function for the value of ‘mid’. Now, inside the countPainters() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
