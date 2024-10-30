https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

https://www.naukri.com/code360/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

```cpp
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
  int maxi = INT_MIN;
        vector<int>ans;
      
        for(int i=n-1; i>=0; i--){
          if (a[i] > maxi) {
            ans.push_back(a[i]);
          }
          maxi = max(maxi,a[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
}
```

Array Leaders
Difficulty: EasyAccuracy: 29.94%Submissions: 754K+Points: 2
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.


**OPTIMAL SOLUTION**


Simply Traverse the array from rightside of the array.

Create a mx variable and initialize it with a[n-1]. 

```cpp
mx=a[n-1]

```
And create a new ans vector, and push this mx variable in ans vector. 

```cpp

vector<int>ans;
ans.push_back(mx);

```
Now we have to check for every element that is greater than or equal to the current mx variable. 

If current element is less than mx variable, then skip this element, so we continue from there. 

```cpp
for(int i=n-2; i>=0; i--){
   if(a[i]<mx) continue;
}
```
Now we have to add condition for element that is greater than or equal to current mx. 

If current element greater than or equal to mx then update the mx variable and push that element in the vector. 

```cpp
for(int i=n-2; i>=0; i--){
  if(a[i]<mx) continue;
  mx=a[i]; 
  ans.push_back(mx);
}

```
Now finally we have to reverse the array, bcz we have to return the array from left to right, and our ans vector has the traversal from right to left. 

reverse(ans.begin(), ans.end());


```cpp
class Solution{
    public:
    vector<int> leaders(int a[], int n){
        int mx=a[n-1];
        vector<int>ans;
        ans.push_back(mx);
        for(int i=n-2; i>=0; i--){
            if(a[i]<mx)
            continue;
            mx=a[i];
            ans.push_back(mx);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

```
Let’s go through a detailed dry run of this code, line by line, using a sample array to help understand each step.

Suppose we have an input array:
```cpp
a = [16, 17, 4, 3, 5, 2]
n = 6
```

The purpose of the function is to find all **leaders** in the array. A "leader" is an element that is greater than all the elements to its right.

### Code Walkthrough

```cpp
vector<int> leaders(int a[], int n) {
```

- The function `leaders` takes two parameters:
  - `a[]`: the input array.
  - `n`: the number of elements in the array.

#### Step 1: Initialize `mx` to the Last Element

```cpp
int mx = a[n-1];
```

- `mx` is initialized to the last element of the array. In our example:
  ```cpp
  mx = a[5] = 2
  ```

#### Step 2: Initialize `ans` Vector and Add the Last Element

```cpp
vector<int> ans;
ans.push_back(mx);
```

- A vector `ans` is created to store the leaders. We initially push the last element (`mx`) into `ans` because, by definition, the last element is always a leader.

- After this line:
  ```cpp
  ans = [2]
  ```

#### Step 3: Loop Through the Array from Right to Left

```cpp
for(int i = n - 2; i >= 0; i--) {
```

- We start a loop from the second last element (`i = n - 2`) and move to the beginning of the array (`i >= 0`).

#### Step 4: Check if `a[i]` is Greater Than or Equal to `mx`

```cpp
if(a[i] < mx) continue;
```

- For each element `a[i]`, we check if it’s smaller than `mx`. If it is, we skip to the next element (`continue`).

- If `a[i]` is **greater than or equal to `mx`**, we update `mx` to `a[i]` and push `mx` to `ans` as it qualifies as a leader.

Let’s go through each iteration in the loop:

1. **Iteration 1 (`i = 4`):** `a[4] = 5`
   - **Check**: `a[4] = 5` (greater than `mx = 2`)
   - **Update**: `mx = 5`
   - **Push to `ans`**: `ans = [2, 5]`

2. **Iteration 2 (`i = 3`):** `a[3] = 3`
   - **Check**: `a[3] = 3` (less than `mx = 5`)
   - **Skip**: `continue` to the next iteration.

3. **Iteration 3 (`i = 2`):** `a[2] = 4`
   - **Check**: `a[2] = 4` (less than `mx = 5`)
   - **Skip**: `continue` to the next iteration.

4. **Iteration 4 (`i = 1`):** `a[1] = 17`
   - **Check**: `a[1] = 17` (greater than `mx = 5`)
   - **Update**: `mx = 17`
   - **Push to `ans`**: `ans = [2, 5, 17]`

5. **Iteration 5 (`i = 0`):** `a[0] = 16`
   - **Check**: `a[0] = 16` (less than `mx = 17`)
   - **Skip**: `continue` to the next iteration.

#### Step 5: Reverse `ans` to Maintain Left-to-Right Order

```cpp
reverse(ans.begin(), ans.end());
```

- The leaders were added in reverse order, so reversing `ans` gives the correct left-to-right order.

- After reversing:
  ```cpp
  ans = [17, 5, 2]
  ```

#### Final Result

The function returns the `ans` vector, which contains the leaders `[17, 5, 2]`.

### Summary of Output

For the input `[16, 17, 4, 3, 5, 2]`, the output of the function is:

```cpp
[17, 5, 2]
```

### Complexity

- **Time Complexity**: \(O(n)\) because we are only looping through the array once.
- **Space Complexity**: \(O(n)\) for the `ans` vector, which stores the leaders.
--- 

BRUTE FORCE 

```cpp
vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

```
