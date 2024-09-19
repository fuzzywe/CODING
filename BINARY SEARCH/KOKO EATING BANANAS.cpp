Koko Eating Bananas


132

0
Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

Examples
Example 1:
Input Format:
 N = 4, a[] = {7, 15, 6, 3}, h = 8
Result:
 5
Explanation:
 If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  

Example 2:
Input Format:
 N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Result:
 25
Explanation:
 If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.


Before moving on to the solution, let’s understand how Koko will eat the bananas. Assume, the given array is {3, 6, 7, 11} and the given time i.e. h is 8. 

First of all, Koko cannot eat bananas from different piles. He should complete the pile he has chosen and then he can go for another pile.
Now, Koko decides to eat 2 bananas/hour. So, in order to complete the first he will take
3 / 2 = 2 hours. Though mathematically, he should take 1.5 hrs but it is clearly stated in the question that after completing a pile Koko will not consume more bananas in that hour. So, for the first pile, Koko will eat 2 bananas in the first hour and then he will consume 1 banana in another hour. 
From here we can conclude that we have to take ceil of (3/2). Similarly, we will calculate the times for other piles.

1st pile: ceil(3/2) = 2 hrs
2nd pile: ceil(6/2) = 3 hrs
3rd pile: ceil(7/2) = 4 hrs
4th pile: ceil(11/2) = 6 hrs
Koko will take 15 hrs in total to consume all the bananas from all the piles. 

Observation: Upon observation, it becomes evident that the maximum number of bananas (represented by 'k') that Koko can consume in an hour is obtained from the pile that contains the largest quantity of bananas. Therefore, the maximum value of 'k' corresponds to the maximum element present in the given array.

So, our answer i.e. the minimum value of ‘k’ lies between 1 and the maximum element in the array i.e. max(a[]).

Now, let’s move on to the solution.
  


#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

Complexity Analysis
Time Complexity: O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are running nested loops. The outer loop runs for max(a[]) times in the worst case and the inner loop runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

  Let’s walk through a detailed dry run of this code to understand how it works.

### Problem Breakdown:
You are trying to find the minimum eating rate `k` (bananas per hour) such that Koko can finish all the piles of bananas within `h` hours.

Given:
- `v = {7, 15, 6, 3}` (number of bananas in each pile)
- `h = 8` (total hours available)

Koko should eat at a rate that ensures she finishes all the bananas in these piles within the given `h` hours.

---

### **Main Function:**

```cpp
vector<int> v = {7, 15, 6, 3};
int h = 8;
int ans = minimumRateToEatBananas(v, h);
cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
```

1. A vector `v = {7, 15, 6, 3}` represents the number of bananas in each pile.
2. `h = 8` represents the number of hours Koko has to finish eating all the bananas.
3. The `minimumRateToEatBananas` function is called with `v` and `h` as arguments.
4. The answer `ans` is printed at the end.

---

### **`minimumRateToEatBananas` Function:**

```cpp
int maxi = findMax(v);
```

1. **Find the maximum number of bananas in a pile**:
   - This is done by calling the `findMax` function, which will find the largest value in `v`. 
   - For `v = {7, 15, 6, 3}`, the maximum pile is `15`.

2. **Loop to find the minimum eating rate**:
   - Now, the function will iterate over potential eating rates, `i`, from 1 to the maximum pile size `maxi = 15`. 
   - For each rate `i`, it checks how long Koko will take to finish all the bananas by calling `calculateTotalHours`.

---

### **`findMax` Function:**

```cpp
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
```

This function iterates through the vector `v` to find the maximum number of bananas in any pile.

For `v = {7, 15, 6, 3}`:
- Iteration 1: `maxi = max(INT_MIN, 7) = 7`
- Iteration 2: `maxi = max(7, 15) = 15`
- Iteration 3: `maxi = max(15, 6) = 15`
- Iteration 4: `maxi = max(15, 3) = 15`

The maximum number of bananas is `15`.

---

### **`calculateTotalHours` Function:**

```cpp
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}
```

This function calculates how long it will take Koko to eat all the bananas if she eats at the rate of `hourly` bananas per hour.

For each pile, it calculates the hours required by dividing the number of bananas by the hourly rate and using `ceil` to round up since Koko cannot eat part of a banana.

---

### **Dry Run for Each Iteration**:

Let’s step through the loop in `minimumRateToEatBananas`:

---

1. **`i = 1` (Eating rate: 1 banana per hour)**:

   Call `calculateTotalHours(v, 1)`:

   - Pile 1 (7 bananas): `ceil(7/1) = 7 hours`
   - Pile 2 (15 bananas): `ceil(15/1) = 15 hours`
   - Pile 3 (6 bananas): `ceil(6/1) = 6 hours`
   - Pile 4 (3 bananas): `ceil(3/1) = 3 hours`
   
   Total hours = `7 + 15 + 6 + 3 = 31 hours`

   Since 31 hours > 8 hours, eating 1 banana per hour is too slow.

---

2. **`i = 2` (Eating rate: 2 bananas per hour)**:

   Call `calculateTotalHours(v, 2)`:

   - Pile 1 (7 bananas): `ceil(7/2) = 4 hours`
   - Pile 2 (15 bananas): `ceil(15/2) = 8 hours`
   - Pile 3 (6 bananas): `ceil(6/2) = 3 hours`
   - Pile 4 (3 bananas): `ceil(3/2) = 2 hours`
   
   Total hours = `4 + 8 + 3 + 2 = 17 hours`

   Since 17 hours > 8 hours, eating 2 bananas per hour is still too slow.

---

3. **`i = 3` (Eating rate: 3 bananas per hour)**:

   Call `calculateTotalHours(v, 3)`:

   - Pile 1 (7 bananas): `ceil(7/3) = 3 hours`
   - Pile 2 (15 bananas): `ceil(15/3) = 5 hours`
   - Pile 3 (6 bananas): `ceil(6/3) = 2 hours`
   - Pile 4 (3 bananas): `ceil(3/3) = 1 hour`
   
   Total hours = `3 + 5 + 2 + 1 = 11 hours`

   Since 11 hours > 8 hours, eating 3 bananas per hour is still too slow.

---

4. **`i = 4` (Eating rate: 4 bananas per hour)**:

   Call `calculateTotalHours(v, 4)`:

   - Pile 1 (7 bananas): `ceil(7/4) = 2 hours`
   - Pile 2 (15 bananas): `ceil(15/4) = 4 hours`
   - Pile 3 (6 bananas): `ceil(6/4) = 2 hours`
   - Pile 4 (3 bananas): `ceil(3/4) = 1 hour`
   
   Total hours = `2 + 4 + 2 + 1 = 9 hours`

   Since 9 hours > 8 hours, eating 4 bananas per hour is still too slow.

---

5. **`i = 5` (Eating rate: 5 bananas per hour)**:

   Call `calculateTotalHours(v, 5)`:

   - Pile 1 (7 bananas): `ceil(7/5) = 2 hours`
   - Pile 2 (15 bananas): `ceil(15/5) = 3 hours`
   - Pile 3 (6 bananas): `ceil(6/5) = 2 hours`
   - Pile 4 (3 bananas): `ceil(3/5) = 1 hour`
   
   Total hours = `2 + 3 + 2 + 1 = 8 hours`

   Since 8 hours ≤ 8 hours, Koko can finish all the bananas at a rate of 5 bananas per hour.

---

### **Final Output**:

The function returns `5` as the minimum rate at which Koko can eat all the bananas within 8 hours. 

Thus, the output is:

```
Koko should eat atleast 5 bananas/hr.
```


  #include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

Output: Koko should eat atleast 5 bananas/hr.

Complexity Analysis
Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

Space Complexity: O(1) as we are not using any extra space to solve this problem.
  Let's break down the modified version of your code and walk through its logic step by step, including a dry run.

### Problem:

The task is to find the **minimum rate** `k` (bananas per hour) such that Koko can finish eating all the banana piles in exactly `h` hours or less. The piles are stored in the vector `v`, and Koko needs to finish them within `h` hours.

### Approach:

The solution now uses **binary search** to optimize the process of finding the minimum rate `k`. Instead of checking every possible rate linearly, binary search is used to efficiently search the possible rates from `1` to the maximum number of bananas in any pile.

---

### Code Walkthrough:

#### **`findMax` Function:**

```cpp
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
```

This function finds the maximum number of bananas in any pile. For `v = {7, 15, 6, 3}`, the maximum pile is `15`. This value will be the upper bound (`high`) for the binary search range.

---

#### **`calculateTotalHours` Function:**

```cpp
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}
```

This function calculates how many hours Koko will take to finish all the piles if she eats at a rate of `hourly` bananas per hour. The use of `ceil` ensures that any fractional bananas (incomplete pile) are counted as a full hour.

---

#### **`minimumRateToEatBananas` Function:**

```cpp
int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}
```

- **Initial Setup**:
  - `low = 1`: This is the smallest possible rate (Koko eats 1 banana per hour).
  - `high = findMax(v) = 15`: This is the largest possible rate (Koko eats as fast as the biggest pile).

- **Binary Search**:
  - The binary search runs while `low <= high`.
  - At each iteration, the midpoint (`mid`) is calculated: `mid = (low + high) / 2`.
  - We compute how many hours it would take to eat all the bananas if Koko eats `mid` bananas per hour using `calculateTotalHours(v, mid)`.

- **Adjust the Search Space**:
  - If the total hours `totalH <= h` (Koko can finish within the allowed time), reduce the search space by moving the upper bound `high = mid - 1`.
  - Otherwise, increase the lower bound `low = mid + 1`.

- **Return**:
  - Once the loop ends, `low` will be the minimum rate `k` at which Koko can finish all the bananas within `h` hours.

---

### Dry Run Example:

Input:
- `v = {7, 15, 6, 3}` (banana piles)
- `h = 8` (available hours)

#### Initial Binary Search Range:
- `low = 1`, `high = 15`

---

1. **First Iteration**:
   - `mid = (1 + 15) / 2 = 8`
   - Call `calculateTotalHours(v, 8)`:
     - Pile 1 (7 bananas): `ceil(7/8) = 1 hour`
     - Pile 2 (15 bananas): `ceil(15/8) = 2 hours`
     - Pile 3 (6 bananas): `ceil(6/8) = 1 hour`
     - Pile 4 (3 bananas): `ceil(3/8) = 1 hour`
     - Total hours = `1 + 2 + 1 + 1 = 5 hours`
   - Since 5 hours <= 8 hours, Koko can eat at this rate. Adjust `high = mid - 1 = 7`.

---

2. **Second Iteration**:
   - `mid = (1 + 7) / 2 = 4`
   - Call `calculateTotalHours(v, 4)`:
     - Pile 1 (7 bananas): `ceil(7/4) = 2 hours`
     - Pile 2 (15 bananas): `ceil(15/4) = 4 hours`
     - Pile 3 (6 bananas): `ceil(6/4) = 2 hours`
     - Pile 4 (3 bananas): `ceil(3/4) = 1 hour`
     - Total hours = `2 + 4 + 2 + 1 = 9 hours`
   - Since 9 hours > 8 hours, Koko cannot finish in time. Adjust `low = mid + 1 = 5`.

---

3. **Third Iteration**:
   - `mid = (5 + 7) / 2 = 6`
   - Call `calculateTotalHours(v, 6)`:
     - Pile 1 (7 bananas): `ceil(7/6) = 2 hours`
     - Pile 2 (15 bananas): `ceil(15/6) = 3 hours`
     - Pile 3 (6 bananas): `ceil(6/6) = 1 hour`
     - Pile 4 (3 bananas): `ceil(3/6) = 1 hour`
     - Total hours = `2 + 3 + 1 + 1 = 7 hours`
   - Since 7 hours <= 8 hours, Koko can eat at this rate. Adjust `high = mid - 1 = 5`.

---

4. **Fourth Iteration**:
   - `mid = (5 + 5) / 2 = 5`
   - Call `calculateTotalHours(v, 5)`:
     - Pile 1 (7 bananas): `ceil(7/5) = 2 hours`
     - Pile 2 (15 bananas): `ceil(15/5) = 3 hours`
     - Pile 3 (6 bananas): `ceil(6/5) = 2 hours`
     - Pile 4 (3 bananas): `ceil(3/5) = 1 hour`
     - Total hours = `2 + 3 + 2 + 1 = 8 hours`
   - Since 8 hours <= 8 hours, Koko can eat at this rate. Adjust `high = mid - 1 = 4`.

---

### **Result**:
- Now, `low = 5` and `high = 4`, so the loop terminates.
- The minimum rate `k = 5` bananas per hour.

### Output:
```
Koko should eat atleast 5 bananas/hr.
```

This is the final result, meaning Koko needs to eat at least 5 bananas per hour to finish within the 8 hours.
