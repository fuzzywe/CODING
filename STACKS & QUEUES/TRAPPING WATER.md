42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 1-21 screenshot](https://github.com/user-attachments/assets/5005ba36-19a2-4b7c-8956-a5336c15bd31)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 2-10 screenshot](https://github.com/user-attachments/assets/5f05d93b-b52f-4787-8d4a-3957e8fb8485)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 3-49 screenshot](https://github.com/user-attachments/assets/f51feac6-97aa-48ec-8b56-217132b11531)


 
 ![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 3-45 screenshot](https://github.com/user-attachments/assets/d83cf380-a7f3-43a4-883c-be823f9e4fff)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 6-14 screenshot](https://github.com/user-attachments/assets/2cd91f32-63fc-4c22-b301-af697d9b1f68)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 8-1 screenshot](https://github.com/user-attachments/assets/d7c8933d-d574-4126-9b1b-44c4af1a2508)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 10-21 screenshot](https://github.com/user-attachments/assets/4828f7d2-2c62-4dc4-8091-eb848f3e40d2)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 12-53 screenshot](https://github.com/user-attachments/assets/65a5f146-f6db-4ac4-9791-af90ac29ba62)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 13-28 screenshot](https://github.com/user-attachments/assets/52710d87-5e35-4772-a58e-d1c36f4a5faa)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 18-41 screenshot](https://github.com/user-attachments/assets/d5caeb48-a873-41b0-b4db-c7b8c2dc2dbe)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 19-12 screenshot](https://github.com/user-attachments/assets/f1dd164f-74f6-4c05-b65b-269ecc095f71)


![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 21-30 screenshot](https://github.com/user-attachments/assets/22462a88-58d2-4dcd-821e-61cb193a2159)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 25-29 screenshot](https://github.com/user-attachments/assets/4dec3370-ee8c-4640-9db1-236b4841360e)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 28-31 screenshot](https://github.com/user-attachments/assets/23ed0f79-3c08-4bd1-b958-81a8f25d9942)

![L8  Trapping Rainwater _ 2 Approaches _ Stack and Queue Playlist 27-59 screenshot](https://github.com/user-attachments/assets/b928eabf-6166-448a-a464-bfd8b3852d24)

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

**BRUTE APPROACH**
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
     
  int n = height.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, height[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, height[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - height[i];
  }
  return waterTrapped;
}

    };

```

raise an error tle

Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.

Space Complexity: O(1).



**BETTER APPROACH**

 ```cpp
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}
```
int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
Output: The water that can be trapped is 6

Time Complexity: O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.

Space Complexity: O(N)+O(N) for prefix and suffix arrays.



---

**OPTIMAL SOLUTION**

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;

    }
};
```


Output: The water that can be trapped is 6

Time Complexity: O(N) because we are using 2 pointer approach.

Space Complexity: O(1) because we are not using anything extra.

+++
