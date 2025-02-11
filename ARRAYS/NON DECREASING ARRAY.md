https://leetcode.com/problems/non-decreasing-array/description/

https://www.naukri.com/code360/problems/non-decreasing-array_699920?interviewBundleRedirection=true

---

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& N) {
        for (int i = 1, err = 0; i < N.size(); i++)
            if (N[i] < N[i-1])
                if (err++ || (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1]))
                    return false;
        return true;
    }
};

```
---

```cpp

#include <bits/stdc++.h> 
bool isPossible(int *arr, int n)
{
    int err = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) { 
            if (err++ || (i > 1 && i < n - 1 && arr[i-2] > arr[i] && arr[i+1] < arr[i-1])) 
                return false;
        }
    }
    return true;
}



```
