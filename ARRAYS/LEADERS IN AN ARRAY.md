https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

https://www.naukri.com/code360/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse


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
