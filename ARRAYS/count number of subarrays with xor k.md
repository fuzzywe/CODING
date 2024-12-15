
https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

https://www.interviewbit.com/problems/subarray-with-given-xor/


```cpp




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}



```

---

better

```cpp




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}




```

---

optimal

```cpp




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

```

Let's break this code down in a simpler way. I'll explain step-by-step, assuming little prior knowledge, so you can understand how it works.

---

### Goal:
We want to count how many subarrays in the array have an XOR value equal to `k`.

---

### Key Concept: **XOR**
- XOR is a bitwise operation. For example:
  - `2 ^ 3 = 1` because `2 = 10` in binary, and `3 = 11`, so `10 XOR 11 = 01`.
- XOR has a special property:
  - If `a ^ b = c`, then `a = b ^ c` and `b = a ^ c`.  
  - This property is very useful to find subarrays with a given XOR.

---

### What is the Code Doing?
1. **`xr`: Running XOR**
   - We keep track of the XOR of all elements from the start up to the current position. This is called the **running XOR**.
   - Example: For array `[4, 2, 2, 6, 4]`, the running XOR will be:
     - After `4`: `4`
     - After `4 ^ 2`: `6`
     - After `6 ^ 2`: `4`
     - After `4 ^ 6`: `2`
     - After `2 ^ 4`: `6`

2. **`mpp`: Map (or Hash Table)**
   - This map keeps track of how many times a specific XOR value has appeared so far.
   - Why? If a certain XOR has already appeared, it means there is a subarray between the previous occurrence and the current position whose XOR matches the desired `k`.

3. **`cnt`: Counter**
   - We use `cnt` to count how many subarrays satisfy the condition: XOR of the subarray = `k`.

---

### Dry Run Explanation

We will analyze the code line-by-line for the input:

**Array:** `a = [4, 2, 2, 6, 4]`  
**k:** `6`

---

#### Initial Setup:
1. `xr = 0`: Initialize the running XOR to 0.
2. `mpp = {0: 1}`: The map starts with `{0: 1}` because we need to count subarrays starting at the beginning.
3. `cnt = 0`: No subarrays found yet.

---

#### Loop Iterations:

##### **Iteration 1 (i = 0):**
- Current element: `a[0] = 4`
- Update `xr = xr ^ a[0] = 0 ^ 4 = 4`.
- Compute `x = xr ^ k = 4 ^ 6 = 2`.
- Check the map: `mpp[2] = 0` → No subarray found.
- Update map: Add `xr = 4` to `mpp`, so `mpp = {0: 1, 4: 1}`.

---

##### **Iteration 2 (i = 1):**
- Current element: `a[1] = 2`
- Update `xr = xr ^ a[1] = 4 ^ 2 = 6`.
- Compute `x = xr ^ k = 6 ^ 6 = 0`.
- Check the map: `mpp[0] = 1` → Subarray found (from the start to here).
- Update `cnt = cnt + 1 = 1`.
- Update map: Add `xr = 6` to `mpp`, so `mpp = {0: 1, 4: 1, 6: 1}`.

---

##### **Iteration 3 (i = 2):**
- Current element: `a[2] = 2`
- Update `xr = xr ^ a[2] = 6 ^ 2 = 4`.
- Compute `x = xr ^ k = 4 ^ 6 = 2`.
- Check the map: `mpp[2] = 0` → No subarray found.
- Update map: Add `xr = 4` to `mpp`, so `mpp = {0: 1, 4: 2, 6: 1}`.

---

##### **Iteration 4 (i = 3):**
- Current element: `a[3] = 6`
- Update `xr = xr ^ a[3] = 4 ^ 6 = 2`.
- Compute `x = xr ^ k = 2 ^ 6 = 4`.
- Check the map: `mpp[4] = 2` → Two subarrays found!
- Update `cnt = cnt + 2 = 3`.
- Update map: Add `xr = 2` to `mpp`, so `mpp = {0: 1, 4: 2, 6: 1, 2: 1}`.

---

##### **Iteration 5 (i = 4):**
- Current element: `a[4] = 4`
- Update `xr = xr ^ a[4] = 2 ^ 4 = 6`.
- Compute `x = xr ^ k = 6 ^ 6 = 0`.
- Check the map: `mpp[0] = 1` → Subarray found (from the start to here).
- Update `cnt = cnt + 1 = 4`.
- Update map: Add `xr = 6` to `mpp`, so `mpp = {0: 1, 4: 2, 6: 2, 2: 1}`.

---

#### Final Result:
- The total count of subarrays with XOR `k` is `cnt = 4`.

---

### How the Subarrays are Counted:
The subarrays with XOR `6` are:
1. `[4, 2]` (indices 0–1).
2. `[6]` (index 3).
3. `[4, 2, 2, 6]` (indices 0–3).
4. `[6, 4]` (indices 3–4).

---

### Output:
```
The number of subarrays with XOR k is: 4
```
