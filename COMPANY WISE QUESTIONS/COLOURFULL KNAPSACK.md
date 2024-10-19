https://www.naukri.com/code360/problems/colorful-knapsack_630415?ieSlug=samsung-interview-experience-by-anubhav-jain-on-campus-dec-2019-16&ieCompany=samsung&leftPanelTabValue=PROBLEM

Problem statement
You are given 'N' stones labeled from 1 to 'N'. The 'i-th' stone has the weight W[i]. There are 'M' colors labeled by integers from 1 to 'M'. The 'i-th' stone has the color C[i] which is an integer between 1 to 'M', both inclusive.

You have been required to fill a Knapsack with these stones. The Knapsack can hold a total weight of 'X'.

You are required to select exactly 'M' stones; one of each color. The sum of the weights of the stones must not exceed 'X'. Since you paid a premium for a Knapsack with capacity 'X', you are required to fill the Knapsack as much as possible.

Write a program to calculate the best way to fill the Knapsack - that is, the unused capacity should be minimized.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= M <= N <= 100
1 <= X <= 10000
1 <= W[i] <= 100
1 <= C[i] <= M

Time Limit: 1 sec
Sample Input 1:
3 3 5
1 1 1
1 2 3
Sample Output 1:
2
Explanation of Sample Input 1:
We have three stones of each color and hence, we have to select it and in turn, we get a total weight equal to 1 + 1 + 1 = 3. So the minimum unused capacity is 5 - 3 = 2.
Sample Input 2:
8 3 13
2 3 4 2 4 5 2 3
1 1 1 2 2 2 3 3
Sample Output 2:
1
Explanation of Sample Input 2:
We can choose the stone with:
1. Colour as 1 and with Weight 4, 
2. Colour as 2 and with Weight 5, and
3. Colour as 3 and with Weight 3 

So we a total weight 4 + 5 + 3 = 12. Hence the minimum unused capacity is 13 - 12 = 1.

We cannot get weight more than 12 with any other combination.

```cpp

#include<bits/stdc++.h>
int solve(vector<vector<int>> &v, int i, int m, int x, vector<vector<int>> &dp){
    if(i==m){
        return 0;
    }
    if(dp[i][x]!=-2){
        return dp[i][x];
    }
    int ans=-1;
    for(int k: v[i]){
        if((x-k)>=0){
            int a = solve(v, i+1, m, x-k, dp);
            if(a!=-1){
                ans = max(ans, k+a);
            }
        }
    }
    return dp[i][x]=ans;
}
int colorfulKnapsack(int w[], int c[], int n, int m, int x){
    vector<vector<int>> v(m);
    for(int i=0; i<n; i++){
        v[c[i]-1].push_back(w[i]);
    }
    vector<vector<int>> dp(m, vector<int>(x+1, -2));
    sort(v.begin(), v.end());
	int a = solve(v, 0, m, x, dp);
    if(a==-1){
        return a;
    }
    return x-a;
}


```

Let's go through the **dry run** for each line of the code based on the inputs:

```cpp
w[] = {2, 3, 4, 5}
c[] = {1, 2, 1, 2}
n = 4
m = 2
x = 6
```

### `colorfulKnapsack` function:

1. **Line 1: `vector<vector<int>> v(m);`**
   - Creates a 2D vector `v` with `m=2` rows to store the weights based on color groups.

2. **Line 2-4: `for(int i=0; i<n; i++){ v[c[i]-1].push_back(w[i]); }`**
   - Groups weights by their colors:
     - For `i = 0`, `w[0] = 2`, `c[0] = 1` → Add weight 2 to color group 1: `v = [[2], []]`.
     - For `i = 1`, `w[1] = 3`, `c[1] = 2` → Add weight 3 to color group 2: `v = [[2], [3]]`.
     - For `i = 2`, `w[2] = 4`, `c[2] = 1` → Add weight 4 to color group 1: `v = [[2, 4], [3]]`.
     - For `i = 3`, `w[3] = 5`, `c[3] = 2` → Add weight 5 to color group 2: `v = [[2, 4], [3, 5]]`.

3. **Line 5: `vector<vector<int>> dp(m, vector<int>(x+1, -2));`**
   - Initializes a DP table `dp` of size `m x (x+1) = 2 x 7` with all values set to `-2`.
   - `dp = [[-2, -2, -2, -2, -2, -2, -2], [-2, -2, -2, -2, -2, -2, -2]]`.

4. **Line 6: `sort(v.begin(), v.end());`**
   - Sorts the color groups, though in this case, they are already sorted: `v = [[2, 4], [3, 5]]`.

5. **Line 7: `int a = solve(v, 0, m, x, dp);`**
   - Calls the `solve` function starting from color `i = 0`, with the total number of colors `m = 2` and the knapsack capacity `x = 6`.

---

### `solve` function (recursive call stack):

6. **First call: `solve(v, 0, m, 6, dp)`**
   - **Line 1: `if(i==m) return 0;`** → `i != m` (i.e., `i = 0`), so continue.
   - **Line 2: `if(dp[i][x] != -2) return dp[i][x];`** → `dp[0][6] = -2`, so continue.
   - **Line 3: `int ans = -1;`** → Initialize `ans = -1`.
   - **Line 4: `for(int k: v[i])`** → Start iterating over weights in color group 1 (`v[0] = [2, 4]`).

7. **First inner iteration: Try `k = 2` (first weight of color group 1)**
   - **Line 5: `if((x-k) >= 0)`** → Check if `6 - 2 >= 0` (True), so continue.
   - **Line 6: `int a = solve(v, i+1, m, 6-2, dp);`** → Call `solve(v, 1, 2, 4, dp)` for the next color with remaining capacity 4.

---

8. **Second call: `solve(v, 1, m, 4, dp)`**
   - **Line 1: `if(i==m) return 0;`** → `i != m` (i.e., `i = 1`), so continue.
   - **Line 2: `if(dp[i][x] != -2) return dp[i][x];`** → `dp[1][4] = -2`, so continue.
   - **Line 3: `int ans = -1;`** → Initialize `ans = -1`.
   - **Line 4: `for(int k: v[i])`** → Start iterating over weights in color group 2 (`v[1] = [3, 5]`).

9. **First inner iteration: Try `k = 3` (first weight of color group 2)**
   - **Line 5: `if((x-k) >= 0)`** → Check if `4 - 3 >= 0` (True), so continue.
   - **Line 6: `int a = solve(v, i+1, m, 4-3, dp);`** → Call `solve(v, 2, 2, 1, dp)` for the next color with remaining capacity 1.

---

10. **Third call: `solve(v, 2, m, 1, dp)`**
    - **Line 1: `if(i==m) return 0;`** → `i == m` (i.e., `i = 2`), so return 0.
    - This indicates that no more colors are left to choose from, so the total weight chosen so far is valid and return 0.

11. **Back to second call: Update result with `k = 3`**
    - **Line 7: `if(a != -1)` → `a = 0`, so update `ans = max(-1, 3 + 0) = 3`.**
    - **Line 8: `dp[i][x] = ans` → `dp[1][4] = 3`.**

12. **Second inner iteration: Try `k = 5` (second weight of color group 2)**
    - **Line 5: `if((x-k) >= 0)`** → Check if `4 - 5 >= 0` (False), so skip this iteration.

13. **Back to first call: Update result with `k = 2`**
    - **Line 7: `if(a != -1)` → `a = 3`, so update `ans = max(-1, 2 + 3) = 5`.**

14. **Second inner iteration: Try `k = 4` (second weight of color group 1)**
    - **Line 5: `if((x-k) >= 0)`** → Check if `6 - 4 >= 0` (True), so continue.
    - **Line 6: `int a = solve(v, i+1, m, 6-4, dp);`** → Call `solve(v, 1, 2, 2, dp)` for the next color with remaining capacity 2.

---

15. **New second call: `solve(v, 1, m, 2, dp)`**
    - **Line 1: `if(i==m) return 0;`** → `i != m` (i.e., `i = 1`), so continue.
    - **Line 2: `if(dp[i][x] != -2) return dp[i][x];`** → `dp[1][2] = -2`, so continue.
    - **Line 3: `int ans = -1;`** → Initialize `ans = -1`.
    - **Line 4: `for(int k: v[i])`** → Start iterating over weights in color group 2 (`v[1] = [3, 5]`).

16. **First inner iteration: Try `k = 3` (first weight of color group 2)**
    - **Line 5: `if((x-k) >= 0)`** → Check if `2 - 3 >= 0` (False), so skip.

17. **Second inner iteration: Try `k = 5` (second weight of color group 2)**
    - **Line 5: `if((x-k) >= 0)`** → Check if `2 - 5 >= 0` (False), so skip.

18. **End of new second call: Update `dp[1][2] = -1` because no valid solution.**

19. **Back to first call: Update result with `k = 4`**
    - **Line 7: `if(a != -1)` → `a = -1`, so skip this update.**
    - **Line 8: `dp[i][x] = ans` → `dp[0][6] = 5`.**

---

### Final Result:

The function `colorfulKnapsack` returns `x - a = 6 - 5 = 1`. Hence, the remaining capacity in the knapsack is `1`, and the maximum weight that can be packed while choosing one item per color is `5`.

### DP Table after execution:
```
dp = [[-

2, -2, -2, -2, -2, -2, 5],
      [-2, -2,  -1,  -2, 3, -2, -2]]
```
