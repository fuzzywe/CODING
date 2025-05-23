https://www.naukri.com/code360/problems/three-sum_6922132?interviewBundleRedirection=true&leftPanelTabValue=PROBLEM

https://leetcode.com/problems/3sum/

https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


 https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
 


First, we will declare a set data structure as we want unique triplets.
Then we will use the first loop(say i) that will run from 0 to n-1.
BRUTE FORCE
  Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
Then there will be the third loop(say k) that runs from j+1 to n-1.
Now, inside these 3 nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k], and if it is equal to the target i.e. 0 we will sort this triplet and insert it in the set data structure.
Finally, we will return the list of triplets stored in the set data structure.
Note: For a better understanding of intuition, please watch the video at the bottom of the page.


```cpp


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

```
Output: [-1 -1 2 ] [-1 0 1 ]
Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.

---

 ```cpp



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
```
Complexity Analysis
Time Complexity: O(NlogN)+O(N2), where N = size of the array.
Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).



---
```cpp
class Solution {
  public:
    // Function to find if there exists a triplet in the
    // array arr[] which sums up to the target.
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        int l, r;

        // Sorting the elements.
        sort(arr.begin(), arr.end());

        // Traversing the array elements.
        for (int i = 0; i < n - 2; i++) {
            // Taking two pointers. One at element after ith index and another
            // at the last index.
            l = i + 1;
            r = n - 1;
            while (l < r) {
                // If sum of elements at indexes i, l and r is equal
                // to the target, we return true.
                if (arr[i] + arr[l] + arr[r] == target)
                    return true;
                // Else if the sum is less than the target, we increase the left pointer
                // l.
                else if (arr[i] + arr[l] + arr[r] < target)
                    l++;
                // Else the sum is more than the target, so we decrease the right
                // pointer r.
                else
                    r--;
            }
        }

        // Returning false if no triplet sum equal to the target is present.
        return false;
    }
};

```

---

other optimal soln

---

```cpp

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size(); // Get the size of the array
        for (int i = 0; i < n - 2; i++) {
            // Find pair in subarray arr[i+1..n-1] with sum equal to target - arr[i]
            unordered_set<int> s;
            int curr_sum = target - arr[i];
            for (int j = i + 1; j < n; j++) {
                if (s.find(curr_sum - arr[j]) != s.end()) {
                    return true;
                }
                s.insert(arr[j]);
            }
        }

        // If no triplet is found
        return false;
    }
};

```
