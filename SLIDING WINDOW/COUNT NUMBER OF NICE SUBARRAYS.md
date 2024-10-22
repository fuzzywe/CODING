1248. Count Number of Nice Subarrays

https://leetcode.com/problems/count-number-of-nice-subarrays/description/

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

---

HASHING AND TWO POINTER

ntuition:
The problem is essentially about finding subarrays with exactly 'k' odd numbers.

We can use a hashmap to count the occurrences of prefix sums, which helps us keep track

of the number of odd numbers encountered so far.

Approach 1:
Initialize a hashmap to store the count of prefix sums.

Traverse the array and for each element, check if it's odd. If it is, increment the current sum.

Calculate the difference between the current sum and 'k'.

Check if this difference exists in the hashmap, which means there's a subarray with exactly 'k' odd numbers.

Update the hashmap with the current sum.

Return the total count of such subarrays.

Complexity:

Time complexity: O(n), where 'n' is the length of the input array.

Space complexity: O(n), for the hashmap used to store the prefix sums.

```cpp
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        unordered_map<int, int> mpp; // Initialize unordered_map to store prefix sums
        int sum = 0; // Initialize sum to count odd numbers
        int ans = 0; // Initialize answer to count subarrays with exactly 'k' odd numbers
        mpp[0] = 1; // Initialize map with 0 sum to handle cases where subarray starts from index 0

        for (int i = 0; i < n; ++i) { // Iterate through the array
            if (nums[i] % 2 == 1) { // Check if the current number is odd
                sum += 1; // Increment the sum if the number is odd
            }
            int diff = sum - k; // Calculate the difference needed to form a subarray with 'k' odd numbers
            ans += mpp[diff]; // Add the count of subarrays found with the required difference
            mpp[sum]++; // Update the map with the current sum
        }
        return ans; // Return the total count of subarrays with exactly 'k' odd numbers
    }
};
```
---

Intuition
To find the number of subarrays with exactly 'k' odd numbers, we can utilize a sliding window approach combined with prefix sum logic. By counting the number of subarrays with up to 'k' odd numbers and subtracting the count of subarrays with up to 'k-1' odd numbers, we can derive the result.

Approach 2
Implement a helper function countLessThanEqualToK that returns the number of subarrays with at most 'k' odd numbers.

The main function will use this helper to calculate the difference between the number of subarrays with at most 'k' odd numbers and the number of subarrays with at most 'k-1' odd numbers, giving the result.

Use two pointers to maintain a sliding window and keep track of the number of odd numbers in the current window.

Expand the window to include new elements and shrink it when the count of odd numbers exceeds 'k'.

Complexity

Time complexity: O(n), where 'n' is the length of the input array, as each element is processed at most twice (once when expanding and once when contracting the window).

Space complexity: O(1), as we only use a few extra variables and do not use additional space proportional to the input size.

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countLessThanEqualToK(nums, k) - countLessThanEqualToK(nums, k - 1);
    }

    int countLessThanEqualToK(vector<int>& nums, int k) {
        int i = 0; // Left pointer of the sliding window
        int count = 0; // Count of valid subarrays
        int oddCount = 0; // Number of odd elements in the current window
        
        for (int j = 0; j < nums.size(); ++j) { // Right pointer of the sliding window
            if (nums[j] % 2 == 1) // Check if the current element is odd
                oddCount++; // Increment the odd count
            
            // While the number of odd elements exceeds 'k', move the left pointer to the right
            while (oddCount > k) {
                if (nums[i] % 2 == 1) // Check if the element at the left pointer is odd
                    oddCount--; // Decrement the odd count
                i++; // Move the left pointer to the right
            } 
            
            count += j - i + 1; // Add the number of valid subarrays ending at 'j'
        }
        
        return count; // Return the total count of subarrays with at most 'k' odd numbers
    }
};
```
