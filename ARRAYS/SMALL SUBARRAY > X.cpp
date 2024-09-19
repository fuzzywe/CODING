Smallest subarray with sum greater than x


Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [4, 45, 6]
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray exist

brute force:
class Solution {
public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        int minLength = n + 1;
        for (int start = 0; start < n; ++start) {
            int currSum = arr[start];
            if (currSum > x) return 1; // Single element is greater than x
            for (int end = start + 1; end < n; ++end) {
                currSum += arr[end];
                if (currSum > x && (end - start + 1) < minLength) {
                    minLength = end - start + 1;
                }
            }
        }
        return minLength == n + 1 ? 0 : minLength;
    }
};

Time Complexity: O(n2) - Due to the nested loops, where n is the size of the input array arr[].
Space Complexity: O(1) - The algorithm uses only a constant amount of extra space for variables regardless of the input size.

  best soln:

class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int curr_sum = 0, min_len = n + 1;
        int start = 0, end = 0;

        while (end < n) {
            while (curr_sum <= x && end < n)
                curr_sum += arr[end++];

            while (curr_sum > x && start < n) {
                if (end - start < min_len)
                    min_len = end - start;

                curr_sum -= arr[start++];
            }
        }

        if (min_len > n)
            return 0;
        return min_len;
    }
};
Complexity
Time Complexity: O(n) - The algorithm iterates through each element of the array once using the two-pointer approach.
Space Complexity: O(1) - The algorithm uses only a constant amount of extra space regardless of the size of the input array.




