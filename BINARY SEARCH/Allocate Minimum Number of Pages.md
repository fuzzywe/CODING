Allocate Minimum Number of Pages
Example 1:
Input Format:
 n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result:
 113
Explanation:
 The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

We can allocate books in several ways but it is clearly said in the question that we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.

Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate these books in different ways. Some of them are the following:

25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71
From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.

When it is impossible to allocate books:

When the number of books is lesser than the number of students, we cannot allocate books to all the students even if we give only a single book to each student. So, if m > n, we should return -1.

Observations:

Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
Maximum possible answer: We will get the maximum answer when we give all n books to a single student. The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).
From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].

How to calculate the number of students to whom we can allocate the books if one can receive at most ‘pages’ number of pages:

In order to calculate the number of students we will write a function, countStudents(). This function will take the array and ‘pages’ as parameters and return the number of students to whom we can allocate the books.

countStudents(arr[], pages):

We will first declare two variables i.e. ‘students’(stores the no. of students), and pagesStudent(stores the number of pages of a student). As we are starting with the first student, ‘students’ should be initialized with 1.
We will start traversing the given array.
If pagesStudent + arr[i] <= pages: If upon adding the pages with the existing number of pages does not exceed the limit, we can allocate this i-th book to the current student.
Otherwise, we will move to the next student(i.e. students += 1 ) and allocate the book.
Finally, we will return the value of ‘students’.

brute force:

```cpp

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
```
Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible numbers of pages. Inside the loop, we are calling the countStudents() function for each number. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.

Let’s perform a dry run of the code with the input `stalls = {0, 3, 4, 7, 10, 9}` and `k = 4` (number of cows to place).

### Initial Setup:

```cpp
vector<int> stalls = {0, 3, 4, 7, 10, 9};
int k = 4;
```

1. **Sorting the stalls array:**
   ```cpp
   sort(stalls.begin(), stalls.end());
   ```
   After sorting, `stalls = {0, 3, 4, 7, 9, 10}`.

### Aggressive Cows Algorithm (Binary Search)

2. **Initialize `low` and `high`:**
   ```cpp
   int low = 1, high = stalls[n - 1] - stalls[0];
   ```
   - `n = 6` (size of the stalls array).
   - `low = 1` (minimum possible distance between cows).
   - `high = stalls[n - 1] - stalls[0] = 10 - 0 = 10` (maximum possible distance between cows).

3. **Binary Search loop (while `low <= high`):**
   ```cpp
   while (low <= high) {
       int mid = (low + high) / 2;
       if (canWePlace(stalls, mid, k) == true) {
           low = mid + 1;
       }
       else high = mid - 1;
   }
   ```

### Iteration 1 (Binary Search):
- `mid = (1 + 10) / 2 = 5`.

#### **canWePlace Function (for `mid = 5`)**

This function checks if we can place `k = 4` cows with at least a minimum distance of `5` units between them.

- Initialize `cntCows = 1` (placed first cow at `stalls[0] = 0`) and `last = 0` (last position of a cow).
- Loop through the rest of the stalls:
  - `stalls[1] = 3`: `3 - 0 < 5` → No cow placed.
  - `stalls[2] = 4`: `4 - 0 < 5` → No cow placed.
  - `stalls[3] = 7`: `7 - 0 >= 5` → Cow placed at `stalls[3]`, `cntCows = 2`, `last = 7`.
  - `stalls[4] = 9`: `9 - 7 < 5` → No cow placed.
  - `stalls[5] = 10`: `10 - 7 < 5` → No cow placed.

- `cntCows = 2` (less than 4 cows placed), so it returns `false`.

- Since the function returned `false`, update `high = mid - 1 = 5 - 1 = 4`.

### Iteration 2 (Binary Search):
- `mid = (1 + 4) / 2 = 2`.

#### **canWePlace Function (for `mid = 2`)**

This function checks if we can place `4` cows with at least `2` units of distance between them.

- Initialize `cntCows = 1` (placed first cow at `stalls[0] = 0`) and `last = 0`.
- Loop through the rest of the stalls:
  - `stalls[1] = 3`: `3 - 0 >= 2` → Cow placed at `stalls[1]`, `cntCows = 2`, `last = 3`.
  - `stalls[2] = 4`: `4 - 3 >= 2` → Cow placed at `stalls[2]`, `cntCows = 3`, `last = 4`.
  - `stalls[3] = 7`: `7 - 4 >= 2` → Cow placed at `stalls[3]`, `cntCows = 4`, `last = 7`.

- `cntCows = 4` (we've placed all cows), so it returns `true`.

- Since the function returned `true`, update `low = mid + 1 = 2 + 1 = 3`.

### Iteration 3 (Binary Search):
- `mid = (3 + 4) / 2 = 3`.

#### **canWePlace Function (for `mid = 3`)**

This function checks if we can place `4` cows with at least `3` units of distance between them.

- Initialize `cntCows = 1` (placed first cow at `stalls[0] = 0`) and `last = 0`.
- Loop through the rest of the stalls:
  - `stalls[1] = 3`: `3 - 0 >= 3` → Cow placed at `stalls[1]`, `cntCows = 2`, `last = 3`.
  - `stalls[2] = 4`: `4 - 3 < 3` → No cow placed.
  - `stalls[3] = 7`: `7 - 3 >= 3` → Cow placed at `stalls[3]`, `cntCows = 3`, `last = 7`.
  - `stalls[4] = 9`: `9 - 7 >= 3` → Cow placed at `stalls[4]`, `cntCows = 4`, `last = 9`.

- `cntCows = 4` (we've placed all cows), so it returns `true`.

- Since the function returned `true`, update `low = mid + 1 = 3 + 1 = 4`.

### Iteration 4 (Binary Search):
- `mid = (4 + 4) / 2 = 4`.

#### **canWePlace Function (for `mid = 4`)**

This function checks if we can place `4` cows with at least `4` units of distance between them.

- Initialize `cntCows = 1` (placed first cow at `stalls[0] = 0`) and `last = 0`.
- Loop through the rest of the stalls:
  - `stalls[1] = 3`: `3 - 0 < 4` → No cow placed.
  - `stalls[2] = 4`: `4 - 0 < 4` → No cow placed.
  - `stalls[3] = 7`: `7 - 0 >= 4` → Cow placed at `stalls[3]`, `cntCows = 2`, `last = 7`.
  - `stalls[4] = 9`: `9 - 7 < 4` → No cow placed.
  - `stalls[5] = 10`: `10 - 7 < 4` → No cow placed.

- `cntCows = 2` (less than 4 cows placed), so it returns `false`.

- Since the function returned `false`, update `high = mid - 1 = 4 - 1 = 3`.

### Exit Binary Search:

Since `low > high` (`4 > 3`), the binary search loop terminates, and we return `high = 3`.

### Output:

```cpp
cout << "The maximum possible minimum distance is: " << ans << "\n";
```

The maximum possible minimum distance between cows is `3`.

**Output:**
```
The maximum possible minimum distance is: 3
```
---
  
**optimal solution:**

```cpp

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
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
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
```
Output:The answer is: 71.

Complexity Analysis
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.

Let's perform a dry run of the given code with the input:

- `arr = {25, 46, 28, 49, 24}`
- `n = 5` (number of books)
- `m = 4` (number of students)

### Step-by-Step Dry Run:

1. **Initial Setup**:
   - The `findPages` function is called with `arr = {25, 46, 28, 49, 24}`, `n = 5`, and `m = 4`.
   - Check if book allocation is impossible. Since `m = 4` is not greater than `n = 5`, proceed further.

2. **Setting `low` and `high`**:
   - `low` is set to the maximum element of the array, which is `max(arr) = 49`.
   - `high` is set to the sum of the array elements, `sum(arr) = 25 + 46 + 28 + 49 + 24 = 172`.

3. **First Iteration** (`low = 49`, `high = 172`):
   - Calculate `mid = (low + high) / 2 = (49 + 172) / 2 = 110`.
   - Call `countStudents(arr, 110)`:
     - Allocate books to the first student:
       - 25 pages → total = 25.
       - 46 pages → total = 71.
       - 28 pages → total = 99.
       - Next, 49 pages can't fit within 110, so move to the next student:
       - Second student gets 49 pages → total = 49.
       - Next, 24 pages can fit, so total = 73.
     - In total, 2 students are used.
   - Since 2 students ≤ 4, set `high = mid - 1 = 109`.

4. **Second Iteration** (`low = 49`, `high = 109`):
   - Calculate `mid = (low + high) / 2 = (49 + 109) / 2 = 79`.
   - Call `countStudents(arr, 79)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages → total = 71.
       - 28 pages doesn't fit, so move to the next student:
       - Second student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Third student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fourth student gets 24 pages → total = 24.
     - In total, 4 students are used.
   - Since 4 students ≤ 4, set `high = mid - 1 = 78`.

5. **Third Iteration** (`low = 49`, `high = 78`):
   - Calculate `mid = (low + high) / 2 = (49 + 78) / 2 = 63`.
   - Call `countStudents(arr, 63)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages doesn't fit, so move to the next student:
       - Second student gets 46 pages → total = 46.
       - 28 pages doesn't fit, so move to the next student:
       - Third student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Fourth student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fifth student gets 24 pages → total = 24.
     - In total, 5 students are used.
   - Since 5 students > 4, set `low = mid + 1 = 64`.

6. **Fourth Iteration** (`low = 64`, `high = 78`):
   - Calculate `mid = (low + high) / 2 = (64 + 78) / 2 = 71`.
   - Call `countStudents(arr, 71)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages → total = 71.
       - 28 pages doesn't fit, so move to the next student:
       - Second student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Third student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fourth student gets 24 pages → total = 24.
     - In total, 4 students are used.
   - Since 4 students ≤ 4, set `high = mid - 1 = 70`.

7. **Fifth Iteration** (`low = 64`, `high = 70`):
   - Calculate `mid = (low + high) / 2 = (64 + 70) / 2 = 67`.
   - Call `countStudents(arr, 67)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages doesn't fit, so move to the next student:
       - Second student gets 46 pages → total = 46.
       - 28 pages doesn't fit, so move to the next student:
       - Third student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Fourth student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fifth student gets 24 pages → total = 24.
     - In total, 5 students are used.
   - Since 5 students > 4, set `low = mid + 1 = 68`.

8. **Sixth Iteration** (`low = 68`, `high = 70`):
   - Calculate `mid = (low + high) / 2 = (68 + 70) / 2 = 69`.
   - Call `countStudents(arr, 69)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages doesn't fit, so move to the next student:
       - Second student gets 46 pages → total = 46.
       - 28 pages doesn't fit, so move to the next student:
       - Third student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Fourth student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fifth student gets 24 pages → total = 24.
     - In total, 5 students are used.
   - Since 5 students > 4, set `low = mid + 1 = 70`.

9. **Seventh Iteration** (`low = 70`, `high = 70`):
   - Calculate `mid = (low + high) / 2 = (70 + 70) / 2 = 70`.
   - Call `countStudents(arr, 70)`:
     - First student:
       - 25 pages → total = 25.
       - 46 pages → total = 71.
       - 28 pages doesn't fit, so move to the next student:
       - Second student gets 28 pages → total = 28.
       - 49 pages doesn't fit, so move to the next student:
       - Third student gets 49 pages → total = 49.
       - 24 pages doesn't fit, so move to the next student:
       - Fourth student gets 24 pages → total = 24.
     - In total, 4 students are used.
   - Since 4 students ≤ 4, set `high = mid - 1 = 69`.

### Conclusion:
- The binary search terminates when `low` exceeds `high`. The final value of `low` is 70, which is the minimum number of pages a student needs to read such that the books are allocated to 4 students.

Thus, the answer is `70`.
