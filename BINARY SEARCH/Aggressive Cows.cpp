Aggressive Cows 
Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 

Why do we need to sort the stalls?

To arrange the cows in a consecutive manner while ensuring a certain distance between them, the initial step is to sort the stalls based on their positions. In a sorted array, the minimum distance will always be obtained from any two consecutive cows. Arranging the cows in a consecutive manner does not necessarily mean placing them in consecutive stalls.

Assume the given stalls array is: {1,2,8,4,9} and after sorting it will be {1, 2, 4, 8, 9}. The given number of cows is 3.



We have to fit three cows in these 5 stalls. Each stall can accommodate only one. Our task is to maximize the minimum distance between two stalls. Let’s look at some arrangements:







In the first arrangement, the minimum distance between the cows is 1. Now, in the later cases, we have tried to place the cows in a manner so that the minimum distance can be increased. This is done in the second and third cases. It’s not possible to get a minimum distance of more than 3 in any arrangement, so we output 3. 

Observation:

Minimum possible distance between 2 cows: The minimum possible distance between two cows is 1 as the minimum distance between 2 consecutive stalls is 1.
Maximum possible distance between 2 cows: The maximum possible distance between two cows is = max(stalls[])-min(stalls[]). This case occurs when we place 2 cows at two ends of the sorted stalls array.
From the observations, we can conclude that our answer lies in the range 
[1, max(stalls[])-min(stalls[])].

How to place cows with maintaining a certain distance, ‘dist’, in the sorted stalls:

To begin, we will position the first cow in the very first stall. Next, we will iterate through the array, starting from the second stall. If the distance between the current stall and the last stall where a cow was placed is greater than or equal to the value 'dist', we will proceed to place the next cow in the current stall. Thus we will try to place the cows and finally, we will check if we have placed all the cows maintaining the distance, ‘dist’.

To serve this purpose, we will write a function canWePlace() that takes the distance, ‘dist’, as a parameter and returns true if we can place all the cows maintaining a minimum distance of ‘dist’. Otherwise, it returns false.

canWePlace(stalls[], dist, k):

We will declare two variables, ‘cntCows’ and ‘last’. ‘cntCows’ will store the number of cows placed, and ‘last’ will store the position of the last placed cow.
First, we will place the first cow in the very first stall. So, we will set ‘cntCows’ to 1 and ‘last’ to stall[0].
Then, using a loop we will start iterating the array from index 1. Inside the loop, we will do the following:
If stalls[i] - ‘last’ >= dist: This means the current stall is at least ‘dist’ distance away from the last stall. So, we can place the next cow here. We will increase the value ‘cntCows’ by 1 and set ‘last’ to the current stall.
If cntCows >= k: This means we have already placed k cows with maintaining the minimum distance ‘dist’. So, we will return true from this step.
If we are outside the loop, we cannot place k cows with a minimum distance of ‘dist’. So, we will return false.


brute force



#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++) {
        if (canWePlace(stalls, i, k) == false) {
            return (i - 1);
        }
    }
    return limit;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

Complexity Analysis
Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are using a loop from 1 to max(stalls[])-min(stalls[]) to check all possible distances. Inside the loop, we are calling canWePlace() function for each distance. Now, inside the canWePlace() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Let's go through the dry run of the code step by step, for an input of `stalls = {0, 3, 4, 7, 10, 9}` and `k = 4` (the number of cows to be placed).

### Initial Setup:
```cpp
vector<int> stalls = {0, 3, 4, 7, 10, 9}; // The stall positions where cows can be placed.
int k = 4; // The number of cows to place.
```

### Step-by-Step Dry Run:

#### **Main Function (`aggressiveCows`)**

1. **Sorting the stalls:**
   - First, the `stalls` array is sorted:
   ```cpp
   sort(stalls.begin(), stalls.end());
   ```
   - After sorting, `stalls` becomes: `{0, 3, 4, 7, 9, 10}`.

2. **Calculating the limit:**
   ```cpp
   int limit = stalls[n - 1] - stalls[0];
   ```
   - `stalls[n - 1]` is `stalls[5] = 10`, and `stalls[0] = 0`, so the limit is `10 - 0 = 10`. This is the maximum possible distance between two cows.

3. **Looping through distances from 1 to `limit`:**
   ```cpp
   for (int i = 1; i <= limit; i++) {
       if (canWePlace(stalls, i, k) == false) {
           return (i - 1);
       }
   }
   ```
   - The loop starts from `i = 1`, which represents the minimum distance between two cows, and goes up to `i = 10`. In each iteration, it checks if it's possible to place all cows with a minimum distance of `i` using the `canWePlace` function.
   
#### **canWePlace Function**

The function checks if we can place `k = 4` cows with at least `i` distance between them.

##### **For `i = 1`:**

- The first cow is placed at the first stall (`stalls[0] = 0`), so `last = 0`, and `cntCows = 1` (1 cow placed).
- The loop then checks if the next cow can be placed at each subsequent stall:
  - For `stalls[1] = 3`: `3 - 0 >= 1`, so the cow is placed at `3`. Now, `cntCows = 2` and `last = 3`.
  - For `stalls[2] = 4`: `4 - 3 >= 1`, so the cow is placed at `4`. Now, `cntCows = 3` and `last = 4`.
  - For `stalls[3] = 7`: `7 - 4 >= 1`, so the cow is placed at `7`. Now, `cntCows = 4` and `last = 7`.
  - Since `cntCows = 4` (we've placed all cows), it returns `true`.

##### **For `i = 2`:**

- First cow is placed at `stalls[0] = 0`.
- For `stalls[1] = 3`: `3 - 0 >= 2`, so the cow is placed at `3`.
- For `stalls[2] = 4`: `4 - 3 < 2`, so no cow is placed.
- For `stalls[3] = 7`: `7 - 3 >= 2`, so the cow is placed at `7`.
- For `stalls[4] = 9`: `9 - 7 >= 2`, so the cow is placed at `9`.
- Now, `cntCows = 4`, so the function returns `true`.

##### **For `i = 3`:**

- First cow is placed at `stalls[0] = 0`.
- For `stalls[1] = 3`: `3 - 0 >= 3`, so the cow is placed at `3`.
- For `stalls[2] = 4`: `4 - 3 < 3`, so no cow is placed.
- For `stalls[3] = 7`: `7 - 3 >= 3`, so the cow is placed at `7`.
- For `stalls[4] = 9`: `9 - 7 < 3`, so no cow is placed.
- For `stalls[5] = 10`: `10 - 7 >= 3`, so the cow is placed at `10`.
- Now, `cntCows = 4`, so the function returns `true`.

##### **For `i = 4`:**

- First cow is placed at `stalls[0] = 0`.
- For `stalls[1] = 3`: `3 - 0 < 4`, so no cow is placed.
- For `stalls[2] = 4`: `4 - 0 < 4`, so no cow is placed.
- For `stalls[3] = 7`: `7 - 0 >= 4`, so the cow is placed at `7`.
- For `stalls[4] = 9`: `9 - 7 < 4`, so no cow is placed.
- For `stalls[5] = 10`: `10 - 7 < 4`, so no cow is placed.
- Now, `cntCows = 2` (less than 4 cows placed), so it returns `false`.

### Final Result:

- Since placing cows at `i = 4` is not possible, the loop exits and returns `i - 1`, which is `3`.
- So, the maximum possible minimum distance between cows is `3`.

### Output:
```
The maximum possible minimum distance is: 3

```

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

Output:The maximum possible minimum distance is: 3.

Complexity Analysis
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. Now, inside the canWePlace() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem
