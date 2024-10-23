995. Minimum Number of K Consecutive Bit Flips
Hard
Topics
Companies
You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
Example 2:

Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
Example 3:

Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

---

Complexity
Time complexity:o(n)
Space complexity:o(1)
Code

```cpp
class Solution {
public:
     int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;  // This will keep track of the number of flips performed
        int j = 0;  // This will be used to track if the current position is flipped

        for (int i = 0; i < n; i++) {
            // If we've passed the first k elements, we need to check if the position i - k was flipped
            if (i >= k) {
                // If nums[i - k] was flipped, we toggle j
                if (nums[i - k] == 2) {
                    j ^= 1;
                }
            }

            // If we're in a position where we can still flip k bits (i.e., within the bounds)
            if ((nums[i] ^ j) == 0) {
                // If after accounting for previous flips, nums[i] is 0, we need to flip
                if (i + k > n) {
                    // If flipping would go out of bounds, it's impossible to flip the remaining bits
                    return -1;
                }

                // Perform the flip
                flips++;
                j ^= 1;  // Toggle j to indicate the flip
                nums[i] = 2;  // Mark the current position as flipped
            }
        }

        return flips;
    }
};
```
