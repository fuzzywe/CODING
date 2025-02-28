239. Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]

 ---

   ```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        int maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            // maintain decreasing order in the deque, remove smaller elements
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i); // add current index
        }
        ans.push_back(nums[q.front()]);

        // processing for remaining
        for (int i = k; i < nums.size(); i++) {

            // removal of out of range
            while (!q.empty() && i - (q.front()) >= k) {
                q.pop_front();
            }
            int curr = nums[i];
            //      removal of smaller elemnets than curr
            while (!q.empty() && nums[q.back()] <= curr) {
                q.pop_back();
            }

            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

```

Time complexity: O(n)
Space complexity: O(n)
